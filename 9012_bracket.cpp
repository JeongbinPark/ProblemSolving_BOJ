#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	stack<char> s;
	int T;
	bool yes;
	string brackets;

	cin >> T;
	for (int i = 0; i < T; i++)
	{
		while (!s.empty()) s.pop();
		yes = true;
		cin >> brackets;
		for (int j = 0; j < brackets.size(); j++)
		{
			if (s.empty() && brackets.at(j) == ')') yes = false;
			else if (brackets.at(j) == '(') s.push('(');
			else s.pop();
		}
		if (!s.empty()) yes = false;
		cout << (yes? "YES" : "NO")<<"\n";
	}

	return 0;
}