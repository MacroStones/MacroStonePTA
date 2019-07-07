/*Problem Description
输入一个英文句子，将每个单词的第一个字母改成大写字母。
Input
输入数据包含多个测试实例，每个测试实例是一个长度不超过100的英文句子，占一行。
Output
请输出按照要求改写后的英文句子。
*/
#include<stdio.h>
int main(){
    char c; bool flag=true;
    while(scanf("%c",&c)==1){
        if(c==' '||c=='\n'){
            flag=true;
            printf("%c",c);
        }else if(flag){
            flag=false;
            printf("%c",c&0xdf);//把第6位置1
        }else{
            printf("%c",c);
        }
    }
    return 0;
}