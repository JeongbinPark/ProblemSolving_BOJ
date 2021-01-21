#include <iostream>
#include <algorithm>
using namespace std;

int dp[100];
int people[21][2];
int main() {
	int N;
	cin >> N;

	fill(dp, dp + 100, -1);
	dp[0] = 0;

	for (int i = 0; i < N; i++) cin >> people[i][0];
	for (int i = 0; i < N; i++) cin >> people[i][1];

	int max_happ = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 99; j >= 0; j--) {
			if (dp[j] != -1 && j + people[i][0] < 100) {
				dp[j + people[i][0]] = max(dp[j + people[i][0]], people[i][1] + dp[j]);
				max_happ = max(max_happ, dp[j + people[i][0]]);
			}
		}
	}
	cout << max_happ;
	return 0;
}