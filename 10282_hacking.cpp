#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 10000001
using namespace std;

int T;


int main() {
	cin >> T;
	while (T--) {
		int V, E, K;
		int a, b, c;
		int max_cnt = 0, max_time = 0;
		vector< pair<int, int> > node[10001];
		int times[10001];
		priority_queue< pair<int, int> > pq;

		cin >> V >> E >> K;

		while (E--) {
			cin >> a >> b >> c;
			node[b].push_back(make_pair(a, c));
		}
		fill(times + 1, times + V + 1, INF);
		times[K] = 0;
		pq.push(make_pair(0, K));

		while (!pq.empty()) {
			int curr_cost = -pq.top().first;
			int curr_node = pq.top().second;
			pq.pop();
			
			if (times[curr_node] < curr_cost) continue;
			max_cnt++;

			for (int i = 0; i < (int)node[curr_node].size(); i++) {
				int next_cost = curr_cost + node[curr_node][i].second;
				int next_node = node[curr_node][i].first;
				if (times[next_node] > next_cost) {
					times[next_node] = next_cost;
					pq.push(make_pair(-next_cost, next_node));
				}
			}
		}
		for (int i = 1; i <= V; i++) {
			if (times[i] != INF && max_time < times[i]) max_time = times[i];
		}
		cout << max_cnt << " " << max_time << "\n";
	}
	return 0;
}