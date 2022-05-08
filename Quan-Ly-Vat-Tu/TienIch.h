#pragma once
using namespace std;
#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <sstream>
#include <winbgim.h>
#include <iostream>
#include <windows.h>
#include <ctime>



class TienichDoHoa
{
	// xu dung de xoa man hinh.
public:
	static void xoaManHinhTheoToaDo(int x, int y, int w, int h, int colorBack)
	{
		setfillstyle(SOLID_FILL, colorBack);
		bar(x, y, x + w, y + h);
	}
	static string floatToString(float f)
	{
		stringstream ss;
		ss << f;
		string temp;
		ss >> temp;
		return temp;
	}
	static string intToString(int n)
	{
		stringstream ss;
		ss << n;
		string temp;
		ss >> temp;
		return temp;
	}
	static float stringToFloat(string s)
	{
		stringstream ss;
		ss << s;
		float temp;
		ss >> temp;
		return temp;
	}
	static int stringToInt(string s)
	{
		stringstream ss;
		ss << s;
		int temp;
		ss >> temp;
		return temp;
	}
	static string doubleToString(double s)
	{
		stringstream ss;
		ss << s;
		string temp;
		ss >> temp;
		return temp;
	}

	static double stringToDoble(string s)
	{
		stringstream ss;
		ss << s;
		double temp;
		ss >> temp;
		return temp;
	}

	static void xoaKhoangTrangThua(string &s)
	{
		int length = s.length();
		do
		{
			if (s[0] == 32)
			{
				s.erase(0, 1);
				length--;
			}
		} while (s[0] == 32);

		do
		{
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

	static void chuanHoaTen(string &s)
	{
		xoaKhoangTrangThua(s);
		int index = 1;
		int n = s.length();
		if (s[0] >= 97 && s[0] <= 122)
		{
			s[0] = s[0] - 32;
		}
		while (index < n)
		{
			if (s[index] == 32)
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
};

struct Date
{
	int ngay;
	int thang;
	int nam;
	Date(int ngay, int thang, int nam) : ngay(ngay), thang(thang), nam(nam) {}
	Date() : ngay(0), thang(0), nam(0) {}

	static bool ngayThangNamHopLe(int ngay, int thang, int nam)
	{
		if (thang < 1 || thang > 12 || nam < 0 || ngay < 0 || ngay > 31)
		{
			return false;
		}

		if (thang == 2 || thang == 4 || thang == 6 || thang == 9 || thang == 11)
		{
			if (ngay > 30)
				return false;
			if (thang == 2)
			{
				if ((nam % 4 == 0 && nam % 100 != 0) || nam % 400 == 0)
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
	bool operator>(const struct Date &other)
	{
		if (this->nam > other.nam)
			return true;
		else if (this->nam == other.nam)
		{
			if (this->thang > other.thang)
				return true;
			else if (this->thang == other.thang)
			{
				if (this->ngay > other.ngay)
					return true;
			}
		}

		return false;
	}
	Date(string ngay, string thang, string nam)
	{
		// do toi ham
		ngay = TienichDoHoa::stringToInt(ngay);
		thang = TienichDoHoa::stringToFloat(thang);
		nam = TienichDoHoa::stringToInt(nam);
	}

	// viet ra phuong thuc nhap ngay thang nam
	void nhap()
	{
		cout << "nhap ngay: ";
		cin >> this->ngay;
		cout << "nhap thang: ";
		cin >> this->thang;
		cout << "nhap nam: ";
		cin >> this->nam;
		cin.ignore(); // xoa di bo nho dem.
	}

	// viet ham doc vao ngay tu file
	void docFile(ifstream &filein)
	{
		string temp;
		getline(filein, temp, '/');
		ngay = TienichDoHoa::stringToInt(temp);
		getline(filein, temp, '/');
		thang = TienichDoHoa::stringToInt(temp);
		getline(filein, temp, ',');
		nam = TienichDoHoa::stringToInt(temp);
	}

	void ghiFile(ofstream &fileout)
	{
		// ghi vao ngay/thang/nam kem theo dau /
		fileout << ngay << "/" << thang << "/" << nam; // chi nen ghi toi day thoi. con nhieu de do phia kia xu ly.
	}
	// viet ham hien thi ra
	void hienThiConsole()
	{
		cout << this->ngay << "/" << this->thang << "/" << this->nam;
	}
	
	bool isDateInRange( Date &start, Date &end ){
    int entryDate = (this->nam * 10000) + (this->thang * 100) + this->ngay;
    int startDate = (start.nam * 10000) + (start.thang * 100) + start.ngay;
    int endDate = (end.nam * 10000) + (end.thang * 100) + end.ngay;

    if (entryDate >= startDate && entryDate <= endDate){
        return true;
    }
    else{
        return false;
    }
}

	// return ve true neu start be hon hoac bang end !
	static bool soSanhBeHonHoacBangDate(Date &start,Date &end) {  
		// truoc tien kiem tra nam
		// neu start < end 
		if (start.nam < end.nam) { // chi khi nao nam bang hoac be hon thi moi di so sanh tiep 
			return true;
		}
		else if (start.nam == end.nam) {
			// tinh trang nam bang nha => tiep tuc di so sanh thang 
			// di so sanh thang 
			if (start.thang < end.thang) {
				return true; 
			}
			else if (start.thang == end.thang ) {
				// thang da bang nhau chi con cach so sanh ngay 
				if (start.ngay < end.ngay ) {
					return true; 
				}
				else if (start.ngay == end.ngay) {
					return true; 
				}
				// truong hop nam bang thang bang nhung ngay lon hon 
				return false; 
			}
			return false; 
		}
		return false; 
		
	}
	// tra ve string date
	string getStringDate()
	{ // chuyen doi ve string het va noi chuoi ! lai !
		// kiem tra xem ngay thang nam co du hay khong 
		if (TienichDoHoa::intToString(ngay).length() == 1 && TienichDoHoa::intToString(thang).length() == 1 ) {  // truong hop ngay chi co 1 con so
			return  "0" + TienichDoHoa::intToString(ngay) + "/" + "0" +  TienichDoHoa::intToString(thang) + "/" + TienichDoHoa::intToString(nam);
		}
		if (TienichDoHoa::intToString(ngay).length() == 1 && TienichDoHoa::intToString(thang).length() != 1) {
			return  "0" + TienichDoHoa::intToString(ngay) + "/"  +  TienichDoHoa::intToString(thang) + "/" + TienichDoHoa::intToString(nam);
		}
		if (TienichDoHoa::intToString(ngay).length() != 1 && TienichDoHoa::intToString(thang).length() == 1) {
			return  TienichDoHoa::intToString(ngay) + "/"  + "0" +  TienichDoHoa::intToString(thang) + "/" + TienichDoHoa::intToString(nam);
		}
		
		return  TienichDoHoa::intToString(ngay) + "/" + TienichDoHoa::intToString(thang) + "/" + TienichDoHoa::intToString(nam);
	}

	void setDateNow()
	{
		time_t t = time(0);
		tm *now = localtime(&t);
		this->nam = now->tm_year + 1900;
		this->thang = now->tm_mon + 1;
		this->ngay = now->tm_mday;
	}

	// viet ham kiem tra su dung dang cua ngay thang nam
	static bool hopLeNgay(int ngay)
	{
		if (ngay > 0 && ngay <= 31)
		{ // duoc cho la ngay hop le!
			return true;
		}
		return false;
	}

	static bool hopLeThang(int thang)
	{ // kiemTra Tinh Hop Le Cua thang
		if (thang > 0 && thang <= 12)
		{
			return true;
		}
		return false;
	}
	static bool hopLeNam(int nam)
	{
		string tempNam = TienichDoHoa::intToString(nam);
		if (tempNam.length() == 4 && TienichDoHoa::stringToInt(tempNam) <= 2022)
		{
			return true;
		}
		return false;
	}
	
};

class StartBGI
{
public:
	StartBGI()
	{
		int y = GetSystemMetrics(SM_CYSCREEN);
		int x = GetSystemMetrics(SM_CXSCREEN);
		initwindow(GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN) - 40);
	}
	~StartBGI()
	{
		closegraph();
	}
};

// =========================== HAM KIEM TRA KY TU ==============================
bool kiTuChuHoa(char c)
{
	if (c >= 65 && c <= 90)
	{
		return true;
	}
	return false;
}
bool kiTuChuThuong(char c)
{
	if (c >= 97 && c <= 122)
	{
		return true;
	}
	return false;
}
bool kiTuSo(char c)
{
	if (c >= 48 && c <= 57)
	{
		return true;
	}
	return false;
}

bool kiTuChu(char c)
{
	if (kiTuChuHoa(c) || kiTuChuThuong(c))
	{
		return true;
	}
	return false;
}
bool kiTuChuHoacSo(char c)
{
	if (kiTuChu(c) || kiTuSo(c))
	{
		return true;
	}
	return false;
}

bool khongPhaiKhoanCach(char c)
{
	if (c != 32)
	{
		return true;
	}
	return false;
}

bool kiTuChuHoacSoKhongCach(char c)
{
	if ((kiTuChu(c) || kiTuSo(c)) && khongPhaiKhoanCach(c))
	{
		return true;
	}
	return false;
}

bool kiemTraSoNguyen(string str)
{
	for (int i = 0; i < str.length(); i++)
		if (isdigit(str[i]) == false)
			return false;
	return true;
}

bool kiemTraSoThuc(char c)
{
	// chap nhan la ki tu so va dau .
	if (kiTuSo(c) || c == 46)
	{
		return true;
	}
}

bool nhapDate(char c) {
	if (kiTuSo(c) || c == 47) {
		return true; 
	}
	return false; 
	
}


