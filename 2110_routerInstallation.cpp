#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, C, num;
vector<int> v;
int min_distance;

int main() {
	cin >> N >> C;
	for (int i = 0; i < N; i++) {
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	int start = 1;
	int end = v[N - 1] - v[0];

	while (start <= end) {
		int mid = (start + end) / 2;
		int prev = v[0];
		int cnt = 1;
		for (int i = 0; i < N; i++) {
			if (v[i] >= prev + mid) {
				prev = v[i];
				cnt++;
			}
		}

		if (cnt >= C) {
			start = mid + 1;
			min_distance = max(min_distance, mid);
		} else {
			end = mid - 1;
		}
	}
	cout << min_distance;
	return 0;
}
