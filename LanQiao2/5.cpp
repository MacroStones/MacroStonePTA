/*问题描述
给定一个n个顶点，m条边的有向图（其中某些边权可能为负，但保证没有负环）。请你计算从1号点到其他点的最短路（顶点从1到n编号）。

输入格式
第一行两个整数n, m。
接下来的m行，每行有三个整数u, v, l，表示u到v有一条长度为l的边。

输出格式
共n-1行，第i行表示1号点到i+1号点的最短路。
样例输入
3 3
1 2 -1
2 3 -1
3 1 2
样例输出
-1
-2
数据规模与约定
对于10%的数据，n = 2，m = 2。
对于30%的数据，n <= 5，m <= 10。
对于100%的数据，1 <= n <= 20000，1 <= m <= 200000，-10000 <= l <= 10000，保证从任意顶点都能到达其他所有顶点。
http://lx.lanqiao.cn/problem.page?gpid=T15
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;
const int inf = 1<<30;
const int L = 200000;
struct Edges{
    int x,y,w,next;
} e[L<<2];
int head[L];
int dis[L];
int vis[L];
int cnt[L];
void AddEdge(int x,int y,int w,int k){
    e[k].x = x,e[k].y = y,e[k].w = w,e[k].next = head[x],head[x] = k;
}
int relax(int u,int v,int c){
    if(dis[v]>dis[u]+c){
        dis[v] = dis[u]+c;
        return 1;
    }
    return 0;
}
int SPFA(int src){
    int i;
    memset(cnt,0,sizeof(cnt));
    dis[src] = 0;
    queue<int> Q;
    Q.push(src);
    vis[src] = 1;
    cnt[src]++;
    while(!Q.empty()){
        int u,v;
        u = Q.front();
        Q.pop();
        vis[u] = 0;
        for(i = head[u]; i!=-1; i=e[i].next){
            v = e[i].y;
            if(relax(u,v,e[i].w)==1 && !vis[v]){
                Q.push(v);
                vis[v] = 1;
            }
        }
    }
}
int main(){
    int t,n,m;
    int i,j;
    scanf("%d%d",&n,&m);
    memset(e,-1,sizeof(e));
    for(i = 1; i<=n; i++)
    {
        dis[i] = inf;
        vis[i] = 0;
        head[i] = -1;
    }
    for(i = 0; i<m; i++)
    {
        int x,y,w;
        scanf("%d%d%d",&x,&y,&w);
        AddEdge(x,y,w,i);
    }
    SPFA(1);
    for(i = 2; i<=n; i++)
        printf("%d\n",dis[i]);
    return 0;
}
