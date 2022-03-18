#pragma once
#include "autoload.h"
using namespace std;


// kiểu dữ liệu ngày tháng năm 
struct Date {
	int ngay;
	int thang;
	int nam;
	Date(int ngay, int thang, int nam) : ngay(ngay), thang(thang), nam(nam) {}
	Date() : ngay(0) ,thang(0) ,nam(0) {}

	
};

// bật màn hình lên
class StartBGI {
public:
	StartBGI(char* text) {
		int y = GetSystemMetrics(SM_CYSCREEN);
		int x = GetSystemMetrics(SM_CXSCREEN);
		initwindow(GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), text);

	}
	~StartBGI() {
		closegraph();
	}

};



