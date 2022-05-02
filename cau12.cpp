#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct{
    char tenhang[20];
    int dongia;
    int soluong;
    int thanhtien;
}SP;
void nhapdata(SP &a){
    fflush(stdin);
    printf("nhap ten cua san pham :");
    gets(a.tenhang);
    printf("Nhap don gia :");
    scanf("%d",&a.dongia);
    printf("nhap so luong :");
    scanf("%d",&a.soluong);
    a.thanhtien = a.dongia *a.soluong;
    fflush(stdin);

}
void nhaplist(SP a[],int n,FILE *f){
    f=fopen("SO_LIEU.BIN","wb");
      printf("NHAP DANH SACH SAN PHAM  !\n");
      for(int i =0;i<n;i++){
          nhapdata(a[i]);
          fwrite(&a[i],sizeof(SP),1,f);
      }
      fclose(f);
}
void display(SP b[],FILE *f){
    int i = 0;
    int tongtin = 0;
     f=fopen("SO_LIEU.BIN","rb");
    printf("SO LIEU BAN HANG \n");
    printf("STT\tTEN HANG\tDonGia\tsoLUONG\tthanhtien\n");
    while(!feof(f)){
        if(fread(&b[i],sizeof(SP),1,f) >0){
              printf("%d\t%5s\t\t%d\t%d\t%d\n",i+1,b[i].tenhang,b[i].dongia,b[i].soluong,b[i].thanhtien);    
                 tongtin += b[i].thanhtien;
        i++;
        }
    }
    printf("\t\t\t\t tong tin %d ",tongtin);
}
 void bosung(SP a[]){
     int e;
     printf("nhap so san pham can them (it nhat hai san pham )\n");
     scanf("%d",&e);
     FILE * f = fopen("SO_LIEU.BIN","ab");
     for(int i = 0 ; i < e ; i++){
         nhapdata(a[i]);
         fwrite(&a[i],sizeof(SP),1,f);
     }
     fclose(f);
 }

 void menu(){
     SP a[20];
     FILE *f;
    j: printf("1.NHAP DU LIEU BAN HANG LEN TEP \n2.GHI BO SUNG\n3.HIEN THI\n4.KET THUC\n");
     int k;
     printf("Lua chon cua ban :");
     scanf("%d",&k);
     switch(k){
         case 1 :{
             int n ; 
             printf("nhap so mat hang can tao :");
             scanf("%d",&n);
             nhaplist(a,n,f);
             goto j;
         }
         case 2 :{
             bosung(a);
             goto j;
         }
         case 3 :{
              SP b[20];
             display(b,f);
             goto j;
             
         }
         case 4 :{
             break;
         }
     }
 }

 int main (){
     menu();
     return 0;
 }