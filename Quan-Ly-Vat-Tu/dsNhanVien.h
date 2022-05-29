#pragma once
using namespace std;
#include "Tienich.h"
#define MAX 500
#include "ListHoaDon.h"
struct NhanVien
{
	string maNV;
	string ho;
	string ten;
	int phai;		// 0. nam 1. nu
	int soLanTaoHD; // so lan tao HD cua nhan vien ( ) -> khi tao hoa don thanh cong -> ghi lai file!
	ListHoaDon dsHoaDon;
	NhanVien(){};
	void inNV()
	{
		cout << maNV << "  " << ho << "  " << ten << "  " << phai == 0 ? "nam" : "nu";
		cout << " so lan tao HD: " << this->soLanTaoHD;
		// cout << endl << "HOA DON" << endl;
		// dsHoaDon.duyetDSHD();
	}
	NhanVien(string maNV, string ho, string ten, int phai, int soLanTaoHD) : maNV(maNV), ho(ho),
																			 ten(ten), phai(phai), soLanTaoHD(soLanTaoHD) {}
	void ghiFileNhanVien(ofstream &fileout)
	{
		fileout << maNV << "," << ho << "," << ten << "," << phai << "," << soLanTaoHD << endl;
		dsHoaDon.ghiFileDSHD(fileout);
	}

	string getHoTen()
	{
		return ho + " " + ten; // tat ca da duoc chuan Hoa!
	}

	// viet ham so sanh theo ten nhu sau
	static bool soSanhTheoTen(NhanVien *nv1, NhanVien *nv2)
	{
		if (nv1->ten != nv2->ten)
		{
			return nv1->ten > nv2->ten;
		}
		else
		{
			return nv1->ho > nv2->ho;
		}
	}

	// ngoai ra con so sanh theo maNV
	static bool soSanhTheoMaNV(NhanVien *nv1, NhanVien *nv2)
	{
		return nv1->maNV > nv2->maNV;
	}
};

// tao ra 1 kieu cau truc ho tro : chua 1 con tro HoaDon ( hoaDon ma NV do lap va thong tin cua HD do )
struct NhanVienLapHD
{
	NhanVien *ptrNhanVien;
	NodeHoaDon *ptrHoaDon;
	NhanVienLapHD()
	{
		ptrHoaDon = NULL;
		ptrNhanVien = NULL;
	}
	NhanVienLapHD(NhanVien *NhanVien, NodeHoaDon *HoaDon)
	{
		ptrNhanVien = NhanVien;
		ptrHoaDon = HoaDon;
	}
	bool isNull()
	{
		if (ptrNhanVien == NULL && ptrHoaDon == NULL)
		{
			return true;
		}
		return false; // co chua du lieu!
	}
};

class DsNhanVien
{
private:
	int soLuong;
	NhanVien *nv[MAX];

public:
	DsNhanVien() : soLuong(0) {}
	bool dsRong();
	bool dsDay();
	void duyetDSNV();
	NhanVien *themNV(const string &maNV, const string &ho, const string &ten, const int &phai, int soLanTaoHD);
	int timKiemNVTraVeViTri(const string &maVT);
	NhanVien *timKiemNVTraVeDiaChi(const string &maVT);
	bool xoaNV(const string &maVT);
	int soLuongNV();
	void giaiPhongDSNV(); // giai phong danh sach nhanvien.
	void docFileDSNV();
	void ghiFileDSNV();
	
	// viet ham tim kiem theo truong bo vao 

	NhanVien* timKiemNhanVienTheoTen(const string& key) {
		for (int i = 0; i < this->soLuong;i++) {
			if (key == nv[i]->getHoTen()) {
				return nv[i]; 
			}
		}
		return NULL; // KHONG TIM THAY  
	}
	
	//
	
	
	// y tuong lam cau thong ke : deu sap xep ca 
	// bo gnat ca hoa don 1 mang con tro -> sau do sap xep tren do 
	int soLuongHD() {
		int soLuong = 0; 
		for (int i = 0;i < this->soLuongNV();i++) {
			soLuong = soLuong + this->nv[i]->dsHoaDon.soHD(); 
		}
		return soLuong; 
	}
	
	
	void listToArrayHoaDon(HoaDon** arrHoaDon,int &index) {
		for (int i = 0;i < this->soLuongNV();i++) {
			this->nv[i]->dsHoaDon.ganMangHoaDon(arrHoaDon,index); 
		}
	}
	
	
	int hoaDonTheoDate(HoaDon** arrHoaDon,HoaDon **hoaDonHople,int index,Date &start,Date &end) {  
		int chiSo = 0; 
		// ham tra ve so hoa don hop le !
		for (int i = 0; i < index;i++) {  // index ( so hoa don ) 
			  if (arrHoaDon[i]->date.isDateInRange(start,end)) {
			  	hoaDonHople[chiSo++] = arrHoaDon[i]; 
			  }
		}
		return chiSo; 
	}
	


	NodeHoaDon *timKiemHD(const string &soHD)
	{
		NodeHoaDon *tempTimKiem;
		for (int i = 0; i < this->soLuong; i++)
		{
			tempTimKiem = nv[i]->dsHoaDon.timKiemHoaDon(soHD);
			if (tempTimKiem != NULL)
			{
				return tempTimKiem; // tu nv van co the truy cap ra.
			}
		}
		return NULL;
	}

	// viet ham tra ve mang ->
	NhanVien **getDSNV()
	{
		return &nv[0];
	}

	// viet ham tra ve vi tri thu i
	NhanVien *getNhanVien(int index)
	{
		if (this->dsRong() || index < 0 || index >= this->soLuong)
		{
			return NULL;
		}
		// khong quy pham -> co the lay ve dia chi thu i
		return nv[index]; // tra ve dia Chi.
	}

	// viet 1 ham tim tra ve 1 thang NV co chua HD do
	NhanVienLapHD timKiemNhanVienLapHD(const string &soHD)
	{
		NodeHoaDon *tempTimKiem;
		NhanVienLapHD tempNVlapHD;
		for (int i = 0; i < this->soLuong; i++)
		{
			tempTimKiem = nv[i]->dsHoaDon.timKiemHoaDon(soHD);
			if (tempTimKiem != NULL)
			{
				tempNVlapHD.ptrNhanVien = nv[i];
				tempNVlapHD.ptrHoaDon = tempTimKiem;
				return tempNVlapHD;
			}
		}
		return tempNVlapHD;
	}

	// viet ham tao sap xep -> sap xep theo nhieu truong ( ho ten hoac la maNV )
	void insertionSort(bool (*khoaSoSanh)(NhanVien *, NhanVien *))
	{
		int i, j;
		NhanVien *key;
		for (i = 1; i < soLuong; i++)
		{
			key = nv[i];
			j = i - 1;
			while (j >= 0 && khoaSoSanh(nv[j], key))
			{
				nv[j + 1] = nv[j];
				j = j - 1;
			}
			nv[j + 1] = key;
		}
	}
	
	
	// viet ham ghi loai hoa don cua tat ca nhanvien 
	void ghiFileNVHDTheoLoai(string loaiHoaDon,string link) {
		int soLuong = 0; 
		ofstream fileout; 
		fileout.open(link.c_str(),ios::out | ios::trunc); 
		// tiep theo khong can ghi so luong gi ca
		for (int i = 0; i < this->soLuong;i++) 
		{
			soLuong = soLuong +  nv[i]->dsHoaDon.soHoaDonTheoLoai(loaiHoaDon); 
			nv[i]->dsHoaDon.ghiFileHoaDonTheoLoai(fileout,loaiHoaDon); 
		}
		fileout << soLuong; 
		
		fileout.close(); 
	}
	
	// viet ham tim kiem nhung 
	int traVeNhanVienTimKiemPhuHop(string stringSearch,NhanVien **result) {
		int soLuongNhanVienPhuHop = 0; 
		string tenNV; 
		string str = TienichDoHoa::chuoiThuong(stringSearch); 
		for (int i = 0;i < this->soLuong;i++) 
		{
			tenNV = TienichDoHoa::chuoiThuong(this->nv[i]->getHoTen());  
			if (strstr(tenNV.c_str(),str.c_str()))
			{
				result[soLuongNhanVienPhuHop++] = this->nv[i]; 
			}
		}
		return soLuongNhanVienPhuHop; 
	}
	
};

// 	VOID CLASS DANH SACH NHAN VIEN
void DsNhanVien::ghiFileDSNV()
{ // ham nay se duoc goi khi them xoa sua.
	ofstream fileout;
	fileout.open("data/dataNhanVien.txt", ios::out | ios::trunc); // mo ra chi ghi va xoa het
	fileout << this->soLuong << endl;
	for (int i = 0; i < this->soLuong; i++)
	{
		nv[i]->ghiFileNhanVien(fileout);
	}
	fileout.close();
}

void DsNhanVien::docFileDSNV()
{
	ifstream filein;
	filein.open("data/dataNhanVien.txt", ios::in);
	int soLuongNV;
	filein >> soLuongNV;
	filein.ignore();
	for (int i = 0; i < soLuongNV; i++)
	{
		string maNV, ho, ten, tempPhai;
		int phai, soLanTaoHD;
		getline(filein, maNV, ',');
		getline(filein, ho, ',');
		getline(filein, ten, ',');
		getline(filein, tempPhai, ',');
		filein >> soLanTaoHD;
		phai = TienichDoHoa::stringToInt(tempPhai);

		// xuong dong -> khong doc nua
		filein.ignore();
		NhanVien *newNhanVien = this->themNV(maNV, ho, ten, phai, soLanTaoHD);
		newNhanVien->dsHoaDon.docFileDSHD(filein); // doc vao file dsHD.
	}
	filein.close();
}

bool DsNhanVien::dsRong()
{
	if (soLuong == 0)
	{
		return true;
	}
	return false;
}
bool DsNhanVien::dsDay()
{
	if (soLuong == MAX)
	{
		return true;
	}
	return false;
}

void DsNhanVien::duyetDSNV()
{
	for (int i = 0; i < this->soLuong; i++)
	{
		nv[i]->inNV();
		cout << endl;
	}
}

// ham them nv => tra ve dia chi vua moi them vao.
NhanVien *DsNhanVien::themNV(const string &maNV, const string &ho, const string &ten, const int &phai, int soLanTaoHD)
{
	if (!this->dsDay())
	{
		nv[soLuong] = new NhanVien(maNV, ho, ten, phai, soLanTaoHD);
		this->soLuong++;
		return nv[soLuong - 1]; // vi tri cua thang vua moi them vao!.
	}
	return NULL; // them that bai !
}

int DsNhanVien::timKiemNVTraVeViTri(const string &maVT)
{
	for (int i = 0; i < this->soLuong; i++)
	{
		if (nv[i]->maNV == maVT)
		{
			return i;
		}
	}
	return -1;
}

NhanVien *DsNhanVien::timKiemNVTraVeDiaChi(const string &maVT)
{
	for (int i = 0; i < this->soLuong; i++)
	{
		if (nv[i]->maNV == maVT)
		{
			return nv[i];
		}
	}
	return NULL;
}

bool DsNhanVien::xoaNV(const string &maVT)
{
	int viTriXoa = this->timKiemNVTraVeViTri(maVT);
	if (this->dsRong() || viTriXoa == -1)
	{
		return false;
	}
	for (int i = viTriXoa; i < this->soLuong; i++)
	{
		nv[i] = nv[i + 1];
	}
	this->soLuong--;
	return true;
}

int DsNhanVien::soLuongNV()
{
	return this->soLuong;
}

void DsNhanVien::giaiPhongDSNV()
{
	// ham khoi tao chua he duoc goi 
	cout << "Giai Phong Nhan Vien..." << endl; 
	for (int i = 0; i < this->soLuong; i++)
	{
		nv[i]->dsHoaDon.giaiPhongListHoaDon(); // truoc tien can goi toi ham giai phong
		delete nv[i];
	}
}
