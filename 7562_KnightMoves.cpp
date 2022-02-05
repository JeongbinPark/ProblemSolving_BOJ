#include <iostream>
#include <queue>
using namespace std;

bool isPossible(int, int);

int T;
int L;
int s_r, s_c, e_r, e_c;
int d_r[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int d_c[] = {1, 2, 2, 1, -1, -2, -2, -1};

int main() {
	cin >> T;
	while (T--) {
		bool visited[300][300] = { 0 };
		queue< pair<int, pair<int, int> > > q;

		cin >> L >> s_r >> s_c >> e_r >> e_c;

		q.push(make_pair(0, make_pair(s_r, s_c)));
		visited[s_r][s_c] = true;

		while (!q.empty()) {
			int curr_move = q.front().first;
			int curr_r = q.front().second.first;
			int curr_c = q.front().second.second;
			q.pop();

			if (curr_r == e_r && curr_c == e_c) {
				cout << curr_move << "\n"; 
				break;
			}

			for (int d = 0; d < 8; d++) {
				int next_move = curr_move + 1;
				int next_r = curr_r + d_r[d];
				int next_c = curr_c + d_c[d];

				if (isPossible(next_r, next_c) && !visited[next_r][next_c]) {
					visited[next_r][next_c] = true;
					q.push(make_pair(next_move, make_pair(next_r, next_c)));
				}
			}
		}

	}
	return 0;
}

bool isPossible(int r, int c) {
	return r >= 0 && r < L && c >= 0 && c < L;
}
