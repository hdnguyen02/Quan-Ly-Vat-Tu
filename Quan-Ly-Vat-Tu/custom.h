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