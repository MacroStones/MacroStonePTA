/*Problem Description
统计给定文本文件中汉字的个数。
Input
输入文件首先包含一个整数n，表示测试实例的个数，然后是n段文本。
Output
对于每一段文本，输出其中的汉字的个数，每个测试实例的输出占一行。
[Hint:]从汉字机内码的特点考虑~
*/
#include<stdio.h>
int main(){
    int n;
    char s[1024];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
    	scanf("%s",s);
    	int j=0,a=0;
    	while(s[j]!='\0'){
    		if((s[j]<32)||(s[j]>126)){
    			j++;
    			a++;
    		}
    		j++;
    	}
    	printf("%d\n",a);
    }
    return 0;
}