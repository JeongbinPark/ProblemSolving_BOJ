#include <iostream>
#include <string>
using namespace std;

int idx, num, tmp, result;
string str;
bool flag;

int main() {
	cin >> str;
	str += 'E';

	while (idx < (int)str.size()) {
		if (str[idx] >= '0' && str[idx] <= '9') {
			num = 0;
			while (str[idx] >= '0' && str[idx] <= '9') {
				num *= 10;
				num += str[idx] - '0';
				idx++;
			}
			idx--;
		}
		else {
			if (flag) result -= num;
			else result += num;
			if (!flag && str[idx] == '-') flag = true;
		}
		idx++;
	}
	cout << result;
	return 0;
}