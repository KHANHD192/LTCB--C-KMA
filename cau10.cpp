//Nhập vào 2 số là tháng và năm, kiểm tra xem tháng đó có bao nhiêu ngày. In kết quả ra màn hình theo dạng: Tháng 3 năm 2014 có 31 ngày.
#include<stdio.h>
#include<math.h>

void test(int nam ,int thang){
 switch(thang){
    case 1 :
    case 3 :
    case 5 :
    case 7 :
    case 8 :
    case 10 :
    case 12:{
        printf("thang %d nam %d co 31 ngay",thang,nam);
        break;
    }
    case 2 :{
        if( nam %4 == 0 && nam %100 !=0 ){
        printf("Thang 2  nam %d co 29 ngay !",nam);
        }else{
            printf("Thang 2 nam %d co 28 ngay !",nam);
        }
        break;
    }
    case 4 :
    case 6 :
    case 9 :
    case 11 :{
        printf("Thang %d nam %d co 30 ngay ",thang,nam);
        break;
    }




 }  
}
int main (){
    int a,b;
    printf("Nhap nam :");
    scanf("%d",&a);
    printf("nhap thang :");
    scanf("%d",&b);
    test(a,b);
}
