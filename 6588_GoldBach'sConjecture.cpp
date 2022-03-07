//cin.tie(NULL)과 ios_base::sync_with_stdio(false) 없으면 시간초과
#include <iostream>
using namespace std;

int cntPrime;
bool isNotPrime[1000001];
long long cnt;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	for (int i = 2; i <= 1000000; i++) {
		if (isNotPrime[i]) continue;
		cntPrime++;
		cnt++;
		for (int j = i + i; j <= 1000000; j += i) {
			isNotPrime[j] = true;
			cnt++;
		}
	}
	cout << cnt;

	int n = -1;
	while (cin >> n) {
		if (!n) break;
		bool isFound = false;
		for (int i = 3; i < n; i += 2) {
			if (!isNotPrime[i] && !isNotPrime[n - i]) {
				isFound = true;
				cout << n << " = " << i << " + " << n - i << "\n";
				break;
			}
		}
		if (!isFound) cout << "Goldbach's conjecture is wrong." << "\n";
	}
	return 0;
}