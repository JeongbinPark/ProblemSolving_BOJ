#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int T, N, g1, g2, max_freshman, min_g2;
vector<pair<int, int> > v;
bool check[100001];

int main() {
	cin >> T;
	while (T--) {
		cin >> N;
		v.clear();
		fill(check, check + N, true);
		for (int i = 0; i < N; i++) {
			cin >> g1 >> g2;
			v.push_back(make_pair(g1, g2));
		}
		sort(v.begin(), v.end());
		min_g2 = v[0].second;
		max_freshman = 1;
		for (int i = 1; i < N; i++) {
			if (v[i].second < min_g2) {
				min_g2 = v[i].second;
				max_freshman++;
			}
		}
		cout << max_freshman << "\n";
	}
	return 0;
}