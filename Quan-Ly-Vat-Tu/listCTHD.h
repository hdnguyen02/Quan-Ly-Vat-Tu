#pragma once
using namespace std;
#include "Tienich.h"
struct CThoaDon {
    string maVT;   
    float soLuong;
    float donGia; 
    float VAT;  // 10% 0,1 

    CThoaDon(const string& maVT,const float& soLuong,const float& donGia,const float &VAT) :
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
    NodeCTHD(const CThoaDon &info) : info(info.maVT, info.soLuong, info.donGia, info.VAT), pNext(NULL) {}
};

class ListCTHD {
private:
    NodeCTHD* head;   
public:
    ListCTHD() : head(NULL) {} // khoi tao.
    ~ListCTHD() {this->giaiPhongCTHD();}; 
    bool isNull(); 
    NodeCTHD* themVaoDauCTHD(const CThoaDon &info);  // return ve true neu them thanh cong  
 	NodeCTHD* themVaoCuoiCTHD(const CThoaDon &info); 
 	void duyetCTHD(); 
	NodeCTHD* timKiemCTHD(const string& maVT); 
	bool xoaCTHD(const string& maVT);
	void giaiPhongCTHD(); 
	void docFileCTHD(ifstream &filein); 
	void ghiFileCTHD(ofstream &fileout); 
	int soLuongCTHD(); 
};

int ListCTHD::soLuongCTHD() {
	int dem = 0; 
	NodeCTHD* pTemp = head; 
	while(pTemp != NULL) {
		dem++; 
		pTemp = pTemp->pNext;
	} 
	return dem; 
}
void ListCTHD::ghiFileCTHD(ofstream &fileout) {
	fileout << this->soLuongCTHD() << endl;  
	NodeCTHD* pTemp = head; 
	while(pTemp != NULL) {
		fileout << pTemp->info.maVT << "," << pTemp->info.soLuong << "," << pTemp->info.donGia <<
		"," << pTemp->info.VAT << endl; 
		pTemp = pTemp->pNext; 
	}	 
}

void ListCTHD::docFileCTHD(ifstream &filein) {
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
	}

bool ListCTHD::isNull() {
	if (head == NULL) {
		return true; 
	}
	return false; 
}
NodeCTHD* ListCTHD::themVaoDauCTHD(const CThoaDon &info) {  // tem vao dau CTHD 
	if (this->timKiemCTHD(info.maVT)) {
		return NULL; 
	}
	NodeCTHD* newNode = new NodeCTHD(info); 
	newNode->pNext = head; // tro den node dau tien 
	head = newNode;
	return newNode;
}

NodeCTHD* ListCTHD::themVaoCuoiCTHD(const CThoaDon &info) {	
	if (this->timKiemCTHD(info.maVT)) {
		return NULL; 
	}
	NodeCTHD* newNode = new NodeCTHD(info); 
	if (this->isNull()) {
		head = newNode;
		return newNode; 
	}
	
	NodeCTHD* pTemp = head; 
	while(pTemp->pNext != NULL) {  
		pTemp = pTemp->pNext;  
	}
	pTemp->pNext = newNode; 
	return newNode; 
}
void ListCTHD::duyetCTHD() {
	NodeCTHD* pTemp = head;
	while(pTemp != NULL) {
		pTemp->info.inCTHD(); 
		cout << endl; 
		pTemp = pTemp->pNext; 
	}
}


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




