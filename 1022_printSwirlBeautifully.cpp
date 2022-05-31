//배열 범위 조심
#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

void drawBoard();
bool isInBoard(int, int);

int board[50][5];
int r1, c1, r2, c2, maxAbsCoor;
int dr[] = { 0, -1, 0, 1 }, dc[] = { 1, 0, -1, 0 };

int main() {
	cin >> r1 >> c1 >> r2 >> c2;
	
	maxAbsCoor = max(
		max(abs(r1), abs(c1)), 
		max(abs(r2), abs(c2))
	);

	drawBoard();

	int maxValue = max(
		max(board[0][0], board[0][c2 - c1]),
		max(board[r2 - r1][0], board[r2 - r1][c2 - c1])
	);
	int maxLength = 0;
	while (maxValue) {
		maxLength++;
		maxValue /= 10;
	}

	for (int r = 0; r <= r2 - r1; r++) {
		for (int c = 0; c <= c2 - c1; c++) {
			cout.width(maxLength);
			cout.fill(' ');
			cout << board[r][c] << " ";
		}
		cout << "\n";
	}

	return 0;
}

void drawBoard() {
	int maxValue = (maxAbsCoor * 2 + 1) * (maxAbsCoor * 2 + 1);
	int currValue = 1;
	int currR = 0, currC = 0;
	int currDir = 0;
	bool sameMoveSize = true;
	int moveSize = 0;

	if (isInBoard(currR, currC)) {
		board[currR - r1][currC - c1] = currValue;
	}

	while (true) {
		if (sameMoveSize) {
			moveSize++;
		}
		for (int i = 0; i < moveSize; i++) {
			currR += dr[currDir];
			currC += dc[currDir];
			currValue++;
			if (currValue > maxValue) return;
			if (isInBoard(currR, currC)) {
				board[currR - r1][currC - c1] = currValue;
			}
		}
		sameMoveSize = !sameMoveSize;
		currDir = (currDir + 1) % 4;
	}

	return;
}

bool isInBoard(int r, int c) {
	return r >= r1 && r <= r2 && c >= c1 && c <= c2 ;
}
