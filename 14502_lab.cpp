#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;

void BFS();
bool isPossible(int, int);
void Count();

int N, M, maxi, curr_r, curr_c, next_r, next_c;
int board[8][8], test[8][8];
bool visited[8][8];
vector< pair<int, int> > v;
queue < pair<int, int> > q;
int dr[] = { 1, 0, -1, 0 }, dc[] = { 0, 1, 0, -1 };

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if (board[i][j] == 2) v.push_back(make_pair(i, j));
		}

	for (int w1 = 0; w1 < N * M; w1++)
		for (int w2 = w1 + 1; w2 < N * M; w2++)
			for (int w3 = w2 + 1; w3 < N * M; w3++)
				if (!board[w1 / M][w1%M] && !board[w2 / M][w2%M] && !board[w3 / M][w3%M]) {
					memcpy(test, board, sizeof(board));
					test[w1 / M][w1%M] = test[w2 / M][w2%M] = test[w3 / M][w3%M] = 1;
					BFS();
				}
	cout << maxi;
	return 0;
}
void BFS() {
	memset(visited, false, sizeof(visited));
	for (int i = 0; i < (int)v.size(); i++) {
		q.push(make_pair(v[i].first, v[i].second));
		visited[v[i].first][v[i].second] = true;
	}
	while (!q.empty()) {
		curr_r = q.front().first;
		curr_c = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			next_r = curr_r + dr[i];
			next_c = curr_c + dc[i];
			if (isPossible(next_r, next_c) && !test[next_r][next_c] && !visited[next_r][next_c]) {
				test[next_r][next_c] = 2;
				visited[next_r][next_c] = true;
				q.push(make_pair(next_r, next_c));
			}
		}
	}
	Count();
	return;
}
bool isPossible(int r, int c) {
	return r >= 0 && r < N && c >= 0 && c < M;
}
void Count() {
	int cnt = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (!test[i][j]) cnt++;
	maxi = max(maxi, cnt);
	return;
}
