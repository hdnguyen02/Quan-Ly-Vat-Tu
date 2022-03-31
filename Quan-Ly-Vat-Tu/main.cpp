using namespace std;
#include "autoLoad.h" 

int main(int argc, char *argv[])
{
	
	BstVatTu dsVatTu;  
	VatTu vt1("VT05","ho duc nguyen","kg",100); 
	VatTu vt2("VT02","vat tu 2","kg",100); 
 	VatTu vt3("VT07","vat tu 3","kg",100); 
 	VatTu vt4("VT01","vat tu 4","kg",100); 
 	VatTu vt5("VT08","vat tu 5","kg",100);
 	VatTu vt6("VT03","vat tu 6","kg",100);
 	VatTu vt7("VT04","vat tu 7","kg",100);
	VatTu vt8("VT012","vat tu 8","kg",100);
	VatTu vt9("VT00","vat tu 9","kg",100);
	VatTu vt10("VT06","vat tu a","kg",100);

	dsVatTu.themVT(vt1);
	dsVatTu.themVT(vt2); 
	dsVatTu.themVT(vt3); 
	dsVatTu.themVT(vt4); 
	dsVatTu.themVT(vt5);
	dsVatTu.themVT(vt6); 
	dsVatTu.themVT(vt7); 
	dsVatTu.themVT(vt8); 
	dsVatTu.themVT(vt9); 
	dsVatTu.themVT(vt10); 
	
	StartBGI start; 
	menuQuanLyVatTu(dsVatTu);

	return 0;
}
