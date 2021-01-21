#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int calc(int);

int T, N, K, X, Y, W;
int time[1001];
vector<int> pre[1001];
bool visited[1001];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		cin >> N >> K;
		fill(visited + 1, visited + N + 1, false);
		for (int i = 1; i <= N; i++) {
			cin >> time[i];
			pre[i].clear();
		}
		while (K--) {
			cin >> X >> Y;
			pre[Y].push_back(X);
		}
		cin >> W;
		cout << calc(W) << "\n";
	}
	return 0;
}
int calc(int n) {
	if (visited[n]) return time[n];
	visited[n] = true;
	int maxi = 0;
	for (int i = 0; i < (int)pre[n].size(); i++) {
		maxi = max(maxi, calc(pre[n][i]));
	}
	time[n] += maxi;
	return time[n];
}