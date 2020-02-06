/*
对给定的字符串，本题要求你输出最长对称子串的长度。例如，给定Is PAT&TAP symmetric?，最长对称子串为s PAT&TAP s，于是你应该输出11。

输入格式：
输入在一行中给出长度不超过1000的非空字符串。

输出格式：
在一行中输出最长对称子串的长度。
*/

#include<stdio.h>
char s[1024];
int n;
int main(){
    int max=1,i=0,j;
    scanf("%[^\n]",s+1);
    s[0]='[';
    while(s[j]!='\0')j++;
    s[j]=']';
  	s[j+1]='\0';
    while(s[i+1]!='\0'){
        j=0;
        while(s[i-j]==s[i+j+1])j++;
        j=j*2;
        if(max<j)max=j;
        j=0;
        while(s[i+j]==s[i-j])j++;
        j=j*2-1;
        if(max<j)max=j;
        i++;
    }
    printf("%d",max);
    return 0;
}