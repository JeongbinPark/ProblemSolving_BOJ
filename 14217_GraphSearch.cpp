////Dijkstra Algorithm
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#define INF 501
//using namespace std;
//
//int N, M, Q;
//int command, city1, city2;
//vector<int> cities[501];
//int dist[501];
//bool visited[501] = { 0 };
//
//int main() {
//	cin >> N >> M;
//	for(int i = 0; i < M; i++) {
//		cin >> city1 >> city2;
//		cities[city1].push_back(city2);
//		cities[city2].push_back(city1);
//	}
//	
//	cin >> Q; 
//	while (Q--) {
//		cin >> command >> city1 >> city2;
//
//		if (command == 1) {
//			cities[city1].push_back(city2);
//			cities[city2].push_back(city1);
//		}
//		else {
//			for (int i = 0; i < (int)cities[city1].size(); i++) {
//				if (cities[city1][i] == city2) {
//					cities[city1].erase(cities[city1].begin() + i);
//					break;
//				}
//			}
//
//			for (int i = 0; i < (int)cities[city2].size(); i++) {
//				if (cities[city2][i] == city1) {
//					cities[city2].erase(cities[city2].begin() + i);
//					break;
//				}
//			}
//		}
//
//		fill(dist + 1, dist + N + 1, INF);
//		fill(visited, visited + N + 1, 0);
//		dist[1] = 0;
//		visited[1] = true;
//
//		for (int i = 0; i < (int)cities[1].size(); i++) {
//			int next_node = cities[1][i];
//			dist[next_node] = 1;
//		}
//
//		for (int i = 0; i < N; i++) {
//			int curr_node = 0;
//			int curr_cost = INF;
//
//			for (int j = 1; j <= N; j++) {
//				if (dist[j] < curr_cost && !visited[j]) {
//					curr_node = j;
//					curr_cost = dist[j];
//				}
//			}
//
//			visited[curr_node] = true;
//
//			for (int j = 0; j < (int)cities[curr_node].size(); j++) {
//				int next_node = cities[curr_node][j];
//				int next_cost = curr_cost + 1;
//				if (dist[next_node] > next_cost) {
//					dist[next_node] = next_cost;
//				}
//			}
//		}
//
//		for (int i = 1; i <= N; i++) {
//			if (dist[i] == INF) cout << -1 << " ";
//			else cout << dist[i] << " ";
//		}
//		cout << "\n";
//	}
//	return 0;
//}

//BFS
#include <iostream>
#include <queue>
#include <cstdlib>
#define INF 501
using namespace std;

int N, M, Q;
int command, city1, city2;
bool isConnected[501][501];

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> city1 >> city2;
		isConnected[city1][city2] = true;
		isConnected[city2][city1] = true;
	}
	cin >> Q;
	while (Q--) {
		cin >> command >> city1 >> city2;
		if (command == 1) {
			isConnected[city1][city2] = true;
			isConnected[city2][city1] = true;
		} else {
			isConnected[city1][city2] = false;
			isConnected[city2][city1] = false;
		}

		bool visited[501];
		int dists[501];
		fill(visited, visited + N + 1, 0);
		fill(dists, dists + N + 1, INF);

		queue< pair<int, int> > q;
		q.push(make_pair(1, 0));
		visited[1] = true;
		dists[1] = 0;

		while (!q.empty()) {
			int currCity = q.front().first;
			int dist = q.front().second;

			q.pop();

			for (int i = 1; i <= N; i++) {
				if (isConnected[currCity][i] && !visited[i]) {
					visited[i] = true;
					dists[i] = dist + 1;
					q.push(make_pair(i, dist + 1));
				}
			}
		}
		for (int i = 1; i <= N; i++) {
			if (dists[i] == INF) cout << -1 << " ";
			else cout << dists[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}