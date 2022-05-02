//Nhập vào một dãy n số bất kỳ từ bàn phím. Tìm giá trị lớn nhất và nhỏ nhất của dãy số đó. In kết quả tìm được ra màn hình cùng vị trí của các giá trị max, min trong dãy số. 
#include<stdio.h>
#include<math.h>

void importArray(int a[],int n){
    for(int i = 0 ; i < n ; i++){
        printf("A[%d] : ",i);
        scanf("%d",&a[i]);
        
    }
}
int seekMAX_MIN(int flag , int a[],int n){
    if(flag == 0){
        int min  = a[0] ; //KÝ THUẬT ĐẶT LÍNH 
        for (int i =0 ; i < n; i++){
            if(a[i]  < min){
                min =a[i];
            }
        }
        return min;
    }else if (flag  == 1){
            int MAX  = a[0] ; //KÝ THUẬT ĐẶT LÍNH 
        for (int i =0 ; i < n; i++){
            if(a[i]  > MAX){
                MAX =a[i];
            }
        }
        return MAX;
    }
}
int main (){
    int a[20];
    int n;
    printf("Nhap so phan tu cua mang : ");
    scanf("%d",&n);
    importArray(a,n);
    printf("MAX cua mang la %d",seekMAX_MIN(1,a,n));
    printf("\nMin cua mang la %d",seekMAX_MIN(0,a,n));

}