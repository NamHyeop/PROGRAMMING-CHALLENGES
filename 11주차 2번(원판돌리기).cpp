#include <bits/stdc++.h>

using namespace std;

int main(int argc, char * argv[])
{
	
	int Testcase;
	cin >> Testcase;

	int cycle1;
	int cycle2;
	int cycle3;
	int d;
	int st, ed;
	while (Testcase--) 
	{
		int ban[10005] = {};
		int tn;
		int i;
		int j;
		int n;
		int tmp;

		cin >> cycle1 >> cycle2 >> cycle3 >> d;
		st = cycle1 * 1000 + cycle2 * 100 + cycle3 * 10 + d;
		cin >> cycle1 >> cycle2 >> cycle3 >> d;
		ed = cycle1 * 1000 + cycle2 * 100 + cycle3 * 10 + d;
		
		cin >> n;
		while (n--) 
		{
			cin >> cycle1 >> cycle2 >> cycle3 >> d;
			tn = cycle1 * 1000 + cycle2 * 100 + cycle3 * 10 + d;
			ban[tn] = 1;
		}
		int Q[10000];
		int maxCycle;
		int Entrance[10000] = {}; 
		int step[10000] = {}; 
		Q[maxCycle = 0] = st;
		Entrance[st] = 1;
		step[st] = 1;

		for (i = 0; i <= maxCycle; i++)
		{
			tn = Q[i];
			cycle1 = tn / 1000;
			cycle2 = tn % 1000 / 100;
			cycle3 = tn % 100 / 10;
			d = tn % 10;
			tmp = (cycle1 + 1) % 10 * 1000 + cycle2 * 100 + cycle3 * 10 + d;
			if (Entrance[tmp] == 0 && ban[tmp] == 0)
			{
				Entrance[tmp] = 1;
				step[tmp] = step[tn] + 1;
				++maxCycle;
				Q[maxCycle] = tmp;
			}
			tmp = (cycle1 + 9) % 10 * 1000 + cycle2 * 100 + cycle3 * 10 + d;
			if (Entrance[tmp] == 0 && ban[tmp] == 0)
			{
				Entrance[tmp] = 1;
				step[tmp] = step[tn] + 1;
				++maxCycle;
				Q[maxCycle] = tmp;
			}
			tmp = cycle1 * 1000 + (cycle2 + 1) % 10 * 100 + cycle3 * 10 + d;
			if (Entrance[tmp] == 0 && ban[tmp] == 0)
			{
				Entrance[tmp] = 1;
				step[tmp] = step[tn] + 1;
				++maxCycle;
				Q[maxCycle] = tmp;
			}
			tmp = cycle1 * 1000 + (cycle2 + 9) % 10 * 100 + cycle3 * 10 + d;
			if (Entrance[tmp] == 0 && ban[tmp] == 0)
			{
				Entrance[tmp] = 1;
				step[tmp] = step[tn] + 1;
				++maxCycle;
				Q[maxCycle] = tmp;
			}
			tmp = cycle1 * 1000 + cycle2 * 100 + (cycle3 + 1) % 10 * 10 + d;
			if (Entrance[tmp] == 0 && ban[tmp] == 0)
			{
				Entrance[tmp] = 1;
				step[tmp] = step[tn] + 1;
				++maxCycle;
				Q[maxCycle] = tmp;
			}
			tmp = cycle1 * 1000 + cycle2 * 100 + (cycle3 + 9) % 10 * 10 + d;
			if (Entrance[tmp] == 0 && ban[tmp] == 0)
			{
				Entrance[tmp] = 1;
				step[tmp] = step[tn] + 1;
				++maxCycle;
				Q[maxCycle] = tmp;
			}
			tmp = cycle1 * 1000 + cycle2 * 100 + cycle3 * 10 + (d + 1) % 10;
			if (Entrance[tmp] == 0 && ban[tmp] == 0)
			{
				Entrance[tmp] = 1;
				step[tmp] = step[tn] + 1;
				++maxCycle;
				Q[maxCycle] = tmp;
			}
			tmp = cycle1 * 1000 + cycle2 * 100 + cycle3 * 10 + (d + 9) % 10;
			if (Entrance[tmp] == 0 && ban[tmp] == 0)
			{
				Entrance[tmp] = 1;
				step[tmp] = step[tn] + 1;
				++maxCycle;
				Q[maxCycle] = tmp;
			}
			if (Entrance[ed])
				break;
		}
		if (Entrance[ed])
			cout << step[ed] - 1 << "\n";
		else
			cout << "-1" << "\n";

	}
	return 0;
}
