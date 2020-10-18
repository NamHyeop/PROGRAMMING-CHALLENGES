#include<bits/stdc++.h>

using namespace std;

string operate(string a, string b)
{
	string s;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	int i = 0;
	int j = 0;
	int tmp = 0;
	while (a[i] && b[i])
	{
		j = a[i] - '0' + b[i] - '0' + tmp;
		tmp = j / 10;
		s += (j % 10 + '0');
		i++;
	}
	if (i == a.size())
	{
		while (i != b.size())
		{
			j = tmp + b[i] - '0';
			tmp = j / 10;
			s += j % 10 + '0';
			i++;
		}
		if (tmp) s += tmp + '0';
	}
	else if (i == b.size())
	{
		while (i != a.size())
		{
			j = tmp + a[i] - '0';
			tmp = j / 10;
			s += j % 10 + '0';
			i++;
		}
		if (tmp) s += tmp + '0';
	}
	reverse(s.begin(), s.end());
	return s;
}
int main(int argc, char*argv[])
{	
	vector<string> arr;
	string parText;

	arr.push_back("0");
	arr.push_back("2");
	arr.push_back("5");
	arr.push_back("13");
	
	for (int i = 4;; i++)
	{
		parText = operate(arr[i - 1], arr[i - 1]);
		parText = operate(arr[i - 2], parText);
		parText = operate(arr[i - 3], parText);
		arr.push_back(parText);
		if (arr[i].size() > 1001) 
			break;
	}

	int n;
	int Value = arr.size();
	while (cin >> n)
		cout << arr[n] << endl;

	return 0;
}
