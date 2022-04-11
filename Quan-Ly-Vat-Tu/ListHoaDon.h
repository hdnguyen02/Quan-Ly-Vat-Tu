#pragma once
#include "Tienich.h"
using namespace std; 

struct HoaDon {
    string soHD;
    Date date;
    string loai;     // chi nhan 2 gia tri : X ( XUAT ) va N ( NHAP )
    ListCTHD dsCTHD; 
    HoaDon() {}
    HoaDon(const string &soHD,const Date &date,const string &loai) : date(date.ngay,date.thang,date.nam) , 
	soHD(soHD) , loai(loai) {}
};

class NodeHoaDon {
	private:
    HoaDon info;
    NodeHoaDon* pNext;
	public: 
	friend class ListHoaDon; 
	NodeHoaDon() : pNext(NULL) {} 
	NodeHoaDon(const string &soHD,const Date &date,const string &loai) : info(soHD,date,loai), pNext(NULL) {}
	void themCTHD(const CThoaDon& cthd);
    void inHD() ;
};

void NodeHoaDon::inHD() {
		cout << "so HD: " << this->info.soHD << endl; 
		cout << "ngay lap hoa don: "; 
		this->info.date.hienThiConsole(); 
		cout << endl << "loai hoa don : "  << this->info.loai << endl; 
		cout << "HOA DON CHI TIET"<<endl; 
		this->info.dsCTHD.duyetCTHD(); 
}
	
void NodeHoaDon::themCTHD(const CThoaDon& cthd) {
	this->info.dsCTHD.themVaoCuoiCTHD(cthd); 
}


class ListHoaDon {
private: 
    NodeHoaDon* head;  
public: 
	
    ListHoaDon() : head(NULL) {}
    ~ListHoaDon() {this->giaiPhongHD();}; 
	int soLuongHD(); 
	NodeHoaDon *timKiemHoaDon(const string &soHD);
	void duyetDSHD();
	bool xoaHD(const string &soHD );
	void giaiPhongHD();
	NodeHoaDon* themVaoDauHD(const string &soHD,const Date &date,const string& loai); 
	NodeHoaDon* themVaoCuoiHD(const string &soHD,const Date &date,const string& loai); 
//	void docFileHoaDon(ifstream &filein); 
//	void ghiFileHoaDon();  
	
	
	// viet ham themHoaDo => ham tham khao voi doan code phia duoi ham main ( truoc khi them phai NEW )
//	bool themHD(NodeHoaDon *&newNode) {
//		newNode->pNext = head;   
//		head = newNode;
//		return true; 
//	}

	
};
int ListHoaDon::soLuongHD() {
	int dem = 0; 
	NodeHoaDon* pTemp = head; 
	while(pTemp != NULL) {
		dem++; 
		pTemp = pTemp->pNext; 
	}
	return dem; 
}
//void ListHoaDon::docFileHoaDon(ifstream &filein) {
//	int soLuongHD; 
//	filein >> soLuongHD;
//	filein.ignore();
//	HoaDon temp;  
//	for (int i = 0; i < soLuongHD;i++) {
//		getline(filein,temp.soHD,','); 
//		getline(filein,temp.loai,','); 
//		filein.ignore(); 
//		temp.dsCTHD.docFileCTHD(filein); 	  // doc sogn da tui dong xuong dong. 
//		this->themVaoCuoiHD(temp); 
//	}
//}

// khi truyen vao constructor hay truyen vao thang




NodeHoaDon* ListHoaDon::timKiemHoaDon(const string &soHD)
{
	NodeHoaDon* pTemp = head; 
	while(pTemp != NULL) {
		if (pTemp->info.soHD == soHD) {
			return pTemp; 
		}
		pTemp = pTemp->pNext; 
	}
	return NULL; 
}


NodeHoaDon* ListHoaDon::themVaoDauHD(const string &soHD,const Date &date,const string& loai) {
	
	NodeHoaDon* TempNode = this->timKiemHoaDon(soHD);  // neu node nay co ton tai -> khong duoc them. 
	if (TempNode!=NULL) {
		return NULL; 
	}
	NodeHoaDon* newNode = new NodeHoaDon(soHD,date,loai);  
	newNode->pNext = head; // tro den node dau tien 
	head = newNode;
	return newNode;
}



NodeHoaDon* ListHoaDon::themVaoCuoiHD(const string &soHD,const Date &date,const string& loai) {
	NodeHoaDon* TempNode = this->timKiemHoaDon(soHD);  // neu node nay co ton tai -> khong duoc them. 
	if (TempNode!=NULL) {
		return NULL; 
	}
	NodeHoaDon* newNode = new NodeHoaDon(soHD,date,loai); 
	if (head==NULL) {
		head = newNode;
		return newNode; 
	}
	NodeHoaDon* pTemp = head; 
	while(pTemp->pNext != NULL) {  
		pTemp = pTemp->pNext;  
	}
	pTemp->pNext = newNode; 
	return newNode;
}
void ListHoaDon::duyetDSHD() {
	NodeHoaDon* pTemp = head;
	while(pTemp != NULL) {
		pTemp->inHD(); 
		cout << endl; 
		pTemp = pTemp->pNext; 
	}
}
bool ListHoaDon::xoaHD(const string &soHD) {
	NodeHoaDon* nodeDelete = head;  
	NodeHoaDon* previousNodeDelete = NULL; // node phia truoc node can delete 
	while (nodeDelete != NULL && nodeDelete->info.soHD != soHD) {
		previousNodeDelete = nodeDelete; 
		nodeDelete = nodeDelete->pNext; // tim kiem den node tiep theo
	}

	if (nodeDelete == NULL) { // truong hop danh sach dang rong 
		return false; 
	}
	if (previousNodeDelete == NULL) {  // truong hop node can xoa la node dau tien. 
		previousNodeDelete = head->pNext; 
		delete nodeDelete; 
		head = previousNodeDelete; 	
	}
	else {
		previousNodeDelete->pNext = nodeDelete->pNext; 
		delete nodeDelete; 
	}
	return true; 
}
void ListHoaDon::giaiPhongHD() {
	NodeHoaDon* pTemp; 
 	while(head != NULL) {
	 	pTemp = head; 
	 	head = head->pNext; 
	 	delete pTemp; 
	 }
}
