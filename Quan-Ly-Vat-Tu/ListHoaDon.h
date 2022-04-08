#pragma once
#include "Tienich.h"
using namespace std; 

struct HoaDon {
    string soHD;
    Date date;
    string loai;     // chi nhan 2 gia tri : X ( XUAT ) va N ( NHAP )
    ListCTHD *dsCTHD; 
    void inHD();
    
    HoaDon() {
		this->soHD = this->loai = ""; 
		dsCTHD = new ListCTHD;  
	}
//	~HoaDon() {
//			cout << endl << "giai phong cthd"<< endl; 
//			delete dsCTHD; 
//	}
	
	HoaDon(string &soHD,Date &date,string &loai,ListCTHD *dsCTHD) : soHD(soHD), date(date), loai(loai),dsCTHD(dsCTHD)
	{}
};
void HoaDon::inHD() {
	cout<<"ma: " <<this->soHD<<" "<<"ngay: "<<this->date.ngay<<"/"<<this->date.thang
	<<"/"<<this->date.nam<<" loai: "<<this->loai<<endl <<"hoa don chi tiet"<<endl; 
	this->dsCTHD->duyetCTHD(); 
}
class NodeHoaDon {
private:
    HoaDon info;
    NodeHoaDon* pNext;
public:
	friend class ListHoaDon; 
    NodeHoaDon() : pNext(NULL) {};
    NodeHoaDon(HoaDon &info) : info(info.soHD,info.date,info.loai,info.dsCTHD), pNext(NULL) {}
};



// danh sách liên ket don 

class ListHoaDon {
private: 
    NodeHoaDon* head;  
public: 
    ListHoaDon() {
		this->head = NULL;
	}
	int soLuongHD(); 
	NodeHoaDon *timKiemHoaDon(const string &soHD);
	bool themVaoDauHD(HoaDon &info);
	bool themVaoCuoiHD(HoaDon &info);
	void duyetDSHD();
	bool xoaHD(const string &soHD );
	void giaiPhongHD();
	void docFileHoaDon(ifstream &filein); 
	void ghiFileHoaDon();  
	
	
	
	
	
	
	
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
bool ListHoaDon::themVaoDauHD(HoaDon &info) {
	NodeHoaDon* TempNode = this->timKiemHoaDon(info.soHD);  // neu node nay co ton tai -> khong duoc them. 
	if (TempNode!=NULL) {
		return false; 
	}
	NodeHoaDon* newNode = new NodeHoaDon(info);
	
	
	newNode->pNext = head; // tro den node dau tien 
	head = newNode;
	return true;
}
bool ListHoaDon::themVaoCuoiHD(HoaDon &info) {
	NodeHoaDon* TempNode = this->timKiemHoaDon(info.soHD);  // neu node nay co ton tai -> khong duoc them. 
	if (TempNode!=NULL) {
		return false; 
	}
	NodeHoaDon* newNode = new NodeHoaDon(info); 
	if (head==NULL) {
		head = newNode;
		return true; 
	}
	NodeHoaDon* pTemp = head; 
	while(pTemp->pNext != NULL) {  
		pTemp = pTemp->pNext;  
	}
	pTemp->pNext = newNode; 
	return true; 
}
void ListHoaDon::duyetDSHD() {
	NodeHoaDon* pTemp = head;
	while(pTemp != NULL) {
		pTemp->info.inHD(); 
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
void ListHoaDon::giaiPhongHD()
{
	NodeHoaDon* pTemp; 
 	while(head != NULL) {
	 	pTemp = head; 
	 	head = head->pNext; 
	 	delete pTemp; 
	 }
}
