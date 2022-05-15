int hienThiDuLieuLenTableVT1(int x,int y,int colorBack,int indexPage,int soLuongPhanTuTrenMotPage,VatTu **arrVT, int soLuongVT)
{
	int index;
	int khoanCach = 46;

	string temp;
	int dem = 0;
	for (int i = 0; i < soLuongPhanTuTrenMotPage; i++)
	{
		TienichDoHoa::setText(colorBack,15,3,1); 
		if (i + indexPage * soLuongPhanTuTrenMotPage < soLuongVT)
		{
			index = i + indexPage * soLuongPhanTuTrenMotPage;
			temp = TienichDoHoa::floatToString(arrVT[index]->soLuongTon);
			outtextxy(x + 30, y  + khoanCach * i, arrVT[index]->maVT.c_str());	 // hien thi ra maVT
			outtextxy(x + 186, y + khoanCach * i, arrVT[index]->ten.c_str());	 // hien thi ra maVT
			outtextxy(x + 430, y + khoanCach * i, arrVT[index]->donVi.c_str()); // hien thi ra maVT
			outtextxy(x + 600, y + khoanCach * i, temp.c_str());				 // hien thi ra maVT
			line(x, y + khoanCach * i + 32, x + 723, y + khoanCach * i + 32);
			dem++;
		}
	}
	return dem;
}


void veTableVT1(int x,int y,int h,int colorBack)  // truyen vao cac mau sac cu the -> 
{
	int hightTitle = 40; 
//	TienichDoHoa::xoaManHinhTheoToaDo(0, 140, 900, 580, BACKGROUP);
	NutBam titleMaVT(x, y, doDaiCoBan, hightTitle, 12, 7, 0, "MA VT");
	NutBam titileTenVT(x + doDaiCoBan + 3, y , doDaiCoBan * 2 - 60, hightTitle, 12, 7, 0, "TEN");
	NutBam titiledonViVT(x + doDaiCoBan * 3 + 3 * 2 - 60, y , doDaiCoBan, hightTitle, 12, 7, 0, "DVT");
	NutBam titilesoLuongVT(x + doDaiCoBan * 4 + 3 * 3 - 60, y, doDaiCoBan, hightTitle, 12, 7, 0, "SO LUONG TON");
	
	titleMaVT.veNut();
	titilesoLuongVT.veNut();
	titileTenVT.veNut();
	titiledonViVT.veNut();

//	OVuong table(x, y, doDaiCoBan * 5 - 52, y + h, 15); // thay vi ve 1 o vuong ta ve ra 1 cai hinh chu nhat co nen
	NutBam mauNen(x,y + hightTitle,doDaiCoBan*5 - 52,h,colorBack,0,0,""); 
	mauNen.veNut(); 
	setcolor(15);
	line(x + doDaiCoBan, y + hightTitle, x + doDaiCoBan, y + h + hightTitle);
	line(x + doDaiCoBan * 3 + 3 - 60, y  + hightTitle, x + doDaiCoBan * 3 + 3 - 60, y + h + hightTitle);
	line(x + doDaiCoBan * 4 + 3 * 2 - 60, y + hightTitle, x + doDaiCoBan * 4 + 3 * 2 - 60, y + h + hightTitle);
}

// viet 1 ham nhan vao 2 doi so 
void hienThiDuLieuVatTu(int x,int y,int w,int colorBack,int indexPage,int numberShow,VatTu** arrVT,int soLuongVT ) {  // toa do cua cai bang 
	veTableVT1(x,y,w,colorBack);   // hieu chinh table 1 
	
	hienThiDuLieuLenTableVT1(x,y + 50,colorBack,indexPage,numberShow,arrVT,soLuongVT); 
	

	
	
}