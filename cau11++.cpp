 #include<stdio.h>
 #include<stdlib.h>
 #include<string.h>

 typedef struct{
     char hoten[20];
     int tuoi,diemtb;

 }SV;
  typedef struct node{
      SV data;
      node *pnext;
  }node;
  typedef struct{
      node *head;
      node *tail;
  }list;

  void init(list &l){
  l.head = l.tail = NULL;
  }
  node *capphatnode(){
      node *q = (node *)malloc(sizeof(node));
      return q;
  }
  SV nhapdata(){
      SV a;
      fflush(stdin);
      printf("nhap ho va ten :");
       gets(a.hoten);
       printf("nhap tuoi :");
       scanf("%d",&a.tuoi);
       printf("Nhap diem trung binh :");
       scanf("%d",&a.diemtb);
       fflush(stdin);
       return a;
  }

  node *taonode(){
      node *q=capphatnode();
      q->pnext = NULL;
      q->data = nhapdata();
      return q;
  }
  void add_tail(list &l, node *q){
      if (l.tail == NULL){
          l.head = l.tail = q;
      }else{
          l.tail->pnext = q;
          l.tail = q;
      }
  }

  void add_mid(list &l,node *p , node *q){
      if(p == l.tail){
          add_tail(l,q);
      }else{
      q->pnext = p->pnext ;
      p->pnext = q;
  }
  }

  void nhaplist(list &l, int n){
      for(int i = 0 ; i < n;i++){
          node *q = taonode();
          add_tail(l,q);
      }
  }

  void hienthi(list l){
      int i = 1;
      printf("DANH SACH SINH VIEN \n");
      printf("STT\tHO TEN\tTUOI\tDIEM TB \n");
      for(node *k = l.head ; k !=NULL;k=k->pnext){
          printf("%d\t%5s\t%d\t%d\n",i,k->data.hoten,k->data.tuoi,k->data.diemtb);
          i++;
      }
  }
  node *search(list l, char kt[]){
     for(node *k = l.head ; k !=NULL;k=k->pnext){
         if(stricmp(k->data.hoten,kt) == 0){
             return k;
         }
     }
  }
  void xoa_dau(list &l){
      if(l.head == NULL){
          printf("kHONG XOA DUOC ! ");
      }else{
      node *q = l.head;
      l.head = q->pnext;
      q->pnext = NULL;
      free(q);
      }
  }
  void xoa_cuoi(list &l){
      node *k ;
     for(k = l.head ; k !=NULL;k=k->pnext){
         if(k->pnext == l.tail){
             break;
         }
     }
     k->pnext =NULL;
     free(l.tail);
     l.tail = k ;  
  }

  void xoa_Mid(list &l,node *p){
      node *k;
         for(k = l.head ; k !=NULL;k=k->pnext){
         if(k->pnext == p){
             break;
         }
     }
     k->pnext = p ->pnext ;
   //  p->pnext = NULL;
     free(p);
  }

  void xoa_sinhvien(list &l){
      char kt[20];
      printf("Nhap ten sinh vien muon xoa :");
      fflush(stdin);
      gets(kt);
      node *f = search(l,kt);
      if(f == l.head){
          xoa_dau(l);
      }else if(f == l.tail){
            xoa_cuoi(l);
      }else{
          xoa_Mid(l,f);
      }
  }

  void chen_sinhvien(list &l){
      char kt[20];
      printf("Nhap sinh vien muon chen vao sau :");
      fflush(stdin);
      gets(kt);
      node * f = search(l,kt);
      node * q = taonode();
       if(f==l.tail){
          add_tail(l,q);
      }else{
      add_mid(l,f,q);
  }
  }

void menu(){
    list l;
    init(l);
   j: printf("1.TAO DANH SACH\n2.HIEN THI DANH SACH SINH VIEN\n3.CHEN THEM SINH VIEN\n4.XOA mot sinh vien\n5.ket thuc\n");
    int k;
    printf("luA CHON CUA BAN :");
    scanf("%d",&k);
    switch(k){
        case 1:{
            int n;
            printf("Nhap so sinh vien can tao :");
            scanf("%d",&n);
            nhaplist(l,n);
            goto j;
        }
        case 2:{
            hienthi(l);
            goto j;
        }
        case 3 :{
            chen_sinhvien(l);
            goto j;
        }
        case 4:{
            xoa_sinhvien(l);
            goto j;
        }
        case 5 :{
            break;
        }
    }
}

int main (){
    menu();
  
}