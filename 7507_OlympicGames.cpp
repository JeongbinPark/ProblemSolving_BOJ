#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, D, S, E;

int main() {
	cin >> N;
	for (int t = 1; t <= N; t++) {
		cin >> M;
		vector < pair<int, pair<int, int> > > times;
		for (int i = 0; i < M; i++) {
			cin >> D >> S >> E;
			times.push_back(make_pair(D, make_pair(E, S)));
		}
		sort(times.begin(), times.end());

		int cnt = 0;
		int preDate = 0, preEnd = 0;
		for (int i = 0; i < M; i++) {
			int d = times[i].first;
			int s = times[i].second.second;
			int e = times[i].second.first;

			if (preDate < d) {
				preEnd = 0;
				preDate = d;
			}

			if (preEnd <= s) {
				preEnd = e;
				cnt++;
			}
		}
		cout << "Scenario #" << t << ":\n" << cnt << "\n\n";
	}
	return 0;
}