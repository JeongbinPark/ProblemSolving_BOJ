#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int T;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> T;
	while (T--) {
		int N, num;
		cin >> N;
		vector<int> input;
		for (int i = 0; i < N; i++) {
			cin >> num;
			input.push_back(num);
		}
		sort(input.begin(), input.end());

		vector<int> v;
		v.assign(N + 1, input[0]);

		int left = 1;
		int right = N - 1;
		for (int i = 1; i < N; i++) {
			if (i % 2) {
				v[right] = input[i];
				right--;
			}
			else {
				v[left] = input[i];
				left++;
			}
		}

		int maxDiff = 0;
		for (int i = 1; i <= N; i++) {
			maxDiff = max(maxDiff, abs(v[i] - v[i - 1]));
		}
		cout << maxDiff << "\n";
	}
	return 0;
}