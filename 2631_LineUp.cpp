#include <iostream>
#include <algorithm>
using namespace std;

int n, number, cnt = 0;
int lis[200];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> number;
		if (i == 0 || lis[cnt - 1] < number) lis[cnt++] = number;
		else lis[lower_bound(lis, lis + cnt, number) - lis] = number;
	}
	cout << n - cnt;
	return 0;
}
