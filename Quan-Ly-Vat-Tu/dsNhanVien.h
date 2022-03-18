#pragma once
#include "autoLoad.h"
using namespace std;

const int NHANVIENTOIDA = 500;





// cấu trúc cây nhị phân tìm kiếm vật tư





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