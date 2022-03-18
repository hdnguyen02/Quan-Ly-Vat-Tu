#include "autoload.h"
#include<iostream>
using namespace std;






int main() {
    
    char tenBGI[] = "quan ly vat tu"; 
    StartBGI start(tenBGI); // bật màn hình bgi

    char textMenu[][30] = {
        "vat tu","nhan vien","hoa don","thong ke"
    }; 

    const int SOLUONG = 4; 
    cout << MenuDong(0, 0, 100, 100, SOLUONG, 10, 1, 2, 3, textMenu);


    
    
    getch(); 

  

    return 0;
}