#include<iostream>
#include<string>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

int main(int argc, char *argv[])
{
	int Testcase;
	cin >> Testcase;
	cin.get();
	cin.get();
	string crypTarget = "the quick brown fox jumps over the lazy dog";
	char crypPos[80];//주어진 암호의 1,0 구분 
	memset(crypPos, 0, sizeof(crypPos));
	for (int i = 0; i < crypTarget.size(); i++)
	{
		if (crypTarget[i] != ' ')
			crypPos[i] = 'b';
		else
			crypPos[i] = 'a';
	}

	for (int i = 0; i < Testcase; i++)
	{
		int allalpha = 0;
		int thatnum;
		int num = -1;
		int flag = 0;
		vector<string> input;//입력값 전체를 저장하는 변수
		vector<string> ret;//결과값 담는 배열

		string tmp; //입력값 하나당을 저장하기 위한 임시 변수
		string changeValue; //크기가 같은 배열이 변화 값의 기준이 된다.

		while (getline(cin, tmp))
		{
			num++;
			char cryp[80]; //입력값의 1,0 구분
			memset(cryp, 0, sizeof(cryp));

			if (tmp != "")
			{
				for (int i = 0; i < tmp.size(); i++)
				{
					if (tmp[i] == ' ')
						cryp[i] = 'a';
					else
						cryp[i] = 'b';
				}
				//사이즈가 암호랑 같으면

				/*
				for (int i = 0; i < 80; i++)
				cout << cryp[i] <<" ";
				cout << endl;

				for (int i = 0; i < 80; i++)
				cout << crypPos[i]<<" ";
				cout << endl;
				cout << strncmp(cryp, crypPos, 80) << endl;
				*/

				if (!strcmp(cryp, crypPos) && flag == 0)
				{
					thatnum = num;

					string checkSt = tmp;
				//	sort(checkSt.begin(), checkSt.end());
				//	cout << checkSt << endl;
					for (int i = 97; i <= 122; i++)
					{
						for (int j = 0; j < checkSt.size(); j++)
						{
							char spell = i;
							if (spell == checkSt[j])
							{
								allalpha++;
								break;
							}
						}
					}
					if (allalpha == 26)
					{
						changeValue = tmp;
						input.push_back(crypTarget);
						flag = 1;
					}
					else
						input.push_back(tmp);

				}
				else
				{
					input.push_back(tmp);
				}
			}
			else
				break;
		}
		/*
		int allSpell = 0;
		string crypNum = input[thatnum];
		for (int i = 97; i <= 122; i++)
		for (int j = 0; crypNum.size(); j++)
		if ('i' == crypNum[j])
		{
		allSpell++;
		continue;
		}*/

		if (input.empty())
		{
			cout << "No solution" << endl;
			if (i != Testcase - 1)
				cout << endl;
		}
		else{
			for (int j = 0; j < input.size(); j++)
			{
				if (input[j] == crypTarget)
					ret.push_back(input[j]);
				else//여기서 플레그를 활용한 no solution 삽입해야할듯
				{
					if (flag == 0 && allalpha != 26)
						ret.push_back("No solution");
					else
					{
						string partret;
						string trtmp = input[j];
						for (int i = 0; i < trtmp.size(); i++)
						{
							int match = 0;

							for (int j = 0; j < changeValue.size(); j++)
							if (changeValue[j] == trtmp[i])
							{
								partret += crypTarget[j];
								match = 1;
								break;
							}

							if (!match)
								partret += trtmp[i];
						}
						ret.push_back(partret);
					}
				}
			}

			for (int k = 0; k < ret.size(); k++)
			{
				if (ret[k] == "No solution")
				{
					cout << ret[k] << endl;
					break;
				}
				cout << ret[k] << endl;
			}
			//cout << allalpha << endl;
			if (i != Testcase - 1)
				cout << endl;

		}
	}
	return 0;
}
/*
2

vtz ud xnm xugm itr pyy jttk gmv xt otgm xt xnm puk ti xnm fprxq
xnm ceuob lrtzv ita hegfd tsmr xnm ypwq ktj
frtjrpgguvj otvxmdxd prm iev prmvx xnmq

vtz ud xnm xugm itr pyy jttk gmv xt otgm xt xnm puk ti xnm fprxq
xnm ceuob lrtzv ita hegfd tsmr xnm ypwq ktj
frtjrpgguvj otvxmdxd prm iev prmvx xnmq
*/
