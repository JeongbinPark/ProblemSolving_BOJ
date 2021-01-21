#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

bool isPossible(int, int);

int N, M, time, r, c, curr_r, curr_c;
int board[301][301], tmp[301][301];
bool visited[301][301];
bool exist;
queue< pair<int, int> > q;
int dr[] = { 1, 0, -1, 0 }, dc[] = { 0, 1, 0, -1 };

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if (!exist && board[i][j] > 0) {
				exist = true;
				r = i, c = j;
			}
		}
	while (exist) {
		q.push(make_pair(r, c));
		visited[r][c] = true;
		while (!q.empty()) {
			curr_r = q.front().first;
			curr_c = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				r = curr_r + dr[i];
				c = curr_c + dc[i];
				if (isPossible(r, c) && board[r][c] > 0){
					if (!visited[r][c]) {
						visited[r][c] = true;
						q.push(make_pair(r, c));
					}
				}
				else tmp[curr_r][curr_c]++;
			}
		}
		exist = false;
		for (int i = 1; i < N - 1; i++)
			for (int j = 1; j < M - 1; j++) {
				if (board[i][j] > 0&& !visited[i][j]) {
					cout << time;
					return 0;
				}
				if (board[i][j] > 0) {
					board[i][j] -= tmp[i][j];
					if (!exist && board[i][j] > 0) {
						exist = true;
						r = i, c = j;
					}
				}
			}
		fill(visited[0], visited[301], false);
		fill(tmp[0], tmp[301], 0);
		time++;
	}
	cout << 0;
	return 0;
}
bool isPossible(int a, int b) {
	return a > 0 && a < N - 1 && b > 0 && b < M - 1;
}