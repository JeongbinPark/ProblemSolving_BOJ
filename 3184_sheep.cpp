#include <iostream>
#include <queue>
using namespace std;

bool isPossible(int, int);

int R, C;
char field[250][250];
bool visited[250][250] = { 0 };
queue< pair<int, int> > q;
int d_r[4] = { 0, 1, 0, -1 };
int d_c[4] = { 1, 0, -1, 0 };
int result_o = 0, result_v = 0;

int main() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> field[i][j];
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (field[i][j] != '#' && !visited[i][j]) {
				q.push(make_pair(i, j));
				visited[i][j] = true;
				int cnt_o = 0, cnt_v = 0;

				while (!q.empty()) {
					int front_r = q.front().first;
					int front_c = q.front().second;
					q.pop();

					if (field[front_r][front_c] == 'o') cnt_o++;
					if (field[front_r][front_c] == 'v') cnt_v++;

					for (int d = 0; d < 4; d++) {
						int next_r = front_r + d_r[d];
						int next_c = front_c + d_c[d];

						if (isPossible(next_r, next_c) && field[next_r][next_c] != '#' && !visited[next_r][next_c]) {
							q.push(make_pair(next_r, next_c));
							visited[next_r][next_c] = true;
						}
					}

				}
				if (cnt_o > cnt_v) result_o += cnt_o;
				else result_v += cnt_v;
			}
		}
	}
	cout << result_o << " " << result_v;
	return 0;
}

bool isPossible(int r, int c) {
	return (r >= 0 && r < R && c >= 0 && c < C);
}