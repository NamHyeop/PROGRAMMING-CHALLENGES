#include<iostream>
#include<vector>
#include<string>
using namespace std;

int my[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int mx[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

char map[51][51];
int row, col;
int flag = 0;

int search(string &sentance, int y, int x, int count,int k)
{
	//찾는 문자열의 사이즈와 찾는 문자의 갯수가 동일하면 true출력
	if (count == sentance.size())
		return 1;

	if (x < 0 || y < 0 || y > row || x > col)
		return 0;
	
	//map이 대문자이고 
	if ('A' <= map[y][x] && map[y][x] <= 'Z')
	{	//찾는 문자가 대문자인 경우
		if ('A' <= sentance[count] && sentance[count] <= 'Z')
		{
			if (sentance[count] == map[y][x])
			return search(sentance, y + my[k], x + mx[k], count + 1,k);
		}
		else//찾는 문자가 소문자인 경우
		{
			char a = sentance[count] - 32;
			if (a == map[y][x])
			return search(sentance, y + my[k], x + mx[k], count + 1,k);
		}
	}
	else//map이 소문자이고
	{
		//찾는 문자가 대문자인 경우
		if ('A' <= sentance[count] && sentance[count] <= 'Z')
		{
			char a = sentance[count] + 32;
			if (a == map[y][x])
			return search(sentance, y + my[k], x + mx[k], count + 1,k);
		}
		else//찾는 문자가 소문자인 경우
		{
			if (sentance[count] == map[y][x])
			return search(sentance, y + my[k], x + mx[k], count + 1,k);
		}
	}
	return 0;
}

int main(int argc, char * argv[])
{
	cin.tie(NULL);
	ios_base::sync_with_stdio;

	int Testcase;
	cin >> Testcase;

	for (int i = 0; i < Testcase; i++)
	{
		cin >> row >> col;

		//입력값 설정
		for (int i = 0; i < row; i++)
		{
			string input;
			cin >> input;
			for (int j = 0; j < col; j++)
				map[i][j] = input[j];
		}

		int searchnum;
		cin >> searchnum;

		for (int i = 0; i < searchnum; i++)
		{
			string sentance;
			cin >> sentance;
			flag = 0;
			//한 쪽 방향(k)으로만 검사를 해서 맞을 경우 시작 지점을 출력한다.
			for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
			for (int k = 0; k < 8; k++)
			if (search(sentance, i, j, 0, k))
			{	
				if (flag == 1)
					continue;
				flag = 1;
				cout << i + 1 << " " << j + 1 << endl;
			}
			
		}
		cout << endl;
	}
	return 0;
}


/*
1

8 11
abcDEFGhigg
hEbkWalDork
FtyAwaldORm
FtsimrLqsrc
byoArBeDeyv
Klcbqwikomk
strEBGadhrb
yUiqlxcnBjf
1
Betty
*/

/*일직선이 아닌 모든 경우의 수
int search(string &sentance, int y, int x, int count)
{
if (x < 0 || y < 0 || y > row - 1 || x > col - 1)
return 0;

if (count == sentance.size())
{
flag = true;
return 0;
}
if ('A' <= map[y][x] && map[y][x] <= 'Z')
{
if ('A' <= sentance[count] && sentance[count] <= 'Z')
{
if (sentance[count] == map[y][x])
for (int i = 0; i < 8; i++)
search(sentance, y + my[i], x + mx[i], count + 1);
}
else
{
char a = sentance[count] - 32;
if (a == map[y][x])
for (int i = 0; i < 8; i++)
search(sentance, y + my[i], x + mx[i], count + 1);
}
}
if ('a' <= map[y][x] && map[y][x] <= 'z')
{
if ('A' <= sentance[count] && sentance[count] <= 'Z')
{
char a = sentance[count] + 32;
if (a == map[y][x])
for (int i = 0; i < 8; i++)
search(sentance, y + my[i], x + mx[i], count + 1);
}
else
{
if (sentance[count] == map[y][x])
for (int i = 0; i < 8; i++)
search(sentance, y + my[i], x + mx[i], count + 1);
}
}
return 0;
}*/
