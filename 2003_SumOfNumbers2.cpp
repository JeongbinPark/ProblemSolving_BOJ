#include <iostream>
#include <queue>
using namespace std;

int N, M, num, sum, cnt;
queue<int> q;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N >> M;
	while (N--) {
		cin >> num;
		q.push(num);
		sum += num;
		while (!q.empty() && sum >= M) {
			if (sum == M) cnt++;
			sum -= q.front();
			q.pop();
		}
	}
	cout << cnt;
	return 0;
}