#pragma once
using namespace std; 
#include "Tienich.h"
#include "BienDoHoa.h"




// ======================================HIEU CHINH VAT TU===============================================


// ====================================HIEN THI INPUT VATTU==============================================
void themVatTu(BstVatTu &dsVatTu,int &index,NutBam &nhanVien,NutBam &hoaDon,NutBam &doanhThu,NutBam& inDSVT) {
	TienichDoHoa::xoaManHinhTheoToaDo(0,46 + 50,DODAIMANHINH,1000,BACKGROUP); 
	NodeVatTu* tempVT; // kiem tra vt da ton tai hay chua !
	const int chieuDaiBox = 700;
	const int mxTieuDe = (DODAIMANHINH / 2 ) - (chieuDaiBox/2);
	const int cachLeTrenTieuDe = 200;
	const int chieuCaoTieuDe = 40; 
	NutBam tieuDe(mxTieuDe,cachLeTrenTieuDe,chieuDaiBox,chieuCaoTieuDe,14,9,0,"NHAP THONG TIN VAT TU");
	
	// ==========BIEN O VUONG===========
	const int chieuCaoBox = 350; 
	const int cachLeTrenBox = cachLeTrenTieuDe + chieuCaoTieuDe + 5; 
	NutBam box(mxTieuDe,cachLeTrenBox,chieuDaiBox,chieuCaoBox,13,3,4,""); // ve ra 1 cai hop trong
	  
	
	// ============BIEN O NHAP===========
	const int chieuDaiTieuDe = 150; 
	const int chieuDaiInput =  chieuDaiBox - chieuDaiTieuDe - 42; 
	const int cachLeInput = mxTieuDe + 20; 
	const int cachLeTrenInput = cachLeTrenBox + 10; 
	const int chieuCaoInput = 40; 
	const int slktMaVT = 10; 
	ONhap nhapMaVT(cachLeInput,cachLeTrenInput,chieuDaiInput,chieuCaoInput,chieuDaiTieuDe,"ma",2,13,10);
	ONhap nhapTenVT(cachLeInput,cachLeTrenInput  + chieuCaoInput+ 32,chieuDaiInput,chieuCaoInput,chieuDaiTieuDe,"ten",2,13,40);
	ONhap nhapDVT(cachLeInput,cachLeTrenInput  + (chieuCaoInput+ 32)*2,chieuDaiInput,chieuCaoInput,chieuDaiTieuDe,"don vi tinh",2,13,10); 
	ONhap nhapSLTon(cachLeInput,cachLeTrenInput  + (chieuCaoInput+ 32)*3,chieuDaiInput,chieuCaoInput,chieuDaiTieuDe,"so luong ton",2,13,10); 
	const int chieuDaiNutBam = 100; 
	NutBam lamMoi(cachLeInput,cachLeTrenInput+(chieuCaoInput+ 32)*4,chieuDaiNutBam,chieuCaoInput,14,4,1,"lam moi");
	NutBam luu(cachLeInput + 357 + 200,cachLeTrenInput+(chieuCaoInput+ 32)*4,chieuDaiNutBam,chieuCaoInput,14,4,1,"luu");
	
	

	
	tieuDe.veNut(); 
	box.veNut();
	nhapMaVT.veONhap(); 
	nhapTenVT.veONhap(); 
	nhapDVT.veONhap();
	nhapSLTon.veONhap(); 
	lamMoi.veNut(); 
	luu.veNut(); 
	while(true) {
		if (ismouseclick(WM_LBUTTONDOWN)) {  
			int mx = -1;
			int my = -1; 
			getmouseclick(WM_LBUTTONDOWN, mx, my);
			if (hoaDon.isMouseHover(mx,my)) {
				index = ID_HD; 
				return; 
			}
			else if (nhanVien.isMouseHover(mx,my)) {
				index = ID_NV; 
				return; 
			}
			else if (doanhThu.isMouseHover(mx,my)) {
				index = ID_DT; 
				return; 
			}
			else if (inDSVT.isMouseHover(mx,my)) {
			 	index = ID_IN_VT; 
			 	return; 
			}
			else {
				if (nhapMaVT.isMouseHover(mx,my)) {
					TienichDoHoa::xoaManHinhTheoToaDo(mxTieuDe + 40,650,1000,36,BACKGROUP);
					nhapMaVT.NhapVao(kiTuChuHoacSo,""); 
					
				}
				else if (nhapTenVT.isMouseHover(mx,my)) {
					TienichDoHoa::xoaManHinhTheoToaDo(mxTieuDe + 40,650,1000,36,BACKGROUP);
					nhapTenVT.NhapVao(kiTuChuHoacSo,""); 
				}
				else if (nhapSLTon.isMouseHover(mx,my)) {
					TienichDoHoa::xoaManHinhTheoToaDo(mxTieuDe + 40,650,1000,36,BACKGROUP);
					nhapSLTon.nhapSoThuc("chi nhan so thuc!"); 
				}
				else if (nhapDVT.isMouseHover(mx,my)) {
					TienichDoHoa::xoaManHinhTheoToaDo(mxTieuDe + 40,650,1000,36,BACKGROUP);
					nhapDVT.NhapVao(kiTuChu,"chi nhap chu"); 
				}
				else if (luu.isMouseHover(mx,my)) {
					string maVT = nhapMaVT.boNhoDem; 
					string tenVT = nhapTenVT.boNhoDem; 
					float tempSLT = TienichDoHoa::stringToFloat(nhapSLTon.boNhoDem);  
					string  DVT = nhapDVT.boNhoDem; 
					if (maVT == "" || tenVT == "" || nhapSLTon.boNhoDem == "" || DVT == "" ) {
						MessageBox(NULL, "khong duoc bo trong!", "thong bao", MB_ICONEXCLAMATION | MB_OK);
					}
					
					else {
						tempVT = dsVatTu.timKiemVT(nhapMaVT.boNhoDem); 
						if (tempVT == NULL) {
							VatTu tempVT(maVT,tenVT,DVT,tempSLT);
							dsVatTu.themVT(tempVT); 
							nhapMaVT.resetBoNhoDem(); 
							nhapTenVT.resetBoNhoDem(); 
							nhapDVT.resetBoNhoDem(); 
							nhapSLTon.resetBoNhoDem();  
							TienichDoHoa::xoaManHinhTheoToaDo(mxTieuDe + 40,650,1000,36,BACKGROUP);
							MessageBox(NULL, "them thanh cong", "thong bao", MB_ICONINFORMATION | MB_OK);
						}
						else {
							MessageBox(NULL, "them khong thanh cong!, da ton tai vat tu nay!", "thong bao", MB_ICONINFORMATION | MB_OK);
							nhapMaVT.resetBoNhoDem(); 
						}
					}
	
				}
				else if (lamMoi.isMouseHover(mx,my)) {
					nhapMaVT.resetBoNhoDem(); 
					nhapTenVT.resetBoNhoDem(); 
					nhapDVT.resetBoNhoDem(); 
					nhapSLTon.resetBoNhoDem(); 
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

// ===============================HIEN THI DANH SACH VAT TU==========================================
//void inDanhSachVatTu(BstVatTu& dsVatTu,int &index,NutBam &nhanVien,NutBam &hoaDon,NutBam &doanhThu,NutBam& themVT) { 
//	index = -1; 
//	int soLuongNode = dsVatTu.soLuongVT();  
//	NodeVatTu** arrVT = new NodeVatTu*[soLuongNode]; 
//	dsVatTu.sapXepTangDanTheoTen(arrVT);   
//	TienichDoHoa::xoaManHinhTheoToaDo(0,46 + 50,DODAIMANHINH,1000,BACKGROUP); 
//	
//
//	const int daiBox = 1200; 
//	const int caoBox = 600; 
//	int toaDoXBox = DODAIMANHINH/2 - daiBox/2; 
//	int doDaiCoBan = daiBox/5; 
//	const int widthTieuDeMaVT = doDaiCoBan; 
//	const int widthHoTenVT = doDaiCoBan*2; 
//	const int widthDVT = doDaiCoBan; 
//	const int widthSLT = doDaiCoBan;
//
//	 
//	NutBam tieuDeMaVT(toaDoXBox,110,widthTieuDeMaVT,40,6,7,10,"ma vt"); 
//	NutBam tieuDeTenVT(toaDoXBox + widthTieuDeMaVT + 2,110,widthHoTenVT,40,6,7,10,"ten vt"); 
//	NutBam tieuDeDVT(toaDoXBox+doDaiCoBan*3 + 4,110,widthDVT,40,6,7,10,"don vi tinh"); 
//	NutBam tieuDeSLT(toaDoXBox + doDaiCoBan*4 +6,110,widthSLT -6 + 2,40,6,7,10,"so luong ton"); 
//	NutBam luiLai(toaDoXBox                 ,caoBox + 120,80,40,7,6,2,"<<"); 
//	NutBam tienLen(toaDoXBox + daiBox -80   ,caoBox + 120,80,40,7,6,2,">>"); 
//	setcolor(colorLight); 
//	line(toaDoXBox + widthTieuDeMaVT ,110,toaDoXBox + widthTieuDeMaVT ,caoBox +110); 
//	line(toaDoXBox+doDaiCoBan*3 + 2 ,110,toaDoXBox+doDaiCoBan*3 + 2 ,caoBox +110);
//	line(toaDoXBox + doDaiCoBan*4 +4,110,toaDoXBox + doDaiCoBan*4 +4 ,caoBox +110);	
//	OVuong ovVatTu(toaDoXBox,110,daiBox,caoBox,colorLight); 
//	ovVatTu.veOVuong(); 
//	tieuDeMaVT.veNut();
//	tieuDeTenVT.veNut();
//	tieuDeDVT.veNut();
//	tieuDeSLT.veNut();
//	tienLen.veNut(); 
//	luiLai.veNut();
//	
//	// ===================== BAC SU KIEN =====================
//	int indexTrang = 0; // trang dau tien la so 0
//	int soLuongItemPage = 2;  // hien tai la 2 phan tu tren 1 trang 
//	int toiDaIndex = soLuongNode / soLuongItemPage; 
//	inDanhSachLenDoHoa(arrVT,indexTrang,soLuongItemPage,soLuongNode); 
//	string temp; 
//	string stringToiDaIndex = TienichDoHoa::intToString(toiDaIndex); 
//	indexTrang++; 
//	temp = TienichDoHoa::intToString(indexTrang) + "/" + stringToiDaIndex; 
//	outtextxy(DODAIMANHINH/2,caoBox + 120,(char*)(temp.c_str())); 
//	indexTrang--; 
//	while(true) {
//		if (ismouseclick(WM_LBUTTONDOWN)) { 
//			int mx = -1;
//			int my = -1; 
//			getmouseclick(WM_LBUTTONDOWN, mx, my);
//			
//			if (hoaDon.isMouseHover(mx,my)) {
//				index = ID_HD; 
//				return;
//			}
//			else if (nhanVien.isMouseHover(mx,my)) {
//				index = ID_NV; 
//				return; 
//			}
//			else if (doanhThu.isMouseHover(mx,my)) {
//				index = ID_DT; 
//				return; 
//			}
//			else if (themVT.isMouseHover(mx,my)) {
//				index = ID_THEM_VT; 
//				return; 
//			}
//	
//			else if (tienLen.isMouseHover(mx,my)) {
//				if (indexTrang < toiDaIndex-1) {
//					indexTrang++;  
//					inDanhSachLenDoHoa(arrVT,indexTrang,soLuongItemPage,soLuongNode); 
//					indexTrang++; 
//					temp = TienichDoHoa::intToString(indexTrang) + "/" + stringToiDaIndex; 
//					outtextxy(DODAIMANHINH/2,caoBox + 120,(char*)(temp.c_str())); 
//					indexTrang--; 
//				}
//			}
//			else if (luiLai.isMouseHover(mx,my)) {
//				if (indexTrang > 0) {
//					indexTrang--; 
//					inDanhSachLenDoHoa(arrVT,indexTrang,soLuongItemPage,soLuongNode); 
//					indexTrang++; 
//					temp = TienichDoHoa::intToString(indexTrang) + "/" + stringToiDaIndex;  
//					outtextxy(DODAIMANHINH/2,caoBox + 120,(char*)(temp.c_str())); 
//					indexTrang--; 
//				} 	
//			}
//		}
//		delay(1); 
//	}	
//	delete [] arrVT; 
//}			


// truoc tien dieu chinh themVT 

// viet ham va ra table vatTu => table nay cao cao 1 ti 

void veTableVatTu() {
	
}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                                        //
//	                                      HIEN THI TINH NANG VAT TU MOI                                                   //                
//                                                                                                                        //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void hienThiTinhNangVatTu(BstVatTu &dsVatTu,int &index,NutBam &nhanVien,NutBam &hoaDon,NutBam &doanhThu) {
	// xoa di man hinh phia duoi va ve lai toan bo
	index = -1;  
	TienichDoHoa::xoaManHinhTheoToaDo(0,62,DODAIMANHINH,DORONGMANHINH,BACKGROUP);  // xoa di nua man hinh ben duoi. 
	bool kiemTra[3] = {false};
	bool kiemTraVT[3] = {false};  
	const int chieuDaiVT = 230; 
	const int chieuCaoVT = 35;
	const int cachLeNgang = 56; 
	const int cachLeTren = 62 ;
	NutBam themVT(cachLeNgang  ,cachLeTren,chieuDaiVT,chieuCaoVT,COLOR_BTN_SUB,COLOR_HIGHT_BTN_SUB,COLOR_TEXT_BTN_SUB,"THEM VAT TU");
	NutBam inDSVT(chieuDaiVT + cachLeNgang + 2 ,cachLeTren,chieuDaiVT,chieuCaoVT,COLOR_BTN_SUB,COLOR_HIGHT_BTN_SUB,COLOR_TEXT_BTN_SUB,"IN DANH SACH VAT TU"); 
	themVT.veNut(); 

	inDSVT.veNut(); 

	int mx = -1; 
	int my = -1; 
	while (true) {
		if (index != -1) {
			if (index >= 0 && index <= 3) {  // thuoc vung menu to. 
				return;
			}
			else {
				if (index == ID_HIEUCHINH_VT) {

				}
				else if (index == ID_IN_VT) {
//					inDanhSachVatTu(dsVatTu,index,nhanVien,hoaDon,doanhThu,themVT);
					
				}
			}
		}
		if (ismouseclick(WM_MOUSEMOVE)) {
			getmouseclick(WM_MOUSEMOVE, mx, my);  
			nhanVien.kiemTraVeLai(mx,my,kiemTra[0]); 
			hoaDon.kiemTraVeLai(mx,my,kiemTra[1]);
			doanhThu.kiemTraVeLai(mx,my,kiemTra[2]);
			themVT.kiemTraVeLai(mx,my,kiemTraVT[0]); 
			inDSVT.kiemTraVeLai(mx,my,kiemTraVT[2]); 
			
		}
		else if (ismouseclick(WM_LBUTTONDOWN)) {  
			int xclick = -1;
			int yclick = -1; 
			getmouseclick(WM_LBUTTONDOWN, xclick, yclick); 
			if (nhanVien.isMouseHover(xclick,yclick)) {
				index = 1; 
				return; 
			}
			else if (hoaDon.isMouseHover(xclick,yclick)) {
					index = 2;   
					return; 
			}
			else if (doanhThu.isMouseHover(xclick,yclick)) {
					index = 3;   
					return; 
			}
			else if (themVT.isMouseHover(xclick,yclick)) { 
				themVT.duocTroVao = true; 
				themVT.veNut();
				themVatTu(dsVatTu,index,nhanVien,hoaDon,doanhThu,inDSVT); 
			}
			
			else if (inDSVT.isMouseHover(xclick,yclick)) {  // HIEN THI RA TINH NANG IN DANH SACH. 
//				inDanhSachVatTu(dsVatTu,index,nhanVien,hoaDon,doanhThu,themVT); 
			}
		}
	delay(1);
}
}
