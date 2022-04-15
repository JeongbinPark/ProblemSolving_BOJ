#include <iostream>
#include <algorithm>
using namespace std;

int N, M, K;
int board[16][16];
int K_r, K_c;
int result;

int main() {
	cin >> N >> M >> K;

	if (K) {
		K_r = (K - 1) / M + 1;
		K_c = (K - 1) % M + 1;
	}
	else {
		K_r = N;
		K_c = M;
	}

	board[1][0] = 1;
	for (int i = 1; i <= K_r; i++) {
		for (int j = 1; j <= K_c; j++) {
			board[i][j] = board[i - 1][j] + board[i][j - 1];
		}
	}

	result = board[K_r][K_c];

	if (!K) {
		cout << result;
		return 0;
	}

	fill(board[K_r - 1], board[K_r - 1] + M + 1, 0);
	fill(board[K_r], board[K_r] + M + 1, 0);
	for (int i = K_r; i <= N; i++) {
		board[i][K_c - 1] = 0;
	}
	board[K_r][K_c - 1] = 1;
	for (int i = K_r; i <= N; i++) {
		for (int j = K_c; j <= M; j++) {
			board[i][j] = board[i - 1][j] + board[i][j - 1];
		}
	}

	result *= board[N][M];
	cout << result;

	return 0;
}