/*Problem Description
输入一个十进制数N，将它转换成R进制数输出。
Input
输入数据包含多个测试实例，每个测试实例包含两个整数N(32位整数)和R（2<=R<=16, R<>10）。
Output
为每个测试实例输出转换后的数，每个输出占一行。如果R大于10，则对应的数字规则参考16进制（比如，10用A表示，等等）。
*/
#include<stdio.h>
int abs(int x){
	if(x<0)
		return -x;
	else
		return x;
}
int main(){
	int n,r;
	int s[20];
	int m;
	while(scanf("%d %d",&n,&r)!=EOF){
		int i=0;
		m = abs(n);
		int t=(m/r);
		int k=(m%r);
		while(t>0){
			s[i]=k;
			k = (t%r);
    		t = (t/r);
			i++;
		}
    	if(t==0)
			s[i]=k;
		if(n<0)
			printf("-");
		for(int k=i;k>0;k--){
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
	return 0;
}