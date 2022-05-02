#include<stdio.h>


void nhapmang(int a[],int n){
    for(int i = 0 ; i < n ; i++){
            scanf("%d",&a[i]);
    }
}
void xuatmang(int a[],int n){
    for(int i = 0 ; i < n ; i++){
        printf("%d",a[i]);
    }
}

void ghepmang(int a[],int b[],int c[],int m ,int n){
    int i = 0 ;
    int cs1 = 0 , cs2 = 0;
    while(cs1 < m && cs2 < n){
        if(a[cs1] >= b[cs2]){
            c[i] = b[cs2];
            cs2++;
            i++;
        }else if(a[cs1] < b[cs2]){
            c[i] = a[cs1];
            cs1++;
            i++; 
        }
    }
    if(cs1 == m){
        while(cs2 < n){
            c[i] = b[cs2];
            cs2++;
        }
    }else {
        while(cs1 < m){
            c[i] = a[cs1];
            cs1++;
        }
    }
}

int main (){
    int a[]= {2,4,5};
    int b[] = { 3,4,5};
    int c[20] ;
    ghepmang(a,b,c,3,3);
    xuatmang(c,6);
      return 0;
}