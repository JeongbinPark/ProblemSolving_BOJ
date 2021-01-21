/* 시간 초과
#include <iostream>
#include <cstring>
using namespace std;

bool findCycle(int, int);

int T, n, s, notInLoop;
int nextNode[100001];
bool visited[100001];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		cin >> n;
		notInLoop = n;
		memset(visited, false, sizeof(bool) * (n + 1));
		for (int i = 1; i <= n; i++)
			cin >> nextNode[i];
		for (int i = 1; i <= n; i++) {
			if (!visited[i]) {
				s = i;
				findCycle(i, 0);
				visited[i] = true;
			}
		}
		cout << notInLoop << "\n";
	}
}
bool findCycle(int node, int level) {
	if (node == s && level > 0) {
		notInLoop -= level;
		return true;
	}
	if (visited[node]) return false;
	visited[node] = true;
	if (findCycle(nextNode[node], level + 1)) return true;
	visited[node] = false;
	return false;
}
*/

#include <iostream>
#include <cstring>
using namespace std;

bool findCycle(int, int);

int T, n, notInLoop;
int nextNode[100001], recur[100001];
bool visited[100001];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		cin >> n;
		notInLoop = n;
		memset(visited, false, sizeof(bool) * (n + 1));
		for (int i = 1; i <= n; i++)
			cin >> nextNode[i];
		for (int i = 1; i <= n; i++) {
			if (!visited[i]) {
				findCycle(i, 1);
			}
		}
		cout << notInLoop << "\n";
	}
}
bool findCycle(int node, int level) {
	visited[node] = true;
	recur[node] = level;

	if (!visited[nextNode[node]] && findCycle(nextNode[node], level + 1)) return true;
	else if (recur[nextNode[node]]) {
		notInLoop -= level - recur[nextNode[node]] + 1;
	}
	recur[node] = 0;
	return false;
}