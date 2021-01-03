#include<bits/stdc++.h>

using namespace std;

int DP[1010][5001];
int man[5001];
int bad[5001];

int ft_min(int x, int y)
{
	return x < y ? x : y;
}
int ft_cmp(const void *i, const void *j)
{
	return *(int *)j - *(int *)i;
}

int operate(int k, int n)
{
	if (DP[k][n] != -1)
		return DP[k][n];
	if (n < 3 * k) 
		DP[k][n] = 100000000;
	else if (k == 0)
		DP[k][n] = 0;
	else
		DP[k][n] = ft_min(operate(k, n - 1), operate(k - 1, n - 2) + bad[n]);

	return DP[k][n];
}
int main(int argc, char*argv[])
{
	int Testcase;
	int n;
	int k;
	cin >> Testcase;
	
	while (Testcase--)
	{
		cin >> k >> n;
		for (int i = 1; i <= n; i++)
			cin >> man[i];
		k += 8;
		qsort(man + 1, n, sizeof(int), ft_cmp);
		for (int i = 2; i < n + 1; i++)
			bad[i] = (man[i] - man[i - 1])*(man[i] - man[i - 1]);
		for (int i = 0; i <= k; i++)
		for (int j = 0; j <= n; j++)
			DP[i][j] = -1;

		cout << operate(k, n) << "\n";
	}
	return 0;
}
