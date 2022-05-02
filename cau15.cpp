#include<stdio.h>
#include<stdlib.h>

void nhapmatran(int a[][20],int n,int m){
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
		
		scanf("%d",&a[i][j]);
	}
   }
}   
void xuatmatran(int a[][20],int n,int m){
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
		
		printf("%d",&a[i][j]);
	}
	printf("\n");
   }
}   
void pushmatranlenfile(char filePath[], int a[][20],int n,int m){
	FILE *f = fopen(filePath,"wt");
for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
		fprintf(f,"%d",a[i][j]);
		
	}
   }
	fclose(f);
}
void tinhtongmatran(int a[][20],int b[][20],int n,int m,int c[][20]){
		for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
		
		 c[i][j] = a[i][j] + b[i][j];
	}
   }
}

void pushC(char filePath[],int c[][20],int n,int m){
		FILE *f = fopen(filePath,"at");
for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
		fprintf(f,"%d",c[i][j]);
		
	}
   }
	fclose(f);
}
void taofile(int a[][20],int b[][20],int c[][20],int n, int m,char filePath[]){
	FILE *f = fopen(filePath,"at");
	fprintf(f,"%d %d\n",n,m);
	fprintf(f,"%s\n","MA TRAN A");
	pushmatranlenfile(filePath,a,n,m);
	fprintf(f,"%s\n","MA TRAN B");
	pushmatranlenfile(filePath,b,n,m);
	tinhtongmatran(a,b,n,m,c);
	pushmatranlenfile(filePath,c,n,m);
	fclose(f);
}
void docfile(char filePath[]){
	FILE *f = fopen(filePath,"rt");
	int n,m ;
	fscanf(f,"%d %d\n",&n,&m);
	printf("%d %d \n",n,m);
	char ch ; 
	while(true){
		ch = fgetc(f);
		if(ch == 'A'){
			break;
		}
	}
	int a[20][20]; 
	//  
		for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
	      fscanf(f,"%d",&a[i][j]);	
		
	}
   }
   xuatmatran(a,n,m);
   printf("\n");
   	while(true){
		ch = fgetc(f);
		if(ch == 'B'){
			break;
		}
	}
	int b[20][20]; 
	//  
		for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
	      fscanf(f,"%d",&b[i][j]);	
		
	}
   }
   xuatmatran(b,n,m);
   printf("\n");
   
   
	fclose(f);
}

void menu(int a[][20],int b[][20],int c[][20],int n,int m){
	char filePath[] = "SO_LIEU.C";
j :	printf("1.DOC TEP MA_TRAN.C\n");
	printf("2.GHI MA TRAN C BO SUNG VAO CUOI TAP\n");
	printf("3.KET THUC\n");
	int k;
	printf("Lua chon cua ban :");
	scanf("%d",&k);
	switch(k){
		case 1 :{
			docfile(filePath);
			goto j;
			
		
		}
		case 2:{
			tinhtongmatran(a,b,n,m,c);
			pushC(filePath,c,n,m);
			goto j;
		}
		case 3 :{
			break;
		}
	}
}
int main (){
	int a[20][20],b[20][20],c[20][20];
	int n,m;
	printf("nhap n :");
	scanf("%d",&n);
	printf("nhap m :");
	scanf("%d",&m);
	nhapmatran(a,n,m);
	nhapmatran(b,n,m);
	char filePath[] = "SO_LIEU.C";
     
	taofile(a,b,c,n,m,filePath);
	menu(a,b,c,n,m);
	return 0;
}
