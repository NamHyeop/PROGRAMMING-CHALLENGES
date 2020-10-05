//결과는 맞는데
//종료문 설정을 어떻게 해야할 지 몰라 실행초과 나옴

#include<bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[])
{
	while (1)
	{
		string tmpstr;
		vector<string> vecstrText;
		while (getline(cin, tmpstr))
		{
			if (tmpstr == "")
				break;
			while (!tmpstr.empty() && tmpstr.back() == ' ') 
				tmpstr.pop_back();
			vecstrText.push_back(tmpstr);
		}
		int i = 0;
		while (i < vecstrText.size())
		{
			if (vecstrText[i].empty())
			{
				cout << endl;
				i++;
			}
			else
			{
				string strPara(vecstrText[i++]);
				while (i < vecstrText.size())
				{
					if (!vecstrText[i].empty() && vecstrText[i][0] != ' ')
					{
						strPara.push_back(' ');
						strPara += vecstrText[i++];
					}
					else 
						break;
				}
				
				int len = 0, i = 0, j = 0;
				while (i < strPara.size())
				{
					string strWord, strSpace;
					
					while (strPara[j] == ' ') 
						strSpace.push_back(strPara[j++]);
					
					while (j < strPara.size() && strPara[j] != ' ') 
						strWord.push_back(strPara[j++]);
					if (len + strSpace.size() + strWord.size() < 73)
					{
						cout << strSpace << strWord;
						len += strSpace.size() + strWord.size();
						i = j;
					}
					else{
						cout << endl;
						cout << strWord;
						len = strWord.size();
						i = j;
					}
				}
				cout << endl;
			}
		}
		cout << endl;
	}
	return 0;
}
