#include <iostream>
#include <algorithm>
#define MAX 1000000
using namespace std;

int N, num;
int	lis[MAX];
int cnt = 0;

int main() {
	cin >> N;
	cin >> lis[0];
	cnt++;
	for (int i = 1; i < N; i++) {
		cin >> num;
		if (lis[cnt - 1] < num) {
			lis[cnt] = num;
			cnt++;
		}
		else {
			lis[lower_bound(lis, lis + cnt, num) - lis] = num;
		}
	}
	cout << cnt;
	return 0;
}