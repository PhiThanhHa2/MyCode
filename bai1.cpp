//Viết chương trình C++ nhập 10 giá trị nguyên, sau đó tìm giá trị lớn nhất, nhỏ nhất, 
//tìm giá trị có tần suất xuất hiện nhiều nhất, sắp xếp mảng theo thứ tự tăng dần,
// giảm dần và hiển thị kết quả.
#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;
typedef struct
{
   int so;
}ChuoiSo;
void NHAPCS(ChuoiSo *a, int i)
{
    {
        printf("\nNhap ChuoiSo thu %d: ", i + 1);
        fflush(stdin);
        cout<<"\nNhap so : ";
        cin>>a[i].so;
    }
}
void XUATCS(ChuoiSo *a, int n)
{
    int i;
    cout<<" gia tri= ";
    for (i = 0; i < n; i++)
    {
        cout<<a[i].so<<"\n";
    }
}
// void MAXMIN(ChuoiSo *a, int n)
// {
//     ChuoiSo max,min;
//     int dem= 0, i;
//     int b,c;
//    	min=a[0];
// 	max=a[0];
//     for(i= 0; i< n; i++)
//     {
//         if(max<a[i])
//         {
//             max=a[i];
//             dem++;
//         }
//         if(min>=a[i])
//         {
//             min= a[i];
//         }
//     }
//     cout<<"so lan xuat hien"<<dem;
//     cout<<" gia tri max = "<<max.so;
//     cout<<" gia tri min = "<<min.so;
// }
void SAPXEPTANG(ChuoiSo *a, int n)
{
    int i, j;
	printf("\nChuoi so sau khi sap xep la: ");
	ChuoiSo tg;
	for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i].so < a[j].so)
            {
                tg= a[i];
                a[i]= a[j];
                a[j]= tg;
            }
        }
    }cout<<"\nSap xep tang";
    XUATCS(a,n);
}
void SAPXEPGIAM(ChuoiSo *a, int n)
{
    int i, j;
	printf("\nChuoi so sau khi sap xep la: ");
	ChuoiSo tg;
	for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i].so > a[j].so)
            {
                tg= a[i];
                a[i]= a[j];
                a[j]= tg;
            }
        }
    } 
    cout<<"\nSap xep giam";
    XUATCS(a,n);
}
int main()
{
    int n;
    bool kt = false;
    ChuoiSo *a;
    a = (ChuoiSo *)malloc(n * sizeof(ChuoiSo));
    int chon;
    while (true)
    {
        printf("\n|---------------------------MENU-----------------------|\n");
        printf("\n|----------------------------So------------------------|\n");
        printf("\n|-1.Nhap so                                            |\n");
        printf("\n|-2.Xuat so                                            |\n");
        printf("\n|-3.Sap xep tang chuoi so                              |\n");
        printf("\n|-4.Sap xep giam chuoi so                              |\n");
        printf("\n|-0.Thoat (chon 0)                                     |\n");
        printf("\nMoi ban chon thuc don: ");
        scanf("%d", &chon);
        switch (chon)
        {
        case 1:
        {
            int i;
            printf("\nBan chon nhap so ");
            do
            {
                printf("\nNhap n= ");
                scanf("%d", &n);
                if (n > 50)
                    printf("\nMoi nhap lai");
            } while (n > 50);
            for (i = 0; i < n; i++) 
            {
                NHAPCS(a, i);
            }
            kt = true;
            break;
        }
        case 2:
        {
            if (kt == false)
                printf("\nBan phai chon 1 de nhap du lieu truoc");
            else
            {
                printf("\nBan chon xuat so");
                XUATCS(a, n);
            }
            break;
        }
        // case 3:
        // {
        //     if (kt == false)
        //         printf("\nBan phai chon 1 de nhap du lieu truoc");
        //     else
        //     {
        //         printf("\nBan chon In ra so max so min ");
        //         MAXMIN(a, n);
        //     }
        //     break;
       // }
        case 3:
        {
            if (kt == false)
                printf("\nBan phai chon 1 de nhap du lieu truoc");
            else
            {
                printf("\nBan chon Sap xep tang giam chuoi so ");
                SAPXEPTANG(a, n);
            }
            break;
        }
         case 4:
        {
            if (kt == false)
                printf("\nBan phai chon 1 de nhap du lieu truoc");
            else
            {
                printf("\nBan chon Sap xep tang giam chuoi so ");
                SAPXEPGIAM(a, n);
            }
            break;
        }
        case 0:
        {
            printf("\nBan chon thoat chuong trinh");
            return (0);
            break;
        }
        default:
            printf("\nLua chon cua ban khong co trong MENU");
        }
    }
}