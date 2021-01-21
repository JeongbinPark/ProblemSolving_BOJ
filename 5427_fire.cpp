#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

bool isPossible(int, int);

struct node {
	int row, col, time;
	char state;
};

int t, w, h, sg_r, sg_c, curr_r, curr_c, next_r, next_c, time;
char state;
char board[1001][1001];
bool fire[1001][1001], visited[1001][1001];
queue< node > q;
bool impossible;
int dr[] = { 0, 1, 0, -1 }, dc[] = { 1, 0, -1, 0 };
node tmp;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> t;
	while (t--) {
		impossible = true;
		memset(fire, false, sizeof(fire));
		memset(visited, false, sizeof(visited));
		while (!q.empty()) q.pop();

		cin >> w >> h;
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++) {
				cin >> state;
				board[i][j] = state;
				if (state == '*') {
					tmp.row = i, tmp.col = j, tmp.time = 0, tmp.state = '*';
					q.push(tmp);
					fire[i][j] = true;
				}
				else if (state == '@') {
					sg_r = i, sg_c = j;
				}
			}

		tmp.row = sg_r, tmp.col = sg_c, tmp.time = 0, tmp.state = '@';
		q.push(tmp);
		visited[sg_r][sg_c] = true;
		while (!q.empty() && impossible) {
			curr_r = q.front().row;
			curr_c = q.front().col;
			time = q.front().time;
			state = q.front().state;
			q.pop();

			if (state == '*') {
				for (int i = 0; i < 4; i++) {
					next_r = curr_r + dr[i];
					next_c = curr_c + dc[i];
					if (isPossible(next_r, next_c) && board[next_r][next_c] != '#' && !fire[next_r][next_c]) {
						board[next_r][next_c] = '*';
						fire[next_r][next_c] = true;
						tmp.row = next_r, tmp.col = next_c, tmp.time = time + 1, tmp.state = '*';
						q.push(tmp);
					}
				}
			}
			else if (state == '@') {
				for (int i = 0; i < 4; i++) {
					next_r = curr_r + dr[i];
					next_c = curr_c + dc[i];
					if (!isPossible(next_r, next_c)) {
						impossible = false;
						break;
					}
					else if (board[next_r][next_c] == '.' && !fire[next_r][next_c] && !visited[next_r][next_c]) {
						visited[next_r][next_c] = true;
						tmp.row = next_r, tmp.col = next_c, tmp.time = time + 1, tmp.state = '@';
						q.push(tmp);
					}

				}
			}
		}
		if (impossible) cout << "IMPOSSIBLE\n";
		else cout << time + 1 << "\n";
	}
	return 0;
}
bool isPossible(int x, int y) {
	return x >= 0 && x < h&& y >= 0 && y < w;
}

//dp 방법으로 불과 사람 각각 인덱스 위치에 갈 수 있는 시간을 저장해서
//가장 자리에서 사람 < 불 이면 최솟값으로 출력