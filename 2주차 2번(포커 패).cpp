//2 5 8 11 14      17 20 23 26 29 다 같고 && 
//2H 3D 5S 9C KD 2C 3H 4S 8C AH
//패의 위위 비교
//각 패의 최대값 저장

#include<iostream>

#define get_value(x) ((x) / 10)
#define get_suit(x) ((x) % 10)
using namespace std;

int encode_card(char *input)
{
	int result;
	switch (input[0])
	{
	case 'T': result = 100; break;
	case 'J': result = 110; break;
	case 'Q': result = 120; break;
	case 'K': result = 130; break;
	case 'A': result = 140; break;
	default: result = (input[0] - '0') * 10;
	}
	switch (input[1])
	{
	case 'H': result += 1;break;
	case 'D': result += 2;break;
	case 'S': result += 3;break;
	case 'C': result += 4;break;
	}
	return result;
}

long get_hand_value(int hand[5])
{
	int i, j, max, temp;
	int value[5], suit[5];
	long result;
	for (i = 0; i < 4; i++)
	{
		max = i;
		for (j = i + 1; j < 5; j++)
		if (hand[j] > hand[max])
			max = j;
		temp = hand[i];
		hand[i] = hand[max];
		hand[max] = temp;
	}
	for (i = 0; i < 5; i++)
	{
		value[i] = get_value(hand[i]);
		suit[i] = get_suit(hand[i]);
	}

	//스트레이트 플러쉬
	if (value[1] + 1 == value[0] && suit[1] == suit[0]
		&& value[2] + 2 == value[0] && suit[2] == suit[0]
		&& value[3] + 3 == value[0] && suit[3] == suit[0]
		&& value[4] + 4 == value[0] && suit[4] == suit[0])
		return result = (9 << 20) + (value[0] << 16);
	
	//포카드
	if (value[0] == value[3] || value[1] == value[4])
	{
		result = (8 << 20) + (value[1] << 16);
		return result;
	}

	//풀하우스
	if (value[0] == value[2] && value[3] == value[4])
	{
		result = (7 << 20) + (value[0] << 16);
		return result;
	}
	if (value[0] == value[1] && value[2] == value[4])
	{
		result = (7 << 20) + (value[0] << 16);
		return result;
	}
	
	//플러쉬
	if (suit[0] == suit[1] && suit[0] == suit[2] && suit[0] == suit[3] && suit[0] == suit[4])
	{
		result = (6 << 20) + (value[0] << 16) + (value[1] << 12) + (value[2] << 8) + (value[3] << 4) + value[4];
		return result;
	}
	
	//스트레이트
	if (value[0] == value[1] + 1 && value[1] == value[2] + 1 && value[2] == value[3] + 1 && value[3] == value[4] + 1)
	{
		result = (5 << 20) + (value[0] << 16);
		return result;
	}

	//쓰리 카드
	if (value[0] == value[2] || value[1] == value[3] || value[2] == value[4])
	{
		result = (4 << 20) + (value[2] << 16);
		return result;
	}
	
	//투 페어
	if (value[0] == value[1] && value[2] == value[3])
	{
		result = (3 << 20) + (value[0] << 16) + (value[2] << 12) + (value[4] << 8);
		return result;
	}
	if (value[0] == value[1] && value[3] == value[4])
	{
		result = (3 << 20) + (value[0] << 16) + (value[3] << 12) + (value[2] << 8);
		return result;
	}
	if (value[1] == value[2] && value[3] == value[4])
	{
		result = (3 << 20) + (value[1] << 16) + (value[3] << 12) + (value[0] << 8);
		return result;
	}

	//원 페어
	if (value[0] == value[1])
	{
		result = (2 << 20) + (value[0] << 16) + (value[2] << 12) + (value[3] << 8) + (value[4] << 4);
		return result;
	}
	if (value[1] == value[2])
	{
		result = (2 << 20) + (value[1] << 16) + (value[0] << 12) + (value[3] << 8) + (value[4] << 4);
		return result;
	}
	if (value[2] == value[3])
	{
		result = (2 << 20) + (value[2] << 16) + (value[0] << 12) + (value[1] << 8) + (value[4] << 4);
		return result;
	}
	if (value[3] == value[4])
	{
		result = (2 << 20) + (value[3] << 16) + (value[0] << 12) + (value[1] << 8) + (value[2] << 4);
		return result;
	}
	//하이 카드
	else
	{
		result = (1 << 20) + (value[0] << 16) + (value[1] << 12) + (value[2] << 8) + (value[3] << 4) + value[4];
		return result;
	}

}


int main(int argc, char *arav[])
{
	char input[100];
	int cmpinput[2][5];
	long long cmpValue[2];


	while (gets(input))
	{
		int blank = 0;
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if(input[blank] == ' ')
					blank++;
				cmpinput[i][j] = encode_card(input+blank);
				blank += 2;
			}
			cmpValue[i] = get_hand_value(cmpinput[i]);
		}
		
		if (cmpValue[0] > cmpValue[1])
			printf("Black wins.\n");
		else if (cmpValue[0] < cmpValue[1])
			printf("White wins.\n");
		else
			printf("Tie.\n");
			
	}
	return 0;
}
