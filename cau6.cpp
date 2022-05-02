//Viết chương trình tìm bội số chung nhỏ nhất của hai số nguyên dương nhập vào từ bàn phím.
#include<stdio.h>
#include<math.h>

int UCLN(int a, int b){
    if(a ==  b ){
        return a;
    }
    if(a > b){
        return UCLN(a-b,b);
    }else if(b > a){

        return UCLN(a,b-a);
    }
}
int main (){
    int m,n;
    printf("nHAP M VA N :");
    scanf("%d %d",&m,&n);
    printf("Boi chung nho nhat cua m va n la %d",(m *n)/UCLN(m,n));
    return 0;
}