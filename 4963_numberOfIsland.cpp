#include <iostream>
#include <cstring>
using namespace std;

bool isPossible(int, int);
void cnt(int, int);

int w, h, result;
int board[51][51];
bool visited[51][51];
int dr[] = { 1, 0, -1, 0, 1, -1, -1, 1}, dc[] = { 0, 1, 0, -1, 1, 1, -1, -1 };

int main() {
	while (true) {
		result = 0;
		memset(visited, false, sizeof(visited));

		cin >> w >> h;
		if (!w && !h) break;

		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				cin >> board[i][j];

		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++) {
				if (!visited[i][j] && board[i][j]) {
					cnt(i, j);
					result++;
				}
			}

		cout << result << "\n";
	}
	return 0;
}

bool isPossible(int r, int c) {
	return r >= 0 && r < h && c >= 0 && c < w;
}

void cnt(int r, int c) {
	if (visited[r][c] || !board[r][c] || !isPossible(r, c)) return;
	visited[r][c] = true;
	for (int d = 0; d < 8; d++) {
		cnt(r + dr[d], c + dc[d]);
	}
	return;
}