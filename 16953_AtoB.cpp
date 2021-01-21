#include <iostream>
#include <string>
using namespace std;

void find(long long, int);

int A, B;
string number;
bool found = false;

int main() {
	cin >> A >> B;
	find(A, 1);
	if (!found) cout << -1;
	return 0;
}

void find(long long num, int level) {
	if (found || B < num) return;
	if (B == num) {
		cout << level;
		found = true;
		return;
	}
	find(num * 2, level + 1);
	number = to_string(num);
	number += '1';
	find(stoll(number), level + 1);
	return;
}