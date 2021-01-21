#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

bool isPossible(int, int);

struct node {
	int row, col, time;
	char state;
};

int R, C, sg_r, sg_c, curr_r, curr_c, next_r, next_c, time;
char state;
char board[1001][1001];
bool fire[1001][1001], visited[1001][1001];
queue< node > q;
bool possible;
int dr[] = { 0, 1, 0, -1 }, dc[] = { 1, 0, -1, 0 };
node tmp;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> R >> C;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++) {
			cin >> state;
			board[i][j] = state;
			if (state == 'F') {
				tmp.row = i, tmp.col = j, tmp.time = 0, tmp.state = 'F';
				q.push(tmp);
				fire[i][j] = true;
			}
			else if (state == 'J') {
				sg_r = i, sg_c = j;
			}
		}

	tmp.row = sg_r, tmp.col = sg_c, tmp.time = 0, tmp.state = 'J';
	q.push(tmp);
	visited[sg_r][sg_c] = true;
	while (!q.empty() && !possible) {
		curr_r = q.front().row;
		curr_c = q.front().col;
		time = q.front().time;
		state = q.front().state;
		q.pop();

		if (state == 'F') {
			for (int i = 0; i < 4; i++) {
				next_r = curr_r + dr[i];
				next_c = curr_c + dc[i];
				if (isPossible(next_r, next_c) && board[next_r][next_c] != '#' && !fire[next_r][next_c]) {
					board[next_r][next_c] = 'F';
					fire[next_r][next_c] = true;
					tmp.row = next_r, tmp.col = next_c, tmp.time = time + 1, tmp.state = 'F';
					q.push(tmp);
				}
			}
		}
		else if (state == 'J') {
			for (int i = 0; i < 4; i++) {
				next_r = curr_r + dr[i];
				next_c = curr_c + dc[i];
				if (!isPossible(next_r, next_c)) {
					possible = true;
					break;
				}
				else if (board[next_r][next_c] == '.' && !fire[next_r][next_c] && !visited[next_r][next_c]) {
					visited[next_r][next_c] = true;
					tmp.row = next_r, tmp.col = next_c, tmp.time = time + 1, tmp.state = 'J';
					q.push(tmp);
				}

			}
		}
	}
	if (!possible) cout << "IMPOSSIBLE";
	else cout << time + 1;
	
	return 0;
}
bool isPossible(int x, int y) {
	return x >= 0 && x < R && y >= 0 && y < C;
}