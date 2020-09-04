#include <iostream>
#include <algorithm>
using namespace std;
int main(void)
{
	long input1, input2;
	while (cin >> input1 >> input2)
	{
		if (input1 > input2)
		{
			long tmp = input1;
			input1 = input2;
			input2 = tmp;
		}
		long ret = 0;
		for (long i = input1; i <= input2; i++)
		{
			long j = i;
			long length = 1;
			while (j != 1)
			{
				if (j & 1)
				{
					j = j * 3 + 1;
					length++;
				}
				while (!(j & 1))
				{
					j >>= 1;
					length++;
				}
			}
			ret = max(ret, length);
		}
		cout << input1 << " " << input2 << " " << ret << endl;
	}
	return 0;
}
*/

/*
#include<iostream>

using namespace std;

int main(void)
{
	long lbound, ubound, lbOrg, ubOrg, temp;
	long i, j, length, max_length;

	while (scanf("%ld %ld", &lbound, &ubound) == 2)
	{
		lbOrg = lbound;
		ubOrg = ubound;
		if (lbound > ubound)
		{
			temp = lbound;
			lbound = ubound;
			ubound = temp;
		}
		max_length = 0;
		for (i = lbound; i <= ubound; i++)
		{
			j = i;
			length = 1;
			while (j != 1)
			{
				if (j & 1)
				{
					j = j * 3 + 1;
					length++;
				}
				while (!(j & 1))
				{
					j >>= 1;
					length++;
				}
			}
			if (length > max_length)
				max_length = length;
		}
		cout << lbOrg << " " << ubOrg << " " << max_length << endl;
	}
}
