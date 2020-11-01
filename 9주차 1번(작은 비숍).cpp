#include <iostream>
#include <algorithm>

using namespace std;
int main(int argc, char *argv[])
{
	int n, k;
	while (1)
	{
		int ret = 0;
		scanf("%d %d", &n, &k);
		if (n == 0 && k == 0)
			return 0;

		if (k == 0 || n == 1)
		{
			cout << "1" << "\n";
			continue;
		}

		int board1[20];
		int board2[20];
		memset(board1, 0, sizeof(board1));
		memset(board2, 0, sizeof(board2));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			if ((i + j) % 2)
				board1[(i + j) / 2]++;
			else
				board2[(i + j) / 2]++;
		}
		sort(board1, board1 + n - 1);
		sort(board2, board2 + n);


		int dp1[20][20];
		int dp2[20][20];
		memset(dp1, 0, sizeof(dp1));
		memset(dp2, 0, sizeof(dp2));
		dp1[0][0] = 1;
		dp1[0][1] = board1[0];
		dp2[0][0] = 1;
		dp2[0][1] = board2[0];
		for (int i = 1; i < n - 1; i++)
		{
			dp1[i][0] = 1;
			for (int j = 1; j <= board1[i]; j++)
				dp1[i][j] = dp1[i - 1][j] + dp1[i - 1][j - 1] * (board1[i] - (j - 1));
		}
		for (int i = 1; i < n; i++)
		{
			dp2[i][0] = 1;
			for (int j = 1; j <= board2[i]; j++)
				dp2[i][j] = dp2[i - 1][j] + dp2[i - 1][j - 1] * (board2[i] - (j - 1));
		}

		for (int i = 0; i <= k; i++)
			ret += dp1[n - 2][i] * dp2[n - 1][k - i];
		cout << ret << "\n";
	}
	return 0;
}
