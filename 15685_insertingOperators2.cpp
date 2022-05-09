//음수 나누기를 위해 C++14이상 사용
#include <iostream>
#include <algorithm>
#define INF 1000000001
using namespace std;

void calc(int level, int sum);
int calcSum(int op, int sum, int num);

int N;
int numbers[100];
int operators[4]; //+, -, x, /
int minSum = INF, maxSum = -INF;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> numbers[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> operators[i];
	}

	calc(1, numbers[0]);

	cout << maxSum << "\n" << minSum;
	return 0;
}

void calc(int level, int sum) {
	if (level == N) {
		minSum = min(minSum, sum);
		maxSum = max(maxSum, sum);
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (operators[i]) {
			operators[i]--;
 			calc(level + 1, calcSum(i, sum, numbers[level]));
			operators[i]++;
		}
	}
	return;
}

int calcSum(int op, int sum, int num) {
	if (op == 0) return sum + num;
	if (op == 1) return sum - num;
	if (op == 2) return sum * num;
	if (op == 3) return sum / num;
}