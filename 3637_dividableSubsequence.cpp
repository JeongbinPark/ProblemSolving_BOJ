#include <iostream>
using namespace std;

int T, N, M, num, sum;
long long remainders[1000001], cnt;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		cin >> M >> N;
		sum = cnt = 0;
		fill(remainders, remainders + M, 0);
		for (int i = 1; i <= N; i++) {
			cin >> num;
			sum += num;
			sum %= M;

			remainders[sum]++;
		}
		cnt += remainders[0];
		for (int i = 0; i < M; i++) {
			cnt += remainders[i] * (remainders[i] - 1) / 2;
		}
		cout << cnt << "\n";
	}
}
