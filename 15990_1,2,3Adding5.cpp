#include <iostream>
#define MOD 1000000009
using namespace std;

int T;
int dp[100001][3] = { 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1 };

int main() {
	for (int i = 4; i < 100001; i++) {
		dp[i][0] = dp[i - 1][1] + dp[i - 1][2];
		dp[i][1] = dp[i - 2][0] + dp[i - 2][2];
		dp[i][2] = dp[i - 3][0] + dp[i - 3][1];

		dp[i][0] %= MOD;
		dp[i][1] %= MOD;
		dp[i][2] %= MOD;
	}
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		int sum = dp[n][0] + dp[n][1];
		sum %= MOD;
		sum += dp[n][2];
		sum %= MOD;
		cout << sum << "\n";
	}
	return 0;
}