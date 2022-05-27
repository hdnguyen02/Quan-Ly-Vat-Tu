#pragma once
using namespace std;
#include "Tienich.h"
#include "BienDoHoa.h"
#include <algorithm>

//=====================================STRUCT NUT BAM==================================================

struct NutBam
{
	int x, y, w, h;
	int colorBack, colorHight, colorText;
	string tieuDe;
	bool duocTroVao;

	NutBam(int x, int y, int w, int h, int colorBack, int colorHight, int colorText, string tieuDe)
	{
		this->set(x,y,w,h,colorBack,colorHight,colorText,tieuDe); 
	}
	
	// viet mot ham y chang cai nay 
	void set(int x, int y, int w, int h, int colorBack, int colorHight, int colorText, string tieuDe) {	
		this->x = x;
		this->y = y;
		this->w = w;
		this->h = h;
		this->tieuDe = tieuDe;
		this->duocTroVao = false;
		this->colorBack = colorBack;
		this->colorHight = colorHight;
		this->colorText = colorText;
		
	}
	
	void duocChon()
	{
		this->duocTroVao = true;
		this->veNut();
	}

	NutBam(){};
	bool isMouseHover(int mx, int my)
	{
		if (mx >= x && mx <= x + w && my >= y && my <= y + h)
		{
			return true;
		}
		return false;
	}

	void veNut()
	{
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
		if (duocTroVao)
			TienichDoHoa::setText(colorHight,colorText,10,1); 
		else
			TienichDoHoa::setText(colorBack,colorText,10,1);
		outtextxy(toaDoTextX, toaDoTextY, arr);
	}
	
	void veNutCanTrai() {
		setfillstyle(SOLID_FILL, duocTroVao ? colorHight : colorBack); // bo bua.
		TienichDoHoa::setText(colorBack,colorText,10,1); 
		bar(x, y, x + w, y + h);
		int text_h = textheight(this->tieuDe.c_str());
		int toaDoTextY = y + (h - text_h) / 2; // da tim ra toa do Y 
		outtextxy(x + 10,toaDoTextY,this->tieuDe.c_str()); 		
	}


	void khongDuocChon()
	{
		this->duocTroVao = false;
		this->veNut();
	}
	
	void thayDoiTieuDeNut(string tieuDe) {
		this->tieuDe = tieuDe;
		this->veNut(); 
	}
};

// ====================================STRUCT O NHAP===============================================
struct ONhap
{
	int x, y, w, h, SLKTTD;
	string boNhoDem;
	int widthTitle, colorTitle, colorBgoiY;
	string tieuDe; 
	bool khongDuocNhap, daNhapDauCham;
	bool isClick; 
	int mauNen;
	ONhap() {}
	ONhap(int x, int y, int w, int h, int widthTitle, string tieuDe, int colorTitle, int colorBgoiY, int SLKTTD,int mauNen = COLOR_BACKGROUP_INPUT )
	{
		this->x = x;
		this->y = y;
		this->w = w;
		this->h = h;
		this->tieuDe = tieuDe;
		this->widthTitle = widthTitle;
		this->boNhoDem = "";
		this->SLKTTD = SLKTTD; // so luong ki tu duoc nhap.
		this->colorTitle = colorTitle;
		this->colorBgoiY = colorBgoiY;
		this->khongDuocNhap = false;
		this->daNhapDauCham = false; // chua he nhap dau . nao =>  su dung cho ham nhap KiTu
		this->isClick = false; // khi nguoi dung nhap vao nut nay tuc la form dang duoc chon
		this->mauNen = mauNen; 
	}

	void veONhap()
	{
		// co 3 trang thai -> trang thai khong duoc nhap 
		int colorBack; 
		if (this->khongDuocNhap) {
			colorBack = COLOR_DISABLE; 
		}
		else if (this->isClick) {  // tiep theo neu tinh trang o nhap dang la click -> ve theo 
			colorBack = COLOR_NHAP; // form dang duoc nhap vao vi vay cho nen cho nay ve lai mau 
		}
		else {
			colorBack = mauNen; 
		}
		NutBam boxTieuDe(x, y, widthTitle, h, colorTitle, 3, 15, tieuDe);
		boxTieuDe.veNut();
		setfillstyle(SOLID_FILL,colorBack);
		bar(x + widthTitle, y, x + widthTitle + w, y + h);
	}
	
	void veONhapKhiNhap() {
		setfillstyle(SOLID_FILL, COLOR_NHAP);
		bar(x + widthTitle, y, x + widthTitle + w, y + h);
	}

	// viet mot ham chuan hoa -> ho ten
	void chuanHoa()
	{
		TienichDoHoa::chuanHoaTen(this->boNhoDem);
		this->xoaNoiDungONhap();
		this->inNoiDung();
	}

	void xoaKiTuCuoi()
	{
		this->boNhoDem.erase(this->boNhoDem.size() - 1); // xoa di ki tu cuoi cung.
	}
	
	// return ve true neu boNhoDem khong rong 
	bool khongRong() {
		if (this->boNhoDem != "") {
			return true;
		}
		return false;
	}

	void xoaNoiDungONhap()
	{
		TienichDoHoa::xoaManHinhTheoToaDo(x + widthTitle, y, w, h, COLOR_BACKGROUP_INPUT); // xoa song ve lai
		this->veONhap(); 

	}
	
	void thayDoiNoiDung(string s) {
		this->boNhoDem = s; 
		this->xoaNoiDungONhap(); 
		this->inNoiDung(); 
	}
	void inNoiDung()
	{
		int colorBack;
		if (this->isClick) {
			colorBack = COLOR_NHAP; 
		}
		else if (this->khongDuocNhap) {
			colorBack = COLOR_DISABLE; 
		}
		else {
			colorBack = mauNen; 	
		}
		int text_h;
		TienichDoHoa::setText(colorBack,COLOR_TEXT_INPUT,10,1); 
		text_h = textheight(&boNhoDem[0]);
		int toaDoTextY = y + (h - text_h) / 2;
		outtextxy(x + CACH_LE_O_NHAP + widthTitle, toaDoTextY, &boNhoDem[0]);
	}
	
	void xoaBoNhoDem () {
		while (kbhit())
		{ 
			getch();
		}
	}

	void NhapVao(bool (*loaiKiTu)(char&), const string &goiY)  // cho phep thay doi ki tu
	{
		
		if (khongDuocNhap == true)
		{
			return;
		}
		this->isClick = true;
		this->veONhap();
		this->xoaBoNhoDem(); 
		int the_end = 0;
		char c;
		bool kiemTraBackSpace = false;
		do
		{
			boNhoDem = boNhoDem + "-"; // them dau gach nhay.
			if (kiemTraBackSpace)
			{
				this->xoaNoiDungONhap();
				kiemTraBackSpace = false;
			}
			this->inNoiDung();
			this->xoaKiTuCuoi();
			c = getch();
			if (c == ENTER || c == ESC)
			{
				this->isClick  = false; 
				this->xoaGoiY();
				the_end = 1;
				this->veONhap(); 
				this->xoaNoiDungONhap(); 
				this->inNoiDung();
				
			}
			
			
			else if (c == BACK_SPACE && !boNhoDem.empty() )
			{
				this->xoaGoiY();
				boNhoDem.erase(boNhoDem.size() - 1);
				kiemTraBackSpace = true;
			}
			else if (SLKTTD <= boNhoDem.length())
			{
				this->xoaGoiY();
				string temp = "toi da " + TienichDoHoa::intToString(SLKTTD) + " ki tu!";
				TienichDoHoa::setText(colorBgoiY,4,2,5); 
				outtextxy(x, y + h + 3, &temp[0]);
			}
			else if (!loaiKiTu(c))
			{
				this->xoaGoiY();
				TienichDoHoa::setText(colorBgoiY,4,2,5); 
				outtextxy(x, y + h + 3, (char *)goiY.c_str());
			}
			else if (c == SPACE)
			{
				this->xoaGoiY();
				boNhoDem = boNhoDem + " ";
			}
			else if (loaiKiTu(c))
			{ 
				this->xoaGoiY();
				boNhoDem = boNhoDem + c;
			}			
		} while (!the_end);
	}

	void nhapSoThuc(const string &goiY)
	{
		if (khongDuocNhap == true)
		{
			return;
		}
		this->isClick = true; 
		this->veONhap(); 
		this->xoaBoNhoDem();

		int the_end = 0;
		char c;
		bool kiemTraBackSpace = false;
		do
		{
			boNhoDem = boNhoDem + "-"; 
			if (kiemTraBackSpace)
			{
				this->xoaNoiDungONhap();
				kiemTraBackSpace = false;
			}
			this->inNoiDung();
			this->xoaKiTuCuoi();
			c = getch();
			if (c == ENTER || c == ESC)
			{
				this->isClick = false; 
				if (boNhoDem[boNhoDem.length() - 1] == DAUCHAM)
				{
					this->xoaKiTuCuoi();
				}
				this->xoaGoiY();
				the_end = 1;
				this->boNhoDem.erase(remove(this->boNhoDem.begin(), this->boNhoDem.end(), SPACE), this->boNhoDem.end());  // cho nay xoa di bo nhhodem 
				this->xoaNoiDungONhap();
				this->inNoiDung();
			}
			else if (c == BACK_SPACE && !boNhoDem.empty())
			{
				if (boNhoDem[boNhoDem.length() - 1] == 46)
				{
					daNhapDauCham = false;
				}
				this->xoaGoiY();
				boNhoDem.erase(boNhoDem.size() - 1);
				kiemTraBackSpace = true;
			}
			else if (SLKTTD <= boNhoDem.length())
			{
				this->xoaGoiY();
				setcolor(4);
				setbkcolor(colorBgoiY);
				string temp = "toi da " + TienichDoHoa::intToString(SLKTTD) + " ki tu!";
				settextstyle(SMALL_FONT, HORIZ_DIR, 6);
				outtextxy(x, y + h + 3, &temp[0]);
			}
			else if (c == DAUCHAM && daNhapDauCham == false && boNhoDem.length() != 0)
			{ 
				boNhoDem = boNhoDem + ".";
				daNhapDauCham = true;
			}
			else if (kiTuSo(c))
			{
				this->xoaGoiY();
				boNhoDem = boNhoDem + c;
			}
			else if (!kiTuSo(c))
			{
				this->xoaGoiY();
				//setcolor(4);
				// settextstyle(SMALL_FONT, HORIZ_DIR, 6);
				//setbkcolor(colorBgoiY);
				TienichDoHoa::setText(colorBgoiY,4,2,5); 
				outtextxy(x, y + h + 3, goiY.c_str());
			}

		} while (!the_end);
	}

	void xoaGoiY()
	{
		TienichDoHoa::xoaManHinhTheoToaDo(x - 2, y + 1 + h, w + 54, 25, colorBgoiY);
	}
	void resetBoNhoDem()
	{
		this->boNhoDem = "";
		this->xoaNoiDungONhap();
	}
	

	bool isMouseHover(int mx, int my)
	{
		if (mx >= x && mx <= x + w + widthTitle && my >= y && my <= y + h)
		{
			return true;
		}
		return false;
	}
	
	void voHieuHoa() {
		this->khongDuocNhap = true; 
		this->veONhap(); 
		this->inNoiDung(); 
	}
};

//===========================================STRUCT OVUONG==============================================
struct OVuong
{
	int x, y, w, h, mauOVuong;
	OVuong(int x, int y, int w, int h, int mauOVuong)
	{
		this->x = x;
		this->y = y;
		this->w = w;
		this->h = h;
		this->mauOVuong = mauOVuong;
		this->veOVuong();
	}
	OVuong()
	{
		x = 0;
		y = 0;
	}
	void veOVuong()
	{
		setcolor(mauOVuong);
		rectangle(x, y, x + w, y + h);
	}
};
