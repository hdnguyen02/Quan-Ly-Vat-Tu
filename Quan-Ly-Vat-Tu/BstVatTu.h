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
			// kiem tra xem de co the di xuong 
			if (key < nodeDelete->info.maVT) {
				// duy chuyen phai de co the tim kiem 
				nodeDelete = nodeDelete->pLeft; 
			}
			else {
				nodeDelete = nodeDelete->pRight; 
			}
			
		}
		
		// kiem tra xem co ton tai node do khong. 
		if (nodeDelete == NULL) { // tuc la khong tim thay. 
			return false; // xoa that bai vi khong co node nào co key nao. 
		}


	
		
		NodeVatTu* pTempDelete = nodeDelete;  
		if (nodeDelete->pLeft == NULL && nodeDelete->pRight == NULL ) {
				// truong hop nay la node la. 
				delete nodeDelete; 
		}
		
		else if (nodeDelete->pRight != NULL && nodeDelete->pLeft == NULL ) {
				// kiem tra xem node can xoa co phai la root khac hay khong. 
				if (previousNodeDelete == NULL) {
					root = nodeDelete->pRight; 
					// giai phong di node dau tien 
					delete nodeDelete; 
				}
				// node can xoa co 1 child. va child do la node Right. 
				// kiem tra xem node can xoa la node left hay node right cua node parent. 
				else {
					if (previousNodeDelete->pLeft == nodeDelete) {
					// node dang can xoa la node left cua node parent. 
					previousNodeDelete->pLeft = nodeDelete->pRight; 
					}
					else {
						previousNodeDelete->pRight = nodeDelete->pRight; 
					}
					delete pTempDelete;
				}
			
		}
		else if (nodeDelete->pLeft != NULL && nodeDelete->pRight == NULL) {
			if (previousNodeDelete == NULL) {
					root = nodeDelete->pLeft; 
					delete nodeDelete;
				}
			else {
				if (previousNodeDelete->pLeft == nodeDelete) {
				previousNodeDelete->pLeft = nodeDelete->pLeft; 
				}
				else {
					previousNodeDelete->pRight = nodeDelete->pLeft; 
				}
				delete pTempDelete;
				}
			
		}
		else if (nodeDelete->pLeft!=NULL && nodeDelete->pRight != NULL) {
			// truong hop cay con do co hai nut. 
			// tim kiem node nho nhat phia ben phai cua node do 
			NodeVatTu* parentNodeMin = NULL; // node phai truoc node Min ( node se ke vi node bi xoa )
			NodeVatTu* nodeMin = nodeDelete->pRight; 
			// tim thang nho nhat ( va thang do la node cuoi cung phia ben tay phai 
			// xu dung vong lap 
			while (nodeMin->pLeft != NULL) {
				// chua phai node cuoi cung
				parentNodeMin = nodeMin; 
				nodeMin = nodeMin->pLeft;
			}
			
			// sau khi tim ra duoc node min nhat 
			if (parentNodeMin != NULL) {
				parentNodeMin->pLeft = nodeDelete->pRight; 
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
