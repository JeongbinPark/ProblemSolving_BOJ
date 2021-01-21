#include <iostream>
#include <algorithm>
#define MOD 1000000000
using namespace std;

int find(int, int);

int N;
int dp[101][10];
long long cnt;

int main() {
	cin >> N;
	fill(dp[1], dp[N], -1);
	for (int i = 0; i <= 9; i++) dp[0][i] = 1;
	for (int i = 0; i <= 9; i++) {
		cnt += find(N - 1, i);
		cnt %= MOD;
	}
	cout << (cnt - dp[N-1][0] < 0 ? cnt - dp[N - 1][0] + MOD : cnt - dp[N - 1][0]);
	return 0;
}
int find(int level, int num) {
	if (dp[level][num] != -1) return dp[level][num];

	int sum = 0;
	if (num > 0) sum += find(level - 1, num - 1);
	if (num < 9) sum += find(level - 1, num + 1);

	sum %= MOD;
	dp[level][num] = sum;
	return sum;
}