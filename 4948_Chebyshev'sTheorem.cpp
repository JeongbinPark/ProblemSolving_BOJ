#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isNotPrime[246913];
vector<int> primeNum;

int main() {
	for (int i = 2; i <= 246912; i++) {
		if (isNotPrime[i]) continue;
		primeNum.push_back(i);
		for (int j = i + i; j <= 246912; j += i) {
			isNotPrime[j] = true;
		}
	}

	int n = 0;
	while (cin >> n) {
		if (!n) break;
		int cnt = upper_bound(primeNum.begin(), primeNum.end(), 2 * n) - upper_bound(primeNum.begin(), primeNum.end(), n);
		cout << cnt << "\n";
	}
	return 0;
}