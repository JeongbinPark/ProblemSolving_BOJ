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
//i-1��°�� 1x2 Ÿ���� �ڿ� ���̴� ���
//i-2��°�� 2x1 Ÿ�� 2�� �Ǵ� 2x2 Ÿ�� 1�� ���̴� ���