#include <iostream>
#include <algorithm>
using namespace std;

int n, num, cnt = 0;
int dp[1001];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> num;
		if (dp[cnt - 1] < num) {
			dp[cnt] = num;
			cnt++;
		}
		else {
			dp[lower_bound(dp, dp + cnt, num) - dp] = num;
		}
	}
	cout << cnt;
	return 0;
}