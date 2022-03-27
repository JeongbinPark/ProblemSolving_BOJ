#include <iostream>
#include <algorithm>
using namespace std;

int N;
int input[1001];
int dp[1001];
int max_value;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> input[i];
		dp[i] = input[i];
		for (int j = 0; j < i; j++) {
			if (input[j] < input[i] && dp[i] < dp[j] + input[i]) {
				dp[i] = dp[j] + input[i];
			}
		}
		max_value = max(max_value, dp[i]);
	}
	cout << max_value;
	return 0;
}