/* 스택 이용
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	int T;
	char c;
	cin >> T;

	stack<int> s;
	string str;

	getline(cin, str);
	while (T--) {
		str.clear();
		getline(cin, str);
		for (int i = 0; i <= str.size(); i++) {
			if (i == str.size() || str[i] == ' ') {
				while (!s.empty()) {
					c = s.top();
					cout << c;
					s.pop();
				}
				cout << ' ';
			}
			else s.push(str[i]);
		}
		cout << "\n";
	}

	return 0;
}
*/
//reverse이용
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int T, s = 0, t;
	cin >> T;

	string str;
	getline(cin, str);
	while (T--) {
		s = 0;
		getline(cin, str);
		for (int i = 0; i <= str.size(); i++)
		{
			if (i == str.size() || str[i] == ' ') {
				t = i;
				reverse(str.begin() + s, str.begin() + t);
				s = i + 1;
			}
		}
		cout << str << "\n";
	}
	return 0;
}

//토큰이용 방법도 있음