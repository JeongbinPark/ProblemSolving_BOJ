#include <iostream>
using namespace std;

int n, k, c;
int sum[10001] = { 1 };

int main() {
	cin >> n >> k;
	while (n--) {
		cin >> c;
		for (int i = c; i <= k; i++) {
			sum[i] += sum[i - c];
		}
	}
	cout << sum[k];
	return 0;
}