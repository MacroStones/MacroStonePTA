#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    for(int i=100;i<=999;i++)
        if((i/100+(i/10)%10)*2+i%10==n)
            printf("%d%d%d\n",i,(i/10)%10,i/100);
    for(int i=100;i<=999;i++)
        if((i/100+(i/10)%10+i%10)*2==n)
            printf("%d%d%d%d\n",i,i%10,(i/10)%10,i/100);
    return 0;
}