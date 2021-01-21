#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;

int T, N;

int main() {
	cin >> T;
	while (T--) {
		cin >> N;
		map<string, int> m;
		set<string> s;
		while (N--) {
			string name, type;
			cin >> name >> type;
			s.insert(type);
			m[type]++;
		}
		int result = 1;
		set<string>::iterator it;
		for (it = s.begin(); it != s.end(); it++) {
			result *= m[*it] + 1;
		}

		cout << result - 1 << "\n";
	}
	return 0;
}