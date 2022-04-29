#include <iostream>
#include <algorithm>
using namespace std;

int N, X;
int arr[100000];
int cnt;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	cin >> X;

	sort(arr, arr + N);

	int s = 0, e = N - 1;
	while (s < e) {
		int sum = arr[s] + arr[e];
		if (sum == X) {
			cnt++;
			s++;
		} else if (sum < X){
			s++;
		}
		else {
			e--;
		}
	}
	cout << cnt;
	return 0;
}