#include <iostream>
#include <map>
using namespace std;

void CalcLeftTop(int r, int c);
void MatchWithRightBottom(int r, int c);
void CalcRightTop(int r, int c);
void MatchWithLeftBottom(int r, int c);

int N, sum, cnt;
int board[51][51], tmp[52][51];
map<int, int> m;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];

	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < N - 1; j++) {
			CalcLeftTop(i, j);
			MatchWithRightBottom(i + 1, j + 1);
			m.clear();

			CalcRightTop(i, j + 1);
			MatchWithLeftBottom(i + 1, j);
			m.clear();
		}
	}
	cout << cnt;
	return 0;
}
void CalcLeftTop(int r, int c) {
	fill(tmp[0], tmp[N + 1], 0);
	for (int i = r; i >= 0; i--) {
		sum = 0;
		for (int j = c; j >= 0; j--) {
			sum += board[i][j];
			tmp[i][j] = sum + tmp[i + 1][j];
			m[tmp[i][j]]++;
		}
	}
}
void MatchWithRightBottom(int r, int c) {
	fill(tmp[0], tmp[N + 1], 0);
	for (int i = r; i < N; i++) {
		sum = 0;
		for (int j = c; j < N; j++) {
			sum += board[i][j];
			tmp[i][j] = sum + tmp[i - 1][j];
			cnt += m[tmp[i][j]];
		}
	}
}
void CalcRightTop(int r, int c) {
	fill(tmp[0], tmp[N + 1], 0);
	for (int i = r; i >= 0; i--) {
		sum = 0;
		for (int j = c; j < N; j++) {
			sum += board[i][j];
			tmp[i][j] = sum + tmp[i + 1][j];
			m[tmp[i][j]]++;
		}
	}
}
void MatchWithLeftBottom(int r, int c) {
	fill(tmp[0], tmp[N + 1], 0);
	for (int i = r; i < N; i++) {
		sum = 0;
		for (int j = c; j >= 0; j--) {
			sum += board[i][j];
			tmp[i][j] = sum + tmp[i - 1][j];
			cnt += m[tmp[i][j]];
		}
	}
}
