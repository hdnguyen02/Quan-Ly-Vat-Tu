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


// ============================= HIEN THI HAM CHINH SUA CTHD ============================
void hienThiChinhSuaCTHD(NodeCTHD* tempCTHD,ListCTHD* dsCTHD,BstVatTu &dsVatTu,string loaiHD) { 
 	  int w = 540; 
 	  int h = 358; 
 	  int x = DODAIMANHINH/2 - w/2; // in r o nua man hinh 
 	  int y = 332; 
 	  NutBam box(x,y,w,h,8,0,0,"");
	  box.veNut(); 
	  // ve ra nut dau X 
	  NutBam cancel ( w + x - 40,y,40,40,4,2,15,"X") ;
	  cancel.veNut();  
	  NutBam title(x,y,w-40,40,13,0,0,"HIEU CHINH CTHD");
	  title.veNut();  
	  // ve ra 4 nut -> sau do tao ra cac hieu chinh =>  
	  ONhap maVT(x + 30,y + 46 , w - 170,40,100,"ma VT",2,8,10);
	  ONhap soLuong(x + 30,y + 46 + 48  + 19, w - 170,40,100,"so luong",2,8,10);
	  ONhap donGia(x + 30,y + 46*2 + 48 + 19*2, w - 170,40,100,"don gia",2,8,10);
	  ONhap VAT(x + 30,y + 46*3 + 48 + 19*3, w - 170,40,100,"VAT",2,8,10);
	  maVT.veONhap();  
	  soLuong.veONhap();
	  donGia.veONhap(); 
	  VAT.veONhap(); 
	  NutBam hieuChinh (x + 30,y + 50*4 + 48 + 48 + 17,234,38,11,0,0,"sua"); 
	  NutBam xoa(x + w - 40 - 234,y +50*4 + 48 + 48 + 17,234,38,11,0,0,"xoa"); 
	  hieuChinh.veNut(); 
	  
	  xoa.veNut(); 
	  
	  // hien thi CTHD vao trong 
	  maVT.boNhoDem = tempCTHD->getinfo()->maVT; 
	  soLuong.boNhoDem = TienichDoHoa::floatToString(tempCTHD->getinfo()->soLuong); 
	  donGia.boNhoDem = TienichDoHoa::floatToString(tempCTHD->getinfo()->donGia); 
	  VAT.boNhoDem = TienichDoHoa::floatToString(tempCTHD->getinfo()->VAT); 
	  maVT.inNoiDung(); 
	  soLuong.inNoiDung(); 
	  donGia.inNoiDung(); 
	  VAT.inNoiDung(); 
	  
	  // luu tru ra 4 gia tri cu -> khi nao khac thi moi dem ra so kiem tra tiep 
	  string maVTCu = maVT.boNhoDem; 
	  string soLuongCu = soLuong.boNhoDem; 
	  string donGiaCu = soLuong.boNhoDem; 
	  string VATCu = soLuong.boNhoDem; 
	
	  
	  while (true) {
			if (ismouseclick(WM_LBUTTONDOWN)) {  
				int xclick = -1;
				int yclick = -1; 
				getmouseclick(WM_LBUTTONDOWN, xclick, yclick); 
				if (cancel.isMouseHover(xclick,yclick)) {
					// thuc hien ket thuc vong lap => khong hieu chinh gi nua 
					break; // thoat khoi vong lap luon dong thoi xoa ve lai cai khung kia
				}
				else if (maVT.isMouseHover(xclick,yclick)) {
					// thuc hien cho no nhap vao maVT 
					maVT.NhapVao(kiTuChuHoacSo,""); // nhap gi cung duoc => toi da bao nhieu ky tu.
					if (maVT.boNhoDem != maVTCu) { // co su thay doi so voi truoc do thi moi di kiem tra
						if (dsVatTu.timKiemVT(maVT.boNhoDem) == NULL) {
						MessageBox(NULL, "thong bao", "khong ton tai vat tu nay!", MB_ICONINFORMATION | MB_OK);
						// xoa luon maVT cu
						maVT.resetBoNhoDem(); 
						}
						else if (dsCTHD->timKiemCTHD(maVT.boNhoDem) != NULL) {
							MessageBox(NULL, "thong bao", "da ton tai vat tu nay!", MB_ICONINFORMATION | MB_OK);
							maVT.resetBoNhoDem(); 
						} 
					}
					
				}
				else if (soLuong.isMouseHover(xclick,yclick)) {
					soLuong.NhapVao(kiTuSo,"chi nhap so!"); 
				}
				else if (donGia.isMouseHover(xclick,yclick)) {
					donGia.NhapVao(kiTuSo,"chi nhap so!"); 
				}
				else if (VAT.isMouseHover(xclick,yclick)) {
					VAT.NhapVao(kiTuSo,"chi nhap so!"); 	
					if (VAT.boNhoDem != VATCu) {
						if (TienichDoHoa::stringToFloat(VAT.boNhoDem) > 100) {
							MessageBox(NULL, "thong bao", "khong thoa man (VAT < 100%)!", MB_ICONINFORMATION | MB_OK);
						}
					}
					
				}
				// bac dieu kien nhap nhap vao chinh sua 
				else if (hieuChinh.isMouseHover(xclick,yclick)) {
					// kiem tra xem co truong nao dang bi bo trong hay khong 
					if (maVT.boNhoDem == "" || soLuong.boNhoDem == "" || donGia.boNhoDem == "" || VAT.boNhoDem == "") {
						MessageBox(NULL, "thong bao", "khong duoc bo trong!", MB_ICONINFORMATION | MB_OK);
					}
					else {
						if (donGia.boNhoDem != donGiaCu || VAT.boNhoDem != VATCu || maVT.boNhoDem != maVTCu || soLuong.boNhoDem != soLuongCu) {
							NodeVatTu* tempVT = dsVatTu.timKiemVT(maVT.boNhoDem); 
							if (!tempVT->getInfo()->kiemTraDuHang(TienichDoHoa::stringToFloat(soLuong.boNhoDem))) {
								string thongBao = "khong du so luong! so luong trong kho : " + TienichDoHoa::floatToString(tempVT->getInfo()->soLuongTon); 
					 			MessageBox(NULL, thongBao.c_str(),"thong bao", MB_ICONINFORMATION | MB_OK);
					 			soLuong.resetBoNhoDem(); 
							}
							else { 
								tempCTHD->getinfo()->maVT = maVT.boNhoDem; 
								tempCTHD->getinfo()->soLuong = TienichDoHoa::stringToFloat(soLuong.boNhoDem); 
								tempCTHD->getinfo()->donGia = TienichDoHoa::stringToFloat(donGia.boNhoDem);
								tempCTHD->getinfo()->VAT = TienichDoHoa::stringToFloat(VAT.boNhoDem); 
								 MessageBox(NULL, "thong bao", "cap nhap thanh cong!", MB_ICONINFORMATION | MB_OK);
								 break;
							}
						}
					}			
					}
				
				
				else if (xoa.isMouseHover(xclick,yclick)) {
					// hien thi nen 2 lua chon 
					int luaChon = MessageBox(NULL, "ban co chac chac muon xoa!", "thong bao", MB_ICONWARNING | MB_OKCANCEL);
					
					// kiem tra lua chon cua nguoi dung => 
					// nhung truoc tien xoa can phai dam bao 1 viec do chinh la: 
					// nguoi dung chua thay doi du lieu gi phia truoc => neu da thay doi thi khong duoc tinh 
					
					if (luaChon == OK) {
						// thuc hien xoa di 
						if (dsCTHD->xoaCTHD(maVT.boNhoDem) == true) {
							// thong bao voi nguoi dung la xoa thanh cong! 
							MessageBox(NULL, "thong bao", "xoa vat tu thanh cong!", MB_ICONINFORMATION | MB_OK);
							break; // ket thuc vong lap => vi da xoa di VT nay!
							
						} // xoa di boNhoDem-> kiem tra xem co ton tai maHD nay khong 
						else {
							MessageBox(NULL, "thong bao", "khong ton tai Vat Tu nay", MB_ICONINFORMATION | MB_OK); 
						}
						
					}
										
				}
 				
		  	}
	  	delay(1); 
	  }
}	




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

// ngoai hien thi nen du lieu len tren 1 table -> ham con dung de tra ve so luong item tren 1 page
// ====================================== HAM IN RA DU LIEU LEN TABLE ======================================
int hienThiCTHDLenTable(int indexPage,int soLuongItemPage,ListCTHD *dsCTHD,BstVatTu &dsVatTu) {
	const int marginTable = margin + 36; 
	const int marginTop = 354; 
	const int khoanCach = 36; 
	int soLuongCTHD = dsCTHD->soLuongCTHD(); 
	NodeCTHD** arrCTHD = new NodeCTHD*[soLuongCTHD]; 	
	dsCTHD->listToArray(arrCTHD); 
	int dem = 0; // bien dung dem so luong cua CTHD tren table. 
	string temp; 
	for (int i = 0;i < soLuongItemPage;i++) {
		setcolor(CinputText); 
		setbkcolor(0); 
		settextstyle(6, 0, 1);
		if (i + indexPage*soLuongItemPage < soLuongCTHD) {
			dem++; 
			outtextxy(marginTable + 6,marginTop + khoanCach*i,arrCTHD[i + indexPage*soLuongItemPage]->getmaVT().c_str()); 
			NodeVatTu* tempVT = dsVatTu.timKiemVT(arrCTHD[i + indexPage*soLuongItemPage]->getmaVT()); 
			outtextxy(marginTable + doDaiCoban,marginTop + khoanCach*i,tempVT->getInfo()->ten.c_str()); 
			outtextxy(marginTable + doDaiCoban*3 + 36,marginTop + khoanCach*i,tempVT->getInfo()->donVi.c_str());
			temp = TienichDoHoa::floatToString(arrCTHD[i + indexPage*soLuongItemPage]->getSoLuong()); 
			outtextxy(marginTable + doDaiCoban*4,marginTop + khoanCach*i,temp.c_str()); 
			temp = TienichDoHoa::floatToString(arrCTHD[i + indexPage*soLuongItemPage]->getDonGia()); 
			outtextxy(marginTable + doDaiCoban*5,marginTop + khoanCach*i,temp.c_str()); 
			temp = TienichDoHoa::floatToString(arrCTHD[i + indexPage*soLuongItemPage]->getVAT());
			outtextxy(marginTable + doDaiCoban*6 + 32,marginTop + khoanCach*i,temp.c_str()); 
			// in them giaTien cua hoadon ra 
			temp = TienichDoHoa::floatToString(arrCTHD[i + indexPage*soLuongItemPage]->getTongTien());
			outtextxy(marginTable + doDaiCoban*7,marginTop + khoanCach*i,temp.c_str()); 
			NutBam hieuChinh(marginTable + doDaiCoban*7+190,marginTop + khoanCach*i - 4,52,28,11,2,0,"sua"); 
			hieuChinh.veNut(); 
		}

	}
	
	return dem;  
	
	
	
	 
}

void hienThiThemHoaDonNhap(BstVatTu &dsVatTu,dsNhanVien &DSNV,int &index,NutBam &vatTu
,NutBam &nhanVien ,NutBam &doanhThu ,NutBam &inHD) {
	TienichDoHoa::xoaManHinhTheoToaDo(margin,canLeTrenHD,1600,1600,BACKGROUP); 
	NhanVien* tempNV; 
	NodeHoaDon* tempHD; 
	NodeCTHD* pointerCTHD; 
	bool daThemHD = false;  
	index = -1; 
	int indexPage = 0; 
	int soPhanTuTrenMotPage = 9; 
	int soLuongPage; 
	float toiDaPage = 1; 
	
	int soLuongCTHDTrenTable = 0;  // bien dung de chua ham moi lan hien thi lai.
	// khai bao ra 1 bien dung de chua vi tri nguoi dung vua click vao ( de co the biet duoc nguoi dung muon hieu chinh thang nao 
	int viTriDieuChinhCTHD; 
	 
	
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
	ONhap soLuongVT(margin + 280,canLeTrenHD + 90,110,40,96,"So Luong",0,0,5); 
	soLuongVT.veONhap();
	ONhap donGia(margin + 520,canLeTrenHD + 90,200,40,96,"Don Gia",0,0,10); 
	donGia.veONhap();
	ONhap VAT(margin + 890,canLeTrenHD + 90,70,40,80,"VAT(%)",0,0,3); 
	VAT.veONhap();
	
	NutBam themTT(margin + 1230,canLeTrenHD + 90,WHD*2,HHD,mauNhapXuat,mauHightNhapXuat,1,"THEM CTHD"); 
	themTT.veNut(); 
	OVuong baoQuanhHD(5,canLeTrenHD,DODAIMANHINH-12,80,8); 
	OVuong baoQuanCTHD(5,canLeTrenHD + 80,DODAIMANHINH-12,80,8); 


	
    NutBam btnLamMoiHoaDon(margin + 530 + 270,712,190,40,14,3,1,"LAM MOI HD");
	btnLamMoiHoaDon.veNut();
	NutBam btnTienToi(margin + 56,712,50,40,15,3,1,">>");
	NutBam btnLui(margin,712,50,40,15,3,1,"<<");
	btnTienToi.veNut(); 
	btnLui.veNut(); 
	veTableCTHD(); 
	
	
	// toan do NUT HIEU CHINH CTHD. 
	NutBam hieuChinhCTHD1(margin + 36 + doDaiCoban*7+190,354 - 4,52,28,11,3,0,"sua");
	NutBam hieuChinhCTHD2(margin + 36 + doDaiCoban*7+190,354 + 36 -   4,52,28,11,3,0,"sua");
	NutBam hieuChinhCTHD3(margin + 36 + doDaiCoban*7+190,354 + 36*2 - 4,52,28,11,3,0,"sua");
	NutBam hieuChinhCTHD4(margin + 36 + doDaiCoban*7+190,354 + 36*3 - 4,52,28,11,3,0,"sua");
	NutBam hieuChinhCTHD5(margin + 36 + doDaiCoban*7+190,354 + 36*4 - 4,52,28,11,3,0,"sua");
	NutBam hieuChinhCTHD6(margin + 36 + doDaiCoban*7+190,354 + 36*5 - 4,52,28,11,3,0,"sua");
	NutBam hieuChinhCTHD7(margin + 36 + doDaiCoban*7+190,354 + 36*6 - 4,52,28,11,3,0,"sua");
	NutBam hieuChinhCTHD8(margin + 36 + doDaiCoban*7+190,354 + 36*7 - 4,52,28,11,3,0,"sua");
	NutBam hieuChinhCTHD9(margin + 36 + doDaiCoban*7+190,354 + 36*8 - 4,52,28,11,3,0,"sua");

//    soHD.boNhoDem = "df"; 
//    maNV.boNhoDem = "nv1";
	maVT.boNhoDem = "VT15"; 
	soLuongVT.boNhoDem = "1"; 
	donGia.boNhoDem = "2"; 
	VAT.boNhoDem = "2"; 
	
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
				if (maNV.boNhoDem != "") { 
					tempNV = DSNV.timKiemNVTraVeDiaChi(maNV.boNhoDem); 
					if (!tempNV ) {
						MessageBox(NULL, "Khong Ton Tai Nhan Vien Nay!", "Thong Bao", MB_ICONINFORMATION | MB_OK);
						maNV.resetBoNhoDem(); 
					}	
					else  {
						maNV.khongDuocNhap = true; 
					}	
				}
				
				
			}
			else if (soHD.isMouseHover(xclick,yclick)) {
				
				
				soHD.NhapVao(kiTuChuHoacSo,""); 
				bool kiemTraTrung = DSNV.timKiemHD(soHD.boNhoDem); // tra ve True neu tim thay!
				if (kiemTraTrung && !soHD.khongDuocNhap ) {
					MessageBox(NULL, "Da ton tai maHD nay!", "Thong Bao", MB_ICONINFORMATION | MB_OK);
					soHD.resetBoNhoDem(); 
				}
				else if (soHD.boNhoDem != "") {
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
				if (nhapNgay.boNhoDem == "" || nhapThang.boNhoDem == "" || nhapNam.boNhoDem == "" || maNV.boNhoDem == "" || soHD.boNhoDem == "" ) {
					MessageBox(NULL, "Vui Long Dien Vao Hoa Don!", "thong bao", MB_ICONINFORMATION | MB_OK);
				}
				else if (!daThemHD) { // truong hop dsct hd dang rong!
					MessageBox(NULL, "Vui Long Dien vao Chi Tiet Hoa Don!", "thong bao", MB_ICONINFORMATION | MB_OK);
				}
				else {
		        	MessageBox(NULL, "Them thanh cong", "thong bao", MB_ICONINFORMATION | MB_OK);
		        	tempHD->getdsCTHD()->capNhapSoLuongVatTu(dsVatTu,"X"); 
		        	DSNV.ghiFileDSNV("data/dataNhanVien.txt"); 
		        	dsVatTu.ghiVatTuFile(); 
		    		index = ID_THEM_HD_XUAT; 
		    		return; 
					
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
				donGia.NhapVao(kiemTraSoThuc,"chi nhap so!"); 
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
					soLuongCTHDTrenTable = hienThiCTHDLenTable(indexPage,soPhanTuTrenMotPage,tempHD->getdsCTHD(),dsVatTu); 
					indexPage++; 
					setcolor(CinputText); 
					setbkcolor(0); 
					settextstyle(6, 0, 1);
					string temp = TienichDoHoa::intToString(indexPage) + "/" + TienichDoHoa::intToString(toiDaPage);
					outtextxy(DODAIMANHINH/2 -110,720,(char*)(temp.c_str())); 
					indexPage--; 
				}
			}
			else if (btnLui.isMouseHover(xclick,yclick)) {
				if (indexPage > 0) {
					indexPage--;
					veTableCTHD(); 
					soLuongCTHDTrenTable = hienThiCTHDLenTable(indexPage,soPhanTuTrenMotPage,tempHD->getdsCTHD(),dsVatTu); 
					indexPage++;
					string temp = TienichDoHoa::intToString(indexPage) + "/" + TienichDoHoa::intToString(toiDaPage);
					setcolor(CinputText); 
					setbkcolor(0); 
					settextstyle(6, 0, 1);
					outtextxy(DODAIMANHINH/2 - 110, 720,(char*)(temp.c_str())); 
					indexPage--; 
					
				}
			}
		
			else if (themTT.isMouseHover(xclick,yclick)) {
				if (!(nhapNgay.boNhoDem == "" || nhapThang.boNhoDem == "" || nhapNam.boNhoDem == "" || maNV.boNhoDem == "" || soHD.boNhoDem == "" || maVT.boNhoDem == "" || soLuongVT.boNhoDem == "" || donGia.boNhoDem == "" && VAT.boNhoDem == "")  ) {
					float tempSL = TienichDoHoa::stringToFloat(soLuongVT.boNhoDem); 
					float tempdonGia = TienichDoHoa::stringToFloat(donGia.boNhoDem); 
					float tempVAT = TienichDoHoa::stringToFloat(VAT.boNhoDem); 
					if (!daThemHD) {
						tempHD = tempNV->dsHoaDon.themVaoCuoiHD(soHD.boNhoDem,tempDate,"X"); 
						daThemHD = true;
					}
					NodeVatTu* tempVT = dsVatTu.timKiemVT(maVT.boNhoDem); // chan chac tim thay -> vi tren kia da bac dieu kien 
					
				
					if (!tempVT->getInfo()->kiemTraDuHang(tempSL)) {
						// lay ra so luong => 
						string thongBao = + "khong du Vat Tu! so luong ton trong kho " + TienichDoHoa::floatToString(tempVT->getInfo()->soLuongTon); 
						MessageBox(NULL, thongBao.c_str(), "thong bao", MB_ICONINFORMATION | MB_OK); 
						soLuongVT.resetBoNhoDem(); 
					}
					else {
					CThoaDon tempCTHD(maVT.boNhoDem,tempSL,tempdonGia,tempVAT); // khi tat ca da thoa dieu kien. 
					tempHD->themCTHD(tempCTHD);
					int soLuongCTHD =  tempHD->getdsCTHD()->soLuongCTHD(); 
					soLuongPage = soLuongCTHD  / soPhanTuTrenMotPage; 
					toiDaPage = (float)soLuongCTHD / (float)soPhanTuTrenMotPage; 
					if (!kiemTraSoNguyen(TienichDoHoa::floatToString(toiDaPage))) {
							toiDaPage = (int)toiDaPage + 1;   
					}
					veTableCTHD();  
					soLuongCTHDTrenTable = hienThiCTHDLenTable(indexPage,soPhanTuTrenMotPage,tempHD->getdsCTHD(),dsVatTu);
					indexPage++; 
					string temp = TienichDoHoa::intToString(indexPage) + "/" + TienichDoHoa::intToString(toiDaPage);
					setcolor(CinputText); 
					setbkcolor(0); 
					settextstyle(6, 0, 1);
					outtextxy(DODAIMANHINH/2 - 110, 720,(char*)(temp.c_str())); 
					indexPage--;
					
					maVT.resetBoNhoDem(); 
					soLuongVT.resetBoNhoDem(); 
					donGia.resetBoNhoDem(); 
					VAT.resetBoNhoDem(); 
					outtextxy(margin + 1250,720,TienichDoHoa::floatToString(tempHD->getdsCTHD()->tinhTongTien()).c_str());
					}
				}
				else {
					MessageBox(NULL, "khong duoc bo trong!", "thong bao", MB_ICONINFORMATION | MB_OK);
				}
			}
			// y tuong =>
			// hien thi len 1 cai box va cho nguoi dung lua chon 
			// neu nhap vao chinh sua hoac xoa
			// neu nhu 
			else if (hieuChinhCTHD1.isMouseHover(xclick,yclick)) {
				if ( soLuongCTHDTrenTable != 0  ) { 
					pointerCTHD = tempHD->getdsCTHD()->traVeCTHDTheoindex(soPhanTuTrenMotPage*indexPage); 
					if (pointerCTHD != NULL) {
						hienThiChinhSuaCTHD(pointerCTHD,tempHD->getdsCTHD(),dsVatTu,"X"); 
						// sau khi ket thuc thi ve lai cai bang thoi -> vi da lo xoa truoc do
					// khuc nay la khuc ve lai bang. 	
					veTableCTHD();  
					soLuongCTHDTrenTable = hienThiCTHDLenTable(indexPage,soPhanTuTrenMotPage,tempHD->getdsCTHD(),dsVatTu);
					indexPage++; 
					string temp = TienichDoHoa::intToString(indexPage) + "/" + TienichDoHoa::intToString(toiDaPage);
					setcolor(CinputText); 
					setbkcolor(0); 
					settextstyle(6, 0, 1);
					outtextxy(DODAIMANHINH/2 - 110, 720,(char*)(temp.c_str())); 
					indexPage--;
						
					}	
				}	
				
			}
			else if (hieuChinhCTHD2.isMouseHover(xclick,yclick)) {
				if ( soLuongCTHDTrenTable != 0  ) { 
					pointerCTHD = tempHD->getdsCTHD()->traVeCTHDTheoindex(1 + soPhanTuTrenMotPage*indexPage); 
					if (pointerCTHD != NULL) {
						// thuc hien => cho hieu chinh CTHD nay. 
					}	
				}
			}	
			else if (hieuChinhCTHD3.isMouseHover(xclick,yclick)) {
				if ( soLuongCTHDTrenTable != 0  ) { 
					pointerCTHD = tempHD->getdsCTHD()->traVeCTHDTheoindex(2 + soPhanTuTrenMotPage*indexPage); 
					if (pointerCTHD != NULL) {
						// thuc hien => cho hieu chinh CTHD nay. 
					}	
				}
			}	
			else if (hieuChinhCTHD4.isMouseHover(xclick,yclick)) {
				if ( soLuongCTHDTrenTable != 0  ) { 
					pointerCTHD = tempHD->getdsCTHD()->traVeCTHDTheoindex(3 + soPhanTuTrenMotPage*indexPage); 
					if (pointerCTHD != NULL) {
						// thuc hien => cho hieu chinh CTHD nay. 
					}	
				}
			}		
			else if (hieuChinhCTHD5.isMouseHover(xclick,yclick)) {
				if ( soLuongCTHDTrenTable != 0  ) { 
					pointerCTHD = tempHD->getdsCTHD()->traVeCTHDTheoindex(4 + soPhanTuTrenMotPage*indexPage); 
					if (pointerCTHD != NULL) {
						// thuc hien => cho hieu chinh CTHD nay. 
					}	
				}
			}	
			else if (hieuChinhCTHD6.isMouseHover(xclick,yclick)) {
			if ( soLuongCTHDTrenTable != 0  ) { 
					pointerCTHD = tempHD->getdsCTHD()->traVeCTHDTheoindex(5 + soPhanTuTrenMotPage*indexPage); 
					if (pointerCTHD != NULL) {
						// thuc hien => cho hieu chinh CTHD nay. 
					}	
				}
			}	
			else if (hieuChinhCTHD7.isMouseHover(xclick,yclick)) {
			if ( soLuongCTHDTrenTable != 0  ) { 
					pointerCTHD = tempHD->getdsCTHD()->traVeCTHDTheoindex(6 + soPhanTuTrenMotPage*indexPage); 
					if (pointerCTHD != NULL) {
						// thuc hien => cho hieu chinh CTHD nay. 
					}	
				}
			}	
			else if (hieuChinhCTHD8.isMouseHover(xclick,yclick)) {
				if ( soLuongCTHDTrenTable != 0  ) { 
					pointerCTHD = tempHD->getdsCTHD()->traVeCTHDTheoindex(7 + soPhanTuTrenMotPage*indexPage); 
					if (pointerCTHD != NULL) {
						// thuc hien => cho hieu chinh CTHD nay. 
					}	
				} 
			}	
			else if (hieuChinhCTHD9.isMouseHover(xclick,yclick)) {
				if ( soLuongCTHDTrenTable != 0  ) { 
					pointerCTHD = tempHD->getdsCTHD()->traVeCTHDTheoindex(8 + soPhanTuTrenMotPage*indexPage); 
					if (pointerCTHD != NULL) {
						// thuc hien goi ham hieu chinh CTHD.  
					}	
				}
			}	
		}
	delay(10);
}
	
}

void hienThiTinhNangHoaDon(BstVatTu &dsVatTu,dsNhanVien &DSNV,int &index,NutBam &vatTu
,NutBam &nhanVien ,NutBam &doanhThu)                                                        {
	TienichDoHoa::xoaManHinhTheoToaDo(0,56,DODAIMANHINH,DORONGMANHINH,BACKGROUP);
	bool kiemTra[3] = {false};
	bool kiemTraHD[2] = {false};
	index = -1; 
	const int WMenuSub = 230; 
	const int HMenuSub = 35;
	const int marginLeftSub = 56; 
	const int marginTopSub = 62 ;
	NutBam themHDNhap(marginLeftSub ,marginTopSub,WMenuSub,HMenuSub,COLOR_BTN_SUB,COLOR_HIGHT_BTN_SUB,COLOR_TEXT_BTN_SUB,"Them Hoa Don Nhap");
	NutBam inHD(WMenuSub + marginLeftSub + 2 ,marginTopSub,WMenuSub,HMenuSub,COLOR_BTN_SUB,COLOR_HIGHT_BTN_SUB,COLOR_TEXT_BTN_SUB,"In Hoa Don");
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
				if (index == ID_THEM_HD_XUAT) {
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
