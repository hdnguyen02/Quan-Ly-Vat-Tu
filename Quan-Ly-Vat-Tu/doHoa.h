#pragma once
using namespace std; 
#include "autoLoad.h"

#define MAX_MENU 5  // số cột menu 
#define BACKGROUP 5 
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define ENTER 13
// Định nghĩa các cột menu chính 

char MenuChinh[][50] =
{ "Materials", "Employees", "Bills", "Statistics", "Help" };



// viết lại hàm vẽ hình chữ nhật 




// viết hàm vẽ ra hình vuông với các chi tiết sau ( file doHoa.h ) 
void veHinhChuNhat(int x,int y, int w,int h,int colorBackroup, int colorText,char *arr) {
	setfillstyle(SOLID_FILL, colorBackroup);
	bar(x, y, x + w,y + h);
	int text_w = textwidth(arr);
	int text_h = textheight(arr);
	int toaDoTextX = x + (w - text_w) / 2;
	int toaDoTextY = y + (h - text_h) / 2;
	setbkcolor(colorBackroup);
	outtextxy(toaDoTextX, toaDoTextY, arr);
}

// bao gồm các thông số sau:  
// vị trí ô dầu tiên. chiều dài hộp, chiều cao. màu nền. màu hight
// viết ra hàm vẽ ra menu 
void veMenu(int x, int y, int w, int h, int sl,int khoanCach,int colorBack,int colorText,char textMenu[][30]) {

	
	for (int i = 0; i < sl; i++) {
		veHinhChuNhat(x, y + (i * (h + khoanCach)) , w, h, colorBack, colorText, textMenu[i]);
	}
}

int MenuDong(int x, int y, int w, int h, int sl, int khoanCach, int colorBack, int colorText, int colorHight, char textMenu[][30]) {
	bool kt = true;
	veMenu(x, y, w, h, sl, khoanCach, colorBack, colorText, textMenu);
	int px = x;
	int py = y;
	int xcu = px;
	int ycu = py;
	int getEnter;
	int index = 0; // vị trí của thanh đầu tiên.
	int pIndex = index;

	// vị trí của thanh menu 
	// hàm này return về chỉ mục mà người dùng sẽ chọn 


	while (true) {
		if (kt == true) {
			veHinhChuNhat(xcu, ycu, w, h, colorBack, colorText, textMenu[pIndex]);
			xcu = px;
			ycu = py;
			pIndex = index;
			veHinhChuNhat(px, py, w, h, colorHight, colorText, textMenu[index]);
			kt = false;
		}

		if (kbhit()) {
			getEnter = getch();
			if (!(getEnter && getEnter != 224)) {
				getEnter = getch();
				if (getEnter == KEY_UP) {
					if (index != 0) {
						py = py - h - khoanCach;
						index--;
					}

					else {
						index = sl - 1;
						py = y + (h + khoanCach) * (sl - 1);
					}
					kt = true;
				}
				else if (getEnter == KEY_DOWN) {
					if (index != sl - 1) {
						py = py + h + khoanCach;
						index++;
					}
					else {
						py = y;
						index = 0;
					}
					kt = true;
				}
			}
			else if (getEnter == ENTER) {
				return index;
			}
		}
		Sleep(40);
	}
}

