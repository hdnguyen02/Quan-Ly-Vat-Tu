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



// viet ham tim Kiem pivot

// viet ham hoanDoi 
void hoanDoiVatTu(VatTu* &vti,VatTu* &vtj) {
	VatTu* pTemp = vti;
	vti = vtj; 
	vtj = pTemp;  // thanh cong!
}

// viet 1 vai truong so sanh 
bool soSanhTheoTen(VatTu* vt1,VatTu* vt2) {
	if (vt1->ten < vt2->ten) {
		return true;
	}
	return false; 
}

int partition(VatTu** arrVT,int low,int high,bool(*khoaSapXep)(VatTu*,VatTu*)) {
	VatTu* pivot = arrVT[high];   // chon pivot lam phan tu cuoi cung ! 
	int i = ( low - 1 ); // khoi tao vi tri -> luc nay la -1 neu la lan dau -> de ti vao ++ 
	for (int j = low; j < high - 1 ;j++) { // lan l'
		if (khoaSapXep(arrVT[j],pivot)) {  // dua vao khoa ma tuy co sap Xep!
			i++;
			hoanDoiVatTu(arrVT[i],arrVT[j]);  
		
		}
	}
	hoanDoiVatTu(arrVT[i + 1],arrVT[high]);  
	return (i + 1); 
}

// viet ham quicksort 
void quickSort(VatTu** arrVT,int low,int high,bool(*khoaSoSanh)(VatTu*,VatTu*)) {
	if (low < high) {
		int pi = partition(arrVT,low,high,khoaSoSanh);
		quickSort(arrVT,low,pi-1,khoaSoSanh);
		quickSort(arrVT,pi + 1,high,khoaSoSanh);
	}
}

int main(int argc, char *argv[]) {
	StartBGI start; 
	dsNhanVien DSNV;  
	DSNV.docFileDSNV("data/dataNhanVien.txt"); 
	BstVatTu dsVatTu; 
	menuQuanLyVatTu(dsVatTu,DSNV); 	
	
 	DSNV.giaiPhongDSNV(); 

// kiem nghiem thuat toan ! 


	


	system("pause"); 




    
	return 0;
}



