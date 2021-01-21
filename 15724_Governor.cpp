#include <iostream>
using namespace std;

int M, N, K, sum, a, b, c, d;
int block[1025][1025];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		sum = 0;
		for (int j = 1; j <= M; j++) {
			cin >> block[i][j];
			sum += block[i][j];
			block[i][j] = sum + block[i - 1][j];
		}
	}
	cin >> K;

	while (K--) {
		cin >> a >> b >> c >> d;
		cout << block[c][d] + block[a - 1][b - 1] - block[a - 1][d] - block[c][b - 1] << "\n";
	}
	return 0;
}
