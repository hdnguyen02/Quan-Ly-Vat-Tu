#pragma once
#include "autoload.h"
using namespace std;
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
   

};

// struct ho tro chua 2 con tro ( 1 con tro tro vao vi tri node va 1 con tro tro vao vi tri phia truoc no
// kieu du lieu dung de chua 2 con tro ( con tro phia truoc 1 node bst va 1 con tro bst. 


class BstVatTu {
private:
    NodeVatTu* root;
public:
    BstVatTu() : root(NULL) {};
    ~BstVatTu(); 
    void hoTroThemVT(NodeVatTu* root, const VatTu& info); 
    void themVT(const VatTu& info); 
    void duyetCay();
    void hoTroDuyetCay(NodeVatTu* root); 
    void giaiPhong(NodeVatTu* root);
	NodeVatTu* timKiemVT(const string& key);  // return ve NULL neu khong tim thay va vi tri cua no neu tim thay 
	bool isNULL(); 
	// xoa xong thi giai phong cai node do luon 
	bool xoaVT(const string& key); 
	
	
	// tra ve true neu ham nay xoa thanh cong. và false neu key nay khong ton tai trong bstVT
	

};



bool BstVatTu::xoaVT(const string& key) {
		// di chuyen den vi tri node can xoa. 
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
		
		// truong hop can tim thay node de xoa hoac la 
		if (nodeDelete == NULL) { 
			return false; 
		}

		if (nodeDelete->pLeft == NULL || nodeDelete->pRight == NULL) {
			// co the xay ra 2 truong Hop : 
			// la node co 1 con hoac la node la
			NodeVatTu* pTempDelete ; 
			if (nodeDelete->pLeft == NULL) {
				// truong hop cay co 1 con va node con do la node rigth
				pTempDelete = nodeDelete->pRight; 
				
			}
			else {
				pTempDelete = nodeDelete->pLeft; 
			}
			
			if (previousNodeDelete == NULL) { // node can xoa la node NULL. 
				// mat ke la node do co 2 la hay 1 la tá : 
				// truong hop ca 2 deu NULL => thi tk root bi xoa di song nó NULL 
				// xoa di node root
				delete root; 
				root = pTempDelete;
				return true; 
				// giai phong di node root truoc do. 
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
		else if (nodeDelete->pLeft!=NULL && nodeDelete->pRight != NULL) {
			// truong hop cay con do co hai nut. 
			// tim kiem node nho nhat phia ben phai cua node do 
			cout <<endl << "truong hop xoa vao node nay" << endl; 
			NodeVatTu* parentNodeMin = NULL; // node phai truoc node Min ( node se ke vi node bi xoa )
			NodeVatTu* nodeMin = nodeDelete->pRight; 
			// tim thang nho nhat ( va thang do la node cuoi cung phia ben tay phai 
			// xu dung vong lap 
			while (nodeMin->pLeft != NULL) {
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
			
			// coppy noi dung cua node hau de sang node can xoa va xoa di cai node hau de 
			// coppy info. 
				nodeDelete->info = nodeMin->info; 
			// xoa di nodeMin 
			delete nodeMin; 
		}
		
		return true; 
		
	}

void BstVatTu::themVT(const VatTu& info) {
    if (root == NULL) { 
        root = new NodeVatTu(info); 
    }
    else {
        hoTroThemVT(root, info); 
    }
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
	// goi toi ham va truyen doi so vao 
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
	cout << "delete Node : " << root->info.maVT << endl ; 
	delete root; 
}

// viet ham hieu chinh vatTu ( nhap vao ma soVT de co the hieu chinh 

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


BstVatTu::~BstVatTu() {
     
     this->giaiPhong(root); // giai phong di bo nho
    
    
}
