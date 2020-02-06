#include<stdio.h>
int main(){
    int n,m,max=0x80000000,min=0x7FFFFFFF,ans=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&m);
        if(max<m) max=m;
        if(min>m) min=m;
        ans+=m;
    }
    printf("%d\n%d\n%d\n",max,min,ans);
    return 0;
}