#include <iostream>
using namespace std;

int N;
int board[101][101];
long long cnt[101][101] = { 1 };

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == N - 1 && j == N - 1) continue;
			if (j + board[i][j] < N) cnt[i][j + board[i][j]] += cnt[i][j];
			if (i + board[i][j] < N) cnt[i + board[i][j]][j] += cnt[i][j];
		}
	}
	cout << cnt[N - 1][N - 1];
	return 0;
}