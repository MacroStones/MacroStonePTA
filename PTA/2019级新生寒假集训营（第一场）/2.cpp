/*
本题要求将输入的任意3个整数从小到大输出。

输入格式:
输入在一行中给出3个整数，其间以空格分隔。

输出格式:
在一行中将3个整数从小到大输出，其间以“->”相连。
*/

#include <stdio.h>
int main()
{
    int a,b,c;
    int num[3]={0};
    int temp;
    for(int i=0;i<3;i++){
        scanf("%d",&num[i]);
    }
    for(int i=0;i<2;i++){
        for(int j=0;j<2-i;j++){
            if(num[j]>num[j+1]){
                temp=num[j];
                num[j]=num[j+1];
                num[j+1]=temp;
            }
        }
    }
    printf("%d->%d->%d\n",num[0],num[1],num[2]);
    return 0;
}