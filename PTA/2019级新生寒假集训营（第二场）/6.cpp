/*
给定N个正整数，请统计奇数和偶数各有多少个？

输入格式：
输入第一行给出一个正整N（≤1000）；第2行给出N个非负整数，以空格分隔。

输出格式：
在一行中先后输出奇数的个数、偶数的个数。中间以1个空格分隔。
*/

#include<stdio.h>
int main() {
    int ji = 0, ou = 0;
    int n,m;
    scanf("%d",&n);
    for (int i = 0; i < n; i++) {
        scanf("%d",&m);
        if (m % 2 == 0)
            ou++;
        else
            ji++;
    }
    printf("%d %d",ji,ou);
    return 0;
}