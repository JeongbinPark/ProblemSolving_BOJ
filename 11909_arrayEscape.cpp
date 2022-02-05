//으아아아아
//cin.tie(NULL);
//ios_base::sync_with_stdio(false);
//이거 안붙였다고 시간초과라니!!!!
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 2000000000
using namespace std;

int N;
int board[2223][2223];
int cost[2223][2223];
priority_queue< pair<int, pair<int, int> > > pq;


int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}
	fill(&cost[0][0], &cost[N - 1][N], INF);
	cost[0][0] = 0;
	pq.push(make_pair(0, make_pair(0, 0)));

	while (!pq.empty()) {
		int curr_cost = -pq.top().first;
		int curr_r = pq.top().second.first;
		int curr_c = pq.top().second.second;
		pq.pop();

		if (cost[curr_r][curr_c] < curr_cost) continue;

		if (curr_r < N - 1) {
			int next_cost = curr_cost;
			if (board[curr_r][curr_c] <= board[curr_r + 1][curr_c]) {
				next_cost += board[curr_r + 1][curr_c] - board[curr_r][curr_c] + 1;
			}
			if (cost[curr_r + 1][curr_c] > next_cost) {
				cost[curr_r + 1][curr_c] = next_cost;
				pq.push(make_pair(-next_cost, make_pair(curr_r + 1, curr_c)));
			}
		}
		if (curr_c < N - 1) {
			int next_cost = curr_cost;
			if (board[curr_r][curr_c] <= board[curr_r][curr_c + 1]) {
				next_cost += board[curr_r][curr_c + 1] - board[curr_r][curr_c] + 1;
			}
			if (cost[curr_r][curr_c + 1] > next_cost) {
				cost[curr_r][curr_c + 1] = next_cost;
				pq.push(make_pair(-next_cost, make_pair(curr_r, curr_c + 1)));
			}
		}
	}
	cout << cost[N - 1][N - 1];
	return 0;
}