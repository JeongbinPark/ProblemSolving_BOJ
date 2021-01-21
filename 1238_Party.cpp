#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1000000
using namespace std;

int N, M, X, v, w, t, result;
vector< pair<int, int> > fromX[1001], toX[1001];
int time_fromX[1001], time_toX[1001];
priority_queue< pair<int, int> > pq;
int curr_t, curr_n, next_t, next_n;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N >> M >> X;
	while (M--) {
		cin >> v >> w >> t;
		fromX[v].push_back(make_pair(w, t));
		toX[w].push_back(make_pair(v, t));
	}
	fill(time_fromX, time_fromX + N + 1, INF);
	pq.push(make_pair(0, X));
	while (!pq.empty()) {
		curr_t = -pq.top().first;
		curr_n = pq.top().second;
		pq.pop();
		if (time_fromX[curr_n] < curr_t) continue;
		for (int i = 0; i < (int) fromX[curr_n].size(); i++) {
			next_n = fromX[curr_n][i].first;
			next_t = curr_t + fromX[curr_n][i].second;
			if (next_t < time_fromX[next_n]) {
				time_fromX[next_n] = next_t;
				pq.push(make_pair(-next_t, next_n));
			}
		}
	}
	fill(time_toX, time_toX + N + 1, INF);
	pq.push(make_pair(0, X));
	while (!pq.empty()) {
		curr_t = -pq.top().first;
		curr_n = pq.top().second;
		pq.pop();
		if (time_toX[curr_n] < curr_t) continue;
		for (int i = 0; i < (int) toX[curr_n].size(); i++) {
			next_n = toX[curr_n][i].first;
			next_t = curr_t + toX[curr_n][i].second;
			if (next_t < time_toX[next_n]) {
				time_toX[next_n] = next_t;
				pq.push(make_pair(-next_t, next_n));
			}
		}
	}
	for (int i = 1; i <= N; i++)
		if(i != X) result = max(result, time_fromX[i] + time_toX[i]);
	cout << result;
	return 0;
}