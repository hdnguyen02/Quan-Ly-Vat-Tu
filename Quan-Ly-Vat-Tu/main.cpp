#include "MenuQLVT.h"
using namespace std;


 // viet ham them hoa Don vao ds 
void themHoaDon() {
	ListHoaDon DSHD; 
	while(true) {
		system("cls"); 
		cout << "1.Nhap hoa don" << endl; 
		cout <<"2.Xuat hoa don" << endl; 
		int lc; cout << "nhap vao lua chon : "; 
		cin >> lc; 
		cin.ignore(); 
		if (lc == 1) {
			// neu da nhap vao hoaDon thi ta se kiem tra tinh dung dang => neu dung thi new ra 
			string soHD,loai; 
			Date date; 
			cout << "nhap vao so HD: "; 
			getline(cin,soHD); 
			cout <<"nhap vao loai HD: "; 
			getline(cin,loai); 
			// nhap vao CTHD 
			NodeHoaDon* newHoaDon = new NodeHoaDon; 
			newHoaDon->setinfo(soHD,date,loai); 
			while(true) {
				cout << endl << "1.nhap vao CTHD" << endl; 
				cout << "2.Ket thuc" << endl;
				int lc1; 
				cout << "nhap vao lc: "; cin >> lc1; cin.ignore(); 
				if (lc1 == 1) {
					// tao ra 1 thang CTHD 
					CThoaDon temp; 
					// nhap vaoCTHD
					cout << "nhap vao maVT: "; 
					getline(cin,temp.maVT); 
					cout << "nhap vao so luong don gia VAT: "; 
					cin >> temp.donGia >> temp.soLuong >> temp.VAT; 
					// them thang hoa Don nay Vao 
					newHoaDon->themCTHD(temp); 
				}
				else if (lc1 == 2) {
					break; 
				}
			} 
			// them thang Node này vao 
			DSHD.themHD(newHoaDon); 
			
		}
		else if (lc == 2) {
			// xuat ra dsHD 
			
			DSHD.duyetDSHD(); 
			system("pause"); 
		}
	}
}


// viet ham nhapHD cho nhan Vien


int main(int argc, char *argv[]) {

	return 0;
}
