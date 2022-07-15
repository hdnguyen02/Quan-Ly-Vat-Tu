# ĐỒ ÁN QUẢN LÝ VẬT TƯ 

# Table of Contents
- [ĐỀ BÀI](#1)
- [CHỨC NĂNG](#2)
- [LƯU Ý](#3)
- [THẦY NHẬN XÉT](#4)

## ĐỀ BÀI <a name="1"></a>
#### Danh sách vật tư
+ cây nhị phân tìm kiếm ( MAVT (C10), TENVT, DVT (đơn vị tính), Số lượng tồn)
#### Danh sách nhân viên. 
+ danh sách tuyến tính là 1 mảng con trỏ (MANV, HO, TEN, PHAI, con trỏ dshd): con trỏ dshd sẽ trỏ đến danh sách các hóa đơn mà nhân viên đó đã lập. Danh sách nhân viên có tối đa 500 nhân viên
#### Danh sách hóa đơn. 
+ danh sách liên kết đơn(SoHD (C20), Ngày lập hóa đơn, Loai,  con trỏ cthd). Lọai chỉ nhận ‘N’ (phiếu nhập) hoặc ‘X’ (phiếu xuất), dscthd để lưu chi tiết các vật tư của hóa đơn đó.
#### Danh sách chi tiết hóa đơn. 
+ danh sách liên kết đơn ( MAVT, Soluong, Dongia, %VAT).  

#### Chương trình có các chức năng sau: 

a/ Nhập vật tư : cho phép cập nhật (thêm / xóa / hiệu chỉnh ) thông tin của vật tư; riêng số lượng tồn chỉ cho phép nhập khi đó là vật tư mới thêm. 
b/ In danh sách vật tư tồn kho : liệt kê ds vật tư ra màn hình theo thứ tự tên vật tư tăng dần.  Kết xuất : Mã VT		Tên vật tư		Đơn vị tính		Số lượng tồn
c/ Nhập nhân viên: Cập nhập (thêm / xóa / hiệu chỉnh ) các nhân viên  dựa vào mã nhân viên, họ, tên không được rỗng.
d/ In danh sách nhân viên theo thứ tự tên nhân viên tăng dần, nếu trùng tên thì tăng dần theo họ ra màn hình, 1 nhân viên / dòng
e/ Lập hóa đơn nhập/Lập hóa đơn xuất: nhập vào số hóa đơn, ngày lập, loại (chỉ nhận ký tự N hoặc X). Sau đó, tiếp tục cho phép nhập các vật tư của hóa đơn đó; Căn cứ vào loại hóa đơn, chương trình sẽ tự động cập nhật số lượng tồn. 
- Lập hóa đơn có 2 loại hóa đơn : hóa đơn nhập, hóa đơn xuất 
Lưu ý: - Nếu số lượng xuất không đủ hàng thì báo lỗi và in ra số lượng tồn hiện có trong kho;
- Chỉ được phép xóa vật tư đang lập của hóa đơn hiện tại. Khi hóa đơn đã ghi thì không được xóa các vật tư trog hóa đơn 
f/ In hóa đơn : In hóa đơn dựa vào số hóa đơn do ta nhập vào
g/ Thống kê các hóa đơn trong 1 khỏang thời gian: nhập vào 2 thời điểm từ ngày , đến ngày, chương trình sẽ in ra các hóa đơn được lập trong khoảng thời gian như trên. Kết xuất:
		BẢNG LIỆT KÊ CÁC HÓA ĐƠN TRONG KHOẢNG THỜI GIAN
			Từ ngày : ##/##/####   Đến ngày : ##/##/####
    Số HĐ		Ngày lập     Loại HĐ		Họ tên NV lập		Trị giá hóa đơn
h/ In 10 vật tư có doanh thu cao nhất trong 1 khoảng thời gian.
i/ Thống kê doanh thu của cửa hàng trong từng tháng thuộc 1 năm do user nhập vào.
BẢNG THỐNG KÊ DOANH THU NĂM ####
 				THÁNG 		DOANH THU

![Tổng quan](https://user-images.githubusercontent.com/83913057/179233092-8aee8556-183e-4387-8b2e-1467c0860de1.png)
        
## CHỨC NĂNG <a name="2"></a>
a > VẬT TƯ ( THÊM / XÓA / SỮA )  
- Chú ý đến MAVT ( không được trùng ) 
- Không được xóa vật tư đã tạo chi tiết hóa đơn 
- Không nên cho người dùng chỉnh sữa MAVT và số lượng tồn.   



b > IN VẬT TƯ

![Vật Tư](https://user-images.githubusercontent.com/83913057/179233349-a9953de8-28aa-4620-832c-b617739626bf.PNG)

c > NHÂN VIÊN ( THÊM / XÓA / SỮA ) 
- Chú ý đến MANV ( không được trùng )
- Không được xóa nhân viên đã tạo hóa đơn 
- Không nên cho người dùng chỉnh sữa MANV. 

d > IN NHÂN VIÊN 

![Nhân Viên](https://user-images.githubusercontent.com/83913057/179233463-deaa032d-9572-4f9e-b823-a9fb1c5f6ac3.PNG)

e > TẠO HÓA ĐƠN ( CHỨC NĂNG QUAN TRỌNG )  
- Chỉ Nhận 2 loại hóa đơn nhập / xuất. 
- Tạo dao diện thân thiện người dùng, hiển thị đầy đủ thông tin lên màn hình khi thêm hóa đơn ( bao gồm cả tên nhân viên tạo hóa đơn và tên của mã vật tư ).  
- Không được xuất hóa đơn với số lượng < số lượng tồn ( đối với hóa đơn xuất )

![Hóa đơn](https://user-images.githubusercontent.com/83913057/179233473-8b6dbbb4-1d3c-4b1a-a3f6-8f95c1f63c5b.PNG)

g/h/i > THỐNG KÊ / IN HÓA ĐƠN. 

![In Hóa Đơn](https://user-images.githubusercontent.com/83913057/179233483-30ced96a-664d-4a74-81
![Thống kê](https://user-images.githubusercontent.com/83913057/179233490-a6f79516-d9f5-4a52-919a-a2d65ebf29c0.PNG)
e0-745c72d49119.PNG)








