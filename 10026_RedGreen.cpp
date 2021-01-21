#include <iostream>
#include <algorithm>
using namespace std;

void find1(int, int);
void find2(int, int);
bool isPossible(int, int);

int N, r, g, rg, b;
char c, board[101][101];
bool visited1[101][101], visited2[101][101];
int dx[] = { 0, 1, 0, -1 }, dy[] = { 1, 0, -1, 0 };

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> c;
			board[i][j] = c;
		}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			c = board[i][j];
			if (!visited1[i][j]) {
				if (c == 'R') r++;
				else if (c == 'G') g++;
				else b++;
				find1(i, j);
			}
			if (!visited2[i][j]) {
				if (c == 'R' || c == 'G') {
					rg++;
					find2(i, j);
				}
			}
		}
	cout << r + g + b << " " << rg + b;
	return 0;
}
void find1(int x, int y) {
	if (board[x][y] != c) return;
	for (int i = 0; i < 4; i++) {
		if (isPossible(x + dx[i], y + dy[i]) && board[x + dx[i]][y + dy[i]] == c && !visited1[x + dx[i]][y + dy[i]]) {
			visited1[x + dx[i]][y + dy[i]] = true;
			find1(x + dx[i], y + dy[i]);
		}
	}
	return;
}
void find2(int x, int y) {
	if (board[x][y] == 'B') return;
	for (int i = 0; i < 4; i++) {
		if (isPossible(x + dx[i], y + dy[i]) && !visited2[x + dx[i]][y + dy[i]] && board[x][y] != 'B') {
			visited2[x + dx[i]][y + dy[i]] = true;
			find2(x + dx[i], y + dy[i]);
		}
	}
	return;
}

bool isPossible(int x, int y) {
	return x >= 0 && x < N && y >= 0 && y < N;
}