#include <iostream>
using namespace std;

bool isPossible(int, int);

int N, M, curr_r, curr_c, curr_d, tmp_d, cnt, cleaned;
int board[50][50];
bool visited[50][50];
int dr[] = { -1, 0, 1, 0 }, dc[] = { 0, 1, 0, -1 };

int main() {
	cin >> N >> M >> curr_r >> curr_c >> curr_d;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> board[i][j];
	visited[curr_r][curr_c] = true;
	cleaned++;
	while (true) {
		curr_d = (4 + curr_d - 1) % 4;
		if (isPossible(curr_r + dr[curr_d], curr_c + dc[curr_d]) && !visited[curr_r + dr[curr_d]][curr_c + dc[curr_d]]) {
			curr_r += dr[curr_d], curr_c += dc[curr_d];
			visited[curr_r][curr_c] = true;
			cleaned++;
			cnt = 0;
			continue;
		}
		cnt++;
		if (cnt == 4) {
			tmp_d = (4 + curr_d - 2) % 4;
			if (isPossible(curr_r + dr[tmp_d], curr_c + dc[tmp_d])) {
				curr_r += dr[tmp_d], curr_c += dc[tmp_d];
				cnt = 0;
			}
			else break;
		}
	}
	cout << cleaned;
	return 0;
}
bool isPossible(int r, int c) {
	return r > 0 && r < N - 1 && c > 0 && c < M - 1 && board[r][c] == 0;
}