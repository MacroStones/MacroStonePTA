/*Problem Description
给定三条边，请你判断一下能不能组成一个三角形。
Input
输入数据第一行包含一个数M，接下有M行，每行一个实例，包含三个正数A,B,C。其中A,B,C <1000;
Output
对于每个测试实例，如果三条边长A,B,C能组成三角形的话，输出YES，否则NO。
*/
#include<stdio.h>
int main(){
    int r;double m,n,t;//题目中是正数，并没有指定是整数！！！
    scanf("%d",&r);
    while(r--&&scanf("%lf%lf%lf",&m,&n,&t)){
        if(m+n>t&&m+t>n&&t+n>m)
        printf("YES\n");
        else
        printf("NO\n");
    }
    return 0;
}
