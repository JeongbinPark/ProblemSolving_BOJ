#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int find(int);
void merge(int, int);

int n, m, isConnected, city;
vector<int> parent, cnt;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 0; i <= n; i++) {
		parent.push_back(i);
		cnt.push_back(1);
		
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> isConnected;
			if (isConnected) merge(i, j);
		}
	}

	cin >> city;
	int root = find(city);
	for (int i = 1; i < m; i++) {
		cin >> city;
		if (root != find(city)) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}

int find(int x) {
	if (x == parent[x]) return x;
	return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);

	if (x == y) return;
	if (cnt[x] < cnt[y]) swap(x, y);
	parent[y] = x;
	cnt[x] += cnt[y];
	return;
}