#include<bits/stdc++.h>

using namespace std;

struct Node
{
	int w, s;
};

bool comp(const Node &t1, const Node &t2)
{
	return t1.s < t2.s;
}

vector<Node> Cur;
int DP[5607];

void solve()
{
	sort(Cur.begin(), Cur.end(), comp);

	fill(DP, DP + 5607, numeric_limits<int>::max());
	DP[0] = 0;

	int maxNTurtles = 0;

	for (int i = 0; i < Cur.size(); ++i)
	for (int j = maxNTurtles; j >= 0; --j)
	if (Cur[i].s >= DP[j] + Cur[i].w && Cur[i].w + DP[j] < DP[j + 1])
	{
		DP[j + 1] = DP[j] + Cur[i].w;
		maxNTurtles = max(maxNTurtles, j + 1);
	}

	cout << maxNTurtles << endl;
}

int main()
{
	Node tmp;
	while (scanf("%d %d", &tmp.w, &tmp.s) == 2)
		Cur.push_back(tmp);

	solve();
}
