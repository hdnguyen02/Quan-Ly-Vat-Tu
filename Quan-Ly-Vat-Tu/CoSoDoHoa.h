#pragma once
using namespace std; 
#include "Tienich.h"
#include "BienDoHoa.h"



//=====================================STRUCT NUT BAM==================================================


struct NutBam {
	int x, y, w, h; 
	int colorBack,colorHight,colorText; 
	string tieuDe;
	bool duocTroVao;

	
	NutBam( int x, int y, int w, int h,int colorBack,int colorHight,int colorText,string tieuDe) {
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

	void duocChon() {
		this->duocTroVao = true; 
		this->veNut();  
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
		settextstyle(10, 0, 1);  
		int text_w = textwidth(arr);
		int text_h = textheight(arr);
		int toaDoTextX = x + (w - text_w) / 2;
		int toaDoTextY = y + (h - text_h) / 2;
		setcolor(colorText);
		if (duocTroVao) setbkcolor(colorHight);
		else setbkcolor(colorBack); 
		outtextxy(toaDoTextX, toaDoTextY, arr);
	}
	
	// viet ham ve lai 
	void khongDuocChon() {
		this->duocTroVao = false; 
		this->veNut(); 
	}	
	// ham kiem tra xem co nen ve lai mot nut hay khong ( hover thi ve lai hoac co the khong ) 
//	void kiemTraVeLai(int &mx,int &my,bool &kiemTra) { 
//		if (this->isMouseHover(mx,my)) { 
//				this->duocTroVao = true; 
//				this->veNut(); 
//				kiemTra = true; 
//			}
//		else if (kiemTra == true) {
//				this->duocTroVao = false; 
//				this->veNut(); 
//				kiemTra = false; 
//			}
//		}

};


// ====================================STRUCT O NHAP===============================================
struct ONhap {
	int x,y, w, h,SLKTTD;
	string boNhoDem; 
	int widthTitle,colorTitle,colorBgoiY; 
	string tieuDe; 
	bool khongDuocNhap,daNhapDauCham; 
	ONhap() {}	
	ONhap(int x,int y,int w,int h,int widthTitle,string tieuDe,int colorTitle,int colorBgoiY,int SLKTTD) { 
		this->x= x; 
		this->y = y; 
		this->w = w; 
		this->h = h; 
		this->tieuDe = tieuDe; 
		this->widthTitle = widthTitle;  
		this->boNhoDem = ""; 
		this->SLKTTD = SLKTTD;  // so luong ki tu duoc nhap. 	
		this->colorTitle = colorTitle; 
		this->colorBgoiY = colorBgoiY; 
		this->khongDuocNhap = false; 
		this->daNhapDauCham = false; // chua he nhap dau . nao =>  su dung cho ham nhap KiTu
	}

	void veONhap() {
		NutBam boxTieuDe(x,y,widthTitle,h,colorTitle,3,7,tieuDe); 
		boxTieuDe.veNut(); 		
		setfillstyle(SOLID_FILL,khongDuocNhap ? 8 :COLOR_BACKGROUP_INPUT); 
		bar(x + widthTitle,y, x+ widthTitle + w , y+h);  
	}
	
	// viet mot ham chuan hoa -> ho ten 
	void chuanHoa() {
		TienichDoHoa::chuanHoaTen(this->boNhoDem); 
		this->xoaNoiDungONhap(); 
		this->inNoiDung(); 
		this->tatHienThiBoder(); 
	}
	
	void xoaKiTuCuoi() {
		this->boNhoDem.erase(this->boNhoDem.size() - 1); // xoa di ki tu cuoi cung. 
	}
	
	void xoaNoiDungONhap() {  
		TienichDoHoa::xoaManHinhTheoToaDo(x + widthTitle,y,w,h,COLOR_BACKGROUP_INPUT);  // xoa song ve lai 
		this->veONhap();
		this->hienThiBoder(); 
	}
	
	void inNoiDung() {
			int text_h; 
			int toaDoTextY;
			settextstyle(1, 0, 2);
			text_h = textheight(&boNhoDem[0]);
			toaDoTextY = y + (h - text_h) / 2;
			setbkcolor(khongDuocNhap ? 8 :COLOR_BACKGROUP_INPUT);  // chung mau voi cai ma no ve
			setcolor(COLOR_TEXT_INPUT); 
			outtextxy (x + CACH_LE_O_NHAP + widthTitle,toaDoTextY, &boNhoDem[0]);
	}
	
	void tatHienThiBoder() {
		setcolor(COLOR_BACKGROUP_INPUT); 
		rectangle(x + widthTitle,y,x + w + widthTitle ,y + h); // hien thi thanh sang cai boder len. 
	}
	
	// viet 1 ham chuan xoa di khoan trang 
	void chuanHoaXoaKhoanTrang() {
		TienichDoHoa::xoaKhoangTrangThua(this->boNhoDem); 
		this->xoaNoiDungONhap(); 
		this->inNoiDung(); 
		this->tatHienThiBoder(); 
	}
	
	
	
	
	void NhapVao(bool(*loaiKiTu)(char),const string& goiY) {
		if (khongDuocNhap == true) {
			return; 
		}
		while(kbhit()) {  // xoa di bo nho dem!
			getch();
		}
		this->hienThiBoder(); 
		int the_end = 0;
		char c; 
		bool kiemTraBackSpace = false; 
		do
		{
			boNhoDem = boNhoDem + "_"; // them dau gach nhay. 
			if (kiemTraBackSpace) {
				this->xoaNoiDungONhap();  
				kiemTraBackSpace = false;  
			}
		   	this->inNoiDung(); 
			this->xoaKiTuCuoi(); 
		   	c = getch();
			if (c == ENTER || c == ESC) {
				this->xoaGoiY();
				the_end = 1;  
				TienichDoHoa::xoaKhoangTrangThua(this->boNhoDem); 
				this->xoaNoiDungONhap();
				this->inNoiDung(); 
				this->tatHienThiBoder(); 		
			}
			else if (c == BACK_SPACE && !boNhoDem.empty() ) {
					// kiem tra xem neu da xoa di dau . thi bat lai trang thai cho nhap vao dau . tiep tuc 
					
					this->xoaGoiY();
					boNhoDem.erase(boNhoDem.size() - 1); 
					kiemTraBackSpace = true; 			
			}
			else if (SLKTTD <= boNhoDem.length()) {
				this->xoaGoiY(); 
				setcolor(4);
				setbkcolor(colorBgoiY);
				string temp = "toi da " + TienichDoHoa::intToString(SLKTTD) + " ki tu!"; 
				settextstyle(SMALL_FONT, HORIZ_DIR, 6);
				outtextxy(x,y + h + 3,&temp[0]); 
			}
 			else if (c == SPACE ) {
 				this->xoaGoiY();
				boNhoDem = boNhoDem + " " ; 	
			}		
			else if (loaiKiTu(c)) {
				this->xoaGoiY();
				boNhoDem = boNhoDem + c; 
			}	
			else if (!loaiKiTu(c)) {
				this->xoaGoiY();
				setcolor(4); 
				settextstyle(SMALL_FONT, HORIZ_DIR, 6);
				setbkcolor(colorBgoiY); 
				outtextxy(x,y + h + 3,(char*) goiY.c_str()); 	
			}					
		} while (!the_end);
	}
	
	void nhapSoThuc(const string& goiY) {
		if (khongDuocNhap == true) {
			return; 
		}
		while(kbhit()) {  // xoa di bo nho dem!
			getch();
		}
		this->hienThiBoder(); 
		int the_end = 0;
		char c; 
		bool kiemTraBackSpace = false; 
		do
		{
			boNhoDem = boNhoDem + "_"; // them dau gach nhay. 
			if (kiemTraBackSpace) {
				this->xoaNoiDungONhap();  
				kiemTraBackSpace = false;  
			}
		   	this->inNoiDung(); 
			this->xoaKiTuCuoi(); 
		   	c = getch();
			if (c == ENTER || c == ESC) {
				if (boNhoDem[boNhoDem.length() - 1] == 46) {
					this->xoaKiTuCuoi(); 
				}
				this->xoaGoiY();
				the_end = 1;  
				TienichDoHoa::xoaKhoangTrangThua(this->boNhoDem); 
				this->xoaNoiDungONhap();
				this->inNoiDung(); 
				this->tatHienThiBoder(); 		
			}
			else if (c == BACK_SPACE && !boNhoDem.empty() ) {
					if (boNhoDem[boNhoDem.length()-1] == 46) {
						daNhapDauCham = false; 
					}
					this->xoaGoiY();
					boNhoDem.erase(boNhoDem.size() - 1); 
					kiemTraBackSpace = true; 			
			}
			else if (SLKTTD <= boNhoDem.length()) {
				this->xoaGoiY(); 
				setcolor(4);
				setbkcolor(colorBgoiY);
				string temp = "toi da " + TienichDoHoa::intToString(SLKTTD) + " ki tu!"; 
				settextstyle(SMALL_FONT, HORIZ_DIR, 6);
				outtextxy(x,y + h + 3,&temp[0]); 
			}
 			else if (c == SPACE ) {
 				this->xoaGoiY();
				boNhoDem = boNhoDem + " " ; 	
			}
			else if (c == 46 && daNhapDauCham == false && boNhoDem.length() != 0) { // la dau .
				boNhoDem = boNhoDem + "."; 
				daNhapDauCham = true; 	
			}	
			else if (kiTuSo(c)) {  
				this->xoaGoiY();
				boNhoDem = boNhoDem + c; 
			}	
			else if (!kiTuSo(c)) {
				this->xoaGoiY();
				setcolor(4); 
				settextstyle(SMALL_FONT, HORIZ_DIR, 6);
				setbkcolor(colorBgoiY); 
				outtextxy(x,y + h + 3,goiY.c_str()); 	
			}
									
		} while (!the_end);
	}
	
	void xoaGoiY() {
		TienichDoHoa::xoaManHinhTheoToaDo(x -2,y+ 1 + h,w + 40,25,colorBgoiY); 	
	}
	void resetBoNhoDem() {
		this->boNhoDem = ""; 
		this->xoaNoiDungONhap(); 
		this->tatHienThiBoder(); 
	}	
	void hienThiBoder() {
		setcolor(14); 
		settextstyle(5,0,14);
		rectangle(x + widthTitle,y,x + w + widthTitle ,y + h); 
	}
	
	bool isMouseHover(int mx, int my) {   
		if (mx >= x && mx <= x + w + widthTitle && my >= y && my <= y + h) {
			return true;
		}
		return false;
	}
};

//===========================================STRUCT OVUONG==============================================
struct OVuong {
	int x, y, w, h, mauOVuong;
	 OVuong(int x,int y,int w,int h,int mauOVuong) {
	 	this->x = x;
	 	this->y = y; 
	 	this->w = w; 
	 	this->h = h; 
	 	this->mauOVuong = mauOVuong; 
	 	this->veOVuong(); 
	 	
	 }
	OVuong() {
		x = 0; 
		y = 0; 
	}
	void veOVuong() {
		setcolor(mauOVuong);
		rectangle(x, y, x + w, y + h);
	}
};
