//자식 노드가 하나이고, 자식 노드가 삭제될 때, 부모노드가 리프노드가 됨.
#include <iostream>
#include <vector>
using namespace std;

int dfs(int);

int n, parent, root;
int deleteNode;
vector<int> children[50];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> parent;
		if (parent == -1) root = i;
		else children[parent].push_back(i);
	}
	cin >> deleteNode;
	cout << dfs(root);
}

int dfs(int parent) {
	if (parent == deleteNode) return 0;
	if ((int)children[parent].size() == 0) return 1;
	if ((int)children[parent].size() == 1 && children[parent][0] == deleteNode) return 1;
	int num_children = 0;
	vector<int>::iterator it;
	for (it = children[parent].begin(); it != children[parent].end(); it++) {
		num_children += dfs(*it);
	}
	return num_children;
}