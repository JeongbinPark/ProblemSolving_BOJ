#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, s, e;
priority_queue<pair<int, int> > times;
priority_queue<int> endTimes;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s >> e;
		times.push(make_pair(-s, -e));
	}

	endTimes.push(0);

	while (!times.empty()) {
		int time_s = -times.top().first;
		int time_e = -times.top().second;

		times.pop();

		int currEndTime = -endTimes.top();
		if (time_s >= currEndTime) {
			endTimes.pop();
		} 
		endTimes.push(-time_e);
	}
	cout << (int) endTimes.size();

	return 0;
}