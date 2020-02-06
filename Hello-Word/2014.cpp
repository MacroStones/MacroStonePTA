//Problem Description
//青年歌手大奖赛中，评委会给参赛选手打分。选手得分规则为去掉一个最高分和一个最低分，然后计算平均得分，请编程输出某选手的得分。
//Input
//输入数据有多组，每组占一行，每行的第一个数是n(2<n<=100)，表示评委的人数，然后是n个评委的打分。
//Output
//对于每组输入数据，输出选手的得分，结果保留2位小数，每组输出占一行。
#include<stdio.h>
int main()
{
    int n,tmp,max,min,sum;
    while(scanf("%d",&n)==1)
    {
        max=0;min=100;sum=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&tmp);
            if(max<tmp)
            {
                max=tmp;
            }
            if(min>tmp)
            {
                min=tmp;
            }
            sum+=tmp;
        }
        printf("%.2f\n",((float)(sum-max-min))/(n-2));
    }
    return 0;
}