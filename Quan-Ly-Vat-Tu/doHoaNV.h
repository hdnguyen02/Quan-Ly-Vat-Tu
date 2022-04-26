#pragma once
using namespace std; 
#include "Tienich.h"
#include "BienDoHoa.h"
#include "DoHoaHD.h"

// viet ham hien thi table 


// chua sua !


void hienThiChinhSuaNV(dsNhanVien &DSNV, NhanVien* nhanVienCT) {
	OVuong themNV(margin + doDaiCoban*6 - 60,canLeTrenHD + 140 ,margin + doDaiCoban*3 + 30,400,15); 
	NutBam titleHCNV(margin + doDaiCoban*6 - 60,canLeTrenHD + 140,margin + doDaiCoban*3 + 30,40,15,0,0,"HIEU CHINH NHAN VIEN"); 
	titleHCNV.veNut();  
	ONhap nhapMaNV(margin + doDaiCoban*6 ,canLeTrenHD + 170 + 30,doDaiCoban*3 - 100,40,60,"MA: ",0,0,10); 
	ONhap nhapHoNV(margin + doDaiCoban*6 ,canLeTrenHD + 170 + 100,doDaiCoban*3 - 100,40,60,"HO: ",0,0,20);
	ONhap nhapTenNV(margin + doDaiCoban*6 ,canLeTrenHD + 170 + 70 * 2 + 30,doDaiCoban*3 - 100,40,60,"TEN: ",0,0,10);
	
	// tao ra 2 nut bam Nam Nu 
	NutBam nam(margin + doDaiCoban*6 + 60,canLeTrenHD + 170 + 70 * 2 + 30 + 70,60,40,11,13,0,"NAM"); 
	NutBam nu(margin + doDaiCoban*6 + 364,canLeTrenHD + 170 + 70 * 2 + 30 + 70,60,40,11,13,0,"NU"); 
	nam.veNut(); 
	nu.veNut(); 
	nhapMaNV.veONhap(); 
	nhapHoNV.veONhap(); 
	nhapTenNV.veONhap(); 
	
	
	



	NutBam saveNV(margin +doDaiCoban*6 - 60,canLeTrenHD + 170 + 50 + 160 + 120,margin + doDaiCoban*3 + 30,40,0,2,0,"");
	saveNV.veNut(); 
	
	NutBam xoa(margin +doDaiCoban*6 - 60,canLeTrenHD + 170 + 50 + 160 + 120,(margin + doDaiCoban*3 + 30) /2 - 1,40,13,2,0,"xoa");
	xoa.veNut(); 
	
	NutBam hieuChinh(margin +doDaiCoban*6 - 60 + (margin + doDaiCoban*3 + 30) /2 + 1,canLeTrenHD + 170 + 50 + 160 + 120,(margin + doDaiCoban*3 + 30) /2,40,13,2,0,"hieu chinh"); 
	hieuChinh.veNut(); 
	NutBam thoat(margin + doDaiCoban*6 - 60 + (margin + doDaiCoban*3 + 30 - 40 ) ,canLeTrenHD + 140,40,40,4,0,15,"X"); 
	thoat.veNut(); 
	
	int xclick = -1; 
	int yclick = -1; 
	
	string maNVCu = nhanVienCT->maNV; 
	string hoNVCu = nhanVienCT->ho; 
	string tenNVCu = nhanVienCT->ten; 
	int phaiCu = nhanVienCT->phai; 
	
	nhapMaNV.boNhoDem = nhanVienCT->maNV; 
	nhapTenNV.boNhoDem = nhanVienCT->ten; 
	nhapHoNV.boNhoDem = nhanVienCT->ho; 
	
	// khai bao 1 bien phai
	int phai = nhanVienCT->phai; 
	if (phai == 0) {
		nam.duocChon(); 
		nu.khongDuocChon(); 
	}
	else {
		nam.khongDuocChon(); 
		nu.duocChon(); 
	}
	
	// do du lieu len! 
	nhapTenNV.inNoiDung(); 
	nhapHoNV.inNoiDung(); 
	nhapMaNV.inNoiDung(); 
	
	
	while (true) {
		if (ismouseclick(WM_LBUTTONDOWN)) {  
			getmouseclick(WM_LBUTTONDOWN, xclick, yclick); 
			if (nhapMaNV.isMouseHover(xclick,yclick)) {
				nhapMaNV.NhapVao(kiTuChuHoacSo,""); 
				if (nhapMaNV.boNhoDem != "" && nhapMaNV.boNhoDem != maNVCu) {

					if (DSNV.timKiemNVTraVeDiaChi(nhapMaNV.boNhoDem) != NULL) { // da ton tai roi -> nen moi tim thay!
						MessageBox(NULL, "Da Ton Tai Ma Vat Tu Nay!", "thong bao", MB_ICONINFORMATION | MB_OK);
						nhapMaNV.resetBoNhoDem();
					}
				}
				
 			}
 			
				else if (nhapTenNV.isMouseHover(xclick,yclick)) {
					nhapTenNV.NhapVao(kiTuChuHoacSo,""); 
				}
				else if (nhapHoNV.isMouseHover(xclick,yclick)) {
					nhapHoNV.NhapVao(kiTuChu,""); 
				}
				else if (nam.isMouseHover(xclick,yclick)) {
					nam.duocChon();  
					nu.khongDuocChon(); 
				}
				else if (nu.isMouseHover(xclick,yclick)) {
					nam.khongDuocChon(); 
					nu.duocChon(); 
				}
				else if (hieuChinh.isMouseHover(xclick,yclick)) { // nhap vao !
					if (nam.duocTroVao = true) {
						phai = 0; 
					}
					else {
						phai = 1; 
					}
					if (nhapTenNV.boNhoDem == "" || nhapMaNV.boNhoDem == "" || nhapHoNV.boNhoDem == ""  ) {
						MessageBox(NULL, "Khong Duoc Bo Trong!", "thong bao", MB_ICONINFORMATION | MB_OK);
					}
					else if (nhapMaNV.boNhoDem != maNVCu || nhapTenNV.boNhoDem != tenNVCu || nhapHoNV.boNhoDem != hoNVCu || phai != phaiCu) { // phai co thang nao thay doi thi moi chinh sua !
						nhanVienCT->maNV = nhapMaNV.boNhoDem; 
						nhanVienCT->ten = nhapTenNV.boNhoDem; 
						nhanVienCT->ho = nhapHoNV.boNhoDem; 
						nhanVienCT->phai = phai; 
						MessageBox(NULL, "Hieu Chinh Thanh Cong!", "Thong Bao", MB_ICONINFORMATION | MB_OK); 
						DSNV.ghiFileDSNV("data/dataNhanVien.txt"); 
						break; 	
					}
				
				}
 		
 				
				else if (thoat.isMouseHover(xclick,yclick)) {
					break; 
				}
				else if (xoa.isMouseHover(xclick,yclick)) {
					if (nhapMaNV.boNhoDem == maNVCu && nhapTenNV.boNhoDem == tenNVCu && nhapHoNV.boNhoDem == hoNVCu) {
						int luaChon = MessageBox(NULL, "ban co chac chac muon xoa!", "thong bao", MB_ICONWARNING | MB_OKCANCEL);
						if (luaChon == OK) { // xoa di !
							DSNV.xoaNV(nhapMaNV.boNhoDem); 
							MessageBox(NULL, "Xoa nhan vien Thanh Cong!", "Thong Bao", MB_ICONINFORMATION | MB_OK);
							DSNV.ghiFileDSNV("data/dataNhanVien.txt");  
							break;  
						}
					}
					
				}
				
			
			
			
		}
		delay(1); 
	}
	
}







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
			 outtextxy(margin + 30,marginTop + khoanCach*i,arrNV[index]->maNV.c_str());  // hien thi ra maVT 
			 outtextxy(margin + 186,marginTop + khoanCach*i,arrNV[index]->getHoTen().c_str());  // hien thi ra maVT
			 // kiem tra xem la 0 hay 1 
			 if (arrNV[index]->phai == 0) {
			 	temp = "Nam";
			 }
			 else {
			 	temp = "Nu"; 
			 }
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
void hienThiTinhNangNhanVien(dsNhanVien &DSNV,int &index,NutBam &vatTu,NutBam &hoaDon,NutBam &doanhThu,bool(*khoaSapXep)(NhanVien*,NhanVien*)) {
	
	
	
	// khai bao bien quan trong 
	int indexPage = 0; 
	int soLuongPhanTuHienThi = 0; 
	int itemTrenMotPage = 11; 
	int toaDoChiMucX = DODAIMANHINH/2 -110; 
	NhanVien *tempNV; 
	int soLuongNV = DSNV.soLuongNV(); 
	
	int soLuongNhanVienTrenTable = 0;

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
	NutBam nam(margin + doDaiCoban*6 + 60,canLeTrenHD + 170 + 70 * 2 + 30 + 70,60,40,11,13,0,"NAM"); 
	nam.duocTroVao = true;
	nam.veNut(); 
	
	NutBam nu(margin + doDaiCoban*6 + 364,canLeTrenHD + 170 + 70 * 2 + 30 + 70,60,40,11,13,0,"NU"); 
	nu.veNut(); 
	nhapMaNV.veONhap(); 
	nhapHoNV.veONhap(); 
	nhapTenNV.veONhap(); 
	
	// ve ra o Vuong ngan cach nam nu 
//	line(margin + doDaiCoban*6 + 200 + 36,canLeTrenHD + 170 + 70 * 2 + 30 + 60,margin + doDaiCoban*6 + 200 + 36,canLeTrenHD + 170 + 70 * 2 + 30 + 120);

	NutBam saveNV(margin +doDaiCoban*6 - 60,canLeTrenHD + 170 + 50 + 160 + 120,margin + doDaiCoban*3 + 30,40,14,2,0,"SAVE");
	saveNV.veNut(); 
	
	DSNV.insertionSort(NhanVien::soSanhTheoTen); 
	
	veTableNV();
	
	soLuongNhanVienTrenTable = hienThiDuLieuLenTableNV(indexPage,itemTrenMotPage,DSNV); 
	hienThiChiMuc(430,740,indexPage,toiDaPage);
	
	// ve ra sap xep theo 
	setcolor(CinputText); 
	setbkcolor(0); 
	settextstyle(6, 0, 1);
	outtextxy(59,106,"Sap xep theo: "); 
	
	NutBam theoTen(62 + 160,96,100,40,11,13,0,"ho ten");
	NutBam theoMaNV(62 + 160 + 120,96,100,40,11,13,0,"ma");
	theoTen.duocChon(); 
	theoMaNV.veNut(); 
	
	
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
	
	
	NutBam btnLui(margin,730,100,40,15,0,0,"<<");
	NutBam btnTien(margin + 730,730,100,40,15,0,0,">>");
	btnLui.veNut(); 	
	btnTien.veNut(); 
	// bat su kien nhap vao nv 
	int xclick = -1; 
	int yclick = -1; 
	while(true) {
		 if (ismouseclick(WM_LBUTTONDOWN)) {  
		 getmouseclick(WM_LBUTTONDOWN, xclick, yclick);
		 if (nhapMaNV.isMouseHover(xclick,yclick)) {  // hien thi 
			 nhapMaNV.NhapVao(kiTuChuHoacSo,""); 
			 // sau khi nhap song kiem tra xem co trung hay khong 
			 tempNV = DSNV.timKiemNVTraVeDiaChi(nhapMaNV.boNhoDem); 
			 if (tempNV != NULL) {
			 	MessageBox(NULL, "da ton ma nhan vien nay", "thong bao", MB_ICONINFORMATION | MB_OK);
				nhapMaNV.resetBoNhoDem(); 
			 }
			 
 		} 
 		else if ( nhapHoNV.isMouseHover(xclick,yclick) ) {
			 	nhapHoNV.NhapVao(kiTuChu,"chi nhap chu!"); 
			 }
			 else if (nhapTenNV.isMouseHover(xclick,yclick)) {
			 	nhapTenNV.NhapVao(kiTuChu,"chu nhap chu!"); 
			 }
			 else if (nam.isMouseHover(xclick,yclick)) {
			 	// phat sang no len ! 
			 	nam.duocTroVao = true; 
			 	nam.veNut(); 
			 	nu.duocTroVao = false; 
			 	nu.veNut(); 
			 }
			 else if (nu.isMouseHover(xclick,yclick)) {
				nam.duocTroVao = false; 
			 	nam.veNut(); 
			 	nu.duocTroVao = true; 
			 	nu.veNut(); 
			 }
			 else if (saveNV.isMouseHover(xclick,yclick)) {
			 	if (nhapMaNV.boNhoDem == "" || nhapHoNV.boNhoDem == "" || nhapTenNV.boNhoDem == "") {
				 	MessageBox(NULL, "khong duoc bo trong!", "thong bao", MB_ICONINFORMATION | MB_OK);
				 }
				 else {
				 	
				 	int phai; 
				 	if (nam.duocTroVao == true) {
					 	phai = 0; 
					}
					else {
						phai = 1;
					}
					DSNV.themNV(nhapMaNV.boNhoDem,nhapHoNV.boNhoDem,nhapTenNV.boNhoDem,phai); 
					DSNV.ghiFileDSNV("data/dataNhanVien.txt"); 
					MessageBox(NULL, "Them thanh cong!", "thong bao", MB_ICONINFORMATION | MB_OK);
				 	index = ID_NV; 
				 	return; 
				 }
			 }
			else if (btnTien.isMouseHover(xclick,yclick)) {
				if (indexPage < toiDaPage - 1) {
					indexPage++; // nhay qua page khac ! 
					veTableNV();
	
					soLuongNhanVienTrenTable = hienThiDuLieuLenTableNV(indexPage,itemTrenMotPage,DSNV); 
					hienThiChiMuc(430,740,indexPage,toiDaPage); 
										
				}
			}
			else if (btnLui.isMouseHover(xclick,yclick)) { 
				if (indexPage > 0) {
					indexPage--; 
					veTableNV();
	
					soLuongNhanVienTrenTable = hienThiDuLieuLenTableNV(indexPage,itemTrenMotPage,DSNV);  
					hienThiChiMuc(430,740,indexPage,toiDaPage); 
				}
			}
			else if (theoTen.isMouseHover(xclick,yclick)) {
				// ve lai bang thoi ! 
				theoTen.duocChon(); 
				theoMaNV.khongDuocChon(); 
				DSNV.insertionSort(NhanVien::soSanhTheoTen); 
				veTableNV();
				soLuongNhanVienTrenTable = hienThiDuLieuLenTableNV(indexPage,itemTrenMotPage,DSNV);
				hienThiChiMuc(430,740,indexPage,toiDaPage);   
			}
			else if (theoMaNV.isMouseHover(xclick,yclick)) {
				theoMaNV.duocChon(); 
				theoTen.khongDuocChon(); 
				DSNV.insertionSort(NhanVien::soSanhTheoMaNV); 
				veTableNV();
				soLuongNhanVienTrenTable = hienThiDuLieuLenTableNV(indexPage,itemTrenMotPage,DSNV);  
				hienThiChiMuc(430,740,indexPage,toiDaPage); 
			}
			else if (hieuChinh1.isMouseHover(xclick,yclick)){
				if (soLuongNhanVienTrenTable != 0) {
					hienThiChinhSuaNV(DSNV,DSNV.getNhanVien(itemTrenMotPage * indexPage)); 
					index = ID_NV; 
					return; 
				}
			}
			else if (hieuChinh2.isMouseHover(xclick,yclick)) { 
				if (soLuongNhanVienTrenTable >= 2) {
					hienThiChinhSuaNV(DSNV,DSNV.getNhanVien(1 + itemTrenMotPage * indexPage));
					index = ID_NV; 
					return;  
				}
			}
			else if (hieuChinh3.isMouseHover(xclick,yclick)) { 
				if (soLuongNhanVienTrenTable >= 3) {
					hienThiChinhSuaNV(DSNV,DSNV.getNhanVien(2 + itemTrenMotPage * indexPage));
					index = ID_NV; 
					return;  
				}
			}
			else if (hieuChinh4.isMouseHover(xclick,yclick)) { 
				if (soLuongNhanVienTrenTable >= 4) {
					hienThiChinhSuaNV(DSNV,DSNV.getNhanVien(3 + itemTrenMotPage * indexPage));
					index = ID_NV; 
					return; 
				}
			}
			else if (hieuChinh5.isMouseHover(xclick,yclick)) { 
				if (soLuongNhanVienTrenTable >= 5) {
					hienThiChinhSuaNV(DSNV,DSNV.getNhanVien(4 + itemTrenMotPage * indexPage));
					index = ID_NV; 
					return; 
				}
			}
			else if (hieuChinh6.isMouseHover(xclick,yclick)) { 
				if (soLuongNhanVienTrenTable >= 6) {
					hienThiChinhSuaNV(DSNV,DSNV.getNhanVien(5 + itemTrenMotPage * indexPage));
					index = ID_NV; 
					return;  
				}
			}
			else if (hieuChinh7.isMouseHover(xclick,yclick)) { 
				if (soLuongNhanVienTrenTable >= 7) {
					hienThiChinhSuaNV(DSNV,DSNV.getNhanVien(6 + itemTrenMotPage * indexPage));
					index = ID_NV; 
					return;   
				}
			}
			else if (hieuChinh8.isMouseHover(xclick,yclick)) { 
				if (soLuongNhanVienTrenTable >= 8) {
					hienThiChinhSuaNV(DSNV,DSNV.getNhanVien(7 + itemTrenMotPage * indexPage));
					index = ID_NV; 
					return;
				}
			}
			else if (hieuChinh9.isMouseHover(xclick,yclick)) { 
				if (soLuongNhanVienTrenTable >= 9 ) {
					hienThiChinhSuaNV(DSNV,DSNV.getNhanVien(8 + itemTrenMotPage * indexPage));
					index = ID_NV; 
					return;
				}
			}
			else if (hieuChinh10.isMouseHover(xclick,yclick)) { 
				if (soLuongNhanVienTrenTable >= 10) {
					hienThiChinhSuaNV(DSNV,DSNV.getNhanVien(9 + itemTrenMotPage * indexPage));
					index = ID_NV; 
					return;
				}
			}
			else if (hieuChinh11.isMouseHover(xclick,yclick)) { 
				if (soLuongNhanVienTrenTable >= 11) {
					hienThiChinhSuaNV(DSNV,DSNV.getNhanVien(9 + itemTrenMotPage * indexPage));
					index = ID_NV; 
					return; 
				}
			}
			else if (vatTu.isMouseHover(xclick,yclick)) {
				index = ID_VT; 
				return; 
			}
			else if (hoaDon.isMouseHover(xclick,yclick)) {
				index = ID_HD; 
				return; 
			}
			else if (doanhThu.isMouseHover(xclick,yclick)) {
				index = ID_DT; 
				return; 
			}
			
 		}
	delay(1); 
	}
	
	
	
}

