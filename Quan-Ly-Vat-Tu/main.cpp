#include "MenuQLVT.h"
using namespace std;



int main(int argc, char *argv[])
{
	StartBGI start;
	dsNhanVien DSNV;
	DSNV.docFileDSNV();
	BstVatTu dsVatTu;
	menuQuanLyVatTu(dsVatTu, DSNV);
	DSNV.giaiPhongDSNV();
	return 0;
}
