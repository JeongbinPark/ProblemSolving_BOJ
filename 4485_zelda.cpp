#include <iostream>
#include <queue>
#include <algorithm>
#define INF 3000
using namespace std;

bool isPossible(int, int);

int N, T;
int board[127][127];
int cost[128][127];
priority_queue< pair<int, pair<int, int> > > pq;

int curr_c, curr_x, curr_y, next_c, next_x, next_y;
int dx[] = { 1, 0, -1, 0 }, dy[] = { 0, 1, 0, -1 };

int main() {
	while (true) {
		cin >> N;
		if (N == 0) break;
		T++;

		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				cin >> board[i][j];

		fill(cost[0], cost[N + 2], INF);
		cost[1][1] = board[1][1];
		pq.push(make_pair(-cost[1][1], make_pair(1, 1)));
		while (!pq.empty()) {
			curr_c = -pq.top().first;
			curr_x = pq.top().second.first;
			curr_y = pq.top().second.second;
			pq.pop();

			if (cost[curr_x][curr_y] < curr_c) continue;

			for (int i = 0; i < 4; i++) {
				next_x = curr_x + dx[i];
				next_y = curr_y + dy[i];
				next_c = curr_c + board[next_x][next_y];
				if (isPossible(next_x, next_y) && next_c < cost[next_x][next_y]) {
					cost[next_x][next_y] = next_c;
					pq.push(make_pair(-next_c, make_pair(next_x, next_y)));
				}
			}
		}
		cout << "Problem " << T << ": " << cost[N][N] << "\n";
	}
	return 0;
}

bool isPossible(int x, int y) {
	return x > 0 && x <= N && y > 0 && y <= N;
}