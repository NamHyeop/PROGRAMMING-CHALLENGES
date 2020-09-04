/ *
//출력을 영구적으로 바꿀수 있다는걸 알게 된 문제. 이걸 알아낼려고 시간을 도데체 몇 시간을 지불한건지
//수업료가 너무 비싸다 하..
#include <iostream>
#include<sstream>
#include<string>
using namespace std;

//cout dec를 모르고 짠 코드
int main(void)
{
	string input;
	
	while (getline(cin,input))
	{
		int n = 0;
		istringstream iss(input); //istringstream은 공백 단위로 입력을 입력받음
		
		if (input[0] == '0')
		{
			int tmp = 0;
			for (int i = (input.size()-1); 1 < i ; i--) // 맨 뒤부터 16진수 계산을 하겠다.
			{
				int sq = 1;

				if ((65 <= input[i] && input[i] <= 70)) //10이상 문자 표기열인경우
				{
					if (i == (input.size() - 1))
					{
						n += (input[i] - 55) * 1;
						tmp++;
					}
					else if (i == (input.size() - 2))
					{
						n += (input[i] - 55) * 16;
						tmp++;
					}
					else
					{
						for (int i = 0; i < tmp; i++)
							sq *= 16;
					
						n += (input[i] - 55) * sq;
						tmp++;
					}

				}
				else//정수인경우
				{
					if (i == (input.size() - 1))
					{
						n += (input[i] - 48) *1;
						tmp++;
					}
					else if (i == (input.size() - 2))
					{
						n += (input[i] - 48) * 16;
						tmp++;
					}
					else
					{
						for (int i = 0; i < tmp; i++)
							sq *= 16;

						n += (input[i] - 48) * sq;
						tmp++;
					}
				}
			}
			cout << n << endl;
		}
		else
		{
			iss >> n;
			cout << "0x";
			cout << uppercase <<hex << n << endl;
			cout << dec;
		}
	}
	return 0;
}
*/

/*
cout <<dec에 대해 알고짠 코드
진짜 너무화나
#include<iostream>
#include<sstream>
#include<string>
using namespace std;

int main(void)
{
	string line;
	int n;
	while (getline(cin, line))
	{
		istringstream iss(line);
		if (line[0] == '0')
		{
			iss >> hex >> n;
			cout << n << endl;
		}
		else
		{
			iss >> n;
			cout << "0x";
			cout << hex << uppercase << n << endl;
			cout << dec;
		}
	}
	return 0;
}
*/
