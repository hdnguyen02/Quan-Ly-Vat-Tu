#pragma once
using namespace std; 
#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <sstream>
#include<winbgim.h>
#include <iostream>


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
	bool choPhepDate()
	{
		if(thang<1 || thang>12 || nam<0 || ngay<0 || ngay>31)
		{
			return false;
		}
		
		if (thang==2 || thang==4 || thang==6 || thang==9 || thang == 11)
		{
			if (ngay > 30)
				return false;
			if (thang == 2)
			{
				if ((nam%4 == 0 && nam%100 != 0) || nam%400 == 0)
				{
					if (ngay > 29)
						return false;
				}
				else
				{
					if (ngay > 28)
						return false;
				}
			}
		}
		return true;
	}
	
	bool operator > (const struct Date &other)
	{
		if (this->nam > other.nam)
			return true;
		else if (this->nam == other.nam) 
		{
			if(this->thang > other.thang)
				return true;
			else if (this->thang == other.thang)
			{
				if (this->ngay > other.ngay)
					return true;
			}
		}
		
		return false;
	}
	
	bool operator < (const struct Date &other)
	{
		if (this->nam < other.nam)
			return true;
		else if (this->nam == other.nam) 
		{
			if(this->thang < other.thang)
				return true;
			else if (this->thang == other.thang)
			{
				if (this->ngay < other.ngay)
					return true;
			}
		}
		
		return false;
	}
	
	bool operator == (const struct Date &other)
	{
		if (this->nam == other.nam)
			if (this->thang == other.thang)
				if (this->ngay == other.ngay)
					return true;
		return false;
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
//ham chuan hoa
void delBlank(char *s)
{
	for(int i = 0; i < strlen(s); i++)
	{
		if(s[i]==' ')
		{
			s[i] = s[i+1];
			for(int j = i+1;j<strlen(s)-1;j++)
			{
				s[j] = s[j+1];
			}
			s[strlen(s)-1] = '\0';
		}
	}
}


class TienichDoHoa {
	// xu dung de xoa man hinh. 
	public: 
	static void xoaManHinhTheoToaDo(int x,int y,int w,int h,int colorBack) {
		setfillstyle(SOLID_FILL, colorBack);   
		bar(x, y, x + w, y + h); 
	}
	static string floatToString(float f) {
		stringstream ss; 
		ss << f; 
		string temp; 
		ss >> temp; 
		return temp; 
	}
	static string intToString(int n) {
		stringstream ss; 
		ss << n; 
		string temp; 
		ss >> temp; 
		return temp; 
	}
	static float stringToFloat(string s) {
		stringstream ss; 
		ss << s; 
		float temp; 
		ss >> temp;
		return temp; 
	}
	static int stringToInt(string s){
		stringstream ss; 
		ss << s; 
		int temp; 
		ss >> temp; 
		return temp; 
	}
};  


	











