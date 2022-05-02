//Viết chương trình nhập vào ba số a, b, c. Sau đó kiểm tra xem ba số này có tạo thành cạnh của tam giác hay không. Nếu là tam giác thì kiểm tra xem đó là loại tam giác nào trong số các loại sau: vuông, cân, vuông cân, đều, tam giác thường.
#include<stdio.h>
#include<math.h>

void kiemtratamgiac(int a,int b,int c){
    if(a > b-c && b > a - c && c > a- b){
        if(( a*a == b *b + c *c) || (b*b == a*a + c*c) ||(c*c == a *a + b *b)){
           if(a== b || b== c || a== c){
               printf("Tam giac vuong can !\n");
           }else{
                printf("TAM GIAC VUONG \n");
           }
        }
       else if(a == b && b == c){
            printf("Tam giac deu \n!");
        }else if(a== b || b== c || a== c){
            printf("Tam giac can \n");
        }else{
            printf("tam giac thuong !");
        }
    }else{
        printf("Khong phai 3 canh cua mot tam giac !");
    }
}

int main (){
    int a , b ,c ; 
    printf("Nhap a va b va c :");
    scanf("%d %d %d",&a,&b,&c);
    kiemtratamgiac(a,b,c);
    return 0;
}