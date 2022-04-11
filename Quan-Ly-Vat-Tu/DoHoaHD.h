#pragma once
using namespace std; 
#include "Tienich.h"
#include "BienDoHoa.h"


void hienThiThemHoaDon(BstVatTu &dsVatTu,dsNhanVien &DSNV,int &index,NutBam &vatTu
,NutBam &nhanVien ,NutBam &doanhThu ,NutBam &inHD) {
	index = -1; 
	TienichDoHoa::xoaManHinhTheoToaDo(0,46 + 50,DODAIMANHINH,1000,BACKGROUP);  
	// ve ra hai nut cho nguoi dung lua chon ( nhap va xuat ) 
	const int canLeTrenHD = 46 + 50 + 20; 
	const int canLeNgangHD = 16;
	const int WHD = 120; 
	const int HHD = 36;
	// bien mau 
	const int mauNhapXuat = 14; 
	const int mauHightNhapXuat = 14;
	NutBam btnHDNhap(canLeNgangHD,canLeTrenHD,WHD,HHD,mauNhapXuat,mauHightNhapXuat,1,"nhap"); 
	NutBam btnHDXuat(canLeNgangHD + WHD + 2,canLeTrenHD ,WHD,HHD,mauNhapXuat,mauHightNhapXuat,1,"xuat"); 
	btnHDNhap.veNut(); 
	btnHDXuat.veNut(); 
	OVuong oVuongHD(5,canLeTrenHD - 21,DODAIMANHINH - 12,76,8);
	OVuong oVuongBQHD(5,canLeTrenHD - 21,canLeNgangHD + WHD*2 + 5,76,8); 
	// tao ra o Nhap ma NV 
	ONhap maNV(canLeNgangHD + WHD*2 + 30,canLeTrenHD-7,120,46,150,"ma nhan vien",10); 
	maNV.veONhap(); 
	
   	OVuong oVuongBQmaNV(5,canLeTrenHD - 21,568,76,8); 
   	// tiep tuc nhap ngay gio 
   	
	
}

void hienThiTinhNangHoaDon(BstVatTu &dsVatTu,dsNhanVien &DSNV,int &index,NutBam &vatTu
,NutBam &nhanVien ,NutBam &doanhThu)                                                        {
	TienichDoHoa::xoaManHinhTheoToaDo(0,42,DODAIMANHINH,DORONGMANHINH,BACKGROUP);
	bool kiemTra[3] = {false};
	bool kiemTraHD[2] = {false};
	index = -1; 
	OVuong ovVatTu(5,45,DODAIMANHINH - 12,50,8); 
	const int WMenuSub = 230; 
	const int HMenuSub = 35;
	const int marginLeftSub = 15; 
	const int marginTopSub = 53 ;
	NutBam themHD(marginLeftSub ,marginTopSub,WMenuSub,HMenuSub,COLOR_BTN_SUB,COLOR_HIGHT_BTN_SUB,COLOR_TEXT_BTN_SUB,"them hoa don");
	NutBam inHD(WMenuSub + marginLeftSub*2 ,marginTopSub,WMenuSub,HMenuSub,COLOR_BTN_SUB,COLOR_HIGHT_BTN_SUB,COLOR_TEXT_BTN_SUB,"in hoa don");
	themHD.veNut(); 
	inHD.veNut() ; 
	
	
	int mx = -1; 
	int my = -1; 
	while (true) {
		if (index != -1) {
			if (index >= 0 && index <= 3) {  // thuoc vung menu to. 
				return;
			}
			else {
				if (index == ID_THEM_HD) {
					// thuc hien them hd 
				}
				else if (index == ID_IN_HD) {
					// thuc hien goi ham in hoa don. 
					
				}
			}
		}
		if (ismouseclick(WM_MOUSEMOVE)) {
			getmouseclick(WM_MOUSEMOVE, mx, my);  
			vatTu.kiemTraVeLai(mx,my,kiemTra[0]); 
			nhanVien.kiemTraVeLai(mx,my,kiemTra[1]);
			doanhThu.kiemTraVeLai(mx,my,kiemTra[2]);

			themHD.kiemTraVeLai(mx,my,kiemTraHD[0]); 
			inHD.kiemTraVeLai(mx,my,kiemTraHD[1]); 
			
			
		}  // xu kien nguoi dung click. 
		else if (ismouseclick(WM_LBUTTONDOWN)) {  
			int xclick = -1;
			int yclick = -1; 
			getmouseclick(WM_LBUTTONDOWN, xclick, yclick); 
			if (nhanVien.isMouseHover(xclick,yclick)) {
				index = ID_NV; 
				return; 
			}
			else if (vatTu.isMouseHover(xclick,yclick)) {
					index = ID_VT;   
					return; 
			}
			else if (doanhThu.isMouseHover(xclick,yclick)) {
					index = ID_DT;   
					return; 
			}
			else if (themHD.isMouseHover(xclick,yclick)) { 
				hienThiThemHoaDon(dsVatTu,DSNV,index,vatTu,nhanVien ,doanhThu ,inHD);
			}
			
			else if (inHD.isMouseHover(xclick,yclick)) {
				
				
			}
		}
	delay(1);
}
	
	
	
	
	
	
}
