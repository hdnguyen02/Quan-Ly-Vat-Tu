#pragma once
#include "Tienich.h"
using namespace std;

struct HoaDon
{
	string soHD;
	Date date;
	string loai;	 // chi nhan 2 gia tri : X ( XUAT ) va N ( NHAP )
	ListCTHD dsCTHD; // 1 danh sach lien ket don
	string tenNVLapHD; // ho ten cua nhan vien da lap hoaDon nay!  
	HoaDon() {}
	HoaDon(const string &soHD, const Date &date, const string &loai,const string &tenNVLapHD) : 
	date(date.ngay, date.thang, date.nam), soHD(soHD), tenNVLapHD(tenNVLapHD),loai(loai) {}
						
	void in()
		{
			cout << "so HD: " << soHD << endl;
			cout << "ngay lap hoa don: ";
			date.hienThiConsole();
			cout << endl
				 << "loai hoa don : " << loai << endl;
				 cout << "nhan vien toa hoa don : " << tenNVLapHD; 
			// cout << "HOA DON CHI TIET" << endl;
			// this->info.dsCTHD.duyetCTHD();
		}	
		
		// viet ham  tinh ra 1 
		float doanhThuBanRaVatTu(string maVT)	{
			if (this->loai == "N") { 
				return 0; 
			} 
			else {
				return this->dsCTHD.tinhTienVatTu(maVT); 
			}
		}									   
																	   
};

class NodeHoaDon
{
private:
	HoaDon info;
	NodeHoaDon *pNext;

public:
	friend class ListHoaDon;
	NodeHoaDon() : pNext(NULL) {}
	NodeHoaDon(const string &soHD, const Date &date, const string &loai,const string &tenNVLapHD) : info(soHD, date, loai,tenNVLapHD), pNext(NULL) {}
	void themCTHD(const CThoaDon &cthd);
	void inHD();
	ListCTHD *getdsCTHD();
	HoaDon *getinfo()
	{
		return &info; // tra ve dia chi !.
	}
	void ghiFileHD(ofstream &fileout)
	{
		fileout << info.soHD << ",";
		info.date.ghiFile(fileout);
		fileout << "," << info.loai << "," << info.tenNVLapHD << ",";
		fileout << endl;
		info.dsCTHD.ghiFileCTHD(fileout);
	}
	
	void ghiFileHDCoTongTien(ofstream &fileout) {
		fileout << info.soHD << ","; 
		info.date.ghiFile(fileout); 
		fileout << "," << info.loai << "," << info.tenNVLapHD << ","; 
		fileout << endl; 
		info.dsCTHD.ghiFileCTHDCoTongTienVatTu(fileout);   //sau khi tu dong xuong dong roi!. 
		
		
	}
	
	void docFileHD(ifstream &filein)
	{
		getline(filein, info.soHD, ',');
		info.date.docFile(filein);
		getline(filein, info.loai, ',');
		getline(filein,info.tenNVLapHD,','); // doc ten cua nv tao hd! 
		filein.ignore();
		info.dsCTHD.docFileCTHD(filein);
	}

	// viet ham giai phong CTHD cua hoa don
	void giaiPhongListCTHD()
	{
		this->info.dsCTHD.giaiPhongCTHD();
	}
};

ListCTHD *NodeHoaDon::getdsCTHD()
{
	return &info.dsCTHD;
}
void NodeHoaDon::inHD()
{
	cout << "so HD: " << this->info.soHD << endl;
	cout << "ngay lap hoa don: ";
	this->info.date.hienThiConsole();
	cout << endl
		 << "loai hoa don : " << this->info.loai << endl;
	// cout << "HOA DON CHI TIET" << endl;
	// this->info.dsCTHD.duyetCTHD();
}

void NodeHoaDon::themCTHD(const CThoaDon &cthd)
{
	this->info.dsCTHD.themVaoCuoiCTHD(cthd);
}

class ListHoaDon
{
private:
	NodeHoaDon *head;

public:
	ListHoaDon() : head(NULL) {}
	int soLuongHD();
	NodeHoaDon *timKiemHoaDon(const string &soHD);
	void duyetDSHD();
	bool xoaHD(const string &soHD);
	void giaiPhongListHoaDon();
	NodeHoaDon *themVaoDauHD(const string &soHD, const Date &date, const string &loai,const string &tenNVLapHD);
	NodeHoaDon *themVaoCuoiHD(const string &soHD, const Date &date, const string &loai,const string &tenNVLapHD);
	void docFileDSHD(ifstream &filein);
	void ghiFileDSHD(ofstream &fileout);
	int soHD();
	

	int soHoaDonTheoLoai( string loaiHD ) {
		int dem = 0; 
		NodeHoaDon* pTemp = head; 
		while (pTemp != NULL) {
			if (pTemp->getinfo()->loai == loaiHD) {  	// kiem tra xem co phai hoa don xuat hay khong
				dem++;
			}
			pTemp = pTemp->pNext; 
		}
		return dem; 
	}
	
	

	
	void ganMangHoaDon(HoaDon** arrHoaDon,int &index) {
	
		NodeHoaDon* pTemp = head; 
		while (pTemp != NULL) 
		{
				arrHoaDon[index++] = pTemp->getinfo(); 
				pTemp = pTemp->pNext; 
		}
	}
	
	
	// viet ham chi xuat ra hon xuat va hon nhap ra 1 ben 
	void ghiFileHoaDonTheoLoai(ofstream &fileout,string loaiHD)
	{
			NodeHoaDon* pTemp = head; 
			while (pTemp != NULL) {
				if (pTemp->getinfo()->loai == loaiHD) {
					pTemp->ghiFileHDCoTongTien(fileout); 
				}
				pTemp = pTemp->pNext;
			}
	}

		
};

int ListHoaDon::soHD()
{
	int dem = 0;
	NodeHoaDon *pTemp = head;
	while (pTemp != NULL)
	{
		dem++;
		pTemp = pTemp->pNext;
	}
	return dem;
}
int ListHoaDon::soLuongHD()
{
	int dem = 0;
	NodeHoaDon *pTemp = head;
	while (pTemp != NULL)
	{
		dem++;
		pTemp = pTemp->pNext;
	}
	return dem;
}

void ListHoaDon::ghiFileDSHD(ofstream &fileout)
{
	int slHD = this->soHD();
	fileout << slHD << endl;
	NodeHoaDon *pTemp = head;
	while (pTemp != NULL)
	{
		pTemp->ghiFileHD(fileout);
		pTemp = pTemp->pNext;
	}
}



void ListHoaDon::docFileDSHD(ifstream &filein)
{
	int soLuongHD;
	filein >> soLuongHD;
	filein.ignore();
	for (int i = 0; i < soLuongHD; i++)
	{
		string soHD, loai,tenNVLapHD; 
		Date date;
		getline(filein, soHD, ',');
		date.docFile(filein);
		getline(filein, loai, ',');
		getline(filein,tenNVLapHD,','); 
		filein.ignore();
		NodeHoaDon *pTemp = this->themVaoCuoiHD(soHD, date, loai,tenNVLapHD);
		pTemp->getdsCTHD()->docFileCTHD(filein);
	}
}

// khi truyen vao constructor hay truyen vao thang

NodeHoaDon *ListHoaDon::timKiemHoaDon(const string &soHD)
{
	NodeHoaDon *pTemp = head;
	while (pTemp != NULL)
	{
		if (pTemp->info.soHD == soHD)
		{
			return pTemp;
		}
		pTemp = pTemp->pNext;
	}
	return NULL;
}

NodeHoaDon *ListHoaDon::themVaoDauHD(const string &soHD, const Date &date, const string &loai,const string &tenNVLapHD)
{
	NodeHoaDon *newNode = new NodeHoaDon(soHD, date, loai,tenNVLapHD);
	newNode->pNext = head; // tro den node dau tien
	head = newNode;
	return newNode;
}

NodeHoaDon *ListHoaDon::themVaoCuoiHD(const string &soHD, const Date &date, const string &loai,const string &tenNVLapHD)
{
	NodeHoaDon *newNode = new NodeHoaDon(soHD, date, loai,tenNVLapHD);
	if (head == NULL)
	{
		head = newNode;
		return newNode;
	}
	NodeHoaDon *pTemp = head;
	while (pTemp->pNext != NULL)
	{
		pTemp = pTemp->pNext;
	}
	pTemp->pNext = newNode;
	return newNode;
}
void ListHoaDon::duyetDSHD()
{
	NodeHoaDon *pTemp = head;
	while (pTemp != NULL)
	{
		pTemp->inHD();
		cout << endl;
		pTemp = pTemp->pNext;
	}
}
bool ListHoaDon::xoaHD(const string &soHD)
{
	NodeHoaDon *nodeDelete = head;
	NodeHoaDon *previousNodeDelete = NULL; // node phia truoc node can delete
	while (nodeDelete != NULL && nodeDelete->info.soHD != soHD)
	{
		previousNodeDelete = nodeDelete;
		nodeDelete = nodeDelete->pNext; // tim kiem den node tiep theo
	}

	if (nodeDelete == NULL)
	{ // truong hop danh sach dang rong
		return false;
	}
	if (previousNodeDelete == NULL)
	{
		previousNodeDelete = head->pNext;
		delete nodeDelete;
		head = previousNodeDelete;
	}
	else
	{
		previousNodeDelete->pNext = nodeDelete->pNext;
		delete nodeDelete;
	}
	return true;
}
void ListHoaDon::giaiPhongListHoaDon()
{
	NodeHoaDon *pTemp;
	while (head != NULL)
	{
		pTemp = head;
		head = head->pNext;
		pTemp->giaiPhongListCTHD();
		delete pTemp;
	}
}
