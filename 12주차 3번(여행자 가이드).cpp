#include<bits/stdc++.h>

using namespace std;

set<string>st;
set<string>::iterator iter;
map<string, int> board;
map<int, string>Sboard;

vector<int> brati[100000];
int dis[10000];
int fin[100000];
int low[100000];
bool Entrance[100000];
int child[100000];
int parent[100000];
int tim = 0;
int nodes[100000] = { 0, };
int total = 0;

void dfs(int s)
{
	Entrance[s] = true;
	tim++;
	dis[s] = tim;
	low[s] = dis[s];
	for (int i = 0; i < brati[s].size(); i++)
	{
		int x = brati[s][i];
		if (!Entrance[x])
		{
			parent[x] = s;
			child[s]++;
			dfs(x);
			if (low[x] >= dis[s] && parent[s] != -1)
				st.insert(Sboard[s]);
		
			if (child[s]>1 && parent[s] == -1)
				st.insert(Sboard[s]);
			
			low[s] = min(low[x], low[s]);
		}
		else if (x != parent[s])
			if (dis[x]<low[s]) low[s] = dis[x];
	}
}
int power(int x, int y)
{
	int n = 1, i;
	for (i = 0; i<y; i++)
		n *= x;
	return n;
}

int toInteger(string s)
{
	int num = 0, i, l, x;
	l = s.size();
	for (i = 0; i<l; i++){
		x = s[i] - 48;
		num += x*power(10, l - i - 1);
	}
	return num;
}

int main(int argc, char *argv[])
{
	int t, n, m, i, j, u, v, k, l, cnt, cas = 0;
	string s, s1, s2;
	while (1)
	{
		cin >> n;

		if (n == 0) 
			return 0;

		cas++;
		
		if (cas>1)
			cout << endl;

		memset(Entrance, 0, sizeof(Entrance));
		memset(low, -1, sizeof(low));
		memset(dis, 0, sizeof(dis));
		memset(child, 0, sizeof(child));
		memset(parent, -1, sizeof(parent));
		st.clear();
		board.clear();
		Sboard.clear();
		tim = 0, total = 0;
		cnt = 0;
		for (i = 0; i<n + 10; i++)
			brati[i].clear();

		for (i = 0; i<n; i++)
		{
			cin >> s;
			cnt++;
			board[s] = cnt;
			Sboard[cnt] = s;
		}

		cin >> m;
		for (i = 1; i <= m; i++)
		{
			cin >> s1 >> s2;
			u = board[s1];
			v = board[s2];
			brati[u].push_back(v);
			brati[v].push_back(u);
		}
		
		for (i = 1; i <= n; i++)
		if (!Entrance[i])
				dfs(i);
		
		cout << "City map #" << cas << ": " << st.size() << " camera(s) found\n";

		for (iter = st.begin(); iter != st.end(); iter++)
			cout << *iter << endl;

	}
	return 0;
}
