#include <stdio.h>
 
int main()
{
    int row,col;
    printf("Enter row: ");scanf("%d",&row);
    printf("Enter column: ");scanf("%d",&col);
    int i,j;
    for (i=0;i<row;++i)
    {
        for (j=0;j<col;++j)
            if (i==0 || j==0 ||i==(row-1) || j==(col-1)) printf("*");
            else printf(" ");
        printf("\n");
    }
}