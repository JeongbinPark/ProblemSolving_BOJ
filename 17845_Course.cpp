#include <iostream>
#include <algorithm>
using namespace std;

int N, K, imp, time;
int result[10001];

int main() {
	cin >> N >> K;
	fill(result, result + N + 1, -1);
	result[0] = 0;
	for (int i = 1; i <= K; i++) {
		cin >> imp >> time;
		for (int j = N - time; j >= 0; j--) {
			if (result[j] == -1) continue;
			result[j + time] = max(result[j + time], result[j] + imp);
		}
	}
	int max_result = 0;
	for (int i = N; i >= 0; i--) {
		max_result = max(result[i], max_result);
	}
	cout << max_result;
	return 0;
}
