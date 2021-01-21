#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define INF 100000001
using namespace std;

int N, M, v, w, c, n1, n2;
int cost[1001];
vector< pair<int, int> > node[1001];
priority_queue< pair<int, int> > pq;
int curr_c, curr_n, next_c, next_n;

int main() {
	cin >> N >> M;
	while (M--) {
		cin >> v >> w >> c;
		node[v].push_back(make_pair(w, c));
	}
	cin >> n1 >> n2;

	fill(cost + 1, cost + N + 1, INF);
	cost[n1] = 0;
	pq.push(make_pair(0, n1));
	while (!pq.empty()) {
		curr_c = -pq.top().first;
		curr_n = pq.top().second;
		pq.pop();
		if (cost[curr_n]<curr_c) continue;

		for (int i = 0; i < (int)node[curr_n].size(); i++) {
			next_c = curr_c + node[curr_n][i].second;
			next_n = node[curr_n][i].first;
			if (cost[next_n]>next_c) {
				cost[next_n] = next_c;
				pq.push(make_pair(-next_c, next_n));
			}
		}
	}
	cout << cost[n2];
	return 0;
}