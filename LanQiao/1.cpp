#include <stdio.h>
#include <algorithm>
int main(){
    int n;
    int m[200];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",m+i);
    std::sort(m,m+n);
    for(int i=0;i<n;i++)
        printf("%d ",m[i]);
    return 0;
}