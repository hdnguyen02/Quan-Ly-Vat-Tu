#pragma once
#include "autoLoad.h"
using namespace std; 




// dinh nghia cac phim nong 
#define ENTER 13 
#define ESC 27 // nut thoat 
#define BACK_SPACE 8
#define SPACE 32



#define DODAIMANHINH 1536
#define BACKGROUP 7 // mau xam
#define COLOR_MENU_CAP1 1   // màu LIGHTBLUE
#define COLOR_HIGHT_LIGHT 8    // mau LIGHTMAGENTA 
#define COLOR_TEXT 3


// cap do menu 1
#define ID_VT 0 
#define ID_NV 1
#define ID_HD 2
#define ID_DT 3


// ID cua cac menu con cua ID_VT 
#define ID_THEM_VT 4 
#define ID_HIEUCHINH_VT 5
#define ID_IN_VT 6 


// mau cho cac nut con 
#define COLOR_BTN_SUB 2  // mau cua cac nut con 




// dinh nghia mau nen o Nhap 
#define COLOR_BACKGROUP_INPUT 15
#define COLOR_BODER_INPUT 1
#define CACH_LE_O_NHAP 10   // cach cai thanh o nhap ra bao nhieu px
#define COLOR_TEXT_INPUT 2

// Nguyen mau ham 
struct NutBam; 
struct ONhap;
class TienIchDoHoa;  
void menuQuanLyVatTu(); 
void menuCha();
void hienThiTinhNangVatTu(int &index,NutBam &nhanVien,NutBam &hoaDon,NutBam &doanhThu); 
void hienThiInputVatTu(); 


void hienThiInputVatTu() {
	// ve ra form vatTu. 
	
}


// dung de chua cac ham lien quan den do hoa. 
class TienIchDoHoa {
	// xu dung de xoa man hinh. 
	public: 
	static void xoaManHinhTheoToaDo(int x,int y,int w,int h,int colorBack) {
		setfillstyle(SOLID_FILL, colorBack);   
		bar(x, y, x + w, y + h); 
	}
};  



struct ONhap {
	int x,y, w, h; 
	string boNhoDem; 
	string goiY; // goi cho nguoi dung nen nhap nhung gi. 
	int loaiNhap; // quy dinh nhap duoc nhap nhung gi 
	// 0 : nhap ca so lan chu 
	// 1 : chi duoc nhap chu ( co the in hoac thuong ). 
	// 2 : chi duoc nhap so
	// 3 : chi duoc nhap chu in
	// tuy theo loai quy dinh o day. truoc tien cho nhap tat ca. 
	string tieuDe; // hien thi phia truoc duoi dang 1 o vuong  
	bool duocChon; // trang thai co duoc chon hay khong 
	
	
	
	bool isMouseHover(int mx, int my) {  // tra ve xem nguoi dung co nhap vao chon hay khong. 
		if (mx >= x && mx <= x + w && my >= y && my <= y + h) {
			return true;
		}
		return false;
	}
	
	ONhap() {}
	ONhap(int x,int y,int w,int h,string tieuDe) { 
		// ve ra cai form nhap 
		this->x= x; 
		this->y = y; 
		this->w = w; 
		this->h = h; 
		this->tieuDe = tieuDe; 
		this->duocChon = false; // lan dau tao ra nen chua duoc nhap. 
		this->boNhoDem = ""; // chua co gi. 
		
		// tam thoi chua quan tam den cai tieuDe lam gi 	
	}
	// viet 1 phuong thuc de cho nguoi dung co the cho nhap vao 
	
	void veONhap() {
		setfillstyle(SOLID_FILL,COLOR_BACKGROUP_INPUT); // bo bua.
		bar(x,y,x+w,y+h);  
	}
	
	// viet hma kiem tra xem 1 ki tu nhap vao co thoa hay khong 
	bool kiTuSo(char &c) {
		if (c >= 48 && c <= 57) {
			return true; // dung chu so. 
		}
		return false; // khong phai chu so. 
	}
	
	bool kiTuChuHoa(char &c) {
		if (c >= 65 && c <=90 ) {
			// la chu hoa. 
			return true; 
		}
		return false;   
	}
	bool kiTuChuThuong(char &c) {
		if (c >= 97 && c <=122) {
			return true; 
		}
		return false; 
	}
	bool kiTuChu(char &c) {
		if (this->kiTuChuHoa(c) || this->kiTuChuThuong(c)){
			return true; // la ki tu chu hoa thi cung la ki tu chu. 
		}
		return false; // khong phai la chu. 	
	}
	
	// kiem tra vua chu vua so 
	bool kiTuChuHoacSo(char &c) {
		if (this->kiTuChu(c) || this->kiTuSo(c)) {
			return true; 
		}
		return false; 
	}
	// viet ham xoa di ki tu cuoi 
	void xoaKiTuCuoi() {
		this->boNhoDem.erase(this->boNhoDem.size() - 1); // xoa di ki tu cuoi cung. 
	}
	// hàm xoa het tat ca nhung gi nam ben trong   
	void xoaNoiDungONhap() {
		TienIchDoHoa::xoaManHinhTheoToaDo(x,y,w,h,COLOR_BACKGROUP_INPUT);  // xoa song ve lai 
		this->veONhap(); // ve lai. 
	}
	
	void NhapVao() {
		int the_end = 0;
		char c; 
		int text_h; 
		int toaDoTextY;
		bool kiemTraBackSpace = false; 
		do
		{
			boNhoDem = boNhoDem + "|"; // them dau gach nhay. 
			int n = boNhoDem.length();
    		char char_array[n + 1];
    		strcpy(char_array, boNhoDem.c_str());
    		// dieu chinh kich co va font chu nhap.
			text_h = textheight(char_array);
			toaDoTextY = y + (h - text_h) / 2;
			setbkcolor(COLOR_BACKGROUP_INPUT);  // chung mau voi cai ma no ve
			setcolor(COLOR_TEXT_INPUT); 
			settextstyle(1, 0, 2);
			// xoa het cai cu di. 
			// va xoa tu vi tri nao. 
			// xoa het. ve lai. 
			if (kiemTraBackSpace == true) {
				this->xoaNoiDungONhap();  
				kiemTraBackSpace = false;  
			}
		   	outtextxy (CACH_LE_O_NHAP,toaDoTextY, char_array);
		   	// xoa di cai phim nhap 
			this->xoaKiTuCuoi(); 
		   	c = getch();
		   	// cac dieu kien dung. khi nguoi dung nhap enter 
			// bac dieu kien 
			if (c == ENTER || c == ESC) {
				// thoat khong cho nhap nua 
				the_end = 1;  
			}
			else if (c == 's') {
				boNhoDem = boNhoDem + 's'; 
			}
			else if (c == BACK_SPACE && !boNhoDem.empty() ) {
					boNhoDem.erase(boNhoDem.size() - 1); 
					kiemTraBackSpace = true; 
			}
			else if (c == SPACE) {
				// this->xoaKiTuCuoi();  // xoa di 
				boNhoDem = boNhoDem + " " ; // dau cach gia // cong them 1 dau cach.
			}
			
			else if (this->kiTuChuHoacSo(c)) {  // lay tu ki tu nao den ki tu nao. 
				// xoa di cai dau "_" 
				// this->xoaKiTuCuoi(); 
				boNhoDem = boNhoDem + c ; 
			}
			
		} while (!the_end);
	}
	
};
 



struct NutBam {
	int  id,x, y, w, h;
	int colorBack,colorHight,colorText; 
	string tieuDe;
	bool duocTroVao;
	NutBam(int id, int x, int y, int w, int h,int colorBack,int colorHight,int colorText,string tieuDe) {
		this->id = id; 
		this->x = x; 
		this->y = y; 
		this->w = w;
		this->h = h; 
		this->tieuDe = tieuDe; 
		this->duocTroVao = false; 
		this->colorBack = colorBack; 
		this->colorHight =colorHight; 
		this->colorText = colorText;
	}
	
	// neu ham duoc chon 
	void duocChon() {
		this->duocTroVao = true; 
		this->veNut(); // ve lai nut nay voi trang thai duoc chon. 
		
		
	}
	
	NutBam() {}; 
	bool isMouseHover(int mx, int my) {  
		if (mx >= x && mx <= x + w && my >= y && my <= y + h) {
			return true;
		}
		return false;
	}

	void veNut() {
		char arr[70]; 
		strcpy(arr, tieuDe.c_str()); 
		setfillstyle(SOLID_FILL, duocTroVao ? colorHight : colorBack); // bo bua. 
		bar(x, y, x + w, y + h);
		int text_w = textwidth(arr);
		int text_h = textheight(arr);
		int toaDoTextX = x + (w - text_w) / 2;
		int toaDoTextY = y + (h - text_h) / 2;
		setcolor(colorText);
		if (duocTroVao) setbkcolor(colorHight);
		else setbkcolor(colorBack);
		settextstyle(10, 0, 1);
		outtextxy(toaDoTextX, toaDoTextY, arr);
	}
	
	// ham kiem tra xem co nen ve lai mot nut hay khong ( hover thi ve lai hoac co the khong ) 
			
			
	void kiemTraVeLai(int &mx,int &my,bool &kiemTra) { // truyen tham chieu de chay nhanh hon
		if (this->isMouseHover(mx,my)) { // con tro chuoc dang tro. 
				this->duocTroVao = true; 
				this->veNut(); 
				kiemTra = true; 
			}
		else if (kiemTra == true) {
				this->duocTroVao = false; 
				this->veNut(); 
				kiemTra = false; 
			}
		}

};


struct OVuong {
	int x, y, w, h, mauOVuong;
	 OVuong(int x,int y,int w,int h,int mauOVuong) {
	 	this->x = x;
	 	this->y = y; 
	 	this->w = w; 
	 	this->h = h; 
	 	this->mauOVuong = mauOVuong; 
	 	
	 }
	OVuong() {
		x = 0; 
		y = 0; 
	}
	void veOVuong() {
		rectangle(x, y, x + w, y + h);
	}
};



void xoaManHinh() {
	setfillstyle(SOLID_FILL, BACKGROUP);   
	bar(0, 30, 3000, 3000); 
}



void hienThiTinhNangVatTu(int &index,NutBam &nhanVien,NutBam &hoaDon,NutBam &doanhThu) {
	bool kiemTra[3] = {false};
	bool kiemTraVT[3] = {false};  
	OVuong ovVatTu(5,45,DODAIMANHINH - 12,50,2); 
	ovVatTu.veOVuong(); 
	const int chieuDaiVT = 230; 
	const int chieuCaoVT = 35;
	const int cachLeNgang = 15; 
	const int cachLeTren = 53 ;
	NutBam themVT(ID_THEM_VT,cachLeNgang ,cachLeTren,chieuDaiVT,chieuCaoVT,COLOR_BTN_SUB,COLOR_HIGHT_LIGHT,COLOR_TEXT,"THEM VAT TU");
	NutBam hieuChinhVT(ID_HIEUCHINH_VT,chieuDaiVT + cachLeNgang*2 ,cachLeTren,chieuDaiVT,chieuCaoVT,COLOR_BTN_SUB,COLOR_HIGHT_LIGHT,COLOR_TEXT,"HIEU CHINH VAT TU");
	NutBam inDSVT(ID_IN_VT,(chieuDaiVT + cachLeNgang )*2 + cachLeNgang ,cachLeTren,chieuDaiVT,chieuCaoVT,COLOR_BTN_SUB,COLOR_HIGHT_LIGHT,COLOR_TEXT,"IN DANH SACH VAT TU"); 
	themVT.veNut(); 
	hieuChinhVT.veNut() ; 
	inDSVT.veNut(); 
	
	
	// xet vong lap. kiem tra xem 
	int mx = -1; 
	int my = -1; 
	while (true) {
		// kiem tra xem co click
		// kiem tra neu co duy chuyen chuoc 
		if (ismouseclick(WM_MOUSEMOVE)) {
			getmouseclick(WM_MOUSEMOVE, mx, my);  
			nhanVien.kiemTraVeLai(mx,my,kiemTra[0]); 
			hoaDon.kiemTraVeLai(mx,my,kiemTra[1]);
			doanhThu.kiemTraVeLai(mx,my,kiemTra[2]);
			// kiem tra xem cac nut con co duoc hover hông 
			themVT.kiemTraVeLai(mx,my,kiemTraVT[0]); 
			hieuChinhVT.kiemTraVeLai(mx,my,kiemTraVT[1]); 
			inDSVT.kiemTraVeLai(mx,my,kiemTraVT[2]); 
			
		}
		// kiem tra xem co click hay hong
		else if (ismouseclick(WM_LBUTTONDOWN)) {  
			int xclick = -1;
			int yclick = -1; 
			getmouseclick(WM_LBUTTONDOWN, xclick, yclick); 
			if (nhanVien.isMouseHover(xclick,yclick)) {
				index = 1; 
				return; 
			}
			else if (hoaDon.isMouseHover(xclick,yclick)) {
					index = 2;   
					return; 
			}
			else if (doanhThu.isMouseHover(xclick,yclick)) {
					index = 3;   
					return; 
			}
			else if (themVT.isMouseHover(xclick,yclick)) { 
				// hien thi ra cai form nhap. 
				themVT.duocChon(); 
				hienThiInputVatTu() ; 
				
			}
			
			
			
			
			
			
				
		
		}

	delay(1); 
	
}
}


void hienThiTinhNangHoaDon() {

	// xoa het man hinh di 
	
	outtextxy(500,500,"hello word"); 
	cout << "thanh cong"; 
}





void menuCha() {  
	int index = -1; 
	int doDai = DODAIMANHINH / 4 - 16; 
	const int chieuCaoMenuCap1 = 40;  
	NutBam vatTu(ID_VT,0,0, doDai,chieuCaoMenuCap1,COLOR_MENU_CAP1,COLOR_HIGHT_LIGHT,COLOR_TEXT,"VAT TU");
	NutBam nhanVien(ID_NV,doDai, 0, doDai, chieuCaoMenuCap1,COLOR_MENU_CAP1,COLOR_HIGHT_LIGHT,COLOR_TEXT, "NHAN VIEN");
	NutBam hoaDon( ID_HD,doDai*2 , 0, doDai , chieuCaoMenuCap1,COLOR_MENU_CAP1,COLOR_HIGHT_LIGHT,COLOR_TEXT, "HOA DON");
	NutBam doanhThu(ID_DT, doDai * 3, 0, doDai, chieuCaoMenuCap1,COLOR_MENU_CAP1,COLOR_HIGHT_LIGHT,COLOR_TEXT, "DOANH THU");
	vatTu.veNut(); 
	nhanVien.veNut(); 
	hoaDon.veNut(); 
	doanhThu.veNut(); 
	bool kiemTra[4] = { false }; 
	int mx = -1;  
	int my = -1;

	// truoc khi thuc hien vong lap. index hien tai dang o dau 
	
	
	while (true) {
		// kiem tra xem lan lap truoc nguoi dung co nhap chon vao cho khac hay khong 
		if (index != -1) {
			// kiem tra cu the 
			if (index == 0) {
				// nguoi dung chon lai menu vatTu 
				// dieu chinh index lai 
				index = -1 ; 
				hienThiTinhNangVatTu(index,nhanVien,hoaDon,doanhThu); 
			}
			else if (index == 1) {
				hienThiTinhNangHoaDon(); 
				index = -1; 
				
			}
		}
		if (ismouseclick(WM_MOUSEMOVE)) {  // duy chuyen chuoc. 
			getmouseclick(WM_MOUSEMOVE, mx, my);  
			vatTu.kiemTraVeLai(mx,my,kiemTra[0]);   
			nhanVien.kiemTraVeLai(mx,my,kiemTra[1]); 
			hoaDon.kiemTraVeLai(mx,my,kiemTra[2]); 
			doanhThu.kiemTraVeLai(mx,my,kiemTra[3]); 
		}
		else if (ismouseclick(WM_LBUTTONDOWN)) {  
			int xclick = -1;
			int yclick = -1; 
			getmouseclick(WM_LBUTTONDOWN, xclick, yclick);  
			if (vatTu.isMouseHover(xclick, yclick)) {
				  hienThiTinhNangVatTu(index,nhanVien,hoaDon,doanhThu);  
			}
			else if (hoaDon.isMouseHover(xclick, yclick)) {
				hoaDon.duocTroVao = true;
				hoaDon.veNut();		
			}
			else if (nhanVien.isMouseHover(xclick, yclick)) {
				nhanVien.duocTroVao = true;
				nhanVien.veNut();
			
			}
			else if (doanhThu.isMouseHover(xclick,yclick)) {
				doanhThu.duocTroVao = true;
				doanhThu.veNut();
			}

		}
		 delay(1);  
	}

	
}

void menuQuanLyVatTu() {  
	 setfillstyle(SOLID_FILL, BACKGROUP);  
	bar(0, 0, 3000, 3000);
	menuCha(); 
	
	
	

}


