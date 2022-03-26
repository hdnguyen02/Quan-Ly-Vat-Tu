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



class BstVatTu {
private:
    NodeVatTu* root;
public:
    BstVatTu() : root(NULL) {};
    ~BstVatTu(); 
    void supportInsert(NodeVatTu* root, const VatTu& info);
    void insert(const VatTu& info);
    void deleteNode(NodeVatTu* root) ; 
    void duyetCay();
    void hoTroDuyetCay(NodeVatTu* root); 
    void deleteTree(NodeVatTu* root);
	NodeVatTu* search(const string& key);  // return ve NULL neu khong tim thay va vi tri cua no neu tim thay 
	bool isNULL(); 
	

};





void BstVatTu::insert(const VatTu& info) {
    if (root == NULL) { 
        root = new NodeVatTu(info); 
    }
    else {
        supportInsert(root, info); 
    }
}


void BstVatTu::supportInsert(NodeVatTu* root,const VatTu& info) {
    if (info.maVT < root->info.maVT ) {
        if (root->pLeft == NULL) {
            root->pLeft = new NodeVatTu(info); 
        }
        else {
            supportInsert(root->pLeft, info); 
        }
    }
    else {
        if (root->pRight == NULL) {
            root->pRight = new NodeVatTu(info); 
        }
        else {
            supportInsert(root->pRight, info);
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
void BstVatTu::deleteTree(NodeVatTu* root) {
	if (root == NULL) {
		return; 
	}
	deleteTree(root->pLeft); 
	deleteTree(root->pRight); 
	cout << "delete Node : " << root->info.maVT << endl ; 
	delete root; 
}

// viet ham hieu chinh vatTu ( nhap vao ma soVT de co the hieu chinh 

NodeVatTu* BstVatTu::search(const string& key) {
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
     
     this->deleteTree(root); // giai phong di bo nho
    
    
}
