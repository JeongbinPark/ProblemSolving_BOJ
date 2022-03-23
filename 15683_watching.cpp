//c++11 ÀÌ»ף
#include <iostream>
#include <vector>
#include <algorithm>
#define INF 65
using namespace std;

void findBlindSpot(int cctv_idx);
int countBlindSpots();
void watchByDirection(int r, int c, int d);
void unwatchByDirection(int r, int c, int d);
bool isPossible(int r, int c);

int N, M;
int board[8][8];
int d_r[4] = { -1, 0, 1, 0 };
int d_c[4] = { 0, 1, 0, -1 };
vector< vector<int> > cctv[6] = {
	{  },
	{ { 0 },{ 1 },{ 2 },{ 3 } },
	{ { 0, 2 },{ 1, 3 } },
	{ { 0, 1 },{ 1, 2 },{ 2, 3 },{ 3, 0 } },
	{ { 0, 1, 2 },{ 1, 2, 3 },{ 2, 3, 0 },{ 3, 0, 1 } },
	{ { 0 ,1, 2, 3 } }
};
vector< pair<int, int> > cctv_coor;
int minBlind = INF;
int watched[8][8];

int main() {
	cin >> N >> M;

	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			cin >> board[r][c];
			if (board[r][c] > 0 && board[r][c] < 6) {
				cctv_coor.push_back(make_pair(r, c));
			}
		}
	}

	findBlindSpot(0);

	cout << minBlind;
	return 0;
}

void findBlindSpot(int cctv_idx) {
	if (cctv_idx == (int) cctv_coor.size()) {
		int blindsopts = countBlindSpots();
		minBlind = min(minBlind, blindsopts);
		return;
	};

	int r = cctv_coor[cctv_idx].first;
	int c = cctv_coor[cctv_idx].second;
	int cctvNum = board[r][c];

	for (int turn = 0; turn < (int)cctv[cctvNum].size(); turn++) {
		for (int d = 0; d < (int)cctv[cctvNum][turn].size(); d++) {
			watchByDirection(r, c, cctv[cctvNum][turn][d]);
		}

		findBlindSpot(cctv_idx + 1);

		for (int d = 0; d < (int)cctv[cctvNum][turn].size(); d++) {
			unwatchByDirection(r, c, cctv[cctvNum][turn][d]);
		}
	}
	return;
}

int countBlindSpots() {
	int blinds = 0;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			if (board[r][c] == 0 && watched[r][c] == 0) {
				blinds++;
			}
		}
	}
	return blinds;
}

void watchByDirection(int r, int c, int d) {
	int next_r = r;
	int next_c = c;

	while (true) {
		next_r += d_r[d];
		next_c += d_c[d];
		if (!isPossible(next_r, next_c)) {
			break;
		}
		watched[next_r][next_c]++;
	}
	return;
}

void unwatchByDirection(int r, int c, int d) {
	int next_r = r;
	int next_c = c;

	while (true) {
		next_r += d_r[d];
		next_c += d_c[d];
		if (!isPossible(next_r, next_c)) {
			break;
		}
		watched[next_r][next_c]--;
	}
	return;
}

bool isPossible(int r, int c) {
	return r >= 0 && r < N && c >= 0 && c < M && board[r][c] != 6;
}