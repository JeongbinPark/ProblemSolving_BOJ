//visited를 red 좌표로만 해서 틀림.
#include <iostream>
#include <queue>
using namespace std;

struct Node{
	int time;
	int red_r, red_c;
	int blue_r, blue_c;
	Node(int time, int red_r, int red_c, int blue_r, int blue_c) 
		: time(time), red_r(red_r), red_c(red_c), blue_r(blue_r), blue_c(blue_c) {};
};

int N, M;
char board[10][10];
bool visited[10][10][10][10] = { 0 };
int red_r, red_c, blue_r, blue_c;
int d_r[4] = { 0, 1, 0, -1 };
int d_c[4] = { 1, 0, -1, 0 };

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'R') {
				red_r = i;
				red_c = j;
				board[i][j] = '.';
			} else if (board[i][j] == 'B') {
				blue_r = i;
				blue_c = j;
				board[i][j] = '.';
			}
		}
	}
	queue< Node > q;
	Node node(0, red_r, red_c, blue_r, blue_c);
	visited[red_r][red_c][blue_r][blue_c] = true;
	q.push(node);

	while (!q.empty()) {
		int curr_time = q.front().time;
		int curr_red_r = q.front().red_r;
		int curr_red_c = q.front().red_c;
		int curr_blue_r = q.front().blue_r;
		int curr_blue_c = q.front().blue_c;
		q.pop();

		if (curr_time == 10) break;

		for (int d = 0; d < 4; d++) {
			int next_time = curr_time + 1;
			int next_red_r = curr_red_r;
			int next_red_c = curr_red_c;
			int next_blue_r = curr_blue_r;
			int next_blue_c = curr_blue_c;


			bool RmeetsB, BmeetsR, RmeetsO, BmeetsO;
			RmeetsB = BmeetsR  = RmeetsO = BmeetsO = false;

			for (int i = 0; i < 10 && board[next_blue_r + d_r[d]][next_blue_c + d_c[d]] != '#'; i++) {
				next_blue_r += d_r[d];
				next_blue_c += d_c[d];
				if (next_blue_r == curr_red_r && next_blue_c == curr_red_c) BmeetsR = true;
				if (board[next_blue_r][next_blue_c] == 'O') {
					BmeetsO = true;
					break;
				}
			}
			if (BmeetsO) continue;

			if (BmeetsR) {
				next_blue_r -= d_r[d];
				next_blue_c -= d_c[d];
			}

			for (int i = 0; i < 10 && board[next_red_r + d_r[d]][next_red_c + d_c[d]] != '#'; i++) {
				next_red_r += d_r[d];
				next_red_c += d_c[d];
				if (next_red_r == curr_blue_r && next_red_c == curr_blue_c) RmeetsB = true;
				if (board[next_red_r][next_red_c] == 'O') {
					RmeetsO = true; 
					break;
				}
			}

			if (RmeetsO) {
				cout << 1;
				return 0;
			}

			if (RmeetsB) {
				next_red_r -= d_r[d];
				next_red_c -= d_c[d];
			}
			
			if (visited[next_red_r][next_red_c][next_blue_r][next_blue_c]) continue;
			visited[next_red_r][next_red_c][next_blue_r][next_blue_c] = true;
			Node tmp(next_time, next_red_r, next_red_c, next_blue_r, next_blue_c);
			q.push(tmp);
		}
	}
	cout << 0;
	return 0;
}

//이동할때 R 기준 경우의 수
//B만남 && O 만남 => 실패
//!B만남 && O 만남 => 성공
//B만남 && 벽만남 => 한칸 뒤
//!B만남 && 벽만남 => 그대로

//이동할때 B 기준
//R만남 && O 만남 => 실패
//!R만남 && O 만남 => 실패
//R만남 && 벽만남 => 한칸 뒤
//!R만남 && 벽만남 => 그대로