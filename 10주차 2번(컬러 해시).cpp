#include<bits/stdc++.h>
using namespace std;
map<string, string> board;

string moveLeftA(string v) {
	static char t1, t2;
	string tn;
	tn = v;
	t1 = tn[11], t2 = tn[10];
	tn[11] = tn[9], tn[10] = tn[8], tn[9] = tn[7];
	tn[8] = tn[6], tn[7] = tn[5], tn[6] = tn[4];
	tn[5] = tn[3], tn[4] = tn[2], tn[3] = tn[1];
	tn[2] = tn[0], tn[1] = t1, tn[0] = t2;
	return tn;
}
string moveRightB(string v) {
	static char t1, t2;
	string tn;
	tn = v;
	t1 = tn[9], t2 = tn[10];
	tn[9] = tn[11], tn[10] = tn[12], tn[11] = tn[13];
	tn[12] = tn[14], tn[13] = tn[15], tn[14] = tn[16];
	tn[15] = tn[17], tn[16] = tn[18], tn[17] = tn[19];
	tn[18] = tn[20], tn[19] = t1, tn[20] = t2;
	return tn;
}
string moveLeftC(string v) {
	static char t1, t2;
	string tn;
	tn = v;
	t1 = tn[9], t2 = tn[10];
	tn[9] = tn[11], tn[10] = tn[0], tn[11] = tn[1];
	tn[0] = tn[2], tn[1] = tn[3], tn[2] = tn[4];
	tn[3] = tn[5], tn[4] = tn[6], tn[5] = tn[7];
	tn[6] = tn[8], tn[7] = t1, tn[8] = t2;
	return tn;
}
string moveRightD(string v) {
	static char t1, t2;
	string tn;
	tn = v;
	t1 = tn[11], t2 = tn[10];
	tn[11] = tn[9], tn[10] = tn[20], tn[9] = tn[19];
	tn[20] = tn[18], tn[19] = tn[17], tn[18] = tn[16];
	tn[17] = tn[15], tn[16] = tn[14], tn[15] = tn[13];
	tn[14] = tn[12], tn[13] = t1, tn[12] = t2;
	return tn;
}
void operateBFS() 
{
	
	queue<string> Q;
	string st_ta;
	string next;
	board["034305650121078709T90"] = "";
	Q.push("034305650121078709T90");
	while (!Q.empty())
	{
		st_ta = Q.front(), Q.pop();
		string &st_tmp = board[st_ta];
		if (st_tmp.length() >= 8)
			continue;
		//왼쪽 바퀴를 시계 방향으로
		next = moveLeftC(st_ta);
		string &clo1 = board[next];
		if (clo1 == "")
		{
			clo1 = "1" + st_tmp;
			Q.push(next);
		}
		//오른쪽 바퀴를 시계방향으로
		next = moveRightD(st_ta);
		string &clo2 = board[next];
		if (clo2 == "")
		{
			clo2 = "2" + st_tmp;
			Q.push(next);
		}
		//왼쪽 바퀴를 반시계 방향으로
		next = moveLeftA(st_ta);
		string &clo3 = board[next];
		if (clo3 == "")
		{
			clo3 = "3" + st_tmp;
			Q.push(next);
		}
		//오른쪽 바퀴를 반시계 방향으로
		next = moveRightB(st_ta);
		string &clo4 = board[next];
		if (clo4 == "")
		{
			clo4 = "4" + st_tmp;
			Q.push(next);

		}
	}
}
void check(string tn) {
	map<string, string> panbo;
	map<string, string>::iterator it;
	string next;
	queue<string> Q;
	panbo[tn] = "";
	Q.push(tn);
	while (!Q.empty()) 
	{
		tn = Q.front();
		Q.pop();
		string &st_tmp = panbo[tn];
		it = board.find(tn);
		if (it != board.end())
		{
			cout << st_tmp << it->second << '\n';
			return;
		}
		if (st_tmp.length() >= 8)
			continue;
		
		next = moveLeftA(tn);
		string &clo1 = panbo[next];
		if (clo1 == "")
		{
			clo1 = st_tmp + "1";
			Q.push(next);
		}
		next = moveRightB(tn);
		string &clo2 = panbo[next];
		if (clo2 == "")
		{
			clo2 = st_tmp + "2";
			Q.push(next);
		}
		next = moveLeftC(tn);
		string &clo3 = panbo[next];
		if (clo3 == "")
		{
			clo3 = st_tmp + "3", Q.push(next);
		}
		next = moveRightD(tn);
		string &clo4 = panbo[next];
		if (clo4 == "")
		{
			clo4 = st_tmp + "4";
			Q.push(next);
		}
	}
	cout << "NO SOLUTION WAS FOUND IN 16 STEPS" << '\n';
}
int main(int argc, char *argv[]) 
{
	
	int Testcase;
	cin >> Testcase;
	
	operateBFS();
	for(int i =0; i< Testcase; i++)
	{
		int tmp;
		string str = "";
	//	str = " ";
		for (int i = 0; i < 24; i++)
		{
			cin >> tmp;
			if (i < 21) 
			{
				if (tmp == 10)
					str += 'T';
				else
					str += (char)(tmp + '0');
			}
		}
		if (str == "034305650121078709T90")
			cout <<"PUZZLE ALREADY SOLVED" <<'\n';
		else
			check(str);
			
	}
	return 0;
}
