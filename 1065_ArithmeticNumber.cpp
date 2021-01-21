#include <iostream>
using namespace std;

int N, cnt = 99;

int main() {
	cin >> N;
	if (N < 100) {
		cout << N;
		return 0;
	}
	for (int i = 1; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (i * 100 + j * 10 + i + 2 * (j - i) > N) {
				cout << cnt;
				return 0;
			}
			if (i + 2 * (j - i) >= 0 && i + 2 * (j - i) < 10) {
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}