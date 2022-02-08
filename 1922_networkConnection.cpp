#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int find(int);
void merge(int, int);

int N, M;
int pc1, pc2, cost;
vector<pair<int, pair<int, int> > > lans;
int root[1001];
int height[1001];
int sumCost = 0;

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> pc1 >> pc2 >> cost;
		lans.push_back(make_pair(cost, make_pair(pc1, pc2)));
	}

	for (int i = 1; i <= N; i++) {
		root[i] = i;
		height[i] = 1;
	}

	sort(lans.begin(), lans.end());

	int cnt_lan = 0;
	vector<pair<int, pair<int, int> > >::iterator it;
	for (it = lans.begin(); cnt_lan < N && it != lans.end(); it++) {
		cost = (*it).first;
		pc1 = (*it).second.first;
		pc2 = (*it).second.second;

		if (find(pc1) == find(pc2)) continue;

		cnt_lan++;
		merge(pc1, pc2);
		sumCost += cost;
	}
	cout << sumCost;
	return 0;
}

int find(int node) {
	if (root[node] == node) return node;
	return root[node] = find(root[node]);
}

void merge(int node1, int node2) {
	int root1 = root[node1];
	int root2 = root[node2];

	if (root1 == root2) return;

	if (height[root1] == height[root2]) {
		root[root2] = root1;
		height[root1]++;
	}
	else {
		if (height[root1] > height[root2]) swap(root1, root2);
		root[root2] = root1;
	}
	return;
}