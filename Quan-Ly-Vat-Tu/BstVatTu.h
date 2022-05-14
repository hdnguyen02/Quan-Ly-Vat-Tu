#pragma once
#include "Tienich.h"
using namespace std;

// ================================== CAU TRUC VAT TU ==================================
struct VatTu
{
	// THUOC TINH
	string maVT;
	string ten;
	string donVi;
	float soLuongTon;
	int soLanTaoCTHD; // SO LAN TAO CHI TIET HOA DON CUA VAT TU
	
	// PHUONG THUC 
	
	VatTu(){};
	VatTu(string maVT, string ten, string donVi, float soLuongTon, int soLanTaoCTHD) : 
	maVT(maVT), ten(ten), donVi(donVi), soLuongTon(soLuongTon), soLanTaoCTHD(soLanTaoCTHD){};
	void inVatTu();
	bool kiemTraDuHang(float soLuongHangCanXuat); // ham kiem tra so luong xem co du de xuat kho
	void capNhapSoLuongTon(string loaiHD, float soLuongCapNhap);
	
	// STATIC METHOD
	static bool soSanhTheoTen(VatTu *vt1, VatTu *vt2)
	{
		return vt1->ten > vt2->ten;
	}

	static bool soSanhTheoMaVT(VatTu *vt1, VatTu *vt2)
	{
		return vt1->maVT > vt2->maVT;
	}

	static bool soSanhTheoSoLuongTon(VatTu *vt1, VatTu *vt2)
	{
		return vt1->soLuongTon > vt2->soLuongTon;
	}

	static bool soSanhTheoDonViTinh(VatTu *vt1, VatTu *vt2)
	{
		return vt1->donVi > vt2->donVi;
	}

	// viet ham hoan Doi dia Chi
	static void hoanDoiDiaChiVatTu(VatTu *&vt1, VatTu *&vt2)
	{
		VatTu *tempVT = vt1;
		vt1 = vt2;
		vt2 = tempVT;
	}
};

bool VatTu::kiemTraDuHang(float soLuongHangCanXuat)
	{
		if (soLuongHangCanXuat > soLuongTon)
		{
			return false;
		}
		return true;
	}
	
void VatTu::capNhapSoLuongTon(string loaiHD, float soLuongCapNhap)
{
	if (loaiHD == "X")
	{
		this->soLuongTon = this->soLuongTon - soLuongCapNhap;
	}
	else if (loaiHD == "N")
	{
		this->soLuongTon = this->soLuongTon + soLuongCapNhap;
	}
}



void VatTu::inVatTu()
{
	cout << this->maVT << "  " << this->ten << "  " << this->donVi << "  " << this->soLuongTon << " " << this->soLanTaoCTHD;
}


struct DoanhThuVatTu {
	VatTu* pVatTu;    // CONT TRO CHAU THONG TIN CUA VAT TU DANG TRO DEN
	float doanhThu;   // DOANH THU CUA VAT TU DO : LAM TRONG CAU 3 CAU CUOI
}; 



class NodeVatTu
{
private:
	VatTu info;
	NodeVatTu *pLeft;
	NodeVatTu *pRight;
public:
	friend class BstVatTu;
	NodeVatTu() : pLeft(NULL), pRight(NULL){};
	NodeVatTu(string maVT, string ten, string donVi, float soLuongTon, bool daThemCTHD) 
	: info(maVT, ten, donVi, soLuongTon, daThemCTHD),pLeft(NULL), pRight(NULL) {}
	VatTu *getInfo() { return &info; }
	
};


// ==================================== BST VAT TU ====================================
class BstVatTu
{
private:
	NodeVatTu *root;
	int soLuong;

public:
	// HAM KHOI TAO, HAM HUY
	BstVatTu() : root(NULL), soLuong(0) { this->docVatTuFile(); };
	~BstVatTu() { this->giaiPhongVT(root); };
	// HAM CHUC NANG
	void hoTroThemVT(NodeVatTu *root, string maVT, string ten, string donVi, float soLuongTon, int soLanTaoCTHD);
	bool themVT(string maVT, string ten, string donVi, float soLuongTon, int soLanTaoCTHD);
	void duyetCay();
	void hoTroDuyetCay(NodeVatTu *root);
	void giaiPhongVT(NodeVatTu *root);
	NodeVatTu *timKiemVT(const string &key);
	bool xoaVT(const string &key);
	bool dieuChinhVT(const string &key, const string &tenVT, const string &donViVT);
	bool isNULL();
	int soLuongVT();
	void hoTroBstVatTuToArray(VatTu **arrVT, int &index, NodeVatTu *root);
	void BstVatTuToArray(VatTu **arrVT, int index);

	void sapXepTangDanTheoTen(NodeVatTu **arrVT);											//  ham nay chi dang sap xep tang dan theo ten ma thoi !
	void insertionSort(VatTu **arrVT, int soLuongVT, bool (*khoaSoSanh)(VatTu *, VatTu *)); // ham sap xep ( theo truong )
	// XU LY FILE
	void ghiVatTuFile();
	void docVatTuFile();
	void hoTroGhiVatTuFile(NodeVatTu *root, ofstream &fileout);
	
	
	// viet 1 ham do het tat ca vat tu vao trong 1 mang con tro 
	void hoTroBstVatTuToDoanhThuVatTu(DoanhThuVatTu arrDoanhThuVatTu[],int &index,NodeVatTu* root);
	
	void BstVatTuToDoanhThuVatTu(DoanhThuVatTu arrDoanhThuVatTu[],int index);
};

void BstVatTu::hoTroBstVatTuToDoanhThuVatTu(DoanhThuVatTu arrDoanhThuVatTu[],int &index,NodeVatTu* root) 
{   
		if (root != NULL) 
		{
			hoTroBstVatTuToDoanhThuVatTu(arrDoanhThuVatTu,index,root->pLeft);
			arrDoanhThuVatTu[index++].pVatTu = root->getInfo(); 
			hoTroBstVatTuToDoanhThuVatTu(arrDoanhThuVatTu,index,root->pRight); 
		}
}
	
void BstVatTu::BstVatTuToDoanhThuVatTu(DoanhThuVatTu arrDoanhThuVatTu[],int index) 
{
	hoTroBstVatTuToDoanhThuVatTu(arrDoanhThuVatTu,index,root);
} 

void BstVatTu::insertionSort(VatTu **arrVT, int soLuongVT, bool (*khoaSoSanh)(VatTu *, VatTu *))
{ 
	int i, j;
	VatTu *key;
	for (i = 1; i < soLuongVT; i++)
	{
		key = arrVT[i];
		j = i - 1;
		while (j >= 0 && khoaSoSanh(arrVT[j], key))
		{
			arrVT[j + 1] = arrVT[j];
			j = j - 1;
		}
		arrVT[j + 1] = key;
	}
}

int BstVatTu::soLuongVT()
{
	return this->soLuong;
}



void BstVatTu::hoTroBstVatTuToArray(VatTu **arrVT, int &index, NodeVatTu *root)
{ 
	if (root != NULL)
	{
		hoTroBstVatTuToArray(arrVT, index, root->pLeft);
		arrVT[index++] = root->getInfo(); // chi lay dia chi phan info.
		hoTroBstVatTuToArray(arrVT, index, root->pRight);
	}
}

void BstVatTu::BstVatTuToArray(VatTu **arrVT, int index)
{
	hoTroBstVatTuToArray(arrVT, index, root);
}

// return ve true neu dieu chinh thanh cong va false neu dieu chinh that bai ( vi key khong ton tai )
bool BstVatTu::dieuChinhVT(const string &key, const string &tenVT, const string &donViVT)
{
	NodeVatTu *nodeHieuChinh = timKiemVT(key);
	if (nodeHieuChinh == NULL)
	{
		return false;
	}
	nodeHieuChinh->info.ten = tenVT;
	nodeHieuChinh->info.donVi = donViVT;
	this->ghiVatTuFile();
	return true;
}

bool BstVatTu::xoaVT(const string &key)
{
	NodeVatTu *nodeDelete = root;
	NodeVatTu *previousNodeDelete = NULL; // tro truoc vi tri node can xoa.
	while (nodeDelete != NULL && nodeDelete->info.maVT != key)
	{
		previousNodeDelete = nodeDelete;
		if (key < nodeDelete->info.maVT)
		{
			nodeDelete = nodeDelete->pLeft;
		}
		else
		{
			nodeDelete = nodeDelete->pRight;
		}
	}
	if (nodeDelete == NULL)
	{ 
		return false;
	}
	if (nodeDelete->pLeft == NULL || nodeDelete->pRight == NULL)
	{ // truong hop node co 1 con hoac node la
		NodeVatTu *pTempDelete;
		if (nodeDelete->pLeft == NULL)
		{
			pTempDelete = nodeDelete->pRight; // truong hop cay co 1 con va node con do la node right
		}
		else
		{
			pTempDelete = nodeDelete->pLeft; // truong hop cay co 1 con va node con do la node left
		}

		if (previousNodeDelete == NULL)
		{
			delete root;
			root = pTempDelete;
			this->soLuong--;
			this->ghiVatTuFile();
			return true;
		}
		if (previousNodeDelete->pLeft == nodeDelete)
		{ // node can xoa nam o phia ben tay phai so voi node do./
			previousNodeDelete->pLeft = pTempDelete;
		}
		else
		{
			previousNodeDelete->pRight = pTempDelete;
		}
		delete nodeDelete;
	}
	else
	{
		NodeVatTu *parentNodeMin = NULL;
		NodeVatTu *nodeMin = nodeDelete->pRight;
		while (nodeMin->pLeft != NULL)
		{ // tim thang nho nhat ( va thang do la node cuoi cung phia ben tay phai
			parentNodeMin = nodeMin;
			nodeMin = nodeMin->pLeft;
		}
		if (parentNodeMin != NULL)
		{ // sau khi tim ra duoc node min nhat phia ben tay phai cua node can xoa.
			parentNodeMin->pLeft = nodeMin->pRight;
		}
		else
		{
			// truong hop : truong hop node the mang chinh la node trai cua node can xoa
			nodeDelete->pRight = nodeMin->pRight;
			// truong hop nay co nghia la : node parentNodeMin dang la NULL
			// tuc la cai node can xoa chinh la cai node ben phia duoi no luon
			// luc nay ta chi can cho tk node dang can xoa tro den thang node phia ben
			// phai cua node hau de sau ( vi phia ben tay trai dang NULL -> nen moi dung vong lap
		}
		nodeDelete->info = nodeMin->info; // coppy info.
		delete nodeMin;
	}
	this->soLuong--;
	return true;
}

bool BstVatTu::themVT(string maVT, string ten, string donVi, float soLuongTon, int soLanTaoCTHD)
{
	if (this->timKiemVT(maVT) != NULL)
	{ 
		return false;
	}
	if (root == NULL)
	{
		root = new NodeVatTu(maVT, ten, donVi, soLuongTon, soLanTaoCTHD);
	}
	else
	{
		hoTroThemVT(root, maVT, ten, donVi, soLuongTon, soLanTaoCTHD);
	}
	this->soLuong++;
	return true;
}

void BstVatTu::hoTroThemVT(NodeVatTu *root, string maVT, string ten, string donVi, float soLuongTon, int soLanTaoCTHD)
{
	if (maVT < root->info.maVT)
	{
		if (root->pLeft == NULL)
		{
			root->pLeft = new NodeVatTu(maVT, ten, donVi, soLuongTon, soLanTaoCTHD);
		}
		else
		{
			hoTroThemVT(root->pLeft, maVT, ten, donVi, soLuongTon, soLanTaoCTHD);
		}
	}
	else
	{
		if (root->pRight == NULL)
		{
			root->pRight = new NodeVatTu(maVT, ten, donVi, soLuongTon, soLanTaoCTHD);
		}
		else
		{
			hoTroThemVT(root->pRight, maVT, ten, donVi, soLuongTon, soLanTaoCTHD);
		}
	}
}

void BstVatTu::duyetCay()
{
	hoTroDuyetCay(root);
}

void BstVatTu::hoTroDuyetCay(NodeVatTu *root)
{
	if (root == NULL)
	{
		return;
	}
	hoTroDuyetCay(root->pLeft);
	root->info.inVatTu();
	cout << endl;
	hoTroDuyetCay(root->pRight);
}
void BstVatTu::giaiPhongVT(NodeVatTu *root)
{
	if (root == NULL)
	{
		return;
	}
	giaiPhongVT(root->pLeft);
	giaiPhongVT(root->pRight);
	delete root;
}

NodeVatTu *BstVatTu::timKiemVT(const string &key)
{
	NodeVatTu *temp = root;
	while (temp != NULL && temp->info.maVT != key)
	{
		if (key < temp->info.maVT)
		{
			temp = temp->pLeft;
		}
		else
		{
			temp = temp->pRight;
		}
	}
	if (temp == NULL)
	{
		return NULL;
	}
	return temp;
}

bool BstVatTu::isNULL()
{
	if (root == NULL)
	{
		return true;
	}
	return false;
}
void BstVatTu::hoTroGhiVatTuFile(NodeVatTu *root, ofstream &fileout)
{
	if (root != NULL)
	{
		fileout << root->info.maVT << "," << root->info.ten << "," << root->info.donVi << "," << root->info.soLuongTon << "," << root->info.soLanTaoCTHD << endl;
		hoTroGhiVatTuFile(root->pLeft, fileout);
		hoTroGhiVatTuFile(root->pRight, fileout);
	}
}

void BstVatTu::ghiVatTuFile()
{ // mo file ra va ghi du lieu vao.
	ofstream fileout;
	fileout.open("data/dataVatTu.txt", ios::out | ios::trunc); // chi ghi file vao va xoa du lieu cu di.
	fileout << this->soLuong << endl;
	hoTroGhiVatTuFile(root, fileout);
	fileout.close();
}

// =================================== DOC VAT TU ( DOC TU FILE ) ===================================
void BstVatTu::docVatTuFile()
{
	int soLuongVT;
	ifstream filein;
	filein.open("data/dataVatTu.txt", ios::in);
	string maVT, ten, donVi;
	float soLuongTon;
	string tempSoLuongTon;
	int soLanTaoCTHD;
	filein >> soLuongVT; // quy uoc 1 true
	filein.ignore();
	for (int i = 0; i < soLuongVT; i++)
	{
		getline(filein, maVT, ',');
		getline(filein, ten, ',');
		getline(filein, donVi, ',');
		getline(filein, tempSoLuongTon, ',');
		filein >> soLanTaoCTHD;
		filein.ignore();
		soLuongTon = TienichDoHoa::stringToFloat(tempSoLuongTon);
		this->themVT(maVT, ten, donVi, soLuongTon, soLanTaoCTHD);
	}
	filein.close();
}

// tao ra kieu struct moi -> thu thap toan bo 



