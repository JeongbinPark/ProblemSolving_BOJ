#include <iostream>
using namespace std;

int N, L;

int main() {
	cin >> N >> L;
	while (L <= 100) {
		if (L % 2 == 0 && N % L == L / 2) {
			int first = N / L - L / 2 + 1;
			int last = N / L + L / 2;
			if (first >= 0 && last >= 0) {
				for (int i = first; i <= last; i++) {
					cout << i << " ";
				}
				return 0;
			}
		}
		else if (L % 2 == 1 && N % L == 0) {
			int first = N / L - L / 2;
			int last = N / L + L / 2;
			if (first >= 0 && last >= 0) {
				for (int i = first; i <= last; i++) {
					cout << i << " ";
				}
				return 0;
			}
		}
		L++;
	}
	cout << -1;
	return 0;
}