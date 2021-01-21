#include <iostream>
using namespace std;

int dp[1001] = { 1, 1 };
int mod = 10007;

int main() {
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] * 2;
		dp[i] %= mod;
	}
	cout << dp[n];
}
//i-1번째에 1x2 타일을 뒤에 붙이는 경우
//i-2번째에 2x1 타일 2개 또는 2x2 타일 1개 붙이는 경우