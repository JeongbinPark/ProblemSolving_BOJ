#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int N;
int result;

int main() {
	cin >> N;
	string num = to_string(N);

	int len = num.length();
	int val = 9;
	for (int i = 1; i < len; i++) {
		result += val * i;
		val *= 10;
	}
	
	result += (N - pow(10, len - 1) + 1) * len;

	cout << result;
	return 0;
}