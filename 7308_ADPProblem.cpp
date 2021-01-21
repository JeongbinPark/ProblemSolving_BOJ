#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int t, num, sign, index;
double LeftSingleInt, RightSingleInt, LeftIntWx, RightIntWx;
string str;
bool LeftSide;

int main() {
	cin >> t;
	while (t--) {
		cin >> str;
		LeftSide = true;
		LeftSingleInt = RightSingleInt = LeftIntWx = RightIntWx = 0;
		index = 0, sign = 1, num = 1;
		while (index <= (int)str.size()) {
			if (str[index] >= '0' && str[index] <= '9') {
				num = 0;
				while (str[index] >= '0' && str[index] <= '9') {
					num *= 10;
					num += str[index] - '0';
					index++;
				}
				index--;
				cout << "";
			}
			else if (str[index] == 'x') {
				if (LeftSide) LeftIntWx += sign * num;
				else RightIntWx += sign * num;
			}
			else {
				if (index && str[index - 1] != '=' && str[index - 1] != 'x') {
					if (LeftSide) LeftSingleInt += sign * num;
					else RightSingleInt += sign * num;
				}

				if (str[index] == '=') LeftSide = false, sign = 1, num = 1;
				else if (str[index] == '-') sign = -1, num = 1;
				else if (str[index] == '+') sign = 1, num = 1;
			}
			index++;
		}

		if (LeftIntWx == RightIntWx) {
			if (LeftSingleInt == RightSingleInt) cout << "IDENTITY" << "\n";
			else cout << "IMPOSSIBLE" << "\n";
		}
		else {
			cout << (int) floor(((LeftSingleInt - RightSingleInt) / (RightIntWx - LeftIntWx))) << "\n";
		}
	}
	return 0;
}