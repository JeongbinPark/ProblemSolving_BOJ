#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

void select(int, int);
bool check1();
bool check2();
bool isPossible(int, int);

char c, board[5][5];
int cnt, selected[7];
queue< pair<int, int> > q;
int dr[] = { 1, 0, -1, 0 }, dc[] = { 0, 1, 0, -1 };

int main() {
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++) {
			cin >> c;
			board[i][j] = c;
		}
	select(0, 0);
	cout << cnt;
	return 0;
}

void select(int n, int level) {
	if (level == 7) {
		if (check1() && check2()) cnt++;
		return;
	}
	for (int i = n; i < level + 19; i++) {
		selected[level] = i;
		select(i + 1, level + 1);
	}
	return;
}
bool check1() {
	int y = 0;
	for (int i = 0; i < 7; i++) {
		if (board[selected[i] / 5][selected[i] % 5] == 'Y') y++;
	}
	if (y > 3) return false;
	return true;
}
bool check2() {
	bool check_board[6][5] = { false }, visited[6][5] = { false };
	for (int i = 0; i < 7; i++) {
		check_board[selected[i] / 5][selected[i] % 5] = true;
	}
	int adjoined_cnt = 1;

	q.push(make_pair(selected[0] / 5, selected[0] % 5));
	visited[selected[0] / 5][selected[0] % 5] = true;
	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			if (isPossible(r + dr[i], c + dc[i]) && !visited[r + dr[i]][c + dc[i]] && check_board[r + dr[i]][c + dc[i]]) {
				visited[r + dr[i]][c + dc[i]] = true;
				adjoined_cnt++;
				q.push(make_pair(r + dr[i], c + dc[i]));
			}
		}
	}

	return adjoined_cnt == 7 ? true : false;
}
bool isPossible(int r, int c) {
	return r >= 0 && r < 5 && c >= 0 && c < 5;
}


/*
queue로 bfs말고 거리차이가 1나는 것을 재귀로 카운트 하는 방법도 있음
void chker(int x)
{
	int i;
	chk[x]=1;
	p++;
	for(i=0 ; i<7 ; i++)
	{
		if(chk[i]==0 && (ABS(ans[x].x-ans[i].x)+ABS(ans[x].y-ans[i].y))==1)
			chker(i);
	}
}

*/