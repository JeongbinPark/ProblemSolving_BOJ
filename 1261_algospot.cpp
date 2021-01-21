/*엥..? struct 안에 struct인데 작동을 안하는 거지?
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#define INF 201
using namespace std;

struct node {
	int r, c;
};

int N, M;
string board[102];
int dist[102][102];
priority_queue< pair<int, struct node> > pq;
struct node tmp;

int curr_r, curr_c, curr_d, next_r, next_c, next_d;
int dr[] = { 1, 0, -1, 0 }, dc[] = { 0, 1, 0, -1 };

int main() {
	cin >> M >> N;
	for (int i = 1; i <= N; i++)
		cin >> board[i];
	fill(dist[0], dist[N + 1], INF);

	tmp.r = 1, tmp.c = 1;
	pq.push(make_pair(0, tmp));
	while (!pq.empty()) {
		curr_d = -pq.top().first, curr_r = pq.top().second.r, curr_c = pq.top().second.c;
		pq.pop();
		if (dist[curr_r][curr_c] < curr_d) continue;
		for (int i = 0; i < 4; i++) {
			next_r = curr_r + dr[i];
			next_c = curr_c + dc[i];
			next_d = curr_d + board[curr_r][curr_c] - '0';
			if (dist[next_r][next_c] > next_d) {
				dist[next_r][next_c] = next_d;
				tmp.r = next_r, tmp.c = next_c;
				pq.push(make_pair(-next_d, tmp));
			}
		}
	}
	cout << dist[N][M];
	return 0;
}
*/

#include <iostream>
#include <queue>
#include <algorithm>
#define INF 201
using namespace std;

bool isPossible(int, int);

int N, M;
char c;
int board[102][102];
int dist[103][102];
priority_queue< pair<int, pair<int, int> > > pq;

int curr_d, curr_r, curr_c, next_d, next_r, next_c;
int dr[] = { 1, 0, -1, 0 }, dc[] = { 0, 1, 0, -1 };

int main() {
	cin >> M >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++) {
			cin >> c;
			board[i][j] = c - '0';
		}

	fill(dist[0], dist[N + 2], INF);
	dist[1][1] = 0;
	pq.push(make_pair(0, make_pair(1, 1)));
	while (!pq.empty()) {
		curr_d = -pq.top().first, curr_r = pq.top().second.first, curr_c = pq.top().second.second;
		pq.pop();
		if (dist[curr_r][curr_c] < curr_d) continue;
		for (int i = 0; i < 4; i++) {
			next_r = curr_r + dr[i];
			next_c = curr_c + dc[i];
			next_d = curr_d + board[next_r][next_c];
			if (isPossible(next_r, next_c) && dist[next_r][next_c] > next_d) {
				dist[next_r][next_c] = next_d;
				pq.push(make_pair(-next_d, make_pair(next_r, next_c)));
			}
		}
	}
	cout << dist[N][M];
	return 0;
}
bool isPossible(int r, int c) {
	return r > 0 && r <= N && c > 0 && c <= M;
}

//c++11 이상에서는 tuple 사용하여 (r, c, d) 가능