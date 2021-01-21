#include<iostream>
#include <algorithm>
#define INF 2147483648
using namespace std;

int N;
int row[501], col[501];
long long dp[501][501];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> row[i] >> col[i];
	}
	fill(dp[0], dp[N], INF);
	for (int i = 0; i < N - 1; i++) {
		dp[i][i + 1] = row[i] * col[i] * col[i + 1];
		dp[i][i] = 0;
	}
	dp[N - 1][N - 1] = 0;
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < N - i; j++) {
			for (int k = j; k < i + j; k++) {
				cout << j << " " << k << " " << i + j << "\n";
				dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + row[j] * col[k] * col[i + j]);
			}
		}
	}

	cout << dp[0][N-1];
	return 0;
}