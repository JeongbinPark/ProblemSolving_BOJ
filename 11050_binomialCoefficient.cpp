#include <iostream>
using namespace std;

int N, K;
int facto[11];

int main() {
	facto[0] = 1;
	for (int i = 1; i <= 10; i++) {
		facto[i] = i * facto[i - 1];
	}
	cin >> N >> K;
	cout << facto[N] / facto[K] / facto[N - K];

	return 0;
}