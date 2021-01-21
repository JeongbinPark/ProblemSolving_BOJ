#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	int N, val;
	string cmd;
	stack<int> s;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> cmd;

		if (!cmd.compare("push")) {
			cin >> val;
			s.push(val);
		}
		else if (!cmd.compare("pop")) {
			if (!s.empty()) {
				cout << s.top()<<"\n";
				s.pop();
			}
			else cout << "-1" << "\n";
		}
		else if (!cmd.compare("size")) {
			cout << s.size() << "\n";
		}
		else if (!cmd.compare("empty")) {
			cout << (s.empty() ? 1 : 0) << "\n";
		}
		else if (!cmd.compare("top")) {
			if(!s.empty()) cout << s.top() << "\n";
			else cout << "-1" << "\n";
		}
	}

	return 0;
}