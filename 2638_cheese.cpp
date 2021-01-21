#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

bool isPossible(int, int);

int N, M, curr_r, curr_c, curr_time, next_r, next_c;
int cheese[101][101], air[101][101];
bool visited[101][101];
priority_queue< pair<int, pair<int, int> > > pq;
int dr[] = { 0, 1, 0, -1 }, dc[] = { 1, 0, -1, 0 };

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			cin >> cheese[i][j];
		}

	pq.push(make_pair(0, make_pair(0, 0)));
	visited[0][0] = true;
	while (!pq.empty()) {
		curr_time = -pq.top().first;
		curr_r = pq.top().second.first;
		curr_c = pq.top().second.second;
		pq.pop();

		for (int i = 0; i < 4; i++) {
			next_r = curr_r + dr[i];
			next_c = curr_c + dc[i];
			if (isPossible(next_r, next_c) && !visited[next_r][next_c]) {
				if (cheese[next_r][next_c] == 1) {
					air[next_r][next_c]++;
					if (air[next_r][next_c] == 2) {
						visited[next_r][next_c] = true;
						cheese[next_r][next_c] = 0;
						pq.push(make_pair(-curr_time - 1, make_pair(next_r, next_c)));
					}
				} else{
					visited[next_r][next_c] = true;
					cheese[next_r][next_c] = 0;
					pq.push(make_pair(-curr_time, make_pair(next_r, next_c)));
				}
			}
		}
	}

	cout <<curr_time;
	return 0;
}

bool isPossible(int r, int c) {
	return r >= 0 && r < N && c >= 0 && c < M;
}