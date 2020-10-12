#include<bits/stdc++.h>

using namespace std;

typedef map<int, int> node;

map<string, node> m;
map<string, node>::iterator it;
node::iterator it2, it3;

double Operate(node& n, int EntranceCost[])
{
	int result = 0;
	for (it2 = n.begin(); it2 != n.end(); ++it2)
	{
		if (it2->second >= 0)
		{
			if (it2 == n.begin()) //시작 지점이 아니라면 
				continue;
			it3 = it2;  //증감해서 it2는 지금 끝지점을 나타내므로 it3을 다시 시작지점으로 만들어준뒤
			--it3;//감소시켜준다.
			if (it3->second < 0) //0보다 작다는건 출입구를 의미한다.
			{
				int prev = -it3->second ; //시작지점
				int km = it2->second - prev; //종료지점
				int pr = EntranceCost[(it3->first / 60) % 24];
				result += 100 + abs(km * pr); //소수점 연산을 위한 백 더하기 밑에서 다시 나눈다.
			}
		}
	}
	return result == 0 ? 0.00 : (double)(result + 200) / 100.0; //100으로 다시 나누기 때문에 기본요금 2도 2*100 상태를 유지해야함
}
int main(int argc, char * argv[])
{
	int Testcase;
	cin >> Testcase;

	//소수점 2째자리수로 고정시킨다.
	cout.precision(2);
	cout << fixed; 

	for (int i = 0; i < Testcase; i++)
	{
		int EntranceCost[24];

		for (int i = 0; i < 24; i++)
			cin >> EntranceCost[i];

		string infma;

		cin.ignore(); 
		m.clear();

		while (getline(cin, infma) && !infma.empty())
		{
			istringstream parsing(infma);
			parsing >> infma;
			//map에 들어있는 차판에 대한 키값 저장
			node &n = m[infma];
			parsing >> infma;

			int mm;
			int dd;
			int hh;
			int mi;
			int time;

			sscanf(infma.c_str(), "%d:%d:%d:%d", &mm, &dd, &hh, &mi);//c_str은 문자열 맨뒤에 /0을 넣어서 c에서의 문자열로 표현하는 방법, 파싱하면서 끝에를 의미하는 문자를 찾기 위함
			time = dd * 24 * 60 + hh * 60 + mi;
			
			parsing >> infma;
			int x;
			parsing >> x;
			n[time] = (infma[1] == 'n' ? -x  : x); //시간 순으로 정렬하므로 시작시간 끝나는 시간 순으로 정렬, 입구 표시는 음수로 표현한다.
		}
		for (it = m.begin(); it != m.end(); ++it)
		{
			double result = Operate(it -> second, EntranceCost);

			if (result == 0.00)
				continue;

			cout << it->first << " $" << Operate(it->second, EntranceCost) << endl;

		}
		if (i != Testcase -1)
			cout << '\n';
	}
}
