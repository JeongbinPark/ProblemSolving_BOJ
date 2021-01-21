#include <iostream>
#include <queue>
using namespace std;

bool isPossible(int, int);

int M, N;
int boxes[1000][1000];
bool visited[1000][1000] = { false };
queue< pair<int, int> > pos;
queue<int> day;

int main() {
	cin >> M >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			cin >> boxes[i][j];
			if (boxes[i][j] == 1) {
				pos.push(make_pair(i, j));
				day.push(0);
				visited[i][j] = true;
			}
			else if (boxes[i][j] == -1) {
				visited[i][j] = true;
			}
		}

	int x, y, d;
	int dx[] = { 1, 0, -1, 0 }, dy[] = { 0, 1, 0, -1 };
	while (!pos.empty()) {
		x = pos.front().first;
		y = pos.front().second;
		d = day.front();
		for (int i = 0; i < 4; i++)
		{
			if (isPossible(x + dx[i], y+dy[i])) {
				pos.push(make_pair(x + dx[i], y + dy[i]));
				day.push(d + 1);
				visited[x + dx[i]][y + dy[i]] = true;
			}
		}
		pos.pop();
		day.pop();
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			if (!visited[i][j]) {
				cout << -1;
				return 0;
			}
		}
	cout << d;

	return 0;
}

bool isPossible(int x, int y) {
	if (x < 0 || x >= N || y < 0 || y >= M) return false;
	if (visited[x][y]) return false;
	if (boxes[x][y] != 0) return false;
	return true;
}