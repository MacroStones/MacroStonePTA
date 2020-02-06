/*问题描述
给定两个矩形和每个矩形的对角线上的两个点的坐标，您必须计算两个矩形的相交部分的面积。它的两侧与OX和OY平行。
输入
输入第一行输入是8个正数，表示必须在每个对角线上的四个点的坐标.8个数字是x1，y1，x2，y2，x3，y3，x4，y4。这意味着两个点第一个矩形是（x1，y1），（x2，y2）;第二个矩形上的另外两个点是（x3，y3），（x4，y4）。
产量
输出对于每种情况，在一行中输出相交部分的面积。最多可以计算2个小数位。
样本输入
1.00 1.00 3.00 3.00 2.00 2.00 4.00 4.00
5.00 5.00 13.00 13.00 4.00 4.00 12.50 12.50
样本输出
1.00
56.25
*/
#include<stdio.h>

double min(double x,double y)
{
   return x<y?x:y;
}

double max(double x,double y)
{
   return x>y?x:y;
}

int main()
{
   double x1,x2,x3,x4,y1,y2,y3,y4,d,h,s;
   double minx1,miny1,maxx1,maxy1,minx2,miny2,maxx2,maxy2;
   while(~scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4))
   {
      minx1=min(x1,x2);
      miny1=min(y1,y2);
      maxx1=max(x1,x2);
      maxy1=max(y1,y2);
      minx2=min(x3,x4);
      miny2=min(y3,y4);
      maxx2=max(x3,x4);
      maxy2=max(y3,y4);
      if(minx1>=maxx2||miny1>=maxy2||minx2>=maxx1||miny2>=maxy1)
      printf("0.00\n");
      else
      {
         d=min(maxy2,maxy1)-max(miny1,miny2);//求高 
         h=min(maxx2,maxx1)-max(minx1,minx2);//求长 
         s=d*h;//面积 
         if(s<0)
         s=s*(-1);
         printf("%.2lf\n",s);
      }
   }
   return 0;
}