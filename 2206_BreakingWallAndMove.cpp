#include <iostream>
#include <queue>
#include <algorithm>
#define INF 1000001
using namespace std;

bool isPossible(int, int);

struct node {
	int r, c, cnt;
	bool breaked;
};

int N, M, r, c, mini = INF;
char num;
int board[1001][1001];
bool visited[1001][1001][2];
queue<node> q;
node n, tmp;
int dr[] = { 1, 0, - 1, 0 }, dc[] = { 0, 1, 0, -1 };

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N >> M;
	for(int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			cin >> num;
			board[i][j] = num - '0';
		}
	n.r = 0, n.c = 0, n.cnt = 0, n.breaked = false;
	q.push(n);
	visited[n.r][n.c][1] = true;
	visited[n.r][n.c][0] = true;
	while (!q.empty()) {
		n = q.front();
		q.pop();
		if (n.r == N - 1 && n.c == M - 1) {
			mini = n.cnt;
			break;
		}
		for (int i = 0; i < 4; i++) {
			r = n.r + dr[i];
			c = n.c + dc[i];
			if (isPossible(r, c)) {
				tmp.r = r, tmp.c = c, tmp.cnt = n.cnt + 1;
				if (!n.breaked && !board[r][c] && !visited[r][c][1]) {
					visited[r][c][1] = true;
					tmp.breaked = false;
					q.push(tmp);
				}
				else if (n.breaked && !board[r][c] && !visited[r][c][0]) {
					visited[r][c][0] = true;
					tmp.breaked = true;
					q.push(tmp);
				}
				else if (!n.breaked && board[r][c] && !visited[r][c][0]) {
					visited[r][c][0] = true;
					tmp.breaked = true;
					q.push(tmp);
				}
			}
		}
	}
	cout << (mini == INF ? -1 : mini + 1);
	return 0;
}

bool isPossible(int x, int y) {
	return x >= 0 && x < N && y >= 0 && y < M;
}