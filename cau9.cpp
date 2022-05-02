/*
Viết chương trình nhập vào ma trận thực Anxm . Sau đó tìm giá trị lớn nhất, giá trị nhỏ nhất của ma trận này. In ma trận cùng kết quả tìm được ra màn hình.
Tính tổng các số nguyên tố trong ma trận.

*/

#include<stdio.h>
#include<string.h>

void nhapmatran (int a[][20],int m , int n){
    for(int i  = 0 ; i < m ; i ++){
        for(int  j = 0 ; j < n ; j++){
                printf("A[%d][%d] :",i,j);
                scanf("%d",&a[i][j]);
        }
    }
}
int seekMAX_MIN(int flag , int a[][20],int m , int n){
    if(flag == 0){
        int min  = a[0][0] ; //KÝ THUẬT ĐẶT LÍNH 
        for(int i  = 0 ; i < m ; i ++){
        for(int  j = 0 ; j < n ; j++){
               if(a[i][j]  < min){
                min =a[i][j];
        }
    }
        }
        return min;
    }else if (flag  == 1){
         int min  = a[0][0] ; //KÝ THUẬT ĐẶT LÍNH 
        for(int i  = 0 ; i < m ; i ++){
        for(int  j = 0 ; j < n ; j++){
               if(a[i][j]  > min){
                min =a[i][j];
        }
    }
        }
        return min;
    }
}
int  checkIsPrimeN(int i ,int n){
    if( n == 1){
        return 0;
    }
  if(i > n -1){// i begin to 2 
      return 1;
  }else{
      if(n % i == 0){
          return 0 ;
      }
   return checkIsPrimeN(i+1,n);
  }
}
int sumIsPrimeN(int a[][20],int m  , int n){
       int  k = 2 ;
       int sum = 0 ;
         for(int i  = 0 ; i < m ; i ++){
        for(int  j = 0 ; j < n ; j++){
              if(checkIsPrimeN(k,a[i][j]) == 1){
                  sum += a[i][j];
              }
        }
    }
    return sum;
}

int main(){
    int a[20][20];
    nhapmatran(a,2,2);
    printf("Max mang la %d",seekMAX_MIN(1,a,2,2));
    printf("\nMin mang la %d",seekMAX_MIN(0,a,2,2));
   int k = sumIsPrimeN(a,2,2);
   printf("\n%d",k);
    return 0;

}