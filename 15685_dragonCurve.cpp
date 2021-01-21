#include <iostream>
#include <vector>
using namespace std;

int N, r, c, d, g, curr_r, curr_c, curr_d, cnt;
bool board[102][102];
vector<int> dir[11];
int dr[] = { 0, -1, 0, 1 }, dc[] = { 1, 0, -1, 0 };

int main() {
	cin >> N;
	dir[0].push_back(0);
	for (int i = 1; i <= 10; i++) {
		for (int j = 0; j < (int)dir[i - 1].size(); j++)
			dir[i].push_back(dir[i - 1][j]);
		for (int j = (int)dir[i - 1].size() - 1; j >= 0; j--)
			dir[i].push_back((dir[i - 1][j] + 1) % 4);
	}

	while (N--) {
		cin >> c >> r >> d >> g;
		curr_r = r, curr_c = c;
		board[r][c] = true;
		for (int i = 0; i < (int)dir[g].size(); i++) {
			curr_d = (dir[g][i] + d) % 4;
			curr_r += dr[curr_d], curr_c += dc[curr_d];
			board[curr_r][curr_c] = true;
		}
	}
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (board[i][j] && board[i + 1][j] && board[i + 1][j + 1] && board[i][j + 1]) cnt++;
		}
	}
	cout << cnt;
	return 0;
}