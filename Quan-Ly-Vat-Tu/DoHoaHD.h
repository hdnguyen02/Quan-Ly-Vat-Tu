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
	const int HHD = 62;
	// bien mau 
	const int mauNhapXuat = 3; 
	const int mauHightNhapXuat = 14;
	NutBam btnHDXuat(canLeNgangHD,canLeTrenHD,WHD,HHD,mauNhapXuat,mauHightNhapXuat,1,"nhap"); 
	NutBam btnHDNhap(canLeNgangHD + WHD + 2,canLeTrenHD ,WHD,HHD,mauNhapXuat,mauHightNhapXuat,1,"xuat"); 
	btnHDNhap.veNut(); 
	btnHDXuat.veNut(); 
	OVuong oVuongHD(5,canLeTrenHD - 21,DODAIMANHINH - 12,106,8);
	OVuong oVuongBQHD(5,canLeTrenHD - 21,canLeNgangHD + WHD*2 + 5,106,8);
	ONhap maNV(canLeNgangHD + WHD*2 + 20,canLeTrenHD + 12,190,40,150,"ma nhan vien",0,0,10); 
	maNV.veONhap(); 
	
   	OVuong oVuongBQmaNV(5,canLeTrenHD - 21,630,106,8); 
   	Date tempDate; 
   	tempDate.setDateNow(); 
   	ONhap nhapNgay(canLeNgangHD + WHD*2 + 400,canLeTrenHD + 12,65,40,60,"ngay",0,0,2);
	nhapNgay.veONhap();  
//	OVuong oVuongBQnhapNgay(5,canLeTrenHD - 21,800,106,8);
	ONhap nhapThang(canLeNgangHD + WHD*2 + 370 + 236,canLeTrenHD + 12,65,40,70,"thang",0,0,2);
   	nhapThang.veONhap(); 
   	//OVuong oVuongBQnhapThang(5,canLeTrenHD - 21,1040,106,8);
   	ONhap nhapNam(canLeNgangHD + WHD*2 + 370 + 457,canLeTrenHD + 12,88,40,70,"nam",0,0,4);
   	nhapNam.veONhap(); 
   	nhapNgay.boNhoDem = TienichDoHoa::intToString(tempDate.ngay);
   	nhapThang.boNhoDem = TienichDoHoa::intToString(tempDate.thang);
   	nhapNam.boNhoDem = TienichDoHoa::intToString(tempDate.nam); 
   	nhapNgay.inNoiDung(); 
   	nhapThang.inNoiDung(); 
   	nhapNam.inNoiDung(); 
	OVuong oVuongBQnhapNam(5,canLeTrenHD - 21,1270,106,8);
	NutBam themCTHD(1270 + 30,canLeTrenHD ,204,62,14,3,1,"chi tiet hoa don"); 
	themCTHD.veNut(); 
	
	// mat dinh la nguoi dung chon hoa don xuat. 
	btnHDXuat.duocChon(); 
	// bat dieu kien nguoi dung chon 
	
	while (true) {
		if (index != -1) {
			if (index >= 0 && index <= 3) {  // thuoc vung menu to. 
				return;
			}
			else {
				
				 if (index == ID_IN_HD) {
					// thuc hien goi ham in hoa don. 
					
				}
			}
		}
		
		 if (ismouseclick(WM_LBUTTONDOWN)) {  
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
		
			else if (inHD.isMouseHover(xclick,yclick)) {
				index = ID_IN_HD; 
				return; 
			}
			else if (maNV.isMouseHover(xclick,yclick)) {
				maNV.NhapVao(kiTuChuHoacSo,""); 
				NhanVien* tempNV = DSNV.timKiemNVTraVeDiaChi(maNV.boNhoDem); 
				if (!tempNV) {
					MessageBox(NULL, "khong ton tai nhan vien nay!", "thong bao", MB_ICONINFORMATION | MB_OK);
					maNV.resetBoNhoDem(); 
				}	
			}
			else if (nhapNgay.isMouseHover(xclick,yclick)) {
				nhapNgay.NhapVao(kiTuSo,"chi nhap so!"); 
			}
			else if (nhapThang.isMouseHover(xclick,yclick)) {
				nhapThang.NhapVao(kiTuSo,"chi nhap so!"); 
			}
			else if (nhapNam.isMouseHover(xclick,yclick)) {
				nhapNam.NhapVao(kiTuSo,"chi nhap so!"); 
			}
			else if (themCTHD.isMouseHover(xclick,yclick)) {
				// them vao chi tiet hoa DON => neu da nhap vao day => tat ca deu phai hop le 
				// kiem tra xem co bo trong truong nao khong
				if (nhapNgay.boNhoDem == "" || nhapThang.boNhoDem == "" || nhapNam.boNhoDem == "" || maNV.boNhoDem == "") {
					// HIEN THI LEN BOX KHONG DUOC BO TRONG !
					MessageBox(NULL, "khong duoc bo trong!", "thong bao", MB_ICONINFORMATION | MB_OK);
				}
				else {
					// bat dau qua trinh them. 
					cout << "qua trinh them cthd"; 
				}
				 
			}
 			
		}
	delay(1);
}
	
	
	
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
					hienThiThemHoaDon(dsVatTu,DSNV,index,vatTu,nhanVien ,doanhThu ,inHD);
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
