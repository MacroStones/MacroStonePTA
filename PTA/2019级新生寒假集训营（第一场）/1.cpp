/*
本题的要求很简单，就是求N个数字的和。麻烦的是，这些数字是以有理数分子/分母的形式给出的，你输出的和也必须是有理数的形式。

输入格式：
输入第一行给出一个正整数N（≤100）。随后一行按格式a1/b1 a2/b2 ...给出N个有理数。题目保证所有分子和分母都在长整型范围内。另外，负数的符号一定出现在分子前面。

输出格式：
输出上述数字和的最简形式 —— 即将结果写成整数部分 分数部分，其中分数部分写成分子/分母，要求分子小于分母，且它们没有公因子。如果结果的整数部分为0，则只输出分数部分。
*/

#include<stdio.h>
void swap(long &a,long &b){
    long tmp=a;
    a=b;
    b=tmp;
}
long gcd(long a,long b){
    //a must bit then b
    if(a%b==0)
        return b;
    return gcd(b,a%b);
}
long lcm(long a,long b){
    if(a<b)
        swap(a,b);
    if(a%b==0)
        return a;
    else
        return gcd(a,b)*a*b;
}
int main(){
    int n;
    long sum=0,suma=0,sumb=1;
    scanf("%d",&n);
    while(n--){
        long a,b,tmp;
        scanf("%ld/%ld",&a,&b);
        tmp=lcm(sumb,b);
        suma*=tmp/sumb;
        suma+=a*tmp/b;
        sumb=tmp;
        sum+=suma/sumb;
        suma%=sumb;
        tmp=gcd(suma,sumb);
        suma/=tmp;
        sumb/=tmp;
    }
    if(sum!=0||suma==0)
        printf("%ld",sum);
    if(sum!=0&&suma!=0){
        printf(" ");
    }
    if(suma!=0)
        printf("%ld/%ld",suma,sumb);
    return 0;
}
