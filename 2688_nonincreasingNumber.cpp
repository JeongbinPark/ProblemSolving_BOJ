#include <iostream>
#include <algorithm>
using namespace std;

int T, n, sum, tmp;
long long cnt[65][10];

int main() {
	fill(cnt[0], cnt[0] + 10, 1);
	for (int i = 1; i <= 64; i++) {
		for (int j = 0; j < 10; j++)
			cnt[i][0] += cnt[i - 1][j];
		for (int j = 1; j < 10; j++)
			cnt[i][j] = cnt[i][j - 1] - cnt[i-1][j-1];
	}
	cin >> T;
	while (T--) {
		cin >> n;
		cout << cnt[n][0] << "\n";
	}
	return 0;
}