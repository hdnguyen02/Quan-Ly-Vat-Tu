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






bool kiemTraSoNguyen(string str)
{
	for (int i = 0; i < str.length(); i++)
		if (isdigit(str[i]) == false)
			return false;
	return true;
}



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
	static string longLongToString(long long n) {
		stringstream ss; 
		ss << n;
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
	
	// viet ham dua string ve chu thuong  
	static string chuoiThuong(string s) {
		// lap qua qua va kiem tra
		int length = s.length();  
		for (int i = 0; i < length;i++) {
			// kiem tra xem co phai la chu thuong hay khong 
			if (s[i] <= 'Z' && s[i] >= 'A') {
				s[i] = s[i] - ('Z' - 'z'); 
			} 
		}
		return s; 
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


	
	

static void xoaKhoanTrangDauVaCuoi(string &str)
{
	while (str[0] == ' ')
	{
		str.erase(str.begin() + 0);
	}

	while (str[str.length() - 1] == ' ')
	{
		str.erase(str.begin() + str.length() - 1); 
	}
}


static void xoaKhoanTrangOGiua(string &str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == ' ' && str[i + 1] == ' ')
		{
			str.erase(str.begin() + i);
			i--;
		}
	}
}


static void inHoaKiTuDauMoiTu(string &str)
{
	if (str.length() == 0) {
		return; 
	}
	strlwr((char *)str.c_str()); 
	if (str[0] != ' ')
	{
		if (str[0] >= 97 && str[0] <= 122)
		{
			str[0] -= 32;
		}
		
	}
	for (int i = 0; i < str.length() - 1; i++)
	{
		if (str[i] == ' ' && str[i + 1] != ' ')
		{
		
			if (str[i + 1] >= 97 && str[i + 1] <= 122)
			{
				str[i + 1] -= 32;
			}
		}
	}
}

static void chuanHoaTen(string &str) {
	xoaKhoanTrangDauVaCuoi(str); 
	xoaKhoanTrangOGiua(str); 
	inHoaKiTuDauMoiTu(str); 
}


static void setText(int bkColor,int colorText,int typeFont,int size) {
	setbkcolor(bkColor); 
	setcolor(colorText); 
	settextstyle(typeFont,0,size);
}

static void hienThiThongBao(string thongBao) {
	MessageBox(NULL, thongBao.c_str(), "Thong Bao", MB_ICONINFORMATION | MB_OK);
}
static float tinhToiDaPage(int mountShow, int soPhanTuTrenMotPage)  // ham tinh ra xem co bao nhieu page !
{
	float toiDaPage = (float)mountShow / (float)soPhanTuTrenMotPage;
	if (!kiemTraSoNguyen(TienichDoHoa::floatToString(toiDaPage)))
	{
		toiDaPage = (int)toiDaPage + 1;
	}
	return toiDaPage; 
}
 	
	
};

struct Date
{
	int ngay;
	int thang;
	int nam;
	Date(int ngay, int thang, int nam) : ngay(ngay), thang(thang), nam(nam) {}
	Date() {
		this->setDateNow(); 
	}
	
	// kiem tra ngay thang nam do co bi di qua trong tuong lai hay khong 
	static bool ngayThangNamTuongLai(Date check) {  // ham return ve true neu ngay thang nam nam o tuong lai!
		// truoc tien khai bao 1 date hien tai 
		Date dateNow; 
		dateNow.setDateNow(); 
		// kiem tra so sanh ngay thang nam  // neu check <= dateNow -> thoi diem hien tai hoac qua khu 
		if (Date::soSanhBeHonHoacBangDate(check,dateNow)) {  
			return false; 
		}
		
		return true; // check lon hon hien tai -> tuong lai!
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
	
	void stringToDate(string ngay,string thang,string nam) {
		this->ngay = TienichDoHoa::stringToInt(ngay); 
		this->thang = TienichDoHoa::stringToInt(thang); 
		this->nam = TienichDoHoa::stringToInt(nam); 
	}
	
	void dateToString(string &ngay,string &thang,string &nam) {
		ngay = TienichDoHoa::intToString(this->ngay);
		thang =  TienichDoHoa::intToString(this->thang);
		nam =  TienichDoHoa::intToString(this->nam);
	}

	static bool ngayThangNamHopLe(Date check)
	{
		int ngay = check.ngay; 
		int thang = check.thang; 
		int nam = check.nam; 
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
		if (nam >= 1975) {
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
		this->removeExitButton(); // khong cho nguoi dung click vao nut X  
		// lay ra full toa do man hinh 
		
		 
	}
	~StartBGI()
	{
		closegraph();
	}
	void removeExitButton()
	{
		HMENU hmenu = GetSystemMenu(GetForegroundWindow(), FALSE);
		EnableMenuItem(hmenu, SC_CLOSE, MF_GRAYED);
	}
};

// =========================== HAM KIEM TRA KY TU ==============================
bool kiTuChuHoa(char &c)
{
	if (c >= 65 && c <= 90)
	{
		return true;
	}
	return false;
}
bool kiTuChuThuong(char &c)
{
	if (c >= 97 && c <= 122)
	{
		return true;
	}
	return false;
}
bool kiTuSo(char &c) 
{
	
	if (c >= 48 && c <= 57 )
	{
		return true;
	}
	return false;
}

bool kiTuChu(char &c)
{
	if ((kiTuChuHoa(c) || kiTuChuThuong(c) || c == 32 )  )
	{
		return true;
	}
	return false;
}
bool kiTuChuHoacSo(char &c)
{
	if (kiTuChu(c) || kiTuSo(c))
	{
		return true;
	}
	return false;
}






bool nhapID(char &c) {
	if (kiTuChuThuong(c)) { 
		 c = c - 32;
	}
	if ( (kiTuSo(c) || c == 95 || kiTuChu(c)) && c != 32 ) { 
		return true; 
	}
	return false; 
}

// khong cho pehp nhan dau space 
bool nhapTen(char &c) {
	if (kiTuChu(c) && c != 32) {  // khong phai la space 
		return true; 
	}
	return false; 
}





