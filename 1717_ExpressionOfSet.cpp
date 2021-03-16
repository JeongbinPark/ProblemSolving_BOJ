#include <iostream>
#include <vector>
using namespace std;
int find(int);
void merge(int, int);

int n, m;
int op, a, b;
vector<int> root, height;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 0; i <= n; i++) {
		root.push_back(i);
		height.push_back(1);
	}

	for (int i = 0; i < m; i++) {
		cin >> op >> a >> b;
		if (op) {
			if (find(a) == find(b)) cout << "YES\n";
			else cout << "NO\n";
		}
		else merge(a, b);
	}
	return 0;
}

int find(int node) {
	if (node == root[node]) return node;
	return root[node] = find(root[node]);
}

void merge(int node1, int node2) {
	node1 = find(node1);
	node2 = find(node2);

	if (node1 == node2) return;

	if (height[node1] == height[node2]) {
		root[node2] = node1;
		height[node1]++;
	}
	else if (height[node1] > height[node2]) {
		root[node2] = node1;
	}
	else {
		root[node1] = node2;
	}
}