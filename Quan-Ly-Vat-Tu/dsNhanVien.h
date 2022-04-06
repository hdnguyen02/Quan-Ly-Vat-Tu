#pragma once
using namespace std;
#include "Tienich.h"
#define MAX 500 

struct NhanVien {
    string maNV;  
    string ho;
    string ten;
    int phai;   // 0. nam 1. nu 
    ListHoaDon dsHoaDon; 
	NhanVien() {};
	NhanVien (string maNV,string ho,string ten,int phai):maNV(maNV),ho(ho),ten(ten),phai(phai) {};	
	// tam thoi chi in ra chi tiet hoa don thoi 
	void inNV() ;
};

void NhanVien::inNV() {
	cout << maNV << "  " << ho << "  " << ten << "  " << phai == 0 ? "nam":"nu" ; 
	this->dsHoaDon.duyetDSHD(); 
}


class dsNhanVien {
private:
	int soLuong;   // so luong nhan vien. 
    NhanVien *nv[MAX]; 
public:
	dsNhanVien() : soLuong(0) {} 
	bool dsRong() {
		if (soLuong == 0) {
			return true; 
		}
		return false; 
	}
	bool dsDay() {
		if (soLuong == MAX) {
			return true; 
		}
		return false; 
	}
	
	void duyetDSNV() {
		for (int i = 0; i < this->soLuong; i++) {
			nv[i]->inNV(); // goi toi ham in nhan vien -> vi la con tro nen phai dung phep tro. 
			cout << endl; 
		}
	}
	
	bool themNV(NhanVien info) {
		// kiem tra xem da co thang nao ton tai truoc do chua 
		int viTriTrung = this->timKiemNV(info.maNV); 
		if (!this->dsDay() && viTriTrung == -1) {
			nv[soLuong++] = &info;
			return true; 
		}
		return false; // danh sach day -> khong them duoc. 
	}
	
	// viet ham tim kiem va tra ve dia chi 
	int timKiemNV(const string& maVT) {  // return ve -1 neu khong can sai toi. 
		for (int i = 0; i < this->soLuong;i++) {
			if (nv[i]->maNV == maVT){
				return i; // tra ve vi tri ma tim thay
			}
		}
		return -1; 
	}
	
	// viet ham xoa 
	bool xoaNV(const string& maVT) {
		int viTriXoa = this->timKiemNV(maVT);   
		if (this->dsRong() || viTriXoa == -1 ) {
			return false; 
		}
		
		for (int i = viTriXoa;i < this->soLuong;i++ ) {
			nv[i] = nv[i + 1]; 
		}
		this->soLuong--; 
		return true;
	}
	
	
	
	
	
	int soLuongNV() {
		return this->soLuong;
	}
	
	
};
