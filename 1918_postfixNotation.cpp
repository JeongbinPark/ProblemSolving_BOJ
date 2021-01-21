#include <iostream>
#include <stack>
#include <string>
using namespace std;

int cmp(char c);

int main() {
	string prefix;
	cin >> prefix;

	string postfix;
	stack<char> op;

	for (int i = 0; i < (int)prefix.size(); i++)
	{
		if ('A' <= prefix.at(i) && prefix.at(i) <= 'Z') 
			postfix.push_back(prefix.at(i));
		else if (prefix.at(i) == '(')
			op.push(prefix.at(i));
		else if (prefix.at(i) == ')') {
			while (op.top() != '(') {
				postfix.push_back(op.top());
				op.pop();
			}
			op.pop();
		}
		else {
			while (!op.empty() && cmp(prefix.at(i)) <= cmp(op.top())) {
				postfix.push_back(op.top());
				op.pop();
			}
			op.push(prefix.at(i));
		}
	}
	
	while (!op.empty()) {
		postfix.push_back(op.top());
		op.pop();
	}
	
	cout << postfix;

	return 0;
}

int cmp(char c) {
	if (c == '*' || c == '/') return 2;
	else if (c == '+' || c == '-') return 1;
	else if (c == '(' || c == ')') return 0;
	else return -1;
}