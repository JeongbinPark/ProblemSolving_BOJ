//Ä«Å»¶õ(Ä«Å»¶û) ¼ö 
#include <iostream>
#define MOD 1000000007
using namespace std;

int t, n;
long long c[2501] = {1, };

int main() {
	for (int i = 1; i <= 2500; i++) {
		for (int j = 0; j < i; j++) {
			c[i] += c[j] * c[i - 1 - j];
			c[i] %= MOD;
		}
	}
	cin >> t;
	while(t--) {
		cin >> n;
		if (n % 2) cout << 0 << "\n";
		else cout << c[n / 2] << "\n";
	}
	return 0;
}
