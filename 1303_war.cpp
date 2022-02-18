#include <iostream>
#include <queue>
using namespace std;

bool isPossible(int, int);

int N, M;
char c;
bool board[100][100];
bool visited[100][100];
queue<pair<int, int> > q;
int d_r[4] = { 0, 1, 0, -1 };
int d_c[4] = { 1, 0, -1, 0 };
int B, W;

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> c;
			board[i][j] = c == 'W' ? true : false;
		}
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				int curr_cnt = 0;
				bool isW = board[i][j];
				q.push(make_pair(i, j));
				visited[i][j] = true;

				while (!q.empty()) {
					int curr_r = q.front().first;
					int curr_c = q.front().second;
					curr_cnt++;
					q.pop();

					for (int d = 0; d < 4; d++) {
						int next_r = curr_r + d_r[d];
						int next_c = curr_c + d_c[d];

						if (isPossible(next_r, next_c) && board[next_r][next_c] == isW && !visited[next_r][next_c]) {
							visited[next_r][next_c] = true;
							q.push(make_pair(next_r, next_c));
						}
					}
				}

				if (isW) W += curr_cnt * curr_cnt;
				else B += curr_cnt * curr_cnt;
			}
		}
	}
	cout << W << " " << B;
	return 0;
}

bool isPossible(int r, int c) {
	return r >= 0 && r < M && c >= 0 && c < N;
}