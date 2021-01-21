#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int calc(int);

int N, tmp;
int times[501];
vector<int> pre[501];
bool visited[501];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> times[i];
		while (cin >> tmp && tmp != -1) {
			pre[i].push_back(tmp);
		}
	}
	for (int i = 1; i <= N; i++) {
		cout << calc(i) << "\n";
	}
	return 0;
}
int calc(int n) {
	if (visited[n]) return times[n];
	visited[n] = true;
	int maxi = 0;
	for (int i = 0; i < (int)pre[n].size(); i++) {
		maxi = max(maxi, calc(pre[n][i]));
	}
	times[n] += maxi;
	return times[n];
}