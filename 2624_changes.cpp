#include <iostream>
using namespace std;

int T, K;
int coins[100][2];
int results[10001];

int main() {
	cin >> T >> K;
	for (int i = 0; i < K; i++) {
		cin >> coins[i][0] >> coins[i][1];
	}
	results[0] = 1;

	for (int i = 0; i < K; i++) {
		int unit = coins[i][0];
		int numbers = coins[i][1];
		for (int j = T; j >= 0; j--) {
			int sum = unit;
			for (int k = 0; sum <= j && k < numbers; k++) {
				results[j] += results[j - sum];
				sum += unit;
			}
		}
	}
	cout << results[T];
	return 0;
}
