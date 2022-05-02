// giải hệ phương trình bậc nhất hai ẩn 
/*
Viết chương trình giải hệ 2 phương trình bậc nhất    , với a, b, c, d, e, f, là các hệ số thực nhập vào từ bàn phím. Thông báo kết quả ra màn hình.
*/

#include<stdio.h>
#include<math.h>

void hept(){
    int a,b,c,d,e,f;
    printf("moi nhap a,b,c,d,e,f lan luot:");
    scanf("%d %d%d%d%d%d",&a,&b,&c,&d,&e,&f);
    int Dx = c * e - b *f;
    int Dy = a * f - d *c;
    int D =a * e - b *d;
    if( D != 0){
        printf("phUONG TRINH CO HAI NGIEM %f va %f",Dx/(float)D ,Dy/(float)D );
    }else{
        printf("phuong trinh vo nghiem !");
    }
}
int main (){
    hept();
    return 0;
}