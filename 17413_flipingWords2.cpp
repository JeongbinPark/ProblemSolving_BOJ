#include <iostream>
#include <string>
#include <stack>
using namespace std;

string input;
stack<char> str;

int main() {
	getline(cin, input);
	
	int len = (int)input.size();
	int idx = 0;
	while (idx < len) {
		char c = input[idx];
		if (c == '<') {
			while (!str.empty()) {
				cout << str.top();
				str.pop();
			}
			while (input[idx] != '>') {
				cout << input[idx++];
			}
			cout << '>';
		}
		else if (c == ' '){
			while (!str.empty()) {
				cout << str.top();
				str.pop();
			}
			cout << ' ';
		}
		else {
			str.push(c);
		}
		idx++;
	}
	while (!str.empty()) {
		cout << str.top();
		str.pop();
	}
	return 0;
}