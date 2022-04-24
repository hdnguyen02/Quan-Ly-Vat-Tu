#pragma once
#include "Tienich.h"
using namespace std; 

struct HoaDon {
    string soHD;
    Date date;
    string loai;     // chi nhan 2 gia tri : X ( XUAT ) va N ( NHAP )
    ListCTHD dsCTHD; // 1 danh sach lien ket don
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
    ListCTHD* getdsCTHD(); 
    HoaDon* getinfo() {
		return &info; // tra ve dia chi !.
	}
    void ghiFileHD(ofstream &fileout) {
		fileout << info.soHD << ","; 
		info.date.ghiFile(fileout); 
		fileout << "," << info.loai << ",";
		fileout << endl; 
		info.dsCTHD.ghiFileCTHD(fileout); 
	}
	void docFileHD(ifstream &filein) { 
			getline(filein,info.soHD,','); 
			info.date.docFile(filein); 
			getline(filein,info.loai,','); 
			filein.ignore();  
			info.dsCTHD.docFileCTHD(filein); 	
	}
	
	// viet ham giai phong CTHD cua hoa don 
	void giaiPhongListCTHD() {
		this->info.dsCTHD.giaiPhongCTHD(); 
	}
};

ListCTHD* NodeHoaDon::getdsCTHD() {
	return &info.dsCTHD; 
}
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
	int soLuongHD(); 
	NodeHoaDon *timKiemHoaDon(const string &soHD);
	void duyetDSHD();
	bool xoaHD(const string &soHD );
	void giaiPhongListHoaDon();
	NodeHoaDon* themVaoDauHD(const string &soHD,const Date &date,const string& loai); 
	NodeHoaDon* themVaoCuoiHD(const string &soHD,const Date &date,const string& loai); 
	void docFileDSHD(ifstream &filein); 
	void ghiFileDSHD(ofstream &fileout); 
	int soHD(); 
	string ghepSoHD() {
		// lap qua va noi chuoi lai bang 1 dau , 
		string tempSoHD; 
		NodeHoaDon* pTemp = head; 
		while (pTemp != NULL) {
			tempSoHD =tempSoHD + pTemp->info.soHD + ", "; 
			pTemp = pTemp->pNext; 
			
		}
		// loai bo di dau cham o phia cuoi 
		tempSoHD.erase(tempSoHD.begin() + tempSoHD.length() - 2); // xoa di ki tu cuoi cung => dai ,
		return tempSoHD; 
		// co nen in ra cai le hay khong. 
		
	} 
		
	
};

int ListHoaDon::soHD() {
		int dem = 0; 
		NodeHoaDon* pTemp = head; 
		while(pTemp != NULL) {
			dem++; 
			pTemp = pTemp->pNext; 
		}	
		return dem;
	}
int ListHoaDon::soLuongHD() {
	int dem = 0; 
	NodeHoaDon* pTemp = head; 
	while(pTemp != NULL) {
		dem++; 
		pTemp = pTemp->pNext; 
	}
	return dem; 
}

void ListHoaDon::ghiFileDSHD(ofstream &fileout) {
	int slHD = this->soHD(); 
	fileout << slHD << endl; 
	NodeHoaDon* pTemp = head; 
	while(pTemp  !=  NULL ) {
		pTemp->ghiFileHD(fileout);  
		pTemp = pTemp->pNext; 
	}
}

void ListHoaDon::docFileDSHD(ifstream &filein) {
	int soLuongHD; 
	filein >> soLuongHD;
	filein.ignore();
	for (int i = 0; i < soLuongHD;i++) {
		string soHD,loai; 
		Date date; 
		getline(filein,soHD,','); 
		date.docFile(filein); 
		getline(filein,loai,','); 
		filein.ignore(); 
		NodeHoaDon* pTemp = this->themVaoCuoiHD(soHD,date,loai); 
		pTemp->getdsCTHD()->docFileCTHD(filein); 
	}
}

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
	NodeHoaDon* newNode = new NodeHoaDon(soHD,date,loai);  
	newNode->pNext = head; // tro den node dau tien 
	head = newNode;
	return newNode;
}



NodeHoaDon* ListHoaDon::themVaoCuoiHD(const string &soHD,const Date &date,const string& loai) {
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
void ListHoaDon::giaiPhongListHoaDon() {
	NodeHoaDon* pTemp; 
 	while(head != NULL) {
	 	pTemp = head; 
	 	head = head->pNext;
	 	pTemp->giaiPhongListCTHD(); 
	 	delete pTemp; 
	 	 
	 }
}
