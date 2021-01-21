//Longest Bitonic Subsequence

#include <iostream>
#include <algorithm>
#define MAX 1000
using namespace std;

int arr[MAX], lis1[MAX], lis2[MAX], dp1[MAX], dp2[MAX];
int n, maxi, num, cnt = 0;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int i = 0; i < n; i++) {
		num = arr[i];
		if (!cnt || lis1[cnt - 1] < num) {
			lis1[cnt] = num;
			cnt++;
		}
		else lis1[lower_bound(lis1, lis1 + cnt, num) - lis1] = num;
		dp1[i] = cnt;
	}

	cnt = 0;
	for (int i = 0; i < n; i++) {
		num = arr[n - 1 - i];
		if (!cnt || lis2[cnt - 1] < num) {
			lis2[cnt] = num;
			cnt++;
		}
		else lis2[lower_bound(lis2, lis2 + cnt, num) - lis2] = num;
		dp2[i] = cnt;
	}
	
	int maxi = dp1[0] + dp2[n-1];
	for (int i = 1; i < n; i++) {
		maxi = max(maxi, dp1[i] + dp2[n - 1 - i]);
	}
	cout << maxi - 1;
	return 0;
}