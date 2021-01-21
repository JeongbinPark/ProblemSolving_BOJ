#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
	int N, tmp;
	string cmd;
	deque<int> d;

	cin >> N;
	while (N--) {
		cin >> cmd;
		if (!cmd.compare("push_front")) {
			cin >> tmp;
			d.push_front(tmp);
		}
		else if (!cmd.compare("push_back")) {
			cin >> tmp;
			d.push_back(tmp);
		}
		else if (!cmd.compare("pop_front")) {
			if (d.empty()) cout << -1 << "\n";
			else {
				cout << d.front() << "\n";
				d.pop_front();
			}
		}
		else if (!cmd.compare("pop_back")) {
			if (d.empty()) cout << -1 << "\n";
			else {
				cout << d.back() << "\n";
				d.pop_back();
			}
		}
		else if (!cmd.compare("size")) {
			cout << d.size() << "\n";
		}
		else if (!cmd.compare("empty")) {
			if (d.empty()) cout << 1 << "\n";
			else cout << 0 << "\n";
		}
		else if (!cmd.compare("front")) {
			if (d.empty()) cout << -1 << "\n";
			else cout << d.front() << "\n";
		}
		else if (!cmd.compare("back")) {
			if (d.empty()) cout << -1 << "\n";
			else cout << d.back() << "\n";
		}
	}
	return 0;
}