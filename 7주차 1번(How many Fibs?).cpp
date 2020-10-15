#include<bits/stdc++.h>

using namespace std;

#define MAXDIGIT 100

static char a[MAXDIGIT + 1], b[MAXDIGIT + 1];
static char fib[3][MAXDIGIT + 1];
static int lengtha, lengthb, length[3];
static int result;

int input(void)
{
	int i;
	char tempa[MAXDIGIT + 1], tempb[MAXDIGIT + 1];

	scanf("%s", tempa);
	scanf("%s", tempb);

	//둘다 0일경우 0부터 0까지는 0이다.
	if (tempa[0] == '0' && tempb[0] == '0')
		return 0;
	
	lengtha = strlen(tempa);
	lengthb = strlen(tempb);

	for (i = 0; i < lengtha; i++)
		a[i] = tempa[lengtha - i - 1] - '0';
	for (i = 0; i < lengthb; i++)
		b[i] = tempb[lengthb - i - 1] - '0';
	return 1;
}

int compare(int fi, char *numb, int len)
{
	int i;
	if (length[fi] < len)
		return -1;
	if (length[fi] > len)
		return 1;
	for (i = len - 1; i >= 0; i--)
	{
		if (fib[fi][i] < numb[i])
			return -1;
		if (fib[fi][i] > numb[i])
			return 1;
	}
	return 0;
}

void operate(int target, int a, int b)
{
	int len = 0, carry = 0;
	for (; len < length[a] && len < length[b]; len++)
	{
		fib[target][len] = (fib[a][len] + fib[b][len] + carry);
		if (fib[target][len] >= 10)
			carry = 1;
		else
			carry = 0;
		fib[target][len] %= 10;
	}
	if (len < length[a])
	{
		for (; len < length[a]; len++)
		{
			fib[target][len] = (fib[a][len] + carry);
			if (fib[target][len] >= 10)
				carry = 1;
			else
				carry = 0;
			fib[target][len] %= 10;
		}
	}
	else
	{
		for (; len < length[b]; len++)
		{
			fib[target][len] = (fib[b][len] + carry);
			if (fib[target][len] >= 10)
				carry = 1;
			else
				carry = 0;
		}
	}
	if (carry)
		fib[target][len++] = 1;
	length[target] = len;
}
int main(int argc, char*argv[])
{
	int i;
	while (input())
	{
		length[0] = length[1] = 1;
		fib[0][0] = fib[1][0] = 1;

		for (i = 1; compare(i % 3, a, lengtha) < 0; i++)
			operate((i + 1) % 3, i % 3, (i - 1) % 3);
		result = i;
		for (; compare(i % 3, b, lengthb) <= 0; i++)
			operate((i + 1) % 3, i % 3, (i - 1) % 3);
		result = i - result;
		printf("%d\n", result);

	}
}

