#include <iostream>
#include <algorithm>
using namespace std;

int calc(int, int);
bool isPossible(int, int);

int N, cnt;
int forest[501][500], days[501][500];
int dr[] = { 1, 0, -1, 0 }, dc[] = { 0, 1, 0, -1 };

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> forest[i][j];
	fill(days[0], days[N], -1);


	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			if (days[i][j] == -1) {
				cnt = max(cnt, calc(i, j));
			}
		}

	cout << cnt;
	return 0;
}
int calc(int r, int c) {
	int maxi = 1;
	if (days[r][c] != -1) return days[r][c];
	for (int i = 0; i < 4; i++) {
		if (isPossible(r + dr[i], c + dc[i]) && forest[r + dr[i]][c + dc[i]] > forest[r][c]) {
			maxi = max(maxi, calc(r + dr[i], c + dc[i]) + 1);
		}
	}
	days[r][c] = maxi;
	return maxi;
}
bool isPossible(int r, int c) {
	return r >= 0 && r < N && c >= 0 && c < N;
}