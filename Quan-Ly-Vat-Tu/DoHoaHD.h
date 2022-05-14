#pragma once
using namespace std;
#include "Tienich.h"
#include "BienDoHoa.h"
void veTableCTHD();
void hienThiTableTroGiupXemdsNV(int &index, NutBam &vatTu, NutBam &nhanVien, NutBam &doanhThu, NutBam &themHDNhap, NutBam &themHDXuat, NutBam &TimKiemHD);
int hienThiCTHDLenTableKhongCoSua(int indexPage, int soLuongItemPage, ListCTHD *dsCTHD, BstVatTu &dsVatTu)
{
	const int marginTable = margin + 36;
	const int marginTop = 344;
	const int khoanCach = 40;
	int soLuongCTHD = dsCTHD->soLuongCTHD();
	NodeCTHD **arrCTHD = new NodeCTHD *[soLuongCTHD];
	dsCTHD->listToArray(arrCTHD);
	int dem = 0; // bien dung dem so luong cua CTHD tren table.
	string temp;
	for (int i = 0; i < soLuongItemPage; i++)
	{

		if (i + indexPage * soLuongItemPage < soLuongCTHD)
		{
			dem++;
			setcolor(CinputText);
			setbkcolor(0);
			settextstyle(6, 0, 1);
			outtextxy(marginTable + 6, marginTop + khoanCach * i, arrCTHD[i + indexPage * soLuongItemPage]->getmaVT().c_str());
			NodeVatTu *tempVT = dsVatTu.timKiemVT(arrCTHD[i + indexPage * soLuongItemPage]->getmaVT());
			outtextxy(marginTable + doDaiCoban, marginTop + khoanCach * i, tempVT->getInfo()->ten.c_str());
			outtextxy(marginTable + doDaiCoban * 3 + 12, marginTop + khoanCach * i, tempVT->getInfo()->donVi.c_str());
			temp = TienichDoHoa::floatToString(arrCTHD[i + indexPage * soLuongItemPage]->getSoLuong());
			outtextxy(marginTable + doDaiCoban * 4, marginTop + khoanCach * i, temp.c_str());
			temp = TienichDoHoa::floatToString(arrCTHD[i + indexPage * soLuongItemPage]->getDonGia());
			outtextxy(marginTable + doDaiCoban * 5, marginTop + khoanCach * i, temp.c_str());
			temp = TienichDoHoa::floatToString(arrCTHD[i + indexPage * soLuongItemPage]->getVAT());
			outtextxy(marginTable + doDaiCoban * 6 + 32, marginTop + khoanCach * i, temp.c_str());
			// in them giaTien cua hoadon ra
			temp = TienichDoHoa::floatToString(arrCTHD[i + indexPage * soLuongItemPage]->getTongTien());
			outtextxy(marginTable + doDaiCoban * 7, marginTop + khoanCach * i, temp.c_str());

			setcolor(15);
			line(marginTable - 34, marginTop + khoanCach * i + 26, marginTable + 1378, marginTop + khoanCach * i + 26);
		}
	}
	delete[] arrCTHD;
	return dem;
}

// ham hien thi ra cai bang ( table ) cua CTHD

// indexPage : trang dau tien hien thi!
// soLuongItemPage : so luong item tren 1 page
// viet ham hien Thi ra
// viet 1 ham in rieng ra day
// ham do bao gom:
// cac thong tin can in => chang han nhu moi dau vao ta KT

// ================================ HIEN THI TABLE CTHD ==========================================

void hienThiChiMuc(int x, int y, int indexPage, int toiDaPage)
{
	indexPage++;
	setcolor(CinputText);
	setbkcolor(0);
	settextstyle(6, 0, 1);
	string temp = TienichDoHoa::intToString(indexPage) + "/" + TienichDoHoa::intToString(toiDaPage);
	outtextxy(x, y, (char *)(temp.c_str()));
}

// ================================= VIET HAM HIEN THI HOA DON =======================================
void hienThiHoaDon(NhanVienLapHD &nvLapHD, BstVatTu &dsVatTu, int &index, NutBam &vatTu, NutBam &nhanVien, NutBam &doanhThu, NutBam &themHDNhap, NutBam &themHDXuat, NutBam &inHD, NutBam &xemdsNV, NutBam &xemdsVT)
{
	// xoa di man hinh !

	TienichDoHoa::xoaManHinhTheoToaDo(0, canLeTrenHD - 10, 1600, 1600, BACKGROUP);

	int indexPage = 0;
	int soLuongPhanTuHienThi = 0;
	int itemTrenMotPage = 9;

	int toaDoChiMucX = DODAIMANHINH / 2 - 110;
	int toaDoChiMucY = 740;

	int soLuongCTHD = nvLapHD.ptrHoaDon->getdsCTHD()->soLuongCTHD();
	int soLuongPage = soLuongCTHD / itemTrenMotPage;
	float toiDaPage = (float)soLuongCTHD / (float)itemTrenMotPage;
	if (!kiemTraSoNguyen(TienichDoHoa::floatToString(toiDaPage)))
	{
		toiDaPage = (int)toiDaPage + 1;
	}

	setcolor(13);  // mau Vang
	setbkcolor(0); // xet mau nen ve thanh mau den !
	settextstyle(6, 0, 4);
	outtextxy(650, 130, "HOA DON");
	setcolor(CinputText);
	setbkcolor(0);

	settextstyle(1, 0, 1);
	outtextxy(678, 180, nvLapHD.ptrHoaDon->getinfo()->date.getStringDate().c_str());
	string loaiHD;
	if (nvLapHD.ptrHoaDon->getinfo()->loai == "X")
	{
		loaiHD = "Loai: Xuat";
	}
	else
	{
		loaiHD = "Loai: Nhap";
	}
	outtextxy(100, 222, loaiHD.c_str());
	string soHD = "so HD: " + nvLapHD.ptrHoaDon->getinfo()->soHD;
	outtextxy(1210, 222, soHD.c_str());
	string hoTenNV = "NV lap HD: " + nvLapHD.ptrNhanVien->getHoTen();
	outtextxy(100, 246, hoTenNV.c_str());
	string maNV = "ma NV: " + nvLapHD.ptrNhanVien->maNV;
	outtextxy(1210, 246, maNV.c_str());

	// tiep theo la in ra CTHD => chi in ra va co cac nut thoi -> truyen vao cac tham so sau => goi lai lam thoi ->

	veTableCTHD();
	OVuong(52, 120, doDaiCoban * 9 + 30 + 4, 590, 15);
	NutBam mauNen(52, 180, 600, 40, 2, 3, 4, "");

	setcolor(CinputText);
	setbkcolor(0);
	settextstyle(6, 0, 1);
	outtextxy(margin + 1250, 736, TienichDoHoa::floatToString(nvLapHD.ptrHoaDon->getdsCTHD()->tinhTongTien()).c_str());

	// in ra bang CTHD  => trong cai nay se la 1 vong lap vo tan den khi nao nguoi dung chon ra cai khac thi thoi ?
	// ve ra cai khung :
	hienThiCTHDLenTableKhongCoSua(indexPage, itemTrenMotPage, nvLapHD.ptrHoaDon->getdsCTHD(), dsVatTu); // moi vao thi hien Thi index page thu nhat -> sau do co nhap chon thi tinh sau!
	hienThiChiMuc(toaDoChiMucX, toaDoChiMucY, indexPage, toiDaPage);
	// VE RA CAC CHI TIET XUNG QUANH

	NutBam btnTien(62 + 86, 740, 80, 40, 15, 0, 0, ">>");
	NutBam btnLui(62, 740, 80, 40, 15, 0, 0, "<<");
	btnTien.veNut();
	btnLui.veNut();

	int xclick = -1;
	int yclick = -1;
	// tiep theo bac dieu kien nguoi dung nhap vao cac nut khac -> thuc hien lai
	while (true)
	{
		if (ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_LBUTTONDOWN, xclick, yclick);
			// tiep tuc di kiem tra xem nguoi dung da nhap chon nhung gi => chan han nhu nguoi dung nhap chon vao btn HoTro
			if (btnTien.isMouseHover(xclick, yclick))
			{ //  bac dieu kien dung nhap vao nut tien toi. kiem tra xem co duoc duy chuyen khong !
				// cho nguoi dung nhay den page sau
				if (indexPage < toiDaPage - 1)
				{
					indexPage++; // nhay qua page khac !
					// ve table ( sau do ve ra lai tat ca
					veTableCTHD();
					OVuong(52, 120, doDaiCoban * 9 + 30 + 4, 590, 15);
					hienThiChiMuc(toaDoChiMucX, toaDoChiMucY, indexPage, toiDaPage);
					outtextxy(margin + 1250, 736, TienichDoHoa::floatToString(nvLapHD.ptrHoaDon->getdsCTHD()->tinhTongTien()).c_str());
					hienThiCTHDLenTableKhongCoSua(indexPage, itemTrenMotPage, nvLapHD.ptrHoaDon->getdsCTHD(), dsVatTu);
				}
			}
			else if (btnLui.isMouseHover(xclick, yclick))
			{
				if (indexPage > 0)
				{
					indexPage--;
					veTableCTHD();
					OVuong(52, 120, doDaiCoban * 9 + 30 + 4, 590, 15);

					hienThiChiMuc(toaDoChiMucX, toaDoChiMucY, indexPage, toiDaPage);
					outtextxy(margin + 1250, 736, TienichDoHoa::floatToString(nvLapHD.ptrHoaDon->getdsCTHD()->tinhTongTien()).c_str());
					hienThiCTHDLenTableKhongCoSua(indexPage, itemTrenMotPage, nvLapHD.ptrHoaDon->getdsCTHD(), dsVatTu);
				}
			}
			else if (themHDXuat.isMouseHover(xclick, yclick))
			{
				index = ID_THEM_HD_XUAT;
				return;
			}
			else if (themHDNhap.isMouseHover(xclick, yclick))
			{
				index = ID_THEM_HD_NHAP;
				return;
			}
			else if (xemdsNV.isMouseHover(xclick, yclick))
			{
				index = ID_GOI_Y_DSNV;
				return;
			}
			else if (xemdsVT.isMouseHover(xclick, yclick))
			{
				index = ID_GOI_Y_VT;
				return;
			}
			else if (inHD.isMouseHover(xclick, yclick))
			{
				index = ID_IN_HD;
				return;
			}
			else if (vatTu.isMouseHover(xclick, yclick))
			{
				index = ID_VT;
				return;
			}
			else if (nhanVien.isMouseHover(xclick, yclick))
			{
				index = ID_NV;
				return;
			}
			else if (doanhThu.isMouseHover(xclick, yclick))
			{
				index = ID_DT;
				return;
			}
		}

		delay(10);
	}
}

// ==================================== VIET HAM HIEN THI HO TRO DS NV ========================================
void hienThiTableTroGiupXemdsNV()
{
	TienichDoHoa::xoaManHinhTheoToaDo(0, canLeTrenHD - 10, 1600, 1600, BACKGROUP);
	NutBam titleMaNV(margin, canLeTrenHD + 170, doDaiCoban, 40, colorTieuDe, 7, conlorTextTieuDe, "maMV");
	NutBam titleHoTenNV(margin + doDaiCoban + 3, canLeTrenHD + 170, doDaiCoban * 2, 40, colorTieuDe, 7, conlorTextTieuDe, "ho ten NV");
	NutBam titleGioiTinh(margin + doDaiCoban * 3 + 3 * 2, canLeTrenHD + 170, doDaiCoban, 40, colorTieuDe, 7, conlorTextTieuDe, "gioi tinh");
	NutBam titleHDdaLap(margin + doDaiCoban * 4 + 3 * 3, canLeTrenHD + 170, doDaiCoban * 5 + 10, 40, colorTieuDe, 7, conlorTextTieuDe, "so HD da lap");
	titleMaNV.veNut();
	titleHoTenNV.veNut();
	titleGioiTinh.veNut();
	titleHDdaLap.veNut();
	OVuong table(margin, canLeTrenHD + 170, doDaiCoban * 9 + 18, 400, 15);
	setcolor(15);
	line(margin + doDaiCoban, canLeTrenHD + 170, margin + doDaiCoban, 690);
	line(margin + doDaiCoban * 3 + 3, canLeTrenHD + 170, margin + doDaiCoban * 3 + 3, 690);
	line(margin + doDaiCoban * 4 + 3 * 2, canLeTrenHD + 170, margin + doDaiCoban * 4 + 3 * 2, 690);
}

// ============================= DO HOA IN HOA DON DUA VAO MA HOA DON ================================
void hienThiDuLieuLenTableHoTro(dsNhanVien &DSNV, int &index, NutBam &vatTu, NutBam &nhanVien, NutBam &doanhThu,
								NutBam &taoHDXuat, NutBam &taoHDNhap, NutBam &inHD, NutBam &hoTroNV, NutBam &hoTroVT, int indexPage)
{ // truyen them cac thong so sau.
	int soLuongitemPage = 9;
	const int marginTable = margin + 36;
	const int marginTop = 354;
	const int khoanCach = 36;
	string temp;
	// tinh ra toiDapaga
	int toaDoChiMucX = DODAIMANHINH / 2 - 110;
	int toaDoChiMucY = 720;
	//	ONhap timKiemHD(56 ,117,200,40,130,"tim kiem HD",2,0,10);
	//	timKiemHD.veONhap();

	int soLuongNV = DSNV.soLuongNV();
	int soLuongPage = soLuongNV / soLuongitemPage;
	float toiDaPage = (float)soLuongNV / (float)soLuongitemPage;
	if (!kiemTraSoNguyen(TienichDoHoa::floatToString(toiDaPage)))
	{
		toiDaPage = (int)toiDaPage + 1;
	}

	setcolor(13);
	setbkcolor(0);
	settextstyle(1, 0, 4);
	outtextxy(260, 170, "DANH SACH NHAN VIEN VA HOA DON");

	// ve ra 2 nut -> bao gom tien va lui
	NutBam btnTien(margin + 1370, 712, 50, 40, 15, 3, 1, ">>");
	NutBam btnLui(margin, 712, 50, 40, 15, 3, 1, "<<");
	btnTien.veNut();
	btnLui.veNut();
	hienThiChiMuc(750, 716, indexPage, toiDaPage);

	for (int i = 0; i < soLuongitemPage; i++)
	{
		setcolor(CinputText);
		setbkcolor(0);
		settextstyle(6, 0, 1);
		if (i + indexPage * soLuongitemPage < DSNV.soLuongNV())
		{
			int index = i + indexPage * soLuongitemPage;
			outtextxy(marginTable, marginTop + khoanCach * i, DSNV.getNhanVien(index)->maNV.c_str());
			temp = DSNV.getNhanVien(index)->ho + " " + DSNV.getNhanVien(index)->ten;
			outtextxy(marginTable + doDaiCoban, marginTop + khoanCach * i, temp.c_str());
			if (DSNV.getNhanVien(index)->phai == 0)
			{
				temp = "nam";
			}
			else
			{
				temp = "nu";
			}
			outtextxy(marginTable + doDaiCoban * 3, marginTop + khoanCach * i, temp.c_str());
			temp = DSNV.getNhanVien(index)->dsHoaDon.ghepSoHD();
			outtextxy(marginTable + doDaiCoban * 4, marginTop + khoanCach * i, temp.c_str());
			setcolor(15);
			line(margin, marginTop + khoanCach * i + 28, doDaiCoban * 9 + 78, marginTop + khoanCach * i + 28);
		}
	}
	int xclick = -1;
	int yclick = -1;
	while (true)
	{

		if (ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_LBUTTONDOWN, xclick, yclick);

			if (vatTu.isMouseHover(xclick, yclick))
			{
				index = ID_VT;
				return;
			}
			if (nhanVien.isMouseHover(xclick, yclick))
			{
				index = ID_NV;
				return;
			}
			if (doanhThu.isMouseHover(xclick, yclick))
			{
				index = ID_DT;
				return;
			}
			if (taoHDXuat.isMouseHover(xclick, yclick))
			{
				index = ID_THEM_HD_XUAT;
				return;
			}
			if (taoHDNhap.isMouseHover(xclick, yclick))
			{
				index = ID_THEM_HD_NHAP;
				return;
			}
			if (inHD.isMouseHover(xclick, yclick))
			{
				index = ID_IN_HD;
				return;
			}
			if (hoTroVT.isMouseHover(xclick, yclick))
			{
				index = ID_GOI_Y_VT;
				return;
			}
			if (hoTroNV.isMouseHover(xclick, yclick))
			{
				index = ID_GOI_Y_DSNV;
				return;
			}
			if (btnTien.isMouseHover(xclick, yclick))
			{
				if (indexPage < toiDaPage - 1)
				{
					indexPage++; // nhay qua page khac !
					hienThiDuLieuLenTableHoTro(DSNV, index, vatTu, nhanVien, doanhThu, taoHDXuat, taoHDNhap, inHD, hoTroNV, hoTroVT, indexPage);
				}
			}
			else if (btnLui.isMouseHover(xclick, yclick))
			{
				if (indexPage > 0)
				{				 // chi khi nao indexPage lon hon thi moi duoc lui lai.
					indexPage--; // nhay qua page khac !
					hienThiDuLieuLenTableHoTro(DSNV, index, vatTu, nhanVien, doanhThu, taoHDXuat, taoHDNhap, inHD, hoTroNV, hoTroVT, indexPage);
				}
			}
		}
		delay(1);
	}
}

void hienThiXuatHoaDon(BstVatTu &dsVatTu, dsNhanVien &DSNV, int &index, NutBam &vatTu, NutBam &nhanVien, NutBam &doanhThu, NutBam &themHDNhap, NutBam &themHDXuat, NutBam &inHD, NutBam &hoTroNV, NutBam &hoTroVT)
{
	NhanVienLapHD nvLapHD; // chua 2 con tro ( hoa don va nv da lap hoa Don do! )
	TienichDoHoa::xoaManHinhTheoToaDo(0, canLeTrenHD, 1600, 1600, BACKGROUP);
	int indexPage = 0;
	int soLuongitemPage = 9;
	int w = 300;
	int h = 160;
	int y = 300;
	int x = DODAIMANHINH / 2 - w / 2;
	ONhap timKiemHD(54, 117, 200, 40, 130, "TIM KIEM HD: ", 0, 0, 10);
	timKiemHD.veONhap();

	int xclick = -1;
	int yclick = -1;

	while (true)
	{
		if (index != -1)
		{
			return;
		}
		if (ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_LBUTTONDOWN, xclick, yclick);
			if (timKiemHD.isMouseHover(xclick, yclick))
			{
				timKiemHD.NhapVao(kiTuChuHoacSo, "");
				if (timKiemHD.boNhoDem != "")
				{
					nvLapHD = DSNV.timKiemNhanVienLapHD(timKiemHD.boNhoDem);
					// kiem tra xem co khong neu khong co thi thong bao
					if (!nvLapHD.isNull())
					{ // co tim thay => goi toi ham hien thi ra.
						hienThiHoaDon(nvLapHD, dsVatTu, index, vatTu, nhanVien, doanhThu, themHDNhap, themHDXuat, inHD, hoTroNV, hoTroVT);
					}
					else
					{
						MessageBox(NULL, "khong ton tai so HD nay!", "thong bao", MB_ICONINFORMATION | MB_OK);
						timKiemHD.resetBoNhoDem();
					}
				}
			}
			else if (themHDXuat.isMouseHover(xclick, yclick))
			{
				index = ID_THEM_HD_XUAT;
				return;
			}
			else if (themHDNhap.isMouseHover(xclick, yclick))
			{
				index = ID_THEM_HD_NHAP;
				return;
			}
			else if (hoTroNV.isMouseHover(xclick, yclick))
			{
				index = ID_GOI_Y_DSNV;
				return;
			}
			else if (hoTroVT.isMouseHover(xclick, yclick))
			{
				index = ID_GOI_Y_VT;
				return;
			}
			else if (vatTu.isMouseHover(xclick, yclick))
			{
				index = ID_VT;
				return;
			}
			else if (nhanVien.isMouseHover(xclick, yclick))
			{
				index = ID_NV;
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

// ============================= HIEN THI HAM CHINH SUA CTHD ============================
void hienThiChinhSuaCTHD(NodeCTHD *tempCTHD, ListCTHD *dsCTHD, BstVatTu &dsVatTu, string loaiHD)
{
	// khai bao cac thong so
	int w = 540;
	int h = 358;
	int x = DODAIMANHINH / 2 - w / 2; // in r o nua man hinh
	int y = 332;
	NutBam box(x, y, w, h, 8, 0, 0, "");
	box.veNut();
	// ve ra nut dau X
	NutBam cancel(w + x - 40, y, 40, 40, 4, 2, 15, "X");
	cancel.veNut();
	NutBam title(x, y, w - 40, 40, 14, 0, 1, "HIEU CHINH CTHD");
	title.veNut();
	// ve ra 4 nut -> sau do tao ra cac hieu chinh =>
	ONhap maVT(x + 30, y + 46, w - 170, 40, 110, "MA VT: ", 8, 8, 10);
	ONhap soLuong(x + 30, y + 46 + 48 + 19, w - 170, 40, 110, "SO LUONG: ", 8, 8, 10);
	ONhap donGia(x + 30, y + 46 * 2 + 48 + 19 * 2, w - 170, 40, 110, "DON GIA: ", 8, 8, 10);
	ONhap VAT(x + 30, y + 46 * 3 + 48 + 19 * 3, w - 170, 40, 110, "VAT(%): ", 8, 8, 10);
	maVT.veONhap();
	soLuong.veONhap();
	donGia.veONhap();
	VAT.veONhap();
	NutBam hieuChinh(x + 30, y + 50 * 4 + 48 + 48 + 17, 234 + 6, 38, 13, 0, 0, "SUA");
	NutBam xoa(x + w - 40 - 234 + 6, y + 50 * 4 + 48 + 48 + 17, 234 + 6, 38, 13, 0, 0, "XOA");
	hieuChinh.veNut();

	xoa.veNut();

	// hien thi CTHD vao trong
	maVT.boNhoDem = tempCTHD->getinfo()->maVT;
	soLuong.boNhoDem = TienichDoHoa::floatToString(tempCTHD->getinfo()->soLuong);
	donGia.boNhoDem = TienichDoHoa::floatToString(tempCTHD->getinfo()->donGia);
	VAT.boNhoDem = TienichDoHoa::floatToString(tempCTHD->getinfo()->VAT);
	maVT.inNoiDung();
	soLuong.inNoiDung();
	donGia.inNoiDung();
	VAT.inNoiDung();

	// luu tru ra 4 gia tri cu -> khi nao khac thi moi dem ra so kiem tra tiep
	string maVTCu = maVT.boNhoDem;
	string soLuongCu = soLuong.boNhoDem;
	string donGiaCu = soLuong.boNhoDem;
	string VATCu = soLuong.boNhoDem;

	while (true)
	{
		if (ismouseclick(WM_LBUTTONDOWN))
		{
			int xclick = -1;
			int yclick = -1;
			getmouseclick(WM_LBUTTONDOWN, xclick, yclick);
			if (cancel.isMouseHover(xclick, yclick))
			{
				break; // ket thuc vong lap -> vi nguoi dung da thoat ra ngoai!
			}
			else if (maVT.isMouseHover(xclick, yclick))
			{
				maVT.NhapVao(kiTuChuHoacSo, ""); // nhap gi cung duoc => toi da bao nhieu ky tu.
				if (maVT.boNhoDem != maVTCu)
				{ // co su thay doi so voi truoc do thi moi di kiem tra
					if (dsVatTu.timKiemVT(maVT.boNhoDem) == NULL)
					{
						MessageBox(NULL, "thong bao", "khong ton tai vat tu nay!", MB_ICONINFORMATION | MB_OK);
						maVT.resetBoNhoDem();
					}
					else if (dsCTHD->timKiemCTHD(maVT.boNhoDem) != NULL)
					{
						MessageBox(NULL, "thong bao", "da ton tai vat tu nay!", MB_ICONINFORMATION | MB_OK);
						maVT.resetBoNhoDem();
					}
				}
			}
			else if (soLuong.isMouseHover(xclick, yclick))
			{
				soLuong.nhapSoThuc("chi nhap so thuc!");
			}
			else if (donGia.isMouseHover(xclick, yclick))
			{
				donGia.nhapSoThuc("chi nhap so thuc!");
			}
			else if (VAT.isMouseHover(xclick, yclick))
			{
				VAT.nhapSoThuc("chi nhap so thuc!");
				if (VAT.boNhoDem != VATCu)
				{
					if (TienichDoHoa::stringToFloat(VAT.boNhoDem) > 100)
					{
						MessageBox(NULL, "khong thoa man (VAT < 100%)!", "thong bao", MB_ICONINFORMATION | MB_OK);
						VAT.resetBoNhoDem();
					}
				}
			}
			else if (hieuChinh.isMouseHover(xclick, yclick))
			{
				if (maVT.boNhoDem == "" || soLuong.boNhoDem == "" || donGia.boNhoDem == "" || VAT.boNhoDem == "")
				{
					MessageBox(NULL, "thong bao", "khong duoc bo trong!", MB_ICONINFORMATION | MB_OK);
				}
				else if (maVT.boNhoDem != maVTCu || soLuong.boNhoDem != soLuongCu || donGia.boNhoDem != donGiaCu || VAT.boNhoDem != VATCu)
				{
					// thuc hien chinh sua ! -> phai khac
					// lay ra thang VT moi ra - kiem tra so Luonh
					NodeVatTu *tempVT = dsVatTu.timKiemVT(maVT.boNhoDem);
					// chi kiem tra trong truong hop la HD xuat con nhap thi khong can kiem tra
					if (loaiHD == "X")
					{
						if (!tempVT->getInfo()->kiemTraDuHang(TienichDoHoa::stringToFloat(soLuong.boNhoDem)))
						{
							string thongBao = "khong du so luong! so luong trong kho : " + TienichDoHoa::floatToString(tempVT->getInfo()->soLuongTon);
							MessageBox(NULL, thongBao.c_str(), "thong bao", MB_ICONINFORMATION | MB_OK);
							soLuong.resetBoNhoDem();
						}
						else
						{
							if (maVT.boNhoDem != maVTCu)
							{
								// so Luong LapCTHD cua maVT cu da thay doi
								NodeVatTu *vatTuCu = dsVatTu.timKiemVT(maVTCu);
								vatTuCu->getInfo()->soLanTaoCTHD--; // giam di so lan tao CTHD, tang do Lan Tao CTHD len
								tempVT->getInfo()->soLanTaoCTHD++;	// tang len so lan hien tai !
							}
							// khong co gi thay doi!
							tempCTHD->getinfo()->maVT = maVT.boNhoDem;
							tempCTHD->getinfo()->soLuong = TienichDoHoa::stringToFloat(soLuong.boNhoDem);
							tempCTHD->getinfo()->donGia = TienichDoHoa::stringToFloat(donGia.boNhoDem);
							tempCTHD->getinfo()->VAT = TienichDoHoa::stringToFloat(VAT.boNhoDem);

							MessageBox(NULL, "thong bao", "cap nhap thanh cong!", MB_ICONINFORMATION | MB_OK);
							break;
						}
					}
					else
					{
						if (maVT.boNhoDem != maVTCu)
						{
							// so Luong LapCTHD cua maVT cu da thay doi
							NodeVatTu *vatTuCu = dsVatTu.timKiemVT(maVTCu);
							vatTuCu->getInfo()->soLanTaoCTHD--; // giam di so lan tao CTHD, tang do Lan Tao CTHD len
							tempVT->getInfo()->soLanTaoCTHD++;	// tang len so lan hien tai !
						}
						// khong co gi thay doi!
						tempCTHD->getinfo()->maVT = maVT.boNhoDem;
						tempCTHD->getinfo()->soLuong = TienichDoHoa::stringToFloat(soLuong.boNhoDem);
						tempCTHD->getinfo()->donGia = TienichDoHoa::stringToFloat(donGia.boNhoDem);
						tempCTHD->getinfo()->VAT = TienichDoHoa::stringToFloat(VAT.boNhoDem);

						MessageBox(NULL, "thong bao", "cap nhap thanh cong!", MB_ICONINFORMATION | MB_OK);
						break;
					}
				}
			}

			else if (xoa.isMouseHover(xclick, yclick))
			{
				int luaChon = MessageBox(NULL, "ban co chac chac muon xoa!", "thong bao", MB_ICONWARNING | MB_OKCANCEL);
				if (luaChon == OK)
				{
					// tim kiem VT do
					NodeVatTu *vatTuDelete = dsVatTu.timKiemVT(maVTCu);
					vatTuDelete->getInfo()->soLanTaoCTHD--; // giam di so Lan Tao HD. Vi khong tao HD nay nua !
					if (dsCTHD->xoaCTHD(maVT.boNhoDem) == true)
					{
						break;
					}
					else
					{
						MessageBox(NULL, "thong bao", "khong ton tai Vat Tu nay", MB_ICONINFORMATION | MB_OK);
					}
				}
			}
		}
		delay(1);
	}
}

void veTableCTHD()
{
	TienichDoHoa::xoaManHinhTheoToaDo(margin, canLeTrenHD + 170, 1600, 400, BACKGROUP);
	NutBam titleMaVT(margin, canLeTrenHD + 170, doDaiCoban, 40, colorTieuDe, 7, conlorTextTieuDe, "MA VT");
	NutBam titileTenVT(margin + doDaiCoban + 3, canLeTrenHD + 170, doDaiCoban * 2, 40, colorTieuDe, 7, conlorTextTieuDe, "TEN VT");
	NutBam titiledonViVT(margin + doDaiCoban * 3 + 3 * 2, canLeTrenHD + 170, doDaiCoban, 40, colorTieuDe, 7, conlorTextTieuDe, "DVT");
	NutBam titilesoLuongVT(margin + doDaiCoban * 4 + 3 * 3, canLeTrenHD + 170, doDaiCoban, 40, colorTieuDe, 7, conlorTextTieuDe, "SO LUONG");
	NutBam titiledonGiaVT(margin + doDaiCoban * 5 + 3 * 4, canLeTrenHD + 170, doDaiCoban, 40, colorTieuDe, 7, conlorTextTieuDe, "DON GIA");
	NutBam titleVAT(margin + doDaiCoban * 6 + 3 * 5, canLeTrenHD + 170, doDaiCoban, 40, colorTieuDe, 7, conlorTextTieuDe, "VAT");
	NutBam thanhTien(margin + doDaiCoban * 7 + 3 * 6, canLeTrenHD + 170, doDaiCoban * 2, 40, colorTieuDe, 7, conlorTextTieuDe, "THANH TIEN");
	titleMaVT.veNut();
	titilesoLuongVT.veNut();
	titileTenVT.veNut();
	titiledonViVT.veNut();
	titiledonGiaVT.veNut();
	titleVAT.veNut();
	thanhTien.veNut();
	OVuong table(margin, canLeTrenHD + 170, doDaiCoban * 9 + 18, 400, 15);
	setcolor(15);
	line(margin + doDaiCoban, canLeTrenHD + 170, margin + doDaiCoban, 690);
	line(margin + doDaiCoban * 3 + 3, canLeTrenHD + 170, margin + doDaiCoban * 3 + 3, 690);
	line(margin + doDaiCoban * 4 + 3 * 2, canLeTrenHD + 170, margin + doDaiCoban * 4 + 3 * 2, 690);
	line(margin + doDaiCoban * 5 + 3 * 3, canLeTrenHD + 170, margin + doDaiCoban * 5 + 3 * 3, 690);
	line(margin + doDaiCoban * 6 + 3 * 4, canLeTrenHD + 170, margin + doDaiCoban * 6 + 3 * 4, 690);
	line(margin + doDaiCoban * 7 + 3 * 5, canLeTrenHD + 170, margin + doDaiCoban * 7 + 3 * 5, 690);
	setbkcolor(0);
	setcolor(15);
	outtextxy(margin + 1102, 736, "TONG TIEN: ");
}

// ngoai hien thi nen du lieu len tren 1 table -> ham con dung de tra ve so luong item tren 1 page
// ====================================== HAM IN RA DU LIEU LEN TABLE ======================================
int hienThiCTHDLenTable(int indexPage, int soLuongItemPage, ListCTHD *dsCTHD, BstVatTu &dsVatTu)
{
	const int marginTable = margin + 36;
	const int marginTop = 344;
	const int khoanCach = 40;
	int soLuongCTHD = dsCTHD->soLuongCTHD();
	NodeCTHD **arrCTHD = new NodeCTHD *[soLuongCTHD];
	dsCTHD->listToArray(arrCTHD);
	int dem = 0; // bien dung dem so luong cua CTHD tren table.
	string temp;
	for (int i = 0; i < soLuongItemPage; i++)
	{
		setcolor(CinputText);
		setbkcolor(0);
		settextstyle(6, 0, 1);
		if (i + indexPage * soLuongItemPage < soLuongCTHD)
		{
			dem++;
			outtextxy(marginTable + 6, marginTop + khoanCach * i, arrCTHD[i + indexPage * soLuongItemPage]->getmaVT().c_str());
			NodeVatTu *tempVT = dsVatTu.timKiemVT(arrCTHD[i + indexPage * soLuongItemPage]->getmaVT());
			outtextxy(marginTable + doDaiCoban, marginTop + khoanCach * i, tempVT->getInfo()->ten.c_str());
			outtextxy(marginTable + doDaiCoban * 3 + 20, marginTop + khoanCach * i, tempVT->getInfo()->donVi.c_str());
			temp = TienichDoHoa::floatToString(arrCTHD[i + indexPage * soLuongItemPage]->getSoLuong());
			outtextxy(marginTable + doDaiCoban * 4, marginTop + khoanCach * i, temp.c_str());
			temp = TienichDoHoa::floatToString(arrCTHD[i + indexPage * soLuongItemPage]->getDonGia());
			outtextxy(marginTable + doDaiCoban * 5, marginTop + khoanCach * i, temp.c_str());
			temp = TienichDoHoa::floatToString(arrCTHD[i + indexPage * soLuongItemPage]->getVAT());
			outtextxy(marginTable + doDaiCoban * 6 + 32, marginTop + khoanCach * i, temp.c_str());
			// in them giaTien cua hoadon ra
			temp = TienichDoHoa::floatToString(arrCTHD[i + indexPage * soLuongItemPage]->getTongTien());
			outtextxy(marginTable + doDaiCoban * 7, marginTop + khoanCach * i, temp.c_str());
			NutBam hieuChinh(marginTable + doDaiCoban * 7 + 190, marginTop + khoanCach * i - 4, 52, 28, 11, 2, 0, "SUA");
			hieuChinh.veNut();
			setcolor(15);
			line(marginTable - 34, marginTop + khoanCach * i + 26, marginTable + 1378, marginTop + khoanCach * i + 26);
		}
	}
	delete[] arrCTHD;
	return dem;
}

// viet ham hien thi Tong Tien

void hienThiTongTienCTHD(ListCTHD *dsCTHD)
{
	setcolor(CinputText);
	setbkcolor(0);
	settextstyle(6, 0, 1);
	TienichDoHoa::xoaManHinhTheoToaDo(margin + 1250, 720, margin + 1250 + 100, 720 + 100, BACKGROUP);
	outtextxy(margin + 1250, 736, TienichDoHoa::floatToString(dsCTHD->tinhTongTien()).c_str());
}

void hienThiThemHoaDonXuat(BstVatTu &dsVatTu, dsNhanVien &DSNV, int &index, NutBam &vatTu, NutBam &nhanVien, NutBam &doanhThu, NutBam &taoHDNhap, NutBam &inHD, NutBam &xemdsNV, NutBam &xemdsVT)
{
	TienichDoHoa::xoaManHinhTheoToaDo(0, 96, DODAIMANHINH, 1000, BACKGROUP);
	NhanVien *tempNV;
	NodeHoaDon *tempHD;
	NodeCTHD *pointerCTHD;
	NodeVatTu *tempVT;
	bool daThemHD = false;
	int indexPage = 0;
	int soPhanTuTrenMotPage = 9;
	int soLuongPage;
	float toiDaPage = 1;
	int soLuongCTHDTrenTable = 0;
	NutBam btnSave(margin + 1232, canLeTrenHD + 12, WHD * 2, HHD, mauNhapXuat, mauHightNhapXuat, 1, "SAVE");
	ONhap maNV(margin + 6, canLeTrenHD + 12, 210, 40, 60, "Ma NV: ", 0, 0, 10);
	ONhap soHD(margin + 320, canLeTrenHD + 12, 210, 40, 60, "Ma HD: ", 0, 0, 10);
	soHD.veONhap();
	maNV.veONhap();
	btnSave.veNut();
	Date tempDate;
	tempDate.setDateNow();
	int namHienTai = tempDate.nam;

	// VE NGAY THANG NAM
	ONhap nhapNgay(canLeNgangHD + 400 + 280, canLeTrenHD + 12, 65, 40, 60, "NGAY: ", 0, 0, 2);
	ONhap nhapThang(canLeNgangHD + 606 + 256, canLeTrenHD + 12, 65, 40, 70, "THANG: ", 0, 0, 2);
	ONhap nhapNam(canLeNgangHD + 1017 + 26, canLeTrenHD + 12, 100, 40, 70, "NAM: ", 0, 0, 4);
	nhapNgay.boNhoDem = TienichDoHoa::intToString(tempDate.ngay);
	nhapThang.boNhoDem = TienichDoHoa::intToString(tempDate.thang);
	nhapNam.boNhoDem = TienichDoHoa::intToString(tempDate.nam);
	nhapNam.veONhap();
	nhapNgay.veONhap();
	nhapThang.veONhap();
	nhapNgay.inNoiDung();
	nhapThang.inNoiDung();
	nhapNam.inNoiDung();
	ONhap maVT(margin + 6, canLeTrenHD + 90, 210, 40, 60, "MA VT: ", 0, 0, 10);

	ONhap soLuongVT(margin + 340, canLeTrenHD + 90, 130, 40, 96, "SO LUONG: ", 0, 0, 5);
	ONhap donGia(margin + 660, canLeTrenHD + 90, 130, 40, 96, "DON GIA: ", 0, 0, 5);
	ONhap VAT(margin + 990, canLeTrenHD + 90, 100, 40, 80, "VAT(%): ", 0, 0, 4);
	NutBam themTT(margin + 1230, canLeTrenHD + 90, WHD * 2, HHD, mauNhapXuat, mauHightNhapXuat, 1, "THEM CTHD");
	maVT.veONhap();
	soLuongVT.veONhap();
	donGia.veONhap();
	VAT.veONhap();
	themTT.veNut();

	// O VUONG BAO QUANH
	OVuong baoQuanhHD(54, canLeTrenHD, DODAIMANHINH - 12 - 102, 80, 15);
	OVuong baoQuanCTHD(54, canLeTrenHD + 80, DODAIMANHINH - 12 - 102, 80, 15);

	NutBam btnTienToi(margin + 56, 722, 50, 40, 15, 3, 1, ">>");
	NutBam btnLui(margin, 722, 50, 40, 15, 3, 1, "<<");

	btnTienToi.veNut();
	btnLui.veNut();
	veTableCTHD();

	// TOA DO NUT HIEU CHINH CTHD.
	NutBam hieuChinhCTHD1(margin + 36 + doDaiCoban * 7 + 190, 354 - 4, 52, 28, 11, 3, 0, "sua");
	NutBam hieuChinhCTHD2(margin + 36 + doDaiCoban * 7 + 190, 354 + 36 - 4, 52, 28, 11, 3, 0, "sua");
	NutBam hieuChinhCTHD3(margin + 36 + doDaiCoban * 7 + 190, 354 + 36 * 2 - 4, 52, 28, 11, 3, 0, "sua");
	NutBam hieuChinhCTHD4(margin + 36 + doDaiCoban * 7 + 190, 354 + 36 * 3 - 4, 52, 28, 11, 3, 0, "sua");
	NutBam hieuChinhCTHD5(margin + 36 + doDaiCoban * 7 + 190, 354 + 36 * 4 - 4, 52, 28, 11, 3, 0, "sua");
	NutBam hieuChinhCTHD6(margin + 36 + doDaiCoban * 7 + 190, 354 + 36 * 5 - 4, 52, 28, 11, 3, 0, "sua");
	NutBam hieuChinhCTHD7(margin + 36 + doDaiCoban * 7 + 190, 354 + 36 * 6 - 4, 52, 28, 11, 3, 0, "sua");
	NutBam hieuChinhCTHD8(margin + 36 + doDaiCoban * 7 + 190, 354 + 36 * 7 - 4, 52, 28, 11, 3, 0, "sua");
	NutBam hieuChinhCTHD9(margin + 36 + doDaiCoban * 7 + 190, 354 + 36 * 8 - 4, 52, 28, 11, 3, 0, "sua");

	while (true)
	{

		if (ismouseclick(WM_LBUTTONDOWN))
		{
			int xclick = -1;
			int yclick = -1;
			getmouseclick(WM_LBUTTONDOWN, xclick, yclick);
			if (nhanVien.isMouseHover(xclick, yclick))
			{
				index = ID_NV;
				return;
			}
			if (vatTu.isMouseHover(xclick, yclick))
			{
				index = ID_VT;
				return;
			}
			if (doanhThu.isMouseHover(xclick, yclick))
			{
				index = ID_DT;
				return;
			}

			if (inHD.isMouseHover(xclick, yclick))
			{
				index = ID_IN_HD;
				return;
			}
			if (taoHDNhap.isMouseHover(xclick, yclick))
			{
				index = ID_THEM_HD_NHAP;
				return;
			}
			if (xemdsNV.isMouseHover(xclick, yclick))
			{
				index = ID_GOI_Y_DSNV;
				return;
			}
			if (xemdsVT.isMouseHover(xclick, yclick))
			{
				index = ID_GOI_Y_VT;
				return;
			}

			if (maNV.isMouseHover(xclick, yclick))
			{
				maNV.NhapVao(kiTuChuHoacSo, ""); // xoa di khoan troan trang thua
				if (maNV.boNhoDem != "")
				{
					tempNV = DSNV.timKiemNVTraVeDiaChi(maNV.boNhoDem);
					if (!tempNV)
					{
						MessageBox(NULL, "Khong Ton Tai Nhan Vien Nay!", "Thong Bao", MB_ICONINFORMATION | MB_OK);
						maNV.resetBoNhoDem();
					}
				}
			}
			else if (soHD.isMouseHover(xclick, yclick))
			{

				soHD.NhapVao(kiTuChuHoacSo, "");
				if (DSNV.timKiemHD(soHD.boNhoDem) != NULL && !soHD.khongDuocNhap)
				{
					MessageBox(NULL, "Da ton tai maHD nay!", "Thong Bao", MB_ICONINFORMATION | MB_OK);
					soHD.resetBoNhoDem();
				}
			}
			else if (nhapNgay.isMouseHover(xclick, yclick))
			{
				nhapNgay.NhapVao(kiTuSo, "Chi nhap so!");
				tempDate.ngay = TienichDoHoa::stringToInt(nhapNgay.boNhoDem);
				if (nhapNgay.boNhoDem != "")
				{
					if (!Date::hopLeNgay(tempDate.ngay))
					{
						MessageBox(NULL, "Ngay Khong Hop Le!", "Thong Bao", MB_ICONINFORMATION | MB_OK);
						nhapNgay.resetBoNhoDem();
					}
					else if (nhapThang.boNhoDem != "" && nhapNam.boNhoDem != "")
					{

						tempDate.thang = TienichDoHoa::stringToInt(nhapThang.boNhoDem);
						tempDate.nam = TienichDoHoa::stringToInt(nhapNam.boNhoDem);
						if (!Date::ngayThangNamHopLe(tempDate))
						{
							MessageBox(NULL, "Ngay-Thang-Nam khong hop le!", "Thong Bao", MB_ICONINFORMATION | MB_OK);
							nhapNgay.resetBoNhoDem();
							nhapThang.resetBoNhoDem();
							nhapNam.resetBoNhoDem();
						}
					}
				}
			}
			else if (nhapThang.isMouseHover(xclick, yclick))
			{
				nhapThang.NhapVao(kiTuSo, "Chi nhap so!");
				tempDate.thang = TienichDoHoa::stringToInt(nhapThang.boNhoDem);
				if (nhapThang.boNhoDem != "")
				{
					if (!Date::hopLeThang(tempDate.thang))
					{
						MessageBox(NULL, "Thang Khong Hop Le!", "Thong Bao", MB_ICONINFORMATION | MB_OK);
						nhapThang.resetBoNhoDem();
					}
					else if (nhapNgay.boNhoDem != "" && nhapNam.boNhoDem != "")
					{
						tempDate.ngay = TienichDoHoa::stringToInt(nhapNgay.boNhoDem);
						tempDate.nam = TienichDoHoa::stringToInt(nhapNam.boNhoDem);
						if (!Date::ngayThangNamHopLe(tempDate))
						{
							MessageBox(NULL, "Ngay-Thang-Nam khong hop le!", "Thong Bao", MB_ICONINFORMATION | MB_OK);
							nhapNgay.resetBoNhoDem();
							nhapThang.resetBoNhoDem();
							nhapNam.resetBoNhoDem();
						}
					}
				}
			}
			else if (nhapNam.isMouseHover(xclick, yclick))
			{
				nhapNam.NhapVao(kiTuSo, "Chi nhap so!");
				tempDate.nam = TienichDoHoa::stringToInt(nhapNam.boNhoDem);
				if (nhapNam.boNhoDem != "")
				{
					if (!Date::hopLeNam(tempDate.nam))
					{
						MessageBox(NULL, "Nam Khong Hop Le!", "Thong Bao", MB_ICONINFORMATION | MB_OK);
						nhapNam.resetBoNhoDem();
					}
					else if (nhapNgay.boNhoDem != "" && nhapThang.boNhoDem != "")
					{
						tempDate.ngay = TienichDoHoa::stringToInt(nhapNgay.boNhoDem);
						tempDate.thang = TienichDoHoa::stringToInt(nhapThang.boNhoDem);
						if (!Date::ngayThangNamHopLe(tempDate))
						{
							MessageBox(NULL, "Ngay-Thang-Nam khong hop le!", "Thong Bao", MB_ICONINFORMATION | MB_OK);
							nhapNgay.resetBoNhoDem();
							nhapThang.resetBoNhoDem();
							nhapNam.resetBoNhoDem();
						}
					}
				}
			}
			else if (btnSave.isMouseHover(xclick, yclick))
			{
				const int chuaCoCTHD = 0;
				int soLuongCTHD = -1;
				// lay ra so Luong CTHD trong hoaDon => neu CTHD chua co => khong cho luu hoa Don !
				if (daThemHD)
				{
					soLuongCTHD = tempHD->getdsCTHD()->soLuongCTHD(); // lay ra so Luong CTHD
				}

				if (nhapNgay.boNhoDem == "" || nhapThang.boNhoDem == "" || nhapNam.boNhoDem == "" || maNV.boNhoDem == "" || soHD.boNhoDem == "")
				{
					MessageBox(NULL, "Vui Long Dien Vao Hoa Don!", "thong bao", MB_ICONINFORMATION | MB_OK);
				}
				else if (!daThemHD) // truong hop dsct hd dang rong!
				{
					MessageBox(NULL, "Vui Long Dien vao Chi Tiet Hoa Don!", "thong bao", MB_ICONINFORMATION | MB_OK);
				}
				else if (soLuongCTHD == chuaCoCTHD)
				{
					MessageBox(NULL, "chua them Chi Tiet Hoa Don!", "thong bao", MB_ICONINFORMATION | MB_OK);
				}
				else
				{
					MessageBox(NULL, "Luu Hoa Don Thanh Cong!", "thong bao", MB_ICONINFORMATION | MB_OK);
					tempHD->getdsCTHD()->capNhapSoLuongVatTu(dsVatTu, "X");
					tempNV->soLanTaoHD++; // tang len vi da lap 1 hoa don thanh cong !
					DSNV.ghiFileDSNV();
					dsVatTu.ghiFileVatTu();
					index = ID_THEM_HD_XUAT;
					return;
				}
			}

			// ==================== SAU KHI NHAP SONG MAVT==================

			else if (maVT.isMouseHover(xclick, yclick))
			{
				maVT.NhapVao(kiTuChuHoacSo, "");
				NodeVatTu *pTempMaVT = dsVatTu.timKiemVT(maVT.boNhoDem);
				if (pTempMaVT == NULL && maVT.boNhoDem != "")
				{
					MessageBox(NULL, "khong ton tai ma vat tu nay!", "thong bao", MB_ICONINFORMATION | MB_OK);
					maVT.resetBoNhoDem();
				}
				else if (daThemHD)
				{
					if (tempHD->getdsCTHD()->timKiemCTHD(maVT.boNhoDem))
					{ // boi vi chua them vaoHD
						MessageBox(NULL, "Da ton tai Vat Tu nay!", "Thong Bao", MB_ICONINFORMATION | MB_OK);
						maVT.resetBoNhoDem();
					}
				}
			}
			else if (soLuongVT.isMouseHover(xclick, yclick))
			{
				soLuongVT.nhapSoThuc("chi nhap so thuc!");
				// kiem tra neu nguoi dung nhap vao so 0 => khong thoa
				if (TienichDoHoa::stringToFloat(soLuongVT.boNhoDem) == 0)
				{
					MessageBox(NULL, "khong hop le!", "thong bao", MB_ICONINFORMATION | MB_OK);
					soLuongVT.resetBoNhoDem();
				}
			}
			else if (donGia.isMouseHover(xclick, yclick))
			{
				donGia.nhapSoThuc("chi nhap so thuc!");
			}
			else if (VAT.isMouseHover(xclick, yclick))
			{
				VAT.nhapSoThuc("chi nhap so thuc!");
				float tempVAT = TienichDoHoa::stringToFloat(VAT.boNhoDem);
				if (tempVAT > 100)
				{
					MessageBox(NULL, "khong hop le!", "thong bao", MB_ICONINFORMATION | MB_OK);
					VAT.resetBoNhoDem();
				}
			}
			else if (btnTienToi.isMouseHover(xclick, yclick))
			{
				if (indexPage < toiDaPage - 1)
				{
					indexPage++;
					veTableCTHD();
					hienThiTongTienCTHD(tempHD->getdsCTHD());
					soLuongCTHDTrenTable = hienThiCTHDLenTable(indexPage, soPhanTuTrenMotPage, tempHD->getdsCTHD(), dsVatTu);
					hienThiChiMuc(DODAIMANHINH / 2 - 110, 736, indexPage, toiDaPage);
				}
			}
			else if (btnLui.isMouseHover(xclick, yclick))
			{
				if (indexPage > 0)
				{
					indexPage--;
					veTableCTHD();
					hienThiTongTienCTHD(tempHD->getdsCTHD());
					soLuongCTHDTrenTable = hienThiCTHDLenTable(indexPage, soPhanTuTrenMotPage, tempHD->getdsCTHD(), dsVatTu);
					hienThiChiMuc(DODAIMANHINH / 2 - 110, 736, indexPage, toiDaPage);
				}
			}

			else if (themTT.isMouseHover(xclick, yclick))
			{
				if (!(nhapNgay.boNhoDem == "" || nhapThang.boNhoDem == "" || nhapNam.boNhoDem == "" || maNV.boNhoDem == "" || soHD.boNhoDem == "" || maVT.boNhoDem == "" || soLuongVT.boNhoDem == "" || donGia.boNhoDem == "" && VAT.boNhoDem == ""))
				{
					float tempSL = TienichDoHoa::stringToFloat(soLuongVT.boNhoDem);
					float tempdonGia = TienichDoHoa::stringToFloat(donGia.boNhoDem);
					float tempVAT = TienichDoHoa::stringToFloat(VAT.boNhoDem);
					if (!daThemHD)
					{
						tempDate.ngay = TienichDoHoa::stringToInt(nhapNgay.boNhoDem);
						tempDate.thang = TienichDoHoa::stringToInt(nhapThang.boNhoDem);
						tempDate.nam = TienichDoHoa::stringToInt(nhapNam.boNhoDem);

						maNV.voHieuHoa();
						soHD.voHieuHoa();
						nhapNgay.voHieuHoa();
						nhapThang.voHieuHoa();
						nhapNam.voHieuHoa();

						tempHD = tempNV->dsHoaDon.themVaoCuoiHD(soHD.boNhoDem, tempDate, "X", tempNV->getHoTen());
						daThemHD = true;
					}
					tempVT = dsVatTu.timKiemVT(maVT.boNhoDem); // chan chac tim thay -> vi tren kia da bac dieu kien

					if (!tempVT->getInfo()->kiemTraDuHang(tempSL))
					{
						string thongBao = +"khong du Vat Tu! so luong ton trong kho " + TienichDoHoa::floatToString(tempVT->getInfo()->soLuongTon);
						MessageBox(NULL, thongBao.c_str(), "thong bao", MB_ICONINFORMATION | MB_OK);
						soLuongVT.resetBoNhoDem();
					}
					else
					{
						// da thoa man -> khong cho xoa HD kia
						tempVT->getInfo()->soLanTaoCTHD++;							   // tang len vi da Them CTHD!
						CThoaDon tempCTHD(maVT.boNhoDem, tempSL, tempdonGia, tempVAT); // khi tat ca da thoa dieu kien.
						tempHD->themCTHD(tempCTHD);
						int soLuongCTHD = tempHD->getdsCTHD()->soLuongCTHD();
						soLuongPage = soLuongCTHD / soPhanTuTrenMotPage;
						toiDaPage = (float)soLuongCTHD / (float)soPhanTuTrenMotPage;
						if (!kiemTraSoNguyen(TienichDoHoa::floatToString(toiDaPage)))
						{
							toiDaPage = (int)toiDaPage + 1;
						}
						veTableCTHD();
						soLuongCTHDTrenTable = hienThiCTHDLenTable(indexPage, soPhanTuTrenMotPage, tempHD->getdsCTHD(), dsVatTu);
						maVT.resetBoNhoDem();
						soLuongVT.resetBoNhoDem();
						donGia.resetBoNhoDem();
						VAT.resetBoNhoDem();
						hienThiTongTienCTHD(tempHD->getdsCTHD());
						hienThiChiMuc(DODAIMANHINH / 2 - 110, 736, indexPage, toiDaPage);
					}
				}
				else
				{
					MessageBox(NULL, "khong duoc bo trong!", "thong bao", MB_ICONINFORMATION | MB_OK);
				}
			}

			else if (hieuChinhCTHD1.isMouseHover(xclick, yclick))
			{
				if (soLuongCTHDTrenTable != 0)
				{
					pointerCTHD = tempHD->getdsCTHD()->traVeCTHDTheoindex(soPhanTuTrenMotPage * indexPage);
					if (pointerCTHD != NULL)
					{
						hienThiChinhSuaCTHD(pointerCTHD, tempHD->getdsCTHD(), dsVatTu, "X");
						veTableCTHD();
						soLuongCTHDTrenTable = hienThiCTHDLenTable(indexPage, soPhanTuTrenMotPage, tempHD->getdsCTHD(), dsVatTu);
						hienThiChiMuc(DODAIMANHINH / 2 - 110, 736, indexPage, toiDaPage);
						hienThiTongTienCTHD(tempHD->getdsCTHD());
					}
				}
			}
			else if (hieuChinhCTHD2.isMouseHover(xclick, yclick))
			{
				if (soLuongCTHDTrenTable >= 1)
				{
					pointerCTHD = tempHD->getdsCTHD()->traVeCTHDTheoindex(1 + soPhanTuTrenMotPage * indexPage);
					if (pointerCTHD != NULL)
					{
						hienThiChinhSuaCTHD(pointerCTHD, tempHD->getdsCTHD(), dsVatTu, "X");
						veTableCTHD();
						soLuongCTHDTrenTable = hienThiCTHDLenTable(indexPage, soPhanTuTrenMotPage, tempHD->getdsCTHD(), dsVatTu);
						hienThiChiMuc(DODAIMANHINH / 2 - 110, 736, indexPage, toiDaPage);
						hienThiTongTienCTHD(tempHD->getdsCTHD());
					}
				}
			}
			else if (hieuChinhCTHD3.isMouseHover(xclick, yclick))
			{
				if (soLuongCTHDTrenTable >= 2)
				{
					pointerCTHD = tempHD->getdsCTHD()->traVeCTHDTheoindex(2 + soPhanTuTrenMotPage * indexPage);
					if (pointerCTHD != NULL)
					{
						hienThiChinhSuaCTHD(pointerCTHD, tempHD->getdsCTHD(), dsVatTu, "X");
						veTableCTHD();
						soLuongCTHDTrenTable = hienThiCTHDLenTable(indexPage, soPhanTuTrenMotPage, tempHD->getdsCTHD(), dsVatTu);
						hienThiChiMuc(DODAIMANHINH / 2 - 110, 736, indexPage, toiDaPage);
						hienThiTongTienCTHD(tempHD->getdsCTHD());
					}
				}
			}
			else if (hieuChinhCTHD4.isMouseHover(xclick, yclick))
			{
				if (soLuongCTHDTrenTable >= 3)
				{
					pointerCTHD = tempHD->getdsCTHD()->traVeCTHDTheoindex(3 + soPhanTuTrenMotPage * indexPage);
					if (pointerCTHD != NULL)
					{
						hienThiChinhSuaCTHD(pointerCTHD, tempHD->getdsCTHD(), dsVatTu, "X");
						veTableCTHD();
						soLuongCTHDTrenTable = hienThiCTHDLenTable(indexPage, soPhanTuTrenMotPage, tempHD->getdsCTHD(), dsVatTu);
						hienThiChiMuc(DODAIMANHINH / 2 - 110, 736, indexPage, toiDaPage);
						hienThiTongTienCTHD(tempHD->getdsCTHD());
					}
				}
			}
			else if (hieuChinhCTHD5.isMouseHover(xclick, yclick))
			{
				if (soLuongCTHDTrenTable >= 4)
				{
					pointerCTHD = tempHD->getdsCTHD()->traVeCTHDTheoindex(4 + soPhanTuTrenMotPage * indexPage);
					if (pointerCTHD != NULL)
					{
						hienThiChinhSuaCTHD(pointerCTHD, tempHD->getdsCTHD(), dsVatTu, "X");
						veTableCTHD();
						soLuongCTHDTrenTable = hienThiCTHDLenTable(indexPage, soPhanTuTrenMotPage, tempHD->getdsCTHD(), dsVatTu);
						hienThiChiMuc(DODAIMANHINH / 2 - 110, 736, indexPage, toiDaPage);
						hienThiTongTienCTHD(tempHD->getdsCTHD());
					}
				}
			}
			else if (hieuChinhCTHD6.isMouseHover(xclick, yclick))
			{
				if (soLuongCTHDTrenTable >= 5)
				{
					pointerCTHD = tempHD->getdsCTHD()->traVeCTHDTheoindex(5 + soPhanTuTrenMotPage * indexPage);
					if (pointerCTHD != NULL)
					{
						hienThiChinhSuaCTHD(pointerCTHD, tempHD->getdsCTHD(), dsVatTu, "X");
						veTableCTHD();
						soLuongCTHDTrenTable = hienThiCTHDLenTable(indexPage, soPhanTuTrenMotPage, tempHD->getdsCTHD(), dsVatTu);
						hienThiChiMuc(DODAIMANHINH / 2 - 110, 736, indexPage, toiDaPage);
						hienThiTongTienCTHD(tempHD->getdsCTHD());
					}
				}
			}
			else if (hieuChinhCTHD7.isMouseHover(xclick, yclick))
			{
				if (soLuongCTHDTrenTable >= 7)
				{
					pointerCTHD = tempHD->getdsCTHD()->traVeCTHDTheoindex(6 + soPhanTuTrenMotPage * indexPage);
					if (pointerCTHD != NULL)
					{
						hienThiChinhSuaCTHD(pointerCTHD, tempHD->getdsCTHD(), dsVatTu, "X");
						veTableCTHD();
						soLuongCTHDTrenTable = hienThiCTHDLenTable(indexPage, soPhanTuTrenMotPage, tempHD->getdsCTHD(), dsVatTu);
						hienThiChiMuc(DODAIMANHINH / 2 - 110, 736, indexPage, toiDaPage);
						hienThiTongTienCTHD(tempHD->getdsCTHD());
					}
				}
			}
			else if (hieuChinhCTHD8.isMouseHover(xclick, yclick))
			{
				if (soLuongCTHDTrenTable >= 8)
				{
					pointerCTHD = tempHD->getdsCTHD()->traVeCTHDTheoindex(7 + soPhanTuTrenMotPage * indexPage);
					if (pointerCTHD != NULL)
					{
						hienThiChinhSuaCTHD(pointerCTHD, tempHD->getdsCTHD(), dsVatTu, "X");
						veTableCTHD();
						soLuongCTHDTrenTable = hienThiCTHDLenTable(indexPage, soPhanTuTrenMotPage, tempHD->getdsCTHD(), dsVatTu);
						hienThiChiMuc(DODAIMANHINH / 2 - 110, 736, indexPage, toiDaPage);
						hienThiTongTienCTHD(tempHD->getdsCTHD());
					}
				}
			}
			else if (hieuChinhCTHD9.isMouseHover(xclick, yclick))
			{
				if (soLuongCTHDTrenTable >= 9)
				{
					pointerCTHD = tempHD->getdsCTHD()->traVeCTHDTheoindex(8 + soPhanTuTrenMotPage * indexPage);
					if (pointerCTHD != NULL)
					{
						hienThiChinhSuaCTHD(pointerCTHD, tempHD->getdsCTHD(), dsVatTu, "X");
						veTableCTHD();
						soLuongCTHDTrenTable = hienThiCTHDLenTable(indexPage, soPhanTuTrenMotPage, tempHD->getdsCTHD(), dsVatTu);
						hienThiChiMuc(DODAIMANHINH / 2 - 110, 736, indexPage, toiDaPage);
						hienThiTongTienCTHD(tempHD->getdsCTHD());
					}
				}
			}
		}
		delay(10);
	}
}

//    HIEN THI THEM HD NHAP
void hienThiThemHoaDonNhap(BstVatTu &dsVatTu, dsNhanVien &DSNV, int &index, NutBam &vatTu, NutBam &nhanVien, NutBam &doanhThu, NutBam &taoHDXuat, NutBam &inHD, NutBam &xemdsNV, NutBam &xemdsVT)
{
	TienichDoHoa::xoaManHinhTheoToaDo(0, 96, DODAIMANHINH, 1000, BACKGROUP);
	NhanVien *tempNV;
	NodeHoaDon *tempHD;
	NodeCTHD *pointerCTHD;
	NodeVatTu *tempVT;
	bool daThemHD = false;
	int indexPage = 0;
	int soPhanTuTrenMotPage = 9;
	int soLuongPage;
	float toiDaPage = 1;
	int soLuongCTHDTrenTable = 0;
	NutBam btnSave(margin + 1232, canLeTrenHD + 12, WHD * 2, HHD, mauNhapXuat, mauHightNhapXuat, 1, "SAVE");
	ONhap maNV(margin + 6, canLeTrenHD + 12, 210, 40, 60, "Ma NV: ", 0, 0, 10);
	ONhap soHD(margin + 320, canLeTrenHD + 12, 210, 40, 60, "Ma HD: ", 0, 0, 10);
	soHD.veONhap();
	maNV.veONhap();
	btnSave.veNut();
	Date tempDate;
	tempDate.setDateNow();
	int namHienTai = tempDate.nam;

	// VE NGAY THANG NAM
	ONhap nhapNgay(canLeNgangHD + 400 + 280, canLeTrenHD + 12, 65, 40, 60, "NGAY: ", 0, 0, 2);
	ONhap nhapThang(canLeNgangHD + 606 + 256, canLeTrenHD + 12, 65, 40, 70, "THANG: ", 0, 0, 2);
	ONhap nhapNam(canLeNgangHD + 1017 + 26, canLeTrenHD + 12, 100, 40, 70, "NAM: ", 0, 0, 4);
	nhapNgay.boNhoDem = TienichDoHoa::intToString(tempDate.ngay);
	nhapThang.boNhoDem = TienichDoHoa::intToString(tempDate.thang);
	nhapNam.boNhoDem = TienichDoHoa::intToString(tempDate.nam);
	nhapNam.veONhap();
	nhapNgay.veONhap();
	nhapThang.veONhap();
	nhapNgay.inNoiDung();
	nhapThang.inNoiDung();
	nhapNam.inNoiDung();
	ONhap maVT(margin + 6, canLeTrenHD + 90, 210, 40, 60, "MA VT: ", 0, 0, 10);

	ONhap soLuongVT(margin + 340, canLeTrenHD + 90, 130, 40, 96, "SO LUONG: ", 0, 0, 5);
	ONhap donGia(margin + 660, canLeTrenHD + 90, 130, 40, 96, "DON GIA: ", 0, 0, 5);
	ONhap VAT(margin + 990, canLeTrenHD + 90, 100, 40, 80, "VAT(%): ", 0, 0, 4);
	NutBam themTT(margin + 1230, canLeTrenHD + 90, WHD * 2, HHD, mauNhapXuat, mauHightNhapXuat, 1, "THEM CTHD");
	maVT.veONhap();
	soLuongVT.veONhap();
	donGia.veONhap();
	VAT.veONhap();
	themTT.veNut();

	// O VUONG BAO QUANH
	OVuong baoQuanhHD(54, canLeTrenHD, DODAIMANHINH - 12 - 102, 80, 15);
	OVuong baoQuanCTHD(54, canLeTrenHD + 80, DODAIMANHINH - 12 - 102, 80, 15);

	NutBam btnTienToi(margin + 56, 722, 50, 40, 15, 3, 1, ">>");
	NutBam btnLui(margin, 722, 50, 40, 15, 3, 1, "<<");

	btnTienToi.veNut();
	btnLui.veNut();
	veTableCTHD();

	// TOA DO NUT HIEU CHINH CTHD.
	NutBam hieuChinhCTHD1(margin + 36 + doDaiCoban * 7 + 190, 354 - 4, 52, 28, 11, 3, 0, "sua");
	NutBam hieuChinhCTHD2(margin + 36 + doDaiCoban * 7 + 190, 354 + 36 - 4, 52, 28, 11, 3, 0, "sua");
	NutBam hieuChinhCTHD3(margin + 36 + doDaiCoban * 7 + 190, 354 + 36 * 2 - 4, 52, 28, 11, 3, 0, "sua");
	NutBam hieuChinhCTHD4(margin + 36 + doDaiCoban * 7 + 190, 354 + 36 * 3 - 4, 52, 28, 11, 3, 0, "sua");
	NutBam hieuChinhCTHD5(margin + 36 + doDaiCoban * 7 + 190, 354 + 36 * 4 - 4, 52, 28, 11, 3, 0, "sua");
	NutBam hieuChinhCTHD6(margin + 36 + doDaiCoban * 7 + 190, 354 + 36 * 5 - 4, 52, 28, 11, 3, 0, "sua");
	NutBam hieuChinhCTHD7(margin + 36 + doDaiCoban * 7 + 190, 354 + 36 * 6 - 4, 52, 28, 11, 3, 0, "sua");
	NutBam hieuChinhCTHD8(margin + 36 + doDaiCoban * 7 + 190, 354 + 36 * 7 - 4, 52, 28, 11, 3, 0, "sua");
	NutBam hieuChinhCTHD9(margin + 36 + doDaiCoban * 7 + 190, 354 + 36 * 8 - 4, 52, 28, 11, 3, 0, "sua");

	while (true)
	{
		if (ismouseclick(WM_LBUTTONDOWN))
		{
			int xclick = -1;
			int yclick = -1;
			getmouseclick(WM_LBUTTONDOWN, xclick, yclick);
			if (nhanVien.isMouseHover(xclick, yclick))
			{
				index = ID_NV;
				return;
			}
			if (vatTu.isMouseHover(xclick, yclick))
			{
				index = ID_VT;
				return;
			}
			if (doanhThu.isMouseHover(xclick, yclick))
			{
				index = ID_DT;
				return;
			}

			if (inHD.isMouseHover(xclick, yclick))
			{
				index = ID_IN_HD;
				return;
			}
			if (taoHDXuat.isMouseHover(xclick, yclick))
			{
				index = ID_THEM_HD_XUAT;
				return;
			}
			if (xemdsNV.isMouseHover(xclick, yclick))
			{
				index = ID_GOI_Y_DSNV;
				return;
			}
			if (xemdsVT.isMouseHover(xclick, yclick))
			{
				index = ID_GOI_Y_VT;
				return;
			}

			if (maNV.isMouseHover(xclick, yclick))
			{
				maNV.NhapVao(kiTuChuHoacSo, ""); // xoa di khoan troan trang thua
				if (maNV.boNhoDem != "")
				{
					tempNV = DSNV.timKiemNVTraVeDiaChi(maNV.boNhoDem);
					if (!tempNV)
					{
						MessageBox(NULL, "Khong Ton Tai Nhan Vien Nay!", "Thong Bao", MB_ICONINFORMATION | MB_OK);
						maNV.resetBoNhoDem();
					}
				}
			}
			else if (soHD.isMouseHover(xclick, yclick))
			{
				soHD.NhapVao(kiTuChuHoacSo, "");
				if (DSNV.timKiemHD(soHD.boNhoDem) != NULL && !soHD.khongDuocNhap)
				{
					MessageBox(NULL, "Da ton tai maHD nay!", "Thong Bao", MB_ICONINFORMATION | MB_OK);
					soHD.resetBoNhoDem();
				}
			}
			else if (nhapNgay.isMouseHover(xclick, yclick))
			{
				nhapNgay.NhapVao(kiTuSo, "Chi nhap so!");
				tempDate.ngay = TienichDoHoa::stringToInt(nhapNgay.boNhoDem);
				if (nhapNgay.boNhoDem != "")
				{
					if (!Date::hopLeNgay(tempDate.ngay))
					{
						MessageBox(NULL, "Ngay Khong Hop Le!", "Thong Bao", MB_ICONINFORMATION | MB_OK);
						nhapNgay.resetBoNhoDem();
					}
					else if (nhapThang.boNhoDem != "" && nhapNam.boNhoDem != "")
					{
						tempDate.thang = TienichDoHoa::stringToInt(nhapThang.boNhoDem);
						tempDate.nam = TienichDoHoa::stringToInt(nhapNam.boNhoDem);
						if (!Date::ngayThangNamHopLe(tempDate))
						{
							MessageBox(NULL, "Ngay-Thang-Nam khong hop le!", "Thong Bao", MB_ICONINFORMATION | MB_OK);
							nhapNgay.resetBoNhoDem();
							nhapThang.resetBoNhoDem();
							nhapNam.resetBoNhoDem();
						}
					}
				}
			}
			else if (nhapThang.isMouseHover(xclick, yclick))
			{
				nhapThang.NhapVao(kiTuSo, "Chi nhap so!");
				tempDate.thang = TienichDoHoa::stringToInt(nhapThang.boNhoDem);
				if (nhapThang.boNhoDem != "")
				{
					if (!Date::hopLeThang(tempDate.thang))
					{
						MessageBox(NULL, "Thang Khong Hop Le!", "Thong Bao", MB_ICONINFORMATION | MB_OK);
						nhapThang.resetBoNhoDem();
					}
					else if (nhapNgay.boNhoDem != "" && nhapNam.boNhoDem != "")
					{
						tempDate.ngay = TienichDoHoa::stringToInt(nhapNgay.boNhoDem);
						tempDate.nam = TienichDoHoa::stringToInt(nhapNam.boNhoDem);
						if (!Date::ngayThangNamHopLe(tempDate))
						{
							MessageBox(NULL, "Ngay-Thang-Nam khong hop le!", "Thong Bao", MB_ICONINFORMATION | MB_OK);
							nhapNgay.resetBoNhoDem();
							nhapThang.resetBoNhoDem();
							nhapNam.resetBoNhoDem();
						}
					}
				}
			}
			else if (nhapNam.isMouseHover(xclick, yclick))
			{
				nhapNam.NhapVao(kiTuSo, "Chi nhap so!");
				tempDate.nam = TienichDoHoa::stringToInt(nhapNam.boNhoDem);
				if (nhapNam.boNhoDem != "")
				{
					if (!Date::hopLeNam(tempDate.nam))
					{
						MessageBox(NULL, "Nam Khong Hop Le!", "Thong Bao", MB_ICONINFORMATION | MB_OK);
						nhapNam.resetBoNhoDem();
					}
					else if (nhapNgay.boNhoDem != "" && nhapThang.boNhoDem != "")
					{
						tempDate.ngay = TienichDoHoa::stringToInt(nhapNgay.boNhoDem);
						tempDate.thang = TienichDoHoa::stringToInt(nhapThang.boNhoDem);
						if (!Date::ngayThangNamHopLe(tempDate))
						{
							MessageBox(NULL, "Ngay-Thang-Nam khong hop le!", "Thong Bao", MB_ICONINFORMATION | MB_OK);
							nhapNgay.resetBoNhoDem();
							nhapThang.resetBoNhoDem();
							nhapNam.resetBoNhoDem();
						}
					}
				}
			}
			else if (btnSave.isMouseHover(xclick, yclick))
			{
				if (nhapNgay.boNhoDem == "" || nhapThang.boNhoDem == "" || nhapNam.boNhoDem == "" || maNV.boNhoDem == "" || soHD.boNhoDem == "")
				{
					MessageBox(NULL, "Vui Long Dien Vao Hoa Don!", "thong bao", MB_ICONINFORMATION | MB_OK);
				}
				else if (!daThemHD)
				{ // truong hop dsct hd dang rong!
					MessageBox(NULL, "Vui Long Dien vao Chi Tiet Hoa Don!", "thong bao", MB_ICONINFORMATION | MB_OK);
				}
				else
				{
					MessageBox(NULL, "Luu Hoa Don Thanh Cong!", "thong bao", MB_ICONINFORMATION | MB_OK);
					tempHD->getdsCTHD()->capNhapSoLuongVatTu(dsVatTu, "N");

					tempNV->soLanTaoHD++; // tang so Luong tao HD cua nhan vien do len !
					DSNV.ghiFileDSNV();
					dsVatTu.ghiFileVatTu();
					index = ID_THEM_HD_NHAP;
					return;
				}
			}

			// ==================== SAU KHI NHAP SONG MAVT==================

			else if (maVT.isMouseHover(xclick, yclick))
			{
				maVT.NhapVao(kiTuChuHoacSo, "");
				NodeVatTu *pTempMaVT = dsVatTu.timKiemVT(maVT.boNhoDem);
				if (pTempMaVT == NULL && maVT.boNhoDem != "")
				{
					MessageBox(NULL, "khong ton tai ma vat tu nay!", "thong bao", MB_ICONINFORMATION | MB_OK);
					maVT.resetBoNhoDem();
				}
				else if (daThemHD)
				{
					if (tempHD->getdsCTHD()->timKiemCTHD(maVT.boNhoDem))
					{ // boi vi chua them vaoHD
						MessageBox(NULL, "Da ton tai Vat Tu nay!", "Thong Bao", MB_ICONINFORMATION | MB_OK);
						maVT.resetBoNhoDem();
					}
				}
			}
			else if (soLuongVT.isMouseHover(xclick, yclick))
			{
				soLuongVT.nhapSoThuc("chi nhap so thuc!");
				// kiem tra neu nguoi dung nhap vao so 0 => khong thoa
				if (TienichDoHoa::stringToFloat(soLuongVT.boNhoDem) == 0)
				{
					MessageBox(NULL, "khong hop le!", "thong bao", MB_ICONINFORMATION | MB_OK);
					soLuongVT.resetBoNhoDem();
				}
			}
			else if (donGia.isMouseHover(xclick, yclick))
			{
				donGia.nhapSoThuc("chi nhap so thuc!");
			}
			else if (VAT.isMouseHover(xclick, yclick))
			{
				VAT.nhapSoThuc("chi nhap so thuc!");
				float tempVAT = TienichDoHoa::stringToFloat(VAT.boNhoDem);
				if (tempVAT > 100)
				{
					MessageBox(NULL, "khong hop le!", "thong bao", MB_ICONINFORMATION | MB_OK);
					VAT.resetBoNhoDem();
				}
			}
			else if (btnTienToi.isMouseHover(xclick, yclick))
			{
				if (indexPage < toiDaPage - 1)
				{
					indexPage++;
					veTableCTHD();
					soLuongCTHDTrenTable = hienThiCTHDLenTable(indexPage, soPhanTuTrenMotPage, tempHD->getdsCTHD(), dsVatTu);
					hienThiTongTienCTHD(tempHD->getdsCTHD());
					hienThiChiMuc(DODAIMANHINH / 2 - 110, 736, indexPage, toiDaPage);
				}
			}
			else if (btnLui.isMouseHover(xclick, yclick))
			{
				if (indexPage > 0)
				{
					indexPage--;
					veTableCTHD();
					soLuongCTHDTrenTable = hienThiCTHDLenTable(indexPage, soPhanTuTrenMotPage, tempHD->getdsCTHD(), dsVatTu);
					hienThiTongTienCTHD(tempHD->getdsCTHD());
					hienThiChiMuc(DODAIMANHINH / 2 - 110, 736, indexPage, toiDaPage);
				}
			}

			else if (themTT.isMouseHover(xclick, yclick))
			{
				if (!(nhapNgay.boNhoDem == "" || nhapThang.boNhoDem == "" || nhapNam.boNhoDem == "" || maNV.boNhoDem == "" || soHD.boNhoDem == "" || maVT.boNhoDem == "" || soLuongVT.boNhoDem == "" || donGia.boNhoDem == "" && VAT.boNhoDem == ""))
				{
					float tempSL = TienichDoHoa::stringToFloat(soLuongVT.boNhoDem);
					float tempdonGia = TienichDoHoa::stringToFloat(donGia.boNhoDem);
					float tempVAT = TienichDoHoa::stringToFloat(VAT.boNhoDem);
					if (!daThemHD)
					{
						tempDate.ngay = TienichDoHoa::stringToInt(nhapNgay.boNhoDem);
						tempDate.thang = TienichDoHoa::stringToInt(nhapThang.boNhoDem);
						tempDate.nam = TienichDoHoa::stringToInt(nhapNam.boNhoDem);

						maNV.voHieuHoa();
						soHD.voHieuHoa();
						nhapNgay.voHieuHoa();
						nhapThang.voHieuHoa();
						nhapNam.voHieuHoa();

						tempHD = tempNV->dsHoaDon.themVaoCuoiHD(soHD.boNhoDem, tempDate, "N", tempNV->getHoTen());
						daThemHD = true;
					}
					tempVT = dsVatTu.timKiemVT(maVT.boNhoDem); // chan chac tim thay -> vi tren kia da bac dieu kien

					// da thoa man -> khong cho xoa HD kia
					tempVT->getInfo()->soLanTaoCTHD++;							   // tang len vi da Them CTHD!
					CThoaDon tempCTHD(maVT.boNhoDem, tempSL, tempdonGia, tempVAT); // khi tat ca da thoa dieu kien.
					tempHD->themCTHD(tempCTHD);
					int soLuongCTHD = tempHD->getdsCTHD()->soLuongCTHD();
					soLuongPage = soLuongCTHD / soPhanTuTrenMotPage;
					toiDaPage = (float)soLuongCTHD / (float)soPhanTuTrenMotPage;
					if (!kiemTraSoNguyen(TienichDoHoa::floatToString(toiDaPage)))
					{
						toiDaPage = (int)toiDaPage + 1;
					}
					veTableCTHD();
					soLuongCTHDTrenTable = hienThiCTHDLenTable(indexPage, soPhanTuTrenMotPage, tempHD->getdsCTHD(), dsVatTu);
					hienThiChiMuc(DODAIMANHINH / 2 - 110, 736, indexPage, toiDaPage);
					maVT.resetBoNhoDem();
					soLuongVT.resetBoNhoDem();
					donGia.resetBoNhoDem();
					VAT.resetBoNhoDem();
					hienThiTongTienCTHD(tempHD->getdsCTHD());
				}
				else
				{
					MessageBox(NULL, "khong duoc bo trong!", "thong bao", MB_ICONINFORMATION | MB_OK);
				}
			}

			else if (hieuChinhCTHD1.isMouseHover(xclick, yclick))
			{
				if (soLuongCTHDTrenTable != 0)
				{
					pointerCTHD = tempHD->getdsCTHD()->traVeCTHDTheoindex(soPhanTuTrenMotPage * indexPage);
					if (pointerCTHD != NULL)
					{
						hienThiChinhSuaCTHD(pointerCTHD, tempHD->getdsCTHD(), dsVatTu, "N");
						veTableCTHD();
						soLuongCTHDTrenTable = hienThiCTHDLenTable(indexPage, soPhanTuTrenMotPage, tempHD->getdsCTHD(), dsVatTu);
						hienThiChiMuc(DODAIMANHINH / 2 - 110, 736, indexPage, toiDaPage);
						hienThiTongTienCTHD(tempHD->getdsCTHD());
					}
				}
			}
			else if (hieuChinhCTHD2.isMouseHover(xclick, yclick))
			{
				if (soLuongCTHDTrenTable >= 1)
				{
					pointerCTHD = tempHD->getdsCTHD()->traVeCTHDTheoindex(1 + soPhanTuTrenMotPage * indexPage);
					if (pointerCTHD != NULL)
					{
						hienThiChinhSuaCTHD(pointerCTHD, tempHD->getdsCTHD(), dsVatTu, "N");
						veTableCTHD();
						soLuongCTHDTrenTable = hienThiCTHDLenTable(indexPage, soPhanTuTrenMotPage, tempHD->getdsCTHD(), dsVatTu);
						hienThiChiMuc(DODAIMANHINH / 2 - 110, 736, indexPage, toiDaPage);
						hienThiTongTienCTHD(tempHD->getdsCTHD());
					}
				}
			}
			else if (hieuChinhCTHD3.isMouseHover(xclick, yclick))
			{
				if (soLuongCTHDTrenTable >= 2)
				{
					pointerCTHD = tempHD->getdsCTHD()->traVeCTHDTheoindex(2 + soPhanTuTrenMotPage * indexPage);
					if (pointerCTHD != NULL)
					{
						hienThiChinhSuaCTHD(pointerCTHD, tempHD->getdsCTHD(), dsVatTu, "N");
						veTableCTHD();
						soLuongCTHDTrenTable = hienThiCTHDLenTable(indexPage, soPhanTuTrenMotPage, tempHD->getdsCTHD(), dsVatTu);
						hienThiChiMuc(DODAIMANHINH / 2 - 110, 736, indexPage, toiDaPage);
						hienThiTongTienCTHD(tempHD->getdsCTHD());
					}
				}
			}
			else if (hieuChinhCTHD4.isMouseHover(xclick, yclick))
			{
				if (soLuongCTHDTrenTable >= 3)
				{
					pointerCTHD = tempHD->getdsCTHD()->traVeCTHDTheoindex(3 + soPhanTuTrenMotPage * indexPage);
					if (pointerCTHD != NULL)
					{
						hienThiChinhSuaCTHD(pointerCTHD, tempHD->getdsCTHD(), dsVatTu, "N");
						veTableCTHD();
						soLuongCTHDTrenTable = hienThiCTHDLenTable(indexPage, soPhanTuTrenMotPage, tempHD->getdsCTHD(), dsVatTu);
						hienThiChiMuc(DODAIMANHINH / 2 - 110, 736, indexPage, toiDaPage);
						hienThiTongTienCTHD(tempHD->getdsCTHD());
					}
				}
			}
			else if (hieuChinhCTHD5.isMouseHover(xclick, yclick))
			{
				if (soLuongCTHDTrenTable >= 4)
				{
					pointerCTHD = tempHD->getdsCTHD()->traVeCTHDTheoindex(4 + soPhanTuTrenMotPage * indexPage);
					if (pointerCTHD != NULL)
					{
						hienThiChinhSuaCTHD(pointerCTHD, tempHD->getdsCTHD(), dsVatTu, "N");
						veTableCTHD();
						soLuongCTHDTrenTable = hienThiCTHDLenTable(indexPage, soPhanTuTrenMotPage, tempHD->getdsCTHD(), dsVatTu);
						hienThiChiMuc(DODAIMANHINH / 2 - 110, 736, indexPage, toiDaPage);
						hienThiTongTienCTHD(tempHD->getdsCTHD());
					}
				}
			}
			else if (hieuChinhCTHD6.isMouseHover(xclick, yclick))
			{
				if (soLuongCTHDTrenTable >= 5)
				{
					pointerCTHD = tempHD->getdsCTHD()->traVeCTHDTheoindex(5 + soPhanTuTrenMotPage * indexPage);
					if (pointerCTHD != NULL)
					{
						hienThiChinhSuaCTHD(pointerCTHD, tempHD->getdsCTHD(), dsVatTu, "N");
						veTableCTHD();
						soLuongCTHDTrenTable = hienThiCTHDLenTable(indexPage, soPhanTuTrenMotPage, tempHD->getdsCTHD(), dsVatTu);
						hienThiChiMuc(DODAIMANHINH / 2 - 110, 736, indexPage, toiDaPage);
						hienThiTongTienCTHD(tempHD->getdsCTHD());
					}
				}
			}
			else if (hieuChinhCTHD7.isMouseHover(xclick, yclick))
			{
				if (soLuongCTHDTrenTable >= 7)
				{
					pointerCTHD = tempHD->getdsCTHD()->traVeCTHDTheoindex(6 + soPhanTuTrenMotPage * indexPage);
					if (pointerCTHD != NULL)
					{
						hienThiChinhSuaCTHD(pointerCTHD, tempHD->getdsCTHD(), dsVatTu, "N");
						veTableCTHD();
						soLuongCTHDTrenTable = hienThiCTHDLenTable(indexPage, soPhanTuTrenMotPage, tempHD->getdsCTHD(), dsVatTu);
						hienThiChiMuc(DODAIMANHINH / 2 - 110, 736, indexPage, toiDaPage);
						hienThiTongTienCTHD(tempHD->getdsCTHD());
					}
				}
			}
			else if (hieuChinhCTHD8.isMouseHover(xclick, yclick))
			{
				if (soLuongCTHDTrenTable >= 8)
				{
					pointerCTHD = tempHD->getdsCTHD()->traVeCTHDTheoindex(7 + soPhanTuTrenMotPage * indexPage);
					if (pointerCTHD != NULL)
					{
						hienThiChinhSuaCTHD(pointerCTHD, tempHD->getdsCTHD(), dsVatTu, "N");
						veTableCTHD();
						soLuongCTHDTrenTable = hienThiCTHDLenTable(indexPage, soPhanTuTrenMotPage, tempHD->getdsCTHD(), dsVatTu);
						hienThiChiMuc(DODAIMANHINH / 2 - 110, 736, indexPage, toiDaPage);
						hienThiTongTienCTHD(tempHD->getdsCTHD());
					}
				}
			}
			else if (hieuChinhCTHD9.isMouseHover(xclick, yclick))
			{
				if (soLuongCTHDTrenTable >= 9)
				{
					pointerCTHD = tempHD->getdsCTHD()->traVeCTHDTheoindex(8 + soPhanTuTrenMotPage * indexPage);
					if (pointerCTHD != NULL)
					{
						hienThiChinhSuaCTHD(pointerCTHD, tempHD->getdsCTHD(), dsVatTu, "N");
						veTableCTHD();
						soLuongCTHDTrenTable = hienThiCTHDLenTable(indexPage, soPhanTuTrenMotPage, tempHD->getdsCTHD(), dsVatTu);
						hienThiChiMuc(DODAIMANHINH / 2 - 110, 736, indexPage, toiDaPage);
						hienThiTongTienCTHD(tempHD->getdsCTHD());
					}
				}
			}
		}
		delay(10);
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void tinhToiDaPage(int mountShow, float &toiDaPage, int soPhanTuTrenMotPage, int &soLuongPage)
{
	soLuongPage = mountShow / soPhanTuTrenMotPage;
	toiDaPage = (float)mountShow / (float)soPhanTuTrenMotPage;
	if (!kiemTraSoNguyen(TienichDoHoa::floatToString(toiDaPage)))
	{
		toiDaPage = (int)toiDaPage + 1;
	}
}

void hienThiThemHoaDonNhapVaXuat(BstVatTu &dsVatTu, dsNhanVien &DSNV, int &index, NutBam &vatTu, NutBam &nhanVien,
								 NutBam &hoaDon, NutBam &doanhThu,NutBam &taoHDXuat, NutBam &taoHDNhap, NutBam &inHD, NutBam &xemdsNV, NutBam &xemdsVT, bool hoaDonXuat)
{
	TienichDoHoa::xoaManHinhTheoToaDo(0, 96, DODAIMANHINH, 1000, BACKGROUP);
	NhanVien *tempNV;
	NodeHoaDon *tempHD;
	NodeCTHD *pointerCTHD;
	NodeVatTu *tempVT;
	bool tonTaiHoaDon = false;
	int indexPage = 0;
	int soPhanTuTrenMotPage = 9;
	int soLuongPage;
	int soLuongCTHD;
	float toiDaPage = 1;
	int soLuongCTHDTrenTable = 0;
	bool khongBiLoiKhiTaoHD = true; // BIEN NAY  DANH DAU XEM NGUOI DUNG CO TAO SAI CHI TIET HOA DON HAY KHONG
	NutBam btnSave(margin + 1232 + 34, canLeTrenHD + 12, WHD * 2 - 34, HHD, mauNhapXuat, mauHightNhapXuat, 1, "SAVE");
	NutBam themCTHD(margin + 1230 + 34, canLeTrenHD + 90, WHD * 2 - 34, HHD, mauNhapXuat, mauHightNhapXuat, 1, "THANH TOAN");
	ONhap maNV(margin + 6, canLeTrenHD + 12, 160, 40, 60, "Ma NV: ", 0, 0, 10);
	
	ONhap soHD(margin + 742, canLeTrenHD + 12, 160, 40, 60, "So HD: ", 0, 0, 10);
	ONhap hoTenNV(margin + 260,canLeTrenHD + 12,300 + 60,40,90,"ho & Ten: ",0,0,25);
	
	hoTenNV.veONhap(); 
	soHD.veONhap();
	maNV.veONhap();
	btnSave.veNut();
	Date tempDate;


	// VE NGAY THANG NAM
	
	
	ONhap nhapNgay(canLeNgangHD + 630 + 200 + 90 + 110 , canLeTrenHD + 12, 50, 40, 0, "", 0, 0, 2);
	ONhap nhapThang(canLeNgangHD + 606 + 256 + 70 + 55 + 120 , canLeTrenHD + 12, 50, 40, 0, "", 0, 0, 2);
	ONhap nhapNam(canLeNgangHD + 1017 + 160 + 10, canLeTrenHD + 12, 70, 40, 0, "", 0, 0, 4);
	tempDate.dateToString(nhapNgay.boNhoDem, nhapThang.boNhoDem, nhapNam.boNhoDem);
	nhapNam.veONhap();
	nhapNgay.veONhap();
	nhapThang.veONhap();
	nhapNgay.inNoiDung();
	nhapThang.inNoiDung();
	nhapNam.inNoiDung();
	
	ONhap maVT(margin + 6, canLeTrenHD + 90, 160, 40, 60, "MA VT: ", 0, 0, 10);

	ONhap soLuongVT(margin + 340, canLeTrenHD + 90, 130, 40, 96, "SO LUONG: ", 0, 0, 5);
	ONhap donGia(margin + 660, canLeTrenHD + 90, 130, 40, 96, "DON GIA: ", 0, 0, 5);
	ONhap VAT(margin + 990, canLeTrenHD + 90, 100, 40, 80, "VAT(%): ", 0, 0, 4);
	
	maVT.veONhap();
	soLuongVT.veONhap();
	donGia.veONhap();
	VAT.veONhap();
	themCTHD.veNut();

	// O VUONG BAO QUANH
	OVuong baoQuanhHD(54, canLeTrenHD, DODAIMANHINH - 12 - 102, 80, 15);
	OVuong baoQuanCTHD(54, canLeTrenHD + 80, DODAIMANHINH - 12 - 102, 80, 15);

	NutBam btnTienToi(margin + 56, 722, 50, 40, 15, 3, 1, ">>");
	NutBam btnLui(margin, 722, 50, 40, 15, 3, 1, "<<");

	btnTienToi.veNut();
	btnLui.veNut();
	veTableCTHD();

	// TOA DO NUT HIEU CHINH CTHD.
	NutBam hieuChinhCTHD1(margin + 36 + doDaiCoban * 7 + 190, 354 - 4, 52, 28, 11, 3, 0, "sua");
	NutBam hieuChinhCTHD2(margin + 36 + doDaiCoban * 7 + 190, 354 + 36 - 4, 52, 28, 11, 3, 0, "sua");
	NutBam hieuChinhCTHD3(margin + 36 + doDaiCoban * 7 + 190, 354 + 36 * 2 - 4, 52, 28, 11, 3, 0, "sua");
	NutBam hieuChinhCTHD4(margin + 36 + doDaiCoban * 7 + 190, 354 + 36 * 3 - 4, 52, 28, 11, 3, 0, "sua");
	NutBam hieuChinhCTHD5(margin + 36 + doDaiCoban * 7 + 190, 354 + 36 * 4 - 4, 52, 28, 11, 3, 0, "sua");
	NutBam hieuChinhCTHD6(margin + 36 + doDaiCoban * 7 + 190, 354 + 36 * 5 - 4, 52, 28, 11, 3, 0, "sua");
	NutBam hieuChinhCTHD7(margin + 36 + doDaiCoban * 7 + 190, 354 + 36 * 6 - 4, 52, 28, 11, 3, 0, "sua");
	NutBam hieuChinhCTHD8(margin + 36 + doDaiCoban * 7 + 190, 354 + 36 * 7 - 4, 52, 28, 11, 3, 0, "sua");
	NutBam hieuChinhCTHD9(margin + 36 + doDaiCoban * 7 + 190, 354 + 36 * 8 - 4, 52, 28, 11, 3, 0, "sua");

	while (true)
	{

		if (ismouseclick(WM_LBUTTONDOWN))
		{
			int xclick = -1;
			int yclick = -1;
			getmouseclick(WM_LBUTTONDOWN, xclick, yclick);
			if (nhanVien.isMouseHover(xclick, yclick))
			{
				index = ID_NV;
				return;
			}
			if (vatTu.isMouseHover(xclick, yclick))
			{
				index = ID_VT;
				return;
			}
			if (hoaDon.isMouseHover(xclick, yclick))
			{
				index = ID_HD;
				return;
			}
			if (doanhThu.isMouseHover(xclick, yclick))
			{
				index = ID_DT;
				return;
			}

			if (inHD.isMouseHover(xclick, yclick))
			{
				index = ID_IN_HD;
				return;
			}
			if (taoHDNhap.isMouseHover(xclick, yclick))
			{
				index = ID_THEM_HD_NHAP;
				return;
			}
			if (taoHDXuat.isMouseHover(xclick,yclick)) {
				index = ID_THEM_HD_XUAT;
				return;
			}
			if (xemdsNV.isMouseHover(xclick, yclick))
			{
				index = ID_GOI_Y_DSNV;
				return;
			}
			if (xemdsVT.isMouseHover(xclick, yclick))
			{
				index = ID_GOI_Y_VT;
				return;
			}

			if (maNV.isMouseHover(xclick, yclick))
			{
				maNV.NhapVao(nhapID, "Chi Nhan Chu,So Hoac _ !"); // xoa di khoan troan trang thua
				if (maNV.khongRong())
				{
					tempNV = DSNV.timKiemNVTraVeDiaChi(maNV.boNhoDem);
					if (tempNV != NULL)
					{
						hoTenNV.thayDoiNoiDung(tempNV->getHoTen()); 
					}
					else 
					{
						MessageBox(NULL, "Khong Ton Tai Nhan Vien Nay!", "Thong Bao", MB_ICONINFORMATION | MB_OK);
						maNV.resetBoNhoDem();
						hoTenNV.resetBoNhoDem(); 
					}
					
				}
				else {
					hoTenNV.resetBoNhoDem(); 
				}
			}
			else if (hoTenNV.isMouseHover(xclick,yclick)) 
			{
				hoTenNV.NhapVao(kiTuChu,"Chi Nhan Chu!"); 
				hoTenNV.chuanHoa(); 
				if (hoTenNV.khongRong()) 
				{
					tempNV = DSNV.timKiemNhanVienTheoTen(hoTenNV.boNhoDem);
					if (tempNV != NULL) 
					{
						maNV.thayDoiNoiDung(tempNV->maNV);
					}
					else 
					{
						TienichDoHoa::hienThiThongBao("Khong Ton Tai Nhan Vien Nay"); 
						maNV.resetBoNhoDem(); 
						hoTenNV.resetBoNhoDem(); 
					}
				}
				else {  // truong hop khong he nhap gi 
					maNV.resetBoNhoDem(); 
				}
 				
				
				
			}
			else if (soHD.isMouseHover(xclick, yclick))
			{

				soHD.NhapVao(nhapID, "Chi Nhan Chu,So Hoac _ !");
				if (DSNV.timKiemHD(soHD.boNhoDem) != NULL && !soHD.khongDuocNhap)
				{
					MessageBox(NULL, "Da ton tai maHD nay!", "Thong Bao", MB_ICONINFORMATION | MB_OK);
					soHD.resetBoNhoDem();
				}
			}
			else if (nhapNgay.isMouseHover(xclick, yclick))
			{
				nhapNgay.NhapVao(kiTuSo, "Chi nhap so!");
				if (nhapNgay.khongRong())
				{
					if (!Date::hopLeNgay(TienichDoHoa::stringToInt(nhapNgay.boNhoDem)))
					{
						MessageBox(NULL, "Ngay Khong Hop Le!", "Thong Bao", MB_ICONINFORMATION | MB_OK);
						nhapNgay.resetBoNhoDem();
					}
				}
			}
			else if (nhapThang.isMouseHover(xclick, yclick))
			{
				nhapThang.NhapVao(kiTuSo, "Chi nhap so!");
				if (nhapThang.khongRong())
				{
					if (!Date::hopLeThang(TienichDoHoa::stringToInt(nhapThang.boNhoDem)))
					{
						MessageBox(NULL, "Thang Khong Hop Le!", "Thong Bao", MB_ICONINFORMATION | MB_OK);
						nhapThang.resetBoNhoDem();
					}
				}
			}
			else if (nhapNam.isMouseHover(xclick, yclick))
			{
				nhapNam.NhapVao(kiTuSo, "Chi nhap so!");
				if (nhapNam.boNhoDem != "")
				{
					if (!Date::hopLeNam(TienichDoHoa::stringToInt(nhapNam.boNhoDem)))
					{
						MessageBox(NULL, "Nam Khong Hop Le!", "Thong Bao", MB_ICONINFORMATION | MB_OK);
						nhapNam.resetBoNhoDem();
					}
				}
			}
			else if (btnSave.isMouseHover(xclick, yclick))
			{
				const int chuaCoCTHD = 0;
				int soLuongCTHD = -1;
				if (tonTaiHoaDon)
				{
					soLuongCTHD = tempHD->getdsCTHD()->soLuongCTHD(); // lay ra so Luong CTHD
				}

				if (nhapNgay.boNhoDem == "" || nhapThang.boNhoDem == "" || nhapNam.boNhoDem == "" || maNV.boNhoDem == "" || soHD.boNhoDem == "")
				{
					MessageBox(NULL, "Vui Long Dien Vao Hoa Don!", "thong bao", MB_ICONINFORMATION | MB_OK);
				}
				else if (!tonTaiHoaDon) // truong hop dsct hd dang rong!
				{
					MessageBox(NULL, "Vui Long Dien vao Chi Tiet Hoa Don!", "thong bao", MB_ICONINFORMATION | MB_OK);
				}
				else if (soLuongCTHD == chuaCoCTHD)
				{
					TienichDoHoa::hienThiThongBao("Chua Them Chi Tiet Hoa Don"); 
				}
				else
				{
					MessageBox(NULL, "Luu Hoa Don Thanh Cong!", "thong bao", MB_ICONINFORMATION | MB_OK);
					if (hoaDonXuat)
					 {
						tempHD->getdsCTHD()->capNhapSoLuongVatTu(dsVatTu, "X");
					}
					else 
					{
						tempHD->getdsCTHD()->capNhapSoLuongVatTu(dsVatTu, "N");
					}
					tempNV->soLanTaoHD++; // tang len vi da lap 1 hoa don thanh cong !
					DSNV.ghiFileDSNV();
					dsVatTu.ghiFileVatTu();
					index = ID_THEM_HD_XUAT;
					return;
				}
			}

			// ==================== SAU KHI NHAP SONG MAVT==================

			else if (maVT.isMouseHover(xclick, yclick))
			{
				maVT.NhapVao(nhapID, "Chi Nhan Chu,So Hoac _ !");
				tempVT = dsVatTu.timKiemVT(maVT.boNhoDem);
				if (tempVT == NULL && maVT.boNhoDem != "")
				{
					MessageBox(NULL, "khong ton tai ma vat tu nay!", "thong bao", MB_ICONINFORMATION | MB_OK);
					maVT.resetBoNhoDem();
				}
				else if (tonTaiHoaDon)
				{
					if (tempHD->getdsCTHD()->timKiemCTHD(maVT.boNhoDem))
					{ // boi vi chua them vaoHD
						MessageBox(NULL, "Da ton tai Vat Tu nay!", "Thong Bao", MB_ICONINFORMATION | MB_OK);
						maVT.resetBoNhoDem();
					}
				}
			}
			else if (soLuongVT.isMouseHover(xclick, yclick))
			{
				soLuongVT.nhapSoThuc("chi nhap so thuc!");
				// kiem tra neu nguoi dung nhap vao so 0 => khong thoa
				if (TienichDoHoa::stringToFloat(soLuongVT.boNhoDem) == 0)
				{
					MessageBox(NULL, "khong hop le!", "thong bao", MB_ICONINFORMATION | MB_OK);
					soLuongVT.resetBoNhoDem();
				}
			}
			else if (donGia.isMouseHover(xclick, yclick))
			{
				donGia.nhapSoThuc("chi nhap so thuc!");
			}
			else if (VAT.isMouseHover(xclick, yclick))
			{
				VAT.nhapSoThuc("chi nhap so thuc!");
				float tempVAT = TienichDoHoa::stringToFloat(VAT.boNhoDem);
				if (tempVAT > 100)
				{
					MessageBox(NULL, "khong hop le!", "thong bao", MB_ICONINFORMATION | MB_OK);
					VAT.resetBoNhoDem();
				}
			}
			else if (btnTienToi.isMouseHover(xclick, yclick))
			{
				if (indexPage < toiDaPage - 1)
				{
					indexPage++;
					veTableCTHD();
					hienThiTongTienCTHD(tempHD->getdsCTHD());
					soLuongCTHDTrenTable = hienThiCTHDLenTable(indexPage, soPhanTuTrenMotPage, tempHD->getdsCTHD(), dsVatTu);
					hienThiChiMuc(DODAIMANHINH / 2 - 110, 736, indexPage, toiDaPage);
				}
			}
			else if (btnLui.isMouseHover(xclick, yclick))
			{
				if (indexPage > 0)
				{
					indexPage--;
					veTableCTHD();
					hienThiTongTienCTHD(tempHD->getdsCTHD());
					soLuongCTHDTrenTable = hienThiCTHDLenTable(indexPage, soPhanTuTrenMotPage, tempHD->getdsCTHD(), dsVatTu);
					hienThiChiMuc(DODAIMANHINH / 2 - 110, 736, indexPage, toiDaPage);
				}
			}

			else if (themCTHD.isMouseHover(xclick, yclick))
			{

				if (nhapNgay.khongRong() && nhapThang.khongRong() && nhapNam.khongRong() && maNV.khongRong() &&
					soHD.khongRong() && maVT.khongRong() && soLuongVT.khongRong() && donGia.khongRong() && VAT.khongRong() && hoTenNV.khongRong()) 
				{
					if (!tonTaiHoaDon) //  BIEN NAY KIEM TRA XEM HOA DON DA DUOC THEM CHUA.
					{
						tempDate.ngay = TienichDoHoa::stringToInt(nhapNgay.boNhoDem);
						tempDate.thang = TienichDoHoa::stringToInt(nhapThang.boNhoDem);
						tempDate.nam = TienichDoHoa::stringToInt(nhapNam.boNhoDem);
						if (Date::ngayThangNamTuongLai(tempDate))
						{
							MessageBox(NULL, "dd/mm/yyyy Tuong Lai!", "Thong Bao", MB_ICONINFORMATION | MB_OK);
							khongBiLoiKhiTaoHD = false;
						}
						else if (!Date::ngayThangNamHopLe(tempDate))
						{
							MessageBox(NULL, "dd/mm/yyyy Khong Hop Le!", "Thong Bao", MB_ICONINFORMATION | MB_OK);
							khongBiLoiKhiTaoHD = false;
						}
						else // KHI XUONG TOI DAY -> MA NV DA HOP LE,SO HD HOP LE, NGAY THANG NAM HOP LE
						{
							// BAC DAU LAP CHI TIET HOA DON !
							maNV.voHieuHoa();
							hoTenNV.voHieuHoa(); 
							soHD.voHieuHoa();
							nhapNgay.voHieuHoa();
							nhapThang.voHieuHoa();
							nhapNam.voHieuHoa();

							if (hoaDonXuat)
							{
								tempHD = tempNV->dsHoaDon.themVaoCuoiHD(soHD.boNhoDem, tempDate, "X", tempNV->getHoTen());
							}
							else
							{
								tempHD = tempNV->dsHoaDon.themVaoCuoiHD(soHD.boNhoDem, tempDate, "N", tempNV->getHoTen());
							}

							tonTaiHoaDon = true;
							khongBiLoiKhiTaoHD = true;
						}
					}

					if (khongBiLoiKhiTaoHD)
					{
						
						bool duVatTu = true;
						// THEM CHI TIET HOA DON
						float tempSL = TienichDoHoa::stringToFloat(soLuongVT.boNhoDem);
						float tempdonGia = TienichDoHoa::stringToFloat(donGia.boNhoDem);
						float tempVAT = TienichDoHoa::stringToFloat(VAT.boNhoDem);
						if (hoaDonXuat) // KIEM TRA XEM CO DU HANG KHONG KHI XUAT HOA DON
						{
							tempVT = dsVatTu.timKiemVT(maVT.boNhoDem);
							if (!tempVT->getInfo()->kiemTraDuHang(tempSL))
							{
								string thongBao = +"khong Du Vat Tu! So Luong Ton Trong Kho " + TienichDoHoa::floatToString(tempVT->getInfo()->soLuongTon);
								MessageBox(NULL, thongBao.c_str(), "thong bao", MB_ICONINFORMATION | MB_OK);
								soLuongVT.resetBoNhoDem();
								duVatTu = false;
							}
							
						}
						if (duVatTu)
							{ // HOA DON LA NHAP HOAC XUAT CO DU VAT TU
								tempVT->getInfo()->soLanTaoCTHD++;
								CThoaDon tempCTHD(maVT.boNhoDem, tempSL, tempdonGia, tempVAT); // khi tat ca da thoa dieu kien.
								tempHD->getdsCTHD()->themVaoCuoiCTHD(tempCTHD);
								soLuongCTHD = tempHD->getdsCTHD()->soLuongCTHD();
								tinhToiDaPage(soLuongCTHD, toiDaPage, soPhanTuTrenMotPage, soLuongPage);
								veTableCTHD();
								soLuongCTHDTrenTable = hienThiCTHDLenTable(indexPage, soPhanTuTrenMotPage, tempHD->getdsCTHD(), dsVatTu);
								hienThiTongTienCTHD(tempHD->getdsCTHD());
								hienThiChiMuc(DODAIMANHINH / 2 - 110, 736, indexPage, toiDaPage);

								maVT.resetBoNhoDem();
								soLuongVT.resetBoNhoDem();
								donGia.resetBoNhoDem();
								VAT.resetBoNhoDem();
							}
					}
				}
				else
					MessageBox(NULL, "Vui Long Dien Day Du!", "Thong Bao", MB_ICONINFORMATION | MB_OK);
			}

			else if (hieuChinhCTHD1.isMouseHover(xclick, yclick))
			{
				if (soLuongCTHDTrenTable != 0)
				{
					pointerCTHD = tempHD->getdsCTHD()->traVeCTHDTheoindex(soPhanTuTrenMotPage * indexPage);
					if (pointerCTHD != NULL)
					{
						hienThiChinhSuaCTHD(pointerCTHD, tempHD->getdsCTHD(), dsVatTu, "X");
						veTableCTHD();
						soLuongCTHDTrenTable = hienThiCTHDLenTable(indexPage, soPhanTuTrenMotPage, tempHD->getdsCTHD(), dsVatTu);
						hienThiChiMuc(DODAIMANHINH / 2 - 110, 736, indexPage, toiDaPage);
						hienThiTongTienCTHD(tempHD->getdsCTHD());
					}
				}
			}
			else if (hieuChinhCTHD2.isMouseHover(xclick, yclick))
			{
				if (soLuongCTHDTrenTable >= 1)
				{
					pointerCTHD = tempHD->getdsCTHD()->traVeCTHDTheoindex(1 + soPhanTuTrenMotPage * indexPage);
					if (pointerCTHD != NULL)
					{
						hienThiChinhSuaCTHD(pointerCTHD, tempHD->getdsCTHD(), dsVatTu, "X");
						veTableCTHD();
						soLuongCTHDTrenTable = hienThiCTHDLenTable(indexPage, soPhanTuTrenMotPage, tempHD->getdsCTHD(), dsVatTu);
						hienThiChiMuc(DODAIMANHINH / 2 - 110, 736, indexPage, toiDaPage);
						hienThiTongTienCTHD(tempHD->getdsCTHD());
					}
				}
			}
			else if (hieuChinhCTHD3.isMouseHover(xclick, yclick))
			{
				if (soLuongCTHDTrenTable >= 2)
				{
					pointerCTHD = tempHD->getdsCTHD()->traVeCTHDTheoindex(2 + soPhanTuTrenMotPage * indexPage);
					if (pointerCTHD != NULL)
					{
						hienThiChinhSuaCTHD(pointerCTHD, tempHD->getdsCTHD(), dsVatTu, "X");
						veTableCTHD();
						soLuongCTHDTrenTable = hienThiCTHDLenTable(indexPage, soPhanTuTrenMotPage, tempHD->getdsCTHD(), dsVatTu);
						hienThiChiMuc(DODAIMANHINH / 2 - 110, 736, indexPage, toiDaPage);
						hienThiTongTienCTHD(tempHD->getdsCTHD());
					}
				}
			}
			else if (hieuChinhCTHD4.isMouseHover(xclick, yclick))
			{
				if (soLuongCTHDTrenTable >= 3)
				{
					pointerCTHD = tempHD->getdsCTHD()->traVeCTHDTheoindex(3 + soPhanTuTrenMotPage * indexPage);
					if (pointerCTHD != NULL)
					{
						hienThiChinhSuaCTHD(pointerCTHD, tempHD->getdsCTHD(), dsVatTu, "X");
						veTableCTHD();
						soLuongCTHDTrenTable = hienThiCTHDLenTable(indexPage, soPhanTuTrenMotPage, tempHD->getdsCTHD(), dsVatTu);
						hienThiChiMuc(DODAIMANHINH / 2 - 110, 736, indexPage, toiDaPage);
						hienThiTongTienCTHD(tempHD->getdsCTHD());
					}
				}
			}
			else if (hieuChinhCTHD5.isMouseHover(xclick, yclick))
			{
				if (soLuongCTHDTrenTable >= 4)
				{
					pointerCTHD = tempHD->getdsCTHD()->traVeCTHDTheoindex(4 + soPhanTuTrenMotPage * indexPage);
					if (pointerCTHD != NULL)
					{
						hienThiChinhSuaCTHD(pointerCTHD, tempHD->getdsCTHD(), dsVatTu, "X");
						veTableCTHD();
						soLuongCTHDTrenTable = hienThiCTHDLenTable(indexPage, soPhanTuTrenMotPage, tempHD->getdsCTHD(), dsVatTu);
						hienThiChiMuc(DODAIMANHINH / 2 - 110, 736, indexPage, toiDaPage);
						hienThiTongTienCTHD(tempHD->getdsCTHD());
					}
				}
			}
			else if (hieuChinhCTHD6.isMouseHover(xclick, yclick))
			{
				if (soLuongCTHDTrenTable >= 5)
				{
					pointerCTHD = tempHD->getdsCTHD()->traVeCTHDTheoindex(5 + soPhanTuTrenMotPage * indexPage);
					if (pointerCTHD != NULL)
					{
						hienThiChinhSuaCTHD(pointerCTHD, tempHD->getdsCTHD(), dsVatTu, "X");
						veTableCTHD();
						soLuongCTHDTrenTable = hienThiCTHDLenTable(indexPage, soPhanTuTrenMotPage, tempHD->getdsCTHD(), dsVatTu);
						hienThiChiMuc(DODAIMANHINH / 2 - 110, 736, indexPage, toiDaPage);
						hienThiTongTienCTHD(tempHD->getdsCTHD());
					}
				}
			}
			else if (hieuChinhCTHD7.isMouseHover(xclick, yclick))
			{
				if (soLuongCTHDTrenTable >= 7)
				{
					pointerCTHD = tempHD->getdsCTHD()->traVeCTHDTheoindex(6 + soPhanTuTrenMotPage * indexPage);
					if (pointerCTHD != NULL)
					{
						hienThiChinhSuaCTHD(pointerCTHD, tempHD->getdsCTHD(), dsVatTu, "X");
						veTableCTHD();
						soLuongCTHDTrenTable = hienThiCTHDLenTable(indexPage, soPhanTuTrenMotPage, tempHD->getdsCTHD(), dsVatTu);
						hienThiChiMuc(DODAIMANHINH / 2 - 110, 736, indexPage, toiDaPage);
						hienThiTongTienCTHD(tempHD->getdsCTHD());
					}
				}
			}
			else if (hieuChinhCTHD8.isMouseHover(xclick, yclick))
			{
				if (soLuongCTHDTrenTable >= 8)
				{
					pointerCTHD = tempHD->getdsCTHD()->traVeCTHDTheoindex(7 + soPhanTuTrenMotPage * indexPage);
					if (pointerCTHD != NULL)
					{
						hienThiChinhSuaCTHD(pointerCTHD, tempHD->getdsCTHD(), dsVatTu, "X");
						veTableCTHD();
						soLuongCTHDTrenTable = hienThiCTHDLenTable(indexPage, soPhanTuTrenMotPage, tempHD->getdsCTHD(), dsVatTu);
						hienThiChiMuc(DODAIMANHINH / 2 - 110, 736, indexPage, toiDaPage);
						hienThiTongTienCTHD(tempHD->getdsCTHD());
					}
				}
			}
			else if (hieuChinhCTHD9.isMouseHover(xclick, yclick))
			{
				if (soLuongCTHDTrenTable >= 9)
				{
					pointerCTHD = tempHD->getdsCTHD()->traVeCTHDTheoindex(8 + soPhanTuTrenMotPage * indexPage);
					if (pointerCTHD != NULL)
					{
						hienThiChinhSuaCTHD(pointerCTHD, tempHD->getdsCTHD(), dsVatTu, "X");
						veTableCTHD();
						soLuongCTHDTrenTable = hienThiCTHDLenTable(indexPage, soPhanTuTrenMotPage, tempHD->getdsCTHD(), dsVatTu);
						hienThiChiMuc(DODAIMANHINH / 2 - 110, 736, indexPage, toiDaPage);
						hienThiTongTienCTHD(tempHD->getdsCTHD());
					}
				}
			}
		}
		delay(10);
	}
}

// =================================== HAM HIEN THI TINH NANG HOA DON ================================
void hienThiTinhNangHoaDon(BstVatTu &dsVatTu, dsNhanVien &DSNV, int &index, NutBam &vatTu, NutBam &nhanVien, NutBam &hoaDon, NutBam &doanhThu)
{
	TienichDoHoa::xoaManHinhTheoToaDo(0, 56, DODAIMANHINH, DORONGMANHINH, BACKGROUP);
	index = -1;
	const int WMenuSub = 230;
	const int HMenuSub = 35;
	const int marginLeftSub = 56;
	const int marginTopSub = 62;
	NutBam themHDXuat(marginLeftSub, marginTopSub, WMenuSub, HMenuSub, COLOR_BTN_SUB, COLOR_HIGHT_BTN_SUB, COLOR_TEXT_BTN_SUB, "HOA DON XUAT");
	NutBam themHDNhap(marginLeftSub + WMenuSub + 2, marginTopSub, WMenuSub, HMenuSub, COLOR_BTN_SUB, COLOR_HIGHT_BTN_SUB, COLOR_TEXT_BTN_SUB, "HOA DON NHAP");
	NutBam inHD(marginLeftSub + WMenuSub * 2 + 2 * 2, marginTopSub, WMenuSub, HMenuSub, COLOR_BTN_SUB, COLOR_HIGHT_BTN_SUB, COLOR_TEXT_BTN_SUB, "IN HOA DON");
	NutBam xemdsNV(marginLeftSub + WMenuSub * 3 + 2 * 3, marginTopSub, WMenuSub, HMenuSub, COLOR_BTN_SUB, COLOR_HIGHT_BTN_SUB, COLOR_TEXT_BTN_SUB, "NHAN VIEN VA HOA DON");
	NutBam xemdsVT(marginLeftSub + WMenuSub * 4 + 2 * 4, marginTopSub, WMenuSub, HMenuSub, COLOR_BTN_SUB, COLOR_HIGHT_BTN_SUB, COLOR_TEXT_BTN_SUB, "VAT TU");
	themHDXuat.veNut();
	themHDNhap.veNut();
	inHD.veNut();
	xemdsNV.veNut();
	xemdsVT.veNut();

	int mx = -1;
	int my = -1;
	while (true)
	{
		if (index != -1)
		{
			if (index >= 0 && index <= 3)
			{ // thuoc vung menu to.
				return;
			}
			else if (index == ID_THEM_HD_XUAT)
			{
				index = -1;
				themHDNhap.khongDuocChon();
				themHDXuat.duocChon();
				inHD.khongDuocChon();
				xemdsVT.khongDuocChon();
				xemdsNV.khongDuocChon();
				hienThiThemHoaDonNhapVaXuat(dsVatTu, DSNV, index, vatTu, nhanVien, hoaDon, doanhThu, themHDXuat,themHDNhap, inHD, xemdsNV, xemdsVT, true);
			}
			else if (index == ID_IN_HD)
			{
				index = -1;
				inHD.duocChon();
				themHDNhap.khongDuocChon();
				themHDXuat.khongDuocChon();
				xemdsNV.khongDuocChon();
				xemdsVT.khongDuocChon();

				hienThiXuatHoaDon(dsVatTu, DSNV, index, vatTu, nhanVien, doanhThu, themHDNhap, themHDXuat, inHD, xemdsNV, xemdsVT);
			}

			else if (index == ID_GOI_Y_DSNV)
			{
				themHDNhap.khongDuocChon();
				themHDXuat.khongDuocChon();
				inHD.khongDuocChon();
				xemdsVT.khongDuocChon();
				xemdsNV.duocChon();
			}
			else if (index == ID_GOI_Y_VT)
			{
			}
			else if (index == ID_THEM_HD_NHAP)
			{
				themHDNhap.duocChon();
				themHDXuat.khongDuocChon();
				inHD.khongDuocChon();
				xemdsNV.khongDuocChon();
				xemdsVT.khongDuocChon();

				hienThiThemHoaDonNhapVaXuat(dsVatTu, DSNV, index, vatTu, nhanVien, hoaDon, doanhThu,themHDXuat, themHDNhap, inHD, xemdsNV, xemdsVT, false);
			}
		}

		else if (ismouseclick(WM_LBUTTONDOWN))
		{
			int xclick = -1;
			int yclick = -1;
			getmouseclick(WM_LBUTTONDOWN, xclick, yclick);
			if (nhanVien.isMouseHover(xclick, yclick))
			{
				index = ID_NV;
				return;
			}
			else if (vatTu.isMouseHover(xclick, yclick))
			{
				index = ID_VT;
				return;
			}
			else if (doanhThu.isMouseHover(xclick, yclick))
			{
				index = ID_DT;
				return;
			}
			else if (themHDXuat.isMouseHover(xclick, yclick))
			{
				themHDXuat.duocChon();
				themHDNhap.khongDuocChon();
				inHD.khongDuocChon();
				xemdsNV.khongDuocChon();
				xemdsVT.khongDuocChon();
				hienThiThemHoaDonNhapVaXuat(dsVatTu, DSNV, index, vatTu, nhanVien, hoaDon, doanhThu,themHDXuat, themHDNhap, inHD, xemdsNV, xemdsVT, true);
			}
			else if (themHDNhap.isMouseHover(xclick, yclick))
			{
				themHDNhap.duocChon();
				themHDXuat.khongDuocChon();
				inHD.khongDuocChon();
				xemdsNV.khongDuocChon();
				xemdsVT.khongDuocChon();
				hienThiThemHoaDonNhapVaXuat(dsVatTu, DSNV, index, vatTu, nhanVien, hoaDon, doanhThu,themHDXuat, themHDNhap, inHD, xemdsNV, xemdsVT, false);
			}

			else if (inHD.isMouseHover(xclick, yclick))
			{
				themHDNhap.khongDuocChon();
				themHDXuat.khongDuocChon();
				inHD.duocChon();
				xemdsNV.khongDuocChon();
				xemdsVT.khongDuocChon();
				hienThiXuatHoaDon(dsVatTu, DSNV, index, vatTu, nhanVien, doanhThu, themHDNhap, themHDXuat, inHD, xemdsNV, xemdsVT);
			}
			else if (xemdsNV.isMouseHover(xclick, yclick))
			{
				xemdsNV.duocChon();
				inHD.khongDuocChon();
				xemdsVT.khongDuocChon();
				themHDNhap.khongDuocChon();
				themHDXuat.khongDuocChon();
			}
		}
		delay(1);
	}
}


