#pragma once
using namespace std;
#include "Tienich.h"
#include "BienDoHoa.h"
#include "DoHoaVT.h"
void veTableCTHD();
#include "HamDoHoaVatTu.h"
#include "HamDoHoaNhanVien.h"


// Neu dang nhap do ma nhap vao tab khac -> xac nhan nguoi dung da nhap ra cai khac 





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
			outtextxy(marginTable + doDaiCoBan, marginTop + khoanCach * i, tempVT->getInfo()->ten.c_str());
			outtextxy(marginTable + doDaiCoBan * 3 + 12, marginTop + khoanCach * i, tempVT->getInfo()->donVi.c_str());
			temp = TienichDoHoa::floatToString(arrCTHD[i + indexPage * soLuongItemPage]->getSoLuong());
			outtextxy(marginTable + doDaiCoBan * 4, marginTop + khoanCach * i, temp.c_str());
			temp = TienichDoHoa::floatToString(arrCTHD[i + indexPage * soLuongItemPage]->getDonGia());
			outtextxy(marginTable + doDaiCoBan * 5, marginTop + khoanCach * i, temp.c_str());
			temp = TienichDoHoa::floatToString(arrCTHD[i + indexPage * soLuongItemPage]->getVAT());
			outtextxy(marginTable + doDaiCoBan * 6 + 32, marginTop + khoanCach * i, temp.c_str());
			// in them giaTien cua hoadon ra
			temp = TienichDoHoa::floatToString(arrCTHD[i + indexPage * soLuongItemPage]->getTongTien());
			outtextxy(marginTable + doDaiCoBan * 7, marginTop + khoanCach * i, temp.c_str());
			setcolor(15);
			line(marginTable - 34, marginTop + khoanCach * i + 26, marginTable + 1378, marginTop + khoanCach * i + 26);
		}
	}
	delete[] arrCTHD;
	return dem;
}



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
void hienThiHoaDon(NhanVienLapHD &nvLapHD, BstVatTu &dsVatTu, int &index, NutBam &vatTu, NutBam &nhanVien, NutBam &doanhThu, NutBam &themHDNhap, NutBam &themHDXuat, NutBam &inHD)
{
	TienichDoHoa::xoaManHinhTheoToaDo(0, canLeTrenHD - 10, 1600, 1600, BACKGROUP);

	int indexPage = 0;
	int soLuongPhanTuHienThi = 0;
	int itemTrenMotPage = 9;

	int toaDoChiMucX = DODAIMANHINH / 2 - 110;
	int toaDoChiMucY = 740;

	int soLuongCTHD = nvLapHD.ptrHoaDon->getdsCTHD()->soLuongCTHD();
	float toiDaPage = TienichDoHoa::tinhToiDaPage(soLuongCTHD,itemTrenMotPage); 

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

	
	veTableCTHD();
	OVuong(52, 120, doDaiCoBan * 9 + 30 + 4, 590, 15);
	NutBam mauNen(52, 180, 600, 40, 2, 3, 4, "");

	setcolor(CinputText);
	setbkcolor(0);
	settextstyle(6, 0, 1);
	outtextxy(margin + 1250, 736, TienichDoHoa::floatToString(nvLapHD.ptrHoaDon->getdsCTHD()->tinhTongTien()).c_str());
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
			if (btnTien.isMouseHover(xclick, yclick))
			{ 
				if (indexPage < toiDaPage - 1)
				{
					indexPage++;
					veTableCTHD();
					OVuong(52, 120, doDaiCoBan * 9 + 30 + 4, 590, 15);
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
					OVuong(52, 120, doDaiCoBan * 9 + 30 + 4, 590, 15);

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




void hienThiXuatHoaDon(BstVatTu &dsVatTu, dsNhanVien &DSNV, int &index, NutBam &vatTu, NutBam &nhanVien, NutBam &doanhThu, NutBam &themHDNhap, NutBam &themHDXuat, NutBam &inHD)
{
	NhanVienLapHD nvLapHD; 
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
					if (!nvLapHD.isNull())
					{ // co tim thay => goi toi ham hien thi ra.
						hienThiHoaDon(nvLapHD, dsVatTu, index, vatTu, nhanVien, doanhThu, themHDNhap, themHDXuat, inHD);
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
	NodeVatTu* tempVTCu = dsVatTu.timKiemVT(tempCTHD->getmaVT());    //   chua vung nho vat tu cu  
	NodeVatTu* tempVTMoi = NULL; 
	CThoaDon* CTHD = tempCTHD->getinfo();  // Chi Tiet Hoa Don Hien Tai   
	string thongBao;   // chua thong bao 
	int w = 540;  
	int h = 358;
	int x = DODAIMANHINH / 2 - w / 2; // in r o nua man hinh
	int y = 332;
	NutBam box(x, y, w, h, 8, 0, 0, EMPTYSTRING);
	box.veNut();
	// ve ra nut dau X
	NutBam cancel(w + x - 40, y, 40, 40, 4, 2, 15, "X");
	cancel.veNut();
	NutBam title(x, y, w - 40, 40, 10, 0, 1, "HIEU CHINH CHI TIET HOA DON");
	title.veNut();
	// ve ra 4 nut -> sau do tao ra cac hieu chinh =>
	ONhap maVT(x + 30, y + 46, w - 170, 40, 110, "MA VT: ", 8, 8, 10);
	ONhap soLuong(x + 30, y + 46 + 48 + 19, w - 170, 40, 110, "SO LUONG: ", 8, 8, 7);
	ONhap donGia(x + 30, y + 46 * 2 + 48 + 19 * 2, w - 170, 40, 110, "DON GIA: ", 8, 8, 7);
	ONhap VAT(x + 30, y + 46 * 3 + 48 + 19 * 3, w - 170, 40, 110, "VAT(%): ", 8, 8, 4);
	
	
	NutBam hieuChinh(x + 30, y + 50 * 4 + 48 + 48 + 17, 234 + 6, 38, 13, 0, 0, "SUA");
	NutBam xoa(x + w - 40 - 234 + 6, y + 50 * 4 + 48 + 48 + 17, 234 + 6, 38, 13, 0, 0, "XOA");
	maVT.veONhap();
	VAT.veONhap();
	soLuong.veONhap();
	donGia.veONhap();
	hieuChinh.veNut();
	xoa.veNut();

	
	maVT.thayDoiNoiDung(CTHD->maVT);  
	soLuong.thayDoiNoiDung(TienichDoHoa::floatToString(CTHD->soLuong));  
	donGia.thayDoiNoiDung(TienichDoHoa::floatToString(CTHD->donGia)); 
	VAT.thayDoiNoiDung(TienichDoHoa::floatToString(CTHD->VAT)); 
	string maVTCu = maVT.boNhoDem;
	string soLuongCu = soLuong.boNhoDem;
	string donGiaCu = donGia.boNhoDem;
	string VATCu = VAT.boNhoDem;
	
	
	int xclick = -1;
	int yclick = -1;
	while (true)
	{
		if (ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_LBUTTONDOWN, xclick, yclick);
			if (cancel.isMouseHover(xclick, yclick))
			{
				break; // ket thuc vong lap -> vi nguoi dung da thoat ra ngoai!
			}
			else if (maVT.isMouseHover(xclick, yclick))
			{
				maVT.NhapVao(nhapID, "Chi Nhan Ki Tu Chu So Hoac _ !"); 
				if (maVT.khongRong() && maVT.boNhoDem != maVTCu) { 
					tempVTMoi = dsVatTu.timKiemVT(maVT.boNhoDem); 
					if (tempVTMoi == NULL) {
						thongBao = "Khong Ton Tai " + maVT.boNhoDem +  " !";
						TienichDoHoa::hienThiThongBao(thongBao); 
						maVT.resetBoNhoDem(); 
					}
					else if (dsCTHD->timKiemCTHD(maVT.boNhoDem) != NULL) 
					{
						thongBao = "Da Ton Tai " + maVT.boNhoDem + " Trong Danh Hoa Don!"; 
						TienichDoHoa::hienThiThongBao(thongBao); 
						maVT.resetBoNhoDem(); 
					}
				}
			}
			else if (soLuong.isMouseHover(xclick, yclick))
			{
				soLuong.nhapSoThuc("chi nhap so thuc!");
				if (soLuong.khongRong()) {
					// kiem tra xem co phai la 0 hay khong 
					if (TienichDoHoa::stringToFloat(soLuong.boNhoDem) == 0) {
						TienichDoHoa::hienThiThongBao("Khong Hop Le ( So Luong = 0 )!"); 
						soLuong.resetBoNhoDem(); 
					}
				}
			}
			else if (donGia.isMouseHover(xclick, yclick))
			{
				donGia.nhapSoThuc("chi nhap so thuc!");
				if (donGia.khongRong()) {
					if (TienichDoHoa::stringToFloat(donGia.boNhoDem) == 0) {
						TienichDoHoa::hienThiThongBao("Khong Hop Le ( Don Gia = 0 ) !"); 
						donGia.resetBoNhoDem();
					}
				}
			}
			else if (VAT.isMouseHover(xclick, yclick))
			{
				VAT.nhapSoThuc("chi nhap so thuc!");
				if (VAT.boNhoDem != VATCu)
				{
					if (TienichDoHoa::stringToFloat(VAT.boNhoDem) > 100)
					{
						TienichDoHoa::hienThiThongBao("Khong Hop Ly (VAT <= 100%)"); 
						VAT.resetBoNhoDem();
					}
				}
			}
			else if (hieuChinh.isMouseHover(xclick, yclick))
			{
				if (maVT.boNhoDem == "" || soLuong.boNhoDem == "" || donGia.boNhoDem == "" || VAT.boNhoDem == "")
				{
					TienichDoHoa::hienThiThongBao("Khong Duoc Bo Trong!"); 
				}
				else if (maVT.boNhoDem != maVTCu || soLuong.boNhoDem != soLuongCu || donGia.boNhoDem != donGiaCu || VAT.boNhoDem != VATCu)
				{  // Co su thay doi moi tien hanh hieu chinh CTHD  
					if (loaiHD == HOADONXUAT)
					{
						NodeVatTu* vatTuCanKiemTra = NULL; 
						if (maVT.boNhoDem != maVTCu) 
						{  
							vatTuCanKiemTra = tempVTMoi; 
						} 
							
						else 
						{ 
							vatTuCanKiemTra = tempVTCu; 
						}
						if (!vatTuCanKiemTra->getInfo()->kiemTraDuHang(TienichDoHoa::stringToFloat(soLuong.boNhoDem)))
						{
							thongBao = "Khong Du - So Luong Ton Trong Kho : " + TienichDoHoa::floatToString(vatTuCanKiemTra->getInfo()->soLuongTon);
							TienichDoHoa::hienThiThongBao(thongBao); 
							soLuong.resetBoNhoDem(); 
						}
						else 
						{
							CTHD->maVT = maVT.boNhoDem; 
							CTHD->soLuong = TienichDoHoa::stringToFloat(soLuong.boNhoDem); 
							CTHD->donGia = TienichDoHoa::stringToFloat(donGia.boNhoDem); 
							CTHD->VAT =TienichDoHoa::stringToFloat(VAT.boNhoDem); 
							// cap nhap lai so lan them CTHD 
							if (vatTuCanKiemTra == tempVTMoi) {
								// nguoi dung da chon vat tu moi
								tempVTMoi->getInfo()->soLanTaoCTHD++; 
								tempVTCu->getInfo()->soLanTaoCTHD--; // giam di so lan tao hoa don 
							}
							TienichDoHoa::hienThiThongBao("Hieu Chinh Thanh Cong!"); 
							break; 
						}
					}
				
					else if (loaiHD == HOADONNHAP) // truong hop la hoa don nhap 
					{
						if (maVT.boNhoDem != maVTCu)  // truong hop nguoi dung chon vat tu khac
						{
							tempVTMoi->getInfo()->soLanTaoCTHD++; 
							tempVTCu->getInfo()->soLanTaoCTHD--; 
						}
						CTHD->maVT = maVT.boNhoDem; 
						CTHD->soLuong = TienichDoHoa::stringToFloat(soLuong.boNhoDem);
						CTHD->donGia = TienichDoHoa::stringToFloat(donGia.boNhoDem);
						CTHD->VAT = TienichDoHoa::stringToFloat(VAT.boNhoDem);
						TienichDoHoa::hienThiThongBao("Cap Nhap Thanh Cong!");  
						break;
						
					}
					
				}
			}

			else if (xoa.isMouseHover(xclick, yclick))
			{
				// kiem tra nguyen trang moi tinh toi chuyen xoa 
				if (maVT.boNhoDem == maVTCu && soLuong.boNhoDem == soLuongCu && donGia.boNhoDem == donGiaCu && VAT.boNhoDem == VATCu) 
				{
					int luaChon = MessageBox(NULL, "Xoa Vat Tu Khoi Hoa Don!", "Thong Bao", MB_ICONWARNING | MB_OKCANCEL);
					if (luaChon == OK)
					{
						tempVTCu->getInfo()->soLanTaoCTHD--; // giam di so lan tao hoa don
						dsCTHD->xoaCTHD(maVT.boNhoDem);   // xoa di vi cai nay maVT no da ton tai khong can lo 
						break; 
						
					}
				}
				
			}
		}
		delay(1);
	}
}

void veTableCTHD()
{
	TienichDoHoa::xoaManHinhTheoToaDo(margin, canLeTrenHD + 170, 1600, 410, BACKGROUP);
	NutBam titleMaVT(margin, canLeTrenHD + 170, doDaiCoBan, 40, colorTieuDe, 7, conlorTextTieuDe, "MA VT");
	NutBam titileTenVT(margin + doDaiCoBan + 3, canLeTrenHD + 170, doDaiCoBan * 2, 40, colorTieuDe, 7, conlorTextTieuDe, "TEN VT");
	NutBam titiledonViVT(margin + doDaiCoBan * 3 + 3 * 2, canLeTrenHD + 170, doDaiCoBan, 40, colorTieuDe, 7, conlorTextTieuDe, "DVT");
	NutBam titilesoLuongVT(margin + doDaiCoBan * 4 + 3 * 3, canLeTrenHD + 170, doDaiCoBan, 40, colorTieuDe, 7, conlorTextTieuDe, "SO LUONG");
	NutBam titiledonGiaVT(margin + doDaiCoBan * 5 + 3 * 4, canLeTrenHD + 170, doDaiCoBan, 40, colorTieuDe, 7, conlorTextTieuDe, "DON GIA");
	NutBam titleVAT(margin + doDaiCoBan * 6 + 3 * 5, canLeTrenHD + 170, doDaiCoBan, 40, colorTieuDe, 7, conlorTextTieuDe, "VAT");
	NutBam thanhTien(margin + doDaiCoBan * 7 + 3 * 6, canLeTrenHD + 170, doDaiCoBan * 2, 40, colorTieuDe, 7, conlorTextTieuDe, "THANH TIEN");
	titleMaVT.veNut();
	titilesoLuongVT.veNut();
	titileTenVT.veNut();
	titiledonViVT.veNut();
	titiledonGiaVT.veNut();
	titleVAT.veNut();
	thanhTien.veNut();
	OVuong table(margin, canLeTrenHD + 170, doDaiCoBan * 9 + 18, 400, 15);
	setcolor(15);
	line(margin + doDaiCoBan, canLeTrenHD + 170, margin + doDaiCoBan, 690);
	line(margin + doDaiCoBan * 3 + 3, canLeTrenHD + 170, margin + doDaiCoBan * 3 + 3, 690);
	line(margin + doDaiCoBan * 4 + 3 * 2, canLeTrenHD + 170, margin + doDaiCoBan * 4 + 3 * 2, 690);
	line(margin + doDaiCoBan * 5 + 3 * 3, canLeTrenHD + 170, margin + doDaiCoBan * 5 + 3 * 3, 690);
	line(margin + doDaiCoBan * 6 + 3 * 4, canLeTrenHD + 170, margin + doDaiCoBan * 6 + 3 * 4, 690);
	line(margin + doDaiCoBan * 7 + 3 * 5, canLeTrenHD + 170, margin + doDaiCoBan * 7 + 3 * 5, 690);
	setbkcolor(0);
	setcolor(15);
	outtextxy(margin + 1102, 736, "TONG TIEN: ");
}



int hienThiCTHDLenTable(int indexPage, int soLuongItemPage, ListCTHD *dsCTHD, BstVatTu &dsVatTu)
{
	const int marginTable = margin + 36;
	const int marginTop = 344;
	const int khoanCach = 40;
	int soLuongCTHD = dsCTHD->soLuongCTHD();
	if (soLuongCTHD == 0) {
		return 0; 
	}
	NodeCTHD **arrCTHD = new NodeCTHD *[soLuongCTHD];
	dsCTHD->listToArray(arrCTHD);
	int dem = 0; // bien dung dem so luong cua CTHD tren table.
	string temp;
	for (int i = 0; i < soLuongItemPage; i++)
	{
		TienichDoHoa::setText(0,15,3,1); 
		if (i + indexPage * soLuongItemPage < soLuongCTHD)
		{
			dem++;
			outtextxy(marginTable + 6, marginTop + khoanCach * i, arrCTHD[i + indexPage * soLuongItemPage]->getmaVT().c_str());
			NodeVatTu *tempVT = dsVatTu.timKiemVT(arrCTHD[i + indexPage * soLuongItemPage]->getmaVT());
			outtextxy(marginTable + doDaiCoBan, marginTop + khoanCach * i, tempVT->getInfo()->ten.c_str());
			outtextxy(marginTable + doDaiCoBan * 3 + 20, marginTop + khoanCach * i, tempVT->getInfo()->donVi.c_str());
			temp = TienichDoHoa::floatToString(arrCTHD[i + indexPage * soLuongItemPage]->getSoLuong());
			outtextxy(marginTable + doDaiCoBan * 4, marginTop + khoanCach * i, temp.c_str());
			temp = TienichDoHoa::floatToString(arrCTHD[i + indexPage * soLuongItemPage]->getDonGia());
			outtextxy(marginTable + doDaiCoBan * 5, marginTop + khoanCach * i, temp.c_str());
			temp = TienichDoHoa::floatToString(arrCTHD[i + indexPage * soLuongItemPage]->getVAT()) + " %"; 
			outtextxy(marginTable + doDaiCoBan * 6 + 32, marginTop + khoanCach * i, temp.c_str());
			temp = TienichDoHoa::floatToString(arrCTHD[i + indexPage * soLuongItemPage]->getTongTien());
			outtextxy(marginTable + doDaiCoBan * 7, marginTop + khoanCach * i, temp.c_str());
			NutBam hieuChinh(marginTable + doDaiCoBan * 7 + 190, marginTop + khoanCach * i - 4, 52, 28, 11, 2, 0, "SUA");
			hieuChinh.veNut();
			setcolor(15);
			line(marginTable - 34, marginTop + khoanCach * i + 28, marginTable + 1378, marginTop + khoanCach * i + 28);
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




void hienThiThemHoaDonNhapVaXuat(BstVatTu &dsVatTu, dsNhanVien &DSNV, int &index, NutBam &vatTu, NutBam &nhanVien,
								 NutBam &hoaDon, NutBam &doanhThu,NutBam &taoHDXuat, NutBam &taoHDNhap, NutBam &inHD, bool hoaDonXuat)
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
	bool nhapVaoChinhSua = false; // NEU BIEN LA TRUE NGUOI DUNG DA NHAP VAO CHINH SUA
	bool khongBiLoiKhiTaoHD = true; // BIEN NAY  DANH DAU XEM NGUOI DUNG CO TAO SAI CHI TIET HOA DON HAY KHONG
	
	
	// BIEN SU DUNG CHO VA TU  
	int soLuongVatTu = dsVatTu.soLuongVT(); 
	int soPhanTuVatTuTrenMotPage = 8; 
	int indexPageVatTu = 0; 
	float toiDaPageVatTu = TienichDoHoa::tinhToiDaPage(soLuongVatTu,soPhanTuVatTuTrenMotPage); 
	int toaDoXVatTu = 400; 
	int toaDoYVatTu = 290; 
	int chieuCaoTableVatTu = 364;
	VatTu** arrVatTu = new VatTu*[soLuongVatTu];  // NHO DELETE DI NHE 
	dsVatTu.BstVatTuToArray(arrVatTu,0); 
	bool hienThiTraCuuVatTu = false; // khi nguoi dung nhap vao day hien thi ra nut bang tra cuu 
	NutBam traCuuVatTu(350,722,200,40,15,0,0,"TRA CUU VAT TU");
	traCuuVatTu.veNut();  
	
	
	
	// BIEN SU DUNG CHO DANH SACH NHAN VIEN -> KHONG CAN PHAI LO DELETE -> DA CO HAM HUY GIAI PHONG  
	int soPhanTuNhanVienTrenMotPage = 8; 
	int indexPageNhanVien = 0; // chi so cua page 
	float toiDaPageNhanVien = TienichDoHoa::tinhToiDaPage(DSNV.soLuongNV(),soPhanTuNhanVienTrenMotPage); 
	int toaDoXNhanVien = 400; 
	int toaDoYNhanVien = 290; 
	int chieuCaoTableNhanVien = 404; 
	bool hienThiTraCuuNhanVien = false; // neu dang bat cai table nay thi => hien thi no len  
	NutBam traCuuNhanVien(820,722,200,40,15,0,0,"TRA CUU NHAN VIEN");
	traCuuNhanVien.veNut();  
	

	NutBam btnSave(margin + 1232 + 34 + 30, canLeTrenHD + 12, WHD * 2 - 34 - 30, 40, mauNhapXuat, mauHightNhapXuat, 1, "SAVE");
	NutBam themCTHD(margin + 1230 + 34 + 30, canLeTrenHD + 90, WHD * 2 - 34 - 30, 40, mauNhapXuat, mauHightNhapXuat, 1, "THANH TOAN");
	ONhap maNV(margin + 6, canLeTrenHD + 12, 160, 40, 60, "MA NV: ", 0, 0, 10);
	
	ONhap soHD(margin + 742, canLeTrenHD + 12, 160, 40, 60, "So HD: ", 0, 0, 10);
	ONhap hoTenNV(margin + 260,canLeTrenHD + 12,300 + 60,40,90,"HO & TEN: ",0,0,25);
	
	ONhap nhapNgay(canLeNgangHD + 630 + 200 + 90 + 110 , canLeTrenHD + 12, 50, 40, 0, "", 0, 0, 2);
	ONhap nhapThang(canLeNgangHD + 606 + 256 + 70 + 55 + 120 , canLeTrenHD + 12, 50, 40, 0, "", 0, 0, 2);
	ONhap nhapNam(canLeNgangHD + 1017 + 160 + 10, canLeTrenHD + 12, 70, 40, 0, "", 0, 0, 4);
	
	ONhap maVT(margin + 6, canLeTrenHD + 90, 160, 40, 60, "MA VT: ", 0, 0, 10);
	// hien thi ra mot cai o de hien thi ra  
	TienichDoHoa::setText(BACKGROUP,15,10,1); 
	outtextxy(margin + 240,canLeTrenHD + 100,"TEN: "); 
	
	NutBam tenVT(margin + 300 ,canLeTrenHD + 90,260,40,14,1,1 ,"");
	tenVT.veNut(); 
	
	ONhap soLuongVT(margin + 400 + 120 + 10 + 30 + 20, canLeTrenHD + 90, 130, 40, 96, "SO LUONG: ", 0, 0, 7);
	ONhap donGia(margin + 660 + 120 + 10 + 30 + 10, canLeTrenHD + 90, 130, 40, 96, "DON GIA: ", 0, 0, 7);
	ONhap VAT(margin + 990 + 60 + 30, canLeTrenHD + 90, 100, 40, 80, "VAT(%): ", 0, 0, 4);
	
	OVuong baoQuanhHD(54, canLeTrenHD, DODAIMANHINH - 12 - 102, 80, 15);
	OVuong baoQuanCTHD(54, canLeTrenHD + 80, DODAIMANHINH - 12 - 102, 80, 15);

	NutBam btnTienToi(margin + 100, 722, 80, 40, 15, 3, 1, ">>");
	NutBam btnLui(margin, 722, 80, 40, 15, 3, 1, "<<");
	
	hoTenNV.veONhap(); 
	soHD.veONhap();
	maNV.veONhap();
	btnSave.veNut();
	Date tempDate;

	
	tempDate.dateToString(nhapNgay.boNhoDem, nhapThang.boNhoDem, nhapNam.boNhoDem);
	nhapNam.veONhap();
	nhapNgay.veONhap();
	nhapThang.veONhap();
	nhapNgay.inNoiDung();
	nhapThang.inNoiDung();
	nhapNam.inNoiDung();
	
	
	maVT.veONhap();
	soLuongVT.veONhap();
	donGia.veONhap();
	VAT.veONhap();
	themCTHD.veNut();

	// O VUONG BAO QUANH
	int mauNenTableHoTro = 0; 
	

	btnTienToi.veNut();
	btnLui.veNut();
	veTableCTHD();
	 

	// TOA DO NUT HIEU CHINH CTHD.
	NutBam hieuChinhCTHD1(margin + 36 + doDaiCoBan * 7 + 190, 354 - 4, 52, 28, 11, 3, 0, "sua");
	NutBam hieuChinhCTHD2(margin + 36 + doDaiCoBan * 7 + 190, 354 + 36 - 4, 52, 28, 11, 3, 0, "sua");
	NutBam hieuChinhCTHD3(margin + 36 + doDaiCoBan * 7 + 190, 354 + 36 * 2 - 4, 52, 28, 11, 3, 0, "sua");
	NutBam hieuChinhCTHD4(margin + 36 + doDaiCoBan * 7 + 190, 354 + 36 * 3 - 4, 52, 28, 11, 3, 0, "sua");
	NutBam hieuChinhCTHD5(margin + 36 + doDaiCoBan * 7 + 190, 354 + 36 * 4 - 4, 52, 28, 11, 3, 0, "sua");
	NutBam hieuChinhCTHD6(margin + 36 + doDaiCoBan * 7 + 190, 354 + 36 * 5 - 4, 52, 28, 11, 3, 0, "sua");
	NutBam hieuChinhCTHD7(margin + 36 + doDaiCoBan * 7 + 190, 354 + 36 * 6 - 4, 52, 28, 11, 3, 0, "sua");
	NutBam hieuChinhCTHD8(margin + 36 + doDaiCoBan * 7 + 190, 354 + 36 * 7 - 4, 52, 28, 11, 3, 0, "sua");
	NutBam hieuChinhCTHD9(margin + 36 + doDaiCoBan * 7 + 190, 354 + 36 * 8 - 4, 52, 28, 11, 3, 0, "sua");
	

	while (true)
	{
		
		if (ismouseclick(WM_LBUTTONDOWN))
		{
			int xclick = -1;
			int yclick = -1;
			getmouseclick(WM_LBUTTONDOWN, xclick, yclick);
			if (nhanVien.isMouseHover(xclick, yclick))
			{
				if (maNV.khongRong() || maVT.khongRong() || soHD.khongRong() || soLuongVT.khongRong() || VAT.khongRong() || donGia.khongRong()) 
				{
					int luaChon = MessageBox(NULL, "Huy Bo Them Hoa Don!", "Thong Bao", MB_ICONWARNING | MB_OKCANCEL);
					if (luaChon == OK){
						index = ID_NV; 
						return; 
					}					
				}
				else {
					index = ID_NV; 
					return; 
				}
				
			}
			if (vatTu.isMouseHover(xclick, yclick))
			{
					if (maNV.khongRong() || maVT.khongRong() || soHD.khongRong() || soLuongVT.khongRong() || VAT.khongRong() || donGia.khongRong()) 
					{
						int luaChon = MessageBox(NULL, "Huy Bo Them Hoa Don!", "Thong Bao", MB_ICONWARNING | MB_OKCANCEL);
						if (luaChon == OK){
							index = ID_VT; 
							return; 
						}					
					}
					else {
						index = ID_VT; 
						return; 
					}
			}
			if (hoaDon.isMouseHover(xclick, yclick))
			{
				if (maNV.khongRong() || maVT.khongRong() || soHD.khongRong() || soLuongVT.khongRong() || VAT.khongRong() || donGia.khongRong()) 
					{
						int luaChon = MessageBox(NULL, "Huy Bo Them Hoa Don!", "Thong Bao", MB_ICONWARNING | MB_OKCANCEL);
						if (luaChon == OK){
							index = ID_HD; 
							return; 
						}					
					}
					else {
						index = ID_HD; 
						return; 
					}
			}
			if (doanhThu.isMouseHover(xclick, yclick))
			{
				if (maNV.khongRong() || maVT.khongRong() || soHD.khongRong() || soLuongVT.khongRong() || VAT.khongRong() || donGia.khongRong()) 
					{
						int luaChon = MessageBox(NULL, "Huy Bo Them Hoa Don!", "Thong Bao", MB_ICONWARNING | MB_OKCANCEL);
						if (luaChon == OK){
							index = ID_DT; 
							return; 
						}					
					}
					else {
						index = ID_DT; 
						return; 
					}
			}

			if (inHD.isMouseHover(xclick, yclick))
			{
				if (maNV.khongRong() || maVT.khongRong() || soHD.khongRong() || soLuongVT.khongRong() || VAT.khongRong() || donGia.khongRong()) 
					{
						int luaChon = MessageBox(NULL, "Huy Bo Them Hoa Don!", "Thong Bao", MB_ICONWARNING | MB_OKCANCEL);
						if (luaChon == OK){
							index = ID_IN_HD; 
							return; 
						}					
					}
					else {
						index = ID_IN_HD; 
						return; 
					}
			}
			if (taoHDNhap.isMouseHover(xclick, yclick))
			{
			if (maNV.khongRong() || maVT.khongRong() || soHD.khongRong() || soLuongVT.khongRong() || VAT.khongRong() || donGia.khongRong()) 
					{
						int luaChon = MessageBox(NULL, "Huy Bo Them Hoa Don!", "Thong Bao", MB_ICONWARNING | MB_OKCANCEL);
						if (luaChon == OK){
							index = ID_THEM_HD_NHAP; 
							return; 
						}					
					}
					else {
						index = ID_THEM_HD_NHAP; 
						return; 
					}
			}
			if (taoHDXuat.isMouseHover(xclick,yclick)) {
				if (maNV.khongRong() || maVT.khongRong() || soHD.khongRong() || soLuongVT.khongRong() || VAT.khongRong() || donGia.khongRong()) 
					{
						int luaChon = MessageBox(NULL, "Huy Bo Them Hoa Don!", "Thong Bao", MB_ICONWARNING | MB_OKCANCEL);
						if (luaChon == OK){
							index = ID_THEM_HD_XUAT; 
							return; 
						}					
					}
					else {
						index = ID_THEM_HD_XUAT; 
						return; 
					}
			}
			
			if (traCuuVatTu.isMouseHover(xclick,yclick)) {
				if(!hienThiTraCuuVatTu) {
					traCuuVatTu.thayDoiTieuDeNut("X");
					hienThiTraCuuVatTu = true; 
					TienichDoHoa::xoaManHinhTheoToaDo(margin, canLeTrenHD + 170, 1600, 410, BACKGROUP);
					hienThiDuLieuVatTu(toaDoXVatTu,toaDoYVatTu,chieuCaoTableVatTu,mauNenTableHoTro,indexPageVatTu,soPhanTuVatTuTrenMotPage,arrVatTu,soLuongVatTu);
					hienThiTraCuuNhanVien = false;
					traCuuNhanVien.thayDoiTieuDeNut("TRA CUU NHAN VIEN"); 
					
				}
				else {
					traCuuVatTu.thayDoiTieuDeNut("Tra Cuu Vat Tu");
					hienThiTraCuuVatTu = false; 
					veTableCTHD();
					// kiem tra song hoa don da them chua  
					if (tonTaiHoaDon) {
						hienThiTongTienCTHD(tempHD->getdsCTHD());
						soLuongCTHDTrenTable = hienThiCTHDLenTable(indexPage, soPhanTuTrenMotPage, tempHD->getdsCTHD(), dsVatTu);
						hienThiChiMuc(DODAIMANHINH / 2 - 110, 736, indexPage, toiDaPage);
					}
					
				}
				
				 
			}
			else if (traCuuNhanVien.isMouseHover(xclick,yclick)) {
				
				if (!hienThiTraCuuNhanVien) 
				{
					traCuuNhanVien.thayDoiTieuDeNut("X");   
					hienThiTraCuuNhanVien = true; 
					TienichDoHoa::xoaManHinhTheoToaDo(margin, canLeTrenHD + 170, 1600, 410, BACKGROUP); // xoa di table CTHD 
					hienThiDuLieuNhanVien(toaDoXNhanVien,toaDoYNhanVien,chieuCaoTableNhanVien,indexPageNhanVien,soPhanTuNhanVienTrenMotPage,DSNV); 
					hienThiTraCuuVatTu = false;
					traCuuVatTu.thayDoiTieuDeNut("TRA CUU VAT TU"); 
				}
				else {
					traCuuNhanVien.thayDoiTieuDeNut("TRA CUU NHAN VIEN");
					hienThiTraCuuNhanVien = false; 
					veTableCTHD();  
					if (tonTaiHoaDon) {
						hienThiTongTienCTHD(tempHD->getdsCTHD());
						soLuongCTHDTrenTable = hienThiCTHDLenTable(indexPage, soPhanTuTrenMotPage, tempHD->getdsCTHD(), dsVatTu);
						hienThiChiMuc(DODAIMANHINH / 2 - 110, 736, indexPage, toiDaPage);
					}
					
				}
				
			}

			else if (maNV.isMouseHover(xclick, yclick))
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
					TienichDoHoa::hienThiThongBao("Vui Long Dien vao Chi Tiet Hoa Don!"); 
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
				tempVT = dsVatTu.timKiemVT(maVT.boNhoDem);  // tim kiem vat tu nay 
				if (maVT.khongRong()) {
					if (tempVT == NULL )
					{
						TienichDoHoa::hienThiThongBao("khong ton tai ma vat tu nay!"); 
						maVT.resetBoNhoDem();
						tenVT.thayDoiTieuDeNut(""); 
					}
					else if (tonTaiHoaDon)
					{
						if (tempHD->getdsCTHD()->timKiemCTHD(maVT.boNhoDem))
						{ // boi vi chua them vaoHD
							TienichDoHoa::hienThiThongBao("Da ton tai Vat Tu nay!"); 
							maVT.resetBoNhoDem();
							tenVT.thayDoiTieuDeNut(EMPTYSTRING); 
						}
						else {
							// phu hop ne 
							tenVT.thayDoiTieuDeNut(tempVT->getInfo()->ten); 
						}
					}
					else if (tempVT != NULL) {
						// truong hop co ton tai vat tu va 
						tenVT.thayDoiTieuDeNut(tempVT->getInfo()->ten); 					
					}
				}
				else {
					tenVT.thayDoiTieuDeNut(EMPTYSTRING); 
				}
				
			}
			else if (soLuongVT.isMouseHover(xclick, yclick))
			{
				soLuongVT.nhapSoThuc("chi nhap so thuc!");
				if (TienichDoHoa::stringToFloat(soLuongVT.boNhoDem) == 0)
				{
					TienichDoHoa::hienThiThongBao("khong hop le!");
					soLuongVT.resetBoNhoDem();
				}
			}
			else if (donGia.isMouseHover(xclick, yclick))
			{
				donGia.nhapSoThuc("chi nhap so thuc!"); // chi nhap so thuc -> khong cho 
				if (donGia.khongRong()) {
					if (TienichDoHoa::stringToFloat(donGia.boNhoDem) == 0) {
						TienichDoHoa::hienThiThongBao("Khong Hop Le!"); 
						donGia.resetBoNhoDem(); 
					}
				}
			}
			else if (VAT.isMouseHover(xclick, yclick))
			{
				VAT.nhapSoThuc("chi nhap so thuc!");
				if (TienichDoHoa::stringToFloat(VAT.boNhoDem) > 100)
				{
					TienichDoHoa::hienThiThongBao("khong hop le!");
					VAT.resetBoNhoDem();
				}
			}
			else if (btnTienToi.isMouseHover(xclick, yclick))
			{
				// kiem tra xem dang o trang thai nao
				if (hienThiTraCuuVatTu && indexPageVatTu < toiDaPageVatTu - 1 ) {
						indexPageVatTu++;
						hienThiDuLieuVatTu(toaDoXVatTu,toaDoYVatTu,chieuCaoTableVatTu,mauNenTableHoTro,indexPageVatTu,soPhanTuVatTuTrenMotPage,arrVatTu,soLuongVatTu);
				}
				else if (hienThiTraCuuNhanVien && indexPageNhanVien < toiDaPageNhanVien - 1  ) {
					indexPageNhanVien++;
					hienThiDuLieuNhanVien(toaDoXNhanVien,toaDoYNhanVien,chieuCaoTableNhanVien,indexPageNhanVien,soPhanTuNhanVienTrenMotPage,DSNV); 
				}
				else {
					if (indexPage < toiDaPage - 1)  
					{
						indexPage++;
						veTableCTHD();
						hienThiTongTienCTHD(tempHD->getdsCTHD());
						soLuongCTHDTrenTable = hienThiCTHDLenTable(indexPage, soPhanTuTrenMotPage, tempHD->getdsCTHD(), dsVatTu);
						hienThiChiMuc(DODAIMANHINH / 2 - 110, 736, indexPage, toiDaPage);
					}
				}
				
			}
			else if (btnLui.isMouseHover(xclick, yclick))
			{
				if (hienThiTraCuuVatTu && indexPageVatTu > 0 ) 
				{
					indexPageVatTu--;
					hienThiDuLieuVatTu(toaDoXVatTu,toaDoYVatTu,chieuCaoTableVatTu,mauNenTableHoTro,indexPageVatTu,soPhanTuVatTuTrenMotPage,arrVatTu,soLuongVatTu);
				}
				else if (hienThiTraCuuNhanVien && indexPageNhanVien > 0) {
					indexPageNhanVien--;
					hienThiDuLieuNhanVien(toaDoXNhanVien,toaDoYNhanVien,chieuCaoTableNhanVien,indexPageNhanVien,soPhanTuNhanVienTrenMotPage,DSNV); 
				}
				else {
					if (indexPage > 0)
					{
						indexPage--;
						veTableCTHD();
						hienThiTongTienCTHD(tempHD->getdsCTHD());
						soLuongCTHDTrenTable = hienThiCTHDLenTable(indexPage, soPhanTuTrenMotPage, tempHD->getdsCTHD(), dsVatTu);
						hienThiChiMuc(DODAIMANHINH / 2 - 110, 736, indexPage, toiDaPage);
					}
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
							TienichDoHoa::hienThiThongBao("dd/mm/yyyy Tuong Lai!");
							khongBiLoiKhiTaoHD = false;
						}
						else if (!Date::ngayThangNamHopLe(tempDate))
						{
							TienichDoHoa::hienThiThongBao("dd/mm/yyyy Khong Hop Le!");
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
								tempHD = tempNV->dsHoaDon.themVaoCuoiHD(soHD.boNhoDem, tempDate, HOADONXUAT, tempNV->getHoTen());
							}
							else
							{
								tempHD = tempNV->dsHoaDon.themVaoCuoiHD(soHD.boNhoDem, tempDate, HOADONNHAP, tempNV->getHoTen());
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
								toiDaPage = TienichDoHoa::tinhToiDaPage(soLuongCTHD,soPhanTuTrenMotPage); 
								
								veTableCTHD();
								soLuongCTHDTrenTable = hienThiCTHDLenTable(indexPage, soPhanTuTrenMotPage, tempHD->getdsCTHD(), dsVatTu);
								hienThiTongTienCTHD(tempHD->getdsCTHD());
								hienThiChiMuc(DODAIMANHINH / 2 - 110, 736, indexPage, toiDaPage);
								
								maVT.resetBoNhoDem();
								soLuongVT.resetBoNhoDem();
								donGia.resetBoNhoDem();
								VAT.resetBoNhoDem();
								tenVT.thayDoiTieuDeNut(""); 
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
					nhapVaoChinhSua = true;  // DANH DAU NGUOI DUNG NHAP VAO CHINH SUA 
				}
			}
			else if (hieuChinhCTHD2.isMouseHover(xclick, yclick))
			{
				if (soLuongCTHDTrenTable >= 1)
				{
					pointerCTHD = tempHD->getdsCTHD()->traVeCTHDTheoindex(1 + soPhanTuTrenMotPage * indexPage);
					nhapVaoChinhSua = true;
				}
			}
			else if (hieuChinhCTHD3.isMouseHover(xclick, yclick))
			{
				if (soLuongCTHDTrenTable >= 2)
				{
					pointerCTHD = tempHD->getdsCTHD()->traVeCTHDTheoindex(2 + soPhanTuTrenMotPage * indexPage);
					nhapVaoChinhSua = true;
				}
			}
			else if (hieuChinhCTHD4.isMouseHover(xclick, yclick))
			{
				if (soLuongCTHDTrenTable >= 3)
				{
					pointerCTHD = tempHD->getdsCTHD()->traVeCTHDTheoindex(3 + soPhanTuTrenMotPage * indexPage);
					nhapVaoChinhSua = true;
				}
			}
			else if (hieuChinhCTHD5.isMouseHover(xclick, yclick))
			{
				if (soLuongCTHDTrenTable >= 4)
				{
					pointerCTHD = tempHD->getdsCTHD()->traVeCTHDTheoindex(4 + soPhanTuTrenMotPage * indexPage);
					nhapVaoChinhSua = true;
				}
			}
			else if (hieuChinhCTHD6.isMouseHover(xclick, yclick))
			{
				if (soLuongCTHDTrenTable >= 5)
				{
					pointerCTHD = tempHD->getdsCTHD()->traVeCTHDTheoindex(5 + soPhanTuTrenMotPage * indexPage);
					nhapVaoChinhSua = true;
				}
			}
			else if (hieuChinhCTHD7.isMouseHover(xclick, yclick))
			{
				if (soLuongCTHDTrenTable >= 7)
				{
					pointerCTHD = tempHD->getdsCTHD()->traVeCTHDTheoindex(6 + soPhanTuTrenMotPage * indexPage);
					nhapVaoChinhSua = true;
				}
			}
			else if (hieuChinhCTHD8.isMouseHover(xclick, yclick))
			{
				if (soLuongCTHDTrenTable >= 8)
				{
					pointerCTHD = tempHD->getdsCTHD()->traVeCTHDTheoindex(7 + soPhanTuTrenMotPage * indexPage);
					nhapVaoChinhSua = true;
				}
			}
			else if (hieuChinhCTHD9.isMouseHover(xclick, yclick))
			{
				if (soLuongCTHDTrenTable >= 9)
				{
					pointerCTHD = tempHD->getdsCTHD()->traVeCTHDTheoindex(8 + soPhanTuTrenMotPage * indexPage);
					nhapVaoChinhSua = true;
				}
			}
			if (nhapVaoChinhSua) {
				if (pointerCTHD != NULL)
					{
						if (hoaDonXuat) {
							hienThiChinhSuaCTHD(pointerCTHD, tempHD->getdsCTHD(), dsVatTu, HOADONXUAT);
						}
						else {
							hienThiChinhSuaCTHD(pointerCTHD, tempHD->getdsCTHD(), dsVatTu, HOADONNHAP);
						}

						toiDaPage = TienichDoHoa::tinhToiDaPage(tempHD->getdsCTHD()->soLuongCTHD(),soPhanTuTrenMotPage); 
						veTableCTHD();
						soLuongCTHDTrenTable = hienThiCTHDLenTable(indexPage, soPhanTuTrenMotPage, tempHD->getdsCTHD(), dsVatTu);
						hienThiChiMuc(DODAIMANHINH / 2 - 110, 736, indexPage, toiDaPage);
						hienThiTongTienCTHD(tempHD->getdsCTHD());
						nhapVaoChinhSua = false; 
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
	themHDXuat.veNut();
	themHDNhap.veNut();
	inHD.veNut();



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
				hienThiThemHoaDonNhapVaXuat(dsVatTu, DSNV, index, vatTu, nhanVien, hoaDon, doanhThu, themHDXuat,themHDNhap, inHD, true);
			}
			else if (index == ID_IN_HD)
			{
				index = -1;
				inHD.duocChon();
				themHDNhap.khongDuocChon();
				themHDXuat.khongDuocChon();
				hienThiXuatHoaDon(dsVatTu, DSNV, index, vatTu, nhanVien, doanhThu, themHDNhap, themHDXuat, inHD);
			}

			else if (index == ID_GOI_Y_DSNV)
			{
				themHDNhap.khongDuocChon();
				themHDXuat.khongDuocChon();
				inHD.khongDuocChon();
			}
			else if (index == ID_GOI_Y_VT)
			{
			}
			else if (index == ID_THEM_HD_NHAP)
			{
				themHDNhap.duocChon();
				themHDXuat.khongDuocChon();
				inHD.khongDuocChon();
				hienThiThemHoaDonNhapVaXuat(dsVatTu, DSNV, index, vatTu, nhanVien, hoaDon, doanhThu,themHDXuat, themHDNhap, inHD,  false);
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
				hienThiThemHoaDonNhapVaXuat(dsVatTu, DSNV, index, vatTu, nhanVien, hoaDon, doanhThu,themHDXuat, themHDNhap, inHD,  true);
			}
			else if (themHDNhap.isMouseHover(xclick, yclick))
			{
				themHDNhap.duocChon();
				themHDXuat.khongDuocChon();
				inHD.khongDuocChon();
				hienThiThemHoaDonNhapVaXuat(dsVatTu, DSNV, index, vatTu, nhanVien, hoaDon, doanhThu,themHDXuat, themHDNhap, inHD,  false);
			}

			else if (inHD.isMouseHover(xclick, yclick))
			{
				themHDNhap.khongDuocChon();
				themHDXuat.khongDuocChon();
				inHD.duocChon();
				hienThiXuatHoaDon(dsVatTu, DSNV, index, vatTu, nhanVien, doanhThu, themHDNhap, themHDXuat, inHD);
			}
		}
		delay(1);
	}
}


