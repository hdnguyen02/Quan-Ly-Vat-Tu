#include "Tienich.h"
void tinhDoanhThu(DoanhThuVatTu arrDTVT[],int soLuongVatTu,HoaDon** arrHoaDon,int soLuongHoaDon,Date &start,Date end) {
		for (int i = 0; i < soLuongVatTu;i++) { 
			arrDTVT[i].doanhThu = 0; 	
			for (int j = 0; j < soLuongHoaDon;j++) {
				// truoc tien can phai kiem tra xem hoa don co hop ngay hay khong 
				if (arrHoaDon[j]->date.isDateInRange(start,end)) {
					arrDTVT[i].doanhThu = arrDTVT[i].doanhThu + arrHoaDon[j]->doanhThuBanRaVatTu(arrDTVT[i].pVatTu->maVT); 
				}	
			}
		}
	}


// viet ham sap xep dua tren tinhDoanhThu 



void sapXepDoanhThuVatTu(DoanhThuVatTu arrDTVT[],int soLuongVatTu) 
{ // truyen vao 1 mang chua gia tri.
	int i, j;
	DoanhThuVatTu key; 
	for (i = 1; i < soLuongVatTu; i++)
	{
		key = arrDTVT[i]; 
		j = i - 1;
		while (j >= 0 && arrDTVT[j].doanhThu < key.doanhThu)
		{
			arrDTVT[j + 1] = arrDTVT[j];
			j = j - 1;
		}
		arrDTVT[j + 1] = key;
	}
}
