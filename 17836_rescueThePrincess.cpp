#include <iostream>
#include <queue>
#include <algorithm>
#define MAX_TIME 10001
using namespace std;

int minTimeWithoutGram();
bool isPossible(int, int);

int N, M, T;
int map[100][100];
int d_r[4] = { 0, 1, 0, -1 };
int d_c[4] = { 1, 0, -1, 0 };
int minTime = MAX_TIME;
int gramRow = -1, gramCol = -1;
int gramTime = MAX_TIME;

int main() {
	cin >> N >> M >> T;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			cin >> map[r][c];
		}
	}
	int timeWithoutGram = minTimeWithoutGram();
	minTime = min(timeWithoutGram, gramTime + N + M - 2 - gramRow - gramCol);

	if (minTime <= T) {
		cout << minTime;
	}
	else {
		cout << "Fail";
	}
	return 0;
}

int minTimeWithoutGram() {
	int timeMap[100][100];
	fill(&timeMap[0][0], &timeMap[99][100], MAX_TIME);

	queue<pair<int, pair<int, int>>> q;
	q.push(make_pair(0, make_pair(0, 0)));
	timeMap[0][0] = 0;
	while (!q.empty()) {
		int currTime = q.front().first;
		int currRow = q.front().second.first;
		int currCol = q.front().second.second;
		q.pop();

		if (currRow == N - 1 && currCol == M - 1) {
			return currTime;
		}
		if (map[currRow][currCol] == 2 && gramTime == MAX_TIME) {
			gramTime = currTime;
			gramRow = currRow;
			gramCol = currCol;
		}

		for (int d = 0; d < 4; d++) {
			int nextRow = currRow + d_r[d];
			int nextCol = currCol + d_c[d];
			if (isPossible(nextRow, nextCol) && map[nextRow][nextCol] != 1 && timeMap[nextRow][nextCol] > currTime + 1) {
				timeMap[nextRow][nextCol] = currTime + 1;
				q.push(make_pair(currTime + 1, make_pair(nextRow, nextCol)));
			}
		}
	}
	return timeMap[N - 1][M - 1];
}

bool isPossible(int r, int c) {
	return r >= 0 && r < N && c >= 0 && c < M;
}
