/*
真的没骗你，这道才是简单题 —— 对任意给定的不超过10的正整数n，要求你输出2n。不难吧？

输入格式：
输入在一行中给出一个不超过10的正整数n。

输出格式：
在一行中按照格式 2^n = 计算结果 输出2​n的值。
*/

#include<stdio.h>
int main(){
    long long n;
    scanf("%lld",&n);
    printf("2^%lld = %lld",n,1<<n);
    return 0;
}