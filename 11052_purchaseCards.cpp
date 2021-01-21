#include <iostream>
#include <algorithm>
using namespace std;

int N, num[1001];

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> num[i];
	for (int i = 2; i <= N; i++) {
		for (int j = 1; j <= i / 2; j++) {
			num[i] = max(num[i], num[j] + num[i - j]);
		}
	}
	cout << num[N];
	return 0;
}