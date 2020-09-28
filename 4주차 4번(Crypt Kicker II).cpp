//이 문제에 대해서는 제 코드를 저 말고는 아무도 안 보는걸 추천합니다.
//문제가 너무 애매해서 도중에 실험하는 케이스가 너무 많습니다.
//코드의 주석은 제외하시고 보길 바랍니다. 저의 문법 개념이 흔들리는 부분에 대해서 실험한 코드 입니다.
//과제 카피용으로 추천 드립니다.

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
		int reflag = 0;
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
			int allalpha = 0;
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

				if (!strcmp(cryp, crypPos) && flag == 0) //암호 값의 위치와 공백이 같아야함, flag를 둔 이유는 암호가 확실할 경우 암호를 재설정 하는 일이 없게 하기 위함이다. 이 문제에서는 암호가 위에 있는게 최우선시 된다. 문제에 ㅓㅄ음
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
					if (allalpha == 26) //여기서 암호화 키 값이 복화의 중복이 없는지 판단함 
					{
						changeValue = tmp;
						input.push_back(crypTarget);
						flag = 1; //일단 암호가 맞다고 가정하고
						reflag = 0;//암호가 맞으니 복호화가 가능하다 가정하고

						vector<pair<char, char>> a;//복호화 키 값의 중복이 없는지 확인
						for (int i = 0; i < changeValue.size(); i++)
							a.push_back({ changeValue[i], crypTarget[i] });

						for (int i = 0; i < a.size(); i++)
						for (int j = 0; j < a.size(); j++)
						{
							if (i == j)
								continue;
							if (a[i].first != a[j].first)
							{
								if (a[i].second == a[j].second)
								{
									reflag = 1;// 증복이 있을경우 복호화가 불가능 하다고 판단.
									flag = 0; //내려가면서 암호화가 가능한 키가 또 있을수 있으니 다시 flag를 0으로 설정
								}
							}
						}
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

		if (reflag)//암호의 키값이 중첩이 되는것, 예를 들어 x -> t를 가리키는데 z -> t를 가리키는 경우 이 문제에서는 복호화가 불가능 하다고 판단함.
		{
			cout << "No soltion." << endl;
			cout << endl;
		}
		else{
			if (input.empty()) //입력이 공백인 경우 답 없음
			{
				cout << "No solution." << endl;
				if (i != Testcase - 1)
					cout << endl;
			}
			else{
				for (int j = 0; j < input.size(); j++)
				{
					if (input[j] == crypTarget && j == thatnum) //암호 자리 위치라면 암호 값을 넣는다.
						ret.push_back(input[j]);
					else
					{
						if (flag == 0 && allalpha != 26) 
							ret.push_back("No solution.");
						else//파싱 과정
						{
							string partret;
							string trtmp = input[j];
							for (int i = 0; i < trtmp.size(); i++)
							{
								int match = 0;

								for (int j = 0; j < changeValue.size(); j++)/
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
					if (ret[k] == "No solution.")
					{
						cout << ret[k] << endl;
						break;
					}
					cout << ret[k] << endl;
				}
				//cout << allalpha << endl;
				//		if (i != Testcase - 1)
				cout << endl;

			}
		}
		
	}

	return 0;
}
/* input
13

vtz ud xnm xugm itr pyy jttk gmv xt otgm xt xnm puk ti xnm fprxq
xnm ceuob lrtzv ita hegfd tsmr xnm ypwq ktj
frtjrpgguvj otvxmdxd prm iev prmvx xnmq

the quick brown fox jumps over the lazy dog

now is the time for all good men to come to the aid of the party
xnm ceuob lrtzv ita hegfd tsmr xnm ypwq ktj
the quick brown fox jumps over the lazy dog
programming contests are fun arent they

now is the time for all good men to come to the aid of the party
the quick brown fox jumps over the lazy dog
xnm ceuob lrtzv ita hegfd tsmr xnm ypwq ktj
programming contests are fun arent they

hetquicktbrowntfoxtjumpstovert hetlazytdog
the quick brown fox jumps over the lazy dog

vtz ud xnm xugm itr pyy jttk gmv xt otgm xt xnm puk ti xnm fprxq
xnm ceuob lrtzv ita hegfd tsmr xnm ypwq ktj
frtjrpgguvj otvxmdxd prm iev prmvx xnmq

the quick brown fox jumps over the lazy dog

now is the time for all good men to come to the aid of the party
xnm ceuob lrtzv ita hegfd tsmr xnm ypwq ktj
the quick brown fox jumps over the lazy dog
programming contests are fun arent they

now is the time for all good men to come to the aid of the party
the quick brown fox jumps over the lazy dog
xnm ceuob lrtzv ita hegfd tsmr xnm ypwq ktj
programming contests are fun arent they

vtz ud xnm xugm itr pyy jttk gmv xt otgm xt xnm puk ti xnm fprxq
xnm ceuob lrtzv ita hegfd tsmr xnm ypwq ktj
frtjrpgguvj otvxmdxd prm iev prmvx xnmq

vtz ud xnm xugm itr pyy jttk gmv xt otgm xt xnm puk ti xnm fprxq
xnm ceuob lrtzv ita hegfd tsmr znm ypwq ktj
frtjrpgguvj otvxmdxd prm iev prmvx xnmq
vtz ud xnm xugm itr pyy jttk gmv xt otgm xt xnm puk ti xnm fprxq

vtz ud xnm xugm itr pyy jttk gmv xt otgm xt xnm puk ti xnm fprxq
xnm ceuob lrtzv ita hegfd tsmr znm ypwq ktj
frtjrpgguvj otvxmdxd prm iev prmvx xnmq
xnm ceuob lrtzv ita hegfd tsmr xnm ypwq ktj
vtz ud xnm xugm itr pyy jttk gmv xt otgm xt xnm puk ti xnm fprxq
frtjrpgguvj otvxmdxd prm iev prmvx xnmq

now is the time for all good men to come to the aid of the party
oju yifqd krczh pct gieav cnur oju bxwl scm
xnm ceuob lrtzv ita hegfd tsmr xnm ypwq ktj
the quick brown fox jumps over the lazy dog
programming contests are fun arent they
*/

/* output
now is the time for all good men to come to the aid of the party
the quick brown fox jumps over the lazy dog
programming contests are fun arent they

the quick brown fox jumps over the lazy dog

hcz fv oju ofeu pcr xbb mccs euh oc qceu oc oju xfs cp oju axrol
the quick brown fox jumps over the lazy dog
oju yifqd krczh pct gieav cnur oju bxwl scm
arcmrxeefhm qchouvov xru pih xruho ojul

now is the time for all good men to come to the aid of the party
the quick brown fox jumps over the lazy dog
xnm ceuob lrtzv ita hegfd tsmr xnm ypwq ktj
programming contests are fun arent they

hetquicktbrowntfoxtjumpstovert hetlazytdog
the quick brown fox jumps over the lazy dog

now is the time for all good men to come to the aid of the party
the quick brown fox jumps over the lazy dog
programming contests are fun arent they

the quick brown fox jumps over the lazy dog

hcz fv oju ofeu pcr xbb mccs euh oc qceu oc oju xfs cp oju axrol
the quick brown fox jumps over the lazy dog
oju yifqd krczh pct gieav cnur oju bxwl scm
arcmrxeefhm qchouvov xru pih xruho ojul

now is the time for all good men to come to the aid of the party
the quick brown fox jumps over the lazy dog
xnm ceuob lrtzv ita hegfd tsmr xnm ypwq ktj
programming contests are fun arent they

now is the time for all good men to come to the aid of the party
the quick brown fox jumps over the lazy dog
programming contests are fun arent they

No solution.

now is the time for all good men to come to the aid of the party
the quick brown fox jumps over whe lazy dog
programming contests are fun arent they
the quick brown fox jumps over the lazy dog
now is the time for all good men to come to the aid of the party
programming contests are fun arent they

vtz ud xnm xugm itr pyy jttk gmv xt otgm xt xnm puk ti xnm fprxq
the quick brown fox jumps over the lazy dog
avg ometl yrxws uxp nmjik xdgr avg qfzc bxh
xnm ceuob lrtzv ita hegfd tsmr xnm ypwq ktj
frtjrpgguvj otvxmdxd prm iev prmvx xnmq

*/
