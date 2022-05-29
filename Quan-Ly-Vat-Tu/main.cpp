#include "MenuQLVT.h"

#include <math.h> 
#include <iomanip>

using namespace std;



int main(int argc, char *argv[])
{
	StartBGI start;
	DsNhanVien DSNV;
	DSNV.docFileDSNV();
	BstVatTu dsVatTu;
	menuQuanLyVatTu(dsVatTu, DSNV);
	DSNV.giaiPhongDSNV(); 
}; 




