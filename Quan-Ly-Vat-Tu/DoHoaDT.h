#pragma once
using namespace std;
#include "Tienich.h"
#include "BienDoHoa.h"
#include "DoanhThu.h"




void hienThiTop10VatTu(DoanhThuVatTu arrDTVT[],Date start,Date end) {  // truyen vao 1 cai mang dap sap xep va viec cua ta la hien thi ra thoi 
	// chi can hien thi ra 10 vat tu thoi khong lam gi ca 
	// ve ra cai bang 
	// hien thi ra 10 vat tu do len thoi 
	TienichDoHoa::xoaManHinhTheoToaDo(0, 96, DODAIMANHINH, 1000, BACKGROUP);
	// nen in ra cac truong nhu sau : 
	// lay ra nhung vat tu va hien thi nhung thong tin sau 


	
	setbkcolor(0); 
	setcolor(15); 
	settextstyle(6,0,3);
	outtextxy(520,160,"TOP 10 VAT TU BAN CHAY"); 
	string strStart = "Tu ngay :  " + start.getStringDate(); 
	string strEnd = "Den ngay :  " + end.getStringDate(); 
	outtextxy(360 + 30,200,strStart.c_str());
	outtextxy(750 + 30,200,strEnd.c_str());
	
	// ve ra 10 cai khung va in ra theo thu tu 
	
	// lay ra 10 vat tu dau tien 
	// troc tien in ra cai bang ! 
	TienichDoHoa::xoaManHinhTheoToaDo(margin, canLeTrenHD + 170, 1600, 400, BACKGROUP);
	int cachLe = margin + 60; 
	NutBam maVT(cachLe + doDaiCoban , canLeTrenHD + 170, doDaiCoban + 3 , 40, colorTieuDe, 7, conlorTextTieuDe, "MA VT");
	NutBam tenVT(cachLe + doDaiCoban * 2 + 3 * 2, canLeTrenHD + 170, doDaiCoban*2, 40, colorTieuDe, 7, conlorTextTieuDe, "TEN VAT TU");
	NutBam donViTinh(cachLe + doDaiCoban * 4 + 3 * 3, canLeTrenHD + 170, doDaiCoban, 40, colorTieuDe, 7, conlorTextTieuDe, "DON VI TINH");
	NutBam soLuongTon(cachLe + doDaiCoban * 5 + 3 * 4, canLeTrenHD + 170, doDaiCoban, 40, colorTieuDe, 7, conlorTextTieuDe, "SO LUONG TON");
	NutBam tongTienVT(cachLe + doDaiCoban * 6 + 3 * 5, canLeTrenHD + 170, doDaiCoban + 3, 40, colorTieuDe, 7, conlorTextTieuDe, "DOANH THU");
	

	maVT.veNut(); 
	tenVT.veNut(); 
	donViTinh.veNut(); 
	soLuongTon.veNut(); 
	tongTienVT.veNut(); 	

	OVuong table(cachLe + doDaiCoban, canLeTrenHD + 170, doDaiCoban * 6 + 18, 400, 15);
	setcolor(15);
	line(cachLe + doDaiCoban * 2 + 3, canLeTrenHD + 170, cachLe + doDaiCoban * 2 + 3, 690);
	line(cachLe + doDaiCoban * 4 + 3 * 2, canLeTrenHD + 170, cachLe + doDaiCoban * 4 + 3 * 2, 690);
	line(cachLe + doDaiCoban * 5 + 3 * 3, canLeTrenHD + 170, cachLe + doDaiCoban * 5 + 3 * 3, 690);
	line(cachLe + doDaiCoban * 6 + 3 * 4, canLeTrenHD + 170, cachLe + doDaiCoban * 6 + 3 * 4, 690);
	
	// hien thi 10 vat tu sau khi duoc sap xep len
	

	
	int khoanCach = 36; 
	int marginTop10 = 340; 
	
	string temp; 
	
	int dem = 0; 
	
	for (int i = 0; i < 10;i++) {
		if (arrDTVT[i].doanhThu != 0 ) {  
			setbkcolor(0); 
			line(cachLe + doDaiCoban ,marginTop10 + khoanCach*i + 26,cachLe + doDaiCoban + 948,marginTop10 + khoanCach*i + 26);
			outtextxy(cachLe + doDaiCoban + 60,marginTop10 + khoanCach*i, arrDTVT[i].pVatTu->maVT.c_str() ); 
			outtextxy(cachLe + doDaiCoban*2 + 30,marginTop10 + khoanCach*i, arrDTVT[i].pVatTu->ten.c_str() ); 
			outtextxy(cachLe + doDaiCoban*4 + 30,marginTop10 + khoanCach*i, arrDTVT[i].pVatTu->donVi.c_str() );
			temp = TienichDoHoa::floatToString(arrDTVT[i].pVatTu->soLuongTon); 
			outtextxy(cachLe + doDaiCoban*5 + 30,marginTop10 + khoanCach*i, temp.c_str() );
			temp = TienichDoHoa::floatToString(arrDTVT[i].doanhThu);
			outtextxy(cachLe + doDaiCoban*6 + 30,marginTop10 + khoanCach*i, temp.c_str() );
			dem++; 
		}
		
		
	}
	if (dem == 0) {
		MessageBox(NULL, "Thong Bao", "Doanh Thu Tat Ca Vat Tu Trong Thoi Gian Nay la 0!", MB_ICONINFORMATION | MB_OK);
	}
	else if (dem != 10) {
		outtextxy(264, 720, "*Nhung vat tu con lai co doanh thu la 0");
	}
	
	
}
int hienThiDuLieuLenTableXemHoaDonTheoDate(int indexPage, int soLuongItemPage, HoaDon** hoaDonHopLe,int soLuongHoaDon)
{
	const int marginTable = margin + 36;
	const int marginTop = 344;
	const int khoanCach = 46;
	int dem = 0; // bien dung dem so luong cua CTHD tren table.
	string temp;
	for (int i = 0; i < soLuongItemPage; i++)
	{
		setcolor(CinputText);
		setbkcolor(0);
		settextstyle(6, 0, 1);
		if (i + indexPage * soLuongItemPage < soLuongHoaDon)
		{
			dem++;
			int index = i + indexPage * soLuongItemPage; 
			outtextxy(marginTable + doDaiCoban + 50, marginTop + khoanCach * i, hoaDonHopLe[index]->soHD.c_str());
			outtextxy(marginTable + doDaiCoban * 2 + 40, marginTop + khoanCach * i,hoaDonHopLe[index]->date.getStringDate().c_str());
			temp = hoaDonHopLe[index]->loai == "X" ? "Xuat" : "Nhap"; 
			outtextxy(marginTable + doDaiCoban * 3 + 80, marginTop + khoanCach * i, temp.c_str());
			outtextxy(marginTable + doDaiCoban * 4 + 60, marginTop + khoanCach * i, hoaDonHopLe[index]->tenNVLapHD.c_str());
			temp = TienichDoHoa::floatToString(hoaDonHopLe[index]->dsCTHD.tinhTongTien());
			outtextxy(marginTable + doDaiCoban * 6 + 60, marginTop + khoanCach * i,temp.c_str() );
		}
	}
	return dem;

}

void veTableXemHDTheoDate()
{
	TienichDoHoa::xoaManHinhTheoToaDo(margin, canLeTrenHD + 170, 1600, 400, BACKGROUP);
	int cachLe = margin + 60; 
	NutBam soHD(cachLe + doDaiCoban , canLeTrenHD + 170, doDaiCoban + 3 , 40, colorTieuDe, 7, conlorTextTieuDe, "SO HOA DON");
	NutBam ngayLap(cachLe + doDaiCoban * 2 + 3 * 2, canLeTrenHD + 170, doDaiCoban, 40, colorTieuDe, 7, conlorTextTieuDe, "NGAY LAP");
	NutBam loaiHoaDon(cachLe + doDaiCoban * 3 + 3 * 3, canLeTrenHD + 170, doDaiCoban, 40, colorTieuDe, 7, conlorTextTieuDe, "LOAI HOA DON");
	NutBam hoTenNV(cachLe + doDaiCoban * 4 + 3 * 4, canLeTrenHD + 170, doDaiCoban*2, 40, colorTieuDe, 7, conlorTextTieuDe, "HO TEN NHAN VIEN LAP");
	NutBam titleVAT(cachLe + doDaiCoban * 6 + 3 * 5, canLeTrenHD + 170, doDaiCoban + 3, 40, colorTieuDe, 7, conlorTextTieuDe, "THANH TIEN");
	

	soHD.veNut(); 
	ngayLap.veNut(); 
	loaiHoaDon.veNut(); 
	hoTenNV.veNut(); 
	titleVAT.veNut(); 	

	OVuong table(cachLe + doDaiCoban, canLeTrenHD + 170, doDaiCoban * 6 + 18, 400, 15);
	setcolor(15);
	line(cachLe + doDaiCoban * 2 + 3, canLeTrenHD + 170, cachLe + doDaiCoban * 2 + 3, 690);
	line(cachLe + doDaiCoban * 3 + 3 * 2, canLeTrenHD + 170, cachLe + doDaiCoban * 3 + 3 * 2, 690);
	line(cachLe + doDaiCoban * 4 + 3 * 3, canLeTrenHD + 170, cachLe + doDaiCoban * 4 + 3 * 3, 690);
	line(cachLe + doDaiCoban * 6 + 3 * 4, canLeTrenHD + 170, cachLe + doDaiCoban * 6 + 3 * 4, 690);

}

//,NutBam &vatTu,NutBam nhanVien,NutBam &hoaDon,NutBam &doanhThu,NutBam &doanhThuNam


void hienThiGiaoDienHoaDonTrongKhoanThoiGian (Date &start,Date &end,HoaDon** hoaDonHopLe,int soLuong,int &index
	,NutBam &vatTu,NutBam nhanVien,NutBam &hoaDon,NutBam &doanhThu,NutBam &doanhThuNam
) 
{
	TienichDoHoa::xoaManHinhTheoToaDo(0, 96, DODAIMANHINH, 1000, BACKGROUP);
	
	// khi v�o ham nay tuc la co hoa don moi vao 
	int indexPage = 0; 
	int iTempTrenMotPage = 9; 
	setbkcolor(0); 
	setcolor(15); 
	settextstyle(6,0,3);
	outtextxy(330,160,"BANG LIET KE HOA DON TRONG KHOAN THOI GIAN"); 
	string strStart = "TU NGAY :  " + start.getStringDate(); 
	string strEnd = "DEN NGAY :  " + end.getStringDate(); 
	outtextxy(360 + 30,200,strStart.c_str());
	outtextxy(750 + 30,200,strEnd.c_str());
	
	// ve ra hai cai nut 
	NutBam btnLui(276,730,100,40,11,3,0,"BACK"); 
	btnLui.veNut(); 
	
	NutBam btnTien(276 + 848,730,100,40,11,3,0,"NEXT"); 
	btnTien.veNut(); 
	
	veTableXemHDTheoDate(); 
	
	float toiDaPage = (float)soLuong / (float)iTempTrenMotPage;
	int soLuongCTHDTrenTable = hienThiDuLieuLenTableXemHoaDonTheoDate(indexPage,iTempTrenMotPage,hoaDonHopLe,soLuong);
	
	
	int soLuongPage = soLuong / iTempTrenMotPage;
	
	if (!kiemTraSoNguyen(TienichDoHoa::floatToString(toiDaPage)))
	{
		toiDaPage = (int)toiDaPage + 1;
	}
	
	hienThiChiMuc(DODAIMANHINH / 2 - 30,736,indexPage,toiDaPage); 

	int xclick = -1; 
	int yclick = -1; 
	
	while(true) {
		if (ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_LBUTTONDOWN, xclick, yclick);
			
			// bac su kien tien toi 
			if (btnLui.isMouseHover(xclick,yclick)) {
				if (indexPage > 0 ) { 
					indexPage--; 
					veTableXemHDTheoDate(); 
					soLuongCTHDTrenTable = hienThiDuLieuLenTableXemHoaDonTheoDate(indexPage,iTempTrenMotPage,hoaDonHopLe,soLuong);
					hienThiChiMuc(DODAIMANHINH / 2 - 30,736,indexPage,toiDaPage); 
				}
			}
			else if (btnTien.isMouseHover(xclick,yclick)) {
				if (indexPage < toiDaPage - 1)
				{
					indexPage++;
					veTableXemHDTheoDate(); 
					soLuongCTHDTrenTable = hienThiDuLieuLenTableXemHoaDonTheoDate(indexPage,iTempTrenMotPage,hoaDonHopLe,soLuong);
					hienThiChiMuc(DODAIMANHINH / 2 - 30,736,indexPage,toiDaPage); 
				}
			}
			else if (vatTu.isMouseHover(xclick,yclick)) {
				index = ID_VT; 
				return;
			}
			else if (nhanVien.isMouseHover(xclick,yclick)) {
				index = ID_NV; 
				return;
			}
			else if (hoaDon.isMouseHover(xclick,yclick)) {
				index = ID_HD; 
				return;
			}
			else if (doanhThu.isMouseHover(xclick,yclick)) {
				index = ID_DT; 
				return;
			}
			
			
		}
		delay(1); 
	}
	
}

void inHoaDonTheoNgayThangNam(BstVatTu &dsVatTu,dsNhanVien &DSNV,int &index,NutBam &vatTu,NutBam &nhanVien,NutBam &hoaDon,NutBam &doanhThu,NutBam &thongKe, NutBam &doanhThuNam ) {
	TienichDoHoa::xoaManHinhTheoToaDo(0, canLeTrenHD, 1600, 1600, BACKGROUP);
	ONhap nhapNgayBD(510,350,100,40,40,"TU: ",0,0,2);  // nhap ngay bac dau 
	ONhap nhapThangBD(550 + 120,350,100,40,40,"/",0,0,2);
	ONhap nhapNamBD(700 + 120,350,100,40,40,"/",0,0,4);
	ONhap nhapNgayKT(510,450,100,40,40,"DEN: ",0,0,2);  // nhap ngay bac dau 
	ONhap nhapThangKT(550 + 120,450,100,40,40,"/",0,0,2);
	ONhap nhapNamKT(700 + 120,450,100,40,40,"/",0,0,4); 
	nhapNgayBD.veONhap();
	nhapThangBD.veONhap(); 
	nhapNamBD.veONhap(); 
	
	nhapNgayKT.veONhap(); 
	nhapThangKT.veONhap(); 
	nhapNamKT.veONhap(); 
	
	
	// cho ngay thang mat dinh la ngay hien tai 
	
	
	// tao ra 1 cai o vong bao quanh  
	NutBam title(450,260,570,40,14,1,1,"THONG KE HOA DON && VAT TU"); 
	title.veNut(); 
	OVuong box (450,300,570,326,15); 
	
	NutBam thongKeHD(470,540,260,40,15,0,0,"THONG KE HOA DON");
	
	NutBam thongKeTop10VT(470 + 260 + 10,540,260,40,15,0,0,"10 VAT TU BAN CHAY");  
	thongKeTop10VT.veNut(); 
	thongKeHD.veNut();
	// bac su kien click
	int xclick = -1; 
	int yclick = -1; 
	Date start,end; 
	
	end.setDateNow(); // mat dinh cho ve ngay nay! 
	nhapNgayKT.boNhoDem = TienichDoHoa::intToString(end.ngay); 
	nhapThangKT.boNhoDem = TienichDoHoa::intToString(end.thang); 
	nhapNamKT.boNhoDem = TienichDoHoa::intToString(end.nam); 
	nhapNgayKT.inNoiDung(); 
	nhapThangKT.inNoiDung(); 
	nhapNamKT.inNoiDung(); 
	while (true) {
		if (index >= 0 && index <= 3) {
			return; 
		}
		else if (ismouseclick(WM_LBUTTONDOWN))
			{
				getmouseclick(WM_LBUTTONDOWN, xclick, yclick);
				if (vatTu.isMouseHover(xclick,yclick)) {
					index = ID_VT; 
					return; 
				}
				else if (nhanVien.isMouseHover(xclick,yclick)) {
					index = ID_VT; 
					return; 
				}
				else if (hoaDon.isMouseHover(xclick,yclick)) {
					index = ID_HD; 
					return; 
				}
				else if (doanhThu.isMouseHover(xclick,yclick)) {
					index = ID_DT; 
					return; 
				}
				else if (doanhThu.isMouseHover(xclick,yclick)) {
					index = ID_DT_NAM; 
					return; 
				}
				
				else if (doanhThuNam.isMouseHover(xclick,yclick)) {
					index = ID_DT_NAM; 
					return; 
				}
				else if (thongKe.isMouseHover(xclick, yclick)) {
					index = ID_DT_THONG_KE;
					return; 
				}
				if (nhapNgayBD.isMouseHover(xclick,yclick))
				{
					nhapNgayBD.NhapVao(kiTuSo,"chi nhap so!");
					
					start.ngay = TienichDoHoa::stringToInt(nhapNgayBD.boNhoDem);
					
					if (nhapNgayBD.boNhoDem != "")
						{
							if (!Date::hopLeNgay(start.ngay))
							{
								MessageBox(NULL, "Ngay Khong Hop Le!", "Thong Bao", MB_ICONINFORMATION | MB_OK);
								nhapNgayBD.resetBoNhoDem();
							}
							else if (nhapThangBD.boNhoDem != "" && nhapNamBD.boNhoDem != "")
							{ 
								start.thang = TienichDoHoa::stringToInt(nhapThangBD.boNhoDem);
								start.nam = TienichDoHoa::stringToInt(nhapNamBD.boNhoDem);
								if (!Date::ngayThangNamHopLe(start.ngay, start.thang, start.nam))
								{
									MessageBox(NULL, "Ngay-Thang-Nam khong hop le!", "Thong Bao", MB_ICONINFORMATION | MB_OK);
									nhapNgayBD.resetBoNhoDem();
									nhapThangBD.resetBoNhoDem();
									nhapNamBD.resetBoNhoDem();
								}
							}
						}
					
				}
				else if (nhapThangBD.isMouseHover(xclick,yclick))
				{
					nhapThangBD.NhapVao(kiTuSo,"chi nhap so!"); 
					start.thang = TienichDoHoa::stringToInt(nhapThangBD.boNhoDem);
					if (nhapThangBD.boNhoDem != "")
					{
						if (!Date::hopLeThang(start.thang))
						{
							MessageBox(NULL, "Thang Khong Hop Le!", "Thong Bao", MB_ICONINFORMATION | MB_OK);
							nhapThangBD.resetBoNhoDem();
						}
						else if (nhapNgayBD.boNhoDem != "" && nhapNamBD.boNhoDem != "")
						{ 
							start.ngay = TienichDoHoa::stringToInt(nhapNgayBD.boNhoDem);
							start.nam = TienichDoHoa::stringToInt(nhapNamBD.boNhoDem);
							if (!Date::ngayThangNamHopLe(start.ngay, start.thang, start.nam))
							{
								MessageBox(NULL, "Ngay-Thang-Nam khong hop le!", "Thong Bao", MB_ICONINFORMATION | MB_OK);
								nhapNgayBD.resetBoNhoDem();
								nhapThangBD.resetBoNhoDem();
								nhapNamBD.resetBoNhoDem();
							}
						}
					}
				}
				else if (nhapNamBD.isMouseHover(xclick,yclick))
				{
					 nhapNamBD.NhapVao(kiTuSo,"chi nhap so!"); 
					 start.nam = TienichDoHoa::stringToInt(nhapNamBD.boNhoDem);
					if (nhapNamBD.boNhoDem != "")
					{
						if (!Date::hopLeNam(start.nam))
						{
							MessageBox(NULL, "Nam Khong Hop Le!", "Thong Bao", MB_ICONINFORMATION | MB_OK);
							nhapNamBD.resetBoNhoDem();
						}
						else if (nhapNgayBD.boNhoDem != "" && nhapThangBD.boNhoDem != "")
						{
							start.ngay = TienichDoHoa::stringToInt(nhapNgayBD.boNhoDem);
							start.thang = TienichDoHoa::stringToInt(nhapThangBD.boNhoDem);
							if (!Date::ngayThangNamHopLe(start.ngay, start.thang, start.nam))
							{
								MessageBox(NULL, "Ngay-Thang-Nam khong hop le!", "Thong Bao", MB_ICONINFORMATION | MB_OK);
								nhapNgayBD.resetBoNhoDem();
								nhapThangBD.resetBoNhoDem();
								nhapNamBD.resetBoNhoDem();
							}
						}
					}
				}
				
				// NHAP NGAY KET THUC
				
				else if (nhapNgayKT.isMouseHover(xclick,yclick))
				{
					nhapNgayKT.NhapVao(kiTuSo,"chi nhap so!");
					end.ngay = TienichDoHoa::stringToInt(nhapNgayKT.boNhoDem);
					if (nhapNgayKT.boNhoDem != "")
						{
							if (!Date::hopLeNgay(end.ngay))
							{
								MessageBox(NULL, "Ngay Khong Hop Le!", "Thong Bao", MB_ICONINFORMATION | MB_OK);
								nhapNgayKT.resetBoNhoDem();
							}
							else if (nhapThangKT.boNhoDem != "" && nhapNamKT.boNhoDem != "")
							{ 
								end.thang = TienichDoHoa::stringToInt(nhapThangKT.boNhoDem);
								end.nam = TienichDoHoa::stringToInt(nhapNamKT.boNhoDem);
								if (!Date::ngayThangNamHopLe(end.ngay, end.thang, end.nam))
								{
									MessageBox(NULL, "Ngay-Thang-Nam khong hop le!", "Thong Bao", MB_ICONINFORMATION | MB_OK);
									nhapNgayKT.resetBoNhoDem();
									nhapThangKT.resetBoNhoDem();
									nhapNamKT.resetBoNhoDem();
								}
							}
						}
				}
				else if (nhapThangKT.isMouseHover(xclick,yclick))
				{
					nhapThangKT.NhapVao(kiTuSo,"chi nhap so!"); 
					
					end.thang = TienichDoHoa::stringToInt(nhapThangKT.boNhoDem);
					if (nhapThangKT.boNhoDem != "")
					{
						if (!Date::hopLeThang(end.thang))
						{
							MessageBox(NULL, "Thang Khong Hop Le!", "Thong Bao", MB_ICONINFORMATION | MB_OK);
							nhapThangKT.resetBoNhoDem();
						}
						else if (nhapNgayKT.boNhoDem != "" && nhapNamKT.boNhoDem != "")
						{ 
							end.ngay = TienichDoHoa::stringToInt(nhapNgayKT.boNhoDem);
							end.nam = TienichDoHoa::stringToInt(nhapNamKT.boNhoDem);
							if (!Date::ngayThangNamHopLe(end.ngay, end.thang, end.nam))
							{
								MessageBox(NULL, "Ngay-Thang-Nam khong hop le!", "Thong Bao", MB_ICONINFORMATION | MB_OK);
								nhapNgayKT.resetBoNhoDem();
								nhapThangKT.resetBoNhoDem();
								nhapNamKT.resetBoNhoDem();
							}
						}
					}
					
				}
				else if (nhapNamKT.isMouseHover(xclick,yclick))
				{
					 nhapNamKT.NhapVao(kiTuSo,"chi nhap so!");
					 end.nam = TienichDoHoa::stringToInt(nhapNamKT.boNhoDem);
					if (nhapNamKT.boNhoDem != "")
					{
						if (!Date::hopLeNam(end.nam))
						{
							MessageBox(NULL, "Nam Khong Hop Le!", "Thong Bao", MB_ICONINFORMATION | MB_OK);
							nhapNamKT.resetBoNhoDem();
						}
						else if (nhapNgayKT.boNhoDem != "" && nhapThangKT.boNhoDem != "")
						{
							end.ngay = TienichDoHoa::stringToInt(nhapNgayKT.boNhoDem);
							end.thang = TienichDoHoa::stringToInt(nhapThangKT.boNhoDem);
							if (!Date::ngayThangNamHopLe(end.ngay, end.thang, end.nam))
							{
								MessageBox(NULL, "Ngay-Thang-Nam khong hop le!", "Thong Bao", MB_ICONINFORMATION | MB_OK);
								nhapNgayKT.resetBoNhoDem();
								nhapThangKT.resetBoNhoDem();
								nhapNamKT.resetBoNhoDem();
							}
						}
					} 
				} 
				
	
				

			else if (thongKeHD.isMouseHover(xclick,yclick))
			 	{
					if (Date::soSanhBeHonHoacBangDate(start,end)
					&& nhapNgayBD.khongRong() && nhapThangBD.khongRong() && nhapNamBD.khongRong() &&
					nhapNgayKT.khongRong() && nhapThangKT.khongRong() && nhapNamKT.khongRong() 
					) {  // da thoa man!
					int soLuongHoaDon = DSNV.soLuongHD(); 
					HoaDon** arrHoaDon = new HoaDon*[soLuongHoaDon];   
					HoaDon** hoaDonHopLe = new HoaDon*[soLuongHoaDon]; // su dung it hon ! 
					int index = 0; // bien chi so mang 
					DSNV.listToArrayHoaDon(arrHoaDon,index); 
					
					int soLuongHDHopLe = DSNV.hoaDonTheoDate(arrHoaDon,hoaDonHopLe,soLuongHoaDon,start,end); 
					
					if (soLuongHDHopLe == 0) 
					{
						MessageBox(NULL, "Khong Ton Tai Hoa Don Trong Khoan Thoi Gian Nay!", "Thong Bao", MB_ICONINFORMATION | MB_OK);
					}
					else  // hien thi ra table ! 
					{ 
						hienThiGiaoDienHoaDonTrongKhoanThoiGian (start,end,hoaDonHopLe,soLuongHDHopLe,index,vatTu,nhanVien,hoaDon,doanhThu,doanhThuNam);   // da truyen vao ds hoa don hop le! 	
					}
					delete []arrHoaDon; 
				}
				else 
				{
					MessageBox(NULL, "Thoi gian khong hop le!", "Thong Bao", MB_ICONINFORMATION | MB_OK);	
				}	
				}
				else if (thongKeTop10VT.isMouseHover(xclick,yclick)) {
					// kiem tra ngay thang nam hop le hay chua 
					if (Date::soSanhBeHonHoacBangDate(start,end)
					&& nhapNgayBD.khongRong() && nhapThangBD.khongRong() && nhapNamBD.khongRong() &&
					nhapNgayKT.khongRong() && nhapThangKT.khongRong() && nhapNamKT.khongRong() 
					) {
						int soLuongHoaDon = DSNV.soLuongHD(); 
						int soLuongVatTu = dsVatTu.soLuongVT(); 
						HoaDon** arrHoaDon = new HoaDon*[soLuongHoaDon]; 
						DoanhThuVatTu arrDTVT[1000]; 
						int index = 0; 
						DSNV.listToArrayHoaDon(arrHoaDon,index); 
						dsVatTu.BstVatTuToDoanhThuVatTu(arrDTVT,0); 
						
						// tiep tuc la sap xep ra 
						tinhDoanhThu(arrDTVT,soLuongVatTu,arrHoaDon,soLuongHoaDon,start,end);
						sapXepDoanhThuVatTu(arrDTVT,soLuongVatTu); 
						hienThiTop10VatTu(arrDTVT,start,end); 	
						delete [] arrHoaDon;		
					}
					else {
							MessageBox(NULL, "Thoi gian khong hop le!", "Thong Bao", MB_ICONINFORMATION | MB_OK);	
					}
					
				}
				}
			
					
				delay(10);
			
			}
		
	
}


void inDoanhThuNam(BstVatTu &dsVatTu,dsNhanVien &DSNV,int &index,NutBam &vatTu,NutBam &nhanVien,NutBam &hoaDon,

NutBam &doanhThu,NutBam &thongKe,NutBam &doanhThuNam) {
	
	TienichDoHoa::xoaManHinhTheoToaDo(0, 96, DODAIMANHINH, 1000, BACKGROUP);
	

	
	NutBam title(450,260,570,40,14,1,1,"DOANH THU THEO NAM"); 
	title.veNut(); 
	OVuong box (450,300,570,326,15); 
	setcolor(14); 
	setbkcolor(0); 
	
	NutBam thongKeResult(536,540 ,400,40,13,0,0,"THONG KE");
	
	thongKeResult.veNut(); 
	

	ONhap nhapNam(540 + 50,406,100,40,100,"",0,0,4);
	
	Date tempDate; 
	tempDate.setDateNow();  
	
	// set cho nam mac dinh 
	nhapNam.boNhoDem = TienichDoHoa::intToString(tempDate.nam); 
	// hien thi nam len 
	
	
	
	
	nhapNam.veONhap(); 
	nhapNam.inNoiDung(); 
	int xclick = - 1; 
	int yclick = -1;
	
	while (true) {
		if (ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_LBUTTONDOWN, xclick, yclick);
			
			if (vatTu.isMouseHover(xclick,yclick)) {
				index = ID_VT; 
				return; 
			}
			else if (nhanVien.isMouseHover(xclick,yclick)) {
				index = ID_NV; 
				return; 
			}
			else if (hoaDon.isMouseHover(xclick,yclick)) {
				index = ID_HD;
				return; 
			}
			else if (doanhThu.isMouseHover(xclick,yclick)) {
				index = ID_DT; 
				return; 
			}
			else if (thongKe.isMouseHover(xclick,yclick)) {
				index = ID_DT_THONG_KE; 
				return; 
			}
			else if (doanhThuNam.isMouseHover(xclick,yclick)) {
				index = ID_DT_NAM; 
				return; 
			}
			else if (nhapNam.isMouseHover(xclick,yclick)) {
				nhapNam.NhapVao(kiTuSo,"Chi Nhap So!"); 
				// bac dieu kien ! 
				// sau khi nhap song kiem tra dieu xem co chinh xac khong 
				if (nhapNam.khongRong()) {  
					// kiem tra xem nam nhap vao co hop le hay khong !
					// kiem tra xem date co nam trong tuong lai hay khong ! 
					int intNam = TienichDoHoa::stringToInt(nhapNam.boNhoDem);  // lay ra nam theo int 
					if (!Date::hopLeNam(intNam)) {
						MessageBox(NULL, "Khong Hop Le Nam!", "Thong Bao", MB_ICONINFORMATION | MB_OK);
						nhapNam.resetBoNhoDem(); 
					}
					if (intNam > tempDate.nam) {
						MessageBox(NULL, "Thoi Gian Trong Tuong Lai!", "Thong Bao", MB_ICONINFORMATION | MB_OK);	
						nhapNam.resetBoNhoDem(); 
						// kiem tra xem nam co hop le hay khong 

					}
				}
				
			}
			else if (thongKeResult.isMouseHover(xclick,yclick)) { 
					// kiem tra ngay thang nam nhap chua 
					if (!nhapNam.khongRong()) {
						MessageBox(NULL, "Nhap Nam", "Thong Bao", MB_ICONINFORMATION | MB_OK);
					}
					else {
						// nam da phu hop 
						// can phai lay ra danh sach hoa don !
						int soLuongHoaDon = DSNV.soLuongHD(); 
						HoaDon** arrHoaDon = new HoaDon*[soLuongHoaDon]; 
						int index = 0; 
						DSNV.listToArrayHoaDon(arrHoaDon,index); 
						float doanhThuTheoThang[12] = {0};  // bao gom 12 phan tu dai dien 12 thang!
						int nam = TienichDoHoa::stringToInt(nhapNam.boNhoDem); // lay ra nam cua nguoi dung
						tinhDoanhThu(arrHoaDon,soLuongHoaDon,doanhThuTheoThang,nam); 
						// xoa di het man hinh va in ra ngay thang nam tuong ung 
						TienichDoHoa::xoaManHinhTheoToaDo(0, 96, DODAIMANHINH, 1000, BACKGROUP);
						// tiep tuc in ra 12 thang  
						string title = "BANG THONG KE DOANH THU NAM " + nhapNam.boNhoDem; 
						setcolor(15); 
						setbkcolor(0); 
						
						outtextxy(400,160,title.c_str()); 
						// in ra 1 1 cai bang bao gom 2 cot 
						
						int cachLe = margin + 60; 
	
						NutBam loaiHoaDon(cachLe + doDaiCoban * 3 + 3 * 3, canLeTrenHD + 120, doDaiCoban, 40, colorTieuDe, 7, conlorTextTieuDe, "THANG");
						NutBam hoTenNV(cachLe + doDaiCoban * 4 + 3 * 4, canLeTrenHD + 120, doDaiCoban, 40, colorTieuDe, 7, conlorTextTieuDe, "DOANH THU");

					
						loaiHoaDon.veNut(); 
						hoTenNV.veNut(); 
					
					
						OVuong table(cachLe + doDaiCoban*3 + 8, canLeTrenHD + 120, doDaiCoban * 2 + 18 - 15, 500, 15);
						setcolor(15);
						
						line(cachLe + doDaiCoban * 4 + 3 * 3, canLeTrenHD + 120, cachLe + doDaiCoban * 4 + 3 * 3, 690 + 50);
					
						// thuc hien vong lap va in ra 
						int khoanCach = 38; 
						string temp; 
						for (int i = 0; i < 12; i++) {
							setbkcolor(0); 
							setcolor(15); 
							line(cachLe +doDaiCoban*3 + 10,i*khoanCach + canLeTrenHD + 202,cachLe +doDaiCoban*3 + 320,i*khoanCach + canLeTrenHD + 202);
							outtextxy(cachLe +doDaiCoban*3 + 80,i*khoanCach + canLeTrenHD + 176,TienichDoHoa::intToString(i + 1).c_str()); 
							outtextxy(cachLe +doDaiCoban*3 + 180,i*khoanCach + canLeTrenHD + 176,TienichDoHoa::floatToString(doanhThuTheoThang[i]).c_str()); 
						}
						
					}
				}
			
		}
		delay(10); 
	}
	
}


void hienThiTinhNangDoanhThu(BstVatTu &dsVatTu,dsNhanVien &DSNV,int &index,NutBam &vatTu,NutBam &nhanVien,NutBam &hoaDon,NutBam &doanhThu) 
{
	TienichDoHoa::xoaManHinhTheoToaDo(0, 56, DODAIMANHINH, DORONGMANHINH, BACKGROUP);
	index = -1; 
	const int WMenuSub = 230;
	const int HMenuSub = 35;
	const int marginLeftSub = 56;
	const int marginTopSub = 62;
	NutBam thongKe(marginLeftSub, marginTopSub, WMenuSub, HMenuSub, COLOR_BTN_SUB, COLOR_HIGHT_BTN_SUB, COLOR_TEXT_BTN_SUB, "THONG KE");
	NutBam doanhThuNam(marginLeftSub + WMenuSub + 2, marginTopSub, WMenuSub, HMenuSub, COLOR_BTN_SUB, COLOR_HIGHT_BTN_SUB, COLOR_TEXT_BTN_SUB, "DOANH THU THEO NAM");

	
	
	
	thongKe.veNut(); 
	doanhThuNam.veNut(); 

	
	//tiep tuc ve 
	int xclick = -1 ; 
	int yclick = -1; 
	while (true) {
			if (index >= 0 && index <=3) {
				return; 
			}
			else if (index == ID_DT_NAM) {
				doanhThuNam.duocChon(); 
				thongKe.khongDuocChon(); 
				inDoanhThuNam(dsVatTu,DSNV,index,vatTu,nhanVien,hoaDon,doanhThu,thongKe,doanhThuNam); 
			}
			else if (index == ID_DT_THONG_KE) {
				thongKe.duocChon(); 
				doanhThuNam.khongDuocChon(); 
				inHoaDonTheoNgayThangNam(dsVatTu,DSNV,index,vatTu,nhanVien,hoaDon,doanhThu,thongKe,doanhThuNam );
			}
			 else if (ismouseclick(WM_LBUTTONDOWN))
			{
				getmouseclick(WM_LBUTTONDOWN, xclick, yclick);
				if (thongKe.isMouseHover(xclick,yclick))
				 {
				 	thongKe.duocChon(); 
				 	doanhThuNam.khongDuocChon(); 
					inHoaDonTheoNgayThangNam(dsVatTu,DSNV,index,vatTu,nhanVien,hoaDon,doanhThu,thongKe,doanhThuNam );
				}
				else if (doanhThuNam.isMouseHover(xclick,yclick)) {
					doanhThuNam.duocChon(); 
					thongKe.khongDuocChon(); 
					inDoanhThuNam(dsVatTu,DSNV,index,vatTu,nhanVien,hoaDon,doanhThu,thongKe,doanhThuNam); 
				}
				else if (vatTu.isMouseHover(xclick,yclick)) {
					index = ID_VT; 
					return; 
				}
				else if (nhanVien.isMouseHover(xclick,yclick)) {
					index = ID_NV; 
					return; 
				}
				else if (hoaDon.isMouseHover(xclick,yclick)) {
					index = ID_HD; 
					return; 
				}
				else if (doanhThu.isMouseHover(xclick,yclick)) { 
					index = ID_DT; 
					return; 
				}
			}
		delay(10);
	}
	
}