//2005
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
