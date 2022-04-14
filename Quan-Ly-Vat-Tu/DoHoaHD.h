#pragma once
using namespace std; 
#include "Tienich.h"
#include "BienDoHoa.h"


// ham hien thi ra cai bang ( table ) cua CTHD


void hienThiTableCTHD() {
	// xoa di man hinh phia duoi 
	TienichDoHoa::xoaManHinhTheoToaDo(margin,canLeTrenHD + 170,1600,1600,BACKGROUP); 
	NutBam titleMaVT(margin,canLeTrenHD + 170,doDaiCoban,40,colorTieuDe,7,conlorTextTieuDe,"maVT"); 
	NutBam titileTenVT(margin + doDaiCoban + 3,canLeTrenHD + 170,doDaiCoban*2,40,colorTieuDe,7,conlorTextTieuDe,"ten VT");
	NutBam titiledonViVT(margin + doDaiCoban*3 + 3*2,canLeTrenHD + 170,doDaiCoban,40,colorTieuDe,7,conlorTextTieuDe,"don vi VT"); 
	NutBam titilesoLuongVT(margin + doDaiCoban*4 + 3*3,canLeTrenHD + 170,doDaiCoban,40,colorTieuDe,7,conlorTextTieuDe,"so luong VT"); 
	NutBam titiledonGiaVT(margin + doDaiCoban*5 + 3*4,canLeTrenHD + 170,doDaiCoban,40,colorTieuDe,7,conlorTextTieuDe,"don gia VT"); 
	NutBam titleVAT(margin + doDaiCoban*6 + 3*5,canLeTrenHD + 170,doDaiCoban,40,colorTieuDe,7,conlorTextTieuDe,"VAT");
	NutBam thanhTien(margin + doDaiCoban*7 + 3*6,canLeTrenHD + 170,doDaiCoban*2,40,colorTieuDe,7,conlorTextTieuDe,"thanh tien tien"); 
	titleMaVT.veNut(); 
	titilesoLuongVT.veNut();
	titileTenVT.veNut(); 
	titiledonViVT.veNut(); 
	titiledonGiaVT.veNut();
	titleVAT.veNut(); 
	thanhTien.veNut(); 
	OVuong table(margin,canLeTrenHD + 170,doDaiCoban*9 + 18,400,15);
	setcolor(15); 
	line(margin+ doDaiCoban ,canLeTrenHD + 170,margin+ doDaiCoban,690); 
	line(margin+ doDaiCoban*3 + 3,canLeTrenHD + 170,margin+ doDaiCoban*3 + 3,690);
	line(margin+ doDaiCoban*4 + 3*2,canLeTrenHD + 170,margin+ doDaiCoban*4 + 3*2,690);
	line(margin+ doDaiCoban*5 + 3*3,canLeTrenHD + 170,margin+ doDaiCoban*5 + 3*3,690);
	line(margin+ doDaiCoban*6 + 3*4,canLeTrenHD + 170,margin+ doDaiCoban*6 + 3*4,690);
	line(margin+ doDaiCoban*7 + 3*5,canLeTrenHD + 170,margin+ doDaiCoban*7 + 3*5,690);
	NutBam btnTruoc(margin,720,40,32,colorTieuDe,3,0,"<<");
	NutBam btnSau(margin + 66,720,40,32,colorTieuDe,3,0,">>");

	btnTruoc.veNut(); 
	btnSau.veNut(); 
	
	// ve them nut Tong cong tien 
	setbkcolor(0); 
	setcolor(15); 
	outtextxy(margin + 1102,720,"tong tien: "); 
}

void hienThiThemHoaDonNhap(BstVatTu &dsVatTu,dsNhanVien &DSNV,int &index,NutBam &vatTu
,NutBam &nhanVien ,NutBam &doanhThu ,NutBam &inHD) {
	TienichDoHoa::xoaManHinhTheoToaDo(margin,canLeTrenHD,1600,1600,BACKGROUP); 
	NhanVien* tempNV; 
	index = -1; 
	TienichDoHoa::xoaManHinhTheoToaDo(0,96,DODAIMANHINH,1000,BACKGROUP);  
	NutBam btnThemHD(margin + 1232,canLeTrenHD + 12 ,WHD*2,HHD,mauNhapXuat,mauHightNhapXuat,1,"THEM HOA DON"); 
	btnThemHD.veNut(); 
	ONhap maNV(margin + 6,canLeTrenHD + 12,190,40,60,"Ma NV: ",0,0,10); 
	maNV.veONhap(); 
	ONhap maHD(margin + 320,canLeTrenHD + 12,190,40,60,"Ma HD: ",0,0,10);
	maHD.veONhap() ;

   	Date tempDate; 
   	tempDate.setDateNow(); 
   	ONhap nhapNgay(canLeNgangHD + 400 + 300,canLeTrenHD + 12,65,40,60,"Ngay: ",0,0,2);
	ONhap nhapThang(canLeNgangHD + 606 + 280,canLeTrenHD + 12,65,40,70,"Thang: ",0,0,2);
   	ONhap nhapNam(canLeNgangHD  + 827 + 190,canLeTrenHD + 12,88,40,70,"Nam: ",0,0,4);
   	nhapNam.veONhap(); 
   	nhapNgay.veONhap(); 
   	nhapThang.veONhap(); 
   	nhapNgay.boNhoDem = TienichDoHoa::intToString(tempDate.ngay);
   	nhapThang.boNhoDem = TienichDoHoa::intToString(tempDate.thang);
   	nhapNam.boNhoDem = TienichDoHoa::intToString(tempDate.nam);
   	nhapNgay.inNoiDung(); 
   	nhapThang.inNoiDung(); 
   	nhapNam.inNoiDung(); 
	ONhap maVT(margin+6,canLeTrenHD + 90,190,40,60,"Ma VT: ",0,0,10); 
	maVT.veONhap(); 
	ONhap soLuongVT(margin + 370,canLeTrenHD + 90,110,40,96,"So Luong",0,0,5); 
	soLuongVT.veONhap();
	ONhap donGia(margin + 630,canLeTrenHD + 90,100,40,96,"Don Gia",0,0,10); 
	donGia.veONhap();
	ONhap VAT(margin + 890,canLeTrenHD + 90,70,40,80,"VAT(%)",0,0,3); 
	VAT.veONhap();
	NutBam themTT(margin + 1215,canLeTrenHD + 90,200,40,mauNhapXuat,mauHightNhapXuat,1,"Thanh Toan"); 
	themTT.veNut(); 
	OVuong baoQuanhHD(5,canLeTrenHD,DODAIMANHINH-12,80,8); 
	OVuong baoQuanCTHD(5,canLeTrenHD + 80,DODAIMANHINH-12,80,8); 
	hienThiTableCTHD(); 
	
	
	while (true) {
		if (index != -1) {
			if (index >= 0 && index <= 3) {  
				return;
			}
			else {
				
				 if (index == ID_IN_HD) {
				
					
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
				tempNV = DSNV.timKiemNVTraVeDiaChi(maNV.boNhoDem); 
				if (!tempNV && maNV.boNhoDem != "") {
					MessageBox(NULL, "Khong Ton Tai Nhan Vien Nay!", "Thong Bao", MB_ICONINFORMATION | MB_OK);
					maNV.resetBoNhoDem(); 
				}	
			}
			else if (maHD.isMouseHover(xclick,yclick)) {
				maHD.NhapVao(kiTuChuHoacSo,""); 
				bool kiemTraTrung = DSNV.timKiemHD(maHD.boNhoDem); // tra ve True neu tim thay!
				if (kiemTraTrung) {
					MessageBox(NULL, "Da ton tai maHD nay!", "Thong Bao", MB_ICONINFORMATION | MB_OK);
					maHD.resetBoNhoDem(); 
				}
				
	
			}
			else if (nhapNgay.isMouseHover(xclick,yclick)) {
				nhapNgay.NhapVao(kiTuSo,"Chi nhap so!"); 
				TienichDoHoa::xoaKhoangTrangThua(nhapNgay.boNhoDem);  
			}
			else if (nhapThang.isMouseHover(xclick,yclick)) {
				nhapThang.NhapVao(kiTuSo,"Chi nhap so!"); 
				TienichDoHoa::xoaKhoangTrangThua(nhapThang.boNhoDem);  
			}
			else if (nhapNam.isMouseHover(xclick,yclick)) {
				nhapNam.NhapVao(kiTuSo,"Chi nhap so!"); 
				TienichDoHoa::xoaKhoangTrangThua(nhapThang.boNhoDem);
				
				
			}
			else if (btnThemHD.isMouseHover(xclick,yclick)) {
				
			}
 			else if (maVT.isMouseHover(xclick,yclick)) {  
				maVT.NhapVao(kiTuChuHoacSo,""); 
				NodeVatTu* pTempMaVT = dsVatTu.timKiemVT(maVT.boNhoDem); 
				if (pTempMaVT == NULL && maVT.boNhoDem != "")  { 
					MessageBox(NULL, "khong ton tai ma vat tu nay!", "thong bao", MB_ICONINFORMATION | MB_OK);
					maVT.resetBoNhoDem(); 
				}
			}
			else if (soLuongVT.isMouseHover(xclick,yclick)) {
				soLuongVT.NhapVao(kiTuSo,"chi nhap so!"); 
			}
			else if (donGia.isMouseHover(xclick,yclick)) {
				donGia.NhapVao(kiTuSo,"chi nhap so!"); 
				
			}
			else if (VAT.isMouseHover(xclick,yclick)) {
				VAT.NhapVao(kiTuSo,"chi nhap so"); 
				float tempVAT = TienichDoHoa::stringToFloat(VAT.boNhoDem); 
				if (tempVAT > 100) {
					MessageBox(NULL, "khong hop le!", "thong bao", MB_ICONINFORMATION | MB_OK); 
					VAT.resetBoNhoDem(); 
				}
			}
		
			else if (themTT.isMouseHover(xclick,yclick)) {
				if (!(nhapNgay.boNhoDem == "" || nhapThang.boNhoDem == "" || nhapNam.boNhoDem == "" || maNV.boNhoDem == "" || maVT.boNhoDem == "" || soLuongVT.boNhoDem == "" || donGia.boNhoDem == "" && VAT.boNhoDem == "") ) {
					string loai = "X"; 
					int ngay = TienichDoHoa::stringToInt(nhapNgay.boNhoDem); 
					int thang = TienichDoHoa::stringToInt(nhapThang.boNhoDem); 
					int nam = TienichDoHoa::stringToInt(nhapNam.boNhoDem); 
					Date date(ngay,thang,nam); 
					cout << maNV.boNhoDem <<endl << maHD.boNhoDem << endl << loai << endl;
					date.hienThiConsole(); 
					cout << maVT.boNhoDem << endl << soLuongVT.boNhoDem << endl << donGia.boNhoDem << VAT.boNhoDem;  		
				}
				else {
					MessageBox(NULL, "khong duoc bo trong!", "thong bao", MB_ICONINFORMATION | MB_OK);
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
	NutBam themHDNhap(marginLeftSub ,marginTopSub,WMenuSub,HMenuSub,COLOR_BTN_SUB,COLOR_HIGHT_BTN_SUB,COLOR_TEXT_BTN_SUB,"Them Hoa Don Nhap");
	NutBam inHD(WMenuSub + marginLeftSub*2 ,marginTopSub,WMenuSub,HMenuSub,COLOR_BTN_SUB,COLOR_HIGHT_BTN_SUB,COLOR_TEXT_BTN_SUB,"In Hoa Don");
	themHDNhap.veNut(); 
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
					hienThiThemHoaDonNhap(dsVatTu,DSNV,index,vatTu,nhanVien ,doanhThu ,inHD);
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

			themHDNhap.kiemTraVeLai(mx,my,kiemTraHD[0]); 
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
			else if (themHDNhap.isMouseHover(xclick,yclick)) { 
				hienThiThemHoaDonNhap(dsVatTu,DSNV,index,vatTu,nhanVien ,doanhThu ,inHD);
			}
			
			else if (inHD.isMouseHover(xclick,yclick)) {
				
				
			}
		}
	delay(1);
}
	
	
	
	
	
	
}
