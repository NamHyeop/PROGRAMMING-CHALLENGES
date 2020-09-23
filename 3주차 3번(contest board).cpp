#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

typedef struct Commit
{
	int nTeam;
	int nProblem;
	int nTime;
	char nState;
}Commit;

typedef struct Rank
{
	int nTeam;
	int nSolved;
	int nTime;
}Rank;

bool operator<(const Rank &r1, const Rank &r2)
{
	if (r1.nSolved < r2.nSolved)
		return true;
	else if (r1.nSolved > r2.nSolved) 
		return false;
	else
	{
		if (r1.nTime > r2.nTime)
			return true;
		else if (r1.nTime < r2.nTime)
			return false;
		else{
			if (r1.nTeam > r2.nTeam)
				return true;
			else
				return false;
		}
	}
}

int main(int argc, char*argv[])
{
	int Testcase = 0;
	cin >> Testcase;
	
	cin.ignore(2);

	for (int i = 0; i < Testcase; i++)
	{
		vector<Commit> vecCom;
		Commit commit;
		string strLine;
		while (getline(cin, strLine))
		{
			if (strLine.empty())
				break;
			istringstream iss(strLine);
			iss >> commit.nTeam >> commit.nProblem >> commit.nTime >> commit.nState;
			vecCom.push_back(commit);
		}
		
		vector<bool> vvb(100, false);
		vector<vector<int>> vvCrtPenalty(100, vector<int>(9, 0)), vvIcrtPenalty(100, vector<int>(9, 0));
		for (int i = 0; i < vecCom.size(); i++)
		{
			vvb[vecCom[i].nTeam - 1] = true;
			if (vecCom[i].nState == 'C')
			{
				if (vvCrtPenalty[vecCom[i].nTeam - 1][vecCom[i].nProblem - 1] == 0)
					vvCrtPenalty[vecCom[i].nTeam - 1][vecCom[i].nProblem - 1] = vecCom[i].nTime;
			}
			else if (vecCom[i].nState == 'I')
			{
				if (vvCrtPenalty[vecCom[i].nTeam - 1][vecCom[i].nProblem - 1] == 0)
					vvIcrtPenalty[vecCom[i].nTeam - 1][vecCom[i].nProblem - 1] += 20;
			}
		}
		vector<Rank> vr;
		Rank rank;
		for (int i = 0; i < 100; i++)
		{
			if (vvb[i])
			{
				rank.nTeam = i + 1;
				rank.nSolved = 0;
				rank.nTime = 0;
				for (int j = 0; j < 9; j++)
				{
					if (vvCrtPenalty[i][j] != 0)
					{
						rank.nSolved++;
						rank.nTime += vvCrtPenalty[i][j] + vvIcrtPenalty[i][j];
					}
				}
				vr.push_back(rank);
			}
		}
		sort(vr.begin(), vr.end());
		for (int i = vr.size(); i > 0; i--)
			cout << vr[i - 1].nTeam << ' ' << vr[i - 1].nSolved << ' ' << vr[i - 1].nTime << endl;
		
		if (i != Testcase - 1) 
			cout << endl;
	}
	return 0;
}
