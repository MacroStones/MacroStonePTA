/*
“一帮一学习小组”是中小学中常见的学习组织方式，老师把学习成绩靠前的学生跟学习成绩靠后的学生排在一组。本题就请你编写程序帮助老师自动完成这个分配工作，即在得到全班学生的排名后，在当前尚未分组的学生中，将名次最靠前的学生与名次最靠后的异性学生分为一组。

输入格式：
输入第一行给出正偶数N（≤50），即全班学生的人数。此后N行，按照名次从高到低的顺序给出每个学生的性别（0代表女生，1代表男生）和姓名（不超过8个英文字母的非空字符串），其间以1个空格分隔。这里保证本班男女比例是1:1，并且没有并列名次。

输出格式：
每行输出一组两个学生的姓名，其间以1个空格分隔。名次高的学生在前，名次低的学生在后。小组的输出顺序按照前面学生的名次从高到低排列。
*/


#include<stdio.h>
struct node
{
	int sex;
	char name[10];
	int flag;
}data[51];
int main()
{
	int n;
	int count=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d %s",&data[i].sex,&data[i].name);
		data[i].flag=0;
	}
	for(int i=0;i<n/2;i++)
	{
		for(int j=n-1;j>=n/2;j--)
		{
			if((data[i].sex!=data[j].sex)&&data[i].flag==0&&data[j].flag==0)
			{
				data[i].flag =1;
				data[j].flag =1;
				count=count+2;
				printf("%s %s\n",data[i].name ,data[j].name );
			}
		}
		if(count==n)
		break;
	}
}