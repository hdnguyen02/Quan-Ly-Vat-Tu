#pragma once
#include "autoLoad.h"
//using namespace std;

// khai bao nguyen mau ham 
 

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

	


	











