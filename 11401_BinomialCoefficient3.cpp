//페르마의 소정리 이용

#include <iostream>
#define MOD 1000000007
using namespace std;

long long getPower(long long, int);

int N, K;
long long factorial[4000010] = { 1, 1 };

int main() {
	cin >> N >> K;
	for (int i = 2; i <= N; i++)
		factorial[i] = (factorial[i - 1] * i) % MOD;
	long long base = (factorial[K] * factorial[N - K]) % MOD;
	cout << (factorial[N] * getPower(base, MOD - 2)) % MOD;
	return 0;
}
long long getPower(long long base, int expo) {
	if (expo == 0) return 1;
	if (expo % 2) return (base * getPower(base, expo - 1)) % MOD;
	else {
		long long half = getPower(base, expo / 2);
		return (half * half) % MOD;
	}
}