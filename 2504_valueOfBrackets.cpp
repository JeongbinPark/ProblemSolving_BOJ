#include <iostream>
#include <stack>
using namespace std;

char c;
int num;
stack<int> s;
char brackets[5] = { '-', '(', ')', '[', ']' };

int main() {
	while (cin >> c) {
		for (int i = 1; i <= 4; i++) {
			if (brackets[i] == c) {
				num = -i;
				break;
			}
		}

		if (num == -2) {
			int tmp = 0;
			while (!s.empty() && s.top() != -1) {
				tmp += s.top();
				s.pop();
			}
			if (s.empty()) break;
			s.pop();
			s.push(tmp ? tmp * 2 : 2);
		} else if (num == -4) {
			int tmp = 0;
			while (!s.empty() && s.top() != -3) {
				tmp += s.top();
				s.pop();
			}
			if (s.empty()) break;
			s.pop();
			s.push(tmp ? tmp * 3 : 3);
		}
		else {
			s.push(num);
		}
	}

	int result = 0;
	while (!s.empty()) {
		if (s.top() < 0) {
			cout << 0;
			return 0;
		}
		result += s.top();
		s.pop();
	}
	cout << result;
	return 0;
}