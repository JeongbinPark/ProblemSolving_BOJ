/* 벡터 이용 1번 노드와 연결된 노드만 이중for문으로 검사
#include <iostream>
#include <vector>
using namespace std;

vector<int> lists[501];
int cnt = 0;
bool visited[501] = { false };

int main() {
	int n, m;
	cin >> n >> m;
	int a, b;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		lists[a].push_back(b);
		lists[b].push_back(a);
	}
	int newNode;
	visited[1] = true;
	for (int i = 0; i < lists[1].size(); i++)
	{
		newNode = lists[1][i];
		if (!visited[newNode]) {
			visited[newNode] = true;
			cnt++;
		}
		for (int j = 0; j < lists[newNode].size(); j++)
		{
			if (!visited[lists[newNode][j]]) {
				visited[lists[newNode][j]] = true;
				cnt++;
			}
		}
	}

	cout << cnt;
	return 0;
}
*/

#include <iostream>
using namespace std;

bool lists[501][501] = { false };
int cnt = 0;

int main() {
	int n, m;
	cin >> n >> m;
	
	int a, b;
	while (m--) {
		cin >> a >> b;
		lists[a][b] = lists[b][a] = true;
	}
	for (int i = 2; i <= n; i++)
	{
		if (lists[1][i]) cnt++;
		else {
			for (int j = 2; j <= n; j++)
				if (lists[1][j] && lists[j][i]) {
					cnt++;
					break;
				}
		}
	}
	cout << cnt;
	return 0;
}