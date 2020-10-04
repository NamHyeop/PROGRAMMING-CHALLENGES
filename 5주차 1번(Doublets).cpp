#include<iostream>
#include<vector>
#include<string>
#include<deque>

using namespace std;

int main(int argc, char *argv[])
{
	vector<string> strarr;
	string strtmp;
	while (getline(cin, strtmp))
	{
		if (strtmp.size() == 0)
			break;
		strarr.push_back(strtmp);
	}

	vector<vector<int>> relationDB(strarr.size(), vector<int>(strarr.size(), 0));

	//트리로 input들의 서로 관계 여부를 확인함
	for (int i = 0; i < strarr.size(); i++)
	for (int j = i; j < strarr.size(); j++)
	{
		//1.두 input들의 사이즈가 같고
		if (strarr[i].size() == strarr[j].size())
		{
			int count = 0;
			for (int k = 0; k < strarr[i].size(); k++)
			{
				if (strarr[i][k] != strarr[j][k])
				{
					count++;
					if (count > 1) //2.1보다 크면 더블릿 관계 성립 불가 
						break;
				}
			}
			//3.count가 1이면 서로 관계 성립 
			if (count == 1)
			{
				relationDB[i][j] = 1;
				relationDB[j][i] = 1;
			}
		}
	}

	string st_word;
	string fi_word;
	
	while (cin >> st_word >> fi_word)
	{

	//	if (st_word.size() == 0 || fi_word.size() == 0)
	//		break;

		vector<int> path;
		vector<int> ret;
		vector<int> log(strarr.size(), 0);
		int start = -1;
		int end = -1;
		//시작 지점 끝 지점 설정
		for (int i = 0; i < strarr.size(); i++)
		{
			if (st_word == strarr[i])
				start = i;
			if (fi_word == strarr[i])
				end = i;
		}
		//시작 지점과 끝 지점을 못 찾을 경우 진행
		if (start == -1 || end == -1)
			continue;

		path.push_back(start);
		log[start] = 1;

     //탐색 시작
		vector<int> tmplog(strarr.size(), 0);
		deque<pair<int, vector<int>>> dq;
		dq.push_back({ start, vector<int>(1, start) }); //
		tmplog[start] = true;
		pair<int, vector<int>> road;
		while (!dq.empty())
		{
			road = dq.front();
			dq.pop_front();

			if (road.first == end)
				break;
			for (int i = 0; i < strarr.size(); i++)
			{
				if (relationDB[road.first][i] && !tmplog[i])
				{
					vector<int> tmpPath(road.second);
					tmplog[i] = true;
					tmpPath.push_back(i);
					dq.push_back({ i, tmpPath });
				}
			}
		}
		if (road.first == end)
			ret = road.second;

		if (ret.empty())
			cout << "No solution." << '\n';
		else
		{
		//	for (auto idx : ret)
		//	{
		//		cout << strarr[idx] << endl;
		//	}
			for (int i = 0; i < ret.size(); i++)
				cout << strarr[ret[i]] << '\n';
		}

		cout << '\n';
		//cin.get();
	}
}


