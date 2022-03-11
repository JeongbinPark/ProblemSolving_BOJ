#include <iostream>
#include <queue>
using namespace std;

int N, x;
priority_queue<int> pq_neg;
priority_queue<int> pq_pos;

int main() {
	cin >> N;
	while (N--) {
		cin >> x;
		if (!x) {
			if (pq_pos.empty() && pq_neg.empty()) {
				cout << 0 << "\n";
				continue;
			}
			else if (pq_pos.empty() && !pq_neg.empty()) {
				cout << pq_neg.top();
				pq_neg.pop();
			}
			else if (!pq_pos.empty() && pq_neg.empty()) {
				cout << -pq_pos.top();
				pq_pos.pop();
			}
			else {
				int pos = pq_pos.top();
				int neg = pq_neg.top();
				if (pos > neg) {
					cout << -pos;
					pq_pos.pop();
				}
				else {
					cout << neg;
					pq_neg.pop();
				}
			}
			cout << "\n";
		}
		else {
			if (x < 0) pq_neg.push(x);
			else pq_pos.push(-x);
		}
	}
	return 0;
}