#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool dfs(int, int);

int T, V, E, s, e;
vector<int> node[20001];
int group[20001];
bool isBipartiteGraph;

int main() {
	cin >> T;
	while (T--) {
		cin >> V >> E;
		isBipartiteGraph = false;
		fill(group, group + V + 1, 0);
		for (int i = 1; i <= V; i++) {
			node[i].clear();
		}
		while (E--) {
			cin >> s >> e;
			node[s].push_back(e);
			node[e].push_back(s);
		}
		for (int i = 1; i <= V; i++) {
			if (!group[i]) {
				isBipartiteGraph = dfs(i, 1);
				if (!isBipartiteGraph) break;
			}
		}
		if (isBipartiteGraph) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
bool dfs(int n, int g) {
	int next_g = g == 1 ? 2 : 1;

	if (group[n] == g) return true;
	else if (group[n] == next_g) return false;

	group[n] = g;

	for (int i = 0; i < (int)node[n].size(); i++) {
		if (!dfs(node[n][i], next_g)) return false;
	}
	return true;
}