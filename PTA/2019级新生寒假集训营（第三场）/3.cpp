/*
本题的目标很简单，就是判断一个给定的正整数是否素数。

输入格式：
输入在第一行给出一个正整数N（≤ 10），随后N行，每行给出一个小于2
​31
​​ 的需要判断的正整数。

输出格式：
对每个需要判断的正整数，如果它是素数，则在一行中输出Yes，否则输出No。
*/


#include<stdio.h>
#include<string.h>
#include<math.h>
int isPrime(int n) {
	int i, limit, flag = 1;
	if(n <= 1)
		flag = 0;
	else if(n == 2)
		flag = 1;
	else if(n % 2 == 0)
		flag = 0;
	else {
		limit = sqrt(n) + 1;
		for(i = 3; i <= limit; i += 2) {
			if(n % i == 0) {
				flag = 0;
				break;
			}
		}
	}
	return flag;
}
int main()
{
	int a[10000];
	int i,j,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		if(isPrime(a[i]))
		{
			printf("Yes\n");
		 } 
		 else
		 {
		 	printf("No\n");
		 }
	}
 }