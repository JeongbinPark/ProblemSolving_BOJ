
#include <iostream>
using namespace std;

int dp[1001][1001];
int mod = 10007;
int sum = 0;
int main() {
	int n;
	cin >> n;
	for (int i = 0; i <= n; i++) {
		dp[i][0] = 1;
		dp[i][i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
			dp[i][j] %= mod;
		}
	}
	for (int i = 0; i <= n / 2; i++) {
		sum += dp[n - i][i];
		sum %= mod;
	}
	cout << sum;
	return 0;
}
//난 조합 이용했는데... 피보나치로도 되는거구나.....

/*
#include <iostream>
using namespace std;

int dp[1001] = { 1, 1 };
int mod = 10007;

int main() {
	int n; 
	cin >> n;
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
		dp[i] %= mod;
	}
	cout << dp[n];
}
*/