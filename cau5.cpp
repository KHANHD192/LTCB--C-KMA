//:  Tính giá trị n giai thừa (n!), với n nhập vào từ bàn phím. In kết quả ra màn hình.
#include<stdio.h>
#include<math.h>

int giaithua(int n){
    if (n <= 1 ){
        return 1;
    }else{
        return n * giaithua(n-1);
    }
}
int main (){
    int n ;
    printf("nhap n : ");
    scanf("%d",&n);
   printf("\n%d", giaithua(n));
    return 0;
}