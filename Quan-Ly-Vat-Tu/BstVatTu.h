#pragma once
#include "autoload.h"

using namespace std;

// ================================== CAU TRUC VAT TU ==================================
struct VatTu {
    string maVT;    
    string ten;   
    string donVi;   
    float soLuongTon;  
    VatTu() {}; 
    VatTu(string maVT, string ten, string donVi, float soLuongTon) : maVT(maVT), ten(ten),
        donVi(donVi), soLuongTon(soLuongTon) {};
    void inVatTu(); 
	


};
void VatTu::inVatTu() {
	cout << this->maVT << "  " << this->ten  << "  " << this->donVi << "  " << this->soLuongTon; 
}


// ================================ CAU TRUC NODE VAT TU ================================
class NodeVatTu {
private:
    VatTu info;
    NodeVatTu* pLeft;
    NodeVatTu* pRight;
public:
    friend class BstVatTu; 
    NodeVatTu(): pLeft(NULL), pRight(NULL) {};  
    NodeVatTu(const VatTu& info) : info(info.maVT, info.ten, info.donVi, info.soLuongTon),
        pLeft(NULL), pRight(NULL) {} 
   VatTu getInfo() {
   		return this->info; 
   }

};

// ==================================== BST VAT TU ====================================
class BstVatTu {
private:
    NodeVatTu* root;
    int soLuong; 
    
public:
	// HAM KHOI TAO, HAM HUY
    BstVatTu() : root(NULL), soLuong(0) {
		// this->docVatTuFile(); 
	};
    ~BstVatTu(); 
    
    // HAM CHUC NANG
    void hoTroThemVT(NodeVatTu* root, const VatTu& info); 
    bool themVT(const VatTu& info); 
    void duyetCay();
    void hoTroDuyetCay(NodeVatTu* root); 
    void giaiPhong(NodeVatTu* root);
	NodeVatTu* timKiemVT(const string& key);
	bool xoaVT(const string& key); 
	bool dieuChinhVT(const string& key,const string& tenVT,const string&donViVT) ;
	bool isNULL();  
	int soLuongVT();
	void BstVatTuToArray(NodeVatTu **arrVT,int &index,NodeVatTu* root);  
	void sapXepTangDanTheoTen(NodeVatTu** arrVT); 
	
	// XU LY FILE
	void ghiVatTuFile();
	void docVatTuFile();
	void hoTroGhiVatTuFile(NodeVatTu *root,ofstream &fileout);
};

int BstVatTu::soLuongVT() {
		return this->soLuong; 
}

void BstVatTu::sapXepTangDanTheoTen(NodeVatTu** arrVT) {  
		int index = 0; 	
		int soLuongVT = this->soLuongVT(); 
		this->BstVatTuToArray(arrVT,index,root);   
		for (int i = 0; i < soLuongVT - 1;i++) {
			for(int j = i + 1;j < soLuongVT;j++) {
				if (arrVT[i]->info.ten > arrVT[j]->info.ten) {
					NodeVatTu* temp = arrVT[i];
					arrVT[i] = arrVT[j]; 
					arrVT[j] = temp;  		
				}
			}
		}
}


void BstVatTu::BstVatTuToArray(NodeVatTu **arrVT,int &index,NodeVatTu* root) { 
		if (root != NULL) {
			BstVatTuToArray(arrVT,index,root->pLeft); 
			arrVT[index++] = root; 
			BstVatTuToArray(arrVT,index,root->pRight); 
		}	
	} 


// return ve true neu dieu chinh thanh cong va false neu dieu chinh that bai ( vi key khong ton tai ) 
bool BstVatTu::dieuChinhVT(const string& key,const string& tenVT,const string&donViVT) {
	NodeVatTu* nodeHieuChinh = timKiemVT(key); 
	if (nodeHieuChinh == NULL) {
		return false; 
	}
	nodeHieuChinh->info.ten = tenVT; 
	nodeHieuChinh->info.donVi = donViVT;
	return true; 
}

bool BstVatTu::xoaVT(const string& key) {
		NodeVatTu* nodeDelete = root; 
		NodeVatTu* previousNodeDelete = NULL; // tro truoc vi tri node can xoa. 
		while (nodeDelete != NULL && nodeDelete->info.maVT != key ) {
			previousNodeDelete = nodeDelete; 
			if (key < nodeDelete->info.maVT) {
				nodeDelete = nodeDelete->pLeft; 
			}
			else {
				nodeDelete = nodeDelete->pRight; 
			}
			
		}
		
		if (nodeDelete == NULL) { // truong hop can tim thay node de xoa hoac cay dang rong
			return false; 
		}
		if (nodeDelete->pLeft == NULL || nodeDelete->pRight == NULL) { // truong hop node co 1 con hoac node la
			NodeVatTu* pTempDelete ; 
			if (nodeDelete->pLeft == NULL) {
				pTempDelete = nodeDelete->pRight; 	// truong hop cay co 1 con va node con do la node right	
			}
			else {
				pTempDelete = nodeDelete->pLeft;   // truong hop cay co 1 con va node con do la node left
			}
			
			if (previousNodeDelete == NULL) { // node can xoa la node NULL. 
				// mat ke la node do co 2 la hay 1 la tá : 
				// truong hop ca 2 deu NULL => thi tk root bi xoa di song nó NULL 
				// xoa di node root
				delete root; 
				root = pTempDelete; 
				this->soLuong--;  
				return true; // return tai de ham khong chay nua. 
			}
			if (previousNodeDelete->pLeft == nodeDelete) {
				// node can xoa nam o phia ben tay phai so voi node do./ 
				previousNodeDelete->pLeft = pTempDelete; 
			}
			else {
				previousNodeDelete->pRight= pTempDelete; 
			}
			delete pTempDelete; // giai phong di node can xoa. 
		}
		else if (nodeDelete->pLeft!=NULL && nodeDelete->pRight != NULL) { // truong hop cay con do co hai nut. 
			// tim kiem node nho nhat phia ben phai cua node do 
			NodeVatTu* parentNodeMin = NULL; // node phai truoc node Min ( node se ke vi node bi xoa )
			NodeVatTu* nodeMin = nodeDelete->pRight; 
			while (nodeMin->pLeft != NULL) { // tim thang nho nhat ( va thang do la node cuoi cung phia ben tay phai 
				// chua phai node cuoi cung
				parentNodeMin = nodeMin; 
				nodeMin = nodeMin->pLeft;
			}
			
			// sau khi tim ra duoc node min nhat phia ben tay phai cua node can xoa. 
			if (parentNodeMin != NULL) {
				parentNodeMin->pLeft = nodeMin->pRight; 
			}
			else {
				// truong hop : truong hop node the mang chinh la node trai cua node can xoa 
				nodeDelete->pRight = nodeMin->pRight; 
				// truong hop nay co nghia la : node parentNodeMin dang la NULL
				// tuc la cai node can xoa chinh la cai node ben phia duoi no luon 
				// luc nay ta chi can cho tk node dang can xoa tro den thang node phia ben 
				// phai cua node hau de sau ( vi phia ben tay trai dang NULL -> nen moi dung vong lap 	
			}
			nodeDelete->info = nodeMin->info; 	// coppy info. 
			delete nodeMin; 
		}
		this->soLuong--; 
		return true; 
		
	}

bool BstVatTu::themVT(const VatTu& info) {
	if (this->timKiemVT(info.maVT) != NULL) { // khong tim thay.  
		return false; // them khong thanh cong. 
	}
	
    if (root == NULL) { 
        root = new NodeVatTu(info); 
    }
    else {
        hoTroThemVT(root, info); 
    }
    this->soLuong++; 
    return true; 
}


void BstVatTu::hoTroThemVT(NodeVatTu* root,const VatTu& info) {
    if (info.maVT < root->info.maVT ) {
        if (root->pLeft == NULL) {
            root->pLeft = new NodeVatTu(info); 
        }
        else {
            hoTroThemVT(root->pLeft, info); 
        }
    }
    else {
        if (root->pRight == NULL) {
            root->pRight = new NodeVatTu(info); 
        }
        else {
            hoTroThemVT(root->pRight, info);
        }
    }
}

void BstVatTu::duyetCay() {
	hoTroDuyetCay(root); 
}

void BstVatTu::hoTroDuyetCay(NodeVatTu* root) {
	if (root == NULL) {
		return;  
	}
	hoTroDuyetCay(root->pLeft);
	root->info.inVatTu(); 
	cout << endl; 
	hoTroDuyetCay(root->pRight); 
}	
void BstVatTu::giaiPhong(NodeVatTu* root) {
	if (root == NULL) {
		return; 
	}
	giaiPhong(root->pLeft); 
	giaiPhong(root->pRight); 
	delete root; 
}



NodeVatTu* BstVatTu::timKiemVT(const string& key) {
	NodeVatTu* temp = root;
	// neu nhu moi voa ma temp == NULL => root nay rong => cha co node nay 
	// hoac cai node nó bang => quy pham => cham duc => return ve chinh node nay. 
	while (temp != NULL && temp->info.maVT != key) {
		if (key < temp->info.maVT) {
			temp = temp->pLeft; 
		}
		else {
			temp = temp->pRight; 
		}
	}
	if (temp == NULL) {
		return NULL;
	}
	return temp; 
}
// hàm tra ve true neu nhu cay nay rong 
bool BstVatTu::isNULL() {
	if (root == NULL) {
		return true; 
	}
	return false; 
}
void BstVatTu::hoTroGhiVatTuFile(NodeVatTu *root,ofstream &fileout) {
	if(root !=NULL) {
		hoTroGhiVatTuFile(root->pLeft,fileout);
		fileout << root->info.maVT<<endl;
		fileout << root->info.ten<<endl;
		fileout << root->info.donVi<<endl;
		fileout << root->info.soLuongTon<<endl;
		hoTroGhiVatTuFile(root->pRight,fileout);
	}
	return; 
}
void BstVatTu::ghiVatTuFile() {
	if(root!=NULL) {
		ofstream fileOut;
		fileOut.open("data/vatTu.txt",ios::out|ios::app);
		fileOut <<this->soLuong<<endl;
		hoTroGhiVatTuFile(root,fileOut);
		fileOut.close();
	}
}

// =================================== DOC VAT TU ( DOC TU FILE ) ===================================
void BstVatTu::docVatTuFile()
{
	 
	if(root!=NULL)
	{
		ifstream fileIn;
		fileIn.open("data/vatTu.txt",ios::in|ios::app);
		fileIn>>this->soLuong;

		for(int i=0;i<soLuong;i++) {
			VatTu tempVT;
			fileIn.getline((char*)(tempVT.maVT.c_str()),sizeof(tempVT.maVT));
			fileIn.getline((char*)(tempVT.ten.c_str()),sizeof(tempVT.ten));
			fileIn.getline((char*)(tempVT.donVi.c_str()),sizeof(tempVT.donVi));
			stringstream ss;  
			char tempSLT[20]; 
			ss<<tempVT.soLuongTon;
			ss>>tempSLT;
			fileIn.getline(tempSLT,sizeof(tempSLT));
			this->themVT(tempVT);
		}
		fileIn.close();	
	}
}


// ============================================ HAM HUY ============================================
BstVatTu::~BstVatTu() {
	 this->ghiVatTuFile(); 
     this->giaiPhong(root);
}
