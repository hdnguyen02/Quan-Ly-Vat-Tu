#include "MenuQLVT.h"
using namespace std;
#include <math.h> 
#include <iomanip>





int main(int argc, char *argv[])
{
	StartBGI start;
	DsNhanVien DSNV;
	DSNV.docFileDSNV();
	BstVatTu dsVatTu;
	menuQuanLyVatTu(dsVatTu, DSNV);
	DSNV.giaiPhongDSNV(); 
}; 




