#include <iostream>
#include <algorithm>
using namespace std;

int N, M, maxi;
char c;
int board[1001][1001];

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++) {
			cin >> c;
			board[i][j] = c - '0';
		}

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++) {
			if (board[i][j] > 0) {
				board[i][j] = min(board[i - 1][j - 1], min(board[i - 1][j], board[i][j - 1])) + 1;
				maxi = max(maxi, board[i][j] * board[i][j]);
			}
		}
	cout << maxi;
	return 0;
}