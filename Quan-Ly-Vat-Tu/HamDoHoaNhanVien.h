#pragma once
void veTableNV1(int x,int y,int h) {
	TienichDoHoa::xoaManHinhTheoToaDo(x - 2, y , doDaiCoBan * 6 + 18 - 120 , h, BACKGROUP);  // xoa di bat cu cai gi neu nhu de cai bang len 
	
	NutBam titleMaNV(x, y, doDaiCoBan, 40, colorTieuDe, 7, conlorTextTieuDe, "MA NHAN VIEN");
	NutBam titileTenNV(x + doDaiCoBan + 3, y, doDaiCoBan * 3 - 60 + 4, 40, colorTieuDe, 7, conlorTextTieuDe, "HO VA TEN");
	NutBam titileGioiTinh(x + doDaiCoBan * 4 + 3 * 3 - 60, y , doDaiCoBan, 40, colorTieuDe, 7, conlorTextTieuDe, "GIOI TINH");
	//NutBam titileHieuChinh(x + doDaiCoBan * 5 + 3 * 4 - 60, y , doDaiCoBan + 6 - 60, 40, colorTieuDe, 7, conlorTextTieuDe, "SUA");
	titleMaNV.veNut();
	titileTenNV.veNut();
	titileGioiTinh.veNut();
//	titileHieuChinh.veNut();
	// ve ra mau mau cai bang   
	
	OVuong table(x, y, 724, h, 15);
	setcolor(15);
	line(x + doDaiCoBan, y + 40, x + doDaiCoBan, y + h);
	line(x + doDaiCoBan * 4 + 3 * 2 - 60, y + 40, x + doDaiCoBan * 4 + 3 * 2 - 60, y + h);
	//line(x + doDaiCoBan * 5 + 3 * 3 - 60, y + 40, x + doDaiCoBan * 5 + 3 * 3 - 60, y + h);
}


int hienThiDuLieuLenTableNV1(int x,int y,int indexPage, int soLuongPhanTuTrenMotPage, DsNhanVien &DSNV)
{
	int index;
	int khoanCach = 46;
	int marginTop = y + 50; 
	int soLuongNV = DSNV.soLuongNV();
	string temp;
	int dem = 0;
	NhanVien **arrNV = DSNV.getDSNV();
	for (int i = 0; i < soLuongPhanTuTrenMotPage; i++)
	{
		TienichDoHoa::setText(BACKGROUP,10,10,1);
		if (i + indexPage * soLuongPhanTuTrenMotPage < soLuongNV)
		{
			index = i + indexPage * soLuongPhanTuTrenMotPage;
			outtextxy(x+ 30, marginTop + khoanCach * i, arrNV[index]->maNV.c_str());		  // hien thi ra maVT
			outtextxy(x + 186, marginTop + khoanCach * i, arrNV[index]->getHoTen().c_str()); // hien thi ra maVT
			// kiem tra xem la 0 hay 1
			if (arrNV[index]->phai == 0)
			{
				temp = "Nam";
			}
			else
			{
				temp = "Nu";
			}
			outtextxy(x + 600, marginTop + khoanCach * i, temp.c_str()); // hien thi ra maVT
			setcolor(15); 
			line(x, marginTop + khoanCach * i + 32, x + 724, marginTop + khoanCach * i + 32);
			dem++;
		}
	}
	return dem;
}


int hienThiDuLieuNhanVien(int x,int y,int h,int indexPage,int numberShow,DsNhanVien &DSNV) {
	
	veTableNV1(x,y,h); 


	return hienThiDuLieuLenTableNV1(x,y,indexPage,numberShow,DSNV); 

	
}
	
