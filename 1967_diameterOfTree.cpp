#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void dfs(int node);

int N, p, c, e;
int nodes[10001];
vector<int> children[10001], edges[10001];
int maxDiameter;

int main() {
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		cin >> p >> c >> e;
		children[p].push_back(c);
		edges[p].push_back(e);
	}

	dfs(1);

	cout << maxDiameter;
	return 0;
}

void dfs(int node){
	int childrenSize = (int)children[node].size();
	if (!childrenSize) return;

	for (int i = 0; i < childrenSize; i++) {
		dfs(children[node][i]);
	}
	
	int maxChildIndex1 = 0, maxChildIndex2 = -1;
	int maxChildDiameter = nodes[children[node][0]] + edges[node][0];
	if (childrenSize > 1) {
		maxChildIndex2 = 1;
		if (nodes[children[node][0]] + edges[node][0] < nodes[children[node][1]] + edges[node][1]) {
			swap(maxChildIndex1, maxChildIndex2);
			maxChildDiameter = nodes[children[node][1]] + edges[node][1];
		}
	}

	for (int i = 2; i < childrenSize; i++) {
		int childDiameter = nodes[children[node][i]] + edges[node][i];
		if (childDiameter >= maxChildDiameter) {
			maxChildDiameter = childDiameter;
			maxChildIndex2 = maxChildIndex1;
			maxChildIndex1 = i;
		}
	}

	int diameter1 = nodes[children[node][maxChildIndex1]] + edges[node][maxChildIndex1];
	int diameter2 = maxChildIndex2 == -1 ? 0 : nodes[children[node][maxChildIndex2]] + edges[node][maxChildIndex2];
	maxDiameter = max(maxDiameter, diameter1 + diameter2);
	nodes[node] = max(diameter1, diameter2);
	return;
}