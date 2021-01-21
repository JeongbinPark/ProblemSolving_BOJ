#include <iostream>
#include <algorithm>
using namespace std;

int n, number, max_sum, result;
bool flag = false;

int main() {
	cin >> n;
	while (n--) {
		cin >> number;
		if (!flag) {
			max_sum = result = number;
			flag = true;
		}
		else {
			max_sum = max(max_sum + number, number);
			result = max(result, max_sum);
		}
	}
	cout << result;
	return 0;
}

