// tích hai ma trận 

#include<stdio.h>
#include<string.h>

void nhapmatran(int a[][20],int m,int n){
    for (int i = 0 ;i < m ; i++){
        for(int j = 0 ; j < n ;j++){
            scanf("%d",&a[i][j]);
        }
    }
}
void tich_matran(int a[][20],int b[][20],int c[][20],int n,int m,int p ){
   for(int i  =0 ; i < n ; i++){
       for(int j = 0 ; j < m ; j++){
           for(int k = 0 ; k < p ; k++ ){
               c[i][j] += a[i][k] * b[k][j];
           }
       }
   }
}
void xuat(int a[][20],int m,int n){
    for (int i = 0 ;i < m ; i++){
        for(int j = 0 ; j < n ;j++){
           printf("%d ",a[i][j]);
        
        }
        printf("\n");
    }
    printf("\n");

}

void menu(){
    int a[20][20],b[20][20],c[20][20];
    int n,p,m;
 j:   printf("1.NHAP HAI MA TRAN \n2.TICH 2 MA TRAN \n3.Hien Thi 3 ma tran\n4.KET THUC\n");
    int k ; 
    printf("Lua chon cua ban :");
    scanf("%d",&k);
    switch(k){
        case 1 :{
            printf("Nhap ma tran A:\n");
            printf("Nhap n :");
            scanf("%d",&n);
            printf("Nhap p :");
            scanf("%d",&p);
            nhapmatran(a,n,p);
            printf("Nhap ma tran B:\n");
            printf("Nhap m :");
            scanf("%d",&m);
            nhapmatran(a,p,m);
             goto j;
        }
        case 2:{
            printf("TICH CUA MA TRAN A * B :\n");
            tich_matran(a,b,c,n,m,p);
            goto j;
        }
        case 3 :{
            printf("HIEN THI 3 MA TRAN \n");
            xuat(a,n,p);
            xuat(b,p,m);
            xuat(c,n,m);
            goto j;

        }
        case 4 :{
            break;
        }
    }
}
    int main(){
        menu();
    }
