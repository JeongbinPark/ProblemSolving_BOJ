#include <iostream>
#include <algorithm>
#define MOD 10007
using namespace std;

int n;
int dp[1001][10] = { 1 };

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		dp[i][0] = 1;
		for (int j = 1; j < 10; j++) {
			dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % MOD;
		}
	}

	int sum = 0;
	for (int i = 0; i < 10; i++) {
		sum += dp[n][i];
		sum %= MOD;
	}
	cout << sum;
	return 0;
}