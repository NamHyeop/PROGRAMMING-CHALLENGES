#include <bits/stdc++.h>
using namespace std;

struct box {
	int to, x, y;
	box()
	{
	}
	box(int a, int b, int c) 
	{
		to = a, x = b, y = c;
	}
};
map<string, int> val;
vector<vector<box> > arr;

int cmp(int x, int y)
{
	if (x == -1)
		return 0;
	if (x == y)
		return 0;
	if (x >= 18 && x <= 24)
		return !((y >= x && y <= 24) || y < 6);
	if (x >= 1 && x <= 6) {
		return !(y >= x && y < 6);
	}
}
int bfs(int src, int des)
{
	if (src == 0 || des == 0)
		return -1;
	queue<pair<int, int> > que;
	vector<int> dist(101, 1e6);
	dist[src] = 0;
	que.push(make_pair(src, -1));
	while (que.size()) 
	{
		int x = que.front().first, prev = que.front().second;

		que.pop();
		int ln = arr[x].size();
		for (int i = 0; i < ln; ++i)
		{
			int y = arr[x][i].to;
			int a = arr[x][i].x, b = arr[x][i].y;
			if (dist[y] > dist[x] + cmp(prev, a))
			{

				dist[y] = dist[x] + cmp(prev, a);
				que.push(make_pair(y, b));
			}
		}

	}

	return (dist[des] == 1e6) ? -1 : dist[des];
}
int main()
{
	int Testcase;
	cin >> Testcase;
	while (Testcase--) 
	{
		int n, x, y, m = 0;
		string s1, s2;
		cin >> n;
		arr = vector<vector<box> >(101);
		val.clear();
		for (int i = 0; i < n; ++i)
		{
			cin >> s1 >> s2 >> x >> y;
			int z = x + y;
			if (z > 24)
				z -= 24;
			if ((x >= 6 && x < 18) || (z > 6 && z <= 18) || y > 12)
				continue;
			if (!val[s1])
			{
				++m;
				val[s1] = m;
			}
			if (!val[s2]) 
			{
				++m;
				val[s2] = m;
			}
			arr[val[s1]].push_back(box(val[s2], x, z));
		}
		cin >> s1 >> s2;
		static int cas = 1;
		printf("Test Case %d.\n", cas++);
		if (s1 == s2) 
		{
			cout << "Vladimir needs 0 litre(s) of blood." << "\n";
			continue;
		}
		int ans = bfs(val[s1], val[s2]);

		if (ans == -1)
		{
			cout << "There is no route Vladimir can take." << "\n";
		}
		else
		{
			cout << "Vladimir needs " << ans <<" litre(s) of blood." <<"\n";
		}
	}
	return 0;
}
