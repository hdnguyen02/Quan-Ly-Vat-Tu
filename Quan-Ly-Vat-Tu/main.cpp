#include "MenuQLVT.h"
using namespace std;


// HAM CAU H 


int main(int argc, char *argv[])
{
	//StartBGI start;
	dsNhanVien DSNV;
	DSNV.docFileDSNV();
	BstVatTu dsVatTu;
	dsVatTu.docVatTuFile();
	//menuQuanLyVatTu(dsVatTu, DSNV);
	
	
	// khai bao ra 1 mang vat tu 
//	DoanhThuVatTu arrDTVT[100]; // khai bao hen xui 100 vat tu 
//	dsVatTu.BstVatTuToDoanhThuVatTu(arrDTVT,0); 
//	
//	// lay ra danh sach hoa don 
//	
//	HoaDon** arrHoaDon = new HoaDon*[DSNV.soLuongHD()]; 
//	int index = 0;
//	DSNV.listToArrayHoaDon(arrHoaDon,index); 
//	cout << "danh sach hoa don" << endl; 
//	for (int i = 0; i < DSNV.soLuongHD();i++) {
//		arrHoaDon[i]->in(); 
//		cout << endl; 
//	}
//	
//	cout << "danh sach vat tu"  << endl; 
//	tinhDoanhThu(arrDTVT,dsVatTu.soLuongVT(),arrHoaDon,DSNV.soLuongHD()); 
//	sapXepDoanhThuVatTu(arrDTVT,dsVatTu.soLuongVT()); 
//	for (int i = 0; i < dsVatTu.soLuongVT();i++) {	
//		arrDTVT[i].pVatTu->inVatTu(); 
//		cout << endl << "so tien trong hoa don: " << arrDTVT[i].doanhThu; 
//		cout << endl; 
//	}
	
	
	// ghi file hoa don xuat ra xem thu 
	DSNV.ghiFileNVHDTheoLoai("X"); 
	
	
	DSNV.giaiPhongDSNV();
	return 0;
}
