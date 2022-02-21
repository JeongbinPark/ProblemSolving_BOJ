#include <iostream>
#include <queue>
using namespace std;

int N, M;
int a, b;
int tp[101];
bool visited[101];
priority_queue<pair<int, int> > pq;

int main() {
	cin >> N >> M;
	for (int i = 0; i < N + M; i++) {
		cin >> a >> b;
		tp[a] = b;
	}

	visited[1] = true;
	pq.push(make_pair(0, 1));

	while (!pq.empty()) {
		int times = -pq.top().first;
		int curr = pq.top().second;
		if (curr == 100) {
			cout << times;
			return 0;
		}
		pq.pop();

		for (int dice = 1; dice <= 6; dice++) {
			int next = curr + dice;
			if (tp[next]) next = tp[next];
			if (next <= 100 && !visited[next]) {
				visited[next] = true;
				pq.push(make_pair(-(times + 1), next));
			}
		}
	}
	return 0;
}