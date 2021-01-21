/* DFS식 백트래킹 => 시간 초과
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void find(int, int);

string maze[100];
int N, M;
int cnt = 0, minimum = 10001;
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> maze[i];

	find(0, 0);
	cout << minimum;
	return 0;
}
void find(int x, int y) {
	if (x < 0 || x >= N || y < 0 || y >= M) return;
	if (maze[x][y] == '0') return;
	cnt++;
	maze[x][y] = '0';
	if (x == N - 1 && y == M - 1) {
		minimum = min(minimum, cnt);
	}
	for (int i = 0; i < 4; i++)
		find(x + dx[i], y + dy[i]);
	cnt--;
	maze[x][y] = '1';
	return;
}
*/


//BFS 방법

#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

string maze[100];
queue< pair<int, int> > q;
queue<int> qc;
int counter[100][100] = { 0 };
int N, M, x, y, c, _x, _y, _c;
int minimum = 10001;
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> maze[i];

	counter[0][0] = 1;
	q.push(make_pair(0, 0));
	qc.push(counter[0][0]);

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		c = qc.front();
		c++;
		for (int i = 0; i < 4; i++)
		{	
			_x = x + dx[i];
			_y = y + dy[i];
			if (_x >= 0 && _x < N && _y >= 0 && _y < M && maze[_x][_y] == '1' && !counter[_x][_y]) {
				if (_x == N - 1 && _y == M - 1) {
					minimum = min(minimum, c);
				}
				q.push(make_pair(_x, _y));
				qc.push(c);
				counter[_x][_y] = c;
			}
		}
		q.pop();
		qc.pop();
	}
	
	cout << counter[N-1][M-1];
	return 0;
}
