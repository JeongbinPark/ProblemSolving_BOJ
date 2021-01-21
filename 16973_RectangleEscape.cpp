/* DFS => 시간초과 예상
#include <iostream>
#include <algorithm>
#define INF 1000001
using namespace std;

void move(int, int, int);
bool isPossible(int, int);

int N, M, H, W, Sr, Sc, Fr, Fc, sum, cnt = INF;
int board[1001][1001];
bool visited[1001][1001];
int dr[] = { 1, 0, -1, 0 }, dc[] = { 0, 1, 0, -1 };

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		sum = 0;
		for (int j = 1; j <= M; j++) {
			cin >> board[i][j];
			sum += board[i][j];
			board[i][j] = sum + board[i - 1][j];
		}
	}
	cin >> H >> W >> Sr >> Sc >> Fr >> Fc;
	H--, W--;
	move(Sr, Sc, 0);
	if (cnt == INF) cout << -1;
	else cout << cnt;
	return 0;
}
void move(int r, int c, int level) {
	if (visited[r][c] || !isPossible(r, c)) return;
	if (r == Fr && c == Fc) {
		cnt = min(cnt, level);
		return;
	}
	visited[r][c] = true;
	for (int i = 0; i < 4; i++) {
		move(r + dr[i], c + dc[i], level + 1);
	}
	visited[r][c] = false;
	return;
}
bool isPossible(int r, int c) {
	if (r < 1 || r > N - H || c < 1 || c > M - W) return false;
	return !(board[r + H][c + W] + board[r - 1][c - 1] - board[r - 1][c + W] - board[r + H][c - 1]);
};
*/

//	BFS 이용
#include <iostream>
#include <queue>
#include <algorithm>
#define INF 1000001
using namespace std;

bool isPossible(int, int);

int N, M, H, W, Sr, Sc, Fr, Fc, sum, cnt = INF;
int board[1001][1001];
bool visited[1001][1001];
int dr[] = { 1, 0, -1, 0 }, dc[] = { 0, 1, 0, -1 };
queue< pair<int, pair<int, int> > > q;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		sum = 0;
		for (int j = 1; j <= M; j++) {
			cin >> board[i][j];
			sum += board[i][j];
			board[i][j] = sum + board[i - 1][j];
		}
	}
	cin >> H >> W >> Sr >> Sc >> Fr >> Fc;
	H--, W--;

	int level, r, c, next_r, next_c;

	visited[Sr][Sc] = true;
	q.push(make_pair(0,(make_pair(Sr, Sc))));
	while (!q.empty()) {
		level = q.front().first;
		r = q.front().second.first;
		c = q.front().second.second;
		q.pop();
		if (r == Fr && c == Fc) {
			cnt = min(cnt, level);
			continue;
		}
		for (int i = 0; i < 4; i++) {
			next_r = r + dr[i];
			next_c = c + dc[i];
			if (!visited[next_r][next_c] && isPossible(next_r, next_c)) {
				q.push(make_pair(level + 1, (make_pair(next_r, next_c))));
				visited[next_r][next_c] = true;
			}
		}
	}
	if (cnt == INF) cout << -1;
	else cout << cnt;
	return 0;
}
bool isPossible(int r, int c) {
	if (r < 1 || r > N - H || c < 1 || c > M - W) return false;
	return !(board[r + H][c + W] + board[r - 1][c - 1] - board[r - 1][c + W] - board[r + H][c - 1]);
};