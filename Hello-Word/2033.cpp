/*Problem Description
HDOJ上面已经有10来道A+B的题目了，相信这些题目曾经是大家的最爱，希望今天的这个A+B能给大家带来好运，也希望这个题目能唤起大家对ACM曾经的热爱。
这个题目的A和B不是简单的整数，而是两个时间，A和B 都是由3个整数组成，分别表示时分秒，比如，假设A为34 45 56，就表示A所表示的时间是34小时 45分钟 56秒。
Input
输入数据有多行组成，首先是一个整数N，表示测试实例的个数，然后是N行数据，每行有6个整数AH,AM,AS,BH,BM,BS，分别表示时间A和B所对应的时分秒。题目保证所有的数据合法。
Output
对于每个测试实例，输出A+B，每个输出结果也是由时分秒3部分组成，同时也要满足时间的规则（即：分和秒的取值范围在0~59），每个输出占一行，并且所有的部分都可以用32位整数表示。
*/
#include<stdio.h>

int main(){
    int N,ah,am,as,bh,bm,bs;
    while(~scanf("%d",&N) && N){
        while(N--){
            scanf("%d %d %d %d %d %d",&ah,&am,&as,&bh,&bm,&bs);
            printf("%d %d %d\n",ah+bh+((am+bm+((as+bs)/60))/60),(am+bm+((as+bs)/60))%60,(as+bs)%60);
        }
    }
    return 0;
}
