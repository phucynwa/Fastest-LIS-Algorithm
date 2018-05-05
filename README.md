# Fastest-LIS-Algorithm

Y tuong cua thuat toan nay do la:
- Tai moi thoi diem, chuoi con co do dai length luon duoc cap nhat vi tri cuoi cung trong inputArr tai lastOfLen[length].
- Gia tri tai vi tri cuoi cung cua do dai length (iputArr[lastOfLen[length]]) phai luon la nho nhat.
- Cap nhat lai vi tri cuoi cung cua do dai length moi khi phat hien thay mot so nho hon iputArr[lastOfLen[length]] va lon hon inputArr[lastOfLen[length - 1]].
- Su dung chat nhi phan de giam thoi gian tim vi tri length nay.

Uu diem:
- Thoi gian thuc thi bai toan nhanh hon 1/3 so voi cac phuong phap hien nay.
- Chua phat hien sai sot.
- Kich thuoc mang toi da len den > 600.000 phan tu.
