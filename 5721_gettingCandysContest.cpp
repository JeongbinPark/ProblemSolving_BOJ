//아.. M = 0, N = 0일때 0을 출력해버려서 틀렸습니다 1회ㅠㅠ
#include <iostream>
#include <algorithm>
using namespace std;

int N = 1, M = 1, num;
int cols[100010];
int rows[100010];

int main() {
	while (true) {
		cin >> M >> N;
		if (!M && !N) return 0;
		for (int row = 0; row < M; row++) {
			for (int col = 0; col < N; col++) {
				cin >> num;
				cols[col] = num;
			}
			cols[N] = cols[N + 1] = cols[N + 2] = 0;

			for (int col = N - 1; col >= 0; col--) {
				cols[col] += max(cols[col + 2], cols[col + 3]);
			}
			rows[row] = max(cols[0], cols[1]);
		}
		rows[M] = rows[M + 1] = rows[M + 2] = 0;

		for (int row = M - 1; row >= 0; row--) {
			rows[row] += max(rows[row + 2], rows[row + 3]);
		}
		cout << max(rows[0], rows[1]) << "\n";
	}
	return 0;
}