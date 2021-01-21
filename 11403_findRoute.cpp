/* DFS 방법
#include <iostream>
#include <vector>
using namespace std;

void find(int, int);

int N, start;
int node[100][100] = { 0 };
bool visited[100] = { false };

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> node[i][j];

	for (int i = 0; i < N; i++)
	{
		fill(visited, visited + N, false);
		start = i;
		find(i, 0);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << node[i][j] << " ";
		cout << "\n";
	}

	return 0;
}
void find(int n, int level) {
	if (visited[n]) return;
	if (level > 0) visited[n] = true;
	for(int i = 0; i < N; i++)
		if (node[n][i]) {
			node[start][i] = 1;
			find(i, level + 1);
		}
	return;
}
*/

//플로이드 와샬
#include <iostream>
using namespace std;

int node[100][100];

int main() {
	int N;
	cin >> N; 
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> node[i][j];

	for (int k = 0; k < N; k++)
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (node[i][k] && node[k][j]) node[i][j] = 1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << node[i][j] << " ";
		cout << "\n";
	}
	return 0;
}