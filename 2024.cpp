/*Problem Description
输入一个字符串，判断其是否是C的合法标识符。
Input
输入数据包含多个测试实例，数据的第一行是一个整数n,表示测试实例的个数，然后是n行输入数据，每行是一个长度不超过50的字符串。
Output
对于每组输入数据，输出一行。如果输入数据是C的合法标识符，则输出"yes"，否则，输出“no”。
*/
#include"stdio.h"
#include"string.h" 
int main()
{
	int i,n,len,flag;
	char array[50];
	scanf("%d",&n);
	getchar();
	while(n--){
		flag = 0;
		gets(array);  // scanf断空格、回车，gets断回车 
		len = strlen(array);
		for (i = 0;i < len;i++){
			if(array[i] == ' ')
				flag++;
		}
		if (flag != 0) 	printf("no\n");
		else if('A' <= array[0] && array[0] <= 'Z'|| 'a' <= array[0] && array[0] <= 'z' || array[0] == '_'){
			for(i=1;i<len;i++){
					if('A' <= array[i] && array[i] <= 'Z' || 'a' <= array[i] && array[i] <= 'z' || array[i] == '_' || 48 <= array[i] && array[i] <= 57)
						continue;  // 合法标识符即为第一位只能为字母或者下划线，剩下的只能为字母、数字下滑线 
					else break;
				}
			if(i == len)
				printf("yes\n");
			else
				printf("no\n");
		}
		else
			printf("no\n"); 
	}	
	return 0;
 }