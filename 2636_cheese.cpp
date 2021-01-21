#include <iostream>
#include <queue>
using namespace std;

bool isPossible(int a, int b);

int h, w, r, c, t, next_r, next_c, curr_t, pre_leftCheese, leftCheese;
int cheese[101][101];
bool visited[101][101];
int dr[] = { 1, 0, -1, 0 }, dc[] = { 0, 1, 0, -1 };
priority_queue<pair<int, pair<int, int> > > q;

int main() {
	cin >> h >> w;
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++) {
			cin >> cheese[i][j];
			if (cheese[i][j]) leftCheese++;
		}
	pre_leftCheese = leftCheese;
	q.push(make_pair(0, make_pair(0, 0)));
	visited[0][0] = true;
	while (!q.empty()) {
		t = -q.top().first;
		r = q.top().second.first;
		c = q.top().second.second;
		q.pop();

		if (t > curr_t) {
			curr_t = t;
			if(leftCheese != 0) pre_leftCheese = leftCheese;
		}

		for (int i = 0; i < 4; i++) {
			next_r = r + dr[i];
			next_c = c + dc[i];
			if (isPossible(next_r, next_c) && !visited[next_r][next_c]) {
				visited[next_r][next_c] = true;
				if (cheese[next_r][next_c]) {
					cheese[next_r][next_c] = 0;
					leftCheese--;
					q.push(make_pair(-t - 1, make_pair(next_r, next_c)));
				}
				else
					q.push(make_pair(-t , make_pair(next_r, next_c)));
			}
		}
	}
	cout << curr_t << "\n" << pre_leftCheese;
	return 0;
}
bool isPossible(int a, int b) {
	return a >= 0 && a < h && b >= 0 && b < w;
}