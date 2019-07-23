/*Problem Description
有一楼梯共M级，刚开始时你在第一级，若每次只能跨上一级或二级，要走上第M级，共有多少种走法？
Input
输入数据首先包含一个整数N，表示测试实例的个数，然后是N行数据，每行包含一个整数M（1<=M<=40）,表示楼梯的级数。
Output
对于每个测试实例，请输出不同走法的数量
#include<stdio.h>
int ans=0;
int diguei(int n){
    if(n<=1){
        ans++;
        return 0;
    }
    diguei(n-1);
    diguei(n-2);
}
int main(){
    int n,m;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&m);
        ans=0;
        diguei(m);
        printf("%d\n",ans);
    }
    return 0;
}*/
#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		int m;
		scanf("%d",&m);
		int a = 1,b = 1, x = 1;
		for(int i=2;i<m;i++){
			x = a + b;
			b = a;
			a = x;
		}
		printf("%d\n", x);
	}

	return 0;
}