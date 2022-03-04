#include <iostream>
#include <algorithm>
#define MAX 2147483647
using namespace std;

int T;
int arr[92682];

int main() {
	long long sum = 0;
	int gap = 0;
	bool isFirst = true;
	for (int i = 1; sum <= MAX; i++) {
		if (isFirst) gap++;
		sum += gap;
		isFirst = !isFirst;
		arr[i] = (int) sum;
	}
	arr[92681] = MAX;
	cin >> T;
	while (T--) {
		int x, y;
		cin >> x >> y;
		cout << lower_bound(arr, arr + 92682, y - x) - arr << "\n";
	}
	return 0;
}
