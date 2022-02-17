//bfs
//#include <iostream>
//#include <queue>
//using namespace std;
//
//bool isPossible(int, int);
//
//int M, N;
//bool letters[251][251];
//bool visited[251][251];
//int num_letters = 0;
//queue<pair<int, int> > q;
//int d_r[8] = { 0, 1, 1, 1, 0, -1, -1 ,-1 };
//int d_c[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
//
//int main() {
//	cin >> M >> N;
//	for (int i = 0; i < M; i++) {
//		for (int j = 0; j < N; j++) {
//			cin >> letters[i][j];
//		}
//	}
//	for (int i = 0; i < M; i++) {
//		for (int j = 0; j < N; j++) {
//			if (letters[i][j] && !visited[i][j]) {
//				q.push(make_pair(i, j));
//				visited[i][j] = true;
//				num_letters++;
//
//				while (!q.empty()) {
//					int curr_r = q.front().first;
//					int curr_c = q.front().second;
//					q.pop();
//
//					for (int d = 0; d < 8; d++) {
//						int next_r = curr_r + d_r[d];
//						int next_c = curr_c + d_c[d];
//
//						if (isPossible(next_r, next_c) && letters[next_r][next_c] && !visited[next_r][next_c]) {
//							q.push(make_pair(next_r, next_c));
//							visited[next_r][next_c] = true;
//						}
//					}
//				}
//			}
//		}
//	}
//	cout << num_letters;
//	return 0;
//}
//
//bool isPossible(int r, int c) {
//	return r >= 0 && r < M && c >= 0 && c < N;
//}

//dfs
#include <iostream>
#include <queue>
using namespace std;

bool isPossible(int, int);
void dfs(int, int);

int M, N;
bool letters[251][251];
bool visited[251][251];
int num_letters = 0;
int d_r[8] = { 0, 1, 1, 1, 0, -1, -1 ,-1 };
int d_c[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };

int main() {
	cin >> M >> N;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> letters[i][j];
		}
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (letters[i][j] && !visited[i][j]) {
				dfs(i, j);
				num_letters++;
			}
		}
	}
	cout << num_letters;
	return 0;
}

bool isPossible(int r, int c) {
	return r >= 0 && r < M && c >= 0 && c < N;
}

void dfs(int r, int c) {
	if (!isPossible(r, c) || !letters[r][c] || visited[r][c]) return;
	visited[r][c] = true;

	for (int d = 0; d < 8; d++) {
		int next_r = r + d_r[d];
		int next_c = c + d_c[d];
		dfs(next_r, next_c);
	}
	return;
}