#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int maze[1001][1001];

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> maze[i][j];
			maze[i][j] += max(maze[i - 1][j - 1], max(maze[i - 1][j], maze[i][j - 1]));
		}
	}
	cout << maze[N][M];
	return 0;
}