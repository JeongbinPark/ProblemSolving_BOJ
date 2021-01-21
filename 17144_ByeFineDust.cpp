#include <iostream>
#include <algorithm>
using namespace std;

bool isPossible(int, int);

int R, C, T, tmp, r_ac, cnt;
int room[50][50], tmp_room[51][50];
int dr[] = { 1, 0, -1, 0 }, dc[] = { 0, 1, 0, -1 };


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> R >> C >> T;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++) {
			cin >> room[i][j];
			if (room[i][j] == -1) {
				room[i][j] = 0;
				r_ac = i;
			}
		}
	r_ac--;
	while (T--) {
		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
				if (room[i][j] > 0) {
					tmp = room[i][j] / 5;
					for (int k = 0; k < 4; k++) {
						if (isPossible(i + dr[k], j + dc[k])) {
							tmp_room[i + dr[k]][j + dc[k]] += tmp;
							tmp_room[i][j] -= tmp;
						}
					}
				}

		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
				room[i][j] += tmp_room[i][j];
		fill(tmp_room[0], tmp_room[50], 0);

		for (int i = r_ac; i > 0; i--) room[i][0] = room[i - 1][0];
		for (int i = 0; i < C; i++) room[0][i] = room[0][i + 1];
		for (int i = 0; i < r_ac; i++) room[i][C - 1] = room[i + 1][C - 1];
		for (int i = C - 1; i > 1; i--) room[r_ac][i] = room[r_ac][i - 1];

		for (int i = r_ac + 1; i < R - 1; i++) room[i][0] = room[i + 1][0];
		for (int i = 0; i < C; i++) room[R - 1][i] = room[R - 1][i + 1];
		for (int i = R - 1; i > r_ac + 1; i--) room[i][C - 1] = room[i - 1][C - 1];
		for (int i = C - 1; i > 1; i--) room[r_ac+1][i] = room[r_ac+1][i - 1];

		room[r_ac][0] = room[r_ac + 1][0] = 0;
		room[r_ac][1] = room[r_ac + 1][1] = 0;
	}

	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			cnt += room[i][j];
	cout << cnt;
	return 0;
}

bool isPossible(int r, int c) {
	return (r >= 0 && r < R && c >= 0 && c < C) && !((r == r_ac || r == r_ac + 1) && c == 0);
}