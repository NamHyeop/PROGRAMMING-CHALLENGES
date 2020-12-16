#include<bits/stdc++.h>

using namespace std;

char DP[205][10005];
char Bfboard[205][10005];

int main(int argc, char *argv[])
{
	int Testcase;
	cin >> Testcase;
	while (Testcase--)
	{
		int length;
		int n;
		int A[2005];
		int sum[2005] = {};
		int i, j;
		
		cin >> length;
		length *= 100;
		n = 1;
		while (scanf("%d", &A[n]), A[n])
		{
			sum[n] = sum[n - 1] + A[n];
			n++;
		}
		memset(DP, 0, sizeof(DP));

		DP[0][0] = 1;
		n--;
		int mx_car = 0, mx_len;
		for (i = 1; i < n+1; i++) 
		{
			for (j = 0; j <= length; j++) 
			{
				if (j - A[i] >= 0 && DP[i - 1][j - A[i]])
				{ 
					DP[i][j] = 1;
					Bfboard[i][j] = 0;
				}
				if (sum[i] - j <= length && DP[i - 1][j])
				{ 
					DP[i][j] = 1;
					Bfboard[i][j] = 1;
				}
				if (DP[i][j])
					mx_car = i;
					mx_len = j;
			}
			if (mx_car != i)
				break;
		}
		cout << "\n";
		cout << mx_car << "\n";

		int where[205];
		i = mx_car;
		j = mx_len;

		while (i)
		{
			where[i] = Bfboard[i][j];
			if (!Bfboard[i][j])
				j -= A[i];
			i--;
		}
		if (Testcase)
			cout <<"";
	}
	return 0;
}
