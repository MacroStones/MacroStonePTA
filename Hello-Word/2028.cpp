/*Problem MinimumCommonMultiple
求n个数的最小公倍数。
Input
输入包含多个测试实例，每个测试实例的开始是一个正整数n，然后是n个正整数。
Output
为每组测试数据输出它们的最小公倍数，每个测试实例的输出占一行。你可以假设最后的输出是一个32位的整数。
*/
#include<stdio.h>
int main(){
    int n;
    while(scanf("%d",&n)==1){
        int MinimumCommonMultiple=1,Number;
        for(int i=0;i<n;i++){
            scanf("%d",&Number);
            int MinimumCommonMultipleTmp=MinimumCommonMultiple;
            while(MinimumCommonMultiple%Number!=0){
                MinimumCommonMultiple+=MinimumCommonMultipleTmp;
            }
        }
        printf("%d\n",MinimumCommonMultiple);
    }
    return 0;
}