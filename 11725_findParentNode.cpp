#include <iostream>
#include <vector>
using namespace std;

void dfs(int, int);

int n, a, b;
vector<int> node[100001];
int parent[100001] = { 0 };

int main() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		node[a].push_back(b);
		node[b].push_back(a);
	}

	parent[1] = -1;
	for (int i = 0; i < (int)node[1].size(); i++)
		dfs(node[1][i], 1);

	for (int i = 2; i <= n; i++)
		cout << parent[i] << "\n";

	return 0;
}

void dfs(int thisNode, int parentNode) {
	if (parent[thisNode]) return;
	parent[thisNode] = parentNode;
	for (int i = 0; i < (int)node[thisNode].size(); i++)
		dfs(node[thisNode][i], thisNode);
	return;
}