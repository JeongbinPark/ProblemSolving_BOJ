#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;

	char cmd[6];
	int tmp;
	queue<int> q;

	for (int i = 0; i < N; i++) {
		cin >> cmd;
		if (!strcmp(cmd, "push")) {
			cin >> tmp;
			q.push(tmp);
		}
		else if (!strcmp(cmd, "pop")) {
			if (q.empty()) cout << -1 << "\n";
			else {
				cout << q.front() << "\n";
				q.pop();
			}
		}
		else if (!strcmp(cmd, "size")) {
			cout << q.size() << "\n";
		}
		else if (!strcmp(cmd, "empty")) {
			cout << q.empty() << "\n";
		}
		else if (!strcmp(cmd, "front")) {
			if (q.empty()) cout << -1 << "\n";
			else {
				cout << q.front() << "\n";
			}
		}
		else if (!strcmp(cmd, "back")) {
			if (q.empty()) cout << -1 << "\n";
			else {
				cout << q.back() << "\n";
			}
		}
	}
	return 0;
}