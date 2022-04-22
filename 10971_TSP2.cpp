#include <iostream>
#include <algorithm>
using namespace std;

void travel(int, int);

int N;
int W[10][10];
bool visited[10];
int startIndex;
int currResult, minResult = 10000001;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> W[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		startIndex = i;
		visited[i] = true;
		travel(i, 0);
		visited[i] = false;
	}
	cout << minResult;
	return 0;
}

void travel(int city, int cnt) {
	if (cnt == N - 1) {
		if (!W[city][startIndex]) return;
		currResult += W[city][startIndex];
		minResult = min(minResult, currResult);
		currResult -= W[city][startIndex];
		return;
	}

	for (int i = 0; i < N; i++) {
		if (W[city][i] && !visited[i]) {
			visited[i] = true;
			currResult += W[city][i];
			travel(i, cnt + 1);
			visited[i] = false;
			currResult -= W[city][i];
		}
	}
	return;
}