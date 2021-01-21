#include <iostream>
#include <string>
using namespace std;

int main() {
	int tmp, result = 1;
	string str;
	cin >> str;
	result *= str[0] == 'c' ? 26 : 10;
	for (int i = 1; i < (int)str.size(); i++) {
		if (str[i] == 'c') tmp = 26;
		else tmp = 10;
		if (str[i] == str[i - 1]) tmp--;
		result *= tmp;
	}
	cout << result;
	return 0;
}