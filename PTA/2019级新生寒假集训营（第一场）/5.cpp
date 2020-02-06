/*
对于给定的正整数N，需要你计算 S=1!+2!+3!+...+N!。

输入格式：
输入在一行中给出一个不超过10的正整数N。

输出格式：
在一行中输出S的值。
*/

#include<stdio.h>
long long jc=1,sum=0;
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        jc*=i;
        sum+=jc;
    }
    printf("%lld",sum);
    return 0;
}