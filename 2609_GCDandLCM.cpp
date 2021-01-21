#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int num1, num2, _num1, _num2, r = 1;
	cin >> num1 >> num2;
	_num1 = num1, _num2 = num2;
	while (r) {
		if (_num1 < _num2) swap(_num1, _num2);
		r = _num1 % _num2;
		_num1 = _num2;
		_num2 = r;
	}
	cout << _num1 << "\n" << num1 * num2 / _num1;
	return 0;
}