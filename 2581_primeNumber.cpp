#include <iostream>
#include <cstring>
using namespace std;

int N, M;

int main() {
	bool isPrime[10001];
	memset(isPrime, 1, 10001 * sizeof(bool));
	isPrime[0] = isPrime[1] = false;

	for (int i = 2; i <= 100; i++) {
		if (isPrime[i]) {
			for (int j = i * 2; j <= 10000; j += i) {
				isPrime[j] = false;
			}
		}
	}

	cin >> M >> N;
	int min = -1;
	int sum = 0;
	for (int i = M; i <= N; i++) {
		if (isPrime[i]) {
			if (min == -1) min = i;
			sum += i;
		}
	}
	if (min == -1) cout << min;
	else cout << sum << "\n" << min;
	return 0;
}