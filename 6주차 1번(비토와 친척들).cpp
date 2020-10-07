
#include<bits/stdc++.h>

using namespace std;
//그리디형식으로 문제 해결
int main(int argc, char*argv[])
{
	int Testcase;
	cin >> Testcase;

	for (int i = 0; i < Testcase; i++)
	{
		int numVilage;
		cin >> numVilage;
		int sum = 987654321;
		vector<int> viliageV;
		for (int i = 0; i < numVilage; i++)
		{
			int viliageSize;
			cin >> viliageSize;
			viliageV.push_back(viliageSize);
		}
		
		for (int j = 0; j < viliageV.size(); j++)
		{
			int tmpsum = 0;
			for (int k = 0; k < viliageV.size(); k++)
			{
				if (j == k)
					continue;
				tmpsum += abs(viliageV[j] - viliageV[k]);
			}
			sum = min(sum, tmpsum);
		}
		
		cout << sum << '\n';
	}

	return 0;
}
