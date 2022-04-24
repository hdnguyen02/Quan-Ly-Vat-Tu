#include "MenuQLVT.h"
using namespace std;

 
void themHoaDon(ListHoaDon &DSHD) {	
			string soHD,loai; 
			Date date; 
			cout << "nhap vao so HD: "; 
			getline(cin,soHD); 
			cout <<"nhap vao loai HD: "; 
			getline(cin,loai);
			date.nhap(); 
			NodeHoaDon* newHoaDon = DSHD.themVaoCuoiHD(soHD,date,loai);  // da tu NEW RA. 
			while(true) {
				cout << endl << "1.nhap vao CTHD" << endl; 
				cout << "2.Ket thuc" << endl;
				int lc1; 
				cout << "nhap vao lc: "; cin >> lc1; cin.ignore(); 
				if (lc1 == 1) {
					CThoaDon temp; 
					cout << "nhap vao maVT: "; 
					getline(cin,temp.maVT); 
					cout << "nhap vao so luong don gia VAT: "; 
					cin >> temp.donGia >> temp.soLuong >> temp.VAT; 
					newHoaDon->themCTHD(temp); 
					
					
					// ghi lai file vi co them hoaDon moi.
					
				}
				else if (lc1 == 2) {
					break; 
				}
			} 
}
 
void nhapNV() {
	dsNhanVien DSNV; 
	while(true) {
		system("cls"); 
		cout << "1.Nhap nhan vien" << endl; 
		cout <<"2.Xuat ds nhan vien" << endl; 
		cout << "3.Them hoa don vao nhan vien" << endl; 
		cout <<"4.Xuat hoa don do nv nhap vao" << endl; 
		cout << "5.ket thuc" << endl;
		
		int lc; cout << "nhap vao lua chon : ";  
		cin >> lc; 
		cin.ignore();
		if (lc == 1) {
			string maNV,ho,ten; 
			int phai = 0 ;
			cout << endl << "nhap vao maNV: "; 
			getline(cin,maNV); 
			cout << "nhap vao ho: ";
			getline(cin,ho); 
			cout << "nhap vao ten : "; 
			getline(cin,ten); 
			DSNV.themNV(maNV,ho,ten,phai); 
		}
		else if (lc == 2) {
			cout << endl << "ds nhan vien: " << endl; 
			DSNV.duyetDSNV(); 
			system("pause"); 
		}
		else if (lc == 3) {
			system("cls"); 
			cout << "nhap vao ma nv can lap hoa don: "; 
			string temp; 
			getline(cin,temp); 
			NhanVien* tempNV = DSNV.timKiemNVTraVeDiaChi(temp);  // tim Kiem. 
			if (tempNV) {
				themHoaDon(tempNV->dsHoaDon);
			}
			else {
				cout << endl << "khong ton tai nhan vien nay!"; 
				
			}
			
		}
		
		else if (lc == 4) {
			string soNV;
			
			cout << "nhap vao soNV: "; 
			getline(cin,soNV); 
			NhanVien* tempNV = DSNV.timKiemNVTraVeDiaChi(soNV); 
			if (tempNV) { 
				tempNV->dsHoaDon.duyetDSHD(); 
			}
			else {
				 cout << endl << "khong ton tai nhan vien nay!"; 
			}	
			system("pause"); 
		}	
		else if (lc == 5) {
			break; 
		}
	}
}

// viet 1 ham con tro ham 
// chi in ra thoi




int main(int argc, char *argv[]) {
//	StartBGI start; 
//	dsNhanVien DSNV;  
//	DSNV.docFileDSNV("data/dataNhanVien.txt"); 
//	BstVatTu dsVatTu; 
//	menuQuanLyVatTu(dsVatTu,DSNV); 	
//	
//	
//	
//	
//	
// DSNV.giaiPhongDSNV(); 


// thu nghiem voi thuat toan so sanh => xu dung con tro chuoc de co the so sanh -> lua chon quickSort 
// viet ham so sanh lay ra 
BstVatTu dsVatTu; 
// tiep theo la doc file => doc file ne 
// khai bao ra 1 mang chua info 
int soLuongVT = dsVatTu.soLuongVT();  
// khai bao 1 mang 
VatTu** arrVT = new VatTu*[soLuongVT];
dsVatTu.BstVatTuToArray(arrVT,0); 

// lap qua 
for (int i = 0; i < soLuongVT;i++) {
	arrVT[i]->inVatTu(); 
	cout << endl;
}










    
	return 0;
}



