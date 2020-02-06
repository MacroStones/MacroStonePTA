#include<stdio.h>
int main(){
    unsigned int a;
    char c[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    char s[16],n=0;
    scanf("%u",&a);
    do{
        s[n]=c[a%16];
        a/=16;
        n++;
    }while(a>0);
    for(n--;n>=0;n--){
        printf("%c",s[n]);
    }
    //printf("\n");
    return 0;
}