#include <iostream>
#define MOD 1000000007
using namespace std;

int n;
int times[51] = { 1, 1 };

int main() {
	cin >> n;
	for (int i = 2; i <= n; i++) {
		times[i] = (1 + times[i - 1] + times[i - 2]) % MOD;
	}
	cout << times[n];
	return 0;
}