/*Problem Description
There are many lamps in a line. All of them are off at first. A series of operations are carried out on these lamps. On the i-th operation, the lamps whose numbers are the multiple of i change the condition ( on to off and off to on ).
Input
Each test case contains only a number n ( 0< n<= 10^5) in a line.
Output
Output the condition of the n-th lamp after infinity operations ( 0 - off, 1 - on ).
Sample Input
1
5
Sample Output
1
0
Hint
hint
Consider the second test case:
The initial condition	   : 0 0 0 0 0 …
After the first operation  : 1 1 1 1 1 …
After the second operation : 1 0 1 0 1 …
After the third operation  : 1 0 0 0 1 …
After the fourth operation : 1 0 0 1 1 …
After the fifth operation  : 1 0 0 1 0 …
The later operations cannot change the condition of the fifth lamp any more. So the answer is 0.
Author
LL
 */
#include <stdio.h>
#include <math.h>
int main()
{
	int a,b;
	while(scanf("%d",&a)!=EOF){
		b=sqrt(a);
		if(a==b*b){
			printf("1\n");
		}else{
			printf("0\n");
		}
	}
	return 0;
}