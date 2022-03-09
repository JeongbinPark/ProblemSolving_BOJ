#include <iostream>
using namespace std;

int gcd(int, int);

int T,  M, N, x, y;

int main() {
	cin >> T;
	while (T--) {
		cin >> M >> N >> x >> y;
		int sum = x - y;
		bool isFound = false;
		int max = M * N / gcd(M, N);
		for (int i = 0; i <= 40000; i++) {
			if (x + i * M > max) 
				break;
			if (sum >= 0 && sum % N == 0) {
				cout << x + i * M << "\n";
				isFound = true;
				break;
			}
			sum += M;
		}
		if (!isFound) cout << -1 << "\n";
	}
	return 0;
}
int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}