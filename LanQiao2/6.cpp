/*问题描述
Farmer John变得非常懒，他不想再继续维护供奶牛之间供通行的道路。
道路被用来连接N个牧场，牧场被连续地编号为1到N。每一个牧场都是一个奶牛的家。
FJ计划除去P条道路中尽可能多的道路，但是还要保持牧场之间 的连通性。
你首先要决定那些道路是需要保留的N-1条道路。
第j条双向道路连接了牧场Sj和Ej(1 <= Sj <= N; 1 <= Ej <= N; Sj != Ej)，而且走完它需要Lj的时间。
没有两个牧场是被一条以上的道路所连接。奶牛们非常伤心，因为她们的交通系统被削减了。
你需要到每一个奶牛的住处去安慰她们。每次你到达第i个牧场的时候(即使你已经到过)，你必须花去Ci的时间和奶牛交谈。
你每个晚上都会在同一个牧场(这是供你选择的)过夜，直到奶牛们都从悲伤中缓过神来。在早上 起来和晚上回去睡觉的时候，你都需要和在你睡觉的牧场的奶牛交谈一次。
这样你才能完成你的 交谈任务。假设Farmer John采纳了你的建议，请计算出使所有奶牛都被安慰的最少时间。

输入格式
第1行包含两个整数N和P。

接下来N行，每行包含一个整数Ci。

接下来P行，每行包含三个整数Sj, Ej和Lj。

输出格式
输出一个整数, 所需要的总时间(包含和在你所在的牧场的奶牛的两次谈话时间)。
样例输入
5 7
10
10
20
6
30
1 2 5
2 3 5
2 4 12
3 4 17
2 5 15
3 5 6
样例输出
176
数据规模与约定
5 <= N <= 10000，N-1 <= P <= 100000，0 <= Lj <= 1000，1 <= Ci <= 1,000。
http://lx.lanqiao.cn/problem.page?gpid=T16
*/
#include<stdio.h>
#include<algorithm>
using namespace std;
int talk[100010],x[100010];
const int vv = 1<<30; 
struct node{
	int start,end,w;
}a[101000];
 
bool cmp(node a,node b){
	return a.w<b.w;
}
/*
int find(int k){
	if(x[k]!=k)
		k=find(x[k]);//每次都要用递归 
	return k;
}
*///这样写的话超时 
/*
int find(int k){
	while(x[k]!=k)
		k=x[x[k]]; 
	return k;
}//这样写的话900多ms险过 
*/
int find(int k)
{
    if(x[k]==k)
    return k;
    int t = find(x[k]);
    x[k] = t;//不同点在于这一步，当找到k点的祖先时，就把这个祖先存到x数组中，下次再找就会减少递归次数 
    return t;
}//这样140多ms， 
int main(){
	int n,p,sum=0,i,k=vv;
	scanf("%d%d",&n,&p);
	for(i=1;i<=n;i++){
		scanf("%d",&talk[i]);
		x[i]=i;
		k=min(k,talk[i]);
	}
	for(i=1;i<=p;i++){
		scanf("%d%d%d",&a[i].start,&a[i].end,&a[i].w);
		a[i].w=2*a[i].w+talk[a[i].start]+talk[a[i].end];
	}
	sort(a+1,a+p+1,cmp);
	for(i=1;i<=p;i++){
		int g=find(a[i].start);
		int v=find(a[i].end);
		if(g!=v){
			sum+=a[i].w;
			x[g]=v;
		}	
	}
	printf("%d\n",sum+k);
	return 0;
}
