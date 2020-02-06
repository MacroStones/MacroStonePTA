/*
给定两个整数集合，它们的相似度定义为：Nc/N​t×100%。其中Nc是两个集合都有的不相等整数的个数，Nt是两个集合一共有的不相等整数的个数。你的任务就是计算任意一对给定集合的相似度。

输入格式：
输入第一行给出一个正整数N（≤50），是集合的个数。随后N行，每行对应一个集合。每个集合首先给出一个正整数M（≤10​4），是集合中元素的个数；然后跟M个[0,10​9]区间内的整数。

之后一行给出一个正整数K（≤2000），随后K行，每行对应一对需要计算相似度的集合的编号（集合从1到N编号）。数字间以空格分隔。

输出格式：
对每一对需要计算的集合，在一行中输出它们的相似度，为保留小数点后2位的百分比数字。
*/

#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<set>
const int N=55;
int main(){
    int n,m;
    scanf("%d",&n);
    std::set<int> s[N];
    for(int i=1;i<=n;i++){
        scanf("%d",&m);
        for(int j=0;j<m;j++){
            int x;
            scanf("%d",&x);
            s[i].insert(x);
        }
    }
    int t;
    scanf("%d",&t);
    while(t--){
        int x,y;
        scanf("%d%d",&x,&y);
        std::set<int>res;
        std::set_intersection(s[x].begin(),s[x].end(),s[y].begin(),s[y].end(),inserter(res,res.begin()));
        int nc=res.size();
        int nt=s[x].size()+s[y].size()-res.size();
        printf("%.2f%%\n",100.0*nc/nt);
    }
    return 0;
}