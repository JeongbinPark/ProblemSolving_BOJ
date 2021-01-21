#include <iostream>
using namespace std;

bool isPossible(int, int);

int N;
int board[16][16];
int ver[16][16] = { 0, 1 }, hor[16][16], dia[16][16];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			if (isPossible(i, j + 1) && !board[i][j + 1]) ver[i][j + 1] += ver[i][j] + dia[i][j];
			if (isPossible(i + 1, j) && !board[i + 1][j]) hor[i + 1][j] += hor[i][j] + dia[i][j];
			if (isPossible(i + 1, j + 1) && !board[i][j + 1] && !board[i + 1][j] && !board[i + 1][j + 1]) dia[i + 1][j + 1] += ver[i][j] + hor[i][j] + dia[i][j];
		}
	cout << ver[N - 1][N - 1] + hor[N - 1][N - 1] + dia[N - 1][N - 1];
	return 0;
}

bool isPossible(int r, int c) {
	return r >= 0 && r < N && c >= 0 && c < N;
}