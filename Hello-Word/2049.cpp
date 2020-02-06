/*Problem Description
国庆期间,省城HZ刚刚举行了一场盛大的集体婚礼,为了使婚礼进行的丰富一些,司仪临时想出了有一个有意思的节目,叫做"考新郎",具体的操作是这样的:
首先,给每位新娘打扮得几乎一模一样,并盖上大大的红盖头随机坐成一排;
然后,让各位新郎寻找自己的新娘.每人只准找一个,并且不允许多人找一个.
最后,揭开盖头,如果找错了对象就要当众跪搓衣板...
看来做新郎也不是容易的事情...
假设一共有N对新婚夫妇,其中有M个新郎找错了新娘,求发生这种情况一共有多少种可能.
Input
输入数据的第一行是一个整数C,表示测试实例的个数，然后是C行数据，每行包含两个整数N和M(1<M<=N<=20)。
Output
对于每个测试实例，请输出一共有多少种发生这种情况的可能，每个实例的输出占一行。
http://acm.hdu.edu.cn/showproblem.php?pid=2049
*/
/*3.错排数
n个有序的元素应有n ！种不同的排列。如若一个排列式的所有的元素都不在原来的位置上，则称这个排列为错排。
证明：假设有n封信，第一封信可放在(2-n)的任一个信封里，共n-1种放法，设第一封信放在了第k个信封里，
若此时第k封信放在了第1个信封里，则只要将剩下的n-2错排，即f(n-2)，
若第k封信没有放在了第1个信封里，可将第1封信的位置看成是“第k个位置”，即将n-1封信错排，即为f(n-1)
M(1)=0,M(2)=1  M(n)=(n-1)[M(n-2)+M(n-1)]
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int mod=1e9+7;
const int maxn=1e6+5;
int T, n, m;
LL M[22];
void init()
{
  M[1] = 0;
  M[2] = 1;
  for(int i = 3; i < 22; i++){
    M[i] = (i-1)*(M[i-1]+M[i-2]);
  }
}
LL C(LL n,LL m)
{
    LL p = 1;
    for(int i = n-m+1; i <= n; i++) p*=i;
    for(int i = 1; i <= m; i++) p/=i;
    return p;
}
int main()
{
    init();
    cin>>T;
    while(T--)
    {
        scanf("%d%d",&n,&m);
        printf("%lld\n",C(n,m)*M[m]);
    }
    return 0;
}