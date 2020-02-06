/*问题描述
考虑聚合An = {1,2，...，n}。例如，A1 = {1}，A3 = {1,2,3}。子集序列被定义为非空子集的阵列。在词典编排顺序中对An的所有子集序列进行排序。你的任务是找到第m个。

输入
输入包含几个测试用例。每个测试用例由两个数字n和m组成（0 <n <= 20,0 <m <= An的子集序列的总数）。

产量
对于每个测试用例，您应该在一行中输出An的第m个子集序列。

样本输入
1 1
2 1
2 2
2 3
2 4
3 10

样本输出
1
1
1 2
2
2 1
2 3 1
*/
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int main(){
    vector<int> lest;
    long long int t[21]={0,1,4},m;
    for(int i=3; i<20; ++i)
        t[i]=i*(t[i-1]+1);
    int n,k;//k记录当前位
    while(cin>>n>>m){
        lest.clear();
        for(int i=1; i<=n; ++i) lest.push_back(i);//存放还剩下的数字
        while(n--){
            k=(m-1)/(t[n]+1);
            cout<<lest[k];
            lest.erase(lest.begin()+k);
            m=(m-1)%(t[n]+1);
            if(m==0) break;
            else cout<<' ';
        }
        cout<<endl;
    }
    return 0;
}