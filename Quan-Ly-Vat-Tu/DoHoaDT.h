#pragma once
using namespace std;
#include "Tienich.h"
#include "BienDoHoa.h"
#include "DoanhThu.h"
#include  "DoHoaHD.h"

const int SO_LUONG_TOP_DOANH_THU_VT = 10;  // theo de !

// ham tra so phan tu se hien thi tren top 10 doanh thu vat tu. 

// logic ham chua dung
// neu nhu so phan tu khac 0 nhieu qua -> neu no bang khong -> no nam o cuoi mang  

int soVatTuHienThiTrenTableTop10DoanhThuVatTu(DoanhThuVatTu arrDTVT[]) {
	const int KHONG_CO_DOANH_THU = 0;  
	int soPhanTuTrungNhau = 0; 
	int doanhThuKhacKhong = 0; 
	// Dem so Luong Vat Tu co Doanh Thu Khac Khong
	for (int i = 0;i < SO_LUONG_TOP_DOANH_THU_VT;i++) 
	{
		if (arrDTVT[i].doanhThu != KHONG_CO_DOANH_THU) 
		{
			doanhThuKhacKhong++;
		}
	}
	// Dem so Luong Vat Tu Trung Doanh Thu
	for (int i = 0;i < doanhThuKhacKhong - 1;i++) { 
		if (arrDTVT[i].doanhThu == arrDTVT[i+1].doanhThu) {  
			soPhanTuTrungNhau++; 
		}
	}
	// tat ca vat tu deu khac khong va khong co phan tu nao trung nhau -> hien thi day du tu tren xuong duoi ! 
	if (doanhThuKhacKhong == SO_LUONG_TOP_DOANH_THU_VT && soPhanTuTrungNhau == 0) {  // tat ca doanh thu deu khac khong   
		return SO_LUONG_TOP_DOANH_THU_VT; 
	}
	
	
	// Co Doanh Thu Vat Tu Bang Khong
	if (doanhThuKhacKhong != SO_LUONG_TOP_DOANH_THU_VT) {
		// kiem tra xem bao nhieu doanh thu va di so sanh voi so luong trung 
		// vi du nhu co 4 phan tu khac khong va co 6 phan tu trung nhau 
		// tuc la co 2 phan tu trung nhau khac khong 
		// 10 - 6 + 2 -> 4 + 2 = 6 phan tu -> hien thi ra 6 phan tu 
		// tinh ra so luong vat tu khac khong  
		if (doanhThuKhacKhong == 0)  //  Khong Hien Thi Gi Ca 
		{
			return 0; 
		}
		int soLuongDoanhThuBangKhong = SO_LUONG_TOP_DOANH_THU_VT - doanhThuKhacKhong;
		return SO_LUONG_TOP_DOANH_THU_VT - soLuongDoanhThuBangKhong + soPhanTuTrungNhau; 
	}
	
}


// Viet Ham Ve Ra Table Hien Thi Nhan Doanh Thu Len  
void veTableDoanhThuVatTu() {
	TienichDoHoa::xoaManHinhTheoToaDo(margin, canLeTrenHD + 170, 1600, 400, BACKGROUP);
	int cachLe = margin + 60; 
	NutBam maVT(cachLe + doDaiCoBan , canLeTrenHD + 170, doDaiCoBan + 3 , 40, colorTieuDe, 7, conlorTextTieuDe, "MA VT");
	NutBam tenVT(cachLe + doDaiCoBan * 2 + 3 * 2, canLeTrenHD + 170, doDaiCoBan*2, 40, colorTieuDe, 7, conlorTextTieuDe, "TEN VAT TU");
	NutBam donViTinh(cachLe + doDaiCoBan * 4 + 3 * 3, canLeTrenHD + 170, doDaiCoBan, 40, colorTieuDe, 7, conlorTextTieuDe, "DON VI TINH");
	NutBam soLuongTon(cachLe + doDaiCoBan * 5 + 3 * 4, canLeTrenHD + 170, doDaiCoBan, 40, colorTieuDe, 7, conlorTextTieuDe, "SO LUONG TON");
	NutBam tongTienVT(cachLe + doDaiCoBan * 6 + 3 * 5, canLeTrenHD + 170, doDaiCoBan + 3, 40, colorTieuDe, 7, conlorTextTieuDe, "DOANH THU");
	
	maVT.veNut(); 
	tenVT.veNut(); 
	donViTinh.veNut(); 
	soLuongTon.veNut(); 
	tongTienVT.veNut(); 	

	OVuong table(cachLe + doDaiCoBan, canLeTrenHD + 170, doDaiCoBan * 6 + 18, 400, 15);
	setcolor(15);
	line(cachLe + doDaiCoBan * 2 + 3, canLeTrenHD + 170, cachLe + doDaiCoBan * 2 + 3, 690);
	line(cachLe + doDaiCoBan * 4 + 3 * 2, canLeTrenHD + 170, cachLe + doDaiCoBan * 4 + 3 * 2, 690);
	line(cachLe + doDaiCoBan * 5 + 3 * 3, canLeTrenHD + 170, cachLe + doDaiCoBan * 5 + 3 * 3, 690);
	line(cachLe + doDaiCoBan * 6 + 3 * 4, canLeTrenHD + 170, cachLe + doDaiCoBan * 6 + 3 * 4, 690);
	
	// thu goi toi ham -> 
	
	
}


// viet ham hien thi du lieu len table 
int hienThiDoanhThuVatTuLenTable(int indexPage,int soLuongHienThi,DoanhThuVatTu arrDTVT[],int soLuongDoanhThu) {
	int index;
	int dem = 0; 
	int khoanCach = 36; 
	int marginTop10 = 340; 
	
	string temp; 
	int cachLe = margin + 60; 
	for (int i = 0; i  < soLuongHienThi;i++) {
		TienichDoHoa::setText(BACKGROUP,10,10,1); 
		if (i + indexPage * soLuongHienThi  < soLuongDoanhThu  ) {
			index = i + indexPage * soLuongHienThi; 
			
			// in ra 
			
			line(cachLe + doDaiCoBan ,marginTop10 + khoanCach*i + 26,cachLe + doDaiCoBan + 948,marginTop10 + khoanCach*i + 26);
			outtextxy(cachLe + doDaiCoBan + 60,marginTop10 + khoanCach*i, arrDTVT[index].pVatTu->maVT.c_str() ); 
			outtextxy(cachLe + doDaiCoBan*2 + 30,marginTop10 + khoanCach*i, arrDTVT[index].pVatTu->ten.c_str() ); 
			outtextxy(cachLe + doDaiCoBan*4 + 30,marginTop10 + khoanCach*i, arrDTVT[index].pVatTu->donVi.c_str() );
			temp = TienichDoHoa::longLongToString((long long)arrDTVT[index].pVatTu->soLuongTon); 
			outtextxy(cachLe + doDaiCoBan*5 + 30,marginTop10 + khoanCach*i, temp.c_str() );
			temp = TienichDoHoa::longLongToString((long long)arrDTVT[i].doanhThu);
			outtextxy(cachLe + doDaiCoBan*6 + 30,marginTop10 + khoanCach*i, temp.c_str() );
			dem++; 
		}
	}
}

void hienThiTop10VatTu(DoanhThuVatTu arrDTVT[],Date start,Date end,int &index,NutBam &vatTu,NutBam &nhanVien,
	NutBam& hoaDon,NutBam &doanhThu,NutBam &close,NutBam &thongKeHD)
 {  // truyen vao 1 cai mang dap sap xep va viec cua ta la hien thi ra thoi 

	TienichDoHoa::xoaManHinhTheoToaDo(0, 96, DODAIMANHINH, 1000, BACKGROUP);
	TienichDoHoa::setText(BACKGROUP,14,10,1); 
	int soVatTuHienThi = soVatTuHienThiTrenTableTop10DoanhThuVatTu(arrDTVT); 
	// Kiem Tra Neu Nhu soVatTuHienThiLa0 -> thong bao voi nguoi dung luon 
	if ( soVatTuHienThi == 0) {
		TienichDoHoa::hienThiThongBao("Khong Ton Tai Doanh Thu!"); 
		// sau khi nguoi dung nhap vao oke => tra ket thuc ham nay 
		return; 
	}
	else 
	{
		// khai bao  
		int indexPage = 0; 
		TienichDoHoa::setText(BACKGROUP,14,10,1); 
		outtextxy(570,160,"Top 10 VAT TU CO DOANH THU CAO NHAT"); 
		string strStart = "Tu ngay :  " + start.getStringDate(); 
		string strEnd = "Den ngay :  " + end.getStringDate(); 
		outtextxy(360 + 30 + 50,200,strStart.c_str());
		outtextxy(750 + 30 +50,200,strEnd.c_str());
		// tiep tuc chay vong lap 
		int toiDaPage = TienichDoHoa::tinhToiDaPage(soVatTuHienThi,10); 
		// tiep theo ve ra table 
		veTableDoanhThuVatTu();  
		hienThiDoanhThuVatTuLenTable(0,10,arrDTVT,soVatTuHienThi); //  hien thi ra tab 0 
		NutBam btnTien(100 + 1100 - 50 - 20 - 6,720,100,40,15,0,0,">>"); 
		NutBam btnLui(100 + 100 + 50 + 20 + 6,720,100,40,15,0,0,"<<");
		btnTien.veNut(); 
		btnLui.veNut(); 
		hienThiChiMuc(730,720,indexPage,toiDaPage); 
	
		int xclick,yclick; 
		while(true) {
			if (ismouseclick(WM_LBUTTONDOWN))
			{
				getmouseclick(WM_LBUTTONDOWN, xclick, yclick);
				if (close.isMouseHover(xclick,yclick)) {
					index = ID_CLOSE; 
					return;
				}
				if (vatTu.isMouseHover(xclick,yclick)) {
					index = ID_VT; 
					return; 
				}
				if (nhanVien.isMouseHover(xclick,yclick)) {
					index = ID_NV; 
					return; 
				}
				if (hoaDon.isMouseHover(xclick,yclick)) {
					index = ID_HD;
					return; 
				}
				if (doanhThu.isMouseHover(xclick,yclick)) {
					index = ID_DT; 
					return; 
				}
				else if (thongKeHD.isMouseHover(xclick,yclick)) {
					index = ID_DT_THONG_KE; 
				}
				else if (btnTien.isMouseHover(xclick,yclick)) {
					if (index < toiDaPage - 1) {
						indexPage++; 
						veTableDoanhThuVatTu();  
						hienThiDoanhThuVatTuLenTable(0,10,arrDTVT,soVatTuHienThi); //  hien thi ra tab 0 
						hienThiChiMuc(730,720,indexPage,toiDaPage); 
					}
				}
				else if (btnLui.isMouseHover(xclick,yclick)) {
					if (index > 0) {
						index--; 
						veTableDoanhThuVatTu();  
						hienThiDoanhThuVatTuLenTable(0,10,arrDTVT,soVatTuHienThi); //  hien thi ra tab 0 
						hienThiChiMuc(730,720,indexPage,toiDaPage);
					}
				}
			}
			delay(10); 
		}
	
	}
	
	
	
	
	
	
	// tao nut thoat ra cho nguoi dung  
	
	// hien thi 10 vat tu sau khi duoc sap xep len
	

	
//	int khoanCach = 36; 
//	int marginTop10 = 340; 
//	
//	string temp; 
//	int cachLe = margin + 60; 
//	int dem = 0; 
//	
//	for (int i = 0; i < 10;i++) {
//		if (arrDTVT[i].doanhThu != 0 ) {  
//			setbkcolor(0); 
//			line(cachLe + doDaiCoBan ,marginTop10 + khoanCach*i + 26,cachLe + doDaiCoBan + 948,marginTop10 + khoanCach*i + 26);
//			outtextxy(cachLe + doDaiCoBan + 60,marginTop10 + khoanCach*i, arrDTVT[i].pVatTu->maVT.c_str() ); 
//			outtextxy(cachLe + doDaiCoBan*2 + 30,marginTop10 + khoanCach*i, arrDTVT[i].pVatTu->ten.c_str() ); 
//			outtextxy(cachLe + doDaiCoBan*4 + 30,marginTop10 + khoanCach*i, arrDTVT[i].pVatTu->donVi.c_str() );
//			temp = TienichDoHoa::longLongToString((long long)arrDTVT[i].pVatTu->soLuongTon); 
//			outtextxy(cachLe + doDaiCoBan*5 + 30,marginTop10 + khoanCach*i, temp.c_str() );
//			temp = TienichDoHoa::longLongToString((long long)arrDTVT[i].doanhThu);
//			outtextxy(cachLe + doDaiCoBan*6 + 30,marginTop10 + khoanCach*i, temp.c_str() );
//			dem++; 
//		}
//		
//		
//	}
//	if (dem == 0) {
//		MessageBox(NULL, "Thong Bao", "Doanh Thu Tat Ca Vat Tu Trong Thoi Gian Nay la 0!", MB_ICONINFORMATION | MB_OK);
//	}
//	else if (dem != 10) {
//		outtextxy(264, 720, "*Nhung vat tu con lai co doanh thu la 0");
//	}
	
	
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
		TienichDoHoa::setText(BACKGROUP,10,10,1); 
		if (i + indexPage * soLuongItemPage < soLuongHoaDon)
		{
			dem++;
			int index = i + indexPage * soLuongItemPage; 
			outtextxy(marginTable + doDaiCoBan + 50, marginTop + khoanCach * i, hoaDonHopLe[index]->soHD.c_str());
			outtextxy(marginTable + doDaiCoBan * 2 + 40, marginTop + khoanCach * i,hoaDonHopLe[index]->date.getStringDate().c_str());
			temp = hoaDonHopLe[index]->loai == "X" ? "Xuat" : "Nhap"; 
			outtextxy(marginTable + doDaiCoBan * 3 + 80, marginTop + khoanCach * i, temp.c_str());
			outtextxy(marginTable + doDaiCoBan * 4 + 60, marginTop + khoanCach * i, hoaDonHopLe[index]->tenNVLapHD.c_str());
			temp = TienichDoHoa::longLongToString((long long)hoaDonHopLe[index]->dsCTHD.tinhTongTien());
			outtextxy(marginTable + doDaiCoBan * 6 + 60, marginTop + khoanCach * i,temp.c_str() );
		}
	}
	return dem;

}

void veTableXemHDTheoDate()
{
	TienichDoHoa::xoaManHinhTheoToaDo(margin, canLeTrenHD + 170, 1600, 400, BACKGROUP);
	int cachLe = margin + 60; 
	NutBam soHD(cachLe + doDaiCoBan , canLeTrenHD + 170, doDaiCoBan + 3 , 40, colorTieuDe, 7, conlorTextTieuDe, "SO HOA DON");
	NutBam ngayLap(cachLe + doDaiCoBan * 2 + 3 * 2, canLeTrenHD + 170, doDaiCoBan, 40, colorTieuDe, 7, conlorTextTieuDe, "NGAY LAP");
	NutBam loaiHoaDon(cachLe + doDaiCoBan * 3 + 3 * 3, canLeTrenHD + 170, doDaiCoBan, 40, colorTieuDe, 7, conlorTextTieuDe, "LOAI HOA DON");
	NutBam hoTenNV(cachLe + doDaiCoBan * 4 + 3 * 4, canLeTrenHD + 170, doDaiCoBan*2, 40, colorTieuDe, 7, conlorTextTieuDe, "HO TEN NHAN VIEN LAP");
	NutBam titleVAT(cachLe + doDaiCoBan * 6 + 3 * 5, canLeTrenHD + 170, doDaiCoBan + 3, 40, colorTieuDe, 7, conlorTextTieuDe, "THANH TIEN");
	

	soHD.veNut(); 
	ngayLap.veNut(); 
	loaiHoaDon.veNut(); 
	hoTenNV.veNut(); 
	titleVAT.veNut(); 	

	OVuong table(cachLe + doDaiCoBan, canLeTrenHD + 170, doDaiCoBan * 6 + 18, 400, 15);
	setcolor(15);
	line(cachLe + doDaiCoBan * 2 + 3, canLeTrenHD + 170, cachLe + doDaiCoBan * 2 + 3, 690);
	line(cachLe + doDaiCoBan * 3 + 3 * 2, canLeTrenHD + 170, cachLe + doDaiCoBan * 3 + 3 * 2, 690);
	line(cachLe + doDaiCoBan * 4 + 3 * 3, canLeTrenHD + 170, cachLe + doDaiCoBan * 4 + 3 * 3, 690);
	line(cachLe + doDaiCoBan * 6 + 3 * 4, canLeTrenHD + 170, cachLe + doDaiCoBan * 6 + 3 * 4, 690);

}




// Co sap xep thoi gian  
void hienThiGiaoDienHoaDonTrongKhoanThoiGian (Date &start,Date &end,HoaDon** hoaDonHopLe,int soLuong,int &index
	,NutBam &vatTu,NutBam nhanVien,NutBam &hoaDon,NutBam &doanhThu,NutBam &close,NutBam &doanhThuNam
) 
{
	
	
	TienichDoHoa::xoaManHinhTheoToaDo(0, 96, DODAIMANHINH, 1000, BACKGROUP);
	
	// khi vào ham nay tuc la co hoa don moi vao 
	
	// hien thi lai code cho nay 1 ti -> nen sap xep theo ngay thang nam ch de nhon 
	
	int indexPage = 0; 
	int iTempTrenMotPage = 8; 
	setbkcolor(BACKGROUP); 
	setcolor(15); 
	settextstyle(6,0,3);
	outtextxy(330,160,"BANG LIET KE HOA DON TRONG KHOAN THOI GIAN"); 
	string strStart = "TU NGAY :  " + start.getStringDate(); 
	string strEnd = "DEN NGAY :  " + end.getStringDate(); 
	outtextxy(360 + 30,200,strStart.c_str());
	outtextxy(750 + 30,200,strEnd.c_str());
	
	// ve ra hai cai nut 
	NutBam btnLui(276,730,100,40,14,3,1,"<<"); 
	btnLui.veNut(); 
	
	NutBam btnTien(276 + 848,730,100,40,14,3,1,">>"); 
	btnTien.veNut(); 
	
	veTableXemHDTheoDate(); 
	float toiDaPage = TienichDoHoa::tinhToiDaPage(soLuong,iTempTrenMotPage); 
	int soLuongCTHDTrenTable = hienThiDuLieuLenTableXemHoaDonTheoDate(indexPage,iTempTrenMotPage,hoaDonHopLe,soLuong);

	
	hienThiChiMuc(DODAIMANHINH / 2 - 30,736,indexPage,toiDaPage); 

	int xclick = -1; 
	int yclick = -1; 
	
	while(true) {
		if (ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_LBUTTONDOWN, xclick, yclick);
			
			// bac su kien tien toi 
			if (close.isMouseHover(xclick,yclick)) {
				index = ID_CLOSE; 
				return;
			}
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

void inHoaDonTheoNgayThangNam(BstVatTu &dsVatTu,DsNhanVien &DSNV,int &index,NutBam &vatTu,NutBam &nhanVien,NutBam &hoaDon,NutBam &doanhThu,NutBam &close,NutBam &thongKe, NutBam &doanhThuNam ) {
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
	
	NutBam title(450,260,570,40,14,1,1,"THONG KE HOA DON && VAT TU"); 
	title.veNut(); 
	OVuong box (450,300,570,326,15); 
	
	NutBam thongKeHD(470,540,260,40,15,0,0,"THONG KE HOA DON");
	
	NutBam thongKeTop10VT(470 + 260 + 10,540,260,40,15,0,0,"TOP 10 VAT TU DOANH THU");  
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
		else if (index == ID_CLOSE) {
			return; 
		}
 		else if (ismouseclick(WM_LBUTTONDOWN))
			{

				getmouseclick(WM_LBUTTONDOWN, xclick, yclick);
				if (vatTu.isMouseHover(xclick,yclick)) {
					index = ID_VT; 
					return; 
				}
				else if (close.isMouseHover(xclick,yclick)) {
					index = ID_CLOSE; 
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
								TienichDoHoa::hienThiThongBao("dd/mm/yyyy Khong Hop Le!");
								nhapNgayBD.resetBoNhoDem();
							}
							else if (nhapThangBD.boNhoDem != "" && nhapNamBD.boNhoDem != "")
							{ 
								start.thang = TienichDoHoa::stringToInt(nhapThangBD.boNhoDem);
								start.nam = TienichDoHoa::stringToInt(nhapNamBD.boNhoDem);
								if (!Date::ngayThangNamHopLe(start))
								{
									TienichDoHoa::hienThiThongBao("dd/mm/yyyy Khong Hop Le!");
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
							MessageBox(NULL, "mm Khong Hop Le!", "Thong Bao", MB_ICONINFORMATION | MB_OK);
							nhapThangBD.resetBoNhoDem();
						}
						else if (nhapNgayBD.boNhoDem != "" && nhapNamBD.boNhoDem != "")
						{ 
							start.ngay = TienichDoHoa::stringToInt(nhapNgayBD.boNhoDem);
							start.nam = TienichDoHoa::stringToInt(nhapNamBD.boNhoDem);
							if (!Date::ngayThangNamHopLe(start))
							{
								TienichDoHoa::hienThiThongBao("dd/mm/yyyy Khong Hop Le!");
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
							TienichDoHoa::hienThiThongBao("dd/mm/yyyy Khong Hop Le!");
							nhapNamBD.resetBoNhoDem();
						}
						else if (nhapNgayBD.boNhoDem != "" && nhapThangBD.boNhoDem != "")
						{
							start.ngay = TienichDoHoa::stringToInt(nhapNgayBD.boNhoDem);
							start.thang = TienichDoHoa::stringToInt(nhapThangBD.boNhoDem);
							if (!Date::ngayThangNamHopLe(start))
							{
								TienichDoHoa::hienThiThongBao("dd/mm/yyyy Khong Hop Le!");
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
								if (!Date::ngayThangNamHopLe(end))
								{
									TienichDoHoa::hienThiThongBao("dd/mm/yyyy Khong Hop Le!");
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
							TienichDoHoa::hienThiThongBao("mm Khong Hop Le!");
							nhapThangKT.resetBoNhoDem();
						}
						else if (nhapNgayKT.boNhoDem != "" && nhapNamKT.boNhoDem != "")
						{ 
							end.ngay = TienichDoHoa::stringToInt(nhapNgayKT.boNhoDem);
							end.nam = TienichDoHoa::stringToInt(nhapNamKT.boNhoDem);
							if (!Date::ngayThangNamHopLe(end))
							{
								TienichDoHoa::hienThiThongBao("dd/mm/yyyy Khong Hop Le!");
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
							TienichDoHoa::hienThiThongBao("yyyy Khong Hop Le!");
							nhapNamKT.resetBoNhoDem();
						}
						else if (nhapNgayKT.boNhoDem != "" && nhapThangKT.boNhoDem != "")
						{
							end.ngay = TienichDoHoa::stringToInt(nhapNgayKT.boNhoDem);
							end.thang = TienichDoHoa::stringToInt(nhapThangKT.boNhoDem);
							if (!Date::ngayThangNamHopLe(end))
							{
								TienichDoHoa::hienThiThongBao("dd/mm/yyyy Khong Hop Le!");
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
					// sap xep tren nay 
					
					HoaDon** hoaDonHopLe = new HoaDon*[soLuongHoaDon]; // su dung it hon ! 
					int index = 0; // bien chi so mang 
					DSNV.listToArrayHoaDon(arrHoaDon,index); 
					ListHoaDon::sapXepHoaDonTheoNgay(arrHoaDon,soLuongHoaDon); 
					int soLuongHDHopLe = DSNV.hoaDonTheoDate(arrHoaDon,hoaDonHopLe,soLuongHoaDon,start,end); 
					
					if (soLuongHDHopLe == 0) 
					{
						TienichDoHoa::hienThiThongBao("Khong Ton Tai Hoa Don Trong Khoan Thoi Gian Nay!");
					}
					else  
					{ 
						hienThiGiaoDienHoaDonTrongKhoanThoiGian (start,end,hoaDonHopLe,soLuongHDHopLe,index,vatTu,nhanVien,hoaDon,doanhThu,close,doanhThuNam);   // da truyen vao ds hoa don hop le! 	
					}
					delete []arrHoaDon; 
				}
				else 
				{
					TienichDoHoa::hienThiThongBao("dd/mm/yyyy Khong Hop Le!");	
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
						DoanhThuVatTu *arrDTVT = new DoanhThuVatTu[dsVatTu.soLuongVT()]; 
						int index = 0; 
						DSNV.listToArrayHoaDon(arrHoaDon,index); 
						dsVatTu.BstVatTuToDoanhThuVatTu(arrDTVT,0);  
						tinhDoanhThuVatTuTheoDate(arrDTVT,soLuongVatTu,arrHoaDon,soLuongHoaDon,start,end);
						// kiem tra xemco doanh thu nao trung doanh thu nao khong 
						
						sapXepDoanhThuVatTu(arrDTVT,soLuongVatTu); 
						hienThiTop10VatTu(arrDTVT,start,end,index,vatTu,nhanVien,hoaDon,doanhThu,close,thongKeHD); 	
						delete []arrDTVT; 
						delete [] arrHoaDon;		
					}
					else 
					{
							TienichDoHoa::hienThiThongBao("dd/mm/yyyy Khong Hop Le!");
					}
					
				}
				}
			
					
				delay(10);
			
			}
		
	
}


void inDoanhThuNam(BstVatTu &dsVatTu,DsNhanVien &DSNV,int &index,NutBam &vatTu,NutBam &nhanVien,NutBam &hoaDon,

NutBam &doanhThu,NutBam &close,NutBam &thongKe,NutBam &doanhThuNam) {
	
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
			else if (close.isMouseHover(xclick,yclick)) {
				index  = ID_CLOSE; 
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
						tinhDoanhThu12Thang(arrHoaDon,soLuongHoaDon,doanhThuTheoThang,nam); 
						// xoa di het man hinh va in ra ngay thang nam tuong ung 
						TienichDoHoa::xoaManHinhTheoToaDo(0, 96, DODAIMANHINH, 1000, BACKGROUP);
						// tiep tuc in ra 12 thang  
						string title = "BANG THONG KE DOANH THU NAM " + nhapNam.boNhoDem; 
						setcolor(15); 
						setbkcolor(0); 
						
						outtextxy(580,160,title.c_str()); 
						// in ra 1 1 cai bang bao gom 2 cot 
						
						int cachLe = margin + 60; 
	
						NutBam loaiHoaDon(cachLe + doDaiCoBan * 3 + 3 * 3, canLeTrenHD + 120, doDaiCoBan, 40, colorTieuDe, 7, conlorTextTieuDe, "THANG");
						NutBam hoTenNV(cachLe + doDaiCoBan * 4 + 3 * 4, canLeTrenHD + 120, doDaiCoBan, 40, colorTieuDe, 7, conlorTextTieuDe, "DOANH THU");

					
						loaiHoaDon.veNut(); 
						hoTenNV.veNut(); 
					
					
						OVuong table(cachLe + doDaiCoBan*3 + 8, canLeTrenHD + 120, doDaiCoBan * 2 + 18 - 15, 500, 15);
						setcolor(15);
						
						line(cachLe + doDaiCoBan * 4 + 3 * 3, canLeTrenHD + 120, cachLe + doDaiCoBan * 4 + 3 * 3, 690 + 50);
					
						// thuc hien vong lap va in ra 
						int khoanCach = 38; 
						string temp; 
						for (int i = 0; i < 12; i++) {
							setbkcolor(0); 
							setcolor(15); 
							line(cachLe +doDaiCoBan*3 + 10,i*khoanCach + canLeTrenHD + 202,cachLe +doDaiCoBan*3 + 320,i*khoanCach + canLeTrenHD + 202);
							outtextxy(cachLe +doDaiCoBan*3 + 80,i*khoanCach + canLeTrenHD + 176,TienichDoHoa::intToString(i + 1).c_str()); 
							outtextxy(cachLe +doDaiCoBan*3 + 180,i*khoanCach + canLeTrenHD + 176,TienichDoHoa::longLongToString((long long)doanhThuTheoThang[i]).c_str()); 
						}
					}
				}
			
		}
		delay(10); 
	}
	
}


void hienThiTinhNangDoanhThu(BstVatTu &dsVatTu,DsNhanVien &DSNV,int &index,NutBam &vatTu,NutBam &nhanVien,NutBam &hoaDon,NutBam &doanhThu,NutBam &close) 
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
			else if(index == ID_CLOSE) {
				return; 
			}
			else if (index == ID_DT_NAM) {
				doanhThuNam.duocChon(); 
				thongKe.khongDuocChon(); 
				inDoanhThuNam(dsVatTu,DSNV,index,vatTu,nhanVien,hoaDon,doanhThu,close,thongKe,doanhThuNam); 
			}
			else if (index == ID_DT_THONG_KE) {
				thongKe.duocChon(); 
				doanhThuNam.khongDuocChon(); 
				inHoaDonTheoNgayThangNam(dsVatTu,DSNV,index,vatTu,nhanVien,hoaDon,doanhThu,close,thongKe,doanhThuNam );
			}
			 else if (ismouseclick(WM_LBUTTONDOWN))
			{
				getmouseclick(WM_LBUTTONDOWN, xclick, yclick);
				if (thongKe.isMouseHover(xclick,yclick))
				 {
				 	thongKe.duocChon(); 
				 	doanhThuNam.khongDuocChon(); 
					inHoaDonTheoNgayThangNam(dsVatTu,DSNV,index,vatTu,nhanVien,hoaDon,doanhThu,close,thongKe,doanhThuNam );
				}
				else if (doanhThuNam.isMouseHover(xclick,yclick)) {
					doanhThuNam.duocChon(); 
					thongKe.khongDuocChon(); 
					inDoanhThuNam(dsVatTu,DSNV,index,vatTu,nhanVien,hoaDon,doanhThu,close,thongKe,doanhThuNam); 
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
				else if (close.isMouseHover(xclick,yclick)) {
					index = ID_CLOSE; 
					return; 
				}
			}
		delay(10);
	}
	
}
