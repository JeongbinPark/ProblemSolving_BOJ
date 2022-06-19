#include <iostream>
using namespace std;

bool isPossible(int r, int c);

int N, K;
int board[999][999];
int dr[] = { 1, 0, -1, 0 }, dc[] = { 0, 1, 0, -1 };
int resultR, resultC;

int main() {
	cin >> N >> K;
	int dir = 0;
	int currR = 0, currC = 0;
	for (int i = N * N; i > 0; i--) {
		if (i == K) {
			resultR = currR;
			resultC = currC;
		}
		board[currR][currC] = i;
		if (!isPossible(currR + dr[dir], currC + dc[dir]) || board[currR + dr[dir]][currC + dc[dir]]) {
			dir = (dir + 1) % 4;
		}
		currR += dr[dir];
		currC += dc[dir];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
	cout << resultR + 1 << " " << resultC + 1;
	return 0;
}

bool isPossible(int r, int c) {
	return r >= 0 && r < N && c >= 0 && c < N;
}