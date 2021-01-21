#include <iostream>
#include <set>
#include <string>
using namespace std;

void dfs(int, int, int);
bool isPossible(int, int);

int board[5][5];
set<string> s;
int dr[] = { 0, 1, 0, -1 }, dc[] = { 1, 0, -1, 0 };
string num = "******";
char ch;

int main() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			dfs(i, j, 0);
		}
	}

	cout << s.size();
	return 0;
}
void dfs(int r, int c, int level) {
	ch = '0' + board[r][c];
	num[level] = ch;
	if (level == 5) {
		s.insert(num);
		return;
	}
	for (int d = 0; d < 4; d++) {
		if(isPossible(r+dr[d], c+dc[d])) dfs(r + dr[d], c + dc[d], level + 1);
	}
}
bool isPossible(int x, int y) {
	return x >= 0 && x < 5 && y >= 0 && y < 5;
}