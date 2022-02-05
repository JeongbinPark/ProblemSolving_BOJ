#include <iostream>
#include <queue>
using namespace std;

bool isPossible(int, int);
void w_move();
void S_move();

int R, C;
int D_r, D_c;
char map[50][50];
int d_r[4] = { 1, 0, -1, 0 };
int d_c[4] = { 0, 1, 0, -1 };
priority_queue< pair<int, pair<int, int > > > S_pq;
priority_queue< pair<int, pair<int, int > > > w_pq;
bool w_exists = false;
int curr_time = 0;
int result_time = 0;

int main() {
	cin >> R >> C;

	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			cin >> map[r][c];
			if (map[r][c] == 'S') {
				S_pq.push(make_pair(0, make_pair(r, c)));
			}
			else if (map[r][c] == '*') {
				w_pq.push(make_pair(0, make_pair(r, c)));
				w_exists = true;
			}
			else if (map[r][c] == 'D') {
				D_r = r;
				D_c = c;
			}
		}
	}

	if (w_exists) {
		w_move();
	} else {
		S_move();
	}

	if (result_time) {
		cout << result_time;
	} else {
		cout << "KAKTUS";
	}
	
	return 0;
}

bool isPossible(int r, int c) {
	return r >= 0 && r < R && c >= 0 && c < C;
}

void w_move() {
	while (!w_pq.empty()) {
		int w_curr_time = -w_pq.top().first;
		int w_curr_r = w_pq.top().second.first;
		int w_curr_c = w_pq.top().second.second;
		w_pq.pop();

		if (w_curr_time > curr_time) {
			S_move();
			curr_time++;
		}
		for (int d = 0; d < 4; d++) {
			int w_next_time = w_curr_time + 1;
			int w_next_r = w_curr_r + d_r[d];
			int w_next_c = w_curr_c + d_c[d];

			if (isPossible(w_next_r, w_next_c) && (map[w_next_r][w_next_c] == '.' || map[w_next_r][w_next_c] == 'S')) {
				map[w_next_r][w_next_c] = '*';
				w_pq.push(make_pair(-w_next_time, make_pair(w_next_r, w_next_c)));
			}
		}
	}
	w_exists = false;
	S_move();
	return;
}

void S_move() {
	while (!S_pq.empty()) {
		int S_curr_time = -S_pq.top().first;
		int S_curr_r = S_pq.top().second.first;
		int S_curr_c = S_pq.top().second.second;

		if (S_curr_r == D_r && S_curr_c == D_c) {
			result_time = S_curr_time;
			return;
		}
		if (w_exists && S_curr_time > curr_time) 
			return;

		S_pq.pop();

		for (int d = 0; d < 4; d++) {
			int S_next_time = S_curr_time + 1;
			int S_next_r = S_curr_r + d_r[d];
			int S_next_c = S_curr_c + d_c[d];

			if (isPossible(S_next_r, S_next_c) && (map[S_next_r][S_next_c] == '.' || map[S_next_r][S_next_c] == 'D')) {
				map[S_next_r][S_next_c] = 'S';
				S_pq.push(make_pair(-S_next_time, make_pair(S_next_r, S_next_c)));
			}
		}
	}
	return;
}

