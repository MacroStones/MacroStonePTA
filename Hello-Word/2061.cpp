/*问题描述
背景
新学期开始，HDU也迎来了50岁生日。无论你的专业是什么，我唯一想告诉你的是：“珍惜大学生活，抓住时间。” 大多数人认为大学生活应该丰富多彩，压力较小。但实际上，大学生活也很繁忙。如果你想掌握从书中学到的知识，那么大量的闲暇时间应该花在个人学习和练习上，尤其是后者。我认为你们每个人都应该像在高中时一样学习。
“没有痛苦，没有收获”，HDU也有奖学金，谁能赢得它？这主要取决于学生的GPA（平均成绩）。现在，我要告诉你规则，
如果有K（K> 0）课程，第i个课程有学分Ci，你的分数为Si，那么结果GPA是
GPA =（C1 * S1 + C2 * S2 + ...... + Ci * Si ......） /（C1 + C2 + ...... + Ci ......）（1 <= i <= K，Ci！= 0）
如果存在0 <= Si <60，则GPA始终不存在。

输入
第一个数字N表示有N个测试用例（N <= 50）。在每种情况下，都有一个数字K（总课程数），然后是K行，每一行都遵循以下格式：课程名称（长度<= 30），学分（<= 10），分数（<= 100 ）。
注意：课程名称中没有空白。所有输入都是合法的

产量
如上所述输出每个案例的GPA，如果GPA不存在，则输出：“抱歉！”，否则只输出GPA值，该值四舍五入到小数点后的2位数。两个测试用例之间有一个空行。 

Sample Input
2
3
Algorithm 3 97
DataStruct 3 90
softwareProject 4 85
2
Database 4 59
English 4 81
 
Sample Output
90.10

Sorry!
*/
#include<stdio.h>
float sum,sumc;
bool flag;
int main(){
    int N;
    scanf("%d",&N);
    while(N--){
        sum=0;
        sumc=0;
        flag=false;
        int K;
        scanf("%d",&K);
        while(K--){
            float C,S;
            scanf("%*s%f%f",&C,&S);
            //printf("%d %d\n",C,S);
            flag=flag||S<60;
            sum+=C*S;
            sumc+=C;
        }
        if(flag)
            printf("Sorry!\n");
        else
            printf("%.2f\n",sum/sumc);
        if(N)
			printf("\n");
    }
    return 0;
}