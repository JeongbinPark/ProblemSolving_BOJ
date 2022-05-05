#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

bool isPossible(int r, int c);

int R, C;
char c;
bool board[50][50];
int d_r[] = { 0, 1, 0, -1 }, d_c[] = { 1, 0, -1, 0 };
int result;

int main() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> c;
			if (c == 'L') board[i][j] = true;
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (!board[i][j]) continue;

			int maxTimes = 0;
			bool visited[50][50];
			memset(visited, 0, sizeof(visited));
			visited[i][j] = true;
			queue<pair<int, pair<int, int> > > q;
			q.push(make_pair(0, make_pair(i, j)));

			while (!q.empty()) {
				int times = q.front().first;
				int curr_r = q.front().second.first;
				int curr_c = q.front().second.second;

				maxTimes = max(maxTimes, times);
				q.pop();

				for (int d = 0; d < 4; d++) {
					int next_r = curr_r + d_r[d];
					int next_c = curr_c + d_c[d];
					if (isPossible(next_r, next_c) && board[next_r][next_c] && !visited[next_r][next_c]) {
						visited[next_r][next_c] = true;
						q.push(make_pair(times + 1, make_pair(next_r, next_c)));
					}
				}
			}
			result = max(result, maxTimes);
		}
	}
	cout << result;
	return 0;
}
bool isPossible(int r, int c) {
	return r >= 0 && r < R && c >= 0 && c < C;
}