/*Problem Description
在2×n的一个长方形方格中,用一个1× 2的骨牌铺满方格,输入n ,输出铺放方案的总数.
例如n=3时,为2× 3方格，骨牌的铺放方案有三种
Input
输入数据由多行组成，每行包含一个整数n,表示该测试实例的长方形方格的规格是2×n (0<n<=50)。
Output
对于每个测试实例，请输出铺放方案的总数，每个实例的输出占一行。
http://acm.hdu.edu.cn/showproblem.php?pid=2046
*/
#include<stdio.h>
long long m[51];
int n;
int main(){
    while(scanf("%d",&n)==1){
    //1:1 2:2 3:3 4:5 5:8 6:13
        if(m[n]==0){
            m[1]=1;m[2]=2;
            for(int i=3;i<=n;i++){
                m[i]=m[i-1]+m[i-2];
            }
        }
    printf("%lld\n",m[n]);
    }
    return 0;
}