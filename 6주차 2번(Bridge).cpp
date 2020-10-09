#include<bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[])
{
	int Testcase;
	cin >> Testcase;

	for (int i = 0; i < Testcase; i++)
	{
		int sum = 0;
		int peopleNum;
		cin >> peopleNum;
		vector<int> v;

		for (int i = 0; i < peopleNum; i++)
		{
			int peopleSize;
			cin >> peopleSize;
			v.push_back(peopleSize);
		}

		sort(v.begin(), v.end());

		cout << '\n';

		while (v.size() >= 4)
		{
			int tmp1= v[1] + v[0] + v.back() + v[1];
			int tmp2 = v.back() + v[0] + v[v.size() - 2] + v[0];
			
			if (tmp1 < tmp2)
				sum += tmp1;
			else
				sum += tmp2;

			v.pop_back();
			v.pop_back();
		}

		if (v.size() == 3)
			sum += v[0] + v[1] + v[2];
		else if (v.size() == 2)
			sum += v[1];
		else
			sum += v[0];

		cout << sum << '\n';
	}

	return 0;
}
/*
0 1 2 3
1 2 3 4

2 3 3 4 5 10

1 2
1
3 4
2
1 2

*/
