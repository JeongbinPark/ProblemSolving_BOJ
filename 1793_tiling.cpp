#include <iostream>
#define MAX 1000000000000000000
using namespace std;

int n;
long long dp[6][251] = { 1, 1, 3 };

int main() {
	for (int i = 3; i <= 250; i++) {
		dp[0][i] = dp[0][i - 1] + 2 * dp[0][i - 2];
		for (int j = 0; j < 5; j++) {
			int quo = dp[j][i] / MAX;
			dp[j+1][i] = dp[j + 1][i - 1] + 2 * dp[j + 1][i - 2] + quo;
			dp[j][i] -= quo * MAX;
		}
	}

	while (cin >> n) {
		for (int j = 4; j > 0; j--) {
			if (dp[j][n]) {
				cout << dp[j][n];
				cout.width(18);
				cout.fill('0');
			}
		}
		cout << dp[0][n] << "\n";
	}
	return 0;
}