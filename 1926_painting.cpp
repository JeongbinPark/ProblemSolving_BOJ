#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

bool isPossible(int, int);

int n, m, tmp;
bool painting[500][500];
bool visited[500][500];
int countPainting = 0;
int largest = 0;
queue<pair<int, int> > q;
int d_r[4] = { 0, 1, 0, -1 };
int d_c[4] = { 1, 0, -1, 0 };

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> tmp;
			painting[i][j] = tmp;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!painting[i][j] || visited[i][j]) continue;

			q.push(make_pair(i,j));
			visited[i][j] = true;
			countPainting++;
			int sizePainting = 0;

			while (!q.empty()) {
				int r = q.front().first;
				int c = q.front().second;
				sizePainting++;

				q.pop();

				for (int d = 0; d < 4; d++) {
					int next_r = r + d_r[d];
					int next_c = c + d_c[d];
					if (isPossible(next_r, next_c) && painting[next_r][next_c] && !visited[next_r][next_c]) {
						visited[next_r][next_c] = true;
						q.push(make_pair(next_r, next_c));
					}
				}
				
			}
			largest = max(largest, sizePainting);
		}
	}
	cout << countPainting << "\n" << largest;
	return 0;
}

bool isPossible(int r, int c) {
	return r >= 0 && r < n && c >= 0 && c < m;
}