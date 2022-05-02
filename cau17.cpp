// cong matrix
#include<stdio.h>
#include<math.h>
// a : n , b: m 
void nhapmang(char kt , int a[],int n){
    for(int i = n ; i >= 0 ; i--){
        printf("%c%d :",kt,i);
        scanf("%d",&a[i]);
    }
}
void xuatmang(char kt , int a[],int n){
    for(int i = n ; i >= 0 ; i--){
     //   printf("kt%d :",i);
        printf("%d ",a[i]);
    }
}
void ganzero(int a[],int n){
   for(int i = 0 ; i < n ; i++){
            a[i] = 0;
   }
}

int laymax(int n,int m){
    int z = n< m? n:m;
    return z;
}

void tong2dathuc(int a[],int b[],int c[],int n ,int m){
    for(int i = (n < m? n:m); i>=0 ; i-- ){
            c[i] = a[i] + b[i];
    }
}
int tinhgiatribieuthuc(int a[],int n,int x){
    int sum = 0 ;
    for(int i = 0 ; i <= n-1 ; i++){
        sum+=a[i]*pow(x,i);
    }
    return sum;
}

void menu(){
    int a[20],b[20],c[20];
    int n;
    int m;
j: printf("1.NHAP HE SO T VA Q\n");
printf("2.TINH HE SO DA THUC T\n");
printf("3.IN HE SO 3 DA THUC\n");
printf("4.In gia tri cua 3 da tuc TP Q T\n");
printf("5.KET THUC \n");
int k;
printf("lua chon cua ban :");
scanf("%d",&k);

switch(k){
    case 1:{
        ganzero(a,10);
        ganzero(b,10);
        ganzero(c,10);
        printf("Nhap so mu cao nhat cau a :");
        scanf("%dd",&n);
       nhapmang('a',a,n);
        printf("Nhap so mu cao nhat cua b :");
        scanf("%d",&m);
       nhapmang('b',b,m);
       goto j;
    }
    case 2:{
       // ganzero(a,b,n,m);
        tong2dathuc(a,b,c,n,m);
        xuatmang('c',c,laymax(n,m));
        printf("\n");
        goto j;
    }
    case 3:{
        printf("HE SO DA THUC P :");
         xuatmang('a',a,n);
         printf("\nHE SO DA THUC Q :");
        xuatmang('b',b,m);
         printf("\nHE SO DA THUC t :\n");
        xuatmang('c',c,laymax(n,m));
     printf("\n");
        goto j;
    }
    case 4 :{
        int x ;
        printf("Nhap x :");
        scanf("%d",&x);
        printf("gia tri cua T :");
        printf("%d",tinhgiatribieuthuc(c,n,x));
        
        goto j;

    }
    case 5 :{
        break;
    }
}
}
int main (){
    menu();
    return 0;
}
