#include <iostream>
using namespace std;

bool isOnePaper(int r, int c, int width);
void countPaper(int r, int c, int width);

int N;
int paper[2187][2187];
int cnt[3];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> paper[i][j];
		}
	}

	countPaper(0, 0, N);
	cout << cnt[0] << " " << cnt[1] << " " << cnt[2];
	return 0;
}

bool isOnePaper(int r, int c, int width) {
	int num = paper[r][c];
	bool sameNum = true;
	for (int i = r; sameNum && i < r + width; i++) {
		for (int j = c; j < c + width; j++) {
			if (num != paper[i][j]) {
				sameNum = false;
				break;
			}
		}
	}
	if (sameNum) {
		cnt[num + 1]++;
		return true;
	}
	return false;
}
void countPaper(int r, int c, int width) {
	if (isOnePaper(r, c, width)) return;

	int nextWidth = width / 3;
	int nextR = r;
	int nextC = c;
	for (int i = 0; i < 3; i++) {
		nextC = c;
		for (int j = 0; j < 3; j++) {
			countPaper(nextR, nextC, nextWidth);
			nextC += nextWidth;
		}
		nextR += nextWidth;
	}
	return;
}