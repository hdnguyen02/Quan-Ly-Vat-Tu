#pragma once
#include "autoload.h"
using namespace std;
struct vatTu {
    string maVT;     // id vật tư ( không được trùng )
    string ten;   // tên vật tư
    string donVi;   // đơn vị tính
    float soLuongTon;  // số lượng tồn
    vatTu() {}; // constructor mặc định
    vatTu(string maVT, string ten, string donVi, float soLuongTon) : maVT(maVT), ten(ten),
        donVi(donVi), soLuongTon(soLuongTon) {};




};


// cấu trúc vật tư
class NodeVatTu {
private:
    vatTu materialKey;
    NodeVatTu* pLeft;
    NodeVatTu* pRight;
public:
    NodeVatTu() : pLeft(NULL), pRight(NULL) {};  // mặc định
    NodeVatTu(string id, string ten, string donVi, float soLuongTon) : materialKey(id, ten, donVi, soLuongTon),
        pLeft(NULL), pRight(NULL) {}

};

class BstVatTu {
private:
    NodeVatTu* root;



public:
    // viết hàm nhập vật tư
    // viết hàm thêm nhân viên vào
    BstVatTu() : root(NULL) {};



};