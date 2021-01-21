#include <iostream>
#include <algorithm>
using namespace std;

void star(int, int, int);

int N;
char board[3073][6146];
int triangle[][2] = { 0,0,1,-1,1,1,2,-2,2,-1,2,0,2,1,2,2 };

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		fill(board[i], board[i] + 2 * N, ' ');
	star(0, N - 1, N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N*2; j++)
			cout << board[i][j];
		cout << "\n";
	}
	return 0;
}
void star(int a, int b, int level) {
	if (level == 3) {
		for (int i = 0; i < 8; i++)
			board[a + triangle[i][0]][b + triangle[i][1]] = '*';
		return;
	}
	int next_level = level / 2;
	star(a, b, next_level);
	star(a + next_level, b - next_level, next_level);
	star(a + next_level, b + next_level, next_level);
	return;
}