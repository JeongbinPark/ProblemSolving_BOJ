#include <iostream>
using namespace std;

bool setNum(int, int);

int board[9][9];
bool existInRow[9][10];	//rowIndex, value
bool existInCol[9][10];	//colIndex, value
bool existInBox[9][10];	//boxIndex, value

int main() {
	for (int r = 0; r < 9; r++) {
		for (int c = 0; c < 9; c++) {
			char num;
			int val;
			int boxIdx = (c / 3) * 3 + r / 3;

			cin >> num;
			val = num - '0';
			board[r][c] = val;
			existInRow[r][val] = true;
			existInCol[c][val] = true;
			existInBox[boxIdx][val] = true;
		}
	}
	if (setNum(0, 0)) {
		for (int r = 0; r < 9; r++) {
			for (int c = 0; c < 9; c++) {
				cout << board[r][c];
			}
			cout << "\n";
		}
	}
	return 0;
}

bool setNum(int row, int col) {
	while (row != 9 && board[row][col]) {
		col++;
		if (col == 9) {
			row++;
			col = 0;
		}
	}
	if (row == 9) 
		return true;
	int boxIdx = (col / 3) * 3 + row / 3;
 	for (int v = 1; v <= 9; v++) {
		board[row][col] = v;
		if (!existInRow[row][v] && !existInCol[col][v] && !existInBox[boxIdx][v]) {
			existInRow[row][v] = existInCol[col][v] = existInBox[boxIdx][v] = true;
			if (setNum(row, col)) 
				return true;
			existInRow[row][v] = existInCol[col][v] = existInBox[boxIdx][v] = false;
		}
	}
	board[row][col] = 0;
	return false;
}