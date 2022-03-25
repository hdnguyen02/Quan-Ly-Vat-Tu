#pragma once
#include "autoLoad.h"
using namespace std; 

struct HoaDon {
    string soHD;
    Date date;
    string loai;   
    listCTHD dsctHD;  
    HoaDon(string soHD, Date date, string loai) : soHD(soHD), date(date.ngay, date.thang, date.nam), loai(loai) {}
    HoaDon() {}
};

class NodeHoaDon {
private:
    HoaDon info;
    NodeHoaDon* pNext;
public:
    NodeHoaDon() : pNext(NULL) {};
    NodeHoaDon(string soHD, Date date, string loai) : info(soHD, date, loai), pNext(NULL) {}
};



// danh sách liên k?t don 

class ListHoaDon {
private: 
    NodeHoaDon* head;  
public: 
    ListHoaDon() {
		this->head = NULL;
	}

};
