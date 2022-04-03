#include <iostream>
#define MOD 1000000009
using namespace std;

int T, n;
int num[1000001] = { 0, 1, 2, 4 };

int main() {
	for (int i = 4; i <= 1000000; i++) {
		num[i] = (num[i - 2] + num[i - 3]) % MOD;
		num[i] = (num[i] + num[i - 1]) % MOD;
	}
	cin >> T;
	while (T--) {
		cin >> n;
		cout << num[n] << "\n";
	}
	return 0;
}