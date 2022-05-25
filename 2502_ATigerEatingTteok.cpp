#include <iostream>
using namespace std;

int D, K;
int a[31] = { 0 , 1 };
int b[31] = { 0, 0, 1 };

int main() {
	cin >> D >> K;
	for (int i = 3; i <= D; i++) {
		a[i] = a[i - 1] + a[i - 2];
		b[i] = b[i - 1] + b[i - 2];
	}

	int num = 0;
	while (++num) {
		int left = K - num * a[D];
		if (left % b[D] == 0 && num <= left / b[D]) {
			cout << num << "\n" << left / b[D];
			break;
		}
	}
	return 0;
}