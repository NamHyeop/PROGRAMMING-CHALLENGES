
#include <bits/stdc++.h>

using namespace std;
long long N = 2e9;

vector<long long> arr;

long long n;

int input()
{
	cin >> n;

	if (n == 0)
		return 0;

	return 1;
}
int main()
{
	arr.push_back(0);
	arr.push_back(1);
	arr.push_back(3);

	int k = 0;
	for (long long i = 3; k <= N; i++) 
	{
		k = 0;
		k = *(arr.end() - 1) + (lower_bound(arr.begin(), arr.end(), i) - arr.begin());
		arr.push_back(k);
	}
	while (input())
	{
		cout << (long long)(lower_bound(arr.begin(), arr.end(), n) - arr.begin()) << '\n';
	}

	return 0;
}
