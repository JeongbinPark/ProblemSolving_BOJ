#include <iostream>
#include <algorithm>
#include <queue>
#define MAX 20
using namespace std;

typedef int(*boardPointer)[MAX];

void move(int cnt, int curr_board[][MAX]);
boardPointer moveLeft(int curr_board[][MAX]);
boardPointer moveRight(int curr_board[][MAX]);
boardPointer moveUp(int curr_board[][MAX]);
boardPointer moveDown(int curr_board[][MAX]);
int getMaxValue(int curr_board[][MAX]);

int N;
int board[MAX][MAX];
int maxValue;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}

	move(0, board);

	cout << maxValue;
	return 0;
}

void move(int cnt, int curr_board[][MAX]) {
	if (cnt == 5) {
		maxValue = max(maxValue, getMaxValue(curr_board));
		return;
	}
	int temp[MAX][MAX];
	//moveLeft
	copy(&curr_board[0][0], &curr_board[0][0] + MAX * MAX, &temp[0][0]);
	move(cnt + 1, moveLeft(temp));
	//moveRight
	copy(&curr_board[0][0], &curr_board[0][0] + MAX * MAX, &temp[0][0]);
	move(cnt + 1, moveRight(temp));
	//moveUp
	copy(&curr_board[0][0], &curr_board[0][0] + MAX * MAX, &temp[0][0]);
	move(cnt + 1, moveUp(temp));
	//moveDown
	copy(&curr_board[0][0], &curr_board[0][0] + MAX * MAX, &temp[0][0]);
	move(cnt + 1, moveDown(temp));

	return;
}

boardPointer moveLeft(int curr_board[][MAX]) {
	for (int i = 0; i < N; i++) {
		queue<int> row;
		for (int j = 0; j < N; j++) {
			if (curr_board[i][j]) {
				row.push(curr_board[i][j]);
			}
		}
		int col_index = 0;
		while(!row.empty()){
			int num = row.front();
			row.pop();
			if (!row.empty() && num == row.front()) {
				row.pop();
				num *= 2;
			}
			curr_board[i][col_index++] = num;
		}
		for (int j = col_index; j < N; j++) {
			curr_board[i][j] = 0;
		}
	}
	return curr_board;
}

boardPointer moveRight(int curr_board[][MAX]) {
	for (int i = 0; i < N; i++) {
		queue<int> row;
		for (int j = N - 1; j >= 0; j--) {
			if (curr_board[i][j]) {
				row.push(curr_board[i][j]);
			}
		}
		int col_index = N - 1;
		while (!row.empty()) {
			int num = row.front();
			row.pop();
			if (!row.empty() && num == row.front()) {
				row.pop();
				num *= 2;
			}
			curr_board[i][col_index--] = num;
		}
		for (int j = col_index; j >= 0; j--) {
			curr_board[i][j] = 0;
		}
	}
	return curr_board;
}

boardPointer moveUp(int curr_board[][MAX]) {
	for (int i = 0; i < N; i++) {
		queue<int> col;
		for (int j = 0; j < N; j++) {
			if (curr_board[j][i]) {
				col.push(curr_board[j][i]);
			}
		}
		int row_index = 0;
		while (!col.empty()) {
			int num = col.front();
			col.pop();
			if (!col.empty() && num == col.front()) {
				col.pop();
				num *= 2;
			}
			curr_board[row_index++][i] = num;
		}
		for (int j = row_index; j < N; j++) {
			curr_board[j][i] = 0;
		}
	}
	return curr_board;
}

boardPointer moveDown(int curr_board[][MAX]) {
	for (int i = 0; i < N; i++) {
		queue<int> col;
		for (int j = N - 1; j >= 0; j--) {
			if (curr_board[j][i]) {
				col.push(curr_board[j][i]);
			}
		}
		int row_index = N - 1;
		while (!col.empty()) {
			int num = col.front();
			col.pop();
			if (!col.empty() && num == col.front()) {
				col.pop();
				num *= 2;
			}
			curr_board[row_index--][i] = num;
		}
		for (int j = row_index; j >= 0; j--) {
			curr_board[j][i] = 0;
		}
	}
	return curr_board;
}

int getMaxValue(int curr_board[][MAX]) {
	int maxValue = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			maxValue = max(maxValue, curr_board[i][j]);
		}
	}
	return maxValue;
}