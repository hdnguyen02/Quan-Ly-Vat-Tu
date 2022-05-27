#pragma once
using namespace std;
#include "Tienich.h"
#include "BienDoHoa.h"
#include "DoHoaHD.h"
#include "HamDoHoaVatTu.h"




void chinhSuaVT(BstVatTu &dsVatTu, VatTu *vatTuCT )
{
	// kiem tra xem thang vat tu co dang NULL khong 
	// bac try catch tai day -> de tranh truong hop app bi chet 

	OVuong themVT(margin + doDaiCoBan * 6 - 60, canLeTrenHD + 140 - 60 , margin + doDaiCoBan * 3 + 30, 400 + 60, 15);
	NutBam titleCSVT(margin + doDaiCoBan * 6 - 60, canLeTrenHD + 140 - 60, margin + doDaiCoBan * 3 + 30, 40, 15, 0, 0,"THONG TIN VAT TU");
	titleCSVT.veNut(); 
	ONhap nhapMaVT(margin + doDaiCoBan * 6  , canLeTrenHD + 140 + 30, doDaiCoBan * 3 - 20 - 10 , 40, 0, "", 0, 0, 10);
	ONhap nhapTenVT(margin + doDaiCoBan * 6 , canLeTrenHD + 234 + 30, doDaiCoBan * 3 - 20 - 10 , 40, 0, "", 0, 0, 25);
	ONhap nhapSoLuong(margin + doDaiCoBan * 6 , canLeTrenHD + 328 + 30, doDaiCoBan * 3 -20 - 10 , 40, 0, "", 0, 0, 7);
	ONhap nhapDVT(margin + doDaiCoBan * 6 , canLeTrenHD + 170 + 50 + 70 * 2 + 60 + 32, doDaiCoBan * 3 - 20 - 10 , 40, 0, "", 0, 0, 15);
	nhapMaVT.boNhoDem = vatTuCT->maVT; // lay ra maVT
	nhapTenVT.boNhoDem = vatTuCT->ten;
	nhapSoLuong.boNhoDem = TienichDoHoa::floatToString(vatTuCT->soLuongTon);
	nhapDVT.boNhoDem = vatTuCT->donVi;

	string tenVTCu = vatTuCT->ten;
	string dvtCu = vatTuCT->donVi;
	nhapMaVT.khongDuocNhap = true;
	nhapSoLuong.khongDuocNhap = true;
	

	nhapMaVT.veONhap();
	nhapTenVT.veONhap();
	nhapSoLuong.veONhap();
	nhapDVT.veONhap();

	nhapMaVT.inNoiDung();
	nhapTenVT.inNoiDung();
	nhapSoLuong.inNoiDung();
	nhapDVT.inNoiDung();
	


	NutBam saveVT(margin + doDaiCoBan * 6 - 60, canLeTrenHD +500 + 26, margin + doDaiCoBan * 3 + 30, 40, 0, 2,0, "");
	NutBam xoa(margin + doDaiCoBan * 6 - 60, canLeTrenHD +500 + 26, (margin + doDaiCoBan * 3 + 30) / 2 - 2, 40, 15, 2, 1, "XOA");
	NutBam hieuChinh(margin + doDaiCoBan * 6 - 60 + (margin + doDaiCoBan * 3 + 30) / 2 + 2, canLeTrenHD +500 + 26, (margin + doDaiCoBan * 3 + 30) / 2, 40, 15, 2, 1, "HIEU CHINH");
		
	
	saveVT.veNut();
	xoa.veNut();
	hieuChinh.veNut();

	NutBam thoat(margin + doDaiCoBan * 6 - 60 + (margin + doDaiCoBan * 3 + 30 - 40), canLeTrenHD + 140 - 60, 40, 40, 4, 0, 15, "X");
	thoat.veNut();
	int xclick = -1;
	int yclick = -1;
	while (true)
	{
		if (ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_LBUTTONDOWN, xclick, yclick);
			if (nhapTenVT.isMouseHover(xclick, yclick))
			{
				nhapTenVT.NhapVao(kiTuChuHoacSo, "");
				nhapTenVT.chuanHoa(); 
			}
			else if (nhapDVT.isMouseHover(xclick, yclick))
			{
				nhapDVT.NhapVao(kiTuChu, "");
				nhapDVT.chuanHoa(); 
			}
			else if (hieuChinh.isMouseHover(xclick, yclick))
			{ // nhap vao !
				if (nhapTenVT.boNhoDem == "" || nhapDVT.boNhoDem == "")
				{
					MessageBox(NULL, "Khong Duoc Bo Trong!", "Thong Bao", MB_ICONINFORMATION | MB_OK);
				}
				else if (nhapTenVT.boNhoDem != tenVTCu || nhapDVT.boNhoDem != dvtCu)
				{ 
					vatTuCT->ten = nhapTenVT.boNhoDem;
					vatTuCT->donVi = nhapDVT.boNhoDem;
					MessageBox(NULL, "Hieu Chinh Thanh Cong!", "Thong Bao", MB_ICONINFORMATION | MB_OK);
					break;
				}
			}

			else if (thoat.isMouseHover(xclick, yclick))
			{
				break;
			}
			else if (xoa.isMouseHover(xclick, yclick))
			{
				if (nhapTenVT.boNhoDem == tenVTCu && nhapDVT.boNhoDem == dvtCu)
				{
					
					bool checkKiemTra = vatTuCT->soLanTaoCTHD == 0 ? true : false; 
					if (checkKiemTra == false)
					{
						MessageBox(NULL, "Khong Duoc Phep Xoa Vat Tu da duoc lap CTHD!", "Thong Bao", MB_ICONINFORMATION | MB_OK);
					}
					else {
						int luaChon = MessageBox(NULL, "ban co chac chac muon xoa!", "thong bao", MB_ICONWARNING | MB_OKCANCEL);
						if (luaChon == OK)
						{
								dsVatTu.xoaVT(nhapMaVT.boNhoDem); 
								dsVatTu.ghiFileVatTu();
								break;
						}
					}
					
				}
			}
		}
		delay(1);
	}

	
}

// viet 1 cai ham hien thi table khi can them vat tu vao 
void tableThemVT() {
	// truoc khi ve can xoa di man hinh chuoi no se ve len 
	TienichDoHoa::xoaManHinhTheoToaDo(margin + doDaiCoBan * 6 - 60, canLeTrenHD + 140 - 60 , margin + doDaiCoBan * 3 + 30, 400 + 60,BACKGROUP); 
	OVuong themVT(margin + doDaiCoBan * 6 - 60, canLeTrenHD + 140 - 60 , margin + doDaiCoBan * 3 + 30, 400 + 60, 15);
	NutBam titleThemVT(margin + doDaiCoBan * 6 - 60, canLeTrenHD + 140 - 60, margin + doDaiCoBan * 3 + 30, 40, 15, 0, 0, "THEM VAT TU");
	TienichDoHoa::setText(0,15,10,1); 
	outtextxy(margin + doDaiCoBan * 6 ,canLeTrenHD + 140,"Ma Vat Tu");
	outtextxy(margin + doDaiCoBan * 6 ,canLeTrenHD + 234,"Ten Vat Tu");
	outtextxy(margin + doDaiCoBan * 6 ,canLeTrenHD + 328,"So Luong Ton");
	outtextxy(margin + doDaiCoBan * 6 ,canLeTrenHD + 170 + 50 + 70 * 2 + 20 + 42,"Don Vi Tinh"); 
	
	ONhap nhapMaVT(margin + doDaiCoBan * 6  , canLeTrenHD + 140 + 30, doDaiCoBan * 3 - 20 - 10 , 40, 0, "", 0, 0, 10);
	ONhap nhapTenVT(margin + doDaiCoBan * 6 , canLeTrenHD + 234 + 30, doDaiCoBan * 3 - 20 - 10 , 40, 0, "", 0, 0, 25);
	ONhap nhapSoLuong(margin + doDaiCoBan * 6 , canLeTrenHD + 328 + 30, doDaiCoBan * 3 -20 - 10 , 40, 0, "", 0, 0, 10);
	ONhap nhapDVT(margin + doDaiCoBan * 6 , canLeTrenHD + 170 + 50 + 70 * 2 + 60 + 32, doDaiCoBan * 3 - 20 - 10 , 40, 0, "", 0, 0, 15);
	
	titleThemVT.veNut();
	nhapMaVT.veONhap();
	nhapTenVT.veONhap();
	nhapSoLuong.veONhap();
	nhapDVT.veONhap();
	NutBam saveVT(margin + doDaiCoBan * 6 - 60, canLeTrenHD +500 + 26, margin + doDaiCoBan * 3 + 30 + 1, 40, 15, 2,0, "LUU VAT TU");
	saveVT.veNut();
}


// viet ham hien thi nut bam vat tu -> tuy theo so luong vat tu ma se ve ra cac nut tuong ung 


// viet them 1 ham xoa di cac nut


void veNutHieuChinhVatTu(int x,int y,int w,int h,int khoanCach,int soLuongHieuChinh) {
	NutBam *hieuChinh = new NutBam[soLuongHieuChinh];  
	TienichDoHoa::xoaManHinhTheoToaDo(58 + 730,170,80,500 + 40,BACKGROUP);
	for (int i = 0; i < soLuongHieuChinh;i++) {
		hieuChinh[i].set(x,y + i*khoanCach,w,h,11,3,0,"Sua"); 
		hieuChinh[i].veNut(); 
	}
	delete []hieuChinh; 
}




void hienThiTinhNangVatTu(BstVatTu &dsVatTu, int &index, NutBam &nhanVien, NutBam &hoaDon, NutBam &doanhThu, bool (*khoaSapXep)(VatTu *, VatTu *))
{
	int indexPage = 0;
	int soLuongPhanTuHienThi = 0;
	int itemTrenMotPage = 11;
	int toaDoChiMucX = DODAIMANHINH / 2 - 110;
	int toaDoChiMucY = 720;
	int soLuongVatTuTrenTable = 0; // chua so luongVT hien thi tren page hienTai !
	int soLuongVT = dsVatTu.soLuongVT();
	VatTu **arrVT = new VatTu *[soLuongVT];
	NodeVatTu *tempVT;
	dsVatTu.BstVatTuToArray(arrVT, 0);
	float toiDaPage= TienichDoHoa::tinhToiDaPage(soLuongVT,itemTrenMotPage); 
	bool theoMa = true; 
	bool nhapVaoChinhSua = false; 
	int indexVatTuChinhSua = -1; 
	
	int toaDoXTable = 58; 
	int toaDoYTable = 170; 
	int chieuCaoTable = 500; 
	int mauNenTable = 0; 
	

	TienichDoHoa::xoaManHinhTheoToaDo(0, 60, 1600, 1600, BACKGROUP);
	
	
	ONhap searchVT(margin + doDaiCoBan* 6 + 94 + 100,94,300,40,0,"",0,0,25,13);

	searchVT.veONhap();


	
	
	OVuong themVT(margin + doDaiCoBan * 6 - 60, canLeTrenHD + 140 - 60 , margin + doDaiCoBan * 3 + 30, 400 + 60, 15);
	NutBam titleThemVT(margin + doDaiCoBan * 6 - 60, canLeTrenHD + 140 - 60, margin + doDaiCoBan * 3 + 30, 40, 15, 0, 0, "THEM VAT TU");
	
	TienichDoHoa::setText(BACKGROUP,10,10,1); 
	outtextxy(margin + doDaiCoBan* 6 - 60 ,102,"TIM KIEM (THEO TEN)"); 
	setcolor(3); 
	outtextxy(margin + doDaiCoBan * 6 ,canLeTrenHD + 140,"Ma Vat Tu");
	outtextxy(margin + doDaiCoBan * 6 ,canLeTrenHD + 234,"Ten Vat Tu");
	outtextxy(margin + doDaiCoBan * 6 ,canLeTrenHD + 328,"So Luong Ton");
	outtextxy(margin + doDaiCoBan * 6 ,canLeTrenHD + 170 + 50 + 70 * 2 + 20 + 42,"Don Vi Tinh"); 
	
	
	ONhap nhapMaVT(margin + doDaiCoBan * 6  , canLeTrenHD + 140 + 30, doDaiCoBan * 3 - 20 - 10 , 40, 0, "", 0, 0, 10);
	ONhap nhapTenVT(margin + doDaiCoBan * 6 , canLeTrenHD + 234 + 30, doDaiCoBan * 3 - 20 - 10 , 40, 0, "", 0, 0, 25);
	ONhap nhapSoLuong(margin + doDaiCoBan * 6 , canLeTrenHD + 328 + 30, doDaiCoBan * 3 -20 - 10 , 40, 0, "", 0, 0, 7);
	ONhap nhapDVT(margin + doDaiCoBan * 6 , canLeTrenHD + 170 + 50 + 70 * 2 + 60 + 32, doDaiCoBan * 3 - 20 - 10 , 40, 0, "", 0, 0, 15);
	
	
	
	titleThemVT.veNut();
	nhapMaVT.veONhap();
	nhapTenVT.veONhap();
	nhapSoLuong.veONhap();
	nhapDVT.veONhap();
	NutBam saveVT(margin + doDaiCoBan * 6 - 60, canLeTrenHD +500 + 26, margin + doDaiCoBan * 3 + 30 + 1, 40, 15, 2,0, "LUU VAT TU");
	saveVT.veNut();

	NutBam btnLui(margin, 730, 100, 40, 14, 0, 1, "<<");
	NutBam btnTien(margin + 622, 730, 100, 40, 14, 0, 1, ">>");
	btnLui.veNut();
	btnTien.veNut();

	// ve them 2 3 cuc sap xep theo
	setcolor(CinputText);
	setbkcolor(0);
	settextstyle(6, 0, 1);
	TienichDoHoa::setText(BACKGROUP,10,10,1); 
	outtextxy(59, 106, "SAP XEP THEO: ");

	NutBam theoTen(62 + 160 + 40, 96, 100, 40, 11, 13, 0, "Ten");
	NutBam theoMaVT(62 + 160 + 120 + 40, 96, 100, 40, 11, 13, 0, "Ma");
	NutBam theoDVT(62 + 160 + 120 * 2 + 40, 96, 100, 40, 11, 13, 0, "DVT");
	NutBam theoSLT(62 + 160 + 120 * 3 + 40, 96, 100, 40, 11, 13, 0, "SL");
	theoTen.duocTroVao = true;

	theoSLT.veNut();
	theoTen.veNut();
	theoMaVT.veNut();
	theoDVT.veNut();
	dsVatTu.insertionSort(arrVT, soLuongVT, khoaSapXep);
	int marginTop = canLeTrenHD + 170 - 70;

	soLuongVatTuTrenTable = hienThiDuLieuVatTu(toaDoXTable,toaDoYTable,chieuCaoTable,mauNenTable,indexPage,itemTrenMotPage,arrVT,soLuongVT); 
	veNutHieuChinhVatTu(margin + 746,marginTop-4,60,28,46,soLuongVatTuTrenTable);  
	hienThiChiMuc(404, 740, indexPage, toiDaPage);
	
	int khoanCach = 46;
	NutBam hieuChinh1(margin + 746, marginTop + khoanCach * 0 - 4, 60, 28, 13, 0, 0, "sua");
	NutBam hieuChinh2(margin + 746, marginTop + khoanCach * 1 - 4, 60, 28, 13, 0, 0, "sua");
	NutBam hieuChinh3(margin + 746, marginTop + khoanCach * 2 - 4, 60, 28, 13, 0, 0, "sua");
	NutBam hieuChinh4(margin + 746, marginTop + khoanCach * 3 - 4, 60, 28, 13, 0, 0, "sua");
	NutBam hieuChinh5(margin + 746, marginTop + khoanCach * 4 - 4, 60, 28, 13, 0, 0, "sua");
	NutBam hieuChinh6(margin + 746, marginTop + khoanCach * 5 - 4, 60, 28, 13, 0, 0, "sua");
	NutBam hieuChinh7(margin + 746, marginTop + khoanCach * 6 - 4, 60, 28, 13, 0, 0, "sua");
	NutBam hieuChinh8(margin + 746, marginTop + khoanCach * 7 - 4, 60, 28, 13, 0, 0, "sua");
	NutBam hieuChinh9(margin + 746, marginTop + khoanCach * 8 - 4, 60, 28, 13, 0, 0, "sua");
	NutBam hieuChinh10(margin + 746, marginTop + khoanCach * 9 - 4, 60, 28, 13, 0, 0, "sua");
	NutBam hieuChinh11(margin + 746, marginTop + khoanCach * 10 - 4, 60, 28, 13, 0, 0, "sua");
	
	
	
	string tenVTCu = nhapTenVT.boNhoDem;
	string maVTCu = nhapMaVT.boNhoDem; 
	string dvtCu = nhapDVT.boNhoDem; 
	int xclick = -1;
	int yclick = -1;
	while (true)
	{
		if (ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_LBUTTONDOWN, xclick, yclick);
			if (btnTien.isMouseHover(xclick, yclick))
			{
				if (indexPage < toiDaPage - 1)
				{
					indexPage++; // nhay qua page khac !
					
					soLuongVatTuTrenTable = hienThiDuLieuVatTu(toaDoXTable,toaDoYTable,chieuCaoTable,mauNenTable,indexPage,itemTrenMotPage,arrVT,soLuongVT); 
					veNutHieuChinhVatTu(margin + 746,marginTop-4,60,28,46,soLuongVatTuTrenTable);  
					hienThiChiMuc(404, 740, indexPage, toiDaPage);
				}
			}
			else if (btnLui.isMouseHover(xclick, yclick))
			{
				if (indexPage > 0)
				{
					indexPage--;
					soLuongVatTuTrenTable = hienThiDuLieuVatTu(toaDoXTable,toaDoYTable,chieuCaoTable,mauNenTable,indexPage,itemTrenMotPage,arrVT,soLuongVT); 
					veNutHieuChinhVatTu(margin + 746,marginTop-4,60,28,46,soLuongVatTuTrenTable);  
					hienThiChiMuc(404, 740, indexPage, toiDaPage);
				}
			}
			else if (theoTen.isMouseHover(xclick, yclick))
			{
				theoTen.duocTroVao = true;
				theoTen.veNut();
				theoMaVT.duocTroVao = false;
				theoMaVT.veNut();
				theoSLT.duocTroVao = false;
				theoSLT.veNut();
				theoDVT.duocTroVao = false;
				theoDVT.veNut();
				dsVatTu.insertionSort(arrVT, soLuongVT, VatTu::soSanhTheoTen);
				soLuongVatTuTrenTable = hienThiDuLieuVatTu(toaDoXTable,toaDoYTable,chieuCaoTable,mauNenTable,indexPage,itemTrenMotPage,arrVT,soLuongVT); 
				veNutHieuChinhVatTu(margin + 746,marginTop-4,60,28,46,soLuongVatTuTrenTable);  
				hienThiChiMuc(404, 740, indexPage, toiDaPage);
			}
			else if (theoMaVT.isMouseHover(xclick, yclick))
			{
				theoMaVT.duocTroVao = true;
				theoMaVT.veNut();
				theoTen.duocTroVao = false;
				theoTen.veNut();
				theoSLT.duocTroVao = false;
				theoSLT.veNut();
				theoDVT.duocTroVao = false;
				theoDVT.veNut();
				dsVatTu.insertionSort(arrVT, soLuongVT, VatTu::soSanhTheoMaVT);
				soLuongVatTuTrenTable = hienThiDuLieuVatTu(toaDoXTable,toaDoYTable,chieuCaoTable,mauNenTable,indexPage,itemTrenMotPage,arrVT,soLuongVT); 
				veNutHieuChinhVatTu(margin + 746,marginTop-4,60,28,46,soLuongVatTuTrenTable);  
				hienThiChiMuc(404, 740, indexPage, toiDaPage);
			}
			else if (theoSLT.isMouseHover(xclick, yclick))
			{
				theoSLT.duocTroVao = true;
				theoSLT.veNut();
				theoTen.duocTroVao = false;
				theoTen.veNut();
				theoMaVT.duocTroVao = false;
				theoMaVT.veNut();
				theoDVT.duocTroVao = false;
				theoDVT.veNut();
				dsVatTu.insertionSort(arrVT, soLuongVT, VatTu::soSanhTheoSoLuongTon);
				soLuongVatTuTrenTable = hienThiDuLieuVatTu(toaDoXTable,toaDoYTable,chieuCaoTable,mauNenTable,indexPage,itemTrenMotPage,arrVT,soLuongVT); 
				veNutHieuChinhVatTu(margin + 746,marginTop-4,60,28,46,soLuongVatTuTrenTable);  
				hienThiChiMuc(404, 740, indexPage, toiDaPage);
			}
			else if (theoDVT.isMouseHover(xclick, yclick))
			{
				theoSLT.duocTroVao = false;
				theoSLT.veNut();
				theoTen.duocTroVao = false;
				theoTen.veNut();
				theoMaVT.duocTroVao = false;
				theoMaVT.veNut();
				theoDVT.duocTroVao = true;
				theoDVT.veNut();
				dsVatTu.insertionSort(arrVT, soLuongVT, VatTu::soSanhTheoDonViTinh);
				soLuongVatTuTrenTable = hienThiDuLieuVatTu(toaDoXTable,toaDoYTable,chieuCaoTable,mauNenTable,indexPage,itemTrenMotPage,arrVT,soLuongVT); 
				veNutHieuChinhVatTu(margin + 746,marginTop-4,60,28,46,soLuongVatTuTrenTable);  
				hienThiChiMuc(404, 740, indexPage, toiDaPage);
			}
			else if (nhapMaVT.isMouseHover(xclick, yclick))
			{
				nhapMaVT.NhapVao(nhapID, "Chi Nhap Chu,So va _ !"); // vi la nhap ma nen khong can chuan hoa
			}
			else if (nhapTenVT.isMouseHover(xclick, yclick))
			{
				nhapTenVT.NhapVao(kiTuChu, "Chi Nhap Chu!");
				if (nhapTenVT.boNhoDem != tenVTCu) {
					nhapTenVT.chuanHoa();
					tenVTCu = nhapTenVT.boNhoDem; 
				}
				
			}
			else if (nhapSoLuong.isMouseHover(xclick, yclick))
			{
				nhapSoLuong.nhapSoThuc("Chi Nhap So Thuc!"); 
			}
			else if (nhapDVT.isMouseHover(xclick, yclick))
			{
				nhapDVT.NhapVao(kiTuChu, "chi Nhap Chu!");
				if (nhapDVT.boNhoDem != dvtCu) {
					nhapDVT.chuanHoa();
					dvtCu = nhapDVT.boNhoDem; 
				}
				
			}
			else if (saveVT.isMouseHover(xclick, yclick))
			{
				
				if (nhapMaVT.boNhoDem == "" || nhapTenVT.boNhoDem == "" || nhapSoLuong.boNhoDem == "" || nhapDVT.boNhoDem == "")
				{
					MessageBox(NULL, "Khong Duoc Bo Trong!", "Thong Bao", MB_ICONINFORMATION | MB_OK);
				}
				else
				{
					if (dsVatTu.themVT(nhapMaVT.boNhoDem, nhapTenVT.boNhoDem, nhapDVT.boNhoDem, TienichDoHoa::stringToFloat(nhapSoLuong.boNhoDem), 0))
					{
						MessageBox(NULL, "Them thanh cong!", "thong bao", MB_ICONINFORMATION | MB_OK);
						delete []arrVT;
						dsVatTu.ghiFileVatTu();
						index = ID_VT;
						return;
					}
					else
					{
						MessageBox(NULL, "Khong Thanh Cong!,Ma Vat Tu da ton tai", "thong bao", MB_ICONINFORMATION | MB_OK);
						nhapMaVT.resetBoNhoDem();
					}
				}
			}
			else if (searchVT.isMouseHover(xclick,yclick)) { 
				TienichDoHoa::xoaManHinhTheoToaDo(margin + doDaiCoBan * 6 - 60, canLeTrenHD + 140 - 60 , margin + doDaiCoBan * 3 + 60, 500,BACKGROUP); 
				// cho nguoi dung nhap vao 
				searchVT.NhapVao(kiTuChu,"Chi Nhan Chu _ !");
				searchVT.chuanHoa(); 
				if (searchVT.khongRong()) 
				{
					// sau khi ten da duoc chuan hoa -> di kiem tra xem co hay khon 
					VatTu* result[100]; // chua cac va tu tim thay 
					int soLuongVatTuThoaMan = 0; 
					// di tiem kiem 
					// chuyen doi ve ki tu thuong het 
					string stringTextLowCase = TienichDoHoa::chuoiThuong(searchVT.boNhoDem); // chuyen doi sang chuoi thuong 
					string tenVT; 
					
					for (int i = 0;i < soLuongVT;i++) {
						tenVT = TienichDoHoa::chuoiThuong(arrVT[i]->ten);   
						if (strstr(tenVT.c_str(),stringTextLowCase.c_str()))
						{
						 	result[soLuongVatTuThoaMan++] = arrVT[i]; 
						}
					}
					
					// kiem tra tai cho nay 
					// hien thi len neu nhu khong tim kiem thay gi 
					if (soLuongVatTuThoaMan == 0) {
						TienichDoHoa::hienThiThongBao("Khong Ton Vat Tu Nay! ");  
						searchVT.resetBoNhoDem(); 
						tableThemVT(); 
						
					}
					else 
					{
						NutBam *hienThiKetQua = new NutBam[soLuongVatTuThoaMan]; 
						
						// tiep tuc xet noi dung cho tui no 
						// bang cach lap qua 
						int canLeTren = 136;
						 int khoanCach = 25;  
						 // ngoai ra con 1 cai nut huy 
						 
						for (int i = 0;i < soLuongVatTuThoaMan;i++) {
							// tiep tuc xet tung thang 
							hienThiKetQua[i].set(1176,canLeTren + i*khoanCach,300,24,BACKGROUP,14,3,result[i]->maVT + " - " + result[i]->ten); 
							hienThiKetQua[i].veNutCanTrai(); 
						}
						NutBam huyTimKiem(1176,canLeTren + soLuongVatTuThoaMan*khoanCach,300,24,BACKGROUP,2,15,"Huy Tim Kiem...");
					 	huyTimKiem.veNutCanTrai(); 
					 	
					 	// tien hanh bac dieu kien de co the su ly 
					 	int xclick = -1; 
					 	int yclick = -1; 
					 	
						int indexResult = -1; // chua vi tri nguoi dung muon xem 
						
					 	// tiep tuc 
						bool timKiem = true; 
						while (timKiem) 
						{
						 	if (ismouseclick(WM_LBUTTONDOWN)) 
							 {
								getmouseclick(WM_LBUTTONDOWN, xclick, yclick);
								for (int i = 0;i < soLuongVatTuThoaMan;i++) 
								{
									if (hienThiKetQua[i].isMouseHover(xclick,yclick))
									{
										indexResult = i; //  lay ra vi tri nguoi dung vua click vao
										timKiem = false;  
										break;   // chi moi co thoat khoi vong lap for thoi 
										
									}
								}
								// van kiem tra xem co bam huy nut huy tim kiem khong 
								if (huyTimKiem.isMouseHover(xclick,yclick)) 
								{
									break; // dung vong lap lai va khong tim kiem nu 
									
								}
							}
							delay(10); 
						}
						// kiem tra xem 
						
						if (indexResult != -1) 
						{
							// hien thi ra cai thang va tu nay // cho no co quyen chinh sua vat tu di 
							// xoa het di cai vung ben duo 
							TienichDoHoa::xoaManHinhTheoToaDo(1176,canLeTren,1000,1000,BACKGROUP);
							chinhSuaVT(dsVatTu,result[indexResult]); 
						
							
						}
						delete []arrVT; 
						index = ID_VT; 
						return; 
						
					}
				} 
				else {
					// rong 
					tableThemVT(); 
				}
			
	
	 			
			}
			// bac su kien nguoi dung click vao thang nao
			if (hieuChinh1.isMouseHover(xclick, yclick))
			{
				// lay ra thang VT nay -> roi sau do chinh sua -> co the chinh sua duoc.
				if (soLuongVatTuTrenTable != 0)
				{
					indexVatTuChinhSua = itemTrenMotPage * indexPage;
					nhapVaoChinhSua = true;
				}
			}
			else if (hieuChinh2.isMouseHover(xclick, yclick))
			{
				if (soLuongVatTuTrenTable >= 1)
				{
					indexVatTuChinhSua = 1 + itemTrenMotPage * indexPage;
					nhapVaoChinhSua = true;
				}
			}
			else if (hieuChinh3.isMouseHover(xclick, yclick))
			{
				if (soLuongVatTuTrenTable >= 2)
				{
					indexVatTuChinhSua = 2 + itemTrenMotPage * indexPage;
					nhapVaoChinhSua = true;
				}
			}
			else if (hieuChinh4.isMouseHover(xclick, yclick))
			{
				if (soLuongVatTuTrenTable >= 3)
				{
					indexVatTuChinhSua = 3 + itemTrenMotPage * indexPage;
					nhapVaoChinhSua = true;
				}
			}
			else if (hieuChinh5.isMouseHover(xclick, yclick))
			{
				if (soLuongVatTuTrenTable >= 4)
				{
					indexVatTuChinhSua = 4 + itemTrenMotPage * indexPage;
					nhapVaoChinhSua = true;
				}
			}
			else if (hieuChinh6.isMouseHover(xclick, yclick))
			{
				if (soLuongVatTuTrenTable >= 5)
				{
					indexVatTuChinhSua = 5 + itemTrenMotPage * indexPage;
					nhapVaoChinhSua = true;
				}
			}
			else if (hieuChinh7.isMouseHover(xclick, yclick))
			{
				if (soLuongVatTuTrenTable >= 6)
				{
					indexVatTuChinhSua = 6 + itemTrenMotPage * indexPage;
					nhapVaoChinhSua = true;
				}
			}
			else if (hieuChinh8.isMouseHover(xclick, yclick))
			{
				if (soLuongVatTuTrenTable >= 7)
				{
					indexVatTuChinhSua = 7 + itemTrenMotPage * indexPage;
					nhapVaoChinhSua = true;
				}
			}
			else if (hieuChinh9.isMouseHover(xclick, yclick))
			{
				if (soLuongVatTuTrenTable >= 8)
				{
					indexVatTuChinhSua = 8 + itemTrenMotPage * indexPage;
					nhapVaoChinhSua = true;
				}
			}
			else if (hieuChinh10.isMouseHover(xclick, yclick))
			{
				if (soLuongVatTuTrenTable >= 9)
				{
					indexVatTuChinhSua = 9 + itemTrenMotPage * indexPage;
					nhapVaoChinhSua = true;
				}
			}
			else if (hieuChinh11.isMouseHover(xclick, yclick))
			{
				if (soLuongVatTuTrenTable >= 10)
				{
				indexVatTuChinhSua = 10 + itemTrenMotPage * indexPage;
					nhapVaoChinhSua = true;
				}
			}
			// bac dieu kien nguoi dung nhap ra ngaoi
			else if (nhanVien.isMouseHover(xclick, yclick))
			{
				index = ID_NV;
				delete[] arrVT;
				return;
			}
			else if (hoaDon.isMouseHover(xclick, yclick))
			{
				index = ID_HD;
				delete[] arrVT;
				return;
			}
			else if (doanhThu.isMouseHover(xclick, yclick))
			{
				index = ID_DT;
				delete[] arrVT;
				return;
			}
			if (nhapVaoChinhSua) 
			{
				nhapVaoChinhSua = true; 
				chinhSuaVT(dsVatTu, arrVT[indexVatTuChinhSua]);
				index = ID_VT;
				delete[] arrVT;
				return;
			}
 		}
		delay(1);
	}
}
