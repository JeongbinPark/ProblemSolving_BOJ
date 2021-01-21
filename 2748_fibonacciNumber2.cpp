#include <iostream>
using namespace std;

long long fibo[91];

int main() {
	int n;
	cin >> n;

	fibo[0] = 0;
	fibo[1] = 1;
	for (int i = 2; i <= n; i++)
		fibo[i] = fibo[i - 1] + fibo[i - 2];

	cout << fibo[n];
	return 0;
}
//바보야... unsigned int는 끽해봐야 int 양수의 2배인데... 
//단위 자체가 다른데....