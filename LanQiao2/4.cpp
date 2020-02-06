/*问题描述
有一棵 n 个节点的树，树上每个节点都有一个正整数权值。如果一个点被选择了，那么在树上和它相邻的点都不能被选择。求选出的点的权值和最大是多少？

输入格式
第一行包含一个整数 n 。
接下来的一行包含 n 个正整数，第 i 个正整数代表点 i 的权值。
接下来一共 n-1 行，每行描述树上的一条边。

输出格式
输出一个整数，代表选出的点的权值和的最大值。
样例输入
5
1 2 3 4 5
1 2
1 3
2 4
2 5
样例输出
12
样例说明
选择3、4、5号点，权值和为 3+4+5 = 12 。
数据规模与约定
对于20%的数据， n <= 20。
对于50%的数据， n <= 1000。
对于100%的数据， n <= 100000。
权值均为不超过1000的正整数。
http://lx.lanqiao.cn/problem.page?gpid=T14
*/
#include <stdio.h>
#include <string.h>
#define _Max 100010
#define max(a, b) a > b ? a : b

struct point
{
    int v, next;   //v指向这条边的另一个结点（父结点），next指向子结点
} edge[_Max * 2];  //一条边记录两次，分别以一个点做记录

int head[_Max];
int M;
int dp[_Max][2];

//添加一个边
void addEdge(int from, int to)
{
    //from结点
    edge[M].v = to;
    edge[M].next = head[from];    //为-1则定位叶结点，否则，指向另外一条边
    head[from] = M++;             //指向他的一条边，增加结点
    //to结点
    edge[M].v = from;
    edge[M].next = head[to];      //为-1则定位叶结点，否则，指向另外一条边
    head[to] = M++;               //指向他的一条边，增加结点
    return ;
}

//深度遍历，先深入到叶子结点，然后一层一层往上回升，一直到根结点，即第一个结点（初始pre为－1是因为根结点没有父结点，用－1表示）
void dfs(int x, int pre)
{
    int i = head[x], v;
    for (; i != -1; i = edge[i].next)  //i != -1说明有子结点，则遍历子结点，否则为叶子结点
    {
        v = edge[i].v;
        if (pre == v)  //如果指向的子结点和父结点重合，则说明这个结点是叶子结点，不需要进一步dp
        {
            continue;
        }
        dfs(v, x);     //x可以理解为父结点
        //深度遍历到最里面的叶子结点的父结点   如果父结点选择，则子结点不选择，否则子结点可能选择或者不选择，但是要比较两者哪个大选择哪个
        dp[x][1] += dp[v][0];                   //   父结点（选） ＋＝ 子结点（不选）
        dp[x][0] += max(dp[v][0], dp[v][1]);    //   父结点（不选） ＋＝ max（子结点（不选），子结点（选））
    }
    return ;
}
int main(int argc, const char * argv[])
{
    int i, n, s, t, tmp;
    scanf("%d", &n);
    M = 0;
    memset(head, -1, sizeof(head));   //初始化每个结点都是独立的没有子结点
    memset(dp, 0, sizeof(dp));
    //输入权值，并且记录在dp[i][1]上，i表示第i个结点，1代表取了这个结点
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &dp[i][1]);
    }
    //输入边，并且添加edge，一个边添加两个edge
    for (i = 1; i < n; i++)
    {
        scanf("%d %d", &s, &t);
        addEdge(s, t);
    }
    dfs(1, -1);   //深度优先遍历，从第一个结点开始遍历
    tmp = max(dp[1][0], dp[1][1]);    //求出最大的权值和
    printf("%d\n", tmp);
    return 0;
}