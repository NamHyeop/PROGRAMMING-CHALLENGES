#include<iostream>
#include<cstring>
#include<string>
using namespace std;

int main()
{
	int inputn;
	string input;
	int intrace[5000];
	int prev;

	while (cin >> inputn)
	{
		for (int i = 1; i <= inputn; i++)
			intrace[i] = 0;

		int flag = 1;
		cin >> prev;
		for (int i = 1; i < inputn; i++)
		{
			int cur;
			cin >> cur;

			//절대값이 0보다 작거나 한도치값과 크거나 같다면 문제 조건에 틀리므로 not jolly를 의미
			int tmp = abs(cur - prev);
			if (tmp <= 0 || tmp >= inputn || intrace[tmp])
			{
				flag = 0;
				break;
			}
			intrace[tmp] = 1;
			prev = cur;
		}

		//루프를 반복하던도중 break을 만날 경우 남아 있는 입력값들의 버퍼를 지우기 위해 존재(매우 중요)
		cin.ignore(30, '\n');
		string ret = (flag ? "Jolly" : "Not jolly");
		cout << ret << endl;
	}
}
