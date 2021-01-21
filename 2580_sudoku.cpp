#include <iostream>
using namespace std;

bool sudoku(int, int);
bool isPossible(int, int);

int board[9][9];

int main() {
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			cin >> board[i][j];

	if (sudoku(0, 0))
	{
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++)
				cout << board[i][j] << " ";
			cout << "\n";
		}
	}
	return 0;
}
bool sudoku(int row, int col) {
	while (row != 9 && board[row][col]) {
		col++;
		row += col / 9;
		col %= 9;
	}
	if (row == 9)
		return true;
	for (int i = 1; i <= 9; i++)
	{
		board[row][col] = i;
		if (isPossible(row, col) && sudoku((col + 1) / 9 + row, (col + 1) % 9)) return true;
	}
	board[row][col] = 0;
	return false;
};
bool isPossible(int row, int col) {
	for (int i = 0; i < 9; i++)
		if (i != col && board[row][i] == board[row][col])
			return false;
	for (int i = 0; i < 9; i++)
		if (i != row && board[i][col] == board[row][col])
			return false;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			if (row / 3 * 3 + i != row && col / 3 * 3 + j != col && board[row / 3 * 3 + i][col / 3 * 3 + j] == board[row][col]) 
				return false;
	}
	return true;
};