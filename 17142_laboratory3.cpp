//ÀÎµ¦½º Çò°¥¸®Áö ¾Êµµ·Ï!
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#define INF 2500
using namespace std;

void calcMinTime();
void chooseViruses(int index, int cnt);
void makeVirusMap();
bool isPossible(int r, int c);

int N, M;
int input[50][50];
int virusCnt;
int virusCoor[11][2];
int chosenVirusIndex[10];
int dr[] = { 0, 1, 0, -1 }, dc[] = { 1, 0, -1, 0 };
int minTime = INF;

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> input[i][j];
			if (input[i][j] == 2) {
				virusCnt++;
				virusCoor[virusCnt][0] = i;
				virusCoor[virusCnt][1] = j;
			}
		}
	}
	
	calcMinTime();

	cout << (minTime != INF ? minTime : -1);
	return 0;
}

void calcMinTime() {
	chooseViruses(1, 0);
	return;
}

void chooseViruses(int index, int cnt) {
	if (cnt == M) {
		makeVirusMap();
		return;
	}
	if (index > virusCnt) {
		return;
	}

	chooseViruses(index + 1, cnt);
	chosenVirusIndex[cnt] = index;
	chooseViruses(index + 1, cnt + 1);
	return;
};

void makeVirusMap() {
	int currMaxTime = 0;
	bool visited[50][50];
	memset(visited, 0, sizeof(visited));
	queue<pair<int, pair<int, int> > > q;
	for (int i = 0; i < M; i++) {
		int virusIndex = chosenVirusIndex[i];
		int virusR = virusCoor[virusIndex][0];
		int virusC = virusCoor[virusIndex][1];
		visited[virusR][virusC] = true;
		q.push(make_pair(0, make_pair(virusR, virusC)));
	}

	while (!q.empty()) {
		int times = q.front().first;
		int currR = q.front().second.first;
		int currC = q.front().second.second;
		if (input[currR][currC] == 0) {
			currMaxTime = max(currMaxTime, times);
		}
		q.pop();

		for (int d = 0; d < 4; d++) {
			int nextR = currR + dr[d];
			int nextC = currC + dc[d];

			if (isPossible(nextR, nextC) && !visited[nextR][nextC] && input[nextR][nextC] != 1) {
				visited[nextR][nextC] = true;
				q.push(make_pair(times + 1, make_pair(nextR, nextC)));
			}
		}
	}
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			if (!input[r][c] && !visited[r][c]) {
				return;
			}
		}
	}
	minTime = min(minTime, currMaxTime);
	return;
}

bool isPossible(int r, int c) {
	return r >= 0 && r < N && c >= 0 && c < N;
}