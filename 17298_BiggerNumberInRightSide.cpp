/*
필요없는 값들을 계속 복사, pop하는 과정으로 시간초과
#include <iostream>
#include <stack>
using namespace std;

int N, val;
stack<int> values, curr_stack, result;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> val;
		values.push(val);
	}

	while (!values.empty()) {
		int this_val = values.top();
		values.pop();

		stack<int> this_stack = curr_stack;
		curr_stack.push(this_val);

		while (true) {
			if (this_stack.empty()) {
				result.push(-1);
				break;
			}
			if (this_val < this_stack.top()) {
				result.push(this_stack.top());
				break;
			}
			this_stack.pop();
		}
	}

	for (int i = 0; i < N; i++) {
		cout << result.top() << " ";
		result.pop();
	}
	return 0;
}
*/

#include <iostream>
#include <stack>
using namespace std;

int N, val;
stack<int> values, curr_stack, result;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> val;
		values.push(val);
	}

	while (!values.empty()) {
		int this_val = values.top();
		values.pop();

		while (true) {
			if (curr_stack.empty()) {
				result.push(-1);
				break;
			}
			if (curr_stack.top() > this_val) {
				result.push(curr_stack.top());
				break;
			}
			curr_stack.pop();
		}
		curr_stack.push(this_val);
	}

	for (int i = 0; i < N; i++) {
		cout << result.top() << " ";
		result.pop();
	}
	return 0;
}