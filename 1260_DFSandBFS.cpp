#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

void dfs(int);
void bfs(int);

int N;
int visited[1001];
vector<int> vec[1001];

int main() {
	int M, V;
	cin >> N >> M >> V;

	int m1, m2;
	for (int i = 0; i < M; i++)
	{
		cin >> m1 >> m2;
		vec[m1].push_back(m2);
		vec[m2].push_back(m1);
	}
	for (int i = 1; i <= N; i++)
		for (int j = 0; j < vec[i].size(); j++)
			sort(vec[i].begin(), vec[i].end());

	dfs(V);
	bfs(V);
	
	return 0;
}
void dfs(int v) {
	stack<int> s;
	bool flag;

	fill(visited, visited + N + 1 , 0);
	visited[v] = 1;
	s.push(v);
	cout << v << " ";
	while (!s.empty()) {
		v = s.top();
		flag = false;
		for (int i = 0; i < vec[v].size(); i++)
			if (!visited[vec[v][i]]) {
				s.push(vec[v][i]);
				visited[vec[v][i]] = 1;
				cout << vec[v][i] << " ";
				flag = true;
				break;
			}
		if (!flag)
			s.pop();
	}
	cout << "\n";
}
void bfs(int v) {
	queue<int> q;

	fill(visited, visited + N + 1, 0);
	visited[v] = 1;
	q.push(v);
	while (!q.empty()) {
		v = q.front();
		q.pop();
		cout << v << " ";
		for (int i = 0; i < vec[v].size(); i++)
			if (!visited[vec[v][i]]) {
				q.push(vec[v][i]);
				visited[vec[v][i]] = 1;
			}
	}
	cout << "\n";
}