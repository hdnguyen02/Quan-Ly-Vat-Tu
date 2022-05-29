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
#include "DoHoaDT.h"
#include "GioiThieu.h"

// ===================================MENU ROOT=========================================================
void menuCha(BstVatTu &dsVatTu, DsNhanVien &DSNV)
{
	int index = -1;
	const int cachLeTrenMeNu = 16;
	int doDai = DODAIMANHINH / 5 - 29;
	const int chieuCaoMenuCap1 = 40;
	NutBam vatTu(0 + 56, cachLeTrenMeNu, doDai, chieuCaoMenuCap1, COLOR_MENU_CAP1, COLOR_HIGHT_LIGHT, COLOR_TEXT, "VAT TU");
	NutBam nhanVien(doDai + 56 + 2, cachLeTrenMeNu, doDai, chieuCaoMenuCap1, COLOR_MENU_CAP1, COLOR_HIGHT_LIGHT, COLOR_TEXT, "NHAN VIEN");
	NutBam hoaDon(doDai * 2 + 56 + 4, cachLeTrenMeNu, doDai, chieuCaoMenuCap1, COLOR_MENU_CAP1, COLOR_HIGHT_LIGHT, COLOR_TEXT, "HOA DON");
	NutBam doanhThu(doDai * 3 + 56 + 6, cachLeTrenMeNu, doDai, chieuCaoMenuCap1, COLOR_MENU_CAP1, COLOR_HIGHT_LIGHT, COLOR_TEXT, "DOANH THU");
	
	// thiet ke nut dong chuong trinh 
	NutBam dongChuongTrinh(doDai * 4 + 56 + 8, cachLeTrenMeNu, doDai - 230, chieuCaoMenuCap1, 4, COLOR_HIGHT_LIGHT, 15, "X");
	dongChuongTrinh.veNut(); 
	
	vatTu.veNut();
	nhanVien.veNut();
	hoaDon.veNut();
	doanhThu.veNut();
	int mx = -1;
	int my = -1;
	while (true)
	{
		if (index != -1)
		{
			if (index == ID_VT)
			{
				vatTu.duocChon();
				nhanVien.khongDuocChon();
				hoaDon.khongDuocChon();
				doanhThu.khongDuocChon();

				hienThiTinhNangVatTu(dsVatTu, index, nhanVien, hoaDon, doanhThu,dongChuongTrinh,VatTu::soSanhTheoTen);
			}
			else if (index == ID_NV)
			{
				nhanVien.duocChon();
				vatTu.khongDuocChon();
				hoaDon.khongDuocChon();
				doanhThu.khongDuocChon();

				hienThiTinhNangNhanVien(DSNV, index, vatTu, hoaDon, doanhThu, dongChuongTrinh,NhanVien::soSanhTheoTen);
			}
			else if (index == ID_HD)
			{
				hoaDon.duocChon();
				vatTu.khongDuocChon();
				nhanVien.khongDuocChon();
				doanhThu.khongDuocChon();
			
				hienThiTinhNangHoaDon(dsVatTu, DSNV, index, vatTu, nhanVien,hoaDon, doanhThu,dongChuongTrinh);
			}
			else if (index == ID_DT)
			{
				
				vatTu.khongDuocChon();
				doanhThu.duocChon();
				nhanVien.khongDuocChon();
				hoaDon.khongDuocChon();
			
				hienThiTinhNangDoanhThu(dsVatTu,DSNV,index,vatTu,nhanVien,hoaDon,doanhThu,dongChuongTrinh); 
			}
			else if (index == ID_CLOSE) {
			 return; 
			 
	
			}
		}
		else if (ismouseclick(WM_LBUTTONDOWN))
		{
			int xclick = -1;
			int yclick = -1;
			getmouseclick(WM_LBUTTONDOWN, xclick, yclick);
			if (vatTu.isMouseHover(xclick, yclick))
			{
				vatTu.duocChon();
				nhanVien.khongDuocChon();
				hoaDon.khongDuocChon();
				doanhThu.khongDuocChon();
				hienThiTinhNangVatTu(dsVatTu, index, nhanVien, hoaDon, doanhThu, dongChuongTrinh,VatTu::soSanhTheoTen);
			}
			else if (hoaDon.isMouseHover(xclick, yclick))
			{
				hoaDon.duocChon();
				vatTu.khongDuocChon();
				nhanVien.khongDuocChon();
				doanhThu.khongDuocChon();
				hienThiTinhNangHoaDon(dsVatTu, DSNV, index, vatTu, nhanVien, hoaDon,doanhThu,dongChuongTrinh);
			}
			else if (nhanVien.isMouseHover(xclick, yclick))
			{
				nhanVien.duocChon();
				vatTu.khongDuocChon();
				hoaDon.khongDuocChon();
				doanhThu.khongDuocChon();
				hienThiTinhNangNhanVien(DSNV, index, vatTu, hoaDon, doanhThu, dongChuongTrinh,NhanVien::soSanhTheoTen);
			}
			else if (doanhThu.isMouseHover(xclick, yclick))
			{
				doanhThu.duocChon();
				vatTu.khongDuocChon();
				nhanVien.khongDuocChon();
				hoaDon.khongDuocChon();
				hienThiTinhNangDoanhThu(dsVatTu,DSNV,index,vatTu,nhanVien,hoaDon,doanhThu,dongChuongTrinh); 
				
			}
			else if (dongChuongTrinh.isMouseHover(xclick,yclick)) {
				return; // ket thuc ham nhe -> 
				
			}
		}
		delay(1);
	}
}

// =================================MENU NHAN THAM SO==============================================
void menuQuanLyVatTu(BstVatTu &dsVatTu, DsNhanVien &DSNV)
{
	setfillstyle(SOLID_FILL, BACKGROUP);
	bar(0, 0, 3000, 3000);
	menuCha(dsVatTu, DSNV);
}
