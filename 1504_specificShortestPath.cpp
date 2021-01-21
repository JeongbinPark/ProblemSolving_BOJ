#include <iostream>
#include <vector>
#include <algorithm>
#define INF 8000001
using namespace std;

void Dijkstra(int);

int N, E, a, b, c, v1, v2;
vector< pair<int, int> > node[801];
int dist[801];
bool visited[801];
int StoV1, StoV2, V1toN, V2toN, V1toV2;

int closest, curr_n, next_n, next_d;

int main() {
	cin >> N >> E;
	while (E--) {
		cin >> a >> b >> c;
		node[a].push_back(make_pair(b, c));
		node[b].push_back(make_pair(a, c));
	}
	cin >> v1 >> v2;

	Dijkstra(1);
	StoV1 = dist[v1];
	StoV2 = dist[v2];

	Dijkstra(v1);
	V1toN = dist[N];
	V1toV2 = dist[v2];

	Dijkstra(v2);
	V2toN = dist[N];

	if ((StoV1 == INF || V2toN == INF) && (StoV2 == INF || V1toN == INF) || V1toV2 == INF) cout << -1;
	else cout << min(StoV1 + V2toN, StoV2 + V1toN) + V1toV2;
	return 0;
}
void Dijkstra(int n) {
	fill(dist + 1, dist + N + 1, INF);
	fill(visited + 1, visited + N + 1, false);
	dist[n] = 0;
	while (true) {
		closest = INF;
		for (int i = 1; i <= N; i++) {
			if (closest > dist[i] && !visited[i]) {
				closest = dist[i];
				curr_n = i;
			}
		}
		if (closest == INF) break;

		visited[curr_n] = true;
		for (int i = 0; i < (int)node[curr_n].size(); i++) {
			next_n = node[curr_n][i].first;
			if (visited[next_n]) continue;
			next_d = dist[curr_n] + node[curr_n][i].second;
			dist[next_n] = min(dist[next_n], next_d);
		}
	}
	return;
}