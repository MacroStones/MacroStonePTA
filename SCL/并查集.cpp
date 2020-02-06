#include "head.h"

int unionFind(int x){
	if(x!=UnionFindSet[x])
	UnionFindSet[x]=find(UnionFindSet[x]);
	return UnionFindSet[x];
}
void unionJoin(int x,int y){
    int fx=find(x);
    int fy=find(y);
    if(fx!=fy){
    UnionFindSet[fx]=fy;}
}