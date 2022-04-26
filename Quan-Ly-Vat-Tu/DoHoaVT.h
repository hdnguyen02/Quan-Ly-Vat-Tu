#pragma once
using namespace std; 
#include "Tienich.h"
#include "BienDoHoa.h"
#include "DoHoaHD.h" 


// thuyet ke 1 ham hien thi ra table CTHD -> sau do cho dung cho thoi 
// 
void chinhSuaVT(BstVatTu &dsVatTu,VatTu* vatTuCT) {  
	OVuong themVT(margin + doDaiCoban*6 - 60,canLeTrenHD + 140 ,margin + doDaiCoban*3 + 30,400,15); 
	NutBam titleCSVT(margin + doDaiCoban*6 - 60,canLeTrenHD + 140,margin + doDaiCoban*3 + 30,40,15,0,0,"Hieu Chinh Vat Tu");
	 
	titleCSVT.veNut();  
	ONhap nhapMaVT(margin + doDaiCoban*6 ,canLeTrenHD + 170 + 30,doDaiCoban*3 - 100,40,60,"ma: ",0,0,10); 
	ONhap nhapTenVT(margin + doDaiCoban*6 ,canLeTrenHD + 170 + 100,doDaiCoban*3 - 100,40,60,"ten: ",0,0,50);
	ONhap nhapSoLuong(margin + doDaiCoban*6 ,canLeTrenHD + 170 + 70 * 2 + 30,doDaiCoban*3 - 100,40,60,"sl: ",0,0,10);
	ONhap nhapDVT(margin + doDaiCoban*6 ,canLeTrenHD + 170 + 50 + 70 * 2 + 50,doDaiCoban*3 - 100,40,60,"dvt: ",0,0,30);
	nhapMaVT.boNhoDem = vatTuCT->maVT; // lay ra maVT 
	nhapTenVT.boNhoDem = vatTuCT->ten; 
	nhapSoLuong.boNhoDem = TienichDoHoa::floatToString(vatTuCT->soLuongTon);
	nhapDVT.boNhoDem =  vatTuCT->donVi;
	
	// tiep theo la bac dieu kien thoi => cho nguoi dung chinh sua nhung truoc tien can lay ra gia tri truoc khi chinh sua 
	string maVTCu = vatTuCT->maVT; 
	string tenVTCu = vatTuCT->ten; 
	string dvtCu  = vatTuCT->donVi; 
	// ngoai ra con ve 1 cai nut thoat cho nguoi dung nua => sau khi nhap nut thoat thi ket thuc ham va ve lai  

	 
	
	
	nhapMaVT.veONhap(); 
	nhapTenVT.veONhap(); 
	nhapSoLuong.veONhap(); 
	nhapDVT.veONhap(); 
	
	nhapMaVT.inNoiDung(); 
	nhapTenVT.inNoiDung(); 
	nhapSoLuong.inNoiDung(); 
	nhapDVT.inNoiDung(); 
	
	NutBam saveVT(margin +doDaiCoban*6 - 60,canLeTrenHD + 170 + 50 + 160 + 120,margin + doDaiCoban*3 + 30,40,0,2,0,"");
	saveVT.veNut(); 
	NutBam xoa(margin +doDaiCoban*6 - 60,canLeTrenHD + 170 + 50 + 160 + 120,(margin + doDaiCoban*3 + 30) /2 - 1,40,13,2,0,"xoa");
	xoa.veNut(); 
	
	NutBam hieuChinh(margin +doDaiCoban*6 - 60 + (margin + doDaiCoban*3 + 30) /2 + 1,canLeTrenHD + 170 + 50 + 160 + 120,(margin + doDaiCoban*3 + 30) /2,40,13,2,0,"hieu chinh"); 
	hieuChinh.veNut(); 
	
	// tao them 1 nut tac
	NutBam thoat(margin + doDaiCoban*6 - 60 + (margin + doDaiCoban*3 + 30 - 40 ) ,canLeTrenHD + 140,40,40,4,0,15,"X"); 
	thoat.veNut(); 
	int xclick = -1; 
	int yclick = -1; 
	while (true) {
		if (ismouseclick(WM_LBUTTONDOWN)) {  
			getmouseclick(WM_LBUTTONDOWN, xclick, yclick); 
			if (nhapMaVT.isMouseHover(xclick,yclick)) {
				nhapMaVT.NhapVao(kiTuChuHoacSo,""); 
				// sau khi nhap song kiem tra xem co trung hay khong ! 
				if (nhapMaVT.boNhoDem != "" && nhapMaVT.boNhoDem != maVTCu) {

					if (dsVatTu.timKiemVT(nhapMaVT.boNhoDem) != NULL) { // da ton tai roi -> nen moi tim thay!
						MessageBox(NULL, "Da Ton Tai Ma Vat Tu Nay!", "thong bao", MB_ICONINFORMATION | MB_OK);
						nhapMaVT.resetBoNhoDem();
					}
				}
				
 			}
 			
				else if (nhapTenVT.isMouseHover(xclick,yclick)) {
					nhapTenVT.NhapVao(kiTuChuHoacSo,""); 
				}
				else if (nhapDVT.isMouseHover(xclick,yclick)) {
					nhapDVT.NhapVao(kiTuChu,""); 
				}
				else if (hieuChinh.isMouseHover(xclick,yclick)) { // nhap vao !
					if (nhapTenVT.boNhoDem == "" || nhapMaVT.boNhoDem == "" || nhapDVT.boNhoDem == "") {
						MessageBox(NULL, "Khong Duoc Bo Trong!", "thong ba", MB_ICONINFORMATION | MB_OK);
					}
					else if (nhapMaVT.boNhoDem != maVTCu || nhapTenVT.boNhoDem != tenVTCu || nhapDVT.boNhoDem != dvtCu) { // phai co thang nao thay doi thi moi chinh sua !
						vatTuCT->maVT = nhapMaVT.boNhoDem; 
						vatTuCT->ten = nhapTenVT.boNhoDem; 
						vatTuCT->donVi = nhapDVT.boNhoDem; 
						MessageBox(NULL, "Hieu Chinh Thanh Cong!", "Thong Bao", MB_ICONINFORMATION | MB_OK); 
						break; 	
					}
				
				}
 		
 				
				else if (thoat.isMouseHover(xclick,yclick)) {
					break; 
				}
				else if (xoa.isMouseHover(xclick,yclick)) {
					if (nhapMaVT.boNhoDem == maVTCu && nhapTenVT.boNhoDem == tenVTCu && nhapDVT.boNhoDem == dvtCu) {
						int luaChon = MessageBox(NULL, "ban co chac chac muon xoa!", "thong bao", MB_ICONWARNING | MB_OKCANCEL);
						if (luaChon == OK) { // xoa di !
							dsVatTu.xoaVT(nhapMaVT.boNhoDem); 
							MessageBox(NULL, "Xoa Vat Tu Thanh Cong!", "Thong Bao", MB_ICONINFORMATION | MB_OK); 
							break;  
						}
					}
					
				}
			
			
			
		}
		delay(1); 
	}
	

	
}


void inDanhSachLenDoHoa(NodeVatTu **arrVT,int indexPage,int soLuongItemPage,int soLuongNode) {	
	const int canLeY = 170;  // cach oVuong 110 va cach tieuDe 40
	const int canLeX = DODAIMANHINH/2 - 1200/2 + 100; 
	const int donViO = 1200 / 5; 
	setbkcolor(BACKGROUP); 
	const int cachNhau = 30; 
	string tempDVT; 
	// =================== CHUA VIET HAM XOA DI DU LIEU CU =================== 
	 
	setcolor(CinputText); 
	for (int i = 0;i < soLuongItemPage;i++) {
		if (i + indexPage*soLuongItemPage < soLuongNode  ) {
		tempDVT = TienichDoHoa::floatToString(arrVT[i + indexPage*soLuongItemPage]->getInfo()->soLuongTon); 
		outtextxy(canLeX,           canLeY + cachNhau*i,(char*)(arrVT[i + indexPage*soLuongItemPage]->getInfo()->maVT.c_str()));
		outtextxy(canLeX + donViO*1,canLeY + cachNhau*i,(char*)(arrVT[i + indexPage*soLuongItemPage]->getInfo()->ten.c_str()));
		outtextxy(canLeX + donViO*3,canLeY + cachNhau*i,(char*)(arrVT[i + indexPage*soLuongItemPage]->getInfo()->donVi.c_str()));
		outtextxy(canLeX + donViO*4,canLeY + cachNhau*i,(char*)(tempDVT.c_str()));
		}	
	}	
}





void veTableVT() {
	TienichDoHoa::xoaManHinhTheoToaDo(0,140,900,580,BACKGROUP); 
	NutBam titleMaVT(margin,canLeTrenHD + 170 - 129,doDaiCoban,40,colorTieuDe,7,conlorTextTieuDe,"ma vat tu"); 
	NutBam titileTenVT(margin + doDaiCoban + 3 ,canLeTrenHD + 170 - 129,doDaiCoban*2 - 60,40,colorTieuDe,7,conlorTextTieuDe,"ten");
	NutBam titiledonViVT(margin + doDaiCoban*3 + 3*2 - 60,canLeTrenHD + 170 - 129,doDaiCoban ,40,colorTieuDe,7,conlorTextTieuDe,"don vi"); 
	NutBam titilesoLuongVT(margin + doDaiCoban*4 + 3*3 - 60,canLeTrenHD + 170 - 129,doDaiCoban,40,colorTieuDe,7,conlorTextTieuDe,"so luong ton"); 
	NutBam titleHieuChinhVT(margin + doDaiCoban*5 + 3*4 - 60,canLeTrenHD + 170 - 129,doDaiCoban + 6 - 60,40,colorTieuDe,7,conlorTextTieuDe,"sua");
	titleMaVT.veNut(); 
	titilesoLuongVT.veNut();
	titileTenVT.veNut(); 
	titiledonViVT.veNut(); 
	titleHieuChinhVT.veNut();
	OVuong table(margin,canLeTrenHD + 40 ,doDaiCoban*6 + 18 - 120 ,560,15);
	setcolor(15); 
	line(margin+ doDaiCoban,canLeTrenHD + 170 - 129,margin+ doDaiCoban,720); 
	line(margin+ doDaiCoban*3 + 3 - 60,canLeTrenHD + 170 - 129,margin+ doDaiCoban*3 + 3 - 60,720);
	line(margin+ doDaiCoban*4 + 3*2 - 60 ,canLeTrenHD + 170 - 129,margin+ doDaiCoban*4 + 3*2 - 60,720);
	line(margin+ doDaiCoban*5 + 3*3 - 60,canLeTrenHD + 170 - 129,margin+ doDaiCoban*5 + 3*3 - 60,720);
}


// viet 1 ham do du lieu len ham thong qua con mang VT 

int hienThiDuLieuLenTableVT(int indexPage,int soLuongPhanTuTrenMotPage,VatTu** arrVT,int soLuongVT) {
	int index; 
	int khoanCach = 46; 
	int marginTop = canLeTrenHD + 170 - 70; 
	
	string temp;
	int dem = 0; 
	for (int i = 0; i < soLuongPhanTuTrenMotPage;i++) {
		setcolor(CinputText); 
		setbkcolor(0); 
		settextstyle(6, 0, 1);
		if ( i + indexPage*soLuongPhanTuTrenMotPage < soLuongVT) {
			 index =  i + indexPage * soLuongPhanTuTrenMotPage; 
			 temp = TienichDoHoa::floatToString(arrVT[index]->soLuongTon); 
			 outtextxy(margin + 30,marginTop + khoanCach*i,arrVT[index]->maVT.c_str());  // hien thi ra maVT 
			 outtextxy(margin + 186,marginTop + khoanCach*i,arrVT[index]->ten.c_str());  // hien thi ra maVT
			 outtextxy(margin + 430,marginTop + khoanCach*i,arrVT[index]->donVi.c_str());  // hien thi ra maVT
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
void hienThiTinhNangVatTu(BstVatTu &dsVatTu,int &index,NutBam &nhanVien,NutBam &hoaDon,NutBam &doanhThu,bool(*khoaSapXep)(VatTu*,VatTu*)) {
	
	
	
	// khai bao bien quan trong 
	int indexPage = 0; 
	int soLuongPhanTuHienThi = 0; 
	int itemTrenMotPage = 11; 
	int toaDoChiMucX = DODAIMANHINH/2 -110; 
	int toaDoChiMucY = 720; 
	int soLuongVatTuTrenTable = 0; // chua so luongVT hien thi tren page hienTai !
	int soLuongVT = dsVatTu.soLuongVT(); 
	VatTu** arrVT = new VatTu*[soLuongVT];
	NodeVatTu* tempVT; 
	dsVatTu.BstVatTuToArray(arrVT,0); 
	int soLuongPage = soLuongVT  / itemTrenMotPage; 
	float toiDaPage = (float)soLuongVT / (float)itemTrenMotPage; 
	
	if (!kiemTraSoNguyen(TienichDoHoa::floatToString(toiDaPage))) {
			toiDaPage = (int)toiDaPage + 1;   
	}
	
	
	
	// bac su kien nguoi dung nhap vao may cai o 
	
	
	
	
	TienichDoHoa::xoaManHinhTheoToaDo(0,60,1600,1600,BACKGROUP); 
	
	OVuong themVT(margin + doDaiCoban*6 - 60,canLeTrenHD + 140 ,margin + doDaiCoban*3 + 30,400,15); 
	NutBam titleThemVT(margin + doDaiCoban*6 - 60,canLeTrenHD + 140,margin + doDaiCoban*3 + 30,40,15,0,0,"THEM VAT TU"); 
	titleThemVT.veNut();  
	ONhap nhapMaVT(margin + doDaiCoban*6 ,canLeTrenHD + 170 + 30,doDaiCoban*3 - 100,40,60,"MA: ",0,0,10); 
	ONhap nhapTenVT(margin + doDaiCoban*6 ,canLeTrenHD + 170 + 100,doDaiCoban*3 - 100,40,60,"TEN: ",0,0,20);
	ONhap nhapSoLuong(margin + doDaiCoban*6 ,canLeTrenHD + 170 + 70 * 2 + 30,doDaiCoban*3 - 100,40,60,"SL: ",0,0,10);
	ONhap nhapDVT(margin + doDaiCoban*6 ,canLeTrenHD + 170 + 50 + 70 * 2 + 50,doDaiCoban*3 - 100,40,60,"DVT: ",0,0,25);
	nhapMaVT.veONhap(); 
	nhapTenVT.veONhap(); 
	nhapSoLuong.veONhap(); 
	nhapDVT.veONhap(); 
	NutBam saveVT(margin +doDaiCoban*6 - 60,canLeTrenHD + 170 + 50 + 160 + 120,margin + doDaiCoban*3 + 30,40,14,2,0,"SAVE");
	saveVT.veNut(); 
	veTableVT(); 
	
	// ve ra 2 nut 
	NutBam btnLui(margin,730,100,40,15,0,0,"<<");
	NutBam btnTien(margin + 730,730,100,40,15,0,0,">>");
	btnLui.veNut(); 	
	btnTien.veNut(); 
	
	// ve them 2 3 cuc sap xep theo
	setcolor(CinputText); 
	setbkcolor(0); 
	settextstyle(6, 0, 1);
	outtextxy(59,106,"Sap xep theo: "); 
	
	NutBam theoTen(62 + 160,96,100,40,11,13,0,"Ten");
	NutBam theoMaVT(62 + 160 + 120,96,100,40,11,13,0,"ma");
	NutBam theoDVT(62 + 160 + 120*2,96,100,40,11,13,0,"dvt");
	NutBam theoSLT(62 + 160 + 120*3,96,100,40,11,13,0,"slt");
	theoTen.duocTroVao = true; 
	
	
	theoSLT.veNut();   
	theoTen.veNut();  
	theoMaVT.veNut(); 
	theoDVT.veNut();
	dsVatTu.insertionSort(arrVT,soLuongVT,khoaSapXep); 

	soLuongVatTuTrenTable = hienThiDuLieuLenTableVT(indexPage,itemTrenMotPage,arrVT,soLuongVT); 
//	setcolor(CinputText); 
//	setbkcolor(0); 
//	settextstyle(6, 0, 1);
	hienThiChiMuc(430,740,indexPage,toiDaPage); 
	// ve ra 11 cai nut hieu chinh ! tuong ung voi toa do cua bon no 
	int marginTop = canLeTrenHD + 170 - 70; 
	int khoanCach = 46; 
	NutBam hieuChinh1(margin + 760, marginTop+ khoanCach*0 -4,60,28,13,0,0,"sua");
	NutBam hieuChinh2(margin + 760, marginTop+ khoanCach*1 -4,60,28,13,0,0,"sua");
	NutBam hieuChinh3(margin + 760, marginTop+ khoanCach*2 -4,60,28,13,0,0,"sua");
	NutBam hieuChinh4(margin + 760, marginTop+ khoanCach*3 -4,60,28,13,0,0,"sua");
	NutBam hieuChinh5(margin + 760, marginTop+ khoanCach*4 -4,60,28,13,0,0,"sua");
	NutBam hieuChinh6(margin + 760, marginTop+ khoanCach*5 -4,60,28,13,0,0,"sua");
	NutBam hieuChinh7(margin + 760, marginTop+ khoanCach*6 -4,60,28,13,0,0,"sua");
	NutBam hieuChinh8(margin + 760, marginTop+ khoanCach*7 -4,60,28,13,0,0,"sua");
	NutBam hieuChinh9(margin + 760, marginTop+ khoanCach*8 -4,60,28,13,0,0,"sua");
	NutBam hieuChinh10(margin + 760, marginTop+ khoanCach*9 -4,60,28,13,0,0,"sua");
	NutBam hieuChinh11(margin + 760, marginTop+ khoanCach*10 -4,60,28,13,0,0,"sua");
	
	
	
	
	
	
	
	int xclick = -1; 
	int yclick = -1; 
	while (true) {
		 if (ismouseclick(WM_LBUTTONDOWN)) {  
			getmouseclick(WM_LBUTTONDOWN, xclick, yclick); 
			// kiem tra nguoi dung bam gi => de goi lai ham => hienThiDuLieu
			if (btnTien.isMouseHover(xclick,yclick)) {
				if (indexPage < toiDaPage - 1) {
					indexPage++; // nhay qua page khac ! 
					veTableVT();  
					soLuongVatTuTrenTable = hienThiDuLieuLenTableVT(indexPage,itemTrenMotPage,arrVT,soLuongVT); 
					hienThiChiMuc(430,740,indexPage,toiDaPage); 
										
				}
			}
			else if (btnLui.isMouseHover(xclick,yclick)) { 
				if (indexPage > 0) {
					indexPage--; 
					veTableVT(); 
					soLuongVatTuTrenTable = hienThiDuLieuLenTableVT(indexPage,itemTrenMotPage,arrVT,soLuongVT); 
					hienThiChiMuc(430,740,indexPage,toiDaPage); 
				}
			}
			else if (theoTen.isMouseHover(xclick,yclick)) { 
				theoTen.duocTroVao = true; 
				theoTen.veNut(); 
				theoMaVT.duocTroVao = false; 
				theoMaVT.veNut();
				theoSLT.duocTroVao = false; 
				theoSLT.veNut(); 
				theoDVT.duocTroVao = false; 
				theoDVT.veNut(); 
				dsVatTu.insertionSort(arrVT,soLuongVT,VatTu::soSanhTheoTen); 
				veTableVT(); 
				soLuongVatTuTrenTable = hienThiDuLieuLenTableVT(indexPage,itemTrenMotPage,arrVT,soLuongVT); 
				hienThiChiMuc(430,740,indexPage,toiDaPage); 
				
			}
			else if (theoMaVT.isMouseHover(xclick,yclick)) {
				theoMaVT.duocTroVao = true; 
				theoMaVT.veNut();
				theoTen.duocTroVao = false; 
				theoTen.veNut(); 
				theoSLT.duocTroVao = false; 
				theoSLT.veNut(); 
				theoDVT.duocTroVao = false; 
				theoDVT.veNut();  
				dsVatTu.insertionSort(arrVT,soLuongVT,VatTu::soSanhTheoMaVT); 
				veTableVT(); 
				soLuongVatTuTrenTable = hienThiDuLieuLenTableVT(indexPage,itemTrenMotPage,arrVT,soLuongVT); 
				hienThiChiMuc(430,740,indexPage,toiDaPage); 
			}
			else if (theoSLT.isMouseHover(xclick,yclick)) {
				theoSLT.duocTroVao = true; 
				theoSLT.veNut(); 
				theoTen.duocTroVao = false; 
				theoTen.veNut(); 
				theoMaVT.duocTroVao = false; 
				theoMaVT.veNut();
				theoDVT.duocTroVao = false; 
				theoDVT.veNut(); 
				dsVatTu.insertionSort(arrVT,soLuongVT,VatTu::soSanhTheoSoLuongTon); 
				veTableVT(); 
				soLuongVatTuTrenTable = hienThiDuLieuLenTableVT(indexPage,itemTrenMotPage,arrVT,soLuongVT);
				hienThiChiMuc(430,740,indexPage,toiDaPage); 
			}
			else if (theoDVT.isMouseHover(xclick,yclick)) {
				theoSLT.duocTroVao = false; 
				theoSLT.veNut(); 
				theoTen.duocTroVao = false; 
				theoTen.veNut(); 
				theoMaVT.duocTroVao = false; 
				theoMaVT.veNut();
				theoDVT.duocTroVao = true; 
				theoDVT.veNut(); 
				dsVatTu.insertionSort(arrVT,soLuongVT,VatTu::soSanhTheoDonViTinh); 
				veTableVT(); 
				soLuongVatTuTrenTable = hienThiDuLieuLenTableVT(indexPage,itemTrenMotPage,arrVT,soLuongVT);
				hienThiChiMuc(430,740,indexPage,toiDaPage); 
			}
			else if (nhapMaVT.isMouseHover(xclick,yclick)) {
				nhapMaVT.NhapVao(kiTuChuHoacSo,""); // sau khi nhap roi 
				if (nhapMaVT.boNhoDem != "") {
					tempVT = dsVatTu.timKiemVT(nhapMaVT.boNhoDem); 
					if (tempVT != NULL) {
						MessageBox(NULL, "da ton vat tu nay!", "thong bao", MB_ICONINFORMATION | MB_OK);
						nhapMaVT.resetBoNhoDem(); 
					}
				}
			}
			else if (nhapTenVT.isMouseHover(xclick,yclick)) { 
				nhapTenVT.NhapVao(kiTuChuHoacSo,""); // ten vt co the co chu hoac ca so !  
			}
			else if (nhapSoLuong.isMouseHover(xclick,yclick)) {
				nhapSoLuong.nhapSoThuc("chi nhap so thuc!"); // 
			}
			else if (nhapDVT.isMouseHover(xclick,yclick)) {
				nhapDVT.NhapVao(kiTuChu,"chi nhap chu!"); 
			}
			else if (saveVT.isMouseHover(xclick,yclick)) {
				if (nhapMaVT.boNhoDem == "" || nhapTenVT.boNhoDem == "" || nhapSoLuong.boNhoDem == "" || nhapDVT.boNhoDem == "") {
					MessageBox(NULL, "khong duoc bo trong!", "thong bao", MB_ICONINFORMATION | MB_OK);
				}
				else {
					VatTu temp(nhapMaVT.boNhoDem,nhapTenVT.boNhoDem,nhapDVT.boNhoDem,TienichDoHoa::stringToFloat(nhapSoLuong.boNhoDem));
					dsVatTu.themVT(temp); 
					MessageBox(NULL, "Them thanh cong!", "thong bao", MB_ICONINFORMATION | MB_OK);
					
					index = ID_VT;
					return; 					
				}
			}
			// bac su kien nguoi dung click vao thang nao 
			if (hieuChinh1.isMouseHover(xclick,yclick)) { 
				// lay ra thang VT nay -> roi sau do chinh sua -> co the chinh sua duoc. 
				if (soLuongVatTuTrenTable != 0) {
					chinhSuaVT(dsVatTu,arrVT[itemTrenMotPage * indexPage]);
					 
					index = ID_VT; 
					delete []arrVT; 
					return; 
				}
			}
			else if (hieuChinh2.isMouseHover(xclick,yclick)) { 
				if (soLuongVatTuTrenTable >= 2) {
					chinhSuaVT(dsVatTu,arrVT[1 + itemTrenMotPage * indexPage]); 
						index = ID_VT; 
					delete []arrVT; 
					return;  
				}
			}
			else if (hieuChinh3.isMouseHover(xclick,yclick)) { 
				if (soLuongVatTuTrenTable >= 3) {
					chinhSuaVT(dsVatTu,arrVT[2 + itemTrenMotPage * indexPage]); 
						index = ID_VT; 
					delete []arrVT; 
					return; 
				}
			}
			else if (hieuChinh4.isMouseHover(xclick,yclick)) { 
				if (soLuongVatTuTrenTable >= 4) {
					chinhSuaVT(dsVatTu,arrVT[3 + itemTrenMotPage * indexPage]); 
					index = ID_VT; 
					delete []arrVT; 
					return; 
				}
			}
			else if (hieuChinh5.isMouseHover(xclick,yclick)) { 
				if (soLuongVatTuTrenTable >= 2) {
					chinhSuaVT(dsVatTu,arrVT[4 + itemTrenMotPage * indexPage]); 
					index = ID_VT; 
					delete []arrVT; 
					return; 
				}
			}
			else if (hieuChinh6.isMouseHover(xclick,yclick)) { 
				if (soLuongVatTuTrenTable >= 2) {
					chinhSuaVT(dsVatTu,arrVT[5 + itemTrenMotPage * indexPage]); 
					index = ID_VT; 
					delete []arrVT; 
					return; 
				}
			}
			else if (hieuChinh7.isMouseHover(xclick,yclick)) { 
				if (soLuongVatTuTrenTable >= 2) {
					chinhSuaVT(dsVatTu,arrVT[6 + itemTrenMotPage * indexPage]); 
					index = ID_VT; 
					delete []arrVT; 
					return;  
				}
			}
			else if (hieuChinh8.isMouseHover(xclick,yclick)) { 
				if (soLuongVatTuTrenTable >= 2) {
					chinhSuaVT(dsVatTu,arrVT[7 + itemTrenMotPage * indexPage]); 
					index = ID_VT; 
					delete []arrVT; 
					return; 
				}
			}
			else if (hieuChinh9.isMouseHover(xclick,yclick)) { 
				if (soLuongVatTuTrenTable >= 2) {
					chinhSuaVT(dsVatTu,arrVT[8 + itemTrenMotPage * indexPage]); 
					index = ID_VT; 
					delete []arrVT; 
					return; 
				}
			}
			else if (hieuChinh10.isMouseHover(xclick,yclick)) { 
				if (soLuongVatTuTrenTable >= 2) {
					chinhSuaVT(dsVatTu,arrVT[9 + itemTrenMotPage * indexPage]); 
					index = ID_VT; 
					delete []arrVT; 
					return; 
				}
			}
			else if (hieuChinh11.isMouseHover(xclick,yclick)) { 
				if (soLuongVatTuTrenTable >= 2) {
					chinhSuaVT(dsVatTu,arrVT[10 + itemTrenMotPage * indexPage]); 
					index = ID_VT; 
					delete []arrVT; 
					return; 
				}
			}
			// bac dieu kien nguoi dung nhap ra ngaoi 
			else if (nhanVien.isMouseHover(xclick,yclick)){
				index = ID_NV; 
				delete []arrVT; 
				return; 
			}
			else if (hoaDon.isMouseHover(xclick,yclick)) {
				index = ID_HD; 
				delete []arrVT; 
				return; 
			}
			else if (doanhThu.isMouseHover(xclick,yclick)) {
				index = ID_DT; 
				delete []arrVT; 
				return; 
			}
 				
		}
		 delay(1); 
	}
	
	
	
	
}
