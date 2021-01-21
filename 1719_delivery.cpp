#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 200001
using namespace std;

int n, m, v, w, t;
vector< pair<int, int> > node[201];
int time[201], result[201][201];
priority_queue< pair<int, pair<int, int> > > pq;
int curr_t, curr_n, curr_sn, next_t, next_n;

int main() {
	cin >> n >> m;
	while (m--) {
		cin >> v >> w >> t;
		node[v].push_back(make_pair(w, t));
		node[w].push_back(make_pair(v, t));
	}
	for (int i = 1; i <= n; i++) {
		fill(time, time + n + 1, INF);
		time[i] = 0;
		pq.push(make_pair(0, make_pair(i, i)));
		while (!pq.empty()) {
			curr_t = -pq.top().first;
			curr_n = pq.top().second.first;
			curr_sn = pq.top().second.second;
			pq.pop();
			if (time[curr_n] < curr_t) continue;
			for (int j = 0; j < (int)node[curr_n].size(); j++) {
				next_t = curr_t + node[curr_n][j].second;
				next_n = node[curr_n][j].first;
				if (next_t < time[next_n]) {
					time[next_n] = next_t;
					result[next_n][i] = curr_n;
					pq.push(make_pair(-next_t, make_pair(next_n, curr_n)));
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) cout << "- ";
			else cout << result[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}
//플로이드와샬방법인가? 여튼 다른 방법도 있더라