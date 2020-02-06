#include<stdio.h>
int main(){
    unsigned int n=0;
    char s[8];
    scanf("%s",s);
    for(int i=0;i<8;i++){
        if(s[i]==0)
            break;
        n*=16;
        if(s[i]>='0'&&s[i]<='9')
            n+=s[i]-'0';
        else
            n+=s[i]-'A'+10;
    }
    printf("%u",n);
    return 0;
}