#include <iostream>
#include <algorithm>
#define inf 1000000000
using namespace std;

int N;
int dp[1000001];

int main() {
	cin >> N;
	for (int i = 2; i <= N; i++) {
		int tmp1 = inf, tmp2 = inf, tmp3 = inf;
		if (i % 3 == 0) tmp1 = dp[i / 3] + 1;
		if (i % 2 == 0) tmp2 = dp[i / 2] + 1;
		tmp3 = dp[i - 1] + 1;
		dp[i] = min(tmp1, min(tmp2, tmp3));
	}
	cout << dp[N];
	return 0;
}