#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 0x3f3f3f3f;

int n;
int m;
int Board[15][110];
int DP[15][110];
int fro[15][110];

int re_num(int pos, int lr) 
{
	pos += lr;
	if (pos <= 0) 
		return n;
	if (pos > n)
		return 1;
	return pos;
}

int main(int argc, char *argv[])
{
	while (scanf("%d%d", &n, &m) == 2)
	{
		memset(fro, 0, sizeof(fro));

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				cin >> Board[i][j];
			}
		}

		memset(DP, inf, sizeof(DP));
		for (int i = 1; i <= n; i++)
			DP[i][m] = Board[i][m];

		for (int j = m - 1; j >= 1; j--) 
		{
			for (int i = 1; i <= n; i++) 
			{  
				for (int k = -1; k <= 1; k++)
				{
					int num = re_num(i, k);
					if (DP[i][j] > DP[num][j + 1] + Board[i][j] || (DP[i][j] == DP[num][j + 1] + Board[i][j] && fro[i][j]>num))
					{
						DP[i][j] = DP[num][j + 1] + Board[i][j];
						fro[i][j] = num;
					}
				}
			}
		}

		int r;
		int minn;

		minn = inf;
		for (int i = 1; i <= n; i++)
		if (minn > DP[i][1])
		{
			r = i;
			minn = DP[i][1];
		}

		int l = 1;
		for (int i = r; i != 0; i = fro[i][l++]) 
		{
			if (l != 1)
				cout << " ";
			cout << i;
		}
		cout << "\n"<< minn << "\n" ;
	}

	return 0;
}
