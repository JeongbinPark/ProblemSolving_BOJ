#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int find(int);
void merge(int, int);

int N, M;
int city1, city2, fee;
vector<pair<int, pair<int, int> > > load;
int root[100001];
int height[100001];
int result = 0;

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> city1 >> city2 >> fee;
		load.push_back(make_pair(fee, make_pair(city1, city2)));
	}
	for (int i = 1; i <= N; i++) {
		root[i] = i;
		height[i] = 1;
	}

	sort(load.begin(), load.end());

	int load_cnt = 0;
	vector<pair<int, pair<int, int> > >::iterator it;
	for (it = load.begin(); load_cnt < N - 2 && it != load.end(); it++) {
		fee = (*it).first;
		city1 = (*it).second.first;
		city2 = (*it).second.second;

		if (find(city1) == find(city2)) continue;

		merge(city1, city2);
		load_cnt++;
		result += fee;
	}
	cout << result;
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
	} else {
		if (height[root1] > height[root2]) swap(root1, root2);
		root[root2] = root1;
	}
	return;
}