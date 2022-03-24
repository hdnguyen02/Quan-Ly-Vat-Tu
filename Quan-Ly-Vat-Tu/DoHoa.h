#pragma once
#include "autoLoad.h"
using namespace std; 




#define DODAIMANHINH 1536
#define BACKGROUP 7 // mau xam
#define COLOR_MENU_CAP1 1   // màu LIGHTBLUE
#define COLOR_HIGHT_LIGHT 8    // mau LIGHTMAGENTA 

// cap do menu 1
#define ID_VT 0 
#define ID_NV 1
#define ID_HD 2
#define ID_DT 3

// dung de chua cac ham lien quan den do hoa. 
class TienIchDoHoa {
	// xu dung de xoa man hinh. 
	public: 
	static void xoaManHinhTheoToaDo(int x,int y,int w,int h,int colorBack) {
		setfillstyle(SOLID_FILL, colorBack);   
		bar(x, y, x + w, y + h); 
	}
};  



struct ONhap {
	int x,y, w, h; 
	string boNhoDem; 
	
	
	string tieuDe; // hien thi phia truoc duoi dang 1 o vuong  
	bool duocChon; // trang thai co duoc chon hay khong 
	
	// thu nghiem 
	char inputbuf[80];
	int input_pos = 0;
	int the_end = 0;
	
	
	bool isMouseHover(int mx, int my) {  // tra ve xem nguoi dung co nhap vao chon hay khong. 
		if (mx >= x && mx <= x + w && my >= y && my <= y + h) {
			return true;
		}
		return false;
	}
	
	ONhap() {}
	ONhap(int x,int y,int w,int h,string tieuDe) { 
		// ve ra cai form nhap 
		this->x= x; 
		this->y = y; 
		this->w = w; 
		this->h = h; 
		this->tieuDe = tieuDe; 
		this->duocChon = false; // lan dau tao ra nen chua duoc nhap. 
		
		// tam thoi chua quan tam den cai tieuDe lam gi 	
	}
	// viet 1 phuong thuc de cho nguoi dung co the cho nhap vao 
	
	void veONhap() {
		
		setfillstyle(SOLID_FILL, 1); // bo bua.
		bar(x,y,x+w,y+h);  
	}
	void NhapVao() {
		// bac dieu kien nguoi dung nhap vao. 
		char c; 
		do
		{
		   outtextxy (x,y, inputbuf);
		   c = getch();
		   switch (c)
		   {
		        case 8: /* backspace */
		          if (input_pos)
		          {
		             input_pos--;
		             inputbuf[input_pos] = 0;
		          }
		          break;
		        case 13: /* return */
		          the_end = 1;
		          break;
		        case 27: /* Escape = Abort */
		          inputbuf[0] = 0;
		          the_end = 1;
		          break;
		        default:
		          if (input_pos < 80-1 && c >= ' ' && c <= '~')
		          {
		             inputbuf[input_pos] = c;
		             input_pos++;
		             inputbuf[input_pos] = 0;
		          }
		   }
		} while (!the_end);
	}
	
};
 



struct NutBam {
	int  id,x, y, w, h;
	int colorBack,colorHight,colorText; 
	string tieuDe;
	bool duocTroVao;
	NutBam(int id, int x, int y, int w, int h,int colorBack,int colorHight,int colorText,string tieuDe) {
		this->id = id; 
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
		int text_w = textwidth(arr);
		int text_h = textheight(arr);
		int toaDoTextX = x + (w - text_w) / 2;
		int toaDoTextY = y + (h - text_h) / 2;
		setcolor(colorText);
		if (duocTroVao) setbkcolor(colorHight);
		else setbkcolor(colorBack);
		settextstyle(10, 0, 1);
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



//void hienThiTinhNangVatTu(int &index,NutBam &nhanVien,NutBam &hoaDon,NutBam &doanhThu) {
//	bool kiemTra[3] = {false};
//	bool kiemTraVT[3] = {false};  
//	ONhap test(400,400,200,40,"gi cung duoc"); 
//	ONhap testPro(600,600,200,40,"gi cung duoc"); 
//	OVuong ovVatTu(5,45,DODAIMANHINH - 12,50,2); 
//	ovVatTu.veOVuong(); 
//	const int chieuDaiVT = 200; 
//	const int chieuCaoVT = 35;
//	const int cachLeNgang = 15; 
//	const int cachLeTren = 53 ;
//	NutBam themVT(cachLeNgang,cachLeTren,chieuDaiVT,chieuCaoVT,"THEM VAT TU");
//	NutBam hieuChinhVT(chieuDaiVT + cachLeNgang + 10,cachLeTren,chieuDaiVT,chieuCaoVT,"HIEU CHINH VAT TU");
//	NutBam inDSVT((chieuDaiVT + cachLeNgang )*2 + 10,cachLeTren,chieuDaiVT,chieuCaoVT,"IN DANH SACH VAT TU"); 
//	themVT.veNut(); 
//	hieuChinhVT.veNut() ; 
//	inDSVT.veNut(); 
//	
//	
//	// xet vong lap. kiem tra xem 
//	int mx = -1; 
//	int my = -1; 
//	while (true) {
//		// kiem tra xem co click
//		// kiem tra neu co duy chuyen chuoc 
//		if (ismouseclick(WM_MOUSEMOVE)) {
//			getmouseclick(WM_MOUSEMOVE, mx, my);  
//			nhanVien.kiemTraVeLai(mx,my,kiemTra[0]); 
//			hoaDon.kiemTraVeLai(mx,my,kiemTra[1]);
//			doanhThu.kiemTraVeLai(mx,my,kiemTra[2]);
//			// kiem tra xem cac nut con co duoc hover hông 
//			themVT.kiemTraVeLai(mx,my,kiemTraVT[0]); 
//			hieuChinhVT.kiemTraVeLai(mx,my,kiemTraVT[1]); 
//			inDSVT.kiemTraVeLai(mx,my,kiemTraVT[2]); 
//			
//		}
//		// kiem tra xem co click hay hong
//		else if (ismouseclick(WM_LBUTTONDOWN)) {  
//			int xclick = -1;
//			int yclick = -1; 
//			getmouseclick(WM_LBUTTONDOWN, xclick, yclick); 
//			if (nhanVien.isMouseHover(xclick,yclick)) {
//				index = 1; 
//				return; 
//			}
//			else if (hoaDon.isMouseHover(xclick,yclick)) {
//					index = 2;   
//					return; 
//			}
//			else if (doanhThu.isMouseHover(xclick,yclick)) {
//					index = 3;   
//					return; 
//			}
//			else if (themVT.isMouseHover(xclick,yclick)) {
//				// ve ra 1 cái o Nhap vao. 
//				TienIchDoHoa::xoaManHinhTheoToaDo(0,cachLeTren + chieuDaiVT + 10,3000,3000,BACKGROUP);
//				test.veONhap(); 
//				
//			}
//			// kiem tra xem co nhap hay khong 
//			else if (test.isMouseHover(xclick,yclick)) {
//				// cho nguoi dung nhap vao. 
//				
//				TienIchDoHoa::xoaManHinhTheoToaDo(0,cachLeTren + chieuDaiVT + 10,3000,3000,BACKGROUP);
//				test.veONhap();
//				test.NhapVao(); // neu click thi co nhap vao. 
//			}
//			// neu nguoi dung nhap vao cai khac 
//			else if (hieuChinhVT.isMouseHover(xclick,yclick)) {
//			 	TienIchDoHoa::xoaManHinhTheoToaDo(0,cachLeTren + chieuDaiVT + 10,3000,3000,BACKGROUP);
//				testPro.veONhap(); 
//				
//			}
//			
//			else if (testPro.isMouseHover(xclick,yclick)) {
//				TienIchDoHoa::xoaManHinhTheoToaDo(0,cachLeTren + chieuDaiVT + 10,3000,3000,BACKGROUP);
//				
//				testPro.veONhap();
//				testPro.NhapVao();  
//			}
//			
//				
//		
//		}
//
//	delay(1); 
//	
//}
//}


void hienThiTinhNangHoaDon() {

	// xoa het man hinh di 
	
	outtextxy(500,500,"hello word"); 
	cout << "thanh cong"; 
}





void menuCha() {  
	int index = -1; 
	int doDai = DODAIMANHINH / 4 - 16; 
	const int chieuCaoMenuCap1 = 40;  
	NutBam vatTu(ID_VT,0,0, doDai,chieuCaoMenuCap1,COLOR_MENU_CAP1,COLOR_HIGHT_LIGHT,3,"VAT TU");
	NutBam nhanVien(ID_NV,doDai, 0, doDai, chieuCaoMenuCap1,COLOR_MENU_CAP1,COLOR_HIGHT_LIGHT,3, "NHAN VIEN");
	NutBam hoaDon( ID_HD,doDai*2 , 0, doDai , chieuCaoMenuCap1,COLOR_MENU_CAP1,COLOR_HIGHT_LIGHT,3, "HOA DON");
	NutBam doanhThu(ID_DT, doDai * 3, 0, doDai, chieuCaoMenuCap1,COLOR_MENU_CAP1,COLOR_HIGHT_LIGHT,3, "DOANH THU");
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
				// hienThiTinhNangVatTu(index,nhanVien,hoaDon,doanhThu); 
			}
			else if (index == 1) {
				hienThiTinhNangHoaDon(); 
				index = -1; 
				
			}
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
				 // hienThiTinhNangVatTu(index,nhanVien,hoaDon,doanhThu);  
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

void menuQuanLyVatTu() {  
	 setfillstyle(SOLID_FILL, BACKGROUP);  
	bar(0, 0, 3000, 3000);
	menuCha(); 
	
	
	

}


