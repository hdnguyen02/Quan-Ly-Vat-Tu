#include "MenuQLVT.h"
using namespace std;

// viet ham nhap vao hoa don 


void nhapHoaDon() {
	ListHoaDon dsHoaDon; 
	while(true) {
		system("cls"); 
		cout << "1.Nhap vao hoa don" << endl; 
		cout << "2.in hoa don" << endl; 
		
		int lc; 
		cout << "nhap vao lc: "; 
		cin >> lc ; 
		cin.ignore(); 
		if (lc == 1 ) {
			// tao ra 1 hoaDon 
			HoaDon temp;  // daTao Ra HoaDon. 
			// nhap vao chi tiet hoaDon 
			system("cls"); 
			cout << "nhap vao ma HD: "; 
			getline(cin,temp.soHD); 
			cout << "nhap vao ngay lap HD : " << endl; 
			temp.date.nhap(); 
			cout << "nhap vao loai hoa don : "; 
			getline(cin,temp.loai); 
			// sau khi nhap song nhap toi chi tiet hoa Don 
			int sublc; 
			while(true) {
				cout << "1.Nhap vao chi tiet hoa don"<< endl; 
				cout <<"2.Thoat"; 
				cout << "nhap vap lc: "; 
				cin >> sublc ; 
				cin.ignore(); 
				if (sublc == 1) {
					// tao ra 1 cthd 
					CThoaDon cthd; 
					// nhap vao chi tiet hoa don nay  
					cout << "nhap vao maVT: "; 
					getline(cin,cthd.maVT); 
					cout << "nhap vao so luong : "; 
					cin >> cthd.soLuong; 
					cout << "nhap vao don gia: "; 
					cin >> cthd.donGia; 
					cout << "nhap vao VAT: "; 
					cin >> cthd.VAT; 
					// tiep tuc in ra 
					cin.ignore(); 
					// sau khi nhap song them no vao CTHD 
					temp.dsCTHD->themVaoCuoiCTHD(cthd); 	
				}
				else if (sublc == 2) {
					break; 
				}
			}
			
			// sau khi nhap song => them hoaDon vao trong dsHoaDon 
			
			dsHoaDon.themVaoCuoiHD(temp); 
			
			
		}
		else if (lc == 2) {
			// in ra chi tiet hoa Don 
			dsHoaDon.duyetDSHD(); 
			system("pause"); 
		}
		else if (lc == 3) {
			break; 
		}
	}
}


int main(int argc, char *argv[]) {
	
	// khai bao ra 1 chi tiet hoa don 
//	ListCTHD cthd;
//	ifstream filein; 
//	filein.open("data/dataCTHD.txt",ios::in); 
//	cthd.docFileCTHD(filein); 
//	filein.close(); 
//	Date date(1,1,1); 
//	HoaDon hd("hd1",date,"X",cthd); // da tro vao 
//	
//	// sau do ta tao ra 1 dsCTHD 
//	ListHoaDon listHD; 
//	listHD.themVaoDauHD(hd); 
//	listHD.duyetDSHD(); 
//	
//	// chang han nhu bay gio cai hoa don Do muon them hoa don di thi phai lam sao 
//	// tao ra 1 hoa Don tam 
//	
//	CThoaDon temp("duc nguyen",1,1,1); 
//	// tiep tuc them vao tk hd
//	hd.dsCTHD->themVaoDauCTHD(temp); 
//	cout << endl << "thuc hien duyet cthd thong qua hd" << endl; 
//	hd.inHD(); 
//	cout << endl << "thuc hien duyet cthd thong qua danh hd" << endl; 
//	listHD.duyetDSHD(); 
//	
//	cout <<endl << "them vao 1 hoa don nua" << endl; 
	
	
//	ListCTHD cthd1;
//	ifstream filein1; 
//	filein1.open("data/CTHD1.txt",ios::in); 
//	cthd1.docFileCTHD(filein1); 
//	filein1.close();
//	// khoi tao 1 tk hoaDon 
//	HoaDon hd1("hd2",date,"L",cthd1); 
//	
//	listHD.themVaoCuoiHD(hd1); 
//	listHD.duyetDSHD(); 
	
	
	nhapHoaDon(); 
	
	
	
	
	
	
	
	
	
	
	
	
	
	
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
//	  cin.ignore(); 
//	  
//	  if (lc == 1) {
//	  			system("cls");
//				string soHD,loai; 
//				Date date;
//				cout << "\nNhap vao so hoa don : ";
//				getline(cin,soHD); 
//				date.nhap(); 
//				cout << "\nNhap vao loai hoa don : "; 
//				getline(cin,loai); 
//				system("cls"); 
//				cout << endl << "thong tin hoa don" << endl;
//				cout << "so hoa don: " << soHD << endl; 
//				cout << "loai hoa don: " << loai  << endl; 
//				cout << "ngay lap hoa don: "; 
//				date.hienThiConsole(); 
//				ListCTHD cthd; 
//				
//				// ================== NHAP CTHD ===================
//				
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
//						cthd.themVaoCuoiCTHD(cthdTemp);  
//					}
//					else if (lc11 == 2) {  // NGUNG VIEC CHI TIET HOA DON. 
//						HoaDon temp(soHD,date,loai,cthd);  
//						dshd.themVaoCuoiHD(temp); 
//						cout << endl << "hoa don vua nhap la" << endl; 
//						dshd.duyetDSHD(); 
//						system("pause"); 
//						break; 
//					}		 
//				}	
//			}  
//		  else if (lc == 2) {
//			dshd.duyetDSHD(); 
//			system("pause"); 
//		  }
//		  else if (lc == 4) {   // NGUNG
//		  	break; 
//		  }
//	  
//	}
//

   
// khai bao new ra 1 Node 

// khai bao ra 1 tk hoaDon 


 
  
	
	
	 
   

	return 0;
}
