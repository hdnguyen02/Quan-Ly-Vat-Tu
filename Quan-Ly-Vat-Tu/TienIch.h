#pragma once
#include "autoLoad.h"
using namespace std;

// khai bao nguyen mau ham 
 

struct Date {
	int ngay;
	int thang;
	int nam;
	Date(int ngay, int thang, int nam) {
		this->ngay = ngay; 
		this->thang = thang; 
		this->nam = nam; 
	}
		
	
	Date() {
		this->ngay = 0; 
		this->thang = 0; 
		this->nam = 0; 
	}

	
};

class StartBGI {
public:
	StartBGI() {
		int y = GetSystemMetrics(SM_CYSCREEN);
		int x = GetSystemMetrics(SM_CXSCREEN);
		initwindow(GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN) - 40);

	}
	~StartBGI() {
		closegraph();
	}


};


// =========================== HAM KIEM TRA KY TU ==============================
bool kiTuChuHoa(char c) {
			if (c >= 65 && c <=90 ) {
				return true; 
			}
			return false;   
		}
	bool kiTuChuThuong(char c) {
		if (c >= 97 && c <=122) {
			return true; 
		}
		return false; 
	}
bool kiTuSo(char c) {
			if (c >= 48 && c <= 57) {
				return true;
			}
			return false; 
		}

bool kiTuChu(char c) {
		if (kiTuChuHoa(c) || kiTuChuThuong(c)){
			return true; 
		}
		return false;  	
	}
bool kiTuChuHoacSo(char c) {
		if (kiTuChu(c) || kiTuSo(c)) {
			return true; 
		}
		return false; 
}

	


// viet kieu du lieu ve duong thang 













