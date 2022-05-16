#pragma once
using namespace std;
#include "Tienich.h"
#include "BienDoHoa.h"
#include "DoHoaHD.h"

// viet ham hien thi table

// chua sua !


// hieu chinh table nhan vien 
// viet code the nay nhe





void hienThiChinhSuaNV(dsNhanVien &DSNV, NhanVien *nhanVienCT)
{
	bool daSua = false; 
	OVuong themNV(margin + doDaiCoBan * 6 - 60, canLeTrenHD + 140, margin + doDaiCoBan * 3 + 30, 400, 15);
	NutBam titleHCNV(margin + doDaiCoBan * 6 - 60, canLeTrenHD + 140, margin + doDaiCoBan * 3 + 30, 40, 15, 0, 0, "HIEU CHINH NHAN VIEN");
	titleHCNV.veNut();
	ONhap nhapMaNV(margin + doDaiCoBan * 6, canLeTrenHD + 170 + 30, doDaiCoBan * 3 - 100, 40, 60, "MA: ", 0, 0, 10);
	nhapMaNV.khongDuocNhap = true;
	ONhap nhapHoNV(margin + doDaiCoBan * 6, canLeTrenHD + 170 + 100, doDaiCoBan * 3 - 100, 40, 60, "HO: ", 0, 0, 20);
	ONhap nhapTenNV(margin + doDaiCoBan * 6, canLeTrenHD + 170 + 70 * 2 + 30, doDaiCoBan * 3 - 100, 40, 60, "TEN: ", 0, 0, 10);

	// tao ra 2 nut bam Nam Nu
	NutBam nam(margin + doDaiCoBan * 6 + 60, canLeTrenHD + 170 + 70 * 2 + 30 + 70, 60, 40, 11, 13, 0, "NAM");
	NutBam nu(margin + doDaiCoBan * 6 + 364, canLeTrenHD + 170 + 70 * 2 + 30 + 70, 60, 40, 11, 13, 0, "NU");
	nam.veNut();
	nu.veNut();
	nhapMaNV.veONhap();
	nhapHoNV.veONhap();
	nhapTenNV.veONhap();

	NutBam saveNV(margin + doDaiCoBan * 6 - 60, canLeTrenHD + 170 + 50 + 160 + 120, margin + doDaiCoBan * 3 + 30, 40, 0, 2, 0, "");
	saveNV.veNut();

	NutBam xoa(margin + doDaiCoBan * 6 - 60, canLeTrenHD + 170 + 50 + 160 + 120, (margin + doDaiCoBan * 3 + 30) / 2 - 1, 40, 14, 2, 1, "XOA");
	xoa.veNut();

	NutBam hieuChinh(margin + doDaiCoBan * 6 - 60 + (margin + doDaiCoBan * 3 + 30) / 2 + 1, canLeTrenHD + 170 + 50 + 160 + 120, (margin + doDaiCoBan * 3 + 30) / 2, 40, 14, 2, 1, "HIEU CHINH");
	hieuChinh.veNut();
	NutBam thoat(margin + doDaiCoBan * 6 - 60 + (margin + doDaiCoBan * 3 + 30 - 40), canLeTrenHD + 140, 40, 40, 4, 0, 15, "X");
	thoat.veNut();

	int xclick = -1;
	int yclick = -1;

	string maNVCu = nhanVienCT->maNV;
	string hoNVCu = nhanVienCT->ho;
	string tenNVCu = nhanVienCT->ten;
	int phaiCu = nhanVienCT->phai;

	nhapMaNV.boNhoDem = nhanVienCT->maNV;
	nhapTenNV.boNhoDem = nhanVienCT->ten;
	nhapHoNV.boNhoDem = nhanVienCT->ho;

	// khai bao 1 bien phai
	int phai = nhanVienCT->phai;
	if (phai == 0)
	{
		nam.duocChon();
		nu.khongDuocChon();
	}
	else
	{
		nam.khongDuocChon();
		nu.duocChon();
	}

	// do du lieu len!
	nhapTenNV.inNoiDung();
	nhapHoNV.inNoiDung();
	nhapMaNV.inNoiDung();

	while (true)
	{
		if (ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_LBUTTONDOWN, xclick, yclick);

			if (nhapTenNV.isMouseHover(xclick, yclick))
			{
				nhapTenNV.NhapVao(kiTuChuHoacSo, "");
				nhapTenNV.chuanHoa();
			}
			else if (nhapHoNV.isMouseHover(xclick, yclick))
			{
				
				nhapHoNV.NhapVao(kiTuChu, "");
				nhapHoNV.chuanHoa();
			}
			else if (nam.isMouseHover(xclick, yclick))
			{
				daSua = true; 
				nam.duocChon();
				nu.khongDuocChon();
				// cap nhap lai bien phai luon 
				nhanVienCT->phai = 0; 
			}
			else if (nu.isMouseHover(xclick, yclick))
			{
				daSua = true;
				nam.khongDuocChon();
				nu.duocChon();
				nhanVienCT->phai = 1; 
			}
			else if (hieuChinh.isMouseHover(xclick, yclick))
			{ // nhap vao !
				if (nam.duocTroVao = true)
				{
					phai = 0;
				}
				else
				{
					phai = 1;
				}
				if (nhapTenNV.boNhoDem == "" || nhapMaNV.boNhoDem == "" || nhapHoNV.boNhoDem == "")
				{
					MessageBox(NULL, "Khong Duoc Bo Trong!", "thong bao", MB_ICONINFORMATION | MB_OK);
				}
				else if (nhapTenNV.boNhoDem != tenNVCu || nhapHoNV.boNhoDem != hoNVCu || daSua == true) 
				{ // phai co thang nao thay doi thi moi chinh sua !
					nhanVienCT->maNV = nhapMaNV.boNhoDem;
					nhanVienCT->ten = nhapTenNV.boNhoDem;
					nhanVienCT->ho = nhapHoNV.boNhoDem;
					MessageBox(NULL, "Hieu Chinh Thanh Cong!", "Thong Bao", MB_ICONINFORMATION | MB_OK);
					DSNV.ghiFileDSNV();
					break;
				}
			}
			else if (thoat.isMouseHover(xclick, yclick))
			{
				break;
			}
			else if (xoa.isMouseHover(xclick, yclick))
			{
				if (nhapMaNV.boNhoDem == maNVCu && nhapTenNV.boNhoDem == tenNVCu && nhapHoNV.boNhoDem == hoNVCu)
				{
					int luaChon = MessageBox(NULL, "ban co chac chac muon xoa!", "thong bao", MB_ICONWARNING | MB_OKCANCEL);
					if (luaChon == OK)
					{ // xoa di !
						if (DSNV.xoaNV(nhapMaNV.boNhoDem) == false)
						{
							MessageBox(NULL, "Khong Duoc Phep Xoa! Nhan Vien da tao Hoa Don!", "Thong Bao", MB_ICONINFORMATION | MB_OK);
						}
						else
						{
							DSNV.ghiFileDSNV();
							break;
						}
					}
				}
			}
		}
		delay(1);
	}
}




void veTableNV()
{
	
	TienichDoHoa::xoaManHinhTheoToaDo(0, 140, 900, 580, BACKGROUP);
	NutBam titleMaNV(margin, canLeTrenHD + 170 - 129, doDaiCoBan, 40, colorTieuDe, 7, conlorTextTieuDe, "MA NHAN VIEN");
	NutBam titileTenNV(margin + doDaiCoBan + 3, canLeTrenHD + 170 - 129, doDaiCoBan * 3 - 60 + 4, 40, colorTieuDe, 7, conlorTextTieuDe, "HO VA TEN");
	NutBam titileGioiTinh(margin + doDaiCoBan * 4 + 3 * 3 - 60, canLeTrenHD + 170 - 129, doDaiCoBan, 40, colorTieuDe, 7, conlorTextTieuDe, "GIOI TINH");
	NutBam titileHieuChinh(margin + doDaiCoBan * 5 + 3 * 4 - 60, canLeTrenHD + 170 - 129, doDaiCoBan + 6 - 60, 40, colorTieuDe, 7, conlorTextTieuDe, "SUA");
	titleMaNV.veNut();
	titileTenNV.veNut();
	titileGioiTinh.veNut();
	titileHieuChinh.veNut();
	OVuong table(margin, canLeTrenHD + 40, doDaiCoBan * 6 + 18 - 120, 560, 15);
	setcolor(15);
	line(margin + doDaiCoBan, canLeTrenHD + 170 - 129, margin + doDaiCoBan, 720);
	line(margin + doDaiCoBan * 4 + 3 * 2 - 60, canLeTrenHD + 170 - 129, margin + doDaiCoBan * 4 + 3 * 2 - 60, 720);
	line(margin + doDaiCoBan * 5 + 3 * 3 - 60, canLeTrenHD + 170 - 129, margin + doDaiCoBan * 5 + 3 * 3 - 60, 720);
}



int hienThiDuLieuLenTableNV(int indexPage, int soLuongPhanTuTrenMotPage, dsNhanVien &DSNV)
{
	int index;
	int khoanCach = 46;
	int marginTop = canLeTrenHD + 170 - 70;
	int soLuongNV = DSNV.soLuongNV();
	string temp;
	int dem = 0;
	// lay ra dia chi cua mang
	NhanVien **arrNV = DSNV.getDSNV();
	for (int i = 0; i < soLuongPhanTuTrenMotPage; i++)
	{
		setcolor(CinputText);
		setbkcolor(0);
		settextstyle(6, 0, 1);
		if (i + indexPage * soLuongPhanTuTrenMotPage < soLuongNV)
		{
			index = i + indexPage * soLuongPhanTuTrenMotPage;
			outtextxy(margin + 30, marginTop + khoanCach * i, arrNV[index]->maNV.c_str());		  // hien thi ra maVT
			outtextxy(margin + 186, marginTop + khoanCach * i, arrNV[index]->getHoTen().c_str()); // hien thi ra maVT
			// kiem tra xem la 0 hay 1
			if (arrNV[index]->phai == 0)
			{
				temp = "Nam";
			}
			else
			{
				temp = "Nu";
			}
			outtextxy(margin + 600, marginTop + khoanCach * i, temp.c_str()); // hien thi ra maVT
			line(margin, marginTop + khoanCach * i + 32, margin + 830, marginTop + khoanCach * i + 32);
			NutBam hieuChinh(margin + 746, marginTop + khoanCach * i - 4, 60, 28, 11, 0, 0, "sua");
			hieuChinh.veNut();
			dem++;
		}
	}
	return dem;
}




void hienThiTinhNangNhanVien(dsNhanVien &DSNV, int &index, NutBam &vatTu, NutBam &hoaDon, NutBam &doanhThu, bool (*khoaSapXep)(NhanVien *, NhanVien *))
{
	int indexPage = 0;
	int soLuongPhanTuHienThi = 0;
	int itemTrenMotPage = 11;
	int toaDoChiMucX = DODAIMANHINH / 2 - 110;
	NhanVien *tempNV;
	int soLuongNV = DSNV.soLuongNV();
	int soLuongNhanVienTrenTable = 0;
	float toiDaPage = TienichDoHoa::tinhToiDaPage(DSNV.soLuongNV(),itemTrenMotPage); 
	TienichDoHoa::xoaManHinhTheoToaDo(0, 60, 1600, 1600, BACKGROUP);

	// bac dau ve ra truoc tien la ve ra cac title
	OVuong themNV(margin + doDaiCoBan * 6 - 60, canLeTrenHD + 140, margin + doDaiCoBan * 3 + 30, 400, 15);
	NutBam titleThemNV(margin + doDaiCoBan * 6 - 60, canLeTrenHD + 140, margin + doDaiCoBan * 3 + 30, 40, 15, 0, 0, "THEM NHAN VIEN");
	titleThemNV.veNut();
	ONhap nhapMaNV(margin + doDaiCoBan * 6, canLeTrenHD + 170 + 30, doDaiCoBan * 3 - 100, 40, 60, "MA: ", 0, 0, 10);
	ONhap nhapHoNV(margin + doDaiCoBan * 6, canLeTrenHD + 170 + 100, doDaiCoBan * 3 - 100, 40, 60, "HO: ", 0, 0, 20);
	ONhap nhapTenNV(margin + doDaiCoBan * 6, canLeTrenHD + 170 + 70 * 2 + 30, doDaiCoBan * 3 - 100, 40, 60, "TEN: ", 0, 0, 20);

	// tao ra 2 nut bam Nam Nu
	NutBam nam(margin + doDaiCoBan * 6 + 60, canLeTrenHD + 170 + 70 * 2 + 30 + 70, 60, 40, 11, 13, 0, "NAM");
	nam.duocTroVao = true;
	nam.veNut();

	NutBam nu(margin + doDaiCoBan * 6 + 364, canLeTrenHD + 170 + 70 * 2 + 30 + 70, 60, 40, 11, 13, 0, "NU");
	nu.veNut();
	nhapMaNV.veONhap();
	nhapHoNV.veONhap();
	nhapTenNV.veONhap();

	// ve ra o Vuong ngan cach nam nu
	//	line(margin + doDaiCoBan*6 + 200 + 36,canLeTrenHD + 170 + 70 * 2 + 30 + 60,margin + doDaiCoBan*6 + 200 + 36,canLeTrenHD + 170 + 70 * 2 + 30 + 120);

	NutBam saveNV(margin + doDaiCoBan * 6 - 60, canLeTrenHD + 170 + 50 + 160 + 120, margin + doDaiCoBan * 3 + 30, 40, 14, 2, 0, "SAVE");
	saveNV.veNut();

	DSNV.insertionSort(NhanVien::soSanhTheoTen);

	veTableNV();

	soLuongNhanVienTrenTable = hienThiDuLieuLenTableNV(indexPage, itemTrenMotPage, DSNV);
	hienThiChiMuc(430, 740, indexPage, toiDaPage);

	// ve ra sap xep theo
	setcolor(CinputText);
	setbkcolor(0);
	settextstyle(6, 0, 1);
	outtextxy(59, 106, "SAP XEP THEO: ");

	NutBam theoTen(62 + 160 + 40, 96, 100, 40, 11, 13, 0, "HO TEN");
	NutBam theoMaNV(62 + 160 + 120 + 40, 96, 100, 40, 11, 13, 0, "MA");
	theoTen.duocChon();
	theoMaNV.veNut();

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

	NutBam btnLui(margin, 730, 100, 40, 15, 0, 0, "<<");
	NutBam btnTien(margin + 730, 730, 100, 40, 15, 0, 0, ">>");
	btnLui.veNut();
	btnTien.veNut();
	// bat su kien nhap vao nv
	int xclick = -1;
	int yclick = -1;
	while (true)
	{
		if (ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_LBUTTONDOWN, xclick, yclick);
			if (nhapMaNV.isMouseHover(xclick, yclick))
			{ 
				nhapMaNV.NhapVao(kiTuChuHoacSo, "");
				// sau khi nhap song kiem tra xem co trung hay khong
				tempNV = DSNV.timKiemNVTraVeDiaChi(nhapMaNV.boNhoDem);
				if (tempNV != NULL)
				{
					MessageBox(NULL, "da ton ma nhan vien nay", "thong bao", MB_ICONINFORMATION | MB_OK);
					nhapMaNV.resetBoNhoDem();
				}
			}
			else if (nhapHoNV.isMouseHover(xclick, yclick))
			{
				nhapHoNV.NhapVao(kiTuChu, "chi nhap chu!");
				nhapHoNV.chuanHoa();
			}
			else if (nhapTenNV.isMouseHover(xclick, yclick))
			{
				nhapTenNV.NhapVao(kiTuChu, "chu nhap chu!");
				nhapTenNV.chuanHoa();
			}
			else if (nam.isMouseHover(xclick, yclick))
			{
				// phat sang no len !
				nam.duocTroVao = true;
				nam.veNut();
				nu.duocTroVao = false;
				nu.veNut();
			}
			else if (nu.isMouseHover(xclick, yclick))
			{
				nam.duocTroVao = false;
				nam.veNut();
				nu.duocTroVao = true;
				nu.veNut();
			}
			else if (saveNV.isMouseHover(xclick, yclick))
			{
				if (nhapMaNV.boNhoDem == "" || nhapHoNV.boNhoDem == "" || nhapTenNV.boNhoDem == "")
				{
					MessageBox(NULL, "khong duoc bo trong!", "thong bao", MB_ICONINFORMATION | MB_OK);
				}
				else
				{

					int phai;
					if (nam.duocTroVao == true)
					{
						phai = 0;
					}
					else
					{
						phai = 1;
					}
					DSNV.themNV(nhapMaNV.boNhoDem, nhapHoNV.boNhoDem, nhapTenNV.boNhoDem, phai, 0);
					DSNV.ghiFileDSNV();
					MessageBox(NULL, "Them thanh cong!", "thong bao", MB_ICONINFORMATION | MB_OK);
					index = ID_NV;
					return;
				}
			}
			else if (btnTien.isMouseHover(xclick, yclick))
			{
				if (indexPage < toiDaPage - 1)
				{
					indexPage++; 
					veTableNV();
					soLuongNhanVienTrenTable = hienThiDuLieuLenTableNV(indexPage, itemTrenMotPage, DSNV);
					hienThiChiMuc(430, 740, indexPage, toiDaPage);
				}
			}
			else if (btnLui.isMouseHover(xclick, yclick))
			{
				if (indexPage > 0)
				{
					indexPage--;
					veTableNV();

					soLuongNhanVienTrenTable = hienThiDuLieuLenTableNV(indexPage, itemTrenMotPage, DSNV);
					hienThiChiMuc(430, 740, indexPage, toiDaPage);
				}
			}
			else if (theoTen.isMouseHover(xclick, yclick))
			{
				// ve lai bang thoi !
				theoTen.duocChon();
				theoMaNV.khongDuocChon();
				DSNV.insertionSort(NhanVien::soSanhTheoTen);
				veTableNV();
				soLuongNhanVienTrenTable = hienThiDuLieuLenTableNV(indexPage, itemTrenMotPage, DSNV);
				hienThiChiMuc(430, 740, indexPage, toiDaPage);
			}
			else if (theoMaNV.isMouseHover(xclick, yclick))
			{
				theoMaNV.duocChon();
				theoTen.khongDuocChon();
				DSNV.insertionSort(NhanVien::soSanhTheoMaNV);
				veTableNV();
				soLuongNhanVienTrenTable = hienThiDuLieuLenTableNV(indexPage, itemTrenMotPage, DSNV);
				hienThiChiMuc(430, 740, indexPage, toiDaPage);
			}
			else if (hieuChinh1.isMouseHover(xclick, yclick))
			{
				if (soLuongNhanVienTrenTable != 0)
				{
					hienThiChinhSuaNV(DSNV, DSNV.getNhanVien(itemTrenMotPage * indexPage));
					index = ID_NV;
					return;
				}
			}
			else if (hieuChinh2.isMouseHover(xclick, yclick))
			{
				if (soLuongNhanVienTrenTable >= 2)
				{
					hienThiChinhSuaNV(DSNV, DSNV.getNhanVien(1 + itemTrenMotPage * indexPage));
					index = ID_NV;
					return;
				}
			}
			else if (hieuChinh3.isMouseHover(xclick, yclick))
			{
				if (soLuongNhanVienTrenTable >= 3)
				{
					hienThiChinhSuaNV(DSNV, DSNV.getNhanVien(2 + itemTrenMotPage * indexPage));
					index = ID_NV;
					return;
				}
			}
			else if (hieuChinh4.isMouseHover(xclick, yclick))
			{
				if (soLuongNhanVienTrenTable >= 4)
				{
					hienThiChinhSuaNV(DSNV, DSNV.getNhanVien(3 + itemTrenMotPage * indexPage));
					index = ID_NV;
					return;
				}
			}
			else if (hieuChinh5.isMouseHover(xclick, yclick))
			{
				if (soLuongNhanVienTrenTable >= 5)
				{
					hienThiChinhSuaNV(DSNV, DSNV.getNhanVien(4 + itemTrenMotPage * indexPage));
					index = ID_NV;
					return;
				}
			}
			else if (hieuChinh6.isMouseHover(xclick, yclick))
			{
				if (soLuongNhanVienTrenTable >= 6)
				{
					hienThiChinhSuaNV(DSNV, DSNV.getNhanVien(5 + itemTrenMotPage * indexPage));
					index = ID_NV;
					return;
				}
			}
			else if (hieuChinh7.isMouseHover(xclick, yclick))
			{
				if (soLuongNhanVienTrenTable >= 7)
				{
					hienThiChinhSuaNV(DSNV, DSNV.getNhanVien(6 + itemTrenMotPage * indexPage));
					index = ID_NV;
					return;
				}
			}
			else if (hieuChinh8.isMouseHover(xclick, yclick))
			{
				if (soLuongNhanVienTrenTable >= 8)
				{
					hienThiChinhSuaNV(DSNV, DSNV.getNhanVien(7 + itemTrenMotPage * indexPage));
					index = ID_NV;
					return;
				}
			}
			else if (hieuChinh9.isMouseHover(xclick, yclick))
			{
				if (soLuongNhanVienTrenTable >= 9)
				{
					hienThiChinhSuaNV(DSNV, DSNV.getNhanVien(8 + itemTrenMotPage * indexPage));
					index = ID_NV;
					return;
				}
			}
			else if (hieuChinh10.isMouseHover(xclick, yclick))
			{
				if (soLuongNhanVienTrenTable >= 10)
				{
					hienThiChinhSuaNV(DSNV, DSNV.getNhanVien(9 + itemTrenMotPage * indexPage));
					index = ID_NV;
					return;
				}
			}
			else if (hieuChinh11.isMouseHover(xclick, yclick))
			{
				if (soLuongNhanVienTrenTable >= 11)
				{
					hienThiChinhSuaNV(DSNV, DSNV.getNhanVien(9 + itemTrenMotPage * indexPage));
					index = ID_NV;
					return;
				}
			}
			else if (vatTu.isMouseHover(xclick, yclick))
			{
				index = ID_VT;
				return;
			}
			else if (hoaDon.isMouseHover(xclick, yclick))
			{
				index = ID_HD;
				return;
			}
			else if (doanhThu.isMouseHover(xclick, yclick))
			{
				index = ID_DT;
				return;
			}
		}
		delay(1);
	}
}
