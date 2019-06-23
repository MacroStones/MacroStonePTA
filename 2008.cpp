//Problem Description
//统计给定的n个数中，负数、零和正数的个数。
//Input
//输入数据有多组，每组占一行，每行的第一个数是整数n（n<100），表示需要统计的数值的个数，然后是n个[实数]；如果n=0，则表示输入结束，该行不做处理。
//Output
//对于每组输入数据，输出一行a,b和c，分别表示给定的数据中负数、零和正数的个数
#include<stdio.h>
int main()
{
	int n,neg,zero,pos;
	float num;
	while(scanf("%d",&n)==1)
	{
		if(n==0)
			return 0;
		neg=zero=pos=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%f",&num);
			if(num>0)
				pos++;
			else if(num<0)
				neg++;
			else
				zero++;
		}
		printf("%d %d %d\n",neg,zero,pos);
	}
	return 0;
}
