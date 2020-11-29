#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

int n;
double x[103], y[103];

struct node
{
	int dest;
	double weight;

	node(int i, double w)
	{
		dest = i; weight = w;
	}
};

typedef vector<node>ve;
typedef vector<ve>vve;

double distance(double x1, double y1, double x2, double y2)
{
	return sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
}

bool operator < (node a, node b)
{
	return a.weight>b.weight;
}

int main(int argc, char *argv[])
{
	int Testcase;
	int i;
	int j;
	double k;

	cin >> Testcase;

	while (Testcase--)
	{
		cin >> n;
		vve G(n);

		for (i = 0; i<n; i++)
			cin >> x[i] >> y[i];

		for (i = 0; i<n; i++)
		for (j = i + 1; j<n; j++)
		{
			k = distance(x[i], y[i], x[j], y[j]);
			G[i].push_back(node(j, k));
			G[j].push_back(node(i, k));
		}

		priority_queue<node>pq;
		pq.push(node(0, 0));
		vector<bool>dist(n, false);
		double res = 0;
		while (!pq.empty())
		{
			int u = pq.top().dest;
			double w = pq.top().weight;
			pq.pop();
			if (dist[u]) continue;
			res += w;
			dist[u] = true;

			for (i = 0; i<G[u].size(); i++)
			{
				int u1 = G[u][i].dest;
				if (dist[u1]) continue;
				pq.push(G[u][i]);
			}
		}
		printf("%.2lf\n", res);
		if (Testcase>0)
			printf("\n");
	}

	return 0;
}
