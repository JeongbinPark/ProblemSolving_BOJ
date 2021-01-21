#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void find(int, int);

int N, M, tmp, mid, result;
vector<int> numbers;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		numbers.push_back(tmp);
	}

	sort(numbers.begin(), numbers.begin() + N);

	cin >> M;
	while (M--) {
		result = 0;
		cin >> tmp;
		find(0, N - 1);
		cout << result << "\n";
	}

	return 0;
}
void find(int s, int t) {
	if (t < s) return;
	mid = (s + t) / 2;
	if (tmp == numbers[mid]) result = 1;
	if (tmp > numbers[mid]) find (mid + 1, t);
	if (tmp < numbers[mid]) find (s, mid - 1);
}