#include <iostream>
#include <map>
using namespace std;

long long dp(long long);

long long N;
int P, Q;
map<long long, long long> m;

int main() {
	m[0] = 1;
	cin >> N >> P >> Q;
	cout << dp(N);
	return 0;
}
long long dp(long long n) {
	if (m[n]) return m[n];
	m[n] = dp(n / P) + dp(n / Q);
	return m[n];
}