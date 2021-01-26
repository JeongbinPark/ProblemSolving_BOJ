#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, num;
vector<int> A, B;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> num;
		A.push_back(num);
	}
	for (int i = 0; i < n; i++) {
		cin >> num;
		B.push_back(num);
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += A[i] * B[n - 1 - i];
	}
	cout << sum;

	return 0;
}