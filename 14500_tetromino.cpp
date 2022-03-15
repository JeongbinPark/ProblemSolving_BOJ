#include <iostream>
#include <algorithm>
using namespace std;

int dfs(int, int, int);
bool isPossible(int, int);

int N, M, max_result;
int board[500][500];
bool visited[500][500];
int d_r[4] = { 0, 1, 0, -1 };
int d_c[4] = { 1, 0, -1, 0 };

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			max_result = max(max_result, dfs(i, j, 1));
		}
	}
	cout << max_result;
	return 0;
}

int dfs(int r, int c, int cnt) {
	if (visited[r][c]) return 0;
	if (cnt == 4) return board[r][c];

	visited[r][c] = true;

	int max_sum = -1;
	for (int d = 0; d < 4; d++) {
		int next_r = r + d_r[d];
		int next_c = c + d_c[d];

		if (isPossible(next_r, next_c)) {
			int result = dfs(next_r, next_c, cnt + 1);
			if (result) max_sum = max(max_sum, result);
		}

	}
	if (c - 2 >= 0 && visited[r][c - 2] && visited[r][c - 1]) {	
		if (r - 1 >= 0) {	//で
			int result = dfs(r - 1, c - 1, cnt + 1);
			if (result) max_sum = max(max_sum, result);
		}
		if (r + 1 < N) {	//ぬ
			int result = dfs(r + 1, c - 1, cnt + 1);
			if (result) max_sum = max(max_sum, result);
		}
	}
	if (c + 2 < M && visited[r][c + 2] && visited[r][c + 1]) {
		if (r - 1 >= 0) {	//で
			int result = dfs(r - 1, c + 1, cnt + 1);
			if (result) max_sum = max(max_sum, result);
		}
		if (r + 1 < N) {	//ぬ
			int result = dfs(r + 1, c + 1, cnt + 1);
			if (result) max_sum = max(max_sum, result);
		}
	}
	if (r - 2 >= 0 && visited[r-2][c] && visited[r-1][c]) {
		if (c - 1 >= 0) {	//っ
			int result = dfs(r - 1, c - 1, cnt + 1);
			if (result) max_sum = max(max_sum, result);
		}
		if (c + 1 < M) {	//た
			int result = dfs(r - 1, c + 1, cnt + 1);
			if (result) max_sum = max(max_sum, result);
		}
	}
	if (r + 2 < N && visited[r+2][c] && visited[r+1][c]) {
		if (c - 1 >= 0) {	//っ
			int result = dfs(r + 1, c - 1, cnt + 1);
			if (result) max_sum = max(max_sum, result);
		}
		if (c + 1 < M) {	//た
			int result = dfs(r + 1, c + 1, cnt + 1);
			if (result) max_sum = max(max_sum, result);
		}
	}
	visited[r][c] = false;
	return max_sum + board[r][c];
}

bool isPossible(int r, int c) {
	return r >= 0 && r < N && c >= 0 && c < M;
}