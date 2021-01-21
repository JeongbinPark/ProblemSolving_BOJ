#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, number, cnt = 0;
vector< pair<int, int> > numbers;
int lis[500];

int main() {
	cin >> n;

	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		numbers.push_back(make_pair(a, b));
	}
	sort(numbers.begin(), numbers.end());

	for (int i = 0; i < n; i++) {
		number = numbers[i].second;
		if (i == 0 || lis[cnt - 1] < number) lis[cnt++] = number;
		else lis[lower_bound(lis, lis + cnt, number) - lis] = number;
	}
	cout << n - cnt;
	return 0;
}