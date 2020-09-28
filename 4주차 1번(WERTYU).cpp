#include<iostream>

using namespace std;

int main(int argc, char *argv[])
{
	char spell;
	while (scanf("%c", &spell) == 1) //길이 반환안할시 오류 , 문제 설명이 미흡해 보임.. 문제 자체는 계속 받는다로 해석이 되는데...
	{
		if ('B' <= spell && spell <= 'P')
		{
			switch (spell)
			{
			case 'B':
				cout << 'V';
				break;
			case 'C':
				cout << 'C';
				break;
			case 'D':
				cout << 'S';
				break;
			case 'E':
				cout << 'W';
				break;
			case 'F':
				cout << 'D';
				break;
			case 'G':
				cout << 'F';
				break;
			case 'H':
				cout << 'G';
				break;
			case 'I':
				cout << 'U';
				break;
			case 'J':
				cout << 'H';
				break;
			case 'K':
				cout << 'J';
				break;
			case 'L':
				cout << 'K';
				break;
			case 'M':
				cout << 'N';
				break;
			case 'N':
				cout << 'B';
				break;
			case 'O':
				cout << 'I';
				break;
			case 'P':
				cout << 'O';
				break;
			}
		}
		else if ('R' <= spell && spell <= 'Y')
		{
			switch (spell)
			{
			case 'R':
				cout << 'E';
				break;
			case 'S':
				cout << 'A';
				break;
			case 'T':
				cout << 'R';
				break;
			case 'U':
				cout << 'Y';
				break;
			case 'V':
				cout << 'C';
				break;
			case 'W':
				cout << 'Q';
				break;
			case 'X':
				cout << 'Z';
				break;
			case 'Y':
				cout << 'T';
				break;
			}
		}
		else if ('0' <= spell && spell <= '9')
		{
			switch (spell)
			{
			case '0':
				cout << '9';
				break;
			case '1':
				cout << '`';
				break;
			case '2':
				cout << '1';
				break;
			case '3':
				cout << '2';
				break;
			case '4':
				cout << '3';
				break;
			case '5':
				cout << '4';
				break;
			case '6':
				cout << '5';
				break;
			case '7':
				cout << '6';
				break;
			case '8':
				cout << '7';
				break;
			case '9':
				cout << '8';
				break;
			}
		}
		else if (spell == '-' || spell == '=' || spell == '['
			|| spell == ']' || spell == '\\' || spell == ';'
			|| spell == '\'' || spell == ',' || spell == '.' || spell == '/')
		{
			switch (spell)
			{
			case '-':
				cout << '0';
				break;
			case '=':
				cout << '-';
				break;
			case '[':
				cout << 'P';
				break;
			case ']':
				cout << '[';
				break;
			case '\\':
				cout << ']';
			case ';':
				cout << 'L';
				break;
			case '\'':
				cout << ';';
				break;
			case ',':
				cout << 'M';
				break;
			case '.':
				cout << ',';
				break;
			case '/':
				cout << '.';
				break;
			}
		}
		else
			cout << spell;
	}
}
