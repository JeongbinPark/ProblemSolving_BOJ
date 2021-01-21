#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	string str;
	stack<char> s;
	bool yes = true;
	while (1) {
		while (!s.empty()) s.pop();
		yes = true;

		getline(cin, str);
		if (!str.compare(".")) break;
		for (int i = 0; i < (int) str.size(); i++)
		{
			if (str.at(i) == '(' || str.at(i) == '[')
				s.push(str.at(i));
			else if ((str.at(i) == ')' && (s.empty() || s.top() != '(')) || (str.at(i) == ']' && (s.empty() || s.top() != '['))) {
				yes = false;
				break;
			}
			else if (str.at(i) == ')' || str.at(i) == ']')
				s.pop();
		}
		if (!s.empty()) yes = false;
		cout << (yes ? "yes" : "no")<<"\n";
	}
	return 0;
}