/*Problem Description
我们看到过很多直线分割平面的题目，今天的这个题目稍微有些变化，我们要求的是n条折线分割平面的最大数目。比如，一条折线可以将平面分成两部分，两条折线最多可以将平面分成7部分，具体如下所示。
Input
输入数据的第一行是一个整数C,表示测试实例的个数，然后是C 行数据，每行包含一个整数n(0<n<=10000),表示折线的数量。
Output
对于每个测试实例，请输出平面的最大分割数，每个实例的输出占一行。
http://acm.hdu.edu.cn/showproblem.php?pid=2050
*/
#include<iostream>
using namespace std;
long long a[10001]={1,2,7};
int main()
{
    int n;
    cin>>n;
    for(int i=3;i<10001;i++)
        a[i]=a[i-1]+4*(i-1)+1;
    while(n--)
    {
        int b;
        cin>>b;
        cout<<a[b]<<endl;
    }
    return 0;
}