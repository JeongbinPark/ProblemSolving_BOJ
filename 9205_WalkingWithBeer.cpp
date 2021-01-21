#include <iostream>
#include <math.h>
using namespace std;

bool findRoute(int );
bool isPossible(int [], int []);
int n;
int node[101][2];
int festival[2];
bool visited[101] = { false };

int main() {
	int t;

	cin >> t;
	while (t-- > 0) {
		fill(visited, visited + 101, false);
		visited[0] = true;
		cin >> n;
		for (int i = 0; i < n + 1; i++)
			cin >> node[i][0] >> node[i][1];
		cin >> festival[0] >> festival[1];

		cout << (findRoute(0) ? "happy" : "sad") << "\n";
	}
	return 0;
}
bool findRoute(int level) {
	if (isPossible(node[level], festival)) return true;
	for (int i = 0; i < n + 1; i++)
	{
		if (!visited[i]&&isPossible(node[i],node[level])) {
			visited[i] = true;
			if(findRoute(i)) return true;
		}
	}
	return false;
}
bool isPossible(int node1[], int node2[]) {
	return abs(node1[0] - node2[0]) + abs(node1[1] - node2[1]) <= 1000 ? true : false;
}
//35줄에 visited[i] = false 할 필요 없음
//이미 거기는 안되는 곳임 ㅇㅇ
//다시 가면 헛수고