#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool isPossible(int, int);

int N, M;
int board[1000][1000];
int idBoard[1000][1000];
vector<int> idValue;
int currId = 0;
int d_r[4] = { 1, 0, -1, 0 };
int d_c[4] = { 0, 1, 0, -1 };
queue< pair<int, int> > q;

int main() {
	idValue.push_back(0);
	cin >> N >> M;

	char c;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> c;
			board[i][j] = c - '0';
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!board[i][j] && !idBoard[i][j]) {
				currId++;
				q.push(make_pair(i, j));
				idBoard[i][j] = currId;

				int curr_cnt = 0;
				while (!q.empty()) {
					int curr_r = q.front().first;
					int curr_c = q.front().second;
					q.pop();

					curr_cnt++;

					for (int d = 0; d < 4; d++) {
						int next_r = curr_r + d_r[d];
						int next_c = curr_c + d_c[d];

						if (isPossible(next_r, next_c) && !board[next_r][next_c] && !idBoard[next_r][next_c]) {
							idBoard[next_r][next_c] = currId;
							q.push(make_pair(next_r, next_c));
						}
					}
				}
				idValue.push_back(curr_cnt);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j]) {
				int idArray[4] = { 0, 0, 0, 0 };
				int cnt = 1;
				for (int d = 0; d < 4; d++) {
					int next_r = i + d_r[d];
					int next_c = j + d_c[d];

					if (isPossible(next_r, next_c)) {
						bool isSame = false;
						for (int k = 0; k < d; k++) {
							if (idArray[k] == idBoard[next_r][next_c]) {
								isSame = true;
								break;
							}
						}
						idArray[d] = isSame ? 0 :idBoard[next_r][next_c];
					}
					cnt += idValue[idArray[d]];
				}
				cout << (cnt % 10);
			}
			else cout << board[i][j];
		}
		cout << "\n";
	}
	return 0;
}

bool isPossible(int r, int c) {
	return r >= 0 && r < N && c >= 0 && c < M;
}