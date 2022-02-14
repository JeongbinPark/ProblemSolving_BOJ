//사이클 고려하지 않아서 시간초과
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int findChild(int);
//
//int n, m;
//int c1, c2;
//vector<int> child[10001];
//int cnt_descendant[10001];
//int max_cnt;
//
//int main() {
//	cin >> n >> m;
//	for (int i = 0; i < m; i++) {
//		cin >> c1 >> c2;
//		child[c2].push_back(c1);
//	}
//	fill(cnt_descendant, cnt_descendant + n + 1, -1);
//
//	for (int i = 1; i <= n; i++) {
//		if (cnt_descendant[i] == -1) {
//			cnt_descendant[i] = findChild(i);
//			max_cnt = max(max_cnt, cnt_descendant[i]);
//		}
//	}
//
//	for (int i = 1; i <= n; i++) {
//		if (cnt_descendant[i] == max_cnt) cout << i << " ";
//	}
//	return 0;
//}
//
//int findChild(int node) {
//	if (cnt_descendant[node] != -1) return cnt_descendant[node] + 1;
//
//	int nodeChild = 0;
//	vector<int>::iterator it;
//	for (it = child[node].begin(); it != child[node].end(); it++) {
//		nodeChild += findChild(*it);
//	}
//	cnt_descendant[node] = nodeChild;
//	return nodeChild + 1;
//}

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

void findChild(int);

int n, m;
int c1, c2;
vector<int> child[10001];
int cnt_descendant[10001];
bool visited[10001];
int max_cnt;
int curr_cnt;

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> c1 >> c2;
		child[c2].push_back(c1);
	}

	for (int i = 1; i <= n; i++) {
		memset(visited, 0, sizeof(bool)*(n+1));
		curr_cnt = 1;
		visited[i] = true;
		findChild(i);
		cnt_descendant[i] = curr_cnt;
		max_cnt = max(max_cnt, curr_cnt);
	}

	for (int i = 1; i <= n; i++) {
		if (cnt_descendant[i] == max_cnt) cout << i << " ";
	}
	return 0;
}

void findChild(int node) {
	vector<int>::iterator it;
	for (it = child[node].begin(); it != child[node].end(); it++) {
		if (!visited[*it]) {
			visited[*it] = true;
			curr_cnt++;
			findChild(*it);
		}
	}
	return;
}