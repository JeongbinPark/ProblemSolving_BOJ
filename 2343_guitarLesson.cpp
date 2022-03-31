/*
#include <iostream>
#include <algorithm>
#define INF 1000000000
using namespace std;

int N, M;
int videos[100001];

int main() {
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		cin >> videos[i];
		videos[i] += videos[i - 1];
	}

	if (M == 1) {
		cout << videos[N];
		return 0;
	}

	videos[N + 1] = videos[N];
	int start = 0;
	int end = videos[N];
	while (start < end) {
		int mid = (start + end) / 2;

		int prevIndex = 0;
		int cnt = 1;
		bool isShort = false;
		for (int i = 1; i <= N + 1; i++) {
			if (videos[i] > videos[prevIndex] + mid) {
				cnt++;
				if (videos[i - 1] - videos[prevIndex] > mid) {
					isShort = true;
					break;
				}
				prevIndex = i - 1;
			}
		}

		if (cnt <= M && !isShort) {
			end = mid;
		}
		else {
			start = mid + 1;
		}
	}
	cout << start;
	return 0;
}
*/
#include <iostream>
#include <algorithm>
#define INF 1000000000
using namespace std;

int N, M, maxLength;
int videos[100001];

int main() {
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		cin >> videos[i];
		maxLength = max(maxLength, videos[i]);
		videos[i] += videos[i - 1];
	}

	if (M == 1) {
		cout << videos[N];
		return 0;
	}

	int start = maxLength;
	int end = videos[N];
	while (start < end) {
		int mid = (start + end) / 2;

		int prevIndex = 0;
		int cnt = 1;
		for (int i = 1; i <= N; i++) {
			if (videos[i] > videos[prevIndex] + mid) {
				cnt++;
				prevIndex = i - 1;
			}
		}

		if (cnt <= M) {
			end = mid;
		}
		else {
			start = mid + 1;
		}
	}
	cout << start;
	return 0;
}