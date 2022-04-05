#pragma once
using namespace std;
#include "Tienich.h"
#define NHANVIENTOIDA 500 


struct NhanVien {
    string maNV;  
    string ho;
    string ten;
    int phai;   // 0. nam 1. nu 
    ListHoaDon dsHoaDon; 

	NhanVien() {};
	NhanVien (string maNV,string ho,string ten,int phai):maNV(maNV),ho(ho),ten(ten),phai(phai) {};
	
	
	bool operator > (const struct NhanVien &other)
	{
		char thisFN[31] = "";
		char thisLN[31] = "";
		char otherFN[31] = "";
		char otherLN[31] = "";
	
		//chuyen ten -> xoa dau cach + viet thuong
		strcpy(thisFN, (char*)(this->ho.c_str()));
		delBlank(thisFN);
		for (int i = 0; i < strlen(thisFN); i++)
			thisFN[i] = tolower(thisFN[i]);
			
		strcpy(thisLN, (char*)(this->ten.c_str()));
		delBlank(thisLN);
		for (int i = 0; i < strlen(thisLN); i++)
			thisLN[i] = tolower(thisLN[i]);
			
		strcpy(otherFN, (char*)(other.ho.c_str()));
		delBlank(otherFN);
		for (int i = 0; i < strlen(otherFN); i++)
			otherFN[i] = tolower(otherFN[i]);
			
		strcpy(otherLN, (char*)(other.ten.c_str()));
		delBlank(otherLN);
		for (int i = 0; i < strlen(otherLN); i++)
			otherLN[i] = tolower(otherLN[i]);
		
		if (strcmp(thisFN, otherFN) > 0)
		{
			return true;
		}
		else if (strcmp(thisFN, otherFN) == 0)
		{
			if (strcmp(thisLN, otherLN) > 0)
			{
				return true;
			}
			else
				return false;
		}
		else 
			return false;
	}
	
	bool operator < (const struct NhanVien &other)
	{
		char thisFN[31] = "";
		char thisLN[31] = "";
		char otherFN[31] = "";
		char otherLN[31] = "";
	
		//chuyen ten -> xoa dau cach + viet thuong
		//chuyen ten -> xoa dau cach + viet thuong
			strcpy(thisFN, (char*)(this->ho.c_str()));
		delBlank(thisFN);
		for (int i = 0; i < strlen(thisFN); i++)
			thisFN[i] = tolower(thisFN[i]);
			
		strcpy(thisLN, (char*)(this->ten.c_str()));
		delBlank(thisLN);
		for (int i = 0; i < strlen(thisLN); i++)
			thisLN[i] = tolower(thisLN[i]);
			
		strcpy(otherFN, (char*)(other.ho.c_str()));
		delBlank(otherFN);
		for (int i = 0; i < strlen(otherFN); i++)
			otherFN[i] = tolower(otherFN[i]);
			
		strcpy(otherLN, (char*)(other.ten.c_str()));
		delBlank(otherLN);
		for (int i = 0; i < strlen(otherLN); i++)
			otherLN[i] = tolower(otherLN[i]);
		
		if (strcmp(thisFN, otherFN) < 0)
		{
			return true;
		}
		else if (strcmp(thisFN, otherFN) == 0)
		{
			if (strcmp(thisLN, otherLN) < 0)
			{
				return true;
			}
			else
				return false;
		}
		else 
			return false;
	}
	
};




class dsNhanVien {
private:
	int soLuong;  
    NhanVien *nv[NHANVIENTOIDA]; 
public:
	dsNhanVien()
	{
		soLuong = 0;
	}
	bool cayRong();
	bool cayDay();
	bool themNV(NhanVien info);
	void xuatNV();
	void xoaCay();
	NhanVien *timNVtheoMa(const string &maCanTim);
	int timNV(const string &pos);
	bool xoaNVtheoMa(const string &ma);
	void docFileNhanVien();
	void ghiFileNhanVien();
	bool chinhSuaNV(const string &maCanTim,const string &hoNV,const string &tenNV,const int &phaiNV);
};

	bool dsNhanVien::cayRong()
	{
		return (soLuong==0);
	}
	
	bool dsNhanVien::cayDay()
	{
		return (soLuong == NHANVIENTOIDA);
	}
	
	bool dsNhanVien::themNV( NhanVien info)		//push_back
	{
		NhanVien *NV=this->timNVtheoMa(info.maNV);
		if(NV==NULL)
		{
		nv[soLuong++] = &info;
		return true;
		}
		return false;
	}
	void dsNhanVien::xuatNV()
	{
		for(int i=0;i<this->soLuong;i++)
			{
				cout<< nv[i]->maNV<<" ";
				cout<<nv[i]->ho<<" ";
				cout<<nv[i]->ten<<" ";
				cout<<nv[i]->phai<<endl;
			}
	}

	NhanVien* dsNhanVien::timNVtheoMa(const string &maCanTim)
	{
		if(nv[0]!=NULL)
		{
		for(int i=0; i<soLuong ;i++)
		{
			if(maCanTim==nv[i]->maNV)
			{
				return nv[i];
			}	
		}
	}
		return NULL;
	}
	int dsNhanVien::timNV(const string &maCanTim)
	{
		if(nv[0]!=NULL)
		{
		for(int i=0; i<soLuong ;i++)
		{
			if(maCanTim==nv[i]->maNV)
			{
				return i;
			}	
		}
		return -1;
	}
}
	void dsNhanVien::xoaCay()
	{
		this->soLuong = 0;
	}
	bool dsNhanVien::xoaNVtheoMa(const string &maCanXoa)
	{
		int pos;
		pos=this->timNV(maCanXoa);
		NhanVien *NV;
		NV=this->timNVtheoMa(maCanXoa);
		if(NV!=NULL)
		{
			if(pos!=this->soLuong)
			{
			
			delete nv[pos];
			for(int j =pos;j<soLuong;j++)
			{
				nv[j]=nv[j+1];
			}
			soLuong--;
			return true;
			}
			else delete nv[pos];
		}
		else return false;
		delete NV;
	}
void dsNhanVien::docFileNhanVien()
{
	ifstream fileIn;
	fileIn.open("data/nhanVien.txt",ios::in);
	fileIn>>this->soLuong;
	cin.ignore();
	for(int i=0;i<this->soLuong;i++)
	{
		NhanVien tempNV;
		getline(fileIn,tempNV.maNV,',');
		getline(fileIn,tempNV.ho,',');
		getline(fileIn,tempNV.ten,',');
		fileIn>>tempNV.phai;
		fileIn.ignore();
		this->themNV(tempNV);				
	}
	fileIn.close();
}

void dsNhanVien::ghiFileNhanVien()
{
	ofstream fileOut;
	fileOut.open("data/nhanVien.txt",ios::out|ios::trunc);
		fileOut<<this->soLuong<<endl;
		cin.ignore();
	for(int i=0;i<this->soLuong;i++)
	{
		fileOut<<nv[i]->maNV<<","<<nv[i]->ho<<","
		<<nv[i]->ten<<","<<nv[i]->phai<<endl;
		
	}
	fileOut.close();
}
bool dsNhanVien::chinhSuaNV(const string &maCanTim,const string &hoNV,const string &tenNV,const int &phaiNV)
{
	int i;
	i=this->timNV(maCanTim);
	NhanVien *NV;
	NV=this->timNVtheoMa(maCanTim);
	if(NV!=NULL)
	{
		nv[i]->ho=hoNV;
		nv[i]->ten=tenNV;
		nv[i]->phai=phaiNV;
		return true;
	}
	return false;	
}
//	//check ID nhan vien, tra ve NULL neu k trung
//	NhanVien* timID(string maCanTim)
//	{
//		for (int i = 0; i < n; i++)
//		{
//			if (nv[i]->maNV == maCanTim)
//			{
//				return nv[i];
//			}
//		}
//		return NULL;
//	}
//	
//	//return false neu co ID trung
//	bool kiemTraIDTrongDS(char idBill[20])
//	{
//		for (int numE = 0; numE < n; numE++)
//		{
//			if (nodeListEmp[numE]->listBill.checkID(idBill) == false) // co ID trung
//				return false;
//		}
//		return true;
//	}
//	
//	// check ID bill
//	
//	
//	void dsNhanVien::themNV(char idEmp[11])
//	{
//		NhanVien* p = timID(idEmp);
//		p->dsNhanVien.insertFirst(newBill);
//	}
//	
//
//
//
//void sortEmp(struct Employee **arr, int left, int right)
//{
//	logs << "sort" << endl;
//	Employee *mid = arr[(left + right) / 2];
//	int i = left, j = right;
//	do
//	{
//		while(*arr[i] < *mid)
//			i++;
//		while(*arr[j] > *mid)
//			j--;
//		if(i <= j)
//		{
//			if(i < j)
//			{
//				Employee *tmp;
//				tmp = arr[i];
//				arr[i] = arr[j];
//				arr[j] = tmp;
//			}
//			i++; j--;
//		}
//	} while(i<=j);
//	if(left < j)
//		sortEmp(arr, left, j);
//	if(right > i)
//		sortEmp(arr, i, right);
//}
////=================================================
////================================================
//
//
////==========DANH-SACH-BILL-THEO-NGAY===============
//struct billDateNode
//{
//	struct Bills *info;
//	struct Employee *Emp;
//	struct billDateNode *next;
//};
//typedef struct billDateNode* NODE_BDate;
//
//
//struct listBillDate
//{
//	int Size;
//	NODE_BDate firstNode;
//	
//	listBillDate()
//	{
//		Size = 0;
//		firstNode = NULL;
//	}
//	
//	void insert(struct Bills &bill, struct Employee *Emp)
//	{
//		NODE_BDate newNode, before, after;
//		newNode = new billDateNode;
//		newNode->info = &bill;
//		newNode->Emp = Emp;
//		for (after = firstNode; 
//			after != NULL && after->info->date < newNode->info->date;
//			before = after, after = after->next);
//			
//		if (after == firstNode)
//		{
//			newNode->next = firstNode;
//			firstNode = newNode;
//		}
//		else
//		{
//			before->next = newNode;
//			newNode->next = after;
//		}
//		Size++;
//	}
//	
//	NODE_BDate index(int stt)
//	{
//		NODE_BDate newNode = firstNode;
//		for (int i = 0; i < stt; newNode = newNode->next, i++);
//		return newNode;
//	}
