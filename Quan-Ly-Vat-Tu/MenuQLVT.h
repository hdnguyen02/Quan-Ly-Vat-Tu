#pragma once
using namespace std; 
#include "BstVatTu.h"
#include "ListCTHD.h"
#include "ListHoaDon.h"
#include "dsNhanVien.h"
#include "CoSoDoHoa.h"
#include "DoHoaVT.h"
#include "DoHoaHD.h"
#include "DoHoaNV.h"


// ===================================MENU ROOT=========================================================
void menuCha(BstVatTu &dsVatTu,dsNhanVien &DSNV) {  
	int index = -1;  
	const int cachLeTrenMeNu = 16; 
	int doDai = DODAIMANHINH / 4 - 29; 
	const int chieuCaoMenuCap1 = 40 ;  
	NutBam vatTu(0 + 56,cachLeTrenMeNu, doDai,chieuCaoMenuCap1,COLOR_MENU_CAP1,COLOR_HIGHT_LIGHT,COLOR_TEXT,"VAT TU");
	NutBam nhanVien(doDai + 56 + 2, cachLeTrenMeNu, doDai, chieuCaoMenuCap1,COLOR_MENU_CAP1,COLOR_HIGHT_LIGHT,COLOR_TEXT, "NHAN VIEN");
	NutBam hoaDon( doDai*2 + 56 + 4, cachLeTrenMeNu, doDai , chieuCaoMenuCap1,COLOR_MENU_CAP1,COLOR_HIGHT_LIGHT,COLOR_TEXT, "HOA DON");
	NutBam doanhThu( doDai * 3 + 56 + 6,  cachLeTrenMeNu, doDai, chieuCaoMenuCap1,COLOR_MENU_CAP1,COLOR_HIGHT_LIGHT,COLOR_TEXT, "DOANH THU");
	vatTu.veNut(); 
	nhanVien.veNut(); 
	hoaDon.veNut(); 
	doanhThu.veNut(); 
	bool kiemTra[4] = { false }; 
	int mx = -1;  
	int my = -1;
	while (true) {
		if (index != -1) {
			if (index == ID_VT) {
				index = -1 ; 
				hienThiTinhNangVatTu(dsVatTu,index,nhanVien,hoaDon,doanhThu,VatTu::soSanhTheoTen); 
			}
			else if (index == ID_NV) {
				hienThiTinhNangNhanVien(DSNV,index,vatTu,hoaDon,doanhThu,NhanVien::soSanhTheoTen); 
			}
			else if (index == ID_HD) {
				index = -1; 
				hienThiTinhNangHoaDon(dsVatTu,DSNV,index,vatTu,nhanVien,doanhThu); 
			}
		}
		if (ismouseclick(WM_MOUSEMOVE)) {
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
				hienThiTinhNangVatTu(dsVatTu,index,nhanVien,hoaDon,doanhThu,VatTu::soSanhTheoTen); 
			}
			else if (hoaDon.isMouseHover(xclick, yclick)) { 
				hienThiTinhNangHoaDon(dsVatTu,DSNV,index,vatTu,nhanVien,doanhThu); 
			}
			else if (nhanVien.isMouseHover(xclick, yclick)) {
				hienThiTinhNangNhanVien(DSNV,index,vatTu,hoaDon,doanhThu,NhanVien::soSanhTheoTen); 
			}
			else if (doanhThu.isMouseHover(xclick,yclick)) {

			}
		}
		 delay(1);  
	}	
}

// =================================MENU NHAN THAM SO==============================================
void menuQuanLyVatTu(BstVatTu &dsVatTu,dsNhanVien &DSNV) {  
	setfillstyle(SOLID_FILL, BACKGROUP);  
	bar(0, 0, 3000, 3000);
	menuCha(dsVatTu,DSNV); 
}




