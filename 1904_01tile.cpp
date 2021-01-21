#include <iostream>
using namespace std;

int n, mod = 15746;
int facto[1000001] = { 1, 1 };

int main() {
	cin >> n;
	for (int i = 2; i <= n; i++) {
		facto[i] = facto[i - 1] + facto[i - 2];
		facto[i] %= mod;
	}
	cout << facto[n];
	return 0;
}

