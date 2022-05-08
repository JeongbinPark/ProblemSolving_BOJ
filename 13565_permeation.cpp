#include <iostream>
using namespace std;

bool percolate();
bool findPath(int, int);
bool isPossible(int, int);

int M, N;
char c;
bool board[1000][1000];
bool visited[1000][1000];
int d_r[] = { 0, 1, 0, -1 }, d_c[] = { 1, 0, -1, 0 };

int main() {
	cin >> M >> N;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> c;
			board[i][j] = c == '1' ? true : false;
		}
	}

	cout << (percolate() ? "YES" : "NO");

	return 0;
}

bool percolate() {
	bool isFound = false;
	for (int i = 0; !isFound && i < N; i++) {
		if (!board[0][i] && findPath(0, i)) {
			isFound = true;
		}
	}
	return isFound;
}

bool findPath(int r, int c) {
	if (!isPossible(r, c) || board[r][c] || visited[r][c]) return false;
	if (r == M - 1) return true;

	visited[r][c] = true;

	for (int d = 0; d < 4; d++) {
		int next_r = r + d_r[d];
		int next_c = c + d_c[d];
		if (findPath(next_r, next_c)) return true;
	}

	return false;
}

bool isPossible(int r, int c) {
	return r >= 0 && r < M && c >= 0 && c < N;
}