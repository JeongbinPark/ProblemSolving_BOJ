#include <iostream>
#include <algorithm>
#define MOD 1000000000
using namespace std;

int N, K;
long long numbers[201];

int main() {
	cin >> N >> K;
	fill(numbers, numbers + N + 1, 1);
	for (int i = 2; i <= K; i++)
		for (int j = 1; j <= N; j++) {
			numbers[j] += numbers[j - 1];
			numbers[j] %= MOD;
		}
	cout << numbers[N];
	return 0;
}