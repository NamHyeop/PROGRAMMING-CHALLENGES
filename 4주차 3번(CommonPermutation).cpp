#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int main(int argc, char *argv[])
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string a, b;

	while (getline(cin, a) && getline(cin,b))
	{

		if (a == "" || b == "")
		{
			cout << '\n';
			continue;
		}
		
		vector<int>entrance(a.size(),0);
		
		string ret;
		for (int i = 0; i < b.size(); i++)
		for (int j = 0; j < a.size(); j++)
		if (a.find(b[i], j) != -1 && entrance[a.find(b[i], j)] == 0)
		{
			entrance[a.find(b[i], j)] = 1;
			ret += b[i];
			break;
		}
		//else
		//	break;
		
		sort(ret.begin(), ret.end());

		cout <<ret << '\n';
	}
}
