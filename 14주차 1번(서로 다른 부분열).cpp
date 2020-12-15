#include<bits\stdc++.h>

using namespace std;

const int MAXX = 10010;
const int MAXZ = 110;
char x[MAXX], z[MAXZ];
int DP[MAXZ][MAXX][30];

void operate(int i, int j) 
{
	for (int k = 0; k < 30; ++k) 
	{
		DP[i][j][k + 1] += (DP[i][j - 1][k] + DP[i - 1][j - 1][k]) / 10000;
		DP[i][j][k] += (DP[i][j - 1][k] + DP[i - 1][j - 1][k]) % 10000;
	}
}
int main(int argc, char *argv[])
{
	int Testcase;
	int i; 
	int j;
	int k;
	int cnt;
	int valueX;
	int	valueZ;
	cin >> Testcase;

	while (Testcase--)
	{
		cin >> x >> z;
		valueX = strlen(x); 
		valueZ = strlen(z);
		memset(DP, 0, sizeof(DP));

		for (j = 0; j <= valueX; ++j)
			DP[0][j][0] = 1;

		for (i = 1; i <= valueZ; ++i)
		for (j = 1; j <= valueX; ++j)
		if (z[i - 1] != x[j - 1]) 
			for (k = 0; k < 30; ++k)
				DP[i][j][k] = DP[i][j - 1][k];
		else 
			operate(i, j);

		for (i = 30 - 1; DP[valueZ][valueX][i] == 0 && i >= 0; --i);
		cout << DP[valueZ][valueX][i];
		for (--i; i >= 0; --i) 
			printf("%04d", DP[valueZ][valueX][i]);
		cout << "\n";
	}
	return 0;
}
