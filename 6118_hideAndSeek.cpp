#include <iostream>
#include <vector>
#include <queue>
#define INF 20001
using namespace std;

int N, M;
int dist[200000];
vector<int> node[20000];
priority_queue< pair<int, int> > q;

int a, b, curr_d, curr_n, next_d, next_n;
int n, d, c = 1;

int main() {
	cin >> N >> M;
	
	while (M--) {
		cin >> a >> b;
		node[a - 1].push_back(b - 1);
		node[b - 1].push_back(a - 1);
	}

	fill(dist, dist + N, INF);
	dist[0] = 0;
	q.push(make_pair(0, 0));
	while (!q.empty()) {
		curr_d = -q.top().first;
		curr_n = q.top().second;

		q.pop();

		if (curr_d < dist[curr_n]) continue;

		for (int i = 0; i < (int) node[curr_n].size(); i++) {
			next_d = curr_d + 1;
			next_n = node[curr_n][i];
			if (dist[next_n] > next_d) {
				q.push(make_pair(-next_d, next_n));
				dist[next_n] = next_d;
			}
		}
	}

	for (int i = 1; i < N; i++) {
		if (dist[n] < dist[i]) {
			n = i;
			d = dist[i];
			c = 1;
		}
		else if (dist[n] == dist[i]) c++;
	}
	cout << n + 1 << " " << d << " " << c;
	return 0;
}