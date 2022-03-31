#pragma once
#include "autoLoad.h"
using namespace std;

struct CThoaDon {
    string maVT;   
    float soLuong;
    float donGia; 
    float VAT;  // 10% 0,1 
    // constructor 
    CThoaDon(string maVT, float soLuong, float donGia, float VAT) :
        maVT(maVT), soLuong(soLuong), donGia(donGia), VAT(VAT) {}
    CThoaDon() {}
};


class NodeCTHD { 
private:
    CThoaDon info;
    NodeCTHD* pNext;
public:
    NodeCTHD() : pNext(NULL) { }
    NodeCTHD(string maVT, float soLuong, float donGia, float VAT) : info(maVT, soLuong, donGia, VAT), pNext(NULL) {}
};

class listCTHD {
private:
    NodeCTHD* head;

public:
    listCTHD() : head(NULL) {} // hoi ki 
 

};
