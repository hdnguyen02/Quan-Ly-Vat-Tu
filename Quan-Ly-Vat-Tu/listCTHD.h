#pragma once
#include "autoLoad.h"
using namespace std;

struct CThoaDon {
    string maVT;   
    float soLuong;
    float donGia; 
    float VAT;  // 10% 0,1 
    // constructor 
    CThoaDon(string maVT, float soLuong, float donGia, float VAT) :
        maVT(maVT), soLuong(soLuong), donGia(donGia), VAT(VAT) {}
    CThoaDon() {} 
    void inCTHD(); 
};


void CThoaDon::inCTHD() {
	cout << this->maVT << "  "  << this->soLuong << "  " << this->donGia  << "  " << this->VAT; 
}

class NodeCTHD { 
private:
    CThoaDon info;
    NodeCTHD* pNext;
public:
	friend class ListCTHD; 
    NodeCTHD() : pNext(NULL) { }
    NodeCTHD(CThoaDon info) : info(info.maVT, info.soLuong, info.donGia, info.VAT), pNext(NULL) {}
};

class ListCTHD {
private:
    NodeCTHD* head;
    
public:
    ListCTHD() : head(NULL) {} // khoi tao.
    ~ListCTHD();    
    bool isNull(); 
    // viet ham push 
    bool themVaoDauCTHD(const CThoaDon &info);  // return ve true neu them thanh cong  
 	bool themVaoCuoiCTHD(const CThoaDon &info); 
 	void duyetCTHD(); 
	NodeCTHD* timKiemCTHD(const string& maVT); 
	bool xoaCTHD(const string& maVT);
	void giaiPhongCTHD(); 
	
	// viet ham doc ghi file.  truyen file se doc 
	void docFileCTHD(ifstream &filein,const string& duongDan) {
		int soLuongCTHD; 
		CThoaDon info;  
		filein >> soLuongCTHD; 
		filein.ignore();  
		for (int i = 0; i < soLuongCTHD;i++) {
				getline(filein,info.maVT,','); 
				getline(filein,info.ten,','); 
				getline(filein,info.donVi,',');
				filein >> info.soLuongTon; 
				filein.ignore(); 
				this->themVT(info); 
			}
		filein.close(); 
	}
};

bool ListCTHD::isNull() {
	if (head == NULL) {
		return true; 
	}
	return false; 
}
bool ListCTHD::themVaoDauCTHD(const CThoaDon &info) {  // tem vao dau CTHD 
//	NodeCTHD* NodeTrung = this->timKiemCTHDTheoMaVT(info.maVT);  // neu node nay co ton tai -> khong duoc them. 
//	if (NodeTrung) {
//		return false; 
//	}
	NodeCTHD* newNode = new NodeCTHD(info); 
	newNode->pNext = head; // tro den node dau tien 
	head = newNode;
}

bool ListCTHD::themVaoCuoiCTHD(const CThoaDon &info) {
	
	NodeCTHD* kiemTraNodeTrung = this->timKiemCTHD(info.maVT);  // neu node nay co ton tai -> khong duoc them. 
	if (kiemTraNodeTrung) {
		return false; 
	}
	NodeCTHD* newNode = new NodeCTHD(info); 
	if (this->isNull()) {
		head = newNode;
		return true; 
	}
	
	NodeCTHD* pTemp = head; 
	while(pTemp->pNext != NULL) { // chua phai node cuoi cung. 
		pTemp = pTemp->pNext;  
	}
	pTemp->pNext = newNode; 
	return true; 
}
void ListCTHD::duyetCTHD() {
	// duyet den cuoi 
	NodeCTHD* pTemp = head;
	while(pTemp != NULL) {
		pTemp->info.inCTHD(); 
		cout << endl; 
		pTemp = pTemp->pNext; 
	}
}

// ta can phai lam them cac ham sau: ham tiem kiem theo maVT. ( tuc la trong CTHD khong có hai thu can luu y 
// thu nhat la maVT do can phai ton tai va thu 2 la maVT do khong duoc trung truoc do. 
NodeCTHD* ListCTHD::timKiemCTHD(const string& maVT) {
	// tim kiem thay la return ve dia chi cua node do => khong co la ve NULL 
	NodeCTHD* pTemp = head; 
	while(pTemp != NULL) {
		// kiem tra 
		if (pTemp->info.maVT == maVT) {
			// tra ve dia chi cua node dang dung 
			return pTemp; 
		}
		pTemp = pTemp->pNext; 
	}
	// khong tim thay 
	return NULL; 
}

// viet ham xoa theo maVT 
bool ListCTHD::xoaCTHD(const string& maVT) {
	NodeCTHD* nodeDelete = head;  
	NodeCTHD* previousNodeDelete = NULL; // node phia truoc node can delete 
	while (nodeDelete != NULL && nodeDelete->info.maVT != maVT) {
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

// ham giai phong danh sach 
void ListCTHD::giaiPhongCTHD() {
	// giai phong tu node dau tien truoc => sau do den node sau cung 
	// neu danh sach rong thi khong can lam gi ca 
 	NodeCTHD* pTemp; 
 	while(head != NULL) {
	 	pTemp = head; 
	 	head = head->pNext; 
	 	cout << "delete : " << pTemp->info.maVT << endl; 
	 	delete pTemp; 
	 }
	
}

 ListCTHD::~ListCTHD(){
 	this->giaiPhongCTHD(); 
 }


