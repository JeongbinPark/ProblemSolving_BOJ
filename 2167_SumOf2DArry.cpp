#include <iostream>
using namespace std;

int N, M, K, a, b, c, d, sum;
int num[301][301];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		sum = 0;
		for (int j = 1; j <= M; j++) {
			cin >> num[i][j];
			sum += num[i][j];
			num[i][j] = sum + num[i - 1][j];
		}
	}

	cin >> K;
	while (K--) {
		cin >> a >> b >> c >> d;
		cout << num[c][d] + num[a - 1][b - 1] - num[a - 1][d] - num[c][b - 1] << "\n";
	}

	return 0;
}
