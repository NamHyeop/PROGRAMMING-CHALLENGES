#include<iostream>
#include<string>
using namespace std;

int main(int argc, char *argv[])
{
	
	string input;
	
	while (getline(cin,input)) //getline을 사용하는 이유는 cin은 공백이 생기면 그것을 다음 변수로 넘겨줌, cin.getline(input, size)표현도 존재
	{
		int words = 0, letters = 0;
		for (int i = 0; i < input.size(); i++)
		{
			//1.input의 첫 부분이 0일때 공백이 아니면 word++, 2.i가 0이상일때는 i앞에가 공백이고 i는 공백이아니면 word++ 
			if ((i == 0) && (input[i] != ' ' && input[i] != '\t') || (i>0 && (input[i - 1] == ' ' || input[i - 1] == '\t') && (input[i] != ' ' && input[i] != '\t')))
				words++;
			//3.걍 공백 아니면 글자수++
			if (input[i] != ' ' && input[i] != '\t')
				letters++;
		}
		cout << letters << " " << words << endl;
	}
	return 0;
}
