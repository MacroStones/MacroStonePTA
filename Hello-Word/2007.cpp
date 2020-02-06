//Problem Description
//给定一段连续的整数，求出他们中所有偶数的平方和以及所有奇数的立方和。
//Input
//输入数据包含多组测试实例，每组测试实例包含一行，由两个整数m和n组成。
//Output
//对于每组输入数据，输出一行，应包括两个整数x和y，分别表示该段连续的整数中所有偶数的平方和以及所有奇数的立方和。
//你可以认为32位整数足以保存结果。
#include<stdio.h>
int main()
{
	unsigned int EvenSquareSum,OddCubicSum;
	unsigned int l,r;
	while(scanf("%u%u",&l,&r)==2)
	{
		if(l>r)
        {
            int tmp=l;
            l=r;
            r=tmp;
        }
		EvenSquareSum=0;
		OddCubicSum=0;
		for(unsigned int i=l;i<=r;i++)
		{
			if(i%2==0)
			{
				EvenSquareSum+=i*i;
			}
			else
			{
				OddCubicSum+=i*i*i;
			}
		}
		printf("%u %u\n",EvenSquareSum,OddCubicSum);
	}
	return 0;
}
