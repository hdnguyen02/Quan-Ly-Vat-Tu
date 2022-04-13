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
		cout << endl << "HOA DON" << endl; 
		dsHoaDon.duyetDSHD(); 
	}
	NhanVien(string maNV,string ho,string ten,int phai) : maNV(maNV) , ho(ho) , ten(ten) , phai(phai) {}
	void ghiFileNhanVien(ofstream &fileout) {
		fileout << maNV << "," << ho << "," << ten << "," << phai << "," << endl; 
		dsHoaDon.ghiFileDSHD(fileout); 
	}
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
	NhanVien* themNV(const string &maNV,const string &ho,const string &ten,const int &phai);
	int timKiemNVTraVeViTri(const string& maVT);
	NhanVien* timKiemNVTraVeDiaChi(const string& maVT);
	bool xoaNV(const string& maVT);
	int soLuongNV();
	void giaiPhongNV();
	void docFileDSNV(string link);   
	void ghiFileDSNV(string link); 
	
	// tra ve true neu ton tai! va nguoc lai
	bool timKiemHD(const string& soHD) {
		NodeHoaDon* tempTimKiem; 
		for (int i = 0; i < this->soLuong;i++) {
			tempTimKiem = nv[i]->dsHoaDon.timKiemHoaDon(soHD); 
			if (tempTimKiem != NULL) {
				return true; 
			}
		}
		return false; 
	}
	
};

// 	VOID CLASS DANH SACH NHAN VIEN
	void dsNhanVien::ghiFileDSNV(string link) {  // ham nay se duoc goi khi them xoa sua. 
		ofstream fileout; 
		fileout.open(link.c_str(),ios::out | ios::trunc); // mo ra chi ghi va xoa het
		fileout << this->soLuong << endl; 
		for (int i = 0; i < this->soLuong;i++) {
			nv[i]->ghiFileNhanVien(fileout); 
		}
		fileout.close(); 		
	}

	void dsNhanVien::docFileDSNV(string link) {
		ifstream filein;
		filein.open(link.c_str(),ios::in); 
		int soLuongNV;  
		filein >> soLuongNV; 
		filein.ignore(); 
		for (int i = 0; i < soLuongNV;i++) {
			string maNV,ho,ten,tempPhai; 
			int phai; 
			getline(filein,maNV,','); 
			getline(filein,ho,','); 
			getline(filein,ten,','); 
			getline(filein,tempPhai,','); 
			phai = TienichDoHoa::stringToInt(tempPhai);
			NhanVien* newNhanVien = this->themNV(maNV,ho,ten,phai); 
			newNhanVien->dsHoaDon.docFileDSHD(filein);  // doc vao file dsHD. 	
		}
		filein.close(); 
	}

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
	
	
	// ham them nv => tra ve dia chi vua moi them vao. 
	NhanVien* dsNhanVien::themNV(const string &maNV,const string &ho,const string &ten,const int &phai) {
		int timKiemTrung = this->timKiemNVTraVeViTri(maNV); 
		if (!this->dsDay() && timKiemTrung == -1) { 
			nv[soLuong] = new NhanVien(maNV,ho,ten,phai); 
			this->soLuong++; 
			return nv[soLuong - 1]; // vi tri cua thang vua moi them vao!.  
		} 
		return NULL; // them that bai ! 
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
