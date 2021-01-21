//사과는 먹으면 없어집니다..... 아.......
#include <iostream>
#include <map>
#include <deque>
using namespace std;

int N, K, L, a, b, time, curr_r, curr_c;
char c;
bool board[102][102], apple[102][102];
map<int, int> change;
int d, dr[] = { 0, 1, 0, -1 }, dc[] = { 1, 0, -1, 0 };
deque< pair<int, int> > deq;

int main() {
	cin >> N >> K;
	while (K--) {
		cin >> a >> b;
		apple[a][b] = true;
	}
	cin >> L;
	while (L--) {
		cin >> a >> c;
		if (c == 'D') change.insert(make_pair(a, 1));
		else change.insert(make_pair(a, -1));
	}
	board[1][1] = true;
	deq.push_front(make_pair(1, 1));
	while (true) {
		curr_r = deq.front().first;
		curr_c = deq.front().second;

		time++;
		if (curr_r + dr[d] < 1 || curr_r + dr[d] > N || curr_c + dc[d] < 1 || curr_c + dc[d] > N || board[curr_r + dr[d]][curr_c + dc[d]]) break;

		board[curr_r + dr[d]][curr_c + dc[d]] = true;
		deq.push_front(make_pair(curr_r + dr[d], curr_c + dc[d]));
		if (apple[curr_r + dr[d]][curr_c + dc[d]]) apple[curr_r + dr[d]][curr_c + dc[d]] = false;
		else {
			board[deq.back().first][deq.back().second] = false;
			deq.pop_back();
		}

		d = (4 + d + change[time]) % 4;
	}
	cout << time;
	return 0;
}