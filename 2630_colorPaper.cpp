#include <iostream>
using namespace std;

void dfs(int, int, int);

int n;
int board[129][129];
int white, blue;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];

	dfs(0, 0, n);
	cout << white << "\n" << blue;
	return 0;
}

void dfs(int r, int c, int w) {
	bool flag = true;
	for (int i = r; flag && i < r + w; i++) {
		for (int j = c; flag && j < c + w; j++) {
			if (board[r][c] != board[i][j]) flag = false;
		}
	}
	if (flag) {
		if (board[r][c]) blue++;
		else white++;
	}
	else {
		dfs(r, c, w / 2);
		dfs(r, c + w / 2, w / 2);
		dfs(r + w / 2, c, w / 2);
		dfs(r + w / 2, c + w / 2, w / 2);
	}
}