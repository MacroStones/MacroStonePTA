/*
迎着一面矩形的大旗一刀斩下，如果你的刀够快的话，这笔直一刀可以切出两块多边形的残片。反过来说，如果有人拿着两块残片来吹牛，说这是自己迎风一刀斩落的，你能检查一下这是不是真的吗？
注意摆在你面前的两个多边形可不一定是端端正正摆好的，它们可能被平移、被旋转（逆时针90度、180度、或270度），或者被（镜像）翻面。
这里假设原始大旗的四边都与坐标轴是平行的。

输入格式：
输入第一行给出一个正整数N（≤20），随后给出N对多边形。每个多边形按下列格式给出：
其中k（2<k≤10）是多边形顶点个数；

注意：题目保证没有多余顶点。即每个多边形的顶点都是不重复的，任意3个相邻顶点不共线。

输出格式：
对每一对多边形，输出YES或者NO。
*/

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <algorithm>
using namespace std;
struct form{
    int vertexs;
    int x[10],y[10];
    bool right[10];
}a,b;
bool rightAngle(int ax,int ay,int bx,int by){
    if(ax*bx+ay*by==0){
        return true;
    }else{
        return false;
    }
}
void findRightSide(form a){
    for(int i=0;i<a.vertexs;i++){
        int ax=a.x[(i+1)%a.vertexs]-a.x[i];
        int ay=a.y[(i+1)%a.vertexs]-a.y[i];
        int bx=a.x[(i-1+a.vertexs)%a.vertexs]-a.x[i];
        int by=a.y[(i-1+a.vertexs)%a.vertexs]-a.y[i];
        a.right[i]=rightAngle(ax,ay,bx,by);
    }
}
int main(){
    int n;
    for(int i=0;i<n;i++){
        scanf("%d",&a.vertexs);
        for(int j=0;j<a.vertexs;i++){
            scanf("%d%d",a.x+i,a.y+i);
        }
        scanf("%d",&b.vertexs);
        for(int j=0;j<b.vertexs;i++){
            scanf("%d%d",b.x+i,b.y+i);
        }
        if(a.vertexs+b.vertexs!=8){
            printf("NO\n");
        }else{
            //?
        }
    }
    return 0;
}