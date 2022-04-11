#pragma once
using namespace std; 
#include "Tienich.h"
#include "BienDoHoa.h"




// ======================================HIEU CHINH VAT TU===============================================
void hienThiHieuChinhVatTu(BstVatTu &dsVatTu,int &index,NutBam &nhanVien,NutBam &hoaDon,NutBam &doanhThu,NutBam& themVT,NutBam& inDSVT) {
	TienichDoHoa::xoaManHinhTheoToaDo(0,46 + 50,DODAIMANHINH,1000,BACKGROUP); 
	const int chieuDaiBox = 700;
	const int mxTieuDe = (DODAIMANHINH / 2 ) - (chieuDaiBox/2);
	const int cachLeTrenTieuDe = 200;
	const int chieuCaoTieuDe = 40; 
	NutBam tieuDe(mxTieuDe,cachLeTrenTieuDe,chieuDaiBox,chieuCaoTieuDe,8,9,10,"HIEU CHINH VAT TU");
	
	// ==========BIEN O VUONG===========
	const int chieuCaoBox = 250; 
	const int cachLeTrenBox = cachLeTrenTieuDe + chieuCaoTieuDe + 5; 
	NutBam box(mxTieuDe,cachLeTrenBox,chieuDaiBox,chieuCaoBox,15,3,4,""); // ve ra 1 cai hop trong
	
	
	// ============BIEN O NHAP===========
	const int chieuDaiTieuDe = 60; 
	const int chieuDaiInput =  chieuDaiBox - chieuDaiTieuDe - 500; 
	const int cachLeInput = mxTieuDe + 250; 
	const int cachLeTrenInput = cachLeTrenBox + 100; 
	const int chieuCaoInput = 40; 
	const int slktMaVT = 10; 
	ONhap nhapMaVT(cachLeInput,cachLeTrenInput,chieuDaiInput,chieuCaoInput,chieuDaiTieuDe,"ma",10);
	NutBam timKiem(mxTieuDe,cachLeTrenBox + 256,chieuDaiBox,40,8,9,10,"tim kiem"); 
	tieuDe.veNut(); 
	box.veNut();
	nhapMaVT.veONhap(); 
	timKiem.veNut();
	int mx = -1;
	int my = -1; 
	while(true) {
		if (ismouseclick(WM_LBUTTONDOWN)) {  
			
			getmouseclick(WM_LBUTTONDOWN, mx, my);
			if (nhapMaVT.isMouseHover(mx,my)) {
				TienichDoHoa::xoaManHinhTheoToaDo(mxTieuDe + 190,cachLeTrenBox + 310,1000,40,BACKGROUP); 
				nhapMaVT.NhapVao(kiTuChuHoacSo,""); 
			}
			else if (timKiem.isMouseHover(mx,my)) {
				string maVT = nhapMaVT.boNhoDem; // lay ra bo nho dem. 
				NodeVatTu* pTempVT = dsVatTu.timKiemVT(maVT);   // tra ve NULL neu khong tim thay.
				if (pTempVT != NULL) {
					TienichDoHoa::xoaManHinhTheoToaDo(0,46 + 50,DODAIMANHINH,1000,BACKGROUP);  // xoa het ( ve lai ) 
					box.veNut(); // ve lai o Vuong
					// hien thi ra 2 cai de co the chinh xua 
					tieuDe.veNut(); 
					ONhap dieuChinhTenVT(cachLeInput - 200,cachLeTrenInput - 80,chieuDaiInput + 400,chieuCaoInput,chieuDaiTieuDe,"ten",50);
					ONhap dieuChinhDVT(cachLeInput - 200,cachLeTrenInput - 20,chieuDaiInput + 400,chieuCaoInput,chieuDaiTieuDe,"dvt",50);
					
					dieuChinhTenVT.boNhoDem = pTempVT->getInfo().ten; 
					dieuChinhDVT.boNhoDem = pTempVT->getInfo().donVi; 
					dieuChinhTenVT.veONhap();		
					dieuChinhTenVT.inNoiDung(); 	
					dieuChinhDVT.veONhap(); 
					dieuChinhDVT.inNoiDung(); 
					
					
					while(true) {
						
						delay(1); 
					}
					
				}
				else {
					setbkcolor(BACKGROUP); 
					setcolor(12); 
					outtextxy(mxTieuDe + 190,cachLeTrenBox + 310,"khong tim thay vat tu nay!"); 
				}
			}
			
		}
			
		delay(1); 
	}
	

	
	
}

// ====================================HIEN THI INPUT VATTU==============================================
void hienThiInputVatTu(BstVatTu &dsVatTu,int &index,NutBam &nhanVien,NutBam &hoaDon,NutBam &doanhThu,NutBam& hieuChinhVT,NutBam& inDSVT) {
	TienichDoHoa::xoaManHinhTheoToaDo(0,46 + 50,DODAIMANHINH,1000,BACKGROUP); 
	const int chieuDaiBox = 700;
	const int mxTieuDe = (DODAIMANHINH / 2 ) - (chieuDaiBox/2);
	const int cachLeTrenTieuDe = 200;
	const int chieuCaoTieuDe = 40; 
	NutBam tieuDe(mxTieuDe,cachLeTrenTieuDe,chieuDaiBox,chieuCaoTieuDe,14,9,4,"NHAP THONG TIN VAT TU");
	
	// ==========BIEN O VUONG===========
	const int chieuCaoBox = 350; 
	const int cachLeTrenBox = cachLeTrenTieuDe + chieuCaoTieuDe + 5; 
	NutBam box(mxTieuDe,cachLeTrenBox,chieuDaiBox,chieuCaoBox,15,3,4,""); // ve ra 1 cai hop trong
	  
	
	// ============BIEN O NHAP===========
	const int chieuDaiTieuDe = 150; 
	const int chieuDaiInput =  chieuDaiBox - chieuDaiTieuDe - 42; 
	const int cachLeInput = mxTieuDe + 20; 
	const int cachLeTrenInput = cachLeTrenBox + 10; 
	const int chieuCaoInput = 40; 
	const int slktMaVT = 10; 
	ONhap nhapMaVT(cachLeInput,cachLeTrenInput,chieuDaiInput,chieuCaoInput,chieuDaiTieuDe,"ma",10);
	ONhap nhapTenVT(cachLeInput,cachLeTrenInput  + chieuCaoInput+ 32,chieuDaiInput,chieuCaoInput,chieuDaiTieuDe,"ten",10);
	ONhap nhapDVT(cachLeInput,cachLeTrenInput  + (chieuCaoInput+ 32)*2,chieuDaiInput,chieuCaoInput,chieuDaiTieuDe,"don vi tinh",10); 
	ONhap nhapSLTon(cachLeInput,cachLeTrenInput  + (chieuCaoInput+ 32)*3,chieuDaiInput,chieuCaoInput,chieuDaiTieuDe,"so luong ton",10); 
	const int chieuDaiNutBam = 100; 
	NutBam lamMoi(cachLeInput,cachLeTrenInput+(chieuCaoInput+ 32)*4,chieuDaiNutBam,chieuCaoInput,3,4,8,"lam moi");
	NutBam luu(cachLeInput + 357 + 200,cachLeTrenInput+(chieuCaoInput+ 32)*4,chieuDaiNutBam,chieuCaoInput,3,4,8,"luu");
	
	
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
			else if (hieuChinhVT.isMouseHover(mx,my)) {
				index = ID_HIEUCHINH_VT; 
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
					nhapSLTon.NhapVao(kiTuSo,"chi nhap so"); 
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
						VatTu tempVT(maVT,tenVT,DVT,tempSLT);
						dsVatTu.themVT(tempVT); 
						nhapMaVT.resetBoNhoDem(); 
						nhapTenVT.resetBoNhoDem(); 
						nhapDVT.resetBoNhoDem(); 
						nhapSLTon.resetBoNhoDem();  
						TienichDoHoa::xoaManHinhTheoToaDo(mxTieuDe + 40,650,1000,36,BACKGROUP);
						MessageBox(NULL, "them thanh cong", "thong bao", MB_ICONINFORMATION | MB_OK);
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

// in ra len bang 
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
		tempDVT = TienichDoHoa::floatToString(arrVT[i + indexPage*soLuongItemPage]->getInfo().soLuongTon); 
		outtextxy(canLeX,           canLeY + cachNhau*i,(char*)(arrVT[i + indexPage*soLuongItemPage]->getInfo().maVT.c_str()));
		outtextxy(canLeX + donViO*1,canLeY + cachNhau*i,(char*)(arrVT[i + indexPage*soLuongItemPage]->getInfo().ten.c_str()));
		outtextxy(canLeX + donViO*3,canLeY + cachNhau*i,(char*)(arrVT[i + indexPage*soLuongItemPage]->getInfo().donVi.c_str()));
		outtextxy(canLeX + donViO*4,canLeY + cachNhau*i,(char*)(tempDVT.c_str()));
		}	
	}	
}

// ===============================HIEN THI DANH SACH VAT TU==========================================
void inDanhSachVatTu(BstVatTu& dsVatTu,int &index,NutBam &nhanVien,NutBam &hoaDon,NutBam &doanhThu,NutBam& themVT,NutBam& chinhSuaVT) { 
	index = -1; 
	int soLuongNode = dsVatTu.soLuongVT();  
	NodeVatTu** arrVT = new NodeVatTu*[soLuongNode]; 
	dsVatTu.sapXepTangDanTheoTen(arrVT);   
	TienichDoHoa::xoaManHinhTheoToaDo(0,46 + 50,DODAIMANHINH,1000,BACKGROUP); 
	

	const int daiBox = 1200; 
	const int caoBox = 600; 
	int toaDoXBox = DODAIMANHINH/2 - daiBox/2; 
	int doDaiCoBan = daiBox/5; 
	const int widthTieuDeMaVT = doDaiCoBan; 
	const int widthHoTenVT = doDaiCoBan*2; 
	const int widthDVT = doDaiCoBan; 
	const int widthSLT = doDaiCoBan;

	 
	NutBam tieuDeMaVT(toaDoXBox,110,widthTieuDeMaVT,40,6,7,10,"ma vt"); 
	NutBam tieuDeTenVT(toaDoXBox + widthTieuDeMaVT + 2,110,widthHoTenVT,40,6,7,10,"ten vt"); 
	NutBam tieuDeDVT(toaDoXBox+doDaiCoBan*3 + 4,110,widthDVT,40,6,7,10,"don vi tinh"); 
	NutBam tieuDeSLT(toaDoXBox + doDaiCoBan*4 +6,110,widthSLT -6 + 2,40,6,7,10,"so luong ton"); 
	NutBam luiLai(toaDoXBox                 ,caoBox + 120,80,40,7,6,2,"<<"); 
	NutBam tienLen(toaDoXBox + daiBox -80   ,caoBox + 120,80,40,7,6,2,">>"); 
	setcolor(colorLight); 
	line(toaDoXBox + widthTieuDeMaVT ,110,toaDoXBox + widthTieuDeMaVT ,caoBox +110); 
	line(toaDoXBox+doDaiCoBan*3 + 2 ,110,toaDoXBox+doDaiCoBan*3 + 2 ,caoBox +110);
	line(toaDoXBox + doDaiCoBan*4 +4,110,toaDoXBox + doDaiCoBan*4 +4 ,caoBox +110);	
	OVuong ovVatTu(toaDoXBox,110,daiBox,caoBox,colorLight); 
	ovVatTu.veOVuong(); 
	tieuDeMaVT.veNut();
	tieuDeTenVT.veNut();
	tieuDeDVT.veNut();
	tieuDeSLT.veNut();
	tienLen.veNut(); 
	luiLai.veNut();
	
	// ===================== BAC SU KIEN =====================
	int indexTrang = 0; // trang dau tien la so 0
	int soLuongItemPage = 2;  // hien tai la 2 phan tu tren 1 trang 
	int toiDaIndex = soLuongNode / soLuongItemPage; 
	inDanhSachLenDoHoa(arrVT,indexTrang,soLuongItemPage,soLuongNode); 
	string temp; 
	string stringToiDaIndex = TienichDoHoa::intToString(toiDaIndex); 
	indexTrang++; 
	temp = TienichDoHoa::intToString(indexTrang) + "/" + stringToiDaIndex; 
	outtextxy(DODAIMANHINH/2,caoBox + 120,(char*)(temp.c_str())); 
	indexTrang--; 
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
			else if (themVT.isMouseHover(mx,my)) {
				index = ID_THEM_VT; 
				return; 
			}
			else if (chinhSuaVT.isMouseHover(mx,my)) {
				index = ID_HIEUCHINH_VT; 
				return; 
			}
			else if (tienLen.isMouseHover(mx,my)) {
				if (indexTrang < toiDaIndex-1) {
					indexTrang++;  
					inDanhSachLenDoHoa(arrVT,indexTrang,soLuongItemPage,soLuongNode); 
					indexTrang++; 
					temp = TienichDoHoa::intToString(indexTrang) + "/" + stringToiDaIndex; 
					outtextxy(DODAIMANHINH/2,caoBox + 120,(char*)(temp.c_str())); 
					indexTrang--; 
				}
			}
			else if (luiLai.isMouseHover(mx,my)) {
				if (indexTrang > 0) {
					indexTrang--; 
					inDanhSachLenDoHoa(arrVT,indexTrang,soLuongItemPage,soLuongNode); 
					indexTrang++; 
					temp = TienichDoHoa::intToString(indexTrang) + "/" + stringToiDaIndex;  
					outtextxy(DODAIMANHINH/2,caoBox + 120,(char*)(temp.c_str())); 
					indexTrang--; 
				} 	
			}
		}
		delay(1); 
	}	
	delete [] arrVT; 
}			



// ============HIEN THI TINH NANG VAT TU MOI ==============
void hienThiTinhNangVatTu(BstVatTu &dsVatTu,int &index,NutBam &nhanVien,NutBam &hoaDon,NutBam &doanhThu) {
	// xoa di man hinh phia duoi va ve lai toan bo
	index = -1;  
	TienichDoHoa::xoaManHinhTheoToaDo(0,42,DODAIMANHINH,DORONGMANHINH,BACKGROUP);  // xoa di nua man hinh ben duoi. 
	bool kiemTra[3] = {false};
	bool kiemTraVT[3] = {false};  
	OVuong ovVatTu(5,45,DODAIMANHINH - 12,50,2); 
	ovVatTu.veOVuong(); 
	const int chieuDaiVT = 230; 
	const int chieuCaoVT = 35;
	const int cachLeNgang = 15; 
	const int cachLeTren = 53 ;
	NutBam themVT(cachLeNgang ,cachLeTren,chieuDaiVT,chieuCaoVT,COLOR_BTN_SUB,COLOR_HIGHT_BTN_SUB,COLOR_TEXT_BTN_SUB,"THEM VAT TU");
	NutBam hieuChinhVT(chieuDaiVT + cachLeNgang*2 ,cachLeTren,chieuDaiVT,chieuCaoVT,COLOR_BTN_SUB,COLOR_HIGHT_BTN_SUB,COLOR_TEXT_BTN_SUB,"HIEU CHINH VAT TU");
	NutBam inDSVT((chieuDaiVT + cachLeNgang )*2 + cachLeNgang ,cachLeTren,chieuDaiVT,chieuCaoVT,COLOR_BTN_SUB,COLOR_HIGHT_BTN_SUB,COLOR_TEXT_BTN_SUB,"IN DANH SACH VAT TU"); 
	themVT.veNut(); 
	hieuChinhVT.veNut() ; 
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
					// thuc hien hieu chinh VT
				}
				else if (index == ID_IN_VT) {
					inDanhSachVatTu(dsVatTu,index,nhanVien,hoaDon,doanhThu,themVT,hieuChinhVT);
					
				}
			}
		}
		if (ismouseclick(WM_MOUSEMOVE)) {
			getmouseclick(WM_MOUSEMOVE, mx, my);  
			nhanVien.kiemTraVeLai(mx,my,kiemTra[0]); 
			hoaDon.kiemTraVeLai(mx,my,kiemTra[1]);
			doanhThu.kiemTraVeLai(mx,my,kiemTra[2]);
			// kiem tra xem cac nut con co duoc hover h�ng 
			themVT.kiemTraVeLai(mx,my,kiemTraVT[0]); 
			hieuChinhVT.kiemTraVeLai(mx,my,kiemTraVT[1]); 
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
				hienThiInputVatTu(dsVatTu,index,nhanVien,hoaDon,doanhThu,hieuChinhVT,inDSVT); 
			}
			
			else if (hieuChinhVT.isMouseHover(xclick,yclick)) {
				hieuChinhVT.duocTroVao = true;
				themVT.veNut(); 
				hienThiHieuChinhVatTu(dsVatTu,index,nhanVien,hoaDon,doanhThu,themVT,inDSVT); 
				
			}
			else if (inDSVT.isMouseHover(xclick,yclick)) {  // HIEN THI RA TINH NANG IN DANH SACH. 
				inDanhSachVatTu(dsVatTu,index,nhanVien,hoaDon,doanhThu,themVT,hieuChinhVT); 
			}
		}
	delay(1);
}
}
