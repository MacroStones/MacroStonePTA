/*
给定一棵二叉树的中序遍历和前序遍历，请你先将树做个镜面反转，再输出反转后的层序遍历的序列。所谓镜面反转，是指将所有非叶结点的左右孩子对换。这里假设键值都是互不相等的正整数。

输入格式：
输入第一行给出一个正整数N（≤30），是二叉树中结点的个数。第二行给出其中序遍历序列。第三行给出其前序遍历序列。数字间以空格分隔。

输出格式：
在一行中输出该树反转后的层序遍历的序列。数字间以1个空格分隔，行首尾不得有多余空格。
*/

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <algorithm>
using namespace std;

struct node
{
    int n;
    node* l;
    node* r;
}*root;
int ldr[30];
int dlr[30];
int n,deep;
void buildTree(int n,int *ldr,int *dlr,node *tree){
    if(n==0){
        tree=NULL;
        return;
    }
    tree = (struct node*)malloc(sizeof(struct node)); 
    tree->n = dlr[0];
    if(n==1){
        tree->l = NULL;
        tree->r = NULL;
        return;
    }
    for(int i=0;i<n;i++){
        if(ldr[i]==dlr[0]){
            buildTree(i,ldr,dlr+1,tree->l);
            buildTree(n-i-1,ldr+i+1,dlr+i+1,tree->r);
            break;
        }
    }
}
void bbfs(int n,node *tree){
    if(tree==NULL)
        return;
    if(n==deep){
        printf("[%d]",&tree->n);
        return;
    }else{
        bbfs(n+1,tree->r);
        bbfs(n+1,tree->l);
    }
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",ldr+i);
    }
    for(int i=0;i<n;i++){
        scanf("%d",dlr+i);
    }
    buildTree(n,ldr,dlr,root);
    //?
    return 0;
}