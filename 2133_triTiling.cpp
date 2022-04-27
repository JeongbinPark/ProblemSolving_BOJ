#include <iostream>
using namespace std;

int N;
int sum[16] = { 0, 3 };
int result[16] = { 1, 3 };

int main() {
	cin >> N;
	if (N == 0) {
		cout << 1;
		return 0;
	}
	if (N % 2) {
		cout << 0;
		return 0;
	}
	for (int i = 2; i <= N / 2; i++) {
		result[i] = result[i - 1] * 3 + sum[i - 2] * 2 + 2;
		sum[i] = sum[i - 1] + result[i];
	}
	cout << result[N / 2];
	return 0;
}