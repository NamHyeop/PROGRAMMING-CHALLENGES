#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(int argc, char*argv[])
{
	int Testcase;
	cin >> Testcase;

	for (int i = 0; i < Testcase; i++)
	{
		int count;
		cin >> count;
		int state;
		int value;

		
		vector<vector<int>> input(count+1, vector<int>(53, 0));
		vector<int> card(53, 0), latecard(53,0);

		for (int i = 1; i <= 52; i++)
			card[i] = i;
	
		for (int i = 1; i <= count; i++)
		for (int j = 1; j <= 52; j++)
			cin >> input[i][j];
		
		cin.ignore();
		
		int cur;
		string tmpcur;
		while (getline(cin, tmpcur))
		{
			if (tmpcur.empty())
				break;
			cur = stoul(tmpcur);

      //핵심 부분 배열의 위치를 전 배열의 위치의 값으로 계속 변경
			for (int i = 1; i <= 52; i++)
				latecard[i] = card[i];
			for (int i = 1; i <= 52; i++)
				card[i] = latecard[input[cur][i]];
		}
		
		for (int i = 1; i <= 52; i++)
		{
			value = (card[i] - 1) % 13;
			state = (card[i] - 1) / 13;
			
			if (0 <= value && value <= 8)
				cout << value + 2<<" ";
			else if (value == 9)
				cout << "Jack"<<" ";
			else if (value == 10)
				cout << "Queen"<<" ";
			else if (value == 11)
				cout << "King"<<" ";
			else if (value == 12)
				cout << "ACE"<<" ";
			
			cout << "of";

			if (state == 0)
				cout << " Clubs" << endl;
			else if (state == 1)
				cout << " Diamonds" << endl;
			else if (state == 2)
				cout << " Hearts" << endl;
			else if (state == 3)
				cout << " Spades" << endl;
		}
		if (i != Testcase - 1)
			cout << endl;
	}
	return 0;
}
