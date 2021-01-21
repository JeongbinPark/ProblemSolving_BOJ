#include <iostream>
using namespace std;

int N;
long long pre_num = 0;
long long num = 1;
long long result = 4;

int main() {
	cin >> N;
	while (--N) {
		long long tmp = num;
		num += pre_num;
		pre_num = tmp;

		result += 2 * num;
	}
	cout << result;

	return 0;
}
