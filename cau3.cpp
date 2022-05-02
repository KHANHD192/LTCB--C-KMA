/*
:  Nhập vào một dãy n số bất kỳ từ bàn phím. Sau đó sắp xếp dãy số theo chiều tăng dần. In ra màn hình dãy số ban đầu và dãy số đã sắp xếp.
*/
#include<stdio.h>

int main (){
    int n;
    int a[10];
    printf("nhap  n:");
    scanf("%d",&n);
    for (int i = 0 ; i < n ; i++){
        printf("a[%d] :",i);
        scanf("%d",&a[i]);
    }
    for (int i = 0 ; i < n - 1 ; i++){
        for (int j = i + 1; j < n;j++ ){
            if (a[i] > a[j]){
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
     for (int i = 0 ; i < n ; i++){
        printf("%d ",a[i]);
        //scanf("%d",&a[i]);
    }

}