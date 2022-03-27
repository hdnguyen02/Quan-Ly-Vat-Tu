using namespace std;
#include "autoLoad.h" 






int main(int argc, char *argv[])
{
	 
	
	VatTu vt1("VT05","vat tu 5","kg",100); 
	VatTu vt2("VT02","vat tu 2","kg",100); 
 	VatTu vt3("VT07","vat tu 7","kg",100); 
 	VatTu vt4("VT01","vat tu 1","kg",100); 
 	VatTu vt5("VT08","vat tu 8","kg",100);
 	VatTu vt6("VT03","vat tu 8","kg",100);
 	VatTu vt7("VT06","vat tu 8","kg",100);
//	 // thuc hien insert vao 
//	// tao ra 1 cay 
	BstVatTu dsVatTu; 
	dsVatTu.themVT(vt1);
	dsVatTu.themVT(vt2); 
	dsVatTu.themVT(vt3); 
	dsVatTu.themVT(vt4); 
	dsVatTu.themVT(vt5);
	dsVatTu.themVT(vt6); 
	dsVatTu.themVT(vt7); 
	
	
	
	dsVatTu.duyetCay(); 
	
	cout << "sau khi xoa di root goc : " << endl; 
	dsVatTu.xoaVT("VT05");  
	dsVatTu.duyetCay(); 


	//menuQuanLyVatTu(); 
	 
	 
	// getch();   
	system("pause"); 
	
	return 0;
}
