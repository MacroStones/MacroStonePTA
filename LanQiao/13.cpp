#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    if((n%4==0 && n%400!=0)||n%400==0)
        printf("yes\n");
    else
        printf("no\n");
    return 0;
}