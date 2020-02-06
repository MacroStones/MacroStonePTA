//Problem Description
//对于给定的一个字符串，统计其中数字字符出现的次数。
//Input
//输入数据有多行，第一行是一个整数n，表示测试实例的个数，后面跟着n行，每行包括一个由字母和数字组成的字符串。
//Output
//对于每个测试实例，输出该串中数值的个数，每个输出占一行。
#include<iostream>
#include<string>
using namespace std;

int main()
{
	int num;

	cin >> num;
	for (int i(0); i < num; i++)
	{
		int count(0);
		string str;
		cin >> str;
		for (unsigned int i(0); i < str.size(); i++) {
			if (!((str.at(i) >= 'a'&&str.at(i) <= 'z') || (str.at(i) >= 'A'&&str.at(i) <= 'Z')))
				count++;
		}
		cout << count << endl;
	}

	return 0;
}