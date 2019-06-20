//2005
//Problem Description
//给定一个日期，输出这个日期是该年的第几天。
//Input
//输入数据有多组，每组占一行，数据格式为YYYY/MM/DD组成，具体参见sample input ,另外，可以向你确保所有的输入数据是合法的。
//Output
//对于每组输入数据，输出一行，表示该日期是该年的第几天。
#include<stdio.h>
int main()
{
	int year,month,day;
	int days;
	const int months[13]={-1,31,28,31,30,31,30,31,31,30,31,30,31};
	while(scanf("%d/%d/%d",&year,&month,&day)==3)
	{
		days=0;
		if((year%400==0||(year%4==0&&year%100!=0))&&month>2)
			days++;
		while(--month>0)
			days+=months[month];
		days+=day;
		printf("%d\n",days);
	}
	return 0;
}
