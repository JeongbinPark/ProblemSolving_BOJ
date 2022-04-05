#include <iostream>
#include <algorithm>
using namespace std;

void findLongest(int r1, int c1, int r2, int c2);

int N;
char board[50][50];
int result;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}


	for (int A_r = 0; A_r < N; A_r++) {
		for (int A_c = 0; A_c < N; A_c++) {
			findLongest(A_r, A_c, A_r, A_c + 1);
			findLongest(A_r, A_c, A_r + 1, A_c);
		}
	}

	cout << result;
	return 0;
}

void findLongest(int r1, int c1, int r2, int c2) {
	if (r2 >= N || c2 >= N) return;
	if (board[r1][c1] == board[r2][c2]) return;

	swap(board[r1][c1], board[r2][c2]);

	int longest = 1;
	for (int i = 0; i < N; i++) {
		int curr = 1;
		char prev = board[i][0];
		for (int j = 1; j < N; j++) {
			if (prev == board[i][j]) {
				curr++;
				longest = max(longest, curr);
			}
			else {
				prev = board[i][j];
				curr = 1;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		int curr = 1;
		char prev = board[0][i];
		for (int j = 1; j < N; j++) {
			if (prev == board[j][i]) {
				curr++;
				longest = max(longest, curr);
			}
			else {
				prev = board[j][i];
				curr = 1;
			}
		}
	}
	result = max(result, longest);

	swap(board[r1][c1], board[r2][c2]);

	return;
}