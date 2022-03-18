#pragma once
#include "autoLoad.h"
using namespace std; 

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
class NodeCTHD {
    // các thành phần của 1 con danh node  
private:
    CThoaDon info;
    NodeCTHD* pNext;
public:
    NodeCTHD() : pNext(NULL) { }
    NodeCTHD(string maVT, float soLuong, string donGia, float VAT) : info(maVT, soLuong, donGia, VAT), pNext(NULL) {}
};

class listCTHD {
private:
    // root đầu tiên của chi tiết hóa đơn 
    NodeCTHD* head;

public:
    listCTHD() : head(NULL) {}

    // các phương thức thêm xóa sữa  

};