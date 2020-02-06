#include<stdio.h>
int main(){
    int n,k,m[1000],f=-1;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",m+i);
    scanf("%d",&k);
    for(int i=0;i<n && f==-1;i++)
        if(m[i]==k) f=i+1;
    printf("%d",f);
    return 0;
}