#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool isPossible(int r, int c);

int M, N, K, lb_x, lb_y, rt_x, rt_y;
bool visited[100][100] = { false };
vector<int> area;
int dr[] = { 0, 1, 0, -1 }, dc[] = { 1, 0, -1, 0 };

int main() {
	cin >> M >> N >> K;
	while (K--) {
		cin >> lb_x >> lb_y >> rt_x >> rt_y;
		for (int r = lb_y; r < rt_y; r++)
			for (int c = lb_x; c < rt_x; c++)
				visited[r][c] = true;
	}

	for (int r = 0; r < M; r++)
		for (int c = 0; c < N; c++) {
			if (!visited[r][c]) {
				int idx = (int)area.size();
				area.push_back(1);

				queue<pair<int, int> > coord;
				coord.push(make_pair(r, c));
				visited[r][c] = true;
				while (!coord.empty()) {
					int curr_r = coord.front().first;
					int curr_c = coord.front().second;

					coord.pop();

					for (int d = 0; d < 4; d++) {
						int next_r = curr_r + dr[d];
						int next_c = curr_c + dc[d];
						if (isPossible(next_r, next_c) && !visited[next_r][next_c]) {
							visited[next_r][next_c] = true;
							area[idx]++;
							coord.push(make_pair(next_r, next_c));
						}
					}
				}
			}
		}

	sort(area.begin(), area.end());

	int cnt = (int)area.size();
	cout << cnt << "\n";
	for (int i = 0; i < cnt; i++)
		cout << area[i] << " ";

	return 0;
}

bool isPossible(int r, int c) {
	return r >= 0 && r < M && c >= 0 && c < N;
}