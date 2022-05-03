#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[1000];
int s, e;
int result;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		e = max(e, arr[i]);
	}
	cin >> M;

	while (s <= e) {
		int m = (s + e) / 2;
		int sum = 0;
		for (int i = 0; i < N; i++) {
			sum += min(m, arr[i]);
		}
		if(M >= sum) {
			result = m;
			s = m + 1;
		} else if (M < sum) {
			e = m - 1;
		}
	}
	cout << result;
	return 0;
}