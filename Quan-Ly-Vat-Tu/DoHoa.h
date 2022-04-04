#pragma once
#include "autoLoad.h"
using namespace std; 

#define ENTER 13 
#define ESC 27 
#define BACK_SPACE 8
#define SPACE 32

#define DODAIMANHINH 1536
#define DORONGMANHINH 864
#define BACKGROUP 7 
#define COLOR_MENU_CAP1 2 
#define COLOR_HIGHT_LIGHT 8    
#define COLOR_TEXT 10
#define COLOR_BODER_INPUT 2

// cap do menu 1
#define ID_VT 0 
#define ID_NV 1
#define ID_HD 2
#define ID_DT 3

// ID cua cac menu con cua ID_VT 
#define ID_THEM_VT 4 
#define ID_HIEUCHINH_VT 5
#define ID_IN_VT 6 

// mau cho cac nut con 
#define COLOR_BTN_SUB 6  // mau cua cac nut con 
#define COLOR_TEXT_BTN_SUB 10
#define COLOR_HIGHT_BTN_SUB 8

// dinh nghia mau nen o Nhap 
#define COLOR_BACKGROUP_INPUT 7
#define CACH_LE_O_NHAP 10   // cach cai thanh o nhap ra bao nhieu px
#define COLOR_TEXT_INPUT 2


// ================================== CLASS TIEN ICH DO HOA=========================================
class TienIchDoHoa {
	// xu dung de xoa man hinh. 
	public: 
	static void xoaManHinhTheoToaDo(int x,int y,int w,int h,int colorBack) {
		setfillstyle(SOLID_FILL, colorBack);   
		bar(x, y, x + w, y + h); 
	}
	static string floatToString(float f) {
		stringstream ss; 
		ss << f; 
		string temp; 
		ss >> temp; 
		return temp; 
	}
	static string intToString(int n) {
		stringstream ss; 
		ss << n; 
		string temp; 
		ss >> temp; 
		return temp; 
	}
	static float stringToFloat(string s) {
		stringstream ss; 
		ss << s; 
		float temp; 
		ss >> temp;
		return temp; 
	}
	static int stringToInt(string s){
		stringstream ss; 
		ss << s; 
		int temp; 
		ss >> temp; 
		return temp; 
	}
};  

//=====================================STRUCT NUT BAM===================================================
struct NutBam {
	int x, y, w, h; 
	int colorBack,colorHight,colorText; 
	string tieuDe;
	bool duocTroVao;
	
	NutBam( int x, int y, int w, int h,int colorBack,int colorHight,int colorText,string tieuDe) {
		this->x = x; 
		this->y = y; 
		this->w = w;
		this->h = h; 
		this->tieuDe = tieuDe; 
		this->duocTroVao = false; 
		this->colorBack = colorBack; 
		this->colorHight =colorHight; 
		this->colorText = colorText;
	}

	void duocChon() {
		this->duocTroVao = true; 
		this->veNut();  
	}
	
	NutBam() {}; 
	bool isMouseHover(int mx, int my) {  
		if (mx >= x && mx <= x + w && my >= y && my <= y + h) {
			return true;
		}
		return false;
	}

	void veNut() {
		char arr[70]; 
		strcpy(arr, tieuDe.c_str()); 
		
		setfillstyle(SOLID_FILL, duocTroVao ? colorHight : colorBack); // bo bua. 
		bar(x, y, x + w, y + h);
		settextstyle(10, 0, 1);  
		int text_w = textwidth(arr);
		int text_h = textheight(arr);
		int toaDoTextX = x + (w - text_w) / 2;
		int toaDoTextY = y + (h - text_h) / 2;
		setcolor(colorText);
		if (duocTroVao) setbkcolor(colorHight);
		else setbkcolor(colorBack); 
		outtextxy(toaDoTextX, toaDoTextY, arr);
	}
	
	// ham kiem tra xem co nen ve lai mot nut hay khong ( hover thi ve lai hoac co the khong ) 
	void kiemTraVeLai(int &mx,int &my,bool &kiemTra) { 
		if (this->isMouseHover(mx,my)) { 
				this->duocTroVao = true; 
				this->veNut(); 
				kiemTra = true; 
			}
		else if (kiemTra == true) {
				this->duocTroVao = false; 
				this->veNut(); 
				kiemTra = false; 
			}
		}

};


// ====================================STRUCT O NHAP===============================================
struct ONhap {
	int x,y, w, h,SLKTTD;
	string boNhoDem; 
	int widthTitle;  
	string tieuDe; 
	ONhap() {}	
	ONhap(int x,int y,int w,int h,int widthTitle,string tieuDe,int SLKTTD) { 
		this->x= x; 
		this->y = y; 
		this->w = w; 
		this->h = h; 
		this->tieuDe = tieuDe; 
		this->widthTitle = widthTitle;  
		this->boNhoDem = ""; 
		this->SLKTTD = SLKTTD;  // so luong ki tu duoc nhap. 	
	}

	void veONhap() {
		NutBam boxTieuDe(x,y,widthTitle,h,2,3,7,tieuDe); 
		boxTieuDe.veNut(); 		
		setfillstyle(SOLID_FILL,COLOR_BACKGROUP_INPUT); 
		bar(x + widthTitle,y, x+ widthTitle + w , y+h);  
	}
	
	void xoaKiTuCuoi() {
		this->boNhoDem.erase(this->boNhoDem.size() - 1); // xoa di ki tu cuoi cung. 
	}
	
	void xoaNoiDungONhap() {  // h�m xoa het tat ca nhung gi nam ben trong o nhap
		TienIchDoHoa::xoaManHinhTheoToaDo(x + widthTitle,y,w,h,COLOR_BACKGROUP_INPUT);  // xoa song ve lai 
		this->veONhap();
		this->hienThiBoder(); 
	}
	
	void inNoiDung() {
			int text_h; 
			int toaDoTextY;
			settextstyle(1, 0, 2);
			text_h = textheight(&boNhoDem[0]);
			toaDoTextY = y + (h - text_h) / 2;
			setbkcolor(COLOR_BACKGROUP_INPUT);  // chung mau voi cai ma no ve
			setcolor(COLOR_TEXT_INPUT); 
			outtextxy (x + CACH_LE_O_NHAP + widthTitle,toaDoTextY, &boNhoDem[0]);
	}
	
	void tatHienThiBoder() {
		setcolor(COLOR_BACKGROUP_INPUT); 
		rectangle(x + widthTitle,y,x + w + widthTitle ,y + h); // hien thi thanh sang cai boder len. 
	}
	void NhapVao(bool(*loaiKiTu)(char),const string& goiY) {
		this->hienThiBoder(); 
		int the_end = 0;
		char c; 
		bool kiemTraBackSpace = false; 
		do
		{
			boNhoDem = boNhoDem + "|"; // them dau gach nhay. 
			if (kiemTraBackSpace) {
				this->xoaNoiDungONhap();  
				kiemTraBackSpace = false;  
			}
		   	this->inNoiDung(); 
			this->xoaKiTuCuoi(); 
		   	c = getch();
			if (c == ENTER || c == ESC) {
				this->xoaGoiY();
				the_end = 1;  
				this->xoaNoiDungONhap();
				this->inNoiDung(); 
				this->tatHienThiBoder(); 		
			}
			else if (c == BACK_SPACE && !boNhoDem.empty() ) {
					this->xoaGoiY();
					boNhoDem.erase(boNhoDem.size() - 1); 
					kiemTraBackSpace = true; 			
			}
			else if (SLKTTD <= boNhoDem.length()) {
				this->xoaGoiY(); 
				setcolor(4);
				setbkcolor(15);
				string temp = "toi da " + TienIchDoHoa::intToString(SLKTTD) + " ki tu!"; 
				settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
				outtextxy(x,y + h + 3,&temp[0]); 
			}
 			else if (c == SPACE ) {
 				this->xoaGoiY();
				boNhoDem = boNhoDem + " " ; 	
			}		
			else if (loaiKiTu(c)) {
				this->xoaGoiY();
				boNhoDem = boNhoDem + c; 
			}	
			else if (!loaiKiTu(c)) {
				this->xoaGoiY();
				setcolor(4); 
				settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
				outtextxy(x,y + h + 3,(char*) goiY.c_str()); 	
			}					
		} while (!the_end);
	}
	
	void xoaGoiY() {
		TienIchDoHoa::xoaManHinhTheoToaDo(x -2,y+ 1 + h,w,25,15); 	
	}
	void resetBoNhoDem() {
		this->boNhoDem = ""; 
		this->xoaNoiDungONhap(); 
		this->tatHienThiBoder(); 
	}	
	void hienThiBoder() {
		setcolor(COLOR_BODER_INPUT); 
		rectangle(x + widthTitle,y,x + w + widthTitle ,y + h); 
	}
	
	bool isMouseHover(int mx, int my) {   
		if (mx >= x && mx <= x + w && my >= y && my <= y + h) {
			return true;
		}
		return false;
	}
};

//===========================================STRUCT OVUONG==============================================
struct OVuong {
	int x, y, w, h, mauOVuong;
	 OVuong(int x,int y,int w,int h,int mauOVuong) {
	 	this->x = x;
	 	this->y = y; 
	 	this->w = w; 
	 	this->h = h; 
	 	this->mauOVuong = mauOVuong; 
	 	
	 }
	OVuong() {
		x = 0; 
		y = 0; 
	}
	void veOVuong() {
		rectangle(x, y, x + w, y + h);
	}
};

void hienThiTinhNangHoaDon() {

}

// ======================================HIEU CHINH VAT TU===============================================
void hienThiHieuChinhVatTu(BstVatTu &dsVatTu,int &index,NutBam &nhanVien,NutBam &hoaDon,NutBam &doanhThu,NutBam& themVT,NutBam& inDSVT) {
	TienIchDoHoa::xoaManHinhTheoToaDo(0,46 + 50,DODAIMANHINH,1000,BACKGROUP); 
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
				TienIchDoHoa::xoaManHinhTheoToaDo(mxTieuDe + 190,cachLeTrenBox + 310,1000,40,BACKGROUP); 
				nhapMaVT.NhapVao(kiTuChuHoacSo,""); 
			}
			else if (timKiem.isMouseHover(mx,my)) {
				string maVT = nhapMaVT.boNhoDem; // lay ra bo nho dem. 
				NodeVatTu* pTempVT = dsVatTu.timKiemVT(maVT);   // tra ve NULL neu khong tim thay.
				if (pTempVT != NULL) {
					TienIchDoHoa::xoaManHinhTheoToaDo(0,46 + 50,DODAIMANHINH,1000,BACKGROUP);  // xoa het ( ve lai ) 
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
	TienIchDoHoa::xoaManHinhTheoToaDo(0,46 + 50,DODAIMANHINH,1000,BACKGROUP); 
	const int chieuDaiBox = 700;
	const int mxTieuDe = (DODAIMANHINH / 2 ) - (chieuDaiBox/2);
	const int cachLeTrenTieuDe = 200;
	const int chieuCaoTieuDe = 40; 
	NutBam tieuDe(mxTieuDe,cachLeTrenTieuDe,chieuDaiBox,chieuCaoTieuDe,8,9,10,"NHAP THONG TIN VAT TU");
	
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
					TienIchDoHoa::xoaManHinhTheoToaDo(mxTieuDe + 40,650,1000,36,BACKGROUP);
					nhapMaVT.NhapVao(kiTuChuHoacSo,""); 
					
				}
				else if (nhapTenVT.isMouseHover(mx,my)) {
					TienIchDoHoa::xoaManHinhTheoToaDo(mxTieuDe + 40,650,1000,36,BACKGROUP);
					nhapTenVT.NhapVao(kiTuChuHoacSo,""); 
				}
				else if (nhapSLTon.isMouseHover(mx,my)) {
					TienIchDoHoa::xoaManHinhTheoToaDo(mxTieuDe + 40,650,1000,36,BACKGROUP);
					nhapSLTon.NhapVao(kiTuSo,"chi nhap so"); 
				}
				else if (nhapDVT.isMouseHover(mx,my)) {
					TienIchDoHoa::xoaManHinhTheoToaDo(mxTieuDe + 40,650,1000,36,BACKGROUP);
					nhapDVT.NhapVao(kiTuChu,"chi nhap chu"); 
				}
				else if (luu.isMouseHover(mx,my)) {
					string maVT = nhapMaVT.boNhoDem; 
					string tenVT = nhapTenVT.boNhoDem; 
					float tempSLT = TienIchDoHoa::stringToFloat(nhapSLTon.boNhoDem);  
					string  DVT = nhapDVT.boNhoDem; 
					if (maVT == "" || tenVT == "" || nhapSLTon.boNhoDem == "" || DVT == "" ) {
						setcolor(12); 
						setbkcolor(BACKGROUP);  
						settextstyle(TRIPLEX_FONT,0,2); 
						outtextxy(mxTieuDe + 48,650,"vui long khong bo trong bat cu truong nao!"); 
					}
					else {
						VatTu tempVT(maVT,tenVT,DVT,tempSLT);
						dsVatTu.themVT(tempVT); 
						nhapMaVT.resetBoNhoDem(); 
						nhapTenVT.resetBoNhoDem(); 
						nhapDVT.resetBoNhoDem(); 
						nhapSLTon.resetBoNhoDem(); 
						setcolor(1); 
						setbkcolor(BACKGROUP); 
						TienIchDoHoa::xoaManHinhTheoToaDo(mxTieuDe + 40,650,1000,36,BACKGROUP);
						outtextxy(mxTieuDe + 270,650,"them thanh cong"); 
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
	 
	setcolor(0); 
	for (int i = 0;i < soLuongItemPage;i++) {
		if (i + indexPage*soLuongItemPage < soLuongNode  ) {
		tempDVT = TienIchDoHoa::floatToString(arrVT[i + indexPage*soLuongItemPage]->getInfo().soLuongTon); 
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
	TienIchDoHoa::xoaManHinhTheoToaDo(0,46 + 50,DODAIMANHINH,1000,BACKGROUP); 
	

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
	NutBam tieuDeSLT(toaDoXBox + doDaiCoBan*4 +6,110,widthSLT -6,40,6,7,10,"so luong ton"); 
	NutBam luiLai(toaDoXBox                 ,caoBox + 120,80,40,4,6,10,"<<"); 
	NutBam tienLen(toaDoXBox + daiBox -80   ,caoBox + 120,80,40,4,6,10,">>"); 
	setcolor(1); 
	line(toaDoXBox + widthTieuDeMaVT ,110,toaDoXBox + widthTieuDeMaVT ,caoBox +110); 
	line(toaDoXBox+doDaiCoBan*3 + 2 ,110,toaDoXBox+doDaiCoBan*3 + 2 ,caoBox +110);
	line(toaDoXBox + doDaiCoBan*4 +4,110,toaDoXBox + doDaiCoBan*4 +4 ,caoBox +110);	
	OVuong ovVatTu(toaDoXBox,110,daiBox,caoBox,1); 
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
	string stringToiDaIndex = TienIchDoHoa::intToString(toiDaIndex); 
	indexTrang++; 
	temp = TienIchDoHoa::intToString(indexTrang) + "/" + stringToiDaIndex; 
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
					temp = TienIchDoHoa::intToString(indexTrang) + "/" + stringToiDaIndex; 
					outtextxy(DODAIMANHINH/2,caoBox + 120,(char*)(temp.c_str())); 
					indexTrang--; 
				}
			}
			else if (luiLai.isMouseHover(mx,my)) {
				if (indexTrang > 0) {
					indexTrang--; 
					inDanhSachLenDoHoa(arrVT,indexTrang,soLuongItemPage,soLuongNode); 
					indexTrang++; 
					temp = TienIchDoHoa::intToString(indexTrang) + "/" + stringToiDaIndex;  
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
	TienIchDoHoa::xoaManHinhTheoToaDo(0,42,DODAIMANHINH,DORONGMANHINH,BACKGROUP);  // xoa di nua man hinh ben duoi. 
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

// ===================================MENU ROOT=========================================================
void menuCha(BstVatTu &dsVatTu) {  
	int index = -1;  
	int doDai = DODAIMANHINH / 4 - 16; 
	const int chieuCaoMenuCap1 = 40;  
	NutBam vatTu(0,0, doDai,chieuCaoMenuCap1,COLOR_MENU_CAP1,COLOR_HIGHT_LIGHT,COLOR_TEXT,"VAT TU");
	NutBam nhanVien(doDai, 0, doDai, chieuCaoMenuCap1,COLOR_MENU_CAP1,COLOR_HIGHT_LIGHT,COLOR_TEXT, "NHAN VIEN");
	NutBam hoaDon( doDai*2 , 0, doDai , chieuCaoMenuCap1,COLOR_MENU_CAP1,COLOR_HIGHT_LIGHT,COLOR_TEXT, "HOA DON");
	NutBam doanhThu( doDai * 3, 0, doDai, chieuCaoMenuCap1,COLOR_MENU_CAP1,COLOR_HIGHT_LIGHT,COLOR_TEXT, "DOANH THU");
	vatTu.veNut(); 
	nhanVien.veNut(); 
	hoaDon.veNut(); 
	doanhThu.veNut(); 
	bool kiemTra[4] = { false }; 
	int mx = -1;  
	int my = -1;
	while (true) {
		if (index != -1) {
			if (index == 0) {
				index = -1 ; 
				hienThiTinhNangVatTu(dsVatTu,index,nhanVien,hoaDon,doanhThu); 
			}
			else if (index == 1) {
			
			}
		}
		if (ismouseclick(WM_MOUSEMOVE)) {
			getmouseclick(WM_MOUSEMOVE, mx, my);  
			vatTu.kiemTraVeLai(mx,my,kiemTra[0]);   
			nhanVien.kiemTraVeLai(mx,my,kiemTra[1]); 
			hoaDon.kiemTraVeLai(mx,my,kiemTra[2]); 
			doanhThu.kiemTraVeLai(mx,my,kiemTra[3]); 
		}
		else if (ismouseclick(WM_LBUTTONDOWN)) {  
			int xclick = -1;
			int yclick = -1; 
			getmouseclick(WM_LBUTTONDOWN, xclick, yclick);  
			if (vatTu.isMouseHover(xclick, yclick)) {
				vatTu.duocTroVao = true; 
				vatTu.veNut(); 
				hienThiTinhNangVatTu(dsVatTu,index,nhanVien,hoaDon,doanhThu);  
			}
			else if (hoaDon.isMouseHover(xclick, yclick)) {
				hoaDon.duocTroVao = true;
				hoaDon.veNut(); 
			}
			else if (nhanVien.isMouseHover(xclick, yclick)) {
				nhanVien.duocTroVao = true;
				nhanVien.veNut();
			}
			else if (doanhThu.isMouseHover(xclick,yclick)) {
				doanhThu.duocTroVao = true;
				doanhThu.veNut();
			}
		}
		 delay(1);  
	}	
}

// =================================MENU NHAN THAM SO==============================================
void menuQuanLyVatTu(BstVatTu &dsVatTu) {  
	setfillstyle(SOLID_FILL, BACKGROUP);  
	bar(0, 0, 3000, 3000);
	menuCha(dsVatTu); 
}




