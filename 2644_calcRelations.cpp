#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define inf 1000
using namespace std;

int dfs(int, int);

int n, m, a, b, x, y, result = inf;
vector<int> relations[101];
bool visited[101];

int main() {
	cin >> n >> a >> b >> m;
	while (m--) {
		cin >> x >> y;
		relations[x].push_back(y);
		relations[y].push_back(x);
	}

	for (int i = 0; i < (int)relations[a].size(); i++) {
		memset(visited, false, sizeof(visited));
		visited[a] = true;
		result = min(result, dfs(relations[a][i], 1));
	}
	cout << (result == inf ? -1 : result);
	return 0;
}

int dfs(int person, int level) {
	if (visited[person]) return inf;
	if (person == b) return level;
	visited[person] = true;
	for (int nextPerson = 0; nextPerson < (int)relations[person].size(); nextPerson++) {
		int tmp = dfs(relations[person][nextPerson], level + 1);
		if (tmp != inf) return tmp;
	}
	visited[person] = false;
	return inf;
}