/*
#include <iostream>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;

int main() {
	queue< pair<int, int> > q;
	int arr[101];
	int t, n, m, tmp, idx, cnt;
	cin >> t;
	while (t--) {
		idx = cnt = 0;
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> tmp;
			q.push(make_pair(i, tmp));
			arr[i] = tmp;
		}
		sort(arr, arr + n, greater<int>());
		while (!q.empty()) {
			if (q.front().second == arr[idx]) {
				cnt++, idx++;
				if (q.front().first == m) break;
			}
			else {
				q.push(make_pair(q.front().first, q.front().second));
			}
			q.pop();
		}
		cout << cnt << "\n";
	}
	return 0;
}*/

#include <iostream>
#include <queue>
using namespace std;


int main() {
	priority_queue<int> pq;
	queue< pair<int, int> > q;
	int t, n, m, tmp, cnt;
	cin >> t;
	while (t--) {
		cnt = 0;
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> tmp;
			q.push(make_pair(tmp, i));
			pq.push(tmp);
		}
		while (!q.empty()) {
			if (pq.top() == q.front().first) {
				cnt++;
				if (q.front().second == m) break;
				pq.pop();
			}
			else
				q.push(make_pair(q.front().first, q.front().second));
			q.pop();
		}
		cout << cnt << "\n";
		while (!q.empty()) q.pop();
		while (!pq.empty()) pq.pop();
	}
	return 0;
}