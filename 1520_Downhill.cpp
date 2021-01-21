#include <iostream>
#include <algorithm>
using namespace std;

int find(int, int);
bool isPossible(int, int);

int M, N;
int board[500][500], route[501][500];
int dr[] = { 1, 0, -1, 0 }, dc[] = { 0, 1, 0, -1 };

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> M >> N;
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	fill(route[0], route[501], -1);
	cout << find(0, 0);
	return 0;
}
int find(int r, int c) {
	if (route[r][c] != -1) {
		return route[r][c];
	}
	if (r == M - 1 && c == N - 1) {
		return 1;
	}
	route[r][c] = 0;
	for (int i = 0; i < 4; i++) {
		if (isPossible(r + dr[i], c + dc[i]) && board[r][c] > board[r+dr[i]][c+dc[i]]){
			route[r][c] += find(r + dr[i], c + dc[i]);
		}
	}
	return route[r][c];
}
bool isPossible(int r, int c) {
	return r >= 0 && r<M&&c >= 0 && c<N;
}