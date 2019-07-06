/*Problem Description
假设一个班有n(n<=50)个学生，每人考m(m<=5)门课，求每个学生的平均成绩和每门课的平均成绩，并输出各科成绩均大于等于平均成绩的学生数量。
Input
输入数据有多个测试实例，每个测试实例的第一行包括两个整数n和m，分别表示学生数和课程数。然后是n行数据，每行包括m个整数（即：考试分数）。
Output
对于每个测试实例，输出3行数据，第一行包含n个数据，表示n个学生的平均成绩，结果保留两位小数；第二行包含m个数据，表示m门课的平均成绩，结果保留两位小数；第三行是一个整数，表示该班级中各科成绩均大于等于平均成绩的学生数量。
每个测试实例后面跟一个空行。
*/
#include<stdio.h>
#include<string.h>
int main(){
    int n,m,tmp,big;
    double xszf[50],kmzf[5];
    while(scanf("%d%d",&n,&m)==2){
        big=0;
        memset(kmzf,0,sizeof(kmzf));
        memset(xszf,0,sizeof(xszf));
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                scanf("%d",tmp);
                kmzf[j]+=tmp;
                xszf[i]+=tmp; 
           }
        }
        for(int i=0;i<n;i++){
            printf("%d ",xszf[i]/m);
        }
        printf("\n");
        for(int i=0;i<m;i++){
            printf("%d ",kmzf[i]/n);
        }
        printf("\n%d\n",dig);
    }
    return 0;
}