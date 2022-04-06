#pragma once
using namespace std; 
#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <sstream>
#include<winbgim.h>
#include <iostream>


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


struct Dates
{
	int day;
	int month;
	int year;
	
	Dates()
	{
		day = 1;
		month = 1;
		year = 1;
	}
	bool isValid()
	{
		if(month<1 || month>12 || year<0 || day<0 || day>31)
		{
			return false;
		}
		
		if (month==2 || month==4 || month==6 || month==9 || month == 11)
		{
			if (day > 30)
				return false;
			if (month == 2)
			{
				if ((year%4 == 0 && year%100 != 0) || year%400 == 0)
				{
					if (day > 29)
						return false;
				}
				else
				{
					if (day > 28)
						return false;
				}
			}
		}
		return true;
	}
	
	bool operator > (const struct Dates &other)
	{
		if (this->year > other.year)
			return true;
		else if (this->year == other.year) 
		{
			if(this->month > other.month)
				return true;
			else if (this->month == other.month)
			{
				if (this->day > other.day)
					return true;
			}
		}
		
		return false;
	}
	
	bool operator < (const struct Dates &other)
	{
		if (this->year < other.year)
			return true;
		else if (this->year == other.year) 
		{
			if(this->month < other.month)
				return true;
			else if (this->month == other.month)
			{
				if (this->day < other.day)
					return true;
			}
		}
		
		return false;
	}
	
	bool operator == (const struct Dates &other)
	{
		if (this->year == other.year)
			if (this->month == other.month)
				if (this->day == other.day)
					return true;
		return false;
	}
};
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
	
	// viet ham doc vao ngay tu file 
	void docFile(ifstream &filein) { 
		// doc toi dau / thi dung 
		string temp; 
		
		getline(filein,temp,'/'); 
		ngay = TienichDoHoa::stringToInt(temp); 
		getline(filein,temp,'/'); 
		thang = TienichDoHoa::stringToInt(temp); 
		getline(filein,temp); 
		nam = TienichDoHoa::stringToInt(temp); 
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




	




void xoaKhoangTrangThua(string &s) {
	int length = s.length();
	do
	{
		if (s[0] == 32)
		{
			s.erase(0, 1);
			length--;
		}
	} while (s[0] == 32);

	do {
		if (s[length - 1] == 32)
		{
			s.erase(length - 1, 1); 
			length--; 
		}
	} while (s[length - 1] == 32);

	for (int i = 1; i < length - 1; i++)
	{
		if (s[i] == 32 && s[i + 1] == 32)
		{
			s.erase(i, 1);
			length--;
			i--;
		}
	}
}



void chuanHoaTen(string &s) {

	xoaKhoangTrangThua(s);
	int index = 1;
	int n = s.length();
	if (s[0] >= 97 && s[0] <= 122) 
	{
		s[0] = s[0] - 32;
	}
	while (index < n)
	{
		if (s[index] == 32   ) 
		{
				if (s[index + 1] >= 97 && s[index + 1] <= 122) 
				{
					s[index + 1] = s[index + 1] - 32;
					index++;
					
				}
		}
		
		else if (s[index] >= 65 && s[index] <= 90)
			{
				s[index] = s[index] + 32;
			}
		
		index++;
	}
		
}






