#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct {
    char tenhang[20];
    int dongia;
    int soluong;
    int thanhtien;
}SP;
 
 SP nhapdata(){
  SP a;
  fflush(stdin);
  printf("Nhap ten mat hang: ");
  gets(a.tenhang);
  printf("nhap don gia :");
  fflush(stdin);
  scanf("%d",&a.dongia);
  printf("nhap so luong :");
  scanf("%d",&a.soluong);
  a.thanhtien = a.dongia * a.soluong;
  fflush(stdin);
  return a;
 }
 void nhapliist(SP a[],int n){
     FILE *f = fopen("SO_LIEU.C","wb");

     for(int i = 0 ; i < n ; i++){
         a[i] = nhapdata();
          fwrite(&a[i],sizeof(SP),1,f);
     }
     fclose(f);
 }

 void xuat(){
     SP a[20];
     int i = 0 ;
     FILE *f = fopen("SO_LIEU.C","rb");
     printf("SO LIEU BAN HANG\n");
     printf("STT\tTEN HANG\tDON GIA\t So lUONG \t THANH TIEN\n");
     while(!feof(f)){
           fread(&a[i],sizeof(SP),1,f);
           printf("%d\t%5s\t%d\t%d\t%d\n",i+1,a[i].tenhang,a[i].dongia,a[i].soluong,a[i].thanhtien);
          i++;
     }

     fclose(f);
 }

 void bosung(){
     SP a[20];
     int n;
     printf("nhap so mat hang can bo sung :");
     scanf("%d",&n);
      FILE *f = fopen("SO_LIEU.C","ab");
      for (int i = 0 ; i < n ; i++){
          a[i]= nhapdata();
          fwrite(&a[i],sizeof(SP),1,f);
      }
      
      fclose(f);
 }

 void menu(){
     SP a[20];
 j:    printf("1.NHAP SO LIEU\n2.GHI BO SUNG\n3.HIEN THI NOI DUNG\n4.KET THUC\n");
     int k;
     printf("Lua chon cua ban :");
     scanf("%d",&k);
     switch(k){
         case 1 :{
             int n ; 
             printf("Nhap so mat hang can tao :");
             scanf("%d",&n);
             nhapliist(a,n);
             goto j;
         }
         case 2 :{
             bosung();
             goto j;
         }
         case 3 :{
             xuat();
             goto j;
         }
         case 4:{
             break;
         }
     }
 }

 int main (){
     menu();
 }