#include <iostream>
using namespace std;

int N, L, low, high, num, len, result;
int board[101][101];
bool possible;

int main() {
	cin >> N >> L;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];

	for (int i = 0; i < N; i++) {
		num = board[i][0];
		len = 1;
		possible = true;
		for (int j = 1; possible && j < N; j++) {
			if (board[i][j] == num) len++;
			else if (board[i][j] == num + 1 && len >= L) {
				num = board[i][j];
				len = 1;
			}
			else if (board[i][j] == num - 1 && j <= N - L) {
				num = board[i][j];
				len = 0;
				for (int k = j; k < j + L; k++) {
					if (board[i][j] != board[i][k]) {
						possible = false;
						break;
					}
				}
				if(possible){
					j += L - 1;
					len = 0;
				}
			}
			else possible = false;
		}
		if(possible) result++;
	}

	for (int i = 0; i < N; i++) {
		num = board[0][i];
		len = 1;
		possible = true;
		for (int j = 1; possible && j < N; j++) {
			if (board[j][i] == num) len++;
			else if (board[j][i] == num + 1 && len >= L) {
				num = board[j][i];
				len = 1;
			}
			else if (board[j][i] == num - 1 && j <= N - L) {
				num = board[j][i];
				len = 0;
				for (int k = j; k < j + L; k++) {
					if (board[j][i] != board[k][i]) {
						possible = false;
						break;
					}
				}
				if (possible) {
					j += L - 1;
					len = 0;
				}
			}
			else possible = false;
		}
		if (possible) result++;
	}

	cout << result;
	return 0;
}