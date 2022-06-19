#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int moneys[100000];
int maxMoney;

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> moneys[i];
		maxMoney = max(maxMoney, moneys[i]);
	}

	int left = 0, right = maxMoney * N;
	while (left <= right) {
		int mid = (left + right) / 2;
		int sum = 0;
		int cnt = 1;
		for (int i = 0; i < N; i++) {
			if (sum + moneys[i] > mid) {
				sum = moneys[i];
				cnt++;
			}
			else sum += moneys[i];
		}
		if (cnt <= M) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	cout << left;
	return 0;
}