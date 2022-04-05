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
  	

	return 0;
}
