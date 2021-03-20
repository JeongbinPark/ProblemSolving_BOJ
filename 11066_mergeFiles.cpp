#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int getMin(int, int);

int t, k, mini;
int file[501];
int preSum[501];
int dp[501][501];

int main() {
	cin >> t;
	while (t--) {
		memset(dp, 0, sizeof(dp));

		cin >> k;
		for (int i = 1; i <= k; i++) {
			cin >> file[i];
			preSum[i] = preSum[i-1] + file[i];
			dp[i][i] = file[i];
		}

		mini = 100000000;
		for (int i = 1; i <= k; i++)
			mini = min(mini, getMin(1, i) + getMin(i + 1, k));

		cout << mini << "\n";
	}
	return 0;
}

int getMin(int s, int e) {
	if (s == e) return file[s];
	if (dp[s][e] != 0) return dp[s][e];

	int temp = 100000000;
	for (int i = s; i < e; i++)
		temp = min(temp, getMin(s, i) + getMin(i + 1, e) + preSum[e] - preSum[s-1]);
	dp[s][e] = temp;
	return dp[s][e];
}