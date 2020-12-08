#include<bits\stdc++.h>

using namespace std;

typedef struct Node
{
	int Weight;
	int Sq;
	int node;
};

Node Elephant[1000];

int linecmp(const void *i, const void *j)
{
	Node *tmp1, *tmp2;
	tmp1 = (Node *)i, tmp2 = (Node *)j;
	if (tmp1->Weight != tmp2->Weight)
		return tmp1->Weight - tmp2->Weight;
	return tmp1->Sq - tmp2->Sq;
}
void ReverseF(int n)
{
	int i, j;
	int DP[1000] = {};
	int source[1000] = {};

	for (i = 0; i < n; i++)
		DP[i] = 1, source[i] = i;

	for (i = 0; i < n; i++)
	{
		for (j = i - 1; j >= 0; j--)
		{
			if ((Elephant[i].Weight != Elephant[j].Weight) && (Elephant[i].Sq < Elephant[j].Sq))
			{
				if (DP[i] <= DP[j] + 1)
				{
					DP[i] = DP[j] + 1;
					source[i] = j;
				}
			}
		}
	}
	int Value = 0;
	int start;
	for (i = 0; i < n; i++)
		if (DP[i] > Value)
		{
			Value = DP[i];
			start = i;
		}
	cout << Value << '\n';
	int ret[1000];
	int idx = 0;
	int k = 1;
	while (source[start] != start)
	{	
		if (Elephant[start].node + 1 > (n / 2 + 1))
		{
			ret[idx++] = n-Elephant[start].node + 1 + k;
			k++;
		}
		else
		ret[idx++] = Elephant[start].node +1;
		
		start = source[start];
	}
	ret[idx++] = Elephant[start].node + 1;

	//for (i = 0; i <= Value -1 ; i++)
	//	cout << ret[i] << '\n';
	for (i = Value - 1; i >= 0; i--)
		cout << ret[i] << '\n';
}
int main(int argc, char*argv[]) 
{
	int i = 0;
	while (scanf("%d %d", &Elephant[i].Weight, &Elephant[i].Sq) == 2)
	{
		Elephant[i].node = i;
		i++;
	}

	qsort(Elephant, i, sizeof(Node), linecmp);

	ReverseF(i);
	return 0;
}
