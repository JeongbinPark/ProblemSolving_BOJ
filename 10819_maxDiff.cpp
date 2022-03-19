#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

void setNum(int, int);

int n;
int arr[8], newArr[8];
bool visited[8];
int maxResult;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	setNum(-1, -1);

	cout << maxResult;
	return 0;
}

void setNum(int num, int level) {
	if (num >= 0) {
		newArr[level] = arr[num];
	}
	if (level == n - 1) {
		int result = 0;
		for (int i = 1; i < n; i++) {
			result += abs(newArr[i - 1] - newArr[i]);
		}
		maxResult = max(maxResult, result);
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			setNum(i, level + 1);
			visited[i] = false;
		}
	}
	return;
}