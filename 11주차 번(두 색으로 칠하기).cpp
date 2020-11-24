#include <bits/stdc++.h>

using namespace std;

#define MAXN 200
static int n, graph[MAXN][MAXN];
static int color[MAXN];
static int colorable;

int input()
{
	int i, j, l, a, b;
	scanf("%d", &n);
	if (n == 0) return 0;
	for (i = 0; i < n; i++)
	for (j = 0; j < n; j++)
		graph[i][j] = 0;
	scanf("%d", &l);
	for (i = 0; i < l; i++)
	{
		scanf("%d %d", &a, &b);
		graph[a][b] = graph[b][a] = 1;
	}
	return 1;
}

void dfs(int node, int c)
{
	int i;
	color[node] = c;
	for (i = 0; i < n && colorable; i++) {
		if (graph[node][i] == 0) continue;
		if (color[i] == 0)
			dfs(i, c % 2 + 1);
		else {
			if (color[i] == c)
			{
				colorable = 0;
				return;
			}
		}
	}
}

void main(void)
{
	int i;
	while (input())
	{
		for (i = 0; i < n; i++)
			color[i] = 0;
		colorable = 1;
		dfs(0, 1);
		if (colorable == 0)
			printf("NOT BICOLORABLE.\n");
		else
			printf("BICOLORABLE.\n");
	}
}
