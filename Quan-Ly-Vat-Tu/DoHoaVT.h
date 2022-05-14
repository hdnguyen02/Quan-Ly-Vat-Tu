#pragma once
using namespace std;
#include "Tienich.h"
#include "BienDoHoa.h"
#include "DoHoaHD.h"



//void hienThiVatTuSearch(VatTu* vatTuSearch) {
//	NutBam tieuDeSearch(margin + doDaiCoban * 6 - 60, canLeTrenHD + 140 - 60, margin + doDaiCoban * 3 + 30, 40, 15, 0, 0,"THONG TIN VAT TU");
//	tieuDeSearch.veNut(); 
//	ONhap nhapMaVT(margin + doDaiCoban * 6 - 16, canLeTrenHD + 140 + 30, doDaiCoban * 3 , 40, 0, "", 0, 0, 10);
//	ONhap nhapTenVT(margin + doDaiCoban * 6 - 16, canLeTrenHD + 234 + 30, doDaiCoban * 3 , 40, 0, "", 0, 0, 25);
//	ONhap nhapSoLuong(margin + doDaiCoban * 6 - 16, canLeTrenHD + 328 + 30, doDaiCoban * 3 , 40, 0, "", 0, 0, 10);
//	ONhap nhapDVT(margin + doDaiCoban * 6 - 16, canLeTrenHD + 170 + 50 + 70 * 2 + 60 + 32, doDaiCoban * 3 , 40, 0, "", 0, 0, 15);
//	nhapMaVT.boNhoDem = vatTuSearch->maVT; // lay ra maVT
//	nhapTenVT.boNhoDem = vatTuSearch->ten;
//	nhapSoLuong.boNhoDem = TienichDoHoa::floatToString(vatTuSearch->soLuongTon);
//	nhapDVT.boNhoDem = vatTuSearch->donVi;
//
//
//	nhapMaVT.khongDuocNhap = true;
//	nhapSoLuong.khongDuocNhap = true;
//	nhapTenVT.khongDuocNhap = true; 
//	nhapDVT.khongDuocNhap = true; 
//	
//
//	nhapMaVT.veONhap();
//	nhapTenVT.veONhap();
//	nhapSoLuong.veONhap();
//	nhapDVT.veONhap();
//
//	nhapMaVT.inNoiDung();
//	nhapTenVT.inNoiDung();
//	nhapSoLuong.inNoiDung();
//	nhapDVT.inNoiDung();
//	
//
//
//	NutBam saveVT(margin + doDaiCoban * 6 - 60, canLeTrenHD +500 + 26, margin + doDaiCoban * 3 + 30, 40, 0, 2,0, "");
//	saveVT.veNut();
//	NutBam thoat(margin + doDaiCoban * 6 - 60 + (margin + doDaiCoban * 3 + 30 - 40), canLeTrenHD + 140 - 60, 40, 40, 4, 0, 15, "X");
//	thoat.veNut();
//	int xclick = -1;
//	int yclick = -1;
//	while (true)
//	{
//		if (ismouseclick(WM_LBUTTONDOWN))
//		{
//			getmouseclick(WM_LBUTTONDOWN, xclick, yclick);
//			if (thoat.isMouseHover(xclick, yclick))
//			{
//				
//				break;
//			}
//		}
//		delay(1);
//	}
//	
//	
//	
//	
//
//}



void chinhSuaVT(BstVatTu &dsVatTu, VatTu *vatTuCT )
{
	NutBam titleCSVT(margin + doDaiCoban * 6 - 60, canLeTrenHD + 140 - 60, margin + doDaiCoban * 3 + 30, 40, 15, 0, 0,"THONG TIN VAT TU");
	titleCSVT.veNut(); 
	ONhap nhapMaVT(margin + doDaiCoban * 6 - 16, canLeTrenHD + 140 + 30, doDaiCoban * 3 , 40, 0, "", 0, 0, 10);
	ONhap nhapTenVT(margin + doDaiCoban * 6 - 16, canLeTrenHD + 234 + 30, doDaiCoban * 3 , 40, 0, "", 0, 0, 25);
	ONhap nhapSoLuong(margin + doDaiCoban * 6 - 16, canLeTrenHD + 328 + 30, doDaiCoban * 3 , 40, 0, "", 0, 0, 10);
	ONhap nhapDVT(margin + doDaiCoban * 6 - 16, canLeTrenHD + 170 + 50 + 70 * 2 + 60 + 32, doDaiCoban * 3 , 40, 0, "", 0, 0, 15);
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
	


	NutBam saveVT(margin + doDaiCoban * 6 - 60, canLeTrenHD +500 + 26, margin + doDaiCoban * 3 + 30, 40, 0, 2,0, "");
	NutBam xoa(margin + doDaiCoban * 6 - 60, canLeTrenHD +500 + 26, (margin + doDaiCoban * 3 + 30) / 2 - 2, 40, 15, 2, 1, "XOA");
	NutBam hieuChinh(margin + doDaiCoban * 6 - 60 + (margin + doDaiCoban * 3 + 30) / 2 + 2, canLeTrenHD +500 + 26, (margin + doDaiCoban * 3 + 30) / 2, 40, 15, 2, 1, "HIEU CHINH");
		
	
	saveVT.veNut();
	xoa.veNut();
	hieuChinh.veNut();

	NutBam thoat(margin + doDaiCoban * 6 - 60 + (margin + doDaiCoban * 3 + 30 - 40), canLeTrenHD + 140 - 60, 40, 40, 4, 0, 15, "X");
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
								dsVatTu.ghiVatTuFile();
								break;
						}
					}
					
				}
			}
		}
		delay(1);
	}
}

void inDanhSachLenDoHoa(NodeVatTu **arrVT, int indexPage, int soLuongItemPage, int soLuongNode)
{
	const int canLeY = 170; // cach oVuong 110 va cach tieuDe 40
	const int canLeX = DODAIMANHINH / 2 - 1200 / 2 + 100;
	const int donViO = 1200 / 5;
	setbkcolor(BACKGROUP);
	const int cachNhau = 30;
	string tempDVT;
	// =================== CHUA VIET HAM XOA DI DU LIEU CU ===================

	setcolor(CinputText);
	for (int i = 0; i < soLuongItemPage; i++)
	{
		if (i + indexPage * soLuongItemPage < soLuongNode)
		{
			tempDVT = TienichDoHoa::floatToString(arrVT[i + indexPage * soLuongItemPage]->getInfo()->soLuongTon);
			outtextxy(canLeX, canLeY + cachNhau * i, (char *)(arrVT[i + indexPage * soLuongItemPage]->getInfo()->maVT.c_str()));
			outtextxy(canLeX + donViO * 1, canLeY + cachNhau * i, (char *)(arrVT[i + indexPage * soLuongItemPage]->getInfo()->ten.c_str()));
			outtextxy(canLeX + donViO * 3, canLeY + cachNhau * i, (char *)(arrVT[i + indexPage * soLuongItemPage]->getInfo()->donVi.c_str()));
			outtextxy(canLeX + donViO * 4, canLeY + cachNhau * i, (char *)(tempDVT.c_str()));
		}
	}
}



void veTableVT()
{
	TienichDoHoa::xoaManHinhTheoToaDo(0, 140, 900, 580, BACKGROUP);
	NutBam titleMaVT(margin, canLeTrenHD + 170 - 129, doDaiCoban, 40, colorTieuDe, 7, conlorTextTieuDe, "MA VT");
	NutBam titileTenVT(margin + doDaiCoban + 3, canLeTrenHD + 170 - 129, doDaiCoban * 2 - 60, 40, colorTieuDe, 7, conlorTextTieuDe, "TEN");
	NutBam titiledonViVT(margin + doDaiCoban * 3 + 3 * 2 - 60, canLeTrenHD + 170 - 129, doDaiCoban, 40, colorTieuDe, 7, conlorTextTieuDe, "DVT");
	NutBam titilesoLuongVT(margin + doDaiCoban * 4 + 3 * 3 - 60, canLeTrenHD + 170 - 129, doDaiCoban, 40, colorTieuDe, 7, conlorTextTieuDe, "SO LUONG TON");
	
	titleMaVT.veNut();
	titilesoLuongVT.veNut();
	titileTenVT.veNut();
	titiledonViVT.veNut();

	OVuong table(margin, canLeTrenHD + 40, doDaiCoban * 5 - 52, 552, 15);
	setcolor(15);
	line(margin + doDaiCoban, canLeTrenHD + 170 - 129, margin + doDaiCoban, 712);
	line(margin + doDaiCoban * 3 + 3 - 60, canLeTrenHD + 170 - 129, margin + doDaiCoban * 3 + 3 - 60, 712);
	line(margin + doDaiCoban * 4 + 3 * 2 - 60, canLeTrenHD + 170 - 129, margin + doDaiCoban * 4 + 3 * 2 - 60, 712);
	// line(margin + doDaiCoban * 5 + 3 * 3 - 60, canLeTrenHD + 170 - 129, margin + doDaiCoban * 5 + 3 * 3 - 60, 712);
}

// viet 1 ham do du lieu len ham thong qua con mang VT

int hienThiDuLieuLenTableVT(int indexPage, int soLuongPhanTuTrenMotPage, VatTu **arrVT, int soLuongVT)
{
	int index;
	int khoanCach = 46;
	int marginTop = canLeTrenHD + 170 - 70;

	string temp;
	int dem = 0;
	for (int i = 0; i < soLuongPhanTuTrenMotPage; i++)
	{
		TienichDoHoa::setText(0,15,3,1); 
		if (i + indexPage * soLuongPhanTuTrenMotPage < soLuongVT)
		{
			index = i + indexPage * soLuongPhanTuTrenMotPage;
			temp = TienichDoHoa::floatToString(arrVT[index]->soLuongTon);
			outtextxy(margin + 30, marginTop + khoanCach * i, arrVT[index]->maVT.c_str());	 // hien thi ra maVT
			outtextxy(margin + 186, marginTop + khoanCach * i, arrVT[index]->ten.c_str());	 // hien thi ra maVT
			outtextxy(margin + 430, marginTop + khoanCach * i, arrVT[index]->donVi.c_str()); // hien thi ra maVT
			outtextxy(margin + 600, marginTop + khoanCach * i, temp.c_str());				 // hien thi ra maVT
			line(margin, marginTop + khoanCach * i + 32, margin + 724, marginTop + khoanCach * i + 32);
			NutBam hieuChinh(margin + 746, marginTop + khoanCach * i - 4, 60, 28, 11, 0, 0, "sua");
			hieuChinh.veNut();
			dem++;
		}
	}
	return dem;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                                        //
//	                                      HIEN THI TINH NANG VAT TU MOI                                                   //
//                                                                                                                        //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
	int soLuongPage = soLuongVT / itemTrenMotPage;
	float toiDaPage = (float)soLuongVT / (float)itemTrenMotPage;

	if (!kiemTraSoNguyen(TienichDoHoa::floatToString(toiDaPage)))
	{
		toiDaPage = (int)toiDaPage + 1;
	}

	// bac su kien nguoi dung nhap vao may cai o

	bool theoMa = true; // mat dinh la tim kiem theo ma ! nhe 
	

	TienichDoHoa::xoaManHinhTheoToaDo(0, 60, 1600, 1600, BACKGROUP);
	
	
	ONhap searchVT(margin + doDaiCoban* 6 + 94 + 100,94,300,40,0,"",0,0,25,13);
	NutBam timKiemTheoMa(margin + doDaiCoban* 6 - 80,94,100,40,11,13,0,"Ma"); 
	
	timKiemTheoMa.veNut();
	NutBam timKiemTheoTen(margin + doDaiCoban* 6 + 50,94,100,40,11,13,0,"Ten"); 
	timKiemTheoTen.veNut(); 
	searchVT.veONhap();
	timKiemTheoMa.duocChon(); 
	timKiemTheoTen.khongDuocChon(); 
	
	
	OVuong themVT(margin + doDaiCoban * 6 - 60, canLeTrenHD + 140 - 60 , margin + doDaiCoban * 3 + 30, 400 + 60, 15);
	
	NutBam titleThemVT(margin + doDaiCoban * 6 - 60, canLeTrenHD + 140 - 60, margin + doDaiCoban * 3 + 30, 40, 15, 0, 0, "THEM VAT TU");
	
	TienichDoHoa::setText(0,15,3,1); 
	outtextxy(margin + doDaiCoban* 6 - 180 ,102,"Tim Kiem"); 
	outtextxy(margin + doDaiCoban * 6 - 16,canLeTrenHD + 140,"Ma Vat Tu");
	outtextxy(margin + doDaiCoban * 6 - 16,canLeTrenHD + 234,"Ten Vat Tu");
	outtextxy(margin + doDaiCoban * 6 - 16,canLeTrenHD + 328,"So Luong Ton");
	outtextxy(margin + doDaiCoban * 6 - 16,canLeTrenHD + 170 + 50 + 70 * 2 + 20 + 42,"Don Vi Tinh"); 
	
	
	ONhap nhapMaVT(margin + doDaiCoban * 6 - 16, canLeTrenHD + 140 + 30, doDaiCoban * 3 , 40, 0, "", 0, 0, 10);
	ONhap nhapTenVT(margin + doDaiCoban * 6 - 16, canLeTrenHD + 234 + 30, doDaiCoban * 3 , 40, 0, "", 0, 0, 25);
	ONhap nhapSoLuong(margin + doDaiCoban * 6 - 16, canLeTrenHD + 328 + 30, doDaiCoban * 3 , 40, 0, "", 0, 0, 10);
	ONhap nhapDVT(margin + doDaiCoban * 6 - 16, canLeTrenHD + 170 + 50 + 70 * 2 + 60 + 32, doDaiCoban * 3 , 40, 0, "", 0, 0, 15);
	
	
	
	titleThemVT.veNut();
	nhapMaVT.veONhap();
	nhapTenVT.veONhap();
	nhapSoLuong.veONhap();
	nhapDVT.veONhap();
	NutBam saveVT(margin + doDaiCoban * 6 - 60, canLeTrenHD +500 + 26, margin + doDaiCoban * 3 + 30 + 1, 40, 15, 2,0, "LUU VAT TU");
	saveVT.veNut();
	veTableVT();

	// ve ra 2 nut
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

	soLuongVatTuTrenTable = hienThiDuLieuLenTableVT(indexPage, itemTrenMotPage, arrVT, soLuongVT);
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
	
	
	// cho tim kiem theo nhieu truong : ten va ca ma so ( don vi tinh co qua nhieu cai trung nhau
	// con so luong ton thi khong hop ly de tim kiem 
	
	
	
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
					veTableVT();
					soLuongVatTuTrenTable = hienThiDuLieuLenTableVT(indexPage, itemTrenMotPage, arrVT, soLuongVT);
					hienThiChiMuc(470, 740, indexPage, toiDaPage);
				}
			}
			else if (btnLui.isMouseHover(xclick, yclick))
			{
				if (indexPage > 0)
				{
					indexPage--;
					veTableVT();
					soLuongVatTuTrenTable = hienThiDuLieuLenTableVT(indexPage, itemTrenMotPage, arrVT, soLuongVT);
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
				veTableVT();
				soLuongVatTuTrenTable = hienThiDuLieuLenTableVT(indexPage, itemTrenMotPage, arrVT, soLuongVT);
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
				veTableVT();
				soLuongVatTuTrenTable = hienThiDuLieuLenTableVT(indexPage, itemTrenMotPage, arrVT, soLuongVT);
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
				veTableVT();
				soLuongVatTuTrenTable = hienThiDuLieuLenTableVT(indexPage, itemTrenMotPage, arrVT, soLuongVT);
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
				veTableVT();
				soLuongVatTuTrenTable = hienThiDuLieuLenTableVT(indexPage, itemTrenMotPage, arrVT, soLuongVT);
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
						dsVatTu.ghiVatTuFile();
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
	 			if (theoMa) {
	 				searchVT.NhapVao(nhapID,"Chi Nhan Chu,So Hoac _ !"); 
	 				if (searchVT.khongRong()) {
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
	 				if (searchVT.khongRong()) {
					 	VatTu* result = NULL; 
						for (int i = 0; i < soLuongVT;i++) {
							if (arrVT[i]->ten == searchVT.boNhoDem) {
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
					chinhSuaVT(dsVatTu, arrVT[itemTrenMotPage * indexPage]);
					index = ID_VT;
					delete[] arrVT;
					return;
				}
			}
			else if (hieuChinh2.isMouseHover(xclick, yclick))
			{
				if (soLuongVatTuTrenTable >= 1)
				{
					chinhSuaVT(dsVatTu, arrVT[1 + itemTrenMotPage * indexPage]);
					index = ID_VT;
					delete[] arrVT;
					return;
				}
			}
			else if (hieuChinh3.isMouseHover(xclick, yclick))
			{
				if (soLuongVatTuTrenTable >= 2)
				{
					chinhSuaVT(dsVatTu, arrVT[2 + itemTrenMotPage * indexPage]);
					index = ID_VT;
					delete[] arrVT;
					return;
				}
			}
			else if (hieuChinh4.isMouseHover(xclick, yclick))
			{
				if (soLuongVatTuTrenTable >= 3)
				{
					chinhSuaVT(dsVatTu, arrVT[3 + itemTrenMotPage * indexPage]);
					index = ID_VT;
					delete[] arrVT;
					return;
				}
			}
			else if (hieuChinh5.isMouseHover(xclick, yclick))
			{
				if (soLuongVatTuTrenTable >= 4)
				{
					chinhSuaVT(dsVatTu, arrVT[4 + itemTrenMotPage * indexPage]);
					index = ID_VT;
					delete[] arrVT;
					return;
				}
			}
			else if (hieuChinh6.isMouseHover(xclick, yclick))
			{
				if (soLuongVatTuTrenTable >= 5)
				{
					chinhSuaVT(dsVatTu, arrVT[5 + itemTrenMotPage * indexPage]);
					index = ID_VT;
					delete[] arrVT;
					return;
				}
			}
			else if (hieuChinh7.isMouseHover(xclick, yclick))
			{
				if (soLuongVatTuTrenTable >= 6)
				{
					chinhSuaVT(dsVatTu, arrVT[6 + itemTrenMotPage * indexPage]);
					index = ID_VT;
					delete[] arrVT;
					return;
				}
			}
			else if (hieuChinh8.isMouseHover(xclick, yclick))
			{
				if (soLuongVatTuTrenTable >= 7)
				{
					chinhSuaVT(dsVatTu, arrVT[7 + itemTrenMotPage * indexPage]);
					index = ID_VT;
					delete[] arrVT;
					return;
				}
			}
			else if (hieuChinh9.isMouseHover(xclick, yclick))
			{
				if (soLuongVatTuTrenTable >= 8)
				{
					chinhSuaVT(dsVatTu, arrVT[8 + itemTrenMotPage * indexPage]);
					index = ID_VT;
					delete[] arrVT;
					return;
				}
			}
			else if (hieuChinh10.isMouseHover(xclick, yclick))
			{
				if (soLuongVatTuTrenTable >= 9)
				{
					chinhSuaVT(dsVatTu, arrVT[9 + itemTrenMotPage * indexPage]);
					index = ID_VT;
					delete[] arrVT;
					return;
				}
			}
			else if (hieuChinh11.isMouseHover(xclick, yclick))
			{
				if (soLuongVatTuTrenTable >= 10)
				{
					chinhSuaVT(dsVatTu, arrVT[10 + itemTrenMotPage * indexPage]);
					index = ID_VT;
					delete[] arrVT;
					return;
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
		}
		delay(1);
	}
}
