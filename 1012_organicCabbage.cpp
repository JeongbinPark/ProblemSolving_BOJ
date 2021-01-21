#include <iostream>
#include <cstring>
using namespace std;

void dfs(int, int);

int field[50][50] = { 0 };
int T, M, N, K, cnt = 0;
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
int main() {
	cin >> T;
	while (T--) {
		memset(field, 0, sizeof(field));
		cnt = 0;
		cin >> M >> N >> K;
		while (K--) {
			int a, b;
			cin >> a >> b;
			field[a][b] = 1;
		}
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (field[i][j]) {
					dfs(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << "\n";
	}
	return 0;
}
void dfs(int x, int y) {
	if (x < 0 || x >= M || y < 0 || y >= N || !field[x][y]) return;
	field[x][y] = 0;
	for (int i = 0; i < 4; i++)
		dfs(x + dx[i], y + dy[i]);
	return;
}