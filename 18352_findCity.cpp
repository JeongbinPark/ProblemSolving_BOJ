#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#define INF 1000000
using namespace std;

int N, M, K, X;
int A, B;
vector<int> path[300001];
int shortest[300002];

int main() {
	cin >> N >> M >> K >> X;
	for (int i = 0; i < M; i++) {
		cin >> A >> B;
		path[A].push_back(B);
	}

	fill(shortest, shortest + N + 1, INF);

	queue< pair<int, int> > q;
	shortest[X] = 0;
	q.push(make_pair(X, 0));

	while (!q.empty()) {
		int curr_node = q.front().first;
		int curr_dist = q.front().second;
		q.pop();

		for (vector<int>::iterator it = path[curr_node].begin(); it != path[curr_node].end(); it++) {
			if (shortest[*it] == INF) {
				shortest[*it] = curr_dist + 1;
				q.push(make_pair(*it, curr_dist + 1));
			}
		}
	}
	bool isExist = false;
	for (int i = 1; i <= N; i++) {
		if (shortest[i] == K) {
			isExist = true;
			cout << i << "\n";
		}
	}
	if (!isExist) cout << -1;
	return 0;
}