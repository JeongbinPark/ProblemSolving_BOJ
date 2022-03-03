#include <iostream>
#include <queue>
using namespace std;

bool isPossible(int, int);

int n, r1, c1, r2, c2;
bool visited[200][200];
queue<pair<int, pair<int, int> > > q;
int d_r[6] = { -2, -2, 0, 0, 2, 2 };
int d_c[6] = { -1, 1, -2, 2, -1, 1 };

int main() {
	cin >> n >> r1 >> c1 >> r2 >> c2;
	if (!(r1 == r2 && c1 == c2)){
		visited[r1][r2] = true;
		q.push(make_pair(0, make_pair(r1, c1)));
	}

	while (!q.empty()) {
		int times = q.front().first;
		int curr_r = q.front().second.first;
		int curr_c = q.front().second.second;
		if (curr_r == r2 && curr_c == c2) {
			cout << times;
			return 0;
		}
		q.pop();

		for (int d = 0; d < 6; d++) {
			int next_r = curr_r + d_r[d];
			int next_c = curr_c + d_c[d];

			if (isPossible(next_r, next_c) && !visited[next_r][next_c]) {
				visited[next_r][next_c] = true;
				q.push(make_pair(times + 1, make_pair(next_r, next_c)));
			}
		}
	}
	cout << -1;
	return 0;
}

bool isPossible(int r, int c) {
	return r >= 0 && r < n && c >= 0 && c < n;
}
