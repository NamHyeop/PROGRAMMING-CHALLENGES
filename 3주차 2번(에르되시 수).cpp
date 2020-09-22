#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>

using namespace std;

vector<string> parsing(const string &Text)
{
	vector<string> tmp;
	int start = 0;
	//find랑 substr의 stl이 1차이 나는걸 기억하자
	int end = Text.find(".,", 0);
	while (end != string::npos)
	{
		tmp.push_back(Text.substr(start, end + 1 - start));
		start = end + 3;
		end = Text.find(".,", start);
	}
	tmp.push_back(Text.substr(start));
	return tmp;
}

int main(int argc, char * argv[])
{
	int Testcase;
	cin >> Testcase;
	for (int i = 0; i< Testcase; i++)
	{
		int p;
		int n;
		cin >> p;
		cin >> n;
		cin.ignore();
		string Text;
		vector<string> psText;
		map<string, int> sortMap;
		map<string, set<string>> treeMap;

		for (int i = 0; i <p; i++)
		{
			getline(cin, Text);
			//파싱 과정
			psText = parsing(Text.substr(0, Text.find_first_of(":")));

			for (int i = 0; i < psText.size(); i++)
			for (int j = 0; j < psText.size(); j++)
			if (i != j)
				treeMap[psText[i]].insert(psText[j]);
		}

		//에르되시수를 계산하는 과정 exist에 먼저 에르도수를 삽입하고(0순위기 때문에) 에르도수랑 연결된
		//treeMap을 탐색하여 1순위를 구하고
		//그렇게 exist에 삽입된 제자들과 연결된 사람들을 탐색하고(이때 안에 이미 있을 경우 삽입 안함, 그래야 우선순위를 넘지 않음)
		//이같은 과정이 에르되시완 연관된 사람이 없을 때까지 반복한다.
		set<string> exist;
		set<string> newExist;
		exist.insert("Erdos, P.");
		sortMap["Erdos, P."] = 0;
		int ErdosNum = 1;
		while (1)
		{
			for (auto Person = exist.begin(); Person != exist.end(); Person++)
			{
				if (treeMap.find(*Person) != treeMap.end())
				{
					set<string> &cur = treeMap.at(*Person);
					for (auto next = cur.begin(); next != cur.end(); next++)
					{
						if (sortMap.find(*next) == sortMap.end())
						{
							sortMap[*next] = ErdosNum;
							newExist.insert(*next);
						}
					}
				}
			}
			if (newExist.empty())
				break;
			ErdosNum++;
			exist = newExist;
			newExist.clear();
		}

		cout << "Scenario " << i + 1 << endl;
		string Professor;
		for (int j = 0; j<n; j++)
		{
			getline(cin, Professor);
			cout << Professor << ' ';
			auto i = sortMap.find(Professor);
			if (i != sortMap.end())
				cout << i->second << endl;
			else
				cout << "infinity" << endl;
		}
	}
	return 0;
}
