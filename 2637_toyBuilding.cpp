#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
int X, Y, K;
int indegree[101] = { 0 };
vector<int> parents[101];
vector< pair<int, int> > parts[101];
bool isBasic[101] = { 0 };
int result[101][101] = { 0 };

int main() {
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		cin >> X >> Y >> K;
		indegree[X]++;
		parents[Y].push_back(X);
		parts[X].push_back(make_pair(Y, K));
	}

	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (!indegree[i]) {
			q.push(i);
			isBasic[i] = true;
		}
	}

	for (int i = 1; i <= N; i++) {
		int curr_idx = q.front();
		q.pop();

		for (vector< pair<int, int> >::iterator it = parts[curr_idx].begin(); it != parts[curr_idx].end(); it++) {
			int idx = (*it).first;
			int times = (*it).second;

			if (isBasic[idx]) result[curr_idx][idx] += times;
			else {
				for (int j = 1; j < N; j++) {
					result[curr_idx][j] += times * result[idx][j];
				}
			}
		}

		for (vector<int>::iterator it = parents[curr_idx].begin(); it != parents[curr_idx].end(); it++) {
			if (!--indegree[*it]) q.push(*it);
		}
	}

	for (int i = 1; i < N; i++) {
		if(isBasic[i]) cout << i << " " << result[N][i] << "\n";
	}
	return 0;
}