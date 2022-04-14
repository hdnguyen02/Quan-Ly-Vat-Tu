#pragma once
using namespace std; 
#include "Tienich.h"
#include "BienDoHoa.h"


// ham hien thi ra cai bang ( table ) cua CTHD

// indexPage : trang dau tien hien thi!
// soLuongItemPage : so luong item tren 1 page 
// viet ham hien Thi ra 
// viet 1 ham in rieng ra day
// ham do bao gom: 
// cac thong tin can in => chang han nhu moi dau vao ta KT 


void veTableCTHD() {
	TienichDoHoa::xoaManHinhTheoToaDo(margin,canLeTrenHD + 170,1600,400,BACKGROUP); 
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
	setbkcolor(0); 
	setcolor(15); 
	outtextxy(margin + 1102,720,"tong tien: ");
}

void hienThiCTHDLenTable(int indexPage,int soLuongItemPage,ListCTHD *dsCTHD,BstVatTu &dsVatTu) {
	const int marginTable = margin + 36; 
	const int marginTop = 354; 
	const int khoanCach = 36; 
	int soLuongCTHD = dsCTHD->soLuongCTHD(); 
	NodeCTHD** arrCTHD = new NodeCTHD*[soLuongCTHD]; 	
	dsCTHD->listToArray(arrCTHD); 
	setcolor(CinputText); 
	setbkcolor(0); 
	settextstyle(6, 0, 1);
	string temp; 
	for (int i = 0;i < soLuongItemPage;i++) {
		if (i + indexPage*soLuongItemPage < soLuongCTHD) {
			outtextxy(marginTable + 6,marginTop + khoanCach*i,arrCTHD[i + indexPage*soLuongItemPage]->getmaVT().c_str()); 
			NodeVatTu* tempVT = dsVatTu.timKiemVT(arrCTHD[i + indexPage*soLuongItemPage]->getmaVT()); 
			outtextxy(marginTable + doDaiCoban,marginTop + khoanCach*i,tempVT->getInfo().ten.c_str()); 
			outtextxy(marginTable + doDaiCoban*3 + 36,marginTop + khoanCach*i,tempVT->getInfo().donVi.c_str());
			temp = TienichDoHoa::floatToString(arrCTHD[i + indexPage*soLuongItemPage]->getSoLuong()); 
			outtextxy(marginTable + doDaiCoban*4,marginTop + khoanCach*i,temp.c_str()); 
			temp = TienichDoHoa::floatToString(arrCTHD[i + indexPage*soLuongItemPage]->getDonGia()); 
			outtextxy(marginTable + doDaiCoban*5,marginTop + khoanCach*i,temp.c_str()); 
			temp = TienichDoHoa::floatToString(arrCTHD[i + indexPage*soLuongItemPage]->getVAT());
			outtextxy(marginTable + doDaiCoban*6 + 32,marginTop + khoanCach*i,temp.c_str()); 
		}

	}
	
	
	
	
	 
}

void hienThiThemHoaDonNhap(BstVatTu &dsVatTu,dsNhanVien &DSNV,int &index,NutBam &vatTu
,NutBam &nhanVien ,NutBam &doanhThu ,NutBam &inHD) {
	TienichDoHoa::xoaManHinhTheoToaDo(margin,canLeTrenHD,1600,1600,BACKGROUP); 
	NhanVien* tempNV; 
	NodeHoaDon* tempHD; 
	bool daThemHD = false;  
	index = -1; 
	int indexPage = 0; 
	int soPhanTuTrenMotPage = 9; 
	int soLuongPage; 
	float toiDaPage = 1; 
	
	TienichDoHoa::xoaManHinhTheoToaDo(0,96,DODAIMANHINH,1000,BACKGROUP);  
	NutBam btnSave(margin + 1232,canLeTrenHD + 12 ,WHD*2,HHD,mauNhapXuat,mauHightNhapXuat,1,"SAVE"); 
	btnSave.veNut(); 
	ONhap maNV(margin + 6,canLeTrenHD + 12,190,40,60,"Ma NV: ",0,0,10); 
	maNV.veONhap(); 
	ONhap soHD(margin + 320,canLeTrenHD + 12,190,40,60,"Ma HD: ",0,0,10);
	soHD.veONhap() ;

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
	
	NutBam themTT(margin + 1230,canLeTrenHD + 90,WHD*2,HHD,mauNhapXuat,mauHightNhapXuat,1,"THEM CTHD"); 
	themTT.veNut(); 
	OVuong baoQuanhHD(5,canLeTrenHD,DODAIMANHINH-12,80,8); 
	OVuong baoQuanCTHD(5,canLeTrenHD + 80,DODAIMANHINH-12,80,8); 


	
	NutBam btnHieuChinhCTHD(margin + 220,712,190,40,14,3,1,"HIEU CHINH CTHD"); 
	btnHieuChinhCTHD.veNut(); 
    NutBam btnLamMoiHoaDon(margin + 530 + 270,712,190,40,14,3,1,"LAM MOI HD");
	btnLamMoiHoaDon.veNut();
	NutBam btnTienToi(margin + 56,712,50,40,15,3,1,">>");
	NutBam btnLui(margin,712,50,40,15,3,1,"<<");
	btnTienToi.veNut(); 
	btnLui.veNut(); 
	veTableCTHD(); 
	
	
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
				else {
					// da tim ra thang nV -> vo Hieu no 
					maNV.khongDuocNhap = true; 
				}	
			}
			else if (soHD.isMouseHover(xclick,yclick)) {
				soHD.NhapVao(kiTuChuHoacSo,""); 
				bool kiemTraTrung = DSNV.timKiemHD(soHD.boNhoDem); // tra ve True neu tim thay!
				if (kiemTraTrung) {
					MessageBox(NULL, "Da ton tai maHD nay!", "Thong Bao", MB_ICONINFORMATION | MB_OK);
					soHD.resetBoNhoDem(); 
				}
				else {
					soHD.khongDuocNhap = true; 
				}	
			
			}
			else if (nhapNgay.isMouseHover(xclick,yclick)) {
				nhapNgay.NhapVao(kiTuSo,"Chi nhap so!"); 

			}
			else if (nhapThang.isMouseHover(xclick,yclick)) {
				nhapThang.NhapVao(kiTuSo,"Chi nhap so!"); 
			}
			else if (nhapNam.isMouseHover(xclick,yclick)) {
				nhapNam.NhapVao(kiTuSo,"Chi nhap so!"); 
			}
			else if (btnSave.isMouseHover(xclick,yclick)) {
				// kiem tra da nhap day du cac truong chua 
				if (nhapNgay.boNhoDem == "" || nhapThang.boNhoDem == "" || nhapNam.boNhoDem == "" || maNV.boNhoDem == "" || soHD.boNhoDem == "" ) {
					MessageBox(NULL, "Vui Long Dien Vao Hoa Don!", "thong bao", MB_ICONINFORMATION | MB_OK);
				}
				else if (!daThemHD) { // truong hop dsct hd dang rong!
					MessageBox(NULL, "Vui Long Dien vao Chi Tiet Hoa Don!", "thong bao", MB_ICONINFORMATION | MB_OK);
				}
				else {
		        	DSNV.ghiFileDSNV("data/dataNhanVien.txt"); 
		        	MessageBox(NULL, "Them thanh cong", "thong bao", MB_ICONINFORMATION | MB_OK);
					
				}	
			}
			
			// ==================== SAU KHI NHAP SONG MAVT==================
			
 			else if (maVT.isMouseHover(xclick,yclick)) {  
				maVT.NhapVao(kiTuChuHoacSo,""); 
				NodeVatTu* pTempMaVT = dsVatTu.timKiemVT(maVT.boNhoDem); 
				if (pTempMaVT == NULL && maVT.boNhoDem != "")  { 
					MessageBox(NULL, "khong ton tai ma vat tu nay!", "thong bao", MB_ICONINFORMATION | MB_OK);
					maVT.resetBoNhoDem(); 
				}
				else if (daThemHD) {
					if (tempHD->getdsCTHD()->timKiemCTHD(maVT.boNhoDem)) { // boi vi chua them vaoHD
						MessageBox(NULL, "Da ton tai Vat Tu nay!", "Thong Bao", MB_ICONINFORMATION | MB_OK);
						maVT.resetBoNhoDem(); 
					}
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
			else if (btnTienToi.isMouseHover(xclick,yclick)) {
				
				if (indexPage < toiDaPage - 1) {
					indexPage++; 
					veTableCTHD(); 
					hienThiCTHDLenTable(indexPage,soPhanTuTrenMotPage,tempHD->getdsCTHD(),dsVatTu); 
					indexPage++; 
					string temp = TienichDoHoa::intToString(indexPage) + "/" + TienichDoHoa::intToString(toiDaPage);
					outtextxy(DODAIMANHINH/2 -110,720,(char*)(temp.c_str())); 
					indexPage--; 
				}
			}
			else if (btnLui.isMouseHover(xclick,yclick)) {
				if (indexPage > 0) {
					indexPage--;
					veTableCTHD(); 
					hienThiCTHDLenTable(indexPage,soPhanTuTrenMotPage,tempHD->getdsCTHD(),dsVatTu); 
					indexPage++; 
					string temp = TienichDoHoa::intToString(indexPage) + "/" + TienichDoHoa::intToString(toiDaPage);
					outtextxy(DODAIMANHINH/2 - 110, 720,(char*)(temp.c_str())); 
					indexPage--; 
					
				}
			}
		
			else if (themTT.isMouseHover(xclick,yclick)) {
				if (!(nhapNgay.boNhoDem == "" || nhapThang.boNhoDem == "" || nhapNam.boNhoDem == "" || maNV.boNhoDem == "" || soHD.boNhoDem == "" || maVT.boNhoDem == "" || soLuongVT.boNhoDem == "" || donGia.boNhoDem == "" && VAT.boNhoDem == "") ) {
					if (!daThemHD) {
						tempHD = tempNV->dsHoaDon.themVaoCuoiHD(soHD.boNhoDem,tempDate,"X"); 
						daThemHD = true;
					}
					float tempSL = TienichDoHoa::stringToFloat(soLuongVT.boNhoDem); 
					float tempdonGia = TienichDoHoa::stringToFloat(donGia.boNhoDem); 
					float tempVAT = TienichDoHoa::stringToFloat(VAT.boNhoDem); 
					CThoaDon tempCTHD(maVT.boNhoDem,tempSL,tempdonGia,tempVAT); // khi tat ca da thoa dieu kien. 
					tempHD->themCTHD(tempCTHD);
					int soLuongCTHD =  tempHD->getdsCTHD()->soLuongCTHD(); 
					soLuongPage = soLuongCTHD  / soPhanTuTrenMotPage; 
					toiDaPage = (float)soLuongCTHD / (float)soPhanTuTrenMotPage; 
					if (!kiemTraSoNguyen(TienichDoHoa::floatToString(toiDaPage))) {
							toiDaPage = (int)toiDaPage + 1;   
					}
				
					veTableCTHD();  
					hienThiCTHDLenTable(indexPage,soPhanTuTrenMotPage,tempHD->getdsCTHD(),dsVatTu);
					indexPage++; 
					string temp = TienichDoHoa::intToString(indexPage) + "/" + TienichDoHoa::intToString(toiDaPage);
					outtextxy(DODAIMANHINH/2 - 110, 720,(char*)(temp.c_str())); 
					indexPage--;
					
					maVT.resetBoNhoDem(); 
					soLuongVT.resetBoNhoDem(); 
					donGia.resetBoNhoDem(); 
					VAT.resetBoNhoDem(); 
				}
				else {
					MessageBox(NULL, "khong duoc bo trong!", "thong bao", MB_ICONINFORMATION | MB_OK);
				}
			}
		}
	delay(10);
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
