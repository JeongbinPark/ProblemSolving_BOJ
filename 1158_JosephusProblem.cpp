#include <iostream>
#include <queue>
using namespace std;

int N, K;
queue<int> q;

int main() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		q.push(i);
	}
	int term = 0;
	cout << "<";
	while (!q.empty()) {
		term++;
		if (term < K) {
			q.push(q.front());
		}
		else {
			term = 0;
			cout << q.front();
			if (q.size() != 1) cout << ", ";

		}
		q.pop();
	}
	cout << ">";
	return 0;
}