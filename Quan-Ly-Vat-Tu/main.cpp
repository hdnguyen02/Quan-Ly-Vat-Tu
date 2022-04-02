using namespace std;
#include "autoLoad.h" 

int main(int argc, char *argv[]) {
//	StartBGI start; 
//	BstVatTu dsVatTu; 
//	dsVatTu.docVatTuFile(); 
//	dsVatTu.duyetCay(); 
	// menuQuanLyVatTu(dsVatTu);
//	NhanVien nv1("NV1","duc1","nguyen",1);
//	NhanVien nv2("NV2","duc2","nguyen",0);
//	NhanVien nv3("NV3","duc3","nguyen",1);
//	NhanVien nv4("NV4","duc4","nguyen",0);
//	NhanVien nv5("NV5","duc5","nguyen",1);
	dsNhanVien ds;
//	ds.themNV(&nv1);
//	ds.themNV(&nv2);
//	ds.themNV(&nv3);
//	ds.themNV(&nv4);
//	ds.themNV(&nv5);
	
//	ds.xoaNVtheoMa("NV2");
//	ds.xuatNV();
	//ds.ghiFileNhanVien();
	ds.docFileNhanVien();
	
	ds.xuatNV();
	return 0;
}
