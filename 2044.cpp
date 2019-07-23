#include<stdio.h>
long long m[50];
int main(){
    int n;
    scanf("%d",&n);
    m[0]=2;m[1]=1;m[2]=2;
    while(n--){
        int a,b;
        scanf("%d%d",&a,&b);
        for(;m[0]<b-a;m[0]++){
            m[m[0]+1]=m[m[0]]+m[m[0]-1];
        }
        printf("%lld\n",m[b-a]);
    }
    return 0;
}