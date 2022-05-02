/*
Viết chương trình giải phương trình bậc hai: ax2 + bx + c = 0, với a, b, c là các hệ số thực nhập vào từ bàn phím.
*/
#include<stdio.h>
#include<math.h>

int main (){
    int a,b,c ;
    printf("nhap a :");
    scanf("%d",&a);
    printf("nhap b :");
    scanf("%d",&b);
    printf("nhap c :");
    scanf("%d",&c);
    if (a == 0 && b==0 && c == 0){
        printf("phuong trinh vo so nghiem");
    }else{
       if (a==b == 0 && c!=0){
           printf("pt vo nghiem !");
       }
       if ( a == 0 ){
             printf("phuong trinh co 1 nghiem la %d ",(float)-c/b);
       }else{
           int delta = b*b - 4 *a *c ;
           if (delta > 0){
               printf("phuong trinh co hai nghiem la %f va %f",(-b + sqrt(delta))/(float)(2*a),(-b - sqrt(delta))/(float)(2*a));
           }else if (delta == 0){
               printf("phuong trinh co nghiem kep la %f ",(float)(-b)/(2 *a));
           }else if (delta < 0){
               printf("phuong trinh vo nghiem !");
           }

       }
    }

}
 // note : casting ở đuôi và phải là %f mới ra được , câu này mất 10p , quá ngu :<
 