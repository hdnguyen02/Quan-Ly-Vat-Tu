#pragma once
#include "autoLoad.h"
using namespace std; 

struct HoaDon {
    string soHD;
    Date date;
    string loai;   // chỉ nhận 2 giá trị 'N' => nhập và 'X' => xuất 
    // con trỏ chi tiết hóa đơn 
    listCTHD dsctHD;   // danh sách chi tiết hóa đơn của 1 hóa đơn. 


    // constructor 
    HoaDon(string soHD, Date date, string loai) : soHD(soHD), date(date.ngay, date.thang, date.nam), loai(loai) {}
    HoaDon() {}
};

// tạo ra node hóa đơn 
class NodeHoaDon {
private:
    HoaDon info;
    NodeHoaDon* pNext;
    // con trỏ trỏ đến hóa dơn khác của 1 nhân viên 
public:
    NodeHoaDon() : pNext(NULL) {};
    NodeHoaDon(string soHD, Date date, string loai) : info(soHD, date, loai), pNext(NULL) {}
};



// danh sách liên kết đơn 
class ListHoaDon {
private: 
    HoaDon* head; 
public: 
    ListHoaDon() : head(NULL) {}

};