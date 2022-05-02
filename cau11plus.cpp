// code ôn lại dslk nghịch
// sửa đề tý nếu là dslk ngược thì chèn vào trước 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct {
    char hoten[20];
    int tuoi;
    float DTB;

}SV;

typedef struct node {
    SV data;
    node * next;
}node;

typedef struct{
    node * head;
    node *tail;
}list ;

void init(list  &l){
    l.head = l.tail = NULL;
}
node *capphatnode(){
    node *q =(node *)malloc(sizeof(node));
    return q;
}
SV nhapdata(){
    SV a;
    fflush(stdin);
    printf("nhap ho ten :");
    gets(a.hoten);
    printf("Nhap tuoi :");
    scanf("%d",&a.tuoi);
    printf("nhap diem trung binh :");
    scanf("%f",&a.DTB);
    fflush(stdin);
    return a;
}
node *taonode(){
    node *q = capphatnode();
    q->data = nhapdata();
    q->next =NULL;
    return q;
}

void add_end(list &l,node *q){
    if(l.tail == NULL){
        l.head=l.tail =q ;
    }else{
        q->next = l.tail;
        l.tail = q;
    }
}
void nhaplist(list &l,int n){
    printf("Nhap danh sach sinh vien !");
    for(int i = 0 ; i < n ; i++){
        node * q =taonode();
        add_end(l,q);
        printf("\n");
    }
}

void add_head(list &l , node * q){
    if(l.head == NULL){
        l.head = l.tail = q;
    }else{
        l.head->next = q;
        l.head = q;
    }
}

void add_mid(list &l ,node *p,node *q){
    if( p == l.head){
        add_head(l,q);
    }else {
        q->next = p->next ;
        p->next = q ;
    }
}
node *search(list &l, char kt[]){
     for(node * k = l.tail ; k !=NULL ;k=k->next){
         if(stricmp(k->data.hoten,kt ) == 0){
             return k ;
         }
     }
}

void chensinhvien(list &l){
    char kt[20];
    printf("nhap ten sinh vien muon chen vao sau : ");
    fflush(stdin);
    gets(kt);
    node * q =search(l,kt);
    node *k = taonode();
    if(q == l.tail){
        add_end(l,k);
    }else if (q == l.head){
        add_head(l,k);
    }else{
        add_mid(l,q,k);
    }
}
void suasinhvien(list &l){
    char kt[20];
    printf("nhap sinh vien co ten can sua :");
    fflush(stdin);
    gets(kt);
    node *k = search(l,kt);
    k->data = nhapdata();
}
void hienthi(list l){
    printf("DANH SACH SINH VIEN !\n");
    int i = 1;
    printf("STT\tHO TEN\tTUOI\tDIEMTB\n");
    for (node * k = l.tail ; k !=NULL; k=k->next){
    printf("%d\t%5s\t%d\t%f\n",i,k->data.hoten,k->data.tuoi,k->data.DTB);
        i++;
    }
}
void menu(){
    list l ;
    init(l);
 j:   printf("1.TAO DANH SACH\n2.HIEN THI DANH SACH\n3.CHEN THEM SINH VIEN\n4.SUA 1 SINH VIEN\n5.Ket thuc\n");
    int k;
    printf("lua chon cua ban :");
    scanf("%d",&k);
  switch(k){
      case 1 : {
          int n;
          printf("nhap so luong sinh vien muon tao :");
          scanf("%d",&n);
          nhaplist(l,n);
          goto j;
      }
      case 2 :{
          hienthi(l);
          goto j;
      }
      case 3 :{
          chensinhvien(l);
          goto j;
      }
      case 4 :{
          suasinhvien(l);
          goto j;
      }
      case 5 :
      {
          break;
      }
  }
}
int main (){
    menu();
    return 0;
}