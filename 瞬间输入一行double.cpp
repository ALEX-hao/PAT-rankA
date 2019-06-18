// A+B for polynomials.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 超长数组干他娘的

#include <iostream>
using namespace std;

int main()
{
	double A[1002], B[1002];
	int e = 0; int flag = 0;
	char ch;

	while(1)
	{		
		cin >> e;
		if (flag == 0)
		{
			
		}
		else
		{
			cin >> A[e];
			if (ch = getchar() == '\n') break;//输入回车是结束循环
		}
		flag = 1;
	}

	cout << "fuck" << endl;
	cin.clear();
	cin.sync();
	flag = 0;
	ch = 'a';
	while (1)
	{		
		cin >> e;
		if (flag == 0)
		{
			
		}

		else
		{
			cin >> B[e];
			if (ch = getchar() == '\n') break;
		}
		flag = 1;
	}

	double C[1002];
	for (int i = 0; i < 1002; i++)
	{
		if (A[i] < -1001) A[i] = 0;
		if (B[i] < -1001) B[i] = 0;
		C[i] = A[i] + B[i];
	}
	int temp = 0;
	for (int i = 0; i < 1002; i++)
	{
		if (C[i] > 0) temp++;
	}
	cout << temp << ' ';
	for (int i = 1001; i >= 0; i--)
	{
		if (C[i] != 0) cout << i << ' ' << C[i] << ' ';
	}
	

	return 0;
}

