#include <iostream>
using namespace std;

void checkArray(int, int, int);

int N;
char c;
bool board[64][64];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> c;
			board[i][j] = c == '1' ? true : false;
		}
	}

	checkArray(0, 0, N);
	return 0;
}

void checkArray(int row, int col, int gap) {
	if (gap == 0) return;
	bool first = board[row][col];
	bool same = true;

	for (int r = row; same && r < row + gap; r++) {
		for (int c = col; c < col + gap; c++) {
			if (board[r][c] != first) {
				same = false;
				break;
			}
		}
	}
	if (same) cout << (first ? "1" : "0");
	else {
		cout << "(";
		int newGap = gap / 2;
		checkArray(row, col, newGap);
		checkArray(row, col + newGap, newGap);
		checkArray(row + newGap, col, newGap);
		checkArray(row + newGap, col + newGap, newGap);
		cout << ")";
	}
	return;
}