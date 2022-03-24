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




};


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

    void deleteNode(NodeVatTu* root) {

    }





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


BstVatTu::~BstVatTu() {
    // giai phong 
    
}
