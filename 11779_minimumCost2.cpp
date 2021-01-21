#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define INF 200000000
using namespace std;

int n, m, v, w, c, n1, n2;
int cost[1002];
vector< pair<int, int> > node[1001];
vector<int> route[1001];
priority_queue< pair<int, int> > pq;
int curr_c, curr_n, next_c, next_n;

int main() {
	cin >> n >> m;
	while (m--) {
		cin >> v >> w >> c;
		node[v].push_back(make_pair(w, c));
	}
	cin >> n1 >> n2;

	fill(cost, cost + n + 1, INF);
	cost[n1] = 0;
	pq.push(make_pair(0, n1));
	while (!pq.empty()) {
		curr_c = -pq.top().first;
		curr_n = pq.top().second;
		pq.pop();
		if (cost[curr_n] < curr_c) continue;
		for (int i = 0; i < (int)node[curr_n].size(); i++) {
			next_n = node[curr_n][i].first;
			next_c = curr_c + node[curr_n][i].second;
			if (next_c < cost[next_n]) {
				cost[next_n] = next_c;
				route[next_n] = route[curr_n];
				route[next_n].push_back(curr_n);
				pq.push(make_pair(-next_c, next_n));
			}
		}
	}
	route[n2].push_back(n2);
	cout << cost[n2] << "\n" << (int)route[n2].size() << "\n";
	for (int i = 0; i < (int)route[n2].size(); i++)
		cout << route[n2][i] << " ";
	return 0;
}