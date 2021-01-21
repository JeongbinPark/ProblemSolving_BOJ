#include <iostream>
using namespace std;

int t, n;
long long dp[101] = { 0, 1, 1, 1, 2 };

int main() {
	cin >> t;
	for (int i = 5; i <= 100; i++)
		dp[i] = dp[i - 1] + dp[i - 5];
	while (t--) {
		cin >> n;
		cout << dp[n] << "\n";
	}
	return 0;
}

