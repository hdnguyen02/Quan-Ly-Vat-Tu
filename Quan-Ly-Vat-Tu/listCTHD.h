#pragma once
using namespace std;
#include "Tienich.h"
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
	void docFileCTHD(ifstream &filein) {
		CThoaDon info;  
		int soLuongCTHD; 
		filein >> soLuongCTHD; 
		filein.ignore();  
		string temp; 
		for (int i = 0; i < soLuongCTHD;i++) {
				getline(filein,info.maVT,','); 
				getline(filein,temp,','); 
				info.soLuong = TienichDoHoa::stringToFloat(temp); 
				getline(filein,temp,',');
				info.donGia = TienichDoHoa::stringToFloat(temp);
				filein >> info.VAT; 
				filein.ignore(); 
				this->themVaoCuoiCTHD(info); 
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
	NodeCTHD* NodeTrung = this->timKiemCTHD(info.maVT);  // neu node nay co ton tai -> khong duoc them. 
	if (NodeTrung) {
		return false; 
	}
	NodeCTHD* newNode = new NodeCTHD(info); 
	newNode->pNext = head; // tro den node dau tien 
	head = newNode;
	return true;
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
	while(pTemp->pNext != NULL) {  
		pTemp = pTemp->pNext;  
	}
	pTemp->pNext = newNode; 
	return true; 
}
void ListCTHD::duyetCTHD() {
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
	NodeCTHD* pTemp = head; 
	while(pTemp != NULL) {
		if (pTemp->info.maVT == maVT) {
			return pTemp; 
		}
		pTemp = pTemp->pNext; 
	}
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

void ListCTHD::giaiPhongCTHD() {
 	NodeCTHD* pTemp; 
 	while(head != NULL) {
	 	pTemp = head; 
	 	head = head->pNext; 
	 	delete pTemp; 
	 }
	
}

 ListCTHD::~ListCTHD(){
 	this->giaiPhongCTHD(); 
 }


