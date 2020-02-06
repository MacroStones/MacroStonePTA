/*问题描述
如果一个自然数N的K进制表示中任意的相邻的两位都不是相邻的数字，那么我们就说这个数是K好数。求L位K进制数中K好数的数目。例如K = 4，L = 2的时候，所有K好数为11、13、20、22、30、31、33 共7个。由于这个数目很大，请你输出它对1000000007取模后的值。

输入格式
输入包含两个正整数，K和L。

输出格式
输出一个整数，表示答案对1000000007取模后的值。
样例输入
4 2
样例输出
7
数据规模与约定
对于30%的数据，KL <= 106；
对于50%的数据，K <= 16， L <= 10；
对于100%的数据，1 <= K,L <= 100。
http://lx.lanqiao.cn/problem.page?gpid=T13
*/
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int K,L;
    int op[102][102];
    long long int sum=0;
    cin>>K>>L;
    memset(op,0,sizeof(op));            //初始化数组，我就是因为这个才又错了一遍
    for(int i=0;i<K;i++){            //初始化
        op[1][i]=1;
    }
    for(int i=2;i<=L;i++){            //每一位的情况
        for(int h=0;h<K;h++){                  //这一位上数字的所有情况
            for(int g=0;g<K;g++){                   //后一位数字所有情况
                if(g!=h+1&&g!=h-1){
                    op[i][h]+=op[i-1][g];            //如果放在前面的h和原第一位的g符合要求，则加入
                    op[i][h]=op[i][h]%1000000007;
                }
            }
        }
    }
    for(int i=1;i<K;i++){
        sum+=op[L][i];
        sum=sum%1000000007;
    }
    cout<<sum<<endl;

}