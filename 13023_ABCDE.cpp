#include <iostream>
#include <vector>
using namespace std;

bool find(int, int);

int N, M;
vector<int> friends[2000];
bool visited[2000] = { false };

int main() {
	cin >> N >> M;
	int a, b;
	while (M--) {
		cin >> a >> b;
		friends[a].push_back(b);
		friends[b].push_back(a);
	}
	for (int i = 0; i < N; i++)
	{
		if (find(i, 0)) {
			cout << 1;
			return 0;
		}
	}
	cout << 0;
	return 0;
}
bool find(int node, int level) {
	if (node >= N || level > 4 || visited[node]) return false;
	if (level == 4) return true;
	visited[node] = true;
	for (int i = 0; i < friends[node].size(); i++)
	{
		if(find(friends[node][i], level + 1)) return true; 
	}
	visited[node] = false;
	return false;
}