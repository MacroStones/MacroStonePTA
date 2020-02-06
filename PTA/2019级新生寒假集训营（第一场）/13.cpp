/*
在诊断肿瘤疾病时，计算肿瘤体积是很重要的一环。给定病灶扫描切片中标注出的疑似肿瘤区域，请你计算肿瘤的体积。

输入格式：
输入第一行给出4个正整数：M、N、L、T，其中M和N是每张切片的尺寸（即每张切片是一个M×N的像素矩阵。最大分辨率是1286×128）；L（≤60）是切片的张数；T是一个整数阈值（若疑似肿瘤的连通体体积小于T，则该小块忽略不计）。

最后给出L张切片。每张用一个由0和1组成的M×N的矩阵表示，其中1表示疑似肿瘤的像素，0表示正常像素。由于切片厚度可以认为是一个常数，于是我们只要数连通体中1的个数就可以得到体积了。麻烦的是，可能存在多个肿瘤，这时我们只统计那些体积不小于T的。两个像素被认为是“连通的”，如果它们有一个共同的切面，如下图所示，所有6个红色的像素都与蓝色的像素连通。

输出格式：
在一行中输出肿瘤的总体积。
*/

#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int dz[6]={0,0,0,0,-1,1},dx[6]={-1,0,1,0,0,0},dy[6]={0,-1,0,1,0,0};
int a[65][1300][130];
int m,n,l,t;
struct zxy{
    int z,x,y;
    zxy(int a,int b,int c):z(a),x(b),y(c){}
};
void bfs(int z,int x,int y,int &num){
    queue<zxy> Q;
    Q.push(zxy(z,x,y));
    while(!Q.empty()){
        zxy p=Q.front(); Q.pop();
        for(int i=0;i<6;i++){
            int nz=p.z+dz[i],nx=p.x+dx[i],ny=p.y+dy[i];
            if(nz>=0&&nz<l && nx>=0&&nx<m && ny>=0&&ny<n && a[nz][nx][ny]==1){
                num++; 
                Q.push(zxy(nz,nx,ny));
                a[nz][nx][ny]=0;
            }
        }
    }
    return;
}
int main(){
    int count=0;
    cin>>m>>n>>l>>t;
    for(int i=0;i<l;i++)
        for(int j=0;j<m;j++)
            for(int k=0;k<n;k++)
                cin>>a[i][j][k];
    for(int i=0;i<l;i++)
        for(int j=0;j<m;j++)
            for(int k=0;k<n;k++){
                int num=0;
                if(a[i][j][k]==1){
                    num=1;
                    a[i][j][k]=0;
                    bfs(i,j,k,num);
                } 
                if(num>=t) count+=num;
            }
    cout<<count;
    return 0;
}