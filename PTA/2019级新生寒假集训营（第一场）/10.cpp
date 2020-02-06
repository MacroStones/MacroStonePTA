/*
给定一棵二叉树的后序遍历和中序遍历，请你输出其层序遍历的序列。这里假设键值都是互不相等的正整数。

输入格式：
输入第一行给出一个正整数N（≤30），是二叉树中结点的个数。第二行给出其后序遍历序列。第三行给出其中序遍历序列。数字间以空格分隔。

输出格式：
在一行中输出该树的层序遍历的序列。数字间以1个空格分隔，行首尾不得有多余空格。
*/

#include<stdio.h>
const int N=32;
int LRD[N];
int LDR[N];
int tree[1073741824];
void buildTree(int lrd,int ldr,int n,int root){
    if(n==0)
        return;
    tree[root]=LRD[lrd+n-1];
    if(n==1)
        return;
    int i;
    for(i=0;i<n;i++)
        if(LDR[ldr+i]==tree[root])
            break;
    buildTree(lrd,ldr,i,root*2+1);
    buildTree(lrd+i,ldr+i+1,n-i-1,root*2+2);
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",LRD+i);
    }
    for(int i=0;i<n;i++){
        scanf("%d",LDR+i);
    }
    buildTree(0,0,n,0);
    int j=1;
    printf("%d",tree[0]);
    for(int i=1;j<n;i++){
        if(tree[i]!=0){
            printf(" %d",tree[i]);
            j++;
        }
    }
    return 0;
}