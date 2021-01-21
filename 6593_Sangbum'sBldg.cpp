#include <iostream>
#include <queue>
#include <algorithm>
#define INF 100000
using namespace std;

bool isPossible(int, int, int);

int L, R, C, s_l, s_r, s_c, e_l, e_r, e_c;
char ch;
char building[32][32][32];
int time[33][32][32];
priority_queue< pair<int, pair<int, pair<int, int> > > > pq;

int curr_t, curr_l, curr_r, curr_c, next_l, next_r, next_c;
int dl[] = { 0, 0, 0, 0, 1, -1 }, dr[] = { 1, 0, -1, 0, 0, 0 }, dc[] = { 0, 1, 0, -1, 0, 0 };

int main() {
	while (true) {
		cin >> L >> R >> C;
		if (!L && !R && !C) break;

		for (int i = 1; i <= L; i++) {
			for (int j = 1; j <= R; j++) {
				for (int k = 1; k <= C; k++) {
					cin >> ch;
					building[i][j][k] = ch;
					if (building[i][j][k] == 'S') {
						s_l = i, s_r = j, s_c = k;
					}
					else if (building[i][j][k] == 'E') {
						e_l = i, e_r = j, e_c = k;
					}
				}
			}
		}

		fill(time[0][0], time[L + 2][0], INF);
		time[s_l][s_r][s_c] = 0;
		pq.push(make_pair(0, make_pair(s_l, make_pair(s_r, s_c))));
		while (!pq.empty()) {
			curr_t = -pq.top().first;
			curr_l = pq.top().second.first;
			curr_r = pq.top().second.second.first;
			curr_c = pq.top().second.second.second;
			pq.pop();

			if (time[curr_l][curr_r][curr_c] < curr_t) continue;

			for (int i = 0; i < 6; i++) {
				next_l = curr_l + dl[i];
				next_r = curr_r + dr[i];
				next_c = curr_c + dc[i];
				if (isPossible(next_l, next_r, next_c) && building[next_l][next_r][next_c] != '#' && curr_t + 1 < time[next_l][next_r][next_c]) {
					time[next_l][next_r][next_c] = curr_t + 1;
					pq.push(make_pair(-(curr_t + 1), make_pair(next_l, make_pair(next_r, next_c))));
				}
			}
		}

		if (time[e_l][e_r][e_c] == INF) cout << "Trapped!" << "\n";
		else cout << "Escaped in " << time[e_l][e_r][e_c] << " minute(s).\n";
	}
	return 0;
}

bool isPossible(int l, int r, int c) {
	return l > 0 && l <= L && r > 0 && r <= R && c > 0 && c <= C;
}