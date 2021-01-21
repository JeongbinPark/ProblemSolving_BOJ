#include <iostream>
using namespace std;

int mod = 1000000;
int p = mod / 10 * 15;
int fibo_pisa[1500001] = { 0, 1 };

int main() {
	long long N;
	cin >> N;
	for (int i = 2; i < p; i++) {
		fibo_pisa[i] = fibo_pisa[i - 1] + fibo_pisa[i - 2];
		fibo_pisa[i] %= mod;
	}
	cout << fibo_pisa[N%p];
	return 0;
}
//피사노 주기 이용
//N번째 피보나치 수를 M으로 나눈 나머지는
//N%P번째 피보나치 수를 M으로 나눈 나머지와 같다
//이때, 주기 P는 
//n>2일때 M=10^n이면, P = 10^(n-1)*15
