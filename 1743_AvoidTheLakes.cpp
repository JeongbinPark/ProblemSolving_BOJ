//bfs
//#include <iostream>
//#include <queue>
//#include <algorithm>
//using namespace std;
//
//bool isPossible(int, int);
//
//int N, M, K;
//int r, c;
//bool board[101][101];
//bool visited[101][101];
//int d_r[4] = { 0, 1, 0, -1 };
//int d_c[4] = { 1, 0, -1, 0 };
//int maxCnt = 0;
//queue<pair<int, int> > q;
//
//int main() {
//	cin >> N >> M >> K;
//	for (int i = 0; i < K; i++) {
//		cin >> r >> c;
//		board[r][c] = true;
//	}
//	for (int i = 1; i <= N; i++) {
//		for (int j = 1; j <= M; j++) {
//			if (board[i][j] && !visited[i][j]) {
//				q.push(make_pair(i, j));
//				visited[i][j] = true;
//
//				int curr_cnt = 0;
//				while (!q.empty()) {
//					int curr_r = q.front().first;
//					int curr_c = q.front().second;
//
//					curr_cnt++;
//					q.pop();
//
//					for (int d = 0; d < 4; d++) {
//						int next_r = curr_r + d_r[d];
//						int next_c = curr_c + d_c[d];
//
//						if (isPossible(next_r, next_c) && board[next_r][next_c] && !visited[next_r][next_c]) {
//							visited[next_r][next_c] = true;
//							q.push(make_pair(next_r, next_c));
//						}
//					}
//				}
//				maxCnt = max(maxCnt, curr_cnt);
//			}
//		}
//	}
//	cout << maxCnt;
//	return 0;
//}
//
//bool isPossible(int r, int c) {
//	return r > 0 && r <= N && c > 0 && c <= M;
//}

//dfs
#include <iostream>
#include <algorithm>
using namespace std;

int dfs(int, int);
bool isPossible(int, int);

int N, M, K;
int r, c;
bool board[101][101];
bool visited[101][101];
int d_r[4] = { 0, 1, 0, -1 };
int d_c[4] = { 1, 0, -1, 0 };
int maxCnt = 0;

int main() {
	cin >> N >> M >> K;
	for (int i = 0; i < K; i++) {
		cin >> r >> c;
		board[r][c] = true;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (board[i][j] && !visited[i][j]) {
				int curr_cnt = dfs(i, j);
				maxCnt = max(maxCnt, curr_cnt);
			}
		}
	}
	cout << maxCnt;
	return 0;
}

int dfs(int r, int c) {
	if (!isPossible(r, c) || visited[r][c] || !board[r][c]) return 0;
	visited[r][c] = true;

	int cnt = 1;
	for (int d = 0; d < 4; d++) {
		int next_r = r + d_r[d];
		int next_c = c + d_c[d];

		cnt += dfs(next_r, next_c);
	}
	return cnt;
}


bool isPossible(int r, int c) {
	return r > 0 && r <= N && c > 0 && c <= M;
}