#include<iostream>
#include<vector>
using namespace std;

int y, x;

int cury[9] = { -1, -1, -1, 0, 0, 0, 1, 1, 1 };
int curx[9] = { -1, 0, 1, -1, 0, 1, -1, 0, 1 };

int search(int my, int mx, vector<vector <char>> &board, vector<vector <int>> &ret)
{
	//1.범위를 벗어나면 종료
	if (my < 0 || my>=y || mx < 0 || mx >= x)
		return 0;

	//2.지뢰인 경우
	if (board[my][mx] == '*')
	{
		ret[my][mx] = -1;
		for (int i = 0; i < 9; i++)
		{
			//범위를 초과하지 않는다면 밑에 조건문 실행(지뢰는 그대로 나둬야 하니 지뢰가 아닐 경우 숫자를 증가시키겠다.)
			if (my+cury[i] < 0 || my+cury[i] >= y || mx+curx[i] < 0 || mx + curx[i] >= x )
				continue;

			if (board[my + cury[i]][mx + curx[i]] != '*')
			{
				ret[my + cury[i]][mx + curx[i]] += 1;
			}
		}
		return search(my + 1, mx, board, ret) ;
	}

	//3.지뢰가 아닌 경우
	else
	{
		if (board[my][mx] != '*')
			return search(my+ 1, mx, board,ret);
	}
}

int main(int argc, char * argv[])
{
	int tmp = 1;
	do{
		cin >> y >> x;

		//1.문자열 입력을 받을 백터 변수 
		vector<vector <char>> board(y, vector<char>(x, 0));
		//2.문자열 받은 입력을 함수를 통해 만들 정답 변수
		vector<vector <int>> ret(y, vector<int>(x, 0));
		if (y == 0 && x == 0)
			return 0;
		
		//3.입력값 초기화
		for (int i = 0; i < y; i++)
		for (int j = 0; j < x; j++)
				cin >> board[i][j];
		
		//4.y축을 증가하면서 x축은 함수를 통한 재귀를 실행하여 정답 변수 ret 작성
		for (int i = 0; i < x; i ++)
		{
			search(0, i, board, ret);
		}

		cout << "Field #" << tmp << ":" <<endl;

		for (int i = 0; i < y; i++)
		{
			for (int j = 0; j < x; j++)
			{
				//5/정답 ret변수안에 -1은 지뢰를 의미함
				if (ret[i][j] == -1)
					cout << '*';
				else
				cout << ret[i][j];
			}
			cout << endl;
		}

		cout << endl;
		tmp++;
	
	} while (y != 0 && x != 0);
}
