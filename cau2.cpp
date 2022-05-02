/*
Viết chương trình nhập vào tổng thu nhập GDP của nước ta năm 2014 (tính theo USD) và tốc độ tăng trưởng kinh tế bình quân nào đó. In ra màn hình thu nhập GDP của các năm theo dạng:
	Năm	GDP
	2014	100
	2015	112.5
	. . .	. . .
cho đến năm có GDP >= 2 lần năm 2014 thì dừng. 

*/

#include<stdio.h>
#include<math.h>

void xuat(int a[],int (i)){
    int year = 2014;
     printf("Nam\tGDP\n");
      for (int j = 0 ; j < i ; j++){
     //     printf("Nam\tGDP\n");
          printf("%d\t%d\n",year,a[j]);
          year++;
      }
}

int main (){
    int a[100];
    int i = 1 ;
    int years = 2014;
   printf("nhap GDP NAM 2014 : ");
   scanf("%d",&a[0]);
   for (i; i < 100 ;i++){
       printf("nhap GDP NAM %d :",2014 + i);
       scanf("%d",&a[i]);
       if(a[i] >= (2 *a[0])){
           break;
       }
   }
    xuat(a,(i+1));
    return 0;
}