#include <iostream>
#include <algorithm>
using namespace std;

void addOp(int, int);

int n;
int num[11];
int op[4];
int minResult = 1000000001, maxResult;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> op[i];
	}

	addOp(1, num[0]);
	cout << maxResult << "\n" << minResult;
	return 0;
}

void addOp(int numIdx, int sum) {
	if (numIdx == n) {
		minResult = min(minResult, sum);
		maxResult = max(maxResult, sum);
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (op[i] <= 0) continue;
		int newSum = sum;
		if (i == 0) newSum += num[numIdx];
		else if (i == 1) newSum -= num[numIdx];
		else if (i == 2) newSum *= num[numIdx];
		else {
			bool isNegative = false;
			if (newSum < 0) {
				isNegative = true;
				newSum *= -1;
			}
			newSum /= num[numIdx];
			newSum = isNegative ? -newSum : newSum;
		}
		op[i]--;
		addOp(numIdx + 1, newSum);
		op[i]++;
	}
	return;
}
