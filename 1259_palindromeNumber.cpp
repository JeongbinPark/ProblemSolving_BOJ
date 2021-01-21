#include <iostream>
#include <string>
using namespace std;

int main() {
	int s, t;
	bool result;
	string str;
	while (cin >> str && str != "0") {
		s = 0, t = str.size() - 1;
		result = true;
		for (int i = 0; i<str.size() / 2; i++) {
			if (str[s + i] != str[t - i]) {
				result = false;
			}
		}
		cout << (result ? "yes" : "no") << "\n";
	}
	return 0;
}