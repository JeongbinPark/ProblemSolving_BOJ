#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, s, e, cnt, time;
vector<pair<int, int> > v;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s >> e;
		v.push_back(make_pair(e, s));
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < N; i++) {
		if (time <= v[i].second) {
			cnt++;
			time = v[i].first;
		}
	}
	cout << cnt;
	return 0;
}