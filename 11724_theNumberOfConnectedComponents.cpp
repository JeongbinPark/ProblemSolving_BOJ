#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> node[1000];
bool visited[1000] = { false };
int sum = 0;

bool find(int);

int main() {
	cin >> N >> M;
	int a, b;
	while (M--) {
		cin >> a >> b;
		node[a-1].push_back(b-1);
		node[b-1].push_back(a-1);
	}
	for (int i = 0; i < N; i++)
	{
		if (!visited[i] && find(i)) sum++;
	}
	cout << sum;
	return 0;
}

bool find(int n) {
	if (visited[n]) return false;
	visited[n] = true;
	for (int i = 0; i < node[n].size(); i++)
	{
		find(node[n][i]);
	}
	return true;
}