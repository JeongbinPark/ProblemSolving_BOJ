#include <iostream>
#include <vector>
#include <queue>
#define MAX 32001
using namespace std;

int N, M;
int A, B;
vector<int> parents[MAX];
int indegree[MAX] = { 0 };
int resultArray[MAX];

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> A >> B;
		indegree[B]++;
		parents[A].push_back(B);
	}

	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (!indegree[i]) q.push(i);
	}

	for (int i = 1; i <= N; i++) {
		int node = q.front();
		q.pop();
		cout << node << " ";
		for (vector<int>::iterator it = parents[node].begin(); it != parents[node].end(); it++) {
			if (!--indegree[*it]) q.push(*it);
		}
	}

	return 0;
}