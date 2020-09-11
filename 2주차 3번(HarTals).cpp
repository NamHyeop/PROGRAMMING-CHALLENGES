#include<iostream>
#include<cstring>
using namespace std;

int main(int argc, char * argv[])
{
	int Testcase;
	int check[3650];
	cin >> Testcase;

	for (int i = 0; i < Testcase; i++)
	{
		int maxDay; //최대 날짜
		int partySize;//정당의 수
		int ret = 0;
		cin >> maxDay;
		cin >> partySize;
		memset(check, -1, sizeof(check)); //메모리를 다 -1로 초기화 해준다 쉬는날은 1로 바꿔준뒤 결과값을 측정할 때 1로 바뀐 갯수만 count해서 쉬는날을 측정할거임

		for (int i = 0; i< partySize; i++)
		{
			int party;
			cin >> party;

			for (int i = 1; party * i <= maxDay; i++) //겹치든지 말든지 쉬는날은 다 1
				check[party * i] = 1;
		}

		int a = 0;
		while ((7 + 7 * a) <= maxDay) //토요일은 쉬는날이 아니므로 다시 -1로 설정
		{
			check[7 + 7 * a] = -1;
			a++;
		}
		int b = 0;
		while ((6 + 6 * b) <= maxDay)//금요일은 쉬는날이 아니므로 다시 -1로 설정
		{
			check[6 + 7 * b] = -1;
			b++;
		}

		for (int i = 0; i <= maxDay; i++)//쉬는날 전부 count
		if (check[i] == 1)
			ret++;

		cout << ret << endl;
	}
	return 0;
}
