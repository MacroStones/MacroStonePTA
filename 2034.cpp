/*Problem Description
参加过上个月月赛的同学一定还记得其中的一个最简单的题目，就是{A}+{B}，那个题目求的是两个集合的并集，今天我们这个A-B求的是两个集合的差，就是做集合的减法运算。（当然，大家都知道集合的定义，就是同一个集合中不会有两个相同的元素，这里还是提醒大家一下）
呵呵，很简单吧？
Input
每组输入数据占1行,每行数据的开始是2个整数n(0<=n<=100)和m(0<=m<=100),分别表示集合A和集合B的元素个数，然后紧跟着n+m个元素，前面n个元素属于集合A，其余的属于集合B. 每个元素为不超出int范围的整数,元素之间有一个空格隔开.
如果n=0并且m=0表示输入的结束，不做处理。
Output
针对每组数据输出一行数据,表示A-B的结果,如果结果为空集合，则输出“NULL”,否则从小到大输出结果,为了简化问题，每个元素后面跟一个空格.
*/
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> a, b;
set<int> ab;
vector<int>::iterator ita, itb;
set<int>::iterator itab;
int main(){
    int n, m;
    int tempa, tempb;
    while (1){
        //ita = a.begin();
        cin >> n;
        cin >> m;
        if (n == 0 && m == 0) break;
        for (int i = 0; i < n; i++){
            cin >> tempa;
            a.push_back(tempa);
        }
        for (int i = 0; i < m; i++){
            cin >> tempb;
            b.push_back(tempb);
        }
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());
        sort(b.begin(), b.end());
        b.erase(unique(b.begin(), b.end()), b.end());
        for (int i = 0; i < a.size(); i++)
            for (int j = 0; j < b.size(); j++)
                if (a[i] == b[j])
                    ab.insert(a[i]);
        itab = ab.begin();
        while (itab != ab.end()){
            ita = a.begin();
            while (ita!=a.end()){
                if (*ita == *itab)
                    ita=a.erase(ita);
                else
                    ita++;
            }
            itab++;
        }
        if (a.size() == 0)
            cout << "NULL" ;
        else{
            for (int i = 0; i < a.size(); i++)
                cout << a[i] << " ";
        }
        cout << endl;
        a.clear(); b.clear(); ab.clear();
    }
    return 0;
}
