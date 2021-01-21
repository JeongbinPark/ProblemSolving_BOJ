/*
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void move(int, int, int);

int R, C;
int cnt = 0;
vector<string> board;
bool visited[26] = { false };	//A,B,C,D

int main() {
	cin >> R >> C;

	string str;
	for (int i = 0; i < R; i++) {
		cin >> str;
		board.push_back(str);
	}

	
	visited[board.at(0)[0] - 'A'] = true;
	move(0, 0, 1);

	cout << cnt;

	return 0;
}
void move(int row, int col, int level) {
	if ((col == C - 1 || visited[board.at(row)[col + 1] - 'A']) && (row == R - 1 || visited[board.at(row + 1)[col] - 'A']) &&(col ==0 || visited[board.at(row)[col - 1] - 'A']) && (row == 0 || visited[board.at(row - 1)[col] - 'A'])) {
		cnt = max(cnt, level);
		return;
	}
	if (col < C - 1 && !visited[board.at(row)[col + 1] - 'A']) {
		visited[board.at(row)[col + 1]-'A'] = true;
		move(row, col + 1, level + 1);
		visited[board.at(row)[col + 1] - 'A'] = false;
	}
	if (row < R - 1 && !visited[board.at(row + 1)[col] - 'A']) {
		visited[board.at(row + 1)[col] - 'A'] = true;
		move(row + 1, col, level + 1);
		visited[board.at(row + 1)[col] - 'A'] = false;
	}
	if (col > 0 && !visited[board.at(row)[col - 1] - 'A']) {
		visited[board.at(row)[col - 1] - 'A'] = true;
		move(row, col - 1, level + 1);
		visited[board.at(row)[col - 1] - 'A'] = false;
	}
	if (row > 0 && !visited[board.at(row - 1)[col] - 'A']) {
		visited[board.at(row - 1)[col] - 'A'] = true;
		move(row - 1, col, level + 1);
		visited[board.at(row - 1)[col] - 'A'] = false;
	}
}
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void move(int, int, int);

int R, C;
int cnt = 0;
vector<string> board;
bool visited[26] = { false };	//A,B,C,D
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
int main() {
	cin >> R >> C;

	string str;
	for (int i = 0; i < R; i++) {
		cin >> str;
		board.push_back(str);
	}

	move(0, 0, 1);

	cout << cnt;

	return 0;
}

void move(int x, int y, int level) {
	if (x<0 || x>R - 1 || y<0 || y>C - 1) return;
	if (visited[board.at(x)[y] - 'A']) return;
	cnt = max(cnt, level);
	visited[board.at(x)[y] - 'A'] = true;
	for (int i = 0; i < 4; i++)
		move(x + dx[i], y + dy[i], level + 1);

	visited[board.at(x)[y] - 'A'] = false;
}