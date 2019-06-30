//Problem Description
//输入n(n<100)个数，找出其中最小的数，将它与最前面的数交换后输出这些数。
//Input
//输入数据有多组，每组占一行，每行的开始是一个整数n，表示这个测试实例的数值的个数，跟着就是n个整数。n=0表示输入的结束，不做处理。
//Output
//对于每组输入数据，输出交换后的数列，每组输出占一行。
#include<stdio.h>
int main()
{
    int n,min;
    int m[100];
    while(scanf("%d",&n)==1)
    {
        if(n==0)return 0;
        min=0;m[0]=0x7fffffff;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",m+i);
            if(m[i]<m[min])
                min=i;
        }
        printf("%d",m[min]);
        m[min]=m[1];
        for(int i=2;i<=n;i++)
            printf(" %d",m[i]);
        printf("\n");
    }
    return 0;
}