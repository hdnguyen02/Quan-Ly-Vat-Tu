#pragma once
using namespace std;
#include "Tienich.h"
#include "BienDoHoa.h"
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <time.h>
void veGioiThieu(int &index,NutBam &vatTu,NutBam &nhanVien,NutBam &hoaDon,NutBam &doanhThu) 
{
	
	// xoa di man hinh 
	TienichDoHoa::xoaManHinhTheoToaDo(0, 56, DODAIMANHINH, DORONGMANHINH, BACKGROUP);
	settextstyle(8,0,5);
	outtextxy(1536/2-700,100,"HOC VIEN CONG NGHE BUU CHINH VIEN THONG co so Phia Nam");
	moveto(50,160);
	setcolor(7);
	setlinestyle(0,4,3);
	lineto(1450,160);
	lineto(1450,670);
	lineto(50,670);
	lineto(50,160);
	setbkcolor(0);
	setcolor(14);
	settextstyle(8,0,4);
	outtextxy(70,200,"* Mon Hoc:");
	outtextxy(70,300,"* Giang vien:");
	outtextxy(70,400,"* Ten Do An:");
	outtextxy(70,500,"* Thanh Vien:");
	outtextxy(340,200,"Cau Truc Du Lieu && Giai Thuat.");
	outtextxy(340,300,"Thay Ki Thu.");
	outtextxy(340,400,"Quan Li Vat Tu.");
	outtextxy(340,500,"1-Ho Duc Nguyen-N20DCCN047-Truong Nhom.");
	outtextxy(340,560,"2-Ngo Tien Hung-N20DCCN025-Thanh Vien.");
	outtextxy(340,620,"3-Tu Thi Thao Nguyen-N20DCCN048-Thanh Vien.");

    
    // bac su kien nguoi dung click ra 
    int xclick = -1; 
    int yclick = -1;
    while(true) {
    	if (ismouseclick(WM_LBUTTONDOWN))
		{
			int xclick = -1;
			int yclick = -1;
			getmouseclick(WM_LBUTTONDOWN, xclick, yclick);
			// bac su kien 
			if (vatTu.isMouseHover(xclick,yclick)) {
				index = ID_VT; 
				return; 
			}
			else if (nhanVien.isMouseHover(xclick,yclick)) {
				index = ID_NV; 
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
		delay(10); 
	}
    
    
}
