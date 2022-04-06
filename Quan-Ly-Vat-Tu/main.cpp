#include "MenuQLVT.h"
using namespace std;


int main(int argc, char *argv[]) {
	
//	int lc; 
//	CThoaDon cthd1("VT01",1,1,1);
//  	CThoaDon cthd2("VT02",1,1,1); 
//  	CThoaDon cthd3("VT03",1,1,1); 
//  	CThoaDon cthd4("VT04",1,1,1); 
//  	CThoaDon cthd5("VT05",1,1,1); 
//  	CThoaDon cthd6("VT06",1,1,1); 
//  	CThoaDon cthd7("VT07",1,1,1); 
//  	
//  	ListCTHD CTHD; 
//  	
// 	CTHD.themVaoCuoiCTHD(cthd1); 
// 	CTHD.themVaoCuoiCTHD(cthd2); 
//  	CTHD.themVaoCuoiCTHD(cthd3); 
//  	CTHD.themVaoCuoiCTHD(cthd4); 
//  	CTHD.themVaoCuoiCTHD(cthd5); 
//  	CTHD.themVaoCuoiCTHD(cthd6); 
//  	CTHD.themVaoCuoiCTHD(cthd7); 
//  	
//  	while(true) {
//			   system("cls"); 
//			   cout << "1.Nhap hoa don"<< endl; 
//			   cout << "2.Xoa hoa don"<< endl;
//			   cout << "3.Tim kiem hoa don"<< endl; 
//			   cout << "4.ket thuc"<< endl;
//			   cout <<"nhap vao lc : "; 
//			   cin >> lc; 
//			   if (lc == 1) { 
//			   	  string ma; 
//			   	  float sl; 
//			   	  float donGia; 
//			   	  float VAT; 
//			   	 bool checkMaTrung; 
//			   	  do {
//			   	  	
//					 	 cout << "ma VT: "; 
//					 	 cin >> ma; 
//					 	 checkMaTrung = CTHD.timKiemCTHD(ma); 
//				  }
//				while(checkMaTrung);  // tra ve neu da tim thay ma nay => 
//			   	  cout  << "don gia : "; 
//			   	  cin >> donGia; 
//			   	  cout  << "so luong: "; 
//			   	  cin >> sl; 
//			   	  cout << "VAT: "; 
//			   	  cin >> VAT; 
//			   	  CThoaDon temp(ma,sl,donGia,VAT); 
//			   	  // kiem tra xem su ton tai 
//			   	  if (CTHD.themVaoCuoiCTHD(temp)) {
//					 	cout << endl << "them than cong!" << endl; 
//					
//				  }
//				  else {
//				  	cout << "them that bai! ma VT da ton tai"; 
//				  }
//			   	  system("pause"); 
//			   	  	
//			   	 
//			   }
//			   else if (lc == 2) {
//			   	 cout << "nhap vao hoa don muon xoa: "; 
//			   	 string temp; 
//			   	 cin >> temp; 
//			   	 if (CTHD.xoaCTHD(temp)) {
//						cout << endl << "xoa thanh cong"; 
//				}
//				else {
//					cout << endl << "xoa that bai"; 
//				}
//				system("pause"); 
//			   }
//			   else if (lc == 3) {
//			   cout << "nhap vao hoa don chi tiet muon tim kiem: "; 
//			   	 string temp; 
//			   	 cin >> temp; 
//			   	 if (CTHD.timKiemCTHD(temp)) {
//						cout << endl << "co ton tai"; 
//				}
//				else {
//					cout << endl << "khong ton tai!"; 
//				}
//				system("pause"); 
//			 }
//			 else if (lc == 4) {
//				break; 
//			 }
//			 else if (lc == 5) {
//			 	CTHD.duyetCTHD(); 
//			 	system("pause"); 
//			 }
//	   
//	  }
  	
//	ListCTHD dscthd; 
//	ifstream filein; 
//	filein.open("data/dataCTHD.txt",ios::in); 
//	dscthd.docFileCTHD(filein); 
//	filein.close();   	
//	dscthd.duyetCTHD(); 
//	cout << endl << "so luong node : " << dscthd.soLuongCTHD(); 
//	
//	// them vao 
//	CThoaDon cthd6("VT06",1,1,1); 
// 	CThoaDon cthd7("VT07",1,1,1); 
//	dscthd.themVaoCuoiCTHD(cthd6); 
//	dscthd.themVaoCuoiCTHD(cthd7); 
//	
//	ofstream fileout; 
//  	fileout.open("data/dataCTHD.txt",ios::out | ios::trunc);
//  	dscthd.ghiFileCTHD(fileout); 
//  	fileout.close(); 
	
	// khai bao 1 danh sach nhan vien 
//	dsNhanVien ds;
//	// tao them ra nhan vien
//	NhanVien NV01("NV01","duc","nguyen",1); 
//	NhanVien NV02("NV02","duc","nguyen",1); 
//	NhanVien NV03("NV03","duc","nguyen",1); 
//	NhanVien NV04("NV04","duc","nguyen",1); 
//	NhanVien NV05("NV05","duc","nguyen",1); 
//	
//	// goi toi ham them 
//	ds.themNV(NV01);
//	ds.themNV(NV02);
//	ds.themNV(NV03);
//	ds.themNV(NV04);
//	ds.themNV(NV05);
//	
//	// duyet code
//	ds.duyetDSNV(); 
//	
//	// tim kiem 
//	int viTri = ds.timKiemNV("NV06"); 
//	if ( viTri != -1 ) {
//		cout << "co tim thay va tai vi tri : " << viTri << endl;
//	}
//	else {
//		 cout <<endl<< "khong tim thay!"; 
//	}
//	cout << endl << "xoa nv02" << endl; 
//	if (ds.xoaNV("NV01")) {
//		cout << "xoa thanh cong" << endl;
//		ds.duyetDSNV(); 
//	}
// 	else {
//	 	cout << "xoa that bai!"; 
//	 }
//	 
//	 cout << endl << "them nhan vien vao : "<< endl; 
//	 NhanVien NV06("NV06","duc","nguyen",1);
//	 if (ds.themNV(NV06)) {
//	 	cout << endl << "them thanh cong" << endl; 
//	 	ds.duyetDSNV(); 
//	 } 
//	 cout << "so luong nhan vien :" << ds.soLuongNV(); 

	// thu nghiem voi hoa don 
	
	// thu nghiem them vai hoaDon Xem sao 
	Date date(1,2,3); 
	
//	HoaDon hd1("HD01",date,"X");
	HoaDon hd2("HD02",date,"X");
	HoaDon hd3("HD03",date,"N");
	HoaDon hd4("HD04",date,"X");
	HoaDon hd5("HD05",date,"N"); 
	
	
	ListHoaDon hd; 
	
	
//	hd.themVaoCuoiHD(hd1); 
//	hd.themVaoCuoiHD(hd2); 
//	hd.themVaoCuoiHD(hd3); 
//	hd.themVaoCuoiHD(hd4); 
//	hd.themVaoCuoiHD(hd5); 

//	ifstream filein; 
//	filein.open("data/dataHoaDon.txt",ios_base::in); 
//	
//	hd.docFileHoaDon(filein); 
//	
//	filein.close(); 
//	
//	hd.duyetDSHD(); 

	Date test(0,0,0); 
	HoaDon hd1("1",test,"X"); 
// them chi tiet hoa don vao hoa don 	

	
	// thuc hien ham xoa
	// them vao chi tiet hoa don 
	 CThoaDon ct1("VT01",1,1,1); 
	 CThoaDon ct2("VT02",2,2,2); 
	 
	 
	  
	 hd1.dsCTHD.themVaoCuoiCTHD(ct1); 
	 
	 hd1.dsCTHD.themVaoCuoiCTHD(ct2); 
	 
	
   
     hd.themVaoCuoiHD(hd1); 
	
     
	 
	hd.duyetDSHD(); 

	return 0;
}
