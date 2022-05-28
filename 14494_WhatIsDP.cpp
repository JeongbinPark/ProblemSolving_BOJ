#include <iostream>
#define MOD 1000000007
using namespace std;

int n, m;
int board[1001][1001] = { 1 };

int main() {
	cin >> n >> m;
	for (int r = 1; r <= n; r++) {
		for (int c = 1; c <= m; c++) {
			board[r][c] = (board[r - 1][c - 1] + board[r - 1][c]) % MOD;
			board[r][c] = (board[r][c] + board[r][c - 1]) % MOD;
		}
	}
	cout << board[n][m];
	return 0;
}