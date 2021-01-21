#include <iostream>
#include <stack>
#include <algorithm>
#define MAX 1000000
using namespace std;

int n, num, cnt = 0;
int arr[MAX], lis[MAX], index[MAX];
stack<int> result;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		arr[i] = num;
		if (!cnt || lis[cnt - 1] < num) {
			lis[cnt] = num;
			index[i] = cnt;
			cnt++;
		}
		else {
			lis[lower_bound(lis, lis + cnt, num) - lis] = num;
			index[i] = lower_bound(lis, lis + cnt, num) - lis;
		}
	}

	cout << cnt << "\n";
	int k = cnt - 1;
	for (int i = n - 1; i >= 0; i--) {
		if (index[i] == k) {
			result.push(arr[i]);
			k--;
		}
	}
	while (!result.empty()) {
		cout << result.top() << " ";
		result.pop();
	}
	return 0;
}