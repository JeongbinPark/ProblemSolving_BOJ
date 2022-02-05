#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector< vector <int> > orders;
int numInput[1001] = { 0 };
bool visited[1001] = { 0 };

int main() {
	cin >> N >> M;
	for (int i = 0; i <= N; i++) {
		vector<int> nexts;
		orders.push_back(nexts);
	}

	for (int i = 0; i < M; i++) {
		int numSinger;
		cin >> numSinger;

		int prev = 0, curr = 0;
		cin >> prev;
		for (int j = 1; j < numSinger; j++) {
			cin >> curr;
			numInput[curr]++;
			orders[prev].push_back(curr);
			prev = curr;
		}
	}

	queue<int> q;
	queue<int> answer;
	for (int i = 1; i <= N; i++) {
		if (!numInput[i]) {
			q.push(i);
			visited[i] = true;
		}
	}

	while (!q.empty()) {
		int node = q.front();
		answer.push(node);
		q.pop();
		for (vector<int>::iterator it = orders[node].begin(); it != orders[node].end(); it++) {
			//numInput[*it]--;
			if (!--numInput[*it]) {
				visited[*it] = true;
				q.push(*it);
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			cout << 0;
			return 0;
		}
	}

	while (!answer.empty()) {
		cout << answer.front() << "\n";
		answer.pop();
	}
	return 0;
}