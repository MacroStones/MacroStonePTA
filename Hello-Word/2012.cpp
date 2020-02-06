//Problem Description
//对于表达式n^2+n+41，当n在（x,y）范围内取整数值时（包括x,y）(-39<=x<y<=50)，判定该表达式的值是否都为素数。
//Input
//输入数据有多组，每组占一行，由两个整数x，y组成，当x=0,y=0时，表示输入结束，该行不做处理。
//Output
//对于每个给定范围内的取值，如果表达式的值都为素数，则输出"OK",否则请输出“Sorry”,每组输出占一行。
#include<stdio.h>
bool prime(int k)
{
    for(int i=2;i*i<=k;i++)
        if(k%i==0) 
            return false;
    return true;
}
int main()
{
    int x,y;
    while(true)
    {
        scanf("%d%d",&x,&y);
        if(x==0 && y==0)
        {
            return 0;
        }
        bool flag=true;
        for(int i=x;i<=y;i++)
        {
            if(!prime(i*i+i+41))
            {
                flag=false;
                break;
            }
        }
        if(flag)
            printf("OK\n");
        else
        {
            printf("Sorry\n");
        }
    }
    return 0;
}