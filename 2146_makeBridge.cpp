
//둘다 시간초과, 종료 조건이 문제..
/*
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#define INF 1000
using namespace std;

bool isPossible(int, int);
bool isFinished();

int N;
int board[101][101];
bool visited[101][101], visited_land[101][101];
priority_queue <pair<int, pair<int, int> > > pq;
int dr[] = { 1,0,-1,0 }, dc[] = { 0,1,0, -1 };
int curr_r = -1, curr_c = -1, curr_level, next_r, next_c;
int land_r, land_c;
int min_len = INF;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			if (board[i][j]) {
				land_r = i;
				land_c = j;
			}
		}
	}
	while (!isFinished()) {
		while (!pq.empty())pq.pop();
		memcpy(visited, visited_land, sizeof(visited_land));

		pq.push(make_pair(0, make_pair(land_r, land_c)));
		visited[land_r][land_c] = true;
		visited_land[land_r][land_c] = true;

		while (!pq.empty()) {
			curr_level = -pq.top().first;
			curr_r = pq.top().second.first;
			curr_c = pq.top().second.second;
			pq.pop();
			if (curr_level > 0 && board[curr_r][curr_c]) {
				min_len = min(min_len, curr_level - 1);
				land_r = curr_r, land_c = curr_c;
				break;
			}
			for (int i = 0; i < 4; i++) {
				next_r = curr_r + dr[i];
				next_c = curr_c + dc[i];
				if (isPossible(next_r, next_c) && !visited[next_r][next_c]) {
					visited[next_r][next_c] = true;
					if (board[next_r][next_c]) visited_land[next_r][next_c] = true;
					if (board[curr_r][curr_c] && board[next_r][next_c]) {
						pq.push(make_pair(-curr_level, make_pair(next_r, next_c)));
					}
					else {
						pq.push(make_pair(-curr_level - 1, make_pair(next_r, next_c)));
					}
				}
			}
		}
	}
	cout << min_len;
	return 0;
}
bool isPossible(int r, int c) {
	return r >= 0 && r < N && c >= 0 && c < N;
}
bool isFinished() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (!visited[i][j]) return false;
	return true;
}
*/

/*
시간 초과
visited_land를 복사해서 visited로 사용하여 land로 막힌 너머에 있는 육지는 검사를 못하여 종료 불가 => 시간초과 발생
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#define INF 1000
using namespace std;

bool isPossible(int, int);
bool isFinished();

int N;
int board[101][101];
bool visited[101][101], visited_land[101][101];
priority_queue <pair<int, pair<int, int> > > pq;
int dr[] = { 1,0,-1,0 }, dc[] = { 0,1,0, -1 };
int curr_r = -1, curr_c = -1, curr_level, next_r, next_c;
int land_r, land_c;
int min_len = INF;
bool flag;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			if (board[i][j]) {
				land_r = i;
				land_c = j;
			}
		}
	}
	while (!isFinished()) {
		while (!pq.empty())pq.pop();
		memcpy(visited, visited_land, sizeof(visited_land));

		pq.push(make_pair(0, make_pair(land_r, land_c)));
		visited[land_r][land_c] = true;
		visited_land[land_r][land_c] = true;
		flag = false;
		while (!pq.empty() && !flag) {
			curr_level = -pq.top().first;
			curr_r = pq.top().second.first;
			curr_c = pq.top().second.second;
			pq.pop();

			for (int i = 0; !flag && i < 4; i++) {
				next_r = curr_r + dr[i];
				next_c = curr_c + dc[i];
				if (isPossible(next_r, next_c) && !visited[next_r][next_c]) {
					visited[next_r][next_c] = true;
					if (board[next_r][next_c]) visited_land[next_r][next_c] = true;
					if (board[curr_r][curr_c] && board[next_r][next_c]) {
						pq.push(make_pair(-curr_level, make_pair(next_r, next_c)));
					}
					else if (curr_level > 0 && board[next_r][next_c]) {
						min_len = min(min_len, curr_level);
						land_r = next_r, land_c = next_c;
						flag = true;
					}
					else {
						pq.push(make_pair(-curr_level - 1, make_pair(next_r, next_c)));
					}
				}
			}
		}
	}
	cout << min_len;
	return 0;
}
bool isPossible(int r, int c) {
	return r >= 0 && r < N && c >= 0 && c < N;
}
bool isFinished() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (!visited[i][j] && board[i][j]) return false;
	return true;
}
*/
/*
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#define INF 1000
using namespace std;

bool isPossible(int, int);
bool isFinished();

int N, num;
bool board[101][101], tmp_board[101][101];
bool visited[102][101];
priority_queue <pair<int, pair<int, int> > > pq;
int dr[] = { 1,0,-1,0 }, dc[] = { 0,1,0, -1 };
int curr_r = -1, curr_c = -1, curr_level, next_r, next_c;
int land_r, land_c;
int min_len = INF;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> num;
			if (num) {
				board[i][j] = true;
				land_r = i;
				land_c = j;
			}
		}
	}
	while (!isFinished()) {
		while (!pq.empty()) pq.pop();
		fill(visited[0], visited[N], false);
		memcpy(tmp_board, board, sizeof(board));

		pq.push(make_pair(0, make_pair(land_r, land_c)));
		visited[land_r][land_c] = true;
		while (!pq.empty()) {
			curr_level = -pq.top().first;
			curr_r = pq.top().second.first;
			curr_c = pq.top().second.second;
			pq.pop();
			if (curr_level > 0 && board[curr_r][curr_c]) {
				min_len = min(min_len, curr_level - 1);
				land_r = curr_r, land_c = curr_c;
				break;
			}

			for (int i = 0; i < 4; i++) {
				next_r = curr_r + dr[i];
				next_c = curr_c + dc[i];
				if (isPossible(next_r, next_c) && !visited[next_r][next_c]) {
					visited[next_r][next_c] = true;
					if (board[curr_r][curr_c] && board[next_r][next_c]) {
						pq.push(make_pair(-curr_level, make_pair(next_r, next_c)));
					}
					else {
						pq.push(make_pair(-curr_level - 1, make_pair(next_r, next_c)));
					}
					if (board[next_r][next_c]) board[next_r][next_c] = false;
				}
			}
		}
	}
	cout << min_len;
	return 0;
}
bool isPossible(int r, int c) {
	return r >= 0 && r < N && c >= 0 && c < N;
}
bool isFinished() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (board[i][j]) return false;
	return true;
}
*/
/*
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#define INF 1000
using namespace std;

bool isPossible(int, int);
bool isFinished();

int N, num;
bool board[101][101], tmp_board[101][101];
bool visited[102][101];
priority_queue <pair<int, pair<int, int> > > pq;
int dr[] = { 1,0,-1,0 }, dc[] = { 0,1,0, -1 };
int curr_r = -1, curr_c = -1, curr_level, next_r, next_c;
int land_r, land_c;
int min_len = INF;
bool flag;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> num;
			if (num) {
				board[i][j] = true;
				land_r = i;
				land_c = j;
			}
		}
	}
	while (!isFinished()) {
		while (!pq.empty()) pq.pop();
		fill(visited[0], visited[N], false);
		memcpy(tmp_board, board, sizeof(board));

		pq.push(make_pair(0, make_pair(land_r, land_c)));
		visited[land_r][land_c] = true;
		flag = false;
		while (!pq.empty() && !flag) {
			curr_level = -pq.top().first;
			curr_r = pq.top().second.first;
			curr_c = pq.top().second.second;
			pq.pop();

			for (int i = 0; !flag && i < 4; i++) {
				next_r = curr_r + dr[i];
				next_c = curr_c + dc[i];
				if (isPossible(next_r, next_c) && !visited[next_r][next_c]) {
					visited[next_r][next_c] = true;
					if (board[curr_r][curr_c] && board[next_r][next_c]) {
						pq.push(make_pair(-curr_level, make_pair(next_r, next_c)));
					}
					else if (curr_level > 0 && board[next_r][next_c]) {
						min_len = min(min_len, curr_level);
						land_r = next_r, land_c = next_c;
						flag = true;
					}
					else {
						pq.push(make_pair(-curr_level - 1, make_pair(next_r, next_c)));
					}
					if (board[next_r][next_c]) board[next_r][next_c] = false;
				}
			}
		}
	}
	cout << min_len;
	return 0;
}
bool isPossible(int r, int c) {
	return r >= 0 && r < N && c >= 0 && c < N;
}
bool isFinished() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (board[i][j]) return false;
	return true;
}
*/

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

bool isPossible(int, int);
void dfs(int, int);

int N, num, curr_r, curr_c, curr_level, curr_land, next_r, next_c, min_len = 100000;
int board[101][101], cnt[101][101];
bool visited[101][101];
priority_queue <pair<int, pair<pair<int, int > , int > > > pq;
int dr[] = { 1,0,-1,0 }, dc[] = { 0,1,0, -1 };

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j] && board[i][j]) {
				num++;
				dfs(i, j);
			}
		}
	}



	while (!pq.empty()) {
		curr_level = -pq.top().first;
		curr_r = pq.top().second.first.first;
		curr_c = pq.top().second.first.second;
		curr_land = pq.top().second.second;
		pq.pop();

		for (int i = 0; i < 4; i++) {
			next_r = curr_r + dr[i];
			next_c = curr_c + dc[i];
			if (isPossible(next_r, next_c)) {
				if (!board[next_r][next_c]) {
					cnt[next_r][next_c] = curr_level + 1;
					board[next_r][next_c] = curr_land;
					pq.push(make_pair(-curr_level - 1, make_pair(make_pair(next_r, next_c), curr_land)));
				}
				else if (board[next_r][next_c] != curr_land) {
					min_len = min(min_len, cnt[next_r][next_c] + curr_level);
				}
			}
		}
	}
	cout << min_len;
	return 0;
}
bool isPossible(int r, int c) {
	return r >= 0 && r < N && c >= 0 && c < N;
}
void dfs(int r, int c) {
	if (!isPossible(r, c) || visited[r][c] || board[r][c] == 0) return;
	board[r][c] = num;
	visited[r][c] = true;
	pq.push(make_pair(0, make_pair(make_pair(r, c), num)));
	for (int i = 0; i < 4; i++)
		dfs(r + dr[i], c + dc[i]);
}
