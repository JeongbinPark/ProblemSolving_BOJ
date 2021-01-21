#include <iostream>
using namespace std;

bool canMove(int, int);
void rolling(int);

int N, M, K;
int map[20][20];
int x, y;

int dice[3][3] = { 0 };
int bottom = 0, tmp;
int d, dx[] = { 0, 0, 0, -1, 1 }, dy[] = { 0, 1, -1, 0, 0 };

int main() {
	cin >> N >> M >> x >> y >> K;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];
	while (K--) {
		cin >> d;
		if (canMove(x + dx[d], y + dy[d])) {
			rolling(d);
			x = x + dx[d], y = y + dy[d];
			if (!map[x][y]) map[x][y] = bottom;
			else {
				bottom = map[x][y];
				map[x][y] = 0;
			}
			cout << dice[1][1] << "\n";
		}
	}
	return 0;
}

bool canMove(int x, int y) {
	return !(x < 0 || x >= N || y < 0 || y >= M);
}
void rolling(int d) {
	if (d == 1) {
		tmp = dice[1][2];
		dice[1][2] = dice[1][1], dice[1][1] = dice[1][0], dice[1][0] = bottom;
	}
	else if (d == 2) {
		tmp = dice[1][0];
		dice[1][0] = dice[1][1], dice[1][1] = dice[1][2], dice[1][2] = bottom;
	}
	else if (d == 3) {
		tmp = dice[0][1];
		dice[0][1] = dice[1][1], dice[1][1] = dice[2][1], dice[2][1] = bottom;
	}
	else if (d == 4) {
		tmp = dice[2][1];
		dice[2][1] = dice[1][1], dice[1][1] = dice[0][1], dice[0][1] = bottom;
	}
	bottom = tmp;
}