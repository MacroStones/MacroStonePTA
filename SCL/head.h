#ifndef HEAD_H
#define HEAD_H 
#define ll long long
#define MAXN 1024

int qpow(int a,int b);//快速幂

int UnionFindSet[MAXN];
int unionFind(int x);//并查集
void unionJoin(int x);

bool isPrime[100000010];
int Prime[5000010], cnt = 0;
void initPrime(int n);//素数筛

//Prim在稠密图中比Kruskal优，在稀疏图中比Kruskal劣。

#endif