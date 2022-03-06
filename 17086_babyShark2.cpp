#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

bool isPossible(int, int);

int N, M;
bool board[50][50];
int num[50][50];
int d_r[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int d_c[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };

int main() {
	cin >> N >>  M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j]) {
				queue<pair<int, pair<int, int>> > q;
				
				q.push(make_pair(0, make_pair(i, j)));

				while (!q.empty()) {
					int times = q.front().first;
;					int curr_r = q.front().second.first;
					int curr_c = q.front().second.second;
					q.pop();

					for (int d = 0; d < 8; d++) {
						int next_r = curr_r + d_r[d];
						int next_c = curr_c + d_c[d];
						if (isPossible(next_r, next_c) && !board[next_r][next_c] && (!num[next_r][next_c] || num[next_r][next_c] > times+1)) {
							num[next_r][next_c] = times + 1;
							q.push(make_pair(times + 1, make_pair(next_r, next_c)));
						}
					}
				}
			}
		}
	}


	int max_distance;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!num[i][j]) continue;
			max_distance = max(max_distance, num[i][j]);
		}
	}
	
	cout << max_distance;
	return 0;
}

bool isPossible(int r, int c) {
	return r >= 0 && r < N && c >= 0 && c < M;
}