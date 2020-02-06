#include<stdio.h>
#include<math.h>
int abs(int x)
{
	if(x<0)
		return -x;
	else
		return x;
}
int main()
{
	int n,r;
	int s[20];
	int m;
	while(scanf("%d %d",&n,&r)!=EOF)
	{
		if(r>=2 && r<=16)
		{
				int i=0;
				m = abs(n);
				int t=(m/r);
				int k=(m%r);
				while(t>0)
				{
					s[i]=k;
					k = (t%r);
					t = (t/r);
					i++;
				}
				if(t==0)
					s[i]=k;
				if(n<0)
					printf("-");
				for(int k=i;k>0;k--)
				{
					if(s[k]>=10)
						printf("%c",(char)(s[k]+55));
					else
						printf("%d",s[k]);
				}
				if(s[0]>=10)
					printf("%c\n",(char)(s[0]+55));
				else
					printf("%d\n",s[0]);
				
		}
	}
	return 0;
}