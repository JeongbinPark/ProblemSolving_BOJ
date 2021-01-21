#include <iostream>
#define MOD 1000000007
using namespace std;

long long getPower(long long, int);

int M, N, K;
long long factorial[4000010] = { 1, 1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> M;
	for (int i = 2; i <= 4000000; i++)
		factorial[i] = (factorial[i - 1] * i) % MOD;
	while (M--) {
		cin >> N >> K;
		long long base = (factorial[K] * factorial[N - K]) % MOD;
		cout << (factorial[N] * getPower(base, MOD - 2)) % MOD << "\n";
	}
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

//아니!!!  sync_with_stdio랑 cin.tie 안한거로 시간초과 나는건 너무한거 아니야!!!!