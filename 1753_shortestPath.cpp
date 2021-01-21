#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define INF 200001
using namespace std;

int V, E, K, u, v, w;
vector< pair<int, int> > node[20001];
int dist[20001];
priority_queue< pair<int, int> > pq;
bool flag;

int curr_d, curr_n, next_d, next_n ;

int main() {
	cin >> V >> E >> K;
	while (E--) {
		cin >> u >> v >> w;
		flag = true;
		for (int i = 0; i < (int)node[u].size() && flag; i++) {
			if (node[u][i].first == v) {
				node[u][i].second = min(node[u][i].second, w);
				flag = false;
			}
		}
		if (flag) node[u].push_back(make_pair(v, w));
	}

	fill(dist + 1, dist + V + 1, INF);
	dist[K] = 0;
	pq.push(make_pair(0, K));
	while (!pq.empty()) {
		curr_d = -pq.top().first;
		curr_n = pq.top().second;
		pq.pop();

		if (dist[curr_n] < curr_d) continue;

		for (int i = 0; i < (int)node[curr_n].size(); i++) {
			next_d = curr_d + node[curr_n][i].second;
			next_n = node[curr_n][i].first;
			if (next_d < dist[next_n]) {
				dist[next_n] = next_d;
				pq.push(make_pair(-next_d, next_n));
			}
		}
	}
	for (int i = 1; i <= V; i++) {
		if (dist[i] == INF) cout << "INF" << "\n";
		else cout << dist[i] << "\n";
	}

	return 0;
}