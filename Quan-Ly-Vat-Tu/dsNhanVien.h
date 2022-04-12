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
	void inNV() {
		cout << maNV << "  " << ho << "  " << ten << "  " << phai == 0 ? "nam":"nu" ; 
	}
	NhanVien(string maNV,string ho,string ten,int phai) : maNV(maNV) , ho(ho) , ten(ten) , phai(phai) {}
};




class dsNhanVien {
private:
	int soLuong;   
    NhanVien *nv[MAX]; 
public:
	dsNhanVien() : soLuong(0) {} 
    ~dsNhanVien() { this->giaiPhongNV();  }
	bool dsRong();
	bool dsDay();
	void duyetDSNV();
	bool themNV(const string &maNV,const string &ho,const string &ten,const int &phai);
	int timKiemNVTraVeViTri(const string& maVT);
	NhanVien* timKiemNVTraVeDiaChi(const string& maVT);
	bool xoaNV(const string& maVT);
	int soLuongNV();
	void giaiPhongNV();
};

// 	VOID CLASS DANH SACH NHAN VIEN

	bool dsNhanVien::dsRong() {
			if (soLuong == 0) {
				return true; 
			}
			return false; 
	}
	bool dsNhanVien::dsDay() {
		if (soLuong == MAX) {
			return true; 
		}
		return false; 
	}
	
	void dsNhanVien::duyetDSNV() {
		for (int i = 0; i < this->soLuong; i++) {
			nv[i]->inNV(); 
			cout << endl; 
		}
	}
	
	
	
	bool dsNhanVien::themNV(const string &maNV,const string &ho,const string &ten,const int &phai) {
		int timKiemTrung = this->timKiemNVTraVeViTri(maNV); 
		if (!this->dsDay() && timKiemTrung == -1) { 
			nv[soLuong++] = new NhanVien(maNV,ho,ten,phai); 
			return true; 
		} 
		return false; 
	}
	
	
	int dsNhanVien::timKiemNVTraVeViTri(const string& maVT) {  
		for (int i = 0; i < this->soLuong;i++) {
			if (nv[i]->maNV == maVT){
				return i; 
			}
		}
		return -1; 
	}
	
	NhanVien* dsNhanVien::timKiemNVTraVeDiaChi(const string& maVT) { 
		for (int i = 0; i < this->soLuong;i++) {
			if (nv[i]->maNV == maVT){
				return nv[i]; 
			}
		}
		return NULL; 
	}

	bool dsNhanVien::xoaNV(const string& maVT) {
		int viTriXoa = this->timKiemNVTraVeViTri(maVT);   
		if (this->dsRong() || viTriXoa == -1 ) {
			return false; 
		}
		for (int i = viTriXoa;i < this->soLuong;i++ ) {
			nv[i] = nv[i + 1]; 
		}
		this->soLuong--; 
		return true;
	}
	
	int dsNhanVien::soLuongNV() {
		return this->soLuong;
	}
	
	void dsNhanVien::giaiPhongNV() {
		for (int i = 0;i < this->soLuong;i++) {
			delete nv[i]; 
		}
	}
