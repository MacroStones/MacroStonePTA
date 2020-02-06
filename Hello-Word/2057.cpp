/*问题描述
我们的HDOJ中肯定存在很多A + B问题，现在又出现了一个新问题。
给你两个十六进制整数，你的任务是计算它们的总和，并以十六进制打印。
简单 ？AC吧！
输入
输入包含几个测试用例，请处理到文件末尾。
每个案例由一个由空格分隔的行中的两个十六进制整数A和B组成。
A和B的长度小于15。
产量
对于每个测试用例，在一行中以十六进制打印A和B的总和。
样本输入
+ A -A
+ 1A 12
1A -9
-1A -12
1A -AA
样本输出
0
2C
11
-2C
-90 */
#include<iostream>
#include<iomanip>
using namespace std;
int main(){
    long long a,b,z;
    while(cin>>hex>>a>>b){
    if(a+b<0)
       cout<<setiosflags(ios::uppercase)<<hex<<'-'<<-(a+b)<<endl;//16进制大写
    else
       cout<<setiosflags(ios::uppercase)<<hex<<a+b<<endl;
    }
}