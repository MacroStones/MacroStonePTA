/*
布置宴席最微妙的事情，就是给前来参宴的各位宾客安排座位。无论如何，总不能把两个死对头排到同一张宴会桌旁！这个艰巨任务现在就交给你，对任何一对客人，请编写程序告诉主人他们是否能被安排同席。

输入格式：
输入第一行给出3个正整数：N（≤100），即前来参宴的宾客总人数，则这些人从1到N编号；M为已知两两宾客之间的关系数；K为查询的条数。随后M行，每行给出一对宾客之间的关系，格式为：宾客1 宾客2 关系，其中关系为1表示是朋友，-1表示是死对头。注意两个人不可能既是朋友又是敌人。最后K行，每行给出一对需要查询的宾客编号。

这里假设朋友的朋友也是朋友。但敌人的敌人并不一定就是朋友，朋友的敌人也不一定是敌人。只有单纯直接的敌对关系才是绝对不能同席的。

输出格式：
对每个查询输出一行结果：如果两位宾客之间是朋友，且没有敌对关系，则输出No problem；如果他们之间并不是朋友，但也不敌对，则输出OK；如果他们之间有敌对，然而也有共同的朋友，则输出OK but...；如果他们之间只有敌对关系，则输出No way。
*/


#include <iostream>
#include <vector>
using namespace std;
int a[101][101];
int n,m,k;
//已知c，d是敌人，找共同朋友；有返回1，否则返回0； 
int find(int c,int d){
  for(int i=1;i<=n;i++) {
    if(a[c][i]&&a[d][i]) return 1;//找到共同朋友返回1 
  }
  return 0;//没找到共同朋友 返回0 
}
int main(){ 
    vector<string>s;
  cin>>n>>m>>k;
  //memset(a,0,sizeof(a));
  int x,y,z;
  //输入关系 
  for(int i=0;i<m;i++){
    cin>>x>>y>>z;
    a[x][y]=z;
    a[y][x]=z;
  }
  //查询关系 
  for(int i=0;i<k;i++){
    cin>>x>>y;
    if(a[x][y]==1) s.push_back("No problem");
    else if(a[x][y]==0) s.push_back("OK");
    else if(a[x][y]==-1&&find(x,y))//是敌人但有共同朋友 
    {s.push_back("OK but...");} 
    else //是敌人并且没有共同朋友 
    {s.push_back("No way");} 
  }  
  //输出
  for(int i=0;i<k;i++) 
     cout<<s[i]<<endl;
  return 0;
}