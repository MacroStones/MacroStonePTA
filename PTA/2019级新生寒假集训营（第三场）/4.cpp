/*
据说一个人的标准体重应该是其身高（单位：厘米）减去100、再乘以0.9所得到的公斤数。已知市斤的数值是公斤数值的两倍。现给定某人身高，请你计算其标准体重应该是多少？（顺便也悄悄给自己算一下吧……）

输入格式：
输入第一行给出一个正整数H（100 < H ≤ 300），为某人身高。

输出格式：
在一行中输出对应的标准体重，单位为市斤，保留小数点后1位。
*/

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <algorithm>
using namespace std;

int main(){
    int h;
    scanf("%d",&h);
    printf("%.1f",(h-100)*1.8);
    return 0;
}