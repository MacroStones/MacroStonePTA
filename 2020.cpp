/*Problem Description
输入n(n<=100)个整数，按照绝对值从大到小排序后输出。题目保证对于每一个测试实例，所有的数的绝对值都不相等。
Input
输入数据有多组，每组占一行，每行的第一个数字为n,接着是n个整数，n=0表示输入数据的结束，不做处理。 
Output
对于每个测试实例，输出排序后的结果，两个数之间用一个空格隔开。每个测试实例占一行。
*/
#include<stdio.h>
#include<math.h>

int main()
{
	int n,i,j,t;
	int a[100] = { 0 };
	while ((scanf("%d", &n) != EOF) && (n != 0))
	{
		for (i = 0; i < n; i++)
			scanf("%d", &a[i]);
		for (i = 0; i < n-1; i++)
			for (j = 0; j < n - 1 - i; j++)
				if (abs(a[j+1]) > abs(a[j])) { t = a[j+1]; a[j+1] = a[j]; a[j] = t; }
		for (i = 0; i < n - 1; i++)
			printf("%d ", a[i]);
		printf("%d\n", a[n - 1]);
	
	}
	
	getchar();
	return 0;
}