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
    int n,m,pass;
    int a[50][5],p[50];
    double x[5],y[50];
    while(scanf("%d%d",&n,&m)==2){
        memset(x,0,sizeof(x));
        memset(y,0,sizeof(y));
        memset(p,0,sizeof(p));
        pass=0;
        for(int i=0;i<n;i++){//i<=n
            for(int j=0;j<m;j++){//j<=m
                scanf("%d",&a[i][j]);
                y[i]+=a[i][j];
                x[j]+=a[i][j];
            }
            if(i<n-1){
                printf("%.2f ",y[i]/m);
            }else{
                printf("%.2f\n",y[i]/m);
            }
        }
        for(int i=0;i<m;i++){//i<m
            x[i]/=n;
            if(i<m-1){
                printf("%.2f ",x[i]);
            }else{
                printf("%.2f\n",x[i]);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j]>=x[j]){
                    p[i]++;
                }
            }
            if(p[i]==m){
                pass++;
            }
        }
        printf("%d\n\n",pass);
    }
    return 0;
}