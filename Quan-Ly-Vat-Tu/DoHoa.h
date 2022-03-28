#pragma once
#include "autoLoad.h"
using namespace std; 




// dinh nghia cac phim nong 
#define ENTER 13 
#define ESC 27 // nut thoat 
#define BACK_SPACE 8
#define SPACE 32



#define DODAIMANHINH 1536
#define DORONGMANHINH 864
#define BACKGROUP 7 // mau xam
#define COLOR_MENU_CAP1 2 // màu LIGHTBLUE
#define COLOR_HIGHT_LIGHT 8    // mau LIGHTMAGENTA 
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

// Nguyen mau ham 


// ================================== CLASS TIEN ICH DO HOA=========================================
class TienIchDoHoa {
	// xu dung de xoa man hinh. 
	public: 
	static void xoaManHinhTheoToaDo(int x,int y,int w,int h,int colorBack) {
		setfillstyle(SOLID_FILL, colorBack);   
		bar(x, y, x + w, y + h); 
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
	
	// neu ham duoc chon 
	void duocChon() {
		this->duocTroVao = true; 
		this->veNut(); // ve lai nut nay voi trang thai duoc chon. 
		
		
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
			
			
	void kiemTraVeLai(int &mx,int &my,bool &kiemTra) { // truyen tham chieu de chay nhanh hon
		if (this->isMouseHover(mx,my)) { // con tro chuoc dang tro. 
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
	int x,y, w, h,slKiTu; // so luong ki tu duoc nhap. 
	string boNhoDem; 
	string goiY; // goi cho nguoi dung nen nhap nhung gi. 
	int loaiNhap; // quy dinh nhap duoc nhap nhung gi 
	int widthTitle;  
	// 0 : nhap ca so lan chu 
	// 1 : chi duoc nhap chu ( co the in hoac thuong ). 
	// 2 : chi duoc nhap so
	// 3 : chi duoc nhap chu in
	// tuy theo loai quy dinh o day. truoc tien cho nhap tat ca. 
	string tieuDe; // hien thi phia truoc duoi dang 1 o vuong  
	bool duocChon; // trang thai co duoc chon hay khong 
	
 
	
	ONhap(int x,int y,int w,int h,int widthTitle,string tieuDe,int sl,string goiY) { 
		this->x= x; 
		this->y = y; 
		this->w = w; 
		this->h = h; 
		this->tieuDe = tieuDe; 
		this->widthTitle = widthTitle;  
		this->duocChon = false; // lan dau tao ra nen chua duoc nhap. 
		this->boNhoDem = ""; 
		this->slKiTu = sl;  // so luong ki tu duoc nhap. 
		
	}
	// viet 1 phuong thuc de cho nguoi dung co the cho nhap vao 
	
	void veONhap() {
		// ve ra cai boder 
		
		NutBam boxTieuDe(x,y,widthTitle,h,2,3,7,tieuDe); 
		boxTieuDe.veNut(); 		
		setfillstyle(SOLID_FILL,COLOR_BACKGROUP_INPUT); 
		bar(x + widthTitle,y, x+ widthTitle + w , y+h);  
		
	}
	
	// viet hma kiem tra xem 1 ki tu nhap vao co thoa hay khong 
	
	
	// kiem tra vua chu vua so 
	
	// viet ham xoa di ki tu cuoi 
	void xoaKiTuCuoi() {
		this->boNhoDem.erase(this->boNhoDem.size() - 1); // xoa di ki tu cuoi cung. 
	}
	// hàm xoa het tat ca nhung gi nam ben trong   
	void xoaNoiDungONhap() {
		
		TienIchDoHoa::xoaManHinhTheoToaDo(x + widthTitle,y,w,h,COLOR_BACKGROUP_INPUT);  // xoa song ve lai 
		this->veONhap(); // ve lai. 
		this->hienThiBoder(); 
	
	}
	
	void inNoiDung() {
			int text_h; 
			int toaDoTextY;
			settextstyle(1, 0, 2);
			text_h = textheight(boNhoDem.c_str());
			toaDoTextY = y + (h - text_h) / 2;
			setbkcolor(COLOR_BACKGROUP_INPUT);  // chung mau voi cai ma no ve
			setcolor(COLOR_TEXT_INPUT); 
			outtextxy (x + CACH_LE_O_NHAP + widthTitle,toaDoTextY, boNhoDem.c_str());
	}
	
	
	// viet 1 hàm tat hien thi boder 
	void tatHienThiBoder() {
		// ve ra cai mau nen trung voi cai mau backgourp la duoc 
		setcolor(COLOR_BACKGROUP_INPUT); 
		rectangle(x + widthTitle,y,x + w + widthTitle ,y + h); // hien thi thanh sang cai boder len. 
	}
	
	// tao ra con tro ham. 
	// ham chi nhan gia tri. 
	
	void NhapVao(bool(*loaiKiTu)(char)) {
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
		   	// cac dieu kien dung. khi nguoi dung nhap enter 
			// bac dieu kien 
			if (c == ENTER || c == ESC) {
				// thoat khong cho nhap nua 
				the_end = 1;  
				this->xoaNoiDungONhap();
				this->inNoiDung(); 
				this->tatHienThiBoder(); 
				
			}
			else if (c == BACK_SPACE && !boNhoDem.empty() ) {
					boNhoDem.erase(boNhoDem.size() - 1); 
					kiemTraBackSpace = true; 
					
			}
			else if (c == SPACE) {
				boNhoDem = boNhoDem + " " ; 
			}
			
			else if (loaiKiTu(c)) {
				boNhoDem = boNhoDem + c; // thoa man ki tu.
			}
			
		} while (!the_end);
	}
	
	void resetBoNhoDem() {
		this->boNhoDem = ""; // dua ve trang thai ban dau.
	}
	
	// viet ham ve lai boder cho cai khung khi dang nhap 
	void hienThiBoder() {
		setcolor(COLOR_BODER_INPUT); 
		rectangle(x + widthTitle,y,x + w + widthTitle ,y + h); // hien thi thanh sang cai boder len. 
	}
	
	
	bool isMouseHover(int mx, int my) {  // tra ve xem nguoi dung co nhap vao chon hay khong. 
		if (mx >= x && mx <= x + w && my >= y && my <= y + h) {
			return true;
		}
		return false;
	}
	
	ONhap() {}
	
	
	
	
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





 







void xoaManHinh() {
	setfillstyle(SOLID_FILL, BACKGROUP);   
	bar(0, 30, 3000, 3000); 
}

void hienThiTinhNangHoaDon() {

	// xoa het man hinh di 
	
	// hien thi ra menu 
}


// ====================================HIEN THI INPUT VATTU==============================================
void hienThiInputVatTu(int &index,NutBam &nhanVien,NutBam &hoaDon,NutBam &doanhThu,NutBam& hieuChinhVT,NutBam& inDSVT) {
	
	// truoc tien xoa man hinh
	// xoa het man hinh di. 
	// xoa het man hinh di. 
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
	
	ONhap nhapMaVT(cachLeInput,cachLeTrenInput,chieuDaiInput,chieuCaoInput,chieuDaiTieuDe,"ma",10);
	ONhap nhapTenVT(cachLeInput,cachLeTrenInput  + chieuCaoInput+ 32,chieuDaiInput,chieuCaoInput,chieuDaiTieuDe,"ten",10);
	
	ONhap nhapDVT(cachLeInput,cachLeTrenInput  + (chieuCaoInput+ 32)*2,chieuDaiInput,chieuCaoInput,chieuDaiTieuDe,"don vi tinh",10); 
	ONhap nhapSLTon(cachLeInput,cachLeTrenInput  + (chieuCaoInput+ 32)*3,chieuDaiInput,chieuCaoInput,chieuDaiTieuDe,"so luong ton",10); 

	// thiet ke them 1 btn nhap vao 
	// ve 2 nut -> 1 nut nop va nut lam moi 
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
	
	
	// bac su kien nguoi dung click 
	while(true) {
		if (ismouseclick(WM_LBUTTONDOWN)) {  
			int mx = -1;
			int my = -1; 
			getmouseclick(WM_LBUTTONDOWN, mx, my);
			// kiem tra bac su kien nguoi dung 
			if (hoaDon.isMouseHover(mx,my)) {
				// nguoi dung chon vao tab khac roi. 
				// ket thuc khong chay nua
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
			// bac dieu kien tiep tuc 
			else if (hieuChinhVT.isMouseHover(mx,my)) {
				index = ID_HIEUCHINH_VT; 
				// khong thuc hien ham nua -> vi nguoi dung chon cai khac. 
				return; 
			}
			else if (inDSVT.isMouseHover(mx,my)) {
			 	index = ID_IN_VT; 
			 	return; 
			}
			else {
				// truong hop nguoi dung dang nhap vao menu hien hanh
				// tien hanh kiem tra 
				if (nhapMaVT.isMouseHover(mx,my)) {
					// cho nguoi dung tien hanh nhap 
					nhapMaVT.NhapVao(kiTuChu); 
				}
				else if (nhapTenVT.isMouseHover(mx,my)) {
					nhapTenVT.NhapVao(kiTuChu); 
				}
				else if (nhapSLTon.isMouseHover(mx,my)) {
					nhapSLTon.NhapVao(kiTuSo); 
				}
				else if (nhapDVT.isMouseHover(mx,my)) {
					nhapDVT.NhapVao(kiTuSo); 
				}
				// truong hop nguoi dung nhap vao nut new hoac nut luu 
				else if (luu.isMouseHover(mx,my)) {
					cout << "luu thanh cong"; 
				}
			}
	} 
		delay(1); 
	}
	
}


// =================================HIEN THI TINH NANG VAT TU=========================================
void hienThiTinhNangVatTu(int &index,NutBam &nhanVien,NutBam &hoaDon,NutBam &doanhThu) {
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
	
	
	// xet vong lap. kiem tra xem 
	int mx = -1; 
	int my = -1; 
	while (true) {
	
		if (index != -1) {
			// xy ly khi nguoi dung vua moi chon. 
			// neu nhu index nam trong vung tu 0 -> 3 thi ta khong nhan xu ly 
			if (index >= 0 && index <= 3) {  // thuoc vung menu to. 
				// khong xu ly 
				return; // di ra ngoai xu ly. 
			}
			else {
				// co the xu ly. vi cung cap menu 
				if (index == ID_HIEUCHINH_VT) {
					// thuc hien hieu chinh VT
				}
				else if (index == ID_IN_VT) {
					// thuc hien in DSVT. 
				}
			}
		}
		if (ismouseclick(WM_MOUSEMOVE)) {
			getmouseclick(WM_MOUSEMOVE, mx, my);  
			nhanVien.kiemTraVeLai(mx,my,kiemTra[0]); 
			hoaDon.kiemTraVeLai(mx,my,kiemTra[1]);
			doanhThu.kiemTraVeLai(mx,my,kiemTra[2]);
			// kiem tra xem cac nut con co duoc hover hông 
			themVT.kiemTraVeLai(mx,my,kiemTraVT[0]); 
			hieuChinhVT.kiemTraVeLai(mx,my,kiemTraVT[1]); 
			inDSVT.kiemTraVeLai(mx,my,kiemTraVT[2]); 
			
		}
		// kiem tra xem co click hay hong
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
				// hien thi ra cai form nhap. 
				themVT.duocTroVao = true; 
				themVT.veNut();
				// truyen ca
				// truyen them 3 nut phia ben ngoai. 
				
				hienThiInputVatTu(index,nhanVien,hoaDon,doanhThu,hieuChinhVT,inDSVT); 
				
			}
			
			
			
			
			
			
				
		
		}

	delay(1); 
	
}
}







// ===================================MENU ROOT=========================================================
void menuCha() {  
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

	// truoc khi thuc hien vong lap. index hien tai dang o dau 
	
	
	while (true) {
		// kiem tra xem lan lap truoc nguoi dung co nhap chon vao cho khac hay khong 
		if (index != -1) {
			// kiem tra cu the 
			if (index == 0) {
				// nguoi dung chon lai menu vatTu 
				// dieu chinh index lai 
				index = -1 ; 
				hienThiTinhNangVatTu(index,nhanVien,hoaDon,doanhThu); 
			}
			else if (index == 1) {
				hienThiTinhNangHoaDon(); 
				index = -1; 
				
			}
			// nhung cai sau. 
		}
		if (ismouseclick(WM_MOUSEMOVE)) {  // duy chuyen chuoc. 
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
				  hienThiTinhNangVatTu(index,nhanVien,hoaDon,doanhThu);  
			}
			else if (hoaDon.isMouseHover(xclick, yclick)) {
				hoaDon.duocTroVao = true;
				hoaDon.veNut();  // ve lai nut nay voi cai mau duoc chon		
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
void menuQuanLyVatTu() {  
	 setfillstyle(SOLID_FILL, BACKGROUP);  
	bar(0, 0, 3000, 3000);
	menuCha(); 
	
	
	

}




