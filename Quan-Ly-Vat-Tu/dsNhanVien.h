#pragma once
#include "autoLoad.h"
using namespace std;

const int NHANVIENTOIDA = 500;  // n 


struct NhanVien {
    string id;  // maNV
    string ho;
    string ten;
    int phai;   // 0. nam 1. nu 

//    NhanVien()
//	{
//		id = '\0';
//		ho = '\0';
//		ten= '\0';
//		phai = 1;
//	}
//	
//	bool operator > (const struct NhanVien &other)
//	{
//		char thisFN[31] = "";
//		char thisLN[31] = "";
//		char otherFN[31] = "";
//		char otherLN[31] = "";
//	
//		//chuyen ten -> xoa dau cach + viet thuong
//		strcpy(thisFN, &this->ho[0]);
//		delBlank(thisFN);
//		for (int i = 0; i < strlen(thisFN); i++)
//			thisFN[i] = tolower(thisFN[i]);
//			
//		strcpy(thisLN, &this->lastName[0]);
//		delBlank(thisLN);
//		for (int i = 0; i < strlen(thisLN); i++)
//			thisLN[i] = tolower(thisLN[i]);
//			
//		strcpy(otherFN, &other.ho[0]);
//		delBlank(otherFN);
//		for (int i = 0; i < strlen(otherFN); i++)
//			otherFN[i] = tolower(otherFN[i]);
//			
//		strcpy(otherLN, &other.ten[0]);
//		delBlank(otherLN);
//		for (int i = 0; i < strlen(otherLN); i++)
//			otherLN[i] = tolower(otherLN[i]);
//		
//		if (strcmp(thisFN, otherFN) > 0)
//		{
//			return true;
//		}
//		else if (strcmp(thisFN, otherFN) == 0)
//		{
//			if (strcmp(thisLN, otherLN) > 0)
//			{
//				return true;
//			}
//			else
//				return false;
//		}
//		else 
//			return false;
//	}
//	
//	bool operator < (const struct NhanVien &other)
//	{
//		char thisFN[31] = "";
//		char thisLN[31] = "";
//		char otherFN[31] = "";
//		char otherLN[31] = "";
//	
//		//chuyen ten -> xoa dau cach + viet thuong
//		//chuyen ten -> xoa dau cach + viet thuong
//		strcpy(thisFN, &this->ho[0]);
//		delBlank(thisFN);
//		for (int i = 0; i < strlen(thisFN); i++)
//			thisFN[i] = tolower(thisFN[i]);
//			
//		strcpy(thisLN, &this->lastName[0]);
//		delBlank(thisLN);
//		for (int i = 0; i < strlen(thisLN); i++)
//			thisLN[i] = tolower(thisLN[i]);
//			
//		strcpy(otherFN, &other.ho[0]);
//		delBlank(otherFN);
//		for (int i = 0; i < strlen(otherFN); i++)
//			otherFN[i] = tolower(otherFN[i]);
//			
//		strcpy(otherLN, &other.ten[0]);
//		delBlank(otherLN);
//		for (int i = 0; i < strlen(otherLN); i++)
//			otherLN[i] = tolower(otherLN[i]);
//		
//		if (strcmp(thisFN, otherFN) < 0)
//		{
//			return true;
//		}
//		else if (strcmp(thisFN, otherFN) == 0)
//		{
//			if (strcmp(thisLN, otherLN) < 0)
//			{
//				return true;
//			}
//			else
//				return false;
//		}
//		else 
//			return false;
//	}
//	
//};
////============CAU-TRUC-NGAY==================
//
//struct Dates
//{
//	int day;
//	int month;
//	int year;
//	
//	Dates()
//	{
//		day = 1;
//		month = 1;
//		year = 1;
//	}
//	bool isValid()
//	{
//		if(month<1 || month>12 || year<0 || day<0 || day>31)
//		{
//			return false;
//		}
//		
//		if (month==2 || month==4 || month==6 || month==9 || month == 11)
//		{
//			if (day > 30)
//				return false;
//			if (month == 2)
//			{
//				if ((year%4 == 0 && year%100 != 0) || year%400 == 0)
//				{
//					if (day > 29)
//						return false;
//				}
//				else
//				{
//					if (day > 28)
//						return false;
//				}
//			}
//		}
//		return true;
//	}
//	
//	bool operator > (const struct Dates &other)
//	{
//		if (this->year > other.year)
//			return true;
//		else if (this->year == other.year) 
//		{
//			if(this->month > other.month)
//				return true;
//			else if (this->month == other.month)
//			{
//				if (this->day > other.day)
//					return true;
//			}
//		}
//		
//		return false;
//	}
//	
//	bool operator < (const struct Dates &other)
//	{
//		if (this->year < other.year)
//			return true;
//		else if (this->year == other.year) 
//		{
//			if(this->month < other.month)
//				return true;
//			else if (this->month == other.month)
//			{
//				if (this->day < other.day)
//					return true;
//			}
//		}
//		
//		return false;
//	}
//	
//	bool operator == (const struct Dates &other)
//	{
//		if (this->year == other.year)
//			if (this->month == other.month)
//				if (this->day == other.day)
//					return true;
//		return false;
//	}
//};
////============CAU-TRUC-NGAY==================
//
//
//
//class dsNhanVien {
//private:
//	int n;  // so luong thuc te. 
//    NhanVien *nv[NHANVIENTOIDA];  // 
//public:
//	listEmp()
//	{
//		n = 0;
//	}
//	bool isEmpty();
//	bool isFull();
//	void Insert(struct NhanVien *newNode);
//	void Detele(int pos);
//	void DeteleID(char tmpID[11]);
//	void Clear();
//	NhanVien* Search_ID(char tmpID[11]);
//};
//
//	
//	bool isEmpty()
//	{
//		return (n==0);
//	}
//	
//	bool isFull()
//	{
//		return (n == NHANVIENTOIDA);
//	}
//	
//	void Insert(struct NhanVien *newNode)		//push_back
//	{
//		nv[n++] = newNode;
//	}
//	
//	void Detele(int pos)
//	{
//		delete nv[pos];
//		for (int j = pos+1; j < n; j++)
//		{
//			nv[j-1] = nv[j];
//		}
//		n--;
//	}
//	
//	void DeteleID(char tmpID[11])
//	{
//		for (int i = 0; i < n; i++)
//		{
//			if (strcmp(nv[i]->ID, tmpID) == 0)
//			{
//				this->Detele(i);
//				break;
//			}
//		}
//	}
//	
//	void Clear()
//	{
//		n = 0;
//	}
//	
//	int Search_info(struct NhanVien *info)
//	{
//		for (int i = 0; i < n; i++)
//		{
//			if (strcmp(nv[i]->ID, info->ID) == 0)
//			{
//				return i;
//			}
//		}
//		return -1;
//	}
//	
//	//check ID nhan vien, tra ve NULL neu k trung
//	struct NhanVien* Search_ID(char tmpID[11])
//	{
//		for (int i = 0; i < n; i++)
//		{
//			if (strcmp(nodeListEmp[i]->ID, tmpID) == 0)
//			{
//				return nodeListEmp[i];
//			}
//		}
//		return NULL;
//	}
//	
//	//return false neu co ID trung
//	bool checkIDBill(char idBill[20])
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
//	Employee *FindEmp(char IDBill[20])
//	{
//		for (int numE = 0; numE < n; numE++)
//		{
//			if (nodeListEmp[numE]->listBill.checkID(IDBill) == false) // co ID trung
//				return nodeListEmp[numE];
//		}
//		return NULL;
//	}
//	
//	
//	void addBill(char idEmp[11], Bills &newBill)
//	{
//		struct Employee* p = Search_ID(idEmp);
//		p->listBill.insertFirst(newBill);
//	}
//	
//};
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
