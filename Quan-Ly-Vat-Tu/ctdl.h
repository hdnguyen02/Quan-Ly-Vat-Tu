#pragma once
#include "autoload.h"
using namespace std;


//số lượng nhân viên max 
const int NHANVIENTOIDA = 500;


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
class nodeVatTu {
private:
    vatTu materialKey;
    nodeVatTu* pLeft;
    nodeVatTu* pRight;
public:
    nodeVatTu() : pLeft(NULL), pRight(NULL) {};  // mặc định
    nodeVatTu(string id, string ten, string donVi, float soLuongTon) : materialKey(id, ten, donVi, soLuongTon),
        pLeft(NULL), pRight(NULL) {}

};


// cấu trúc cây nhị phân tìm kiếm vật tư
class bstVatTu {
private:
    nodeVatTu* root;



public:
    // viết hàm nhập vật tư
    // viết hàm thêm nhân viên vào
    bstVatTu() : root(NULL) {};



};



struct nhanVien {
    string id;  // không được trùng 
    string ho;
    string ten;
    int phai; // quy ước : 0. nữ  1. nam . 2. khác 
};

// tọa struct nhân viên 



class dsNhanVien {
private:
    // bao gồm array. 
    nhanVien nv[NHANVIENTOIDA];
public:
    // số lượng nhân viên tối đa  




};





// tạo danh sách hóa đơn

struct hoaDon {
    string soHD;
    Date date;
    string loai;   // chỉ nhận 2 giá trị 'N' => nhập và 'X' => xuất 
    // con trỏ chi tiết hóa đơn 
    listCTHD dsctHD;   // danh sách chi tiết hóa đơn của 1 hóa đơn. 


    // constructor 
    hoaDon(string soHD, Date date, string loai) : soHD(soHD), date(date.ngay, date.thang, date.nam), loai(loai) {}
    hoaDon() {}
};

// tạo ra node hóa đơn 
class nodeHoaDon {
private:
    hoaDon info;
    nodeHoaDon* pNext;
    // con trỏ trỏ đến hóa dơn khác của 1 nhân viên 
public:
    nodeHoaDon() : pNext(NULL) {};
    nodeHoaDon(string soHD, Date date, string loai) : info(soHD, date, loai), pNext(NULL) {}
};


// chi tiết hóa đơn 
// cần có mã vật tư 
struct CThoaDon {
    string maVT;   // không được trùng 
    float soLuong;
    string donGia;
    float VAT;   // % VAT  
    // constructor 
    CThoaDon(string maVT, float soLuong, string donGia, float VAT) :
        maVT(maVT), soLuong(soLuong), donGia(donGia), VAT(VAT) {}
    CThoaDon() {}
};

// tạo ra danh sách liên kết đơn CThoaDon 
// node chi tiết hóa đơn
class nodeCTHD {
    // các thành phần của 1 con danh node  
private:
    CThoaDon info;
    nodeCTHD* pNext;
public:
    nodeCTHD() : pNext(NULL) { }
    nodeCTHD(string maVT, float soLuong, string donGia, float VAT) : info(maVT, soLuong, donGia, VAT), pNext(NULL) {}
};


// danh sách liên kết đơn chi tiết hóa đơn 
class listCTHD {
private:
    // root đầu tiên của chi tiết hóa đơn 
    nodeCTHD* head;

public:
    listCTHD() : head(NULL) {}

    // các phương thức thêm xóa sữa  

};








