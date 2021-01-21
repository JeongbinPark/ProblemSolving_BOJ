#include <iostream>
using namespace std;

int t, n;
int dp[12] = { 0, 1, 2, 4 };

int main() {
	for (int i = 4; i < 12; i++)
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	cin >> t;
	while (t--) {
		cin >> n;
		cout << dp[n] << "\n";
	}
	return 0;
}
//dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];	//+1, +2, +3