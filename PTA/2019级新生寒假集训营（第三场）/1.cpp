/*题的目标很简单，就是求两个正整数A和B的和，其中A和B都在区间[1,1000]。稍微有点麻烦的是，输入并不保证是两个正整数。

输入格式：
输入在一行给出A和B，其间以空格分开。问题是A和B不一定是满足要求的正整数，有时候可能是超出范围的数字、负数、带小数点的实数、甚至是一堆乱码。

注意：我们把输入中出现的第1个空格认为是A和B的分隔。题目保证至少存在一个空格，并且B不是一个空字符串。

输出格式：
如果输入的确是两个正整数，则按格式A + B = 和输出。如果某个输入不合要求，则在相应位置输出?，显然此时和也是?。
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s, s1, s2;
    int n1 = 0, n2 = 0, i, k = 0, a, b;
    getline(cin, s);
    for(i = 0;i < s.length();i++)
    {
        if(s[i] == ' ')
        {
            b = i;
            k++;
        }
        if(k >= 2)//有两个空格，无论是B为空格还是B为xxx xx的样式，B都要输出?
         {
             n2 = -1;
             break;
         }
        a = b;
    }
    if(k == 1)//只有一个空格，xxx xxx格式
        b = s.length();
    for(i = 0;i < a;i++)
    {
        if(s[i] < '0' || s[i] > '9')
        {
            n1 = -1;
            break;
        }
    }
    for(i = a+1;i < b;i++)
    {
        if(s[i] < '0' || s[i] > '9')
        {
            n2 = -1;
            break;
        }
    }
    if(n1 != -1 && n2 != -1)
    {
        s1 = s.substr(0, a);
        s2 = s.substr(a+1, b-a-1);
        n1 = atoi(s1.c_str());
        n2 = atoi(s2.c_str());
        if(n1 >= 1 && n1 <= 1000 && n2 >= 1 && n2 <= 1000)
            printf("%d + %d = %d", n1, n2, n1+n2);
        else if(n1 >= 1 && n1 <= 1000 &&(n2 < 1 || n2 >1000))
            printf("%d + ? = ?", n1);
        else if(n2 >= 1 && n2 <= 1000 &&(n1 < 1 || n1 >1000))
            printf("? + %d = ?", n2);
        else
            printf("? + ? = ?");
    }
    else if(n1 == -1 && n2 != -1)
    {
        s2 = s.substr(a+1, b-a-1);
        n2 = atoi(s2.c_str());
        if(n2 >= 1 && n2 <= 1000)
            printf("? + %d = ?", n2);
        else
            printf("? + ? = ?");
    }
    else if(n1 != -1 && n2 == -1)
    {
        s1 = s.substr(0, a);
        n1 = atoi(s1.c_str());
        if(n1 >= 1 && n1 <= 1000)
            printf("%d + ? = ?", n1);
        else
            printf("? + ? = ?");
    }
    else
        printf("? + ? = ?");
    return 0;
//数字范围问题，测试点5,6，非正常边界测试
//0 2,测试点5
}