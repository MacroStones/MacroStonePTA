/*Problem Description
Give you the width and height of the rectangle,darw it.
Input
Input contains a number of test cases.For each case ,there are two numbers n and m (0 < n,m < 75)indicate the width and height of the rectangle.Iuput ends of EOF.
Output
For each case,you should draw a rectangle with the width and height giving in the input.
after each case, you should a blank line. 
Sample Input
3 2
Sample Output
+---+
|   |
|   |
+---+
http://acm.hdu.edu.cn/showproblem.php?pid=2052
 */
#include<stdio.h>
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)==2){
    printf("+");
    for(int i=0;i<n;i++)
        printf("-");
    printf("+\n");
    for(int i=0;i<m;i++){
        printf("|");
        for(int i=0;i<n;i++)
            printf("%%");
        printf("|\n");
    }
    printf("+");
    for(int i=0;i<n;i++)
        printf("-");
    printf("+\n");
    }
    return 0;
}