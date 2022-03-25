#pragma once
#include "autoLoad.h"
using namespace std;

const int NHANVIENTOIDA = 500;  // n 


struct nhanVien {
    string id;  // maNV
    string ho;
    string ten;
    int phai;   // 0. nam 1. nu 
};





class dsNhanVien {
private:
	int sl;  // so luong thuc te. 
    nhanVien *nv[NHANVIENTOIDA];  // 
public:




};
