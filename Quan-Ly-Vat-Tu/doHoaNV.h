#pragma once
using namespace std; 
#include "Tienich.h"
#include "BienDoHoa.h"
#include "DoHoaHD.h"

// viet ham hien thi table 


// chua sua !


//void chinhSuaNV(NhanVien &DSNV,NhanVien* nhanVienCT) {  
//	OVuong them(margin + doDaiCoban*6 - 60,canLeTrenHD + 140 ,margin + doDaiCoban*3 + 30,400,15); 
//	NutBam titleCSVT(margin + doDaiCoban*6 - 60,canLeTrenHD + 140,margin + doDaiCoban*3 + 30,40,15,0,0,"Hieu Chinh Vat Tu");
//	 
//	titleCSVT.veNut();  
//	ONhap nhapMaVT(margin + doDaiCoban*6 ,canLeTrenHD + 170 + 30,doDaiCoban*3 - 100,40,60,"ma: ",0,0,10); 
//	ONhap nhapTenVT(margin + doDaiCoban*6 ,canLeTrenHD + 170 + 100,doDaiCoban*3 - 100,40,60,"ten: ",0,0,50);
//	ONhap nhapSoLuong(margin + doDaiCoban*6 ,canLeTrenHD + 170 + 70 * 2 + 30,doDaiCoban*3 - 100,40,60,"sl: ",0,0,10);
//	ONhap nhapDVT(margin + doDaiCoban*6 ,canLeTrenHD + 170 + 50 + 70 * 2 + 50,doDaiCoban*3 - 100,40,60,"dvt: ",0,0,30);
//	nhapMaVT.boNhoDem = vatTuCT->maVT; // lay ra maVT 
//	nhapTenVT.boNhoDem = vatTuCT->ten; 
//	nhapSoLuong.boNhoDem = TienichDoHoa::floatToString(vatTuCT->soLuongTon);
//	nhapDVT.boNhoDem =  vatTuCT->donVi;
//	
//	// tiep theo la bac dieu kien thoi => cho nguoi dung chinh sua nhung truoc tien can lay ra gia tri truoc khi chinh sua 
//	string maVTCu = vatTuCT->maVT; 
//	string tenVTCu = vatTuCT->ten; 
//	string dvtCu  = vatTuCT->donVi; 
//	// ngoai ra con ve 1 cai nut thoat cho nguoi dung nua => sau khi nhap nut thoat thi ket thuc ham va ve lai  
//
//	 
//	
//	
//	nhapMaVT.veONhap(); 
//	nhapTenVT.veONhap(); 
//	nhapSoLuong.veONhap(); 
//	nhapDVT.veONhap(); 
//	
//	nhapMaVT.inNoiDung(); 
//	nhapTenVT.inNoiDung(); 
//	nhapSoLuong.inNoiDung(); 
//	nhapDVT.inNoiDung(); 
//	
//	NutBam saveVT(margin +doDaiCoban*6 - 60,canLeTrenHD + 170 + 50 + 160 + 120,margin + doDaiCoban*3 + 30,40,0,2,0,"");
//	saveVT.veNut(); 
//	NutBam xoa(margin +doDaiCoban*6 - 60,canLeTrenHD + 170 + 50 + 160 + 120,(margin + doDaiCoban*3 + 30) /2 - 1,40,13,2,0,"xoa");
//	xoa.veNut(); 
//	
//	NutBam hieuChinh(margin +doDaiCoban*6 - 60 + (margin + doDaiCoban*3 + 30) /2 + 1,canLeTrenHD + 170 + 50 + 160 + 120,(margin + doDaiCoban*3 + 30) /2,40,13,2,0,"hieu chinh"); 
//	hieuChinh.veNut(); 
//	
//	// tao them 1 nut tac
//	NutBam thoat(margin + doDaiCoban*6 - 60 + (margin + doDaiCoban*3 + 30 - 40 ) ,canLeTrenHD + 140,40,40,4,0,15,"X"); 
//	thoat.veNut(); 
//	int xclick = -1; 
//	int yclick = -1; 
//	while (true) {
//		if (ismouseclick(WM_LBUTTONDOWN)) {  
//			getmouseclick(WM_LBUTTONDOWN, xclick, yclick); 
//			if (nhapMaVT.isMouseHover(xclick,yclick)) {
//				nhapMaVT.NhapVao(kiTuChuHoacSo,""); 
//				// sau khi nhap song kiem tra xem co trung hay khong ! 
//				if (nhapMaVT.boNhoDem != "" && nhapMaVT.boNhoDem != maVTCu) {
//
//					if (dsVatTu.timKiemVT(nhapMaVT.boNhoDem) != NULL) { // da ton tai roi -> nen moi tim thay!
//						MessageBox(NULL, "Da Ton Tai Ma Vat Tu Nay!", "thong bao", MB_ICONINFORMATION | MB_OK);
//						nhapMaVT.resetBoNhoDem();
//					}
//				}
//				
// 			}
// 			
//				else if (nhapTenVT.isMouseHover(xclick,yclick)) {
//					nhapTenVT.NhapVao(kiTuChuHoacSo,""); 
//				}
//				else if (nhapDVT.isMouseHover(xclick,yclick)) {
//					nhapDVT.NhapVao(kiTuChu,""); 
//				}
//				else if (hieuChinh.isMouseHover(xclick,yclick)) { // nhap vao !
//					if (nhapTenVT.boNhoDem == "" || nhapMaVT.boNhoDem == "" || nhapDVT.boNhoDem == "") {
//						MessageBox(NULL, "Khong Duoc Bo Trong!", "thong ba", MB_ICONINFORMATION | MB_OK);
//					}
//					else if (nhapMaVT.boNhoDem != maVTCu || nhapTenVT.boNhoDem != tenVTCu || nhapDVT.boNhoDem != dvtCu) { // phai co thang nao thay doi thi moi chinh sua !
//						vatTuCT->maVT = nhapMaVT.boNhoDem; 
//						vatTuCT->ten = nhapTenVT.boNhoDem; 
//						vatTuCT->donVi = nhapDVT.boNhoDem; 
//						MessageBox(NULL, "Hieu Chinh Thanh Cong!", "Thong Bao", MB_ICONINFORMATION | MB_OK); 
//						break; 	
//					}
//				
//				}
// 		
// 				
//				else if (thoat.isMouseHover(xclick,yclick)) {
//					break; 
//				}
//				else if (xoa.isMouseHover(xclick,yclick)) {
//					if (nhapMaVT.boNhoDem == maVTCu && nhapTenVT.boNhoDem == tenVTCu && nhapDVT.boNhoDem == dvtCu) {
//						int luaChon = MessageBox(NULL, "ban co chac chac muon xoa!", "thong bao", MB_ICONWARNING | MB_OKCANCEL);
//						if (luaChon == OK) { // xoa di !
//							dsVatTu.xoaVT(nhapMaVT.boNhoDem); 
//							MessageBox(NULL, "Xoa Vat Tu Thanh Cong!", "Thong Bao", MB_ICONINFORMATION | MB_OK); 
//							break;  
//						}
//					}
//					
//				}
//			
//			
//			
//		}
//		delay(1); 
//	}
//	
//
//	
//}


//void inDanhSachLenDoHoa(NodeVatTu **arrVT,int indexPage,int soLuongItemPage,int soLuongNode) {	
//	const int canLeY = 170;  // cach oVuong 110 va cach tieuDe 40
//	const int canLeX = DODAIMANHINH/2 - 1200/2 + 100; 
//	const int donViO = 1200 / 5; 
//	setbkcolor(BACKGROUP); 
//	const int cachNhau = 30; 
//	string tempDVT; 
//	// =================== CHUA VIET HAM XOA DI DU LIEU CU =================== 
//	 
//	setcolor(CinputText); 
//	for (int i = 0;i < soLuongItemPage;i++) {
//		if (i + indexPage*soLuongItemPage < soLuongNode  ) {
//		tempDVT = TienichDoHoa::floatToString(arrVT[i + indexPage*soLuongItemPage]->getInfo()->soLuongTon); 
//		outtextxy(canLeX,           canLeY + cachNhau*i,(char*)(arrVT[i + indexPage*soLuongItemPage]->getInfo()->maVT.c_str()));
//		outtextxy(canLeX + donViO*1,canLeY + cachNhau*i,(char*)(arrVT[i + indexPage*soLuongItemPage]->getInfo()->ten.c_str()));
//		outtextxy(canLeX + donViO*3,canLeY + cachNhau*i,(char*)(arrVT[i + indexPage*soLuongItemPage]->getInfo()->donVi.c_str()));
//		outtextxy(canLeX + donViO*4,canLeY + cachNhau*i,(char*)(tempDVT.c_str()));
//		}	
//	}	
//}





void veTableNV() {
	TienichDoHoa::xoaManHinhTheoToaDo(0,140,900,580,BACKGROUP); 
	NutBam titleMaNV(margin,canLeTrenHD + 170 - 129,doDaiCoban,40,colorTieuDe,7,conlorTextTieuDe,"MA NHAN VIEN"); 
	NutBam titileTenNV(margin + doDaiCoban + 3  ,canLeTrenHD + 170 - 129,doDaiCoban*3 - 60 + 4,40,colorTieuDe,7,conlorTextTieuDe,"HO VA TEN");
	NutBam titileGioiTinh(margin + doDaiCoban*4 + 3*3 - 60,canLeTrenHD + 170 - 129,doDaiCoban ,40,colorTieuDe,7,conlorTextTieuDe,"GIOI TINH"); 
	NutBam titileHieuChinh(margin + doDaiCoban*5 + 3*4 - 60,canLeTrenHD + 170 - 129,doDaiCoban + 6 - 60,40,colorTieuDe,7,conlorTextTieuDe,"SUA");
	titleMaNV.veNut(); 
	titileTenNV.veNut(); 
	titileGioiTinh.veNut(); 
	titileHieuChinh.veNut();
	OVuong table(margin,canLeTrenHD + 40 ,doDaiCoban*6 + 18 - 120 ,560,15);
	setcolor(15); 
	line(margin+ doDaiCoban,canLeTrenHD + 170 - 129,margin+ doDaiCoban,720); 
//	line(margin+ doDaiCoban*3 + 3 - 60,canLeTrenHD + 170 - 129,margin+ doDaiCoban*3 + 3 - 60,720);
	line(margin+ doDaiCoban*4 + 3*2 - 60 ,canLeTrenHD + 170 - 129,margin+ doDaiCoban*4 + 3*2 - 60,720);
	line(margin+ doDaiCoban*5 + 3*3 - 60,canLeTrenHD + 170 - 129,margin+ doDaiCoban*5 + 3*3 - 60,720);
}


// viet 1 ham do du lieu len ham thong qua con mang VT 

int hienThiDuLieuLenTableNV(int indexPage,int soLuongPhanTuTrenMotPage,dsNhanVien &DSNV) {
	int index; 
	int khoanCach = 46; 
	int marginTop = canLeTrenHD + 170 - 70; 
	int soLuongNV = DSNV.soLuongNV(); 
	string temp;
	int dem = 0; 
	// lay ra dia chi cua mang
	NhanVien** arrNV = DSNV.getDSNV(); 
	for (int i = 0; i < soLuongPhanTuTrenMotPage;i++) {
		setcolor(CinputText); 
		setbkcolor(0); 
		settextstyle(6, 0, 1);
		if ( i + indexPage*soLuongPhanTuTrenMotPage < soLuongNV) {
			 index =  i + indexPage * soLuongPhanTuTrenMotPage; 
			 temp = TienichDoHoa::floatToString(arrVT[index]->soLuongTon); 
			 outtextxy(margin + 30,marginTop + khoanCach*i,arrVT[index]->maVT.c_str());  // hien thi ra maVT 
			 outtextxy(margin + 186,marginTop + khoanCach*i,arrVT[index]->ten.c_str());  // hien thi ra maVT
			 outtextxy(margin + 600,marginTop + khoanCach*i,temp.c_str());  // hien thi ra maVT
			 line(margin,marginTop + khoanCach*i + 32,margin + 830,marginTop + khoanCach*i + 32); 
			 NutBam hieuChinh(margin + 760,marginTop + khoanCach*i -4,60,28,11,0,0,"sua"); 
			 hieuChinh.veNut(); 
			 dem++; 
		}
	}
	return dem; 
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                                        //
//	                                      HIEN THI TINH NANG VAT TU MOI                                                   //                
//                                                                                                                        //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void hienThiTinhNangNhanVien(dsNhanVien &DSNV,int &index,NutBam &VatTu,NutBam &hoaDon,NutBam &doanhThu,bool(*khoaSapXep)(NhanVien*,NhanVien*)) {
	
	
	
	// khai bao bien quan trong 
	int indexPage = 0; 
	int soLuongPhanTuHienThi = 0; 
	int itemTrenMotPage = 11; 
	int toaDoChiMucX = DODAIMANHINH/2 -110; 
	NhanVien *tempNV; 
	int soLuongNV = DSNV.soLuongNV(); 

	int soLuongPage = soLuongNV  / itemTrenMotPage; 
	float toiDaPage = (float)soLuongNV / (float)itemTrenMotPage; 
	
	if (!kiemTraSoNguyen(TienichDoHoa::floatToString(toiDaPage))) {
			toiDaPage = (int)toiDaPage + 1;   
	}
	
	
	

	
	TienichDoHoa::xoaManHinhTheoToaDo(0,60,1600,1600,BACKGROUP); 
	
	// bac dau ve ra truoc tien la ve ra cac title
	OVuong themNV(margin + doDaiCoban*6 - 60,canLeTrenHD + 140 ,margin + doDaiCoban*3 + 30,400,15); 
	NutBam titleThemNV(margin + doDaiCoban*6 - 60,canLeTrenHD + 140,margin + doDaiCoban*3 + 30,40,15,0,0,"THEM NHAN VIEN"); 
	titleThemNV.veNut();  
	ONhap nhapMaNV(margin + doDaiCoban*6 ,canLeTrenHD + 170 + 30,doDaiCoban*3 - 100,40,60,"MA: ",0,0,10); 
	ONhap nhapHoNV(margin + doDaiCoban*6 ,canLeTrenHD + 170 + 100,doDaiCoban*3 - 100,40,60,"HO: ",0,0,20);
	ONhap nhapTenNV(margin + doDaiCoban*6 ,canLeTrenHD + 170 + 70 * 2 + 30,doDaiCoban*3 - 100,40,60,"TEN: ",0,0,10);
	
	// tao ra 2 nut bam Nam Nu 
	NutBam nam(margin + doDaiCoban*6 + 60,canLeTrenHD + 170 + 70 * 2 + 30 + 70,60,40,11,0,0,"NAM"); 
	nam.veNut(); 
	
	NutBam nu(margin + doDaiCoban*6 + 364,canLeTrenHD + 170 + 70 * 2 + 30 + 70,60,40,11,0,0,"NU"); 
	nu.veNut(); 
	nhapMaNV.veONhap(); 
	nhapHoNV.veONhap(); 
	nhapTenNV.veONhap(); 
	
	// ve ra o Vuong ngan cach nam nu 
	line(margin + doDaiCoban*6 + 200 + 36,canLeTrenHD + 170 + 70 * 2 + 30 + 60,margin + doDaiCoban*6 + 200 + 36,canLeTrenHD + 170 + 70 * 2 + 30 + 120);

	NutBam saveVT(margin +doDaiCoban*6 - 60,canLeTrenHD + 170 + 50 + 160 + 120,margin + doDaiCoban*3 + 30,40,14,2,0,"SAVE");
	saveVT.veNut(); 
	
	
	
	veTableNV();
	
	NutBam btnLui(margin,730,100,40,15,0,0,"<<");
	NutBam btnTien(margin + 730,730,100,40,15,0,0,">>");
	btnLui.veNut(); 	
	btnTien.veNut(); 
	
	
	
}


