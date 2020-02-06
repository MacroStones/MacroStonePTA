/*Problem Description
Give you a number on base ten,you should output it on base two.(0 < n < 1000)
Input
For each case there is a postive number n on base ten, end of file.
Output
For each case output a number on base two.
Sample Input
1
2
3
Sample Output
1
10
11
http://acm.hdu.edu.cn/showproblem.php?pid=2051
*/
#include<stdio.h>
int main(){
    int n;
    bool flag=false;
    while(scanf("%d",&n)==1){
        for(int i=0;i<32;i++){
            if(n>=0 && flag)
                printf("0");
            if(flag=(n<0))
                printf("1");
            n=n<<1;
        }
        printf("\n");
    }
    return 0;
}