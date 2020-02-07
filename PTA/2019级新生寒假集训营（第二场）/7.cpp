/*
给定一个长度不超过10000的、仅由英文字母构成的字符串。请将字符重新调整顺序，按GPLTGPLT....这样的顺序输出，并忽略其它字符。当然，四种字符（不区分大小写）的个数不一定是一样多的，若某种字符已经输出完，则余下的字符仍按GPLT的顺序打印，直到所有字符都被输出。

输入格式：
输入在一行中给出一个长度不超过10000的、仅由英文字母构成的非空字符串。

输出格式：
在一行中按题目要求输出排序后的字符串。题目保证输出非空。
*/

#include<cstdio>
#include<iostream>
#include<string>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=1e5+10;
 
int main(){
	string t;
	cin>>t;
	int len=t.length(),g=0,p=0,l=0,t1=0;
	for(int i=0;i<len;i++){
		if(t[i]=='G'||t[i]=='g') g++;
		else if(t[i]=='P'||t[i]=='p') p++;
		else if(t[i]=='L'||t[i]=='l') l++;
		else if(t[i]=='T'||t[i]=='t') t1++;
	}
	while(g||p||l||t1){
		if(g){
			printf("G");
			g--;
		}
		if(p){
			printf("P");
			p--;
		}
		if(l){
			printf("L");
			l--;
		}
		if(t1){
			printf("T");
			t1--;
		}
	}
	return 0;
}