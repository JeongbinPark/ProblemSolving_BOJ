/*왜 틀리지?
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool isPossible(int, int);

int M, N, H;
int boxes[10000][100];
bool visited[10000][100] = { false };
queue< pair<int, int> > pos;
queue<int> day;

int main() {
	cin >> M >> N >> H;
	for (int i = 0; i < N * H; i++)
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
	vector<int> dx, dy;
	dx.push_back(1), dx.push_back(0), dx.push_back(-1), dx.push_back(0), dx.push_back(N), dx.push_back(-N);
	dy.push_back(0), dy.push_back(1), dy.push_back(0), dy.push_back(-1), dy.push_back(0), dy.push_back(0);
	while (!pos.empty()) {
		x = pos.front().first;
		y = pos.front().second;
		d = day.front();
		for (int i = 0; i < 6; i++)
		{
			if (isPossible(x + dx[i], y + dy[i])) {
				pos.push(make_pair(x + dx[i], y + dy[i]));
				day.push(d + 1);
				visited[x + dx[i]][y + dy[i]] = true;
			}
		}
		pos.pop();
		day.pop();
	}
	for (int i = 0; i < N * H; i++)
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
	if (x < 0 || x >= N * H || y < 0 || y >= M) return false;
	if (visited[x][y]) return false;
	if (boxes[x][y] != 0) return false;
	return true;
}
*/
#include <iostream>
#include <queue>
using namespace std;

bool isPossible(int, int, int);

struct node {
	int x, y, z, day;
};

int M, N, H;
int boxes[100][100][100];
bool visited[100][100][100] = { false };
queue<node> pos;
node tmp;

int main() {
	cin >> M >> N >> H;


	for (int i = 0; i < H; i++)
		for (int j = 0; j < N; j++) 
			for (int k = 0; k < M; k++) {
				cin >> boxes[i][j][k];
				if (boxes[i][j][k] == 1) {
					tmp.x = j, tmp.y = k, tmp.z = i, tmp.day = 0;
					pos.push(tmp);
					visited[i][j][k] = true;
				}
				else if (boxes[i][j][k] == -1) {
					visited[i][j][k] = true;
				}
			}

	int x, y, z, d;
	int dx[] = { 1, 0, -1, 0, 0, 0 }, dy[] = { 0, 1, 0, -1, 0, 0 }, dz[] = {0, 0, 0, 0, 1, -1};
	while (!pos.empty()) {
		x = pos.front().x;
		y = pos.front().y;
		z = pos.front().z;
		d = pos.front().day;
		for (int i = 0; i < 6; i++)
		{
			if (isPossible(x + dx[i], y + dy[i], z + dz[i])) {
				tmp.x = x + dx[i], tmp.y = y + dy[i], tmp.z = z + dz[i], tmp.day = d + 1;
				pos.push(tmp);
				visited[tmp.z][tmp.x][tmp.y] = true;
			}
		}
		pos.pop();
	}
	for (int i = 0; i < H; i++)
		for (int j = 0; j < N; j++)
			for (int k = 0; k < M; k++) 
				if (!visited[i][j][k]) {
					cout << -1;
					return 0;
				}
	cout << d;

	return 0;
}

bool isPossible(int x, int y, int z) {
	if (x < 0 || x >= N || y < 0 || y >= M || z < 0 || z >= H ) return false;
	if (visited[z][x][y]) return false;
	if (boxes[z][x][y] != 0) return false;
	return true;
}