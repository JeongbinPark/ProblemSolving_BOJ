#include <iostream>
using namespace std;

int T, N;
long long koong[67] = { 1, 1, 2, 4, 8 };

int main() {
	cin >> T;
	for (int i = 5; i <= 67; i++) {
		koong[i] = koong[i - 1] * 2 - koong[i - 5];
	}

	while (T--) {
		cin >> N;
		cout << koong[N] << "\n";
	}
	return 0;
}