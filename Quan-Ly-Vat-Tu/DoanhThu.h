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


// ly thuyet nhu sau: 
// nhan vao nam : sau do di loc ra cac hoa don co nam phu hop 

void tinhDoanhThu(HoaDon** arrHoaDon,int soLuongHoaDon,float doanhThuNam[],int nam) {
	// lap qua tat ca ca hoa don va kiem tra 
	for (int i = 0;i < soLuongHoaDon;i++) {
		// kiem tra xem co phai hoa don xuat hay khong va kiem tra so nam phu hop thi kiem tra so thang  
		if (arrHoaDon[i]->date.nam == nam && arrHoaDon[i]->loai == "X") {
			doanhThuTheoNam[arrHoaDon[i]->date.thang - 1] = doanhThuTheoNam[arrHoaDon[i]->date.thang - 1] + arrHoaDon[i]->dsCTHD.tinhTongTien(); 
		}
	}
}
