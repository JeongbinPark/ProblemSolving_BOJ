#include <iostream>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;

bool isPossible(int, int);

int N, max_field, curr_field, h, curr_r, curr_c, next_r, next_c;
int height[101][101];
bool visited[101][101];
int dr[] = { -1, 0, 1, 0 }, dc[] = { 0, -1, 0, 1 };
queue< pair<int, int> > q;
set<int> s;

int main() {
	cin >> N;
	s.insert(0);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> height[i][j];
			s.insert(height[i][j]);
		}
	set<int>::iterator it;
	for (it = s.begin(); it != s.end(); it++) {
		h = *it;
		curr_field = 0;
		fill(visited[0], visited[N], false);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visited[i][j] && height[i][j] > h) {
					curr_field++;
					q.push(make_pair(i, j));
					visited[i][j] = true;
					while (!q.empty()) {
						curr_r = q.front().first;
						curr_c = q.front().second;
						q.pop();

						for (int d = 0; d < 4; d++) {
							next_r = curr_r + dr[d];
							next_c = curr_c + dc[d];
							if (isPossible(next_r, next_c) && height[next_r][next_c] > h && !visited[next_r][next_c]) {
								visited[next_r][next_c] = true;
								q.push(make_pair(next_r, next_c));
							}
						}

					}
				}

			}
		}
		max_field = max(max_field, curr_field);
	}
	cout << max_field;
	return 0;
}

bool isPossible(int r, int c) {
	return r >= 0 && r < N && c >= 0 && c < N;
}