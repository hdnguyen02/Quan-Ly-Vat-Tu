#include "MenuQLVT.h"
using namespace std;


int main(int argc, char *argv[]) {
	
	// khai bao ra 1 chi tiet hoa don 
	ListCTHD cthd;
	ifstream filein; 
	filein.open("data/dataCTHD.txt",ios::in); 
	cthd.docFileCTHD(filein); 
	filein.close(); 
	Date date(1,1,1); 
	HoaDon hd("hd1",date,"X",cthd); // da tro vao 
	
	// sau do ta tao ra 1 dsCTHD 
	ListHoaDon listHD; 
	listHD.themVaoDauHD(hd); 
	listHD.duyetDSHD(); 
	
	// chang han nhu bay gio cai hoa don Do muon them hoa don di thi phai lam sao 
	// tao ra 1 hoa Don tam 
	
	CThoaDon temp("duc nguyen",1,1,1); 
	// tiep tuc them vao tk hd
	hd.dsCTHD->themVaoDauCTHD(temp); 
	cout << endl << "thuc hien duyet cthd thong qua hd" << endl; 
	hd.inHD(); 
	cout << endl << "thuc hien duyet cthd thong qua danh hd" << endl; 
	listHD.duyetDSHD(); 
	
	cout <<endl << "them vao 1 hoa don nua" << endl; 
	
	
	ListCTHD cthd1;
	ifstream filein1; 
	filein1.open("data/CTHD1.txt",ios::in); 
	cthd1.docFileCTHD(filein1); 
	filein1.close();
	// khoi tao 1 tk hoaDon 
	HoaDon hd1("hd2",date,"L",cthd1); 
	
	listHD.themVaoCuoiHD(hd1); 
	listHD.duyetDSHD(); 
	
	
	
	// viet chuong trinh nhap 1 dsct hoa don 
//	ListHoaDon dshd; // danh sach hoa don. 
//	// trong moi hoa don lai co 1 chi tiet hoa don. 
//	int lc;
//	while(true) {
//	  system("cls"); 
//	  cout << "1.Nhap hoa don" << endl; 
//	  cout << "2.Xuat ds hoa don" << endl; 
//	  cout <<"3.Tim kiem hoa don" << endl; 
//	  cout <<"4.Xoa hoa don" << endl; 
//	  cout << "nhap vao lua chon : " ; 
//	  cin >> lc; 
//	  
//	  if (lc == 1) {
//	  	system("cls"); 
//	  	int lc1;
//	  	while(true) {
//	  		system("cls"); 
//		  	cout << "1.Nhap hoa don" << endl; 
//		  	cout << "2.Ket thuc" << endl; 
//		  	do {
//				cout << endl << "Nhap vao lua chon: "; 
//		  		cin >> lc1;
//		  		cin.ignore(); 
//			} while(lc1 != 1 && lc1 != 2); 
//			
//			string soHD,loai;
//			if (lc1 == 1) {  
//				string soHD,loai; 
//				Date date;
//				cout << "\nNhap vao so hoa don : ";
//				getline(cin,soHD); 
//				date.nhap(); 
//				cout << "\nNhap vao loai hoa don : "; 
//				getline(cin,loai); 
//				system("cls"); 
//				
//				cout << endl << "thong tin hoa don" << endl;
//				cout << "so hoa don: " << soHD << endl; 
//				cout << "loai hoa don: " << loai  << endl; 
//				cout << "ngay lap hoa don: "; 
//				date.hienThiConsole(); 
//				// nhap xuong toi day tuc la da thoa man roi => them vao 
//				ListCTHD cthd; 
//				HoaDon temp(soHD,date,loai,cthd);  // tao ra cthd. 
//				// them luon thang hoaDon nay vao dsHoaDon 
//				dshd.themVaoDauHD(temp); 
//				// ================== NHAP CTHD ===================
//				int lc11; 
//				while(true) {
//					cout <<endl <<  "1.Nhap vao chi tiet hoa don";
//					cout <<endl << "2.Thoat" <<endl; 
//					do {
//						cout << "nhap vao lua chon: "; 
//						cin >> lc11;
//						cin.ignore(); 
//					} while (lc11 != 1 && lc11 != 2);  
//					
//					
//					//  NHAP VAO CHI TIET HOA DON
//					if (lc11 == 1) {
//						// nhap vao cthd. 
//						CThoaDon cthdTemp; 
//						cout << "nhap vao maVT: "; 
//						getline(cin,cthdTemp.maVT);
//						cout << "nhapv so luong: "; 
//						cin >> cthdTemp.soLuong; 
//						cout << "nhap vao don gia: "; 
//						cin >> cthdTemp.donGia;
//						cout << "nhap vao VAT : "; 
//						cin >> cthdTemp.VAT; 
//						temp.dsCTHD->themVaoCuoiCTHD(cthdTemp);  
//					}
//					else if (lc11 == 2) {  // NGUNG VIEC CHI TIET HOA DON. 
//						cout << endl << "chi tiet hoa don 1" << endl; 
//						dshd.duyetDSHD(); 
//						system("pause"); 
//						break; 
//					}		 
//				}	
//			}  
//		  	else if (lc1 == 2) {   // NGUNG VIET LAP HOA DON. 
//			  	break; 
//			  }
//			   
//		  }
//	  }
//	  else if (lc == 2) {
//		dshd.duyetDSHD(); 
//		system("pause"); 
//	  }
//	  else if (lc == 4) {   // NGUNG
//	  	break; 
//	  }
//	  
//	}
//

   
	
	
	
	 
   

	return 0;
}
