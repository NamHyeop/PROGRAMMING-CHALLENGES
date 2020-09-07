#include <iostream>
#include <vector>
#include <math.h>
//floorf를 사용하기 위한 math추가. 자기가 원하는 소수점 자리수만 필요할 때 사용
//맨 마지막 출력에 $표시를 확인 못하고 문제 제출하여 Testcase가 전부 실패해서 순간적으로 억장이 무너짐

using namespace std;
int main() {
	int Testcase;
	do{
		cin >> Testcase;
		float result = 0;
		float tmp = 0;
		vector<float> v(Testcase, 0);
		
		if(Testcase == 0)
			return 0;
		
		for(int i =0; i<v.size(); i++)
		{
			cin >> v[i];
			tmp+= v[i];
		}
		tmp /= Testcase;
		
		for(int i = 0; i < v.size(); i++)
			if(v[i] > tmp)
				result+= floorf((v[i]-tmp) * 100) / 100;
		
		printf("$%.2f\n", result);

		}while(1);
	
	return 0;
}
