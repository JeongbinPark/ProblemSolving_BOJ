#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

bool cmp(pair<int, int> jw1, pair<int, int> jw2);

int N, K;
int M, V, C;
vector<pair<int, int> > jw;
multiset<int> bag;

int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> M >> V;
		jw.push_back(make_pair(M, V));
	}
	for (int i = 0; i < K; i++) {
		cin >> C;
		bag.insert(C);
	}
	sort(jw.begin(), jw.end(), cmp);

	int leftBags = K;
	long long maxValue = 0;
	multiset<int>::iterator it;
	for (int i = 0; i < N && leftBags > 0; i++) {
		it = bag.lower_bound(jw[i].first);
		if (it != bag.end()) {
			maxValue += jw[i].second;
			bag.erase(it);
			leftBags--;
		}
	}
	cout << maxValue;
	return 0;
}

bool cmp(pair<int, int> jw1, pair<int, int> jw2) {
	if (jw1.second == jw2.second) {
		return jw1.first < jw2.first;
	}
	return jw1.second > jw2.second;
}