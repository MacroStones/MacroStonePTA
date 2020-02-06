#include<stdio.h>
int main(){
    int m,n,j;
    scanf("%d %d",&m,&n);
    for(int i=0;i<m;i++){
        for(j='A'+i;j>'A'&&j>'A'+i-n;j--)
            printf("%c",j);
        for(j='A';j<='A'+n-i-1;j++)
            printf("%c",j);
        printf("\n");
    }
    return 0;
}