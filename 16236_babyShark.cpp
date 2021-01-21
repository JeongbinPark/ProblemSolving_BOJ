/* 위쪽, 왼쪽 우선순위 보장 X
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstdlib>
using namespace std;

bool isPossible(int, int);

int N, r, c, curr_r, curr_c, s = 2, time, ate;
int board[20][20];
bool visited[21][20];
queue< pair<int, int> > q;
int dr[] = { -1, 0, 0, 1 }, dc[] = { 0, -1, 1, 0 };

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			if (board[i][j] == 9) {
				r = curr_r = i, c = curr_c = j;
				board[i][j] = 0;
			}
		}
	q.push(make_pair(r, c));
	visited[r][c] = true;
	while (!q.empty()) {
		r = q.front().first;
		c = q.front().second;
		q.pop();

		if (board[r][c] != 0 && board[r][c] < s) {
			ate++;
			board[r][c] = 0;
			time += abs(curr_r - r) + abs(curr_c - c);
			curr_r = r, curr_c = c;
			fill(visited[0], visited[21], false);
			while (!q.empty()) q.pop();
			q.push(make_pair(r, c));
			visited[r][c] = true;
		}
		if (ate == s) {
			ate = 0;
			s++;
		}

		for (int i = 0; i < 4; i++) {
			if (isPossible(r + dr[i], c + dc[i]) && !visited[r + dr[i]][c + dc[i]] && board[r + dr[i]][c + dc[i]] <= s) {
				visited[r + dr[i]][c + dc[i]] = true;
				q.push(make_pair(r + dr[i], c + dc[i]));
			}
		}
	}
	cout << time;
	return 0;
}
bool isPossible(int a, int b) {
	return a >= 0 && a < N && b >= 0 && b < N;
}
*/

#include <iostream>
#include <queue>
#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;

bool isPossible(int, int);

int N, r, c, t, curr_r, curr_c, curr_t, s = 2, time, ate;
int board[20][20];
bool visited[21][20];
priority_queue< pair<int, pair<int, int> > > pq;
int dr[] = { -1, 0, 1, 0 }, dc[] = { 0, -1, 0, 1 };
bool found;
vector< pair<int, int> > v;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			if (board[i][j] == 9) {
				r = curr_r = i, c = curr_c = j;
				board[i][j] = 0;
			}
		}
	pq.push(make_pair(0, make_pair(r, c)));
	visited[r][c] = true;
	while (!pq.empty()) {
		t = -pq.top().first;
		r = pq.top().second.first;
		c = pq.top().second.second;
		pq.pop();
		
		if (curr_t < t){
			if (!found) curr_t++;
			else {
				ate++;
				if (ate == s) ate = 0, s++;
				sort(v.begin(), v.end());
				time += t;
				curr_r = v[0].first, curr_c = v[0].second;
				board[curr_r][curr_c] = 0;

				fill(visited[0], visited[21], false);
				v.clear();
				found = false;
				curr_t = 0;
				while (!pq.empty()) pq.pop();
				pq.push(make_pair(0, make_pair(curr_r, curr_c)));
				visited[curr_r][curr_c] = true;
				continue;
			}
		}
		
		for (int i = 0; i < 4; i++) {
			if (isPossible(r + dr[i], c + dc[i]) && !visited[r + dr[i]][c + dc[i]] && board[r + dr[i]][c + dc[i]] <= s) {
				visited[r + dr[i]][c + dc[i]] = true;
				if (board[r + dr[i]][c + dc[i]] != 0 && board[r + dr[i]][c + dc[i]] < s) {
					v.push_back(make_pair(r + dr[i], c + dc[i]));
					found = true;
				}
				pq.push(make_pair(-t - 1, make_pair(r + dr[i], c + dc[i])));
			}
		}
	}
	cout << time;
	return 0;
}
bool isPossible(int a, int b) {
	return a >= 0 && a < N && b >= 0 && b < N;
}

//bfs내에서 queue clear하고 초기값 넣고 continue하는 방법 말고
//while문 내에 bfs를 두는 방법도 있음