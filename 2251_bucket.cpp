#include <iostream>
#include <queue>
#include <set>
using namespace std;

struct Water {
	int A, B, C;
};

int A, B, C;
bool visited[201][201][201];
queue<Water> q;
set<int> result;

int main() {
	cin >> A >> B >> C;
	int max_Water[3] = { A, B, C };
	visited[0][0][C] = true;
	q.push({ 0, 0, C });

	while (!q.empty()) {
		int curr_Water[3] = { q.front().A, q.front().B,  q.front().C };

		if (!curr_Water[0]) result.insert(curr_Water[2]);
		q.pop();

		for (int start = 0; start < 3; start++) {
			for (int end = 0; end < 3; end++) {
				if (start == end) continue;
				if (curr_Water[start] == 0 || curr_Water[end] == max_Water[end]) continue;

				int next_Water[3] = { curr_Water[0], curr_Water[1], curr_Water[2] };

				if (curr_Water[start] + curr_Water[end] > max_Water[end]) {
					next_Water[end] = max_Water[end];
					next_Water[start] = curr_Water[start] + curr_Water[end] - max_Water[end];
				}
				else {
					next_Water[end] = curr_Water[start] + curr_Water[end];
					next_Water[start] = 0;
				}

				if (!visited[next_Water[0]][next_Water[1]][next_Water[2]]) {
					visited[next_Water[0]][next_Water[1]][next_Water[2]] = true;
					q.push({ next_Water[0], next_Water[1], next_Water[2] });
				}
			}
		}
	}
	for (set<int>::iterator it = result.begin(); it != result.end(); it++) {
		cout << *it << " ";
	}
	return 0;
}