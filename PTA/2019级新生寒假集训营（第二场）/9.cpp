/*没有人没抢过红包吧…… 这里给出N个人之间互相发红包、抢红包的记录，请你统计一下他们抢红包的收获。

输入格式：
输入第一行给出一个正整数N（≤10
​4
​​ ），即参与发红包和抢红包的总人数，则这些人从1到N编号。随后N行，第i行给出编号为i的人发红包的记录
其中K（0≤K≤20）是发出去的红包个数，Ni是抢到红包的人的编号，P​i（>0）是其抢到的红包金额（以分为单位）。注意：对于同一个人发出的红包，每人最多只能抢1次，不能重复抢。

输出格式：
按照收入金额从高到低的递减顺序输出每个人的编号和收入金额（以元为单位，输出小数点后2位）。每个人的信息占一行，两数字间有1个空格。如果收入金额有并列，则按抢到红包的个数递减输出；如果还有并列，则按个人编号递增输出。
*/

#include<stdio.h>
#include<algorithm>
using namespace std;
int money[10000],times[10000],n,k;
int map[10000];
bool cmp(int a,int b){
    if(money[a]>money[b])
        return true;
    else if(money[a]<money[b])
        return false;
    else{
        if(times[a]>times[b])
            return true;
        else if(times[a]<times[b])
            return false;
        else{
            if(a<b)
                return true;
            else
                return false;
        }
    }
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&k);
        for(int j=0;j<k;j++){
            int ni,pi;
            scanf("%d%d",&ni,&pi);
            times[ni-1]++;
            money[ni-1]+=pi;
            money[i]-=pi;
        }
    }
    for(int i=0;i<n;i++){
        map[i]=i;
    }
    sort(map,map+n,cmp);
    for(int i=0;i<n;i++){
        printf("%d %.2f\n",map[i]+1,money[map[i]]*0.01);
    }
    return 0;
}