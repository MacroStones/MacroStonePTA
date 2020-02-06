/*
本题要求你计算A−B。不过麻烦的是，A和B都是字符串 —— 即从字符串A中把字符串B所包含的字符全删掉，剩下的字符组成的就是字符串A−B。

输入格式：
输入在2行中先后给出字符串A和B。两字符串的长度都不超过10
​4
​​ ，并且保证每个字符串都是由可见的ASCII码和空白字符组成，最后以换行符结束。

输出格式：
在一行中打印出A−B的结果字符串。
*/

#include<stdio.h>
#include<iostream>

const int MAXN=10011;
char stra[MAXN],strb[MAXN];
int main(){
    std::cin.getline(stra,10011);
    std::cin.getline(strb,10011);
    int i=0,j=0;
    bool flag;
    while(stra[i]!='\0'){
        flag=true;
        j=0;
        while(strb[j]!='\0'){
            if(stra[i]==strb[j]){
                flag=false;
                break;
            }
            j++;
        }
        if(flag){
            printf("%c",stra[i]);
        }
        i++;
    }
    return 0;
}