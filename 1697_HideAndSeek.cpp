#include <iostream>
#include <queue>
#include <algorithm>
#define INF 100001
using namespace std;

int N, K, curr_pos, curr_time;
int time[INF + 1];
priority_queue< pair<int, int> > pq;

int main() {
	cin >> N >> K;
	if (K <= N) {
		cout << N - K;
		return 0;
	}
	fill(time, time + INF, INF);
	time[N] = 0;
	pq.push(make_pair(0, N));
	while (!pq.empty()) {
		curr_time = -pq.top().first;
		curr_pos = pq.top().second;
		pq.pop();
		if (curr_pos < 0 || curr_pos > 100000 || curr_time > time[curr_pos]) continue;

		if (2 * curr_pos < INF && time[2 * curr_pos] > curr_time) {
			time[2 * curr_pos] = curr_time + 1;
			pq.push(make_pair(-curr_time - 1, 2 * curr_pos));
		}
		if (time[curr_pos + 1] == INF) {
			time[curr_pos + 1] = curr_time + 1;
			pq.push(make_pair(-curr_time - 1, curr_pos + 1));
		}
		if (time[curr_pos - 1] == INF) {
			time[curr_pos - 1] = curr_time + 1;
			pq.push(make_pair(-curr_time - 1, curr_pos - 1));
		}
	}
	cout << time[K];
	return 0;
}