
#include<stdio.h>      //等差数列的平均值为  （首项+末项）/2
int main()             //即为  （首项+首项+（项数-1）*公差）/2 = 首项+（项数-1）*公差/2
{                      //此题首项设为 2*i 即数列的第i项 , 项数为m , 公差为2
    int n,m;           //平均值为 首项+项数-1  即2*i+m-1
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int k=n/m,a=n%m,first=1;   //有k个能凑满m项的，用a来判断最后是否有剩余的
        for(int i=1;i<=k*m;i=i+m)  //i<=k组*m项，i=i+m项 这里很关键，多体会
        {
           if(first) first=0;      //frist控制空格输出，第一个输出前面没有空格，其它则有
           else printf(" ");
           printf("%d",2*i+m-1);   //输出平均数 2*i+m-1
        }
        if(a) printf(" %dn",n+k*m+1);  //if(a) 判断后面是否有剩余的
        else printf("n");  //平均值为 首项+项数-1 这里的首项为2*(k*m+1) 即第k*m+1项
    }                       //剩余的项数为  n-k*m 
    return 0;               //故最后剩余的平均值为2*(k*m+1)+n-k*m-1=n+k*m+1
}



#include <stdio.h>
int main()
{
	int n,m,i;
	while (~scanf("%d%d",&n,&m))
	{
		for (i=0;i<n/m;i++)  
			printf(i?" %d":"%d",m+1+2*m*i); //确定前面只输出n/m个，故可用
		if (n/m!=(double)n/m)                   //这里不会出现累计误差，故可用
			printf(" %d",n+n/m*m+1);
		puts("");             //puts输出字符串会自动换行 这里相当于printf("\n");
	}
}

//这是出自threadlocal的代码，非常好，我改动了一点点，并注释
//2 4 6,8 10 12,14 16 18,20 22  输入n=11 m=3  输出4 10 16 21
//等差数列的前n项和构成等差数列，即Sm，S2m-Sm，S3m-S2m，…为等差数列，公差为m*m*d即2*m*m
//则Sm，S2m-Sm，S3m-S2m，…的平均值也为等差数列，公差为2*m*m/m==2*m 首项Sm/m=m+1（见顶端）
//即Sm/m  (S2m-Sm)/m  (S3m-S2m)/m  的公式为 m+1+2*m*i
//由于等差数列平均值为 首项+项数-1  剩余部分的首项 2*（n/m*m+1）项数为n-n/m*m
//故剩余的平均值为2*（n/m*m+1）+n-n/m*m-1==n+n/m*m+1  注意 n和m都为int型 n/m要先约了才乘m的