#include <iostream>
#include <algorithm>
using namespace std;

int N;
int consulting[17][2] = { 0 };
int payments[17] = { 0 };
int result = 0;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> consulting[i][0] >> consulting[i][1];
	}
	
	for (int i = N - 1; i >= 0; i--) {
		int time = consulting[i][0];
		int payment = consulting[i][1];

		if (i + time > N) {
			payments[i] = payments[i + 1];
		} else {
			payments[i] = max(payment + payments[i + time], payments[i + 1]);
		}
		result = max(result, payments[i]);
	}
	cout << result;
	return 0;
}