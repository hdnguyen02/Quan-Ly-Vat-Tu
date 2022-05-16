#pragma once
using namespace std;
#include "Tienich.h"
#include "BienDoHoa.h"
#include "DoHoaHD.h"
#include "HamDoHoaVatTu.h"




void chinhSuaVT(BstVatTu &dsVatTu, VatTu *vatTuCT )
{
	NutBam titleCSVT(margin + doDaiCoBan * 6 - 60, canLeTrenHD + 140 - 60, margin + doDaiCoBan * 3 + 30, 40, 15, 0, 0,"THONG TIN VAT TU");
	titleCSVT.veNut(); 
	ONhap nhapMaVT(margin + doDaiCoBan * 6 - 16, canLeTrenHD + 140 + 30, doDaiCoBan * 3 , 40, 0, "", 0, 0, 10);
	ONhap nhapTenVT(margin + doDaiCoBan * 6 - 16, canLeTrenHD + 234 + 30, doDaiCoBan * 3 , 40, 0, "", 0, 0, 25);
	ONhap nhapSoLuong(margin + doDaiCoBan * 6 - 16, canLeTrenHD + 328 + 30, doDaiCoBan * 3 , 40, 0, "", 0, 0, 10);
	ONhap nhapDVT(margin + doDaiCoBan * 6 - 16, canLeTrenHD + 170 + 50 + 70 * 2 + 60 + 32, doDaiCoBan * 3 , 40, 0, "", 0, 0, 15);
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
	
	int toaDoXTable = 100; 
	int toaDoYTable = 160; 
	int chieuCaoTable = 500; 
	int mauNenTable = 0; 
	

	TienichDoHoa::xoaManHinhTheoToaDo(0, 60, 1600, 1600, BACKGROUP);
	
	
	ONhap searchVT(margin + doDaiCoBan* 6 + 94 + 100,94,300,40,0,"",0,0,25,13);
	NutBam timKiemTheoMa(margin + doDaiCoBan* 6 - 80,94,100,40,11,13,0,"Ma"); 
	
	timKiemTheoMa.veNut();
	NutBam timKiemTheoTen(margin + doDaiCoBan* 6 + 50,94,100,40,11,13,0,"Ten"); 
	timKiemTheoTen.veNut(); 
	searchVT.veONhap();
	timKiemTheoMa.duocChon(); 
	timKiemTheoTen.khongDuocChon(); 
	
	
	OVuong themVT(margin + doDaiCoBan * 6 - 60, canLeTrenHD + 140 - 60 , margin + doDaiCoBan * 3 + 30, 400 + 60, 15);
	
	NutBam titleThemVT(margin + doDaiCoBan * 6 - 60, canLeTrenHD + 140 - 60, margin + doDaiCoBan * 3 + 30, 40, 15, 0, 0, "THEM VAT TU");
	
	TienichDoHoa::setText(0,15,3,1); 
	outtextxy(margin + doDaiCoBan* 6 - 180 ,102,"Tim Kiem"); 
	outtextxy(margin + doDaiCoBan * 6 - 16,canLeTrenHD + 140,"Ma Vat Tu");
	outtextxy(margin + doDaiCoBan * 6 - 16,canLeTrenHD + 234,"Ten Vat Tu");
	outtextxy(margin + doDaiCoBan * 6 - 16,canLeTrenHD + 328,"So Luong Ton");
	outtextxy(margin + doDaiCoBan * 6 - 16,canLeTrenHD + 170 + 50 + 70 * 2 + 20 + 42,"Don Vi Tinh"); 
	
	
	ONhap nhapMaVT(margin + doDaiCoBan * 6 - 16, canLeTrenHD + 140 + 30, doDaiCoBan * 3 , 40, 0, "", 0, 0, 10);
	ONhap nhapTenVT(margin + doDaiCoBan * 6 - 16, canLeTrenHD + 234 + 30, doDaiCoBan * 3 , 40, 0, "", 0, 0, 25);
	ONhap nhapSoLuong(margin + doDaiCoBan * 6 - 16, canLeTrenHD + 328 + 30, doDaiCoBan * 3 , 40, 0, "", 0, 0, 10);
	ONhap nhapDVT(margin + doDaiCoBan * 6 - 16, canLeTrenHD + 170 + 50 + 70 * 2 + 60 + 32, doDaiCoBan * 3 , 40, 0, "", 0, 0, 15);
	
	
	
	titleThemVT.veNut();
	nhapMaVT.veONhap();
	nhapTenVT.veONhap();
	nhapSoLuong.veONhap();
	nhapDVT.veONhap();
	NutBam saveVT(margin + doDaiCoBan * 6 - 60, canLeTrenHD +500 + 26, margin + doDaiCoBan * 3 + 30 + 1, 40, 15, 2,0, "LUU VAT TU");
	saveVT.veNut();

	NutBam btnLui(margin, 730, 100, 40, 15, 0, 0, "<<");
	NutBam btnTien(margin + 730, 730, 100, 40, 15, 0, 0, ">>");
	btnLui.veNut();
	btnTien.veNut();

	// ve them 2 3 cuc sap xep theo
	setcolor(CinputText);
	setbkcolor(0);
	settextstyle(6, 0, 1);
	outtextxy(59, 106, "SAP XEP THEO: ");

	NutBam theoTen(62 + 160 + 40, 96, 100, 40, 11, 13, 0, "TEN");
	NutBam theoMaVT(62 + 160 + 120 + 40, 96, 100, 40, 11, 13, 0, "MA");
	NutBam theoDVT(62 + 160 + 120 * 2 + 40, 96, 100, 40, 11, 13, 0, "DVT");
	NutBam theoSLT(62 + 160 + 120 * 3 + 40, 96, 100, 40, 11, 13, 0, "SL");
	theoTen.duocTroVao = true;

	theoSLT.veNut();
	theoTen.veNut();
	theoMaVT.veNut();
	theoDVT.veNut();
	dsVatTu.insertionSort(arrVT, soLuongVT, khoaSapXep);

	soLuongVatTuTrenTable = hienThiDuLieuVatTu(toaDoXTable,toaDoYTable,chieuCaoTable,mauNenTable,indexPage,itemTrenMotPage,arrVT,soLuongVT); 
	hienThiChiMuc(470, 740, indexPage, toiDaPage);
	int marginTop = canLeTrenHD + 170 - 70;
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
	
	
	// cac bien nam du value cu 
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
					hienThiChiMuc(470, 740, indexPage, toiDaPage);
				}
			}
			else if (btnLui.isMouseHover(xclick, yclick))
			{
				if (indexPage > 0)
				{
					indexPage--;
					soLuongVatTuTrenTable = hienThiDuLieuVatTu(toaDoXTable,toaDoYTable,chieuCaoTable,mauNenTable,indexPage,itemTrenMotPage,arrVT,soLuongVT); 
					hienThiChiMuc(470, 740, indexPage, toiDaPage);
				}
			}
			else if (timKiemTheoMa.isMouseHover(xclick,yclick)) {
				theoMa = true; 
				timKiemTheoMa.duocChon(); 
				timKiemTheoTen.khongDuocChon(); 
			}
			else if (timKiemTheoTen.isMouseHover(xclick,yclick)) {
				theoMa = false; 
				timKiemTheoMa.khongDuocChon(); 
				timKiemTheoTen.duocChon(); 
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
				hienThiChiMuc(470, 740, indexPage, toiDaPage);
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
				hienThiChiMuc(470, 740, indexPage, toiDaPage);
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
				hienThiChiMuc(470, 740, indexPage, toiDaPage);
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
				hienThiChiMuc(470, 740, indexPage, toiDaPage);
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
	 			if (theoMa) 
				 {
	 				searchVT.NhapVao(nhapID,"Chi Nhan Chu,So Hoac _ !"); 
	 				if (searchVT.khongRong())
					  {
					 	NodeVatTu* nodeResult = dsVatTu.timKiemVT(searchVT.boNhoDem); 
					 	if (nodeResult != NULL) {
						 	chinhSuaVT(dsVatTu, nodeResult->getInfo());
						 	delete []arrVT; 
						 	index = ID_VT;
						 	return;
						 	
						 }
						 else 
						 {
						 	MessageBox(NULL, "Khong Tim Thay Vat Tu Nay!", "thong bao", MB_ICONINFORMATION | MB_OK);
						 }
					 }
				}
				else {
					searchVT.NhapVao(kiTuChu,"Chi Nhan Chu!"); 
					searchVT.chuanHoa(); 
	 				if (searchVT.khongRong())
					  {
					 	VatTu* result = NULL; 
						for (int i = 0; i < soLuongVT;i++) {
							if (arrVT[i]->ten == searchVT.boNhoDem) 
							{
								result = arrVT[i]; 
								break;
							}
						}
			 			if (result != NULL) {
			 				chinhSuaVT(dsVatTu, result);
						 	delete []arrVT; 
						 	index = ID_VT;
						 	return;
						}
						else {
							MessageBox(NULL, "Khong Tim Thay Vat Tu Nay!", "thong bao", MB_ICONINFORMATION | MB_OK);
							
						}
					}
					
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
				index = ID_HD;
				delete[] arrVT;
				return;
			}
 		}
		delay(1);
	}
}
