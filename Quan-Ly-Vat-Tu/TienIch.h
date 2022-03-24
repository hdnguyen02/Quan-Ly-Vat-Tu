#pragma once
#include "autoLoad.h"
using namespace std;

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









