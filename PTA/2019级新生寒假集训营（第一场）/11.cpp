/*
给定每个人的家庭成员和其自己名下的房产，请你统计出每个家庭的人口数、人均房产面积及房产套数。

输入格式：
输入第一行给出一个正整数N（≤1000），随后N行，每行按下列格式给出一个人的房产：

编号 父 母 k 孩子1 ... 孩子k 房产套数 总面积

其中编号是每个人独有的一个4位数的编号；父和母分别是该编号对应的这个人的父母的编号（如果已经过世，则显示-1）；k（0≤k≤5）是该人的子女的个数；孩子i是其子女的编号。

输出格式：
首先在第一行输出家庭个数（所有有亲属关系的人都属于同一个家庭）。随后按下列格式输出每个家庭的信息：

家庭成员的最小编号 家庭人口数 人均房产套数 人均房产面积

其中人均值要求保留小数点后3位。家庭信息首先按人均面积降序输出，若有并列，则按成员编号的升序输出。
*/

#include<bits/stdc++.h>
using namespace std;

struct data{
    int id,fa,ma,k,num,area;
    int ch[6];
}a[1005];

struct node{
    int idm,pp,flag;
    double num,area;
}fam[10005];

int root[10005],vis[10005],n,res;

int getr(int k){
    if(root[k]==k) return k;
    else return root[k]=getr(root[k]);
}

void Union(int x,int y){
    int xr=getr(x),yr=getr(y);
    if(xr<yr)
        root[yr]=xr;
    else
        root[xr]=yr;
}

bool cmp(node xx,node yy){
    if(xx.area==yy.area)
        return xx.idm<yy.idm;
    else
        return xx.area>yy.area;
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<10000;++i)
        root[i]=i;
    for(int i=0;i<n;++i){
        scanf("%d%d%d%d",&a[i].id,&a[i].fa,&a[i].ma,&a[i].k);
        for(int j=0;j<a[i].k;++j)
            scanf("%d",&a[i].ch[j]);
        scanf("%d%d",&a[i].num,&a[i].area);
        vis[a[i].id]=1;
        if(a[i].fa!=-1)
            vis[a[i].fa]=1,Union(a[i].id,a[i].fa);
        if(a[i].ma!=-1)
            vis[a[i].ma]=1,Union(a[i].id,a[i].ma);
        for(int j=0;j<a[i].k;++j)
            vis[a[i].ch[j]]=1,Union(a[i].id,a[i].ch[j]);
    }    
    for(int i=0;i<n;++i){
        int idr=getr(a[i].id);
        fam[idr].idm=idr;
        fam[idr].num+=a[i].num;
        fam[idr].area+=a[i].area;
        fam[idr].flag=1;
    }
    for(int i=0;i<10000;++i){
        if(vis[i]) ++fam[getr(i)].pp;
        if(fam[i].flag) ++res;
    }
    for(int i=0;i<10000;++i)
        if(fam[i].flag){
            fam[i].num=fam[i].num*1.0/(fam[i].pp*1.0);
            fam[i].area=fam[i].area*1.0/(fam[i].pp*1.0);
        }
    sort(fam,fam+10000,cmp);
    printf("%d\n",res);
    for(int i=0;i<res;++i)
        printf("%04d %d %.3f %.3f\n",fam[i].idm,fam[i].pp,fam[i].num,fam[i].area);
    return 0;
}