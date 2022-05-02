// dùng stack để chuyển đổi hệ số 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node 
{
    int data;
    node *next ;
}node;
typedef struct STACK{
    node * top;
}STACK;
 
 node *capphatnode(){
     node * q = (node*)malloc(sizeof(node));
     return q;
 }
int nhapdata(int a){
    return a;
}
node *taonode(int a){
    node *q =capphatnode();
    q->next =NULL;
    q->data = nhapdata(a);
    return q;
}
void init(STACK &s){
    s.top = NULL;
}
bool isEmpty(STACK s){
    if(s.top == NULL){
        return true;
    }else{
        return false;
    }
}
void push(STACK &s, node *q){ // giống add_head
 if(isEmpty(s) == true){
        s.top = q;
 }else{
     q->next = s.top;
     s.top = q ;
 }
}
int pop(STACK &s){ // giống xóa head và trả về giá trị cua no
if(isEmpty(s) == true){
    printf("STACK EMPTY!\n");
    return 0;
}else{
    node  * k = s.top ; 
    s.top= k->next ;
    int x  = k->data ; 
    free(k);
    return x;
}
}
void chuyencoso(STACK &s,int n,int k){
   while(n > 0){
        int r = n % k ;
    node *q = taonode(r); 
    push(s,q);
    n = n/k ;
   }
}

void hienthi(STACK s){
    for(node * k = s.top ; k!=NULL;k=k->next){
        printf("%d",k->data);
    }
}

int main (){
    STACK s;
    init(s);
   printf("1.CHUYEN CO SO QUA HE 2 \n");
   printf("2.CHUYEN CO SO QUA HE 8 \n");
   printf("3.CHUYEN CO SO QUA HE 16 \n");
   printf("4.ket thuc \n");
   int k ;
   printf("lua chon cua ban :");
   scanf("%d",&k);
   switch(k){
       case 1 :{
              int n;
              printf("Nhap so muon chuyen :");
              scanf("%d",&n);
              chuyencoso(s,n,2);
              hienthi(s);
              break;
       }
       case 2 :{
              int n;
              printf("Nhap so muon chuyen :");
              scanf("%d",&n);
              chuyencoso(s,n,8);
              hienthi(s);
              break;
       }
       case 3 :{
              int n;
              printf("Nhap so muon chuyen :");
              scanf("%d",&n);
              chuyencoso(s,n,16);
              hienthi(s);
              break;
       }
       case 4 :{
           printf("BYE !!" );
           break;
       }
   }
   }
  