#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 10000000
using namespace std;

int X;
int cnt[1000001][2] = { 0 };

int main() {
	cin >> X;
	for (int i = 2; i <= X; i++) {
		int tmp[3] = { i, i, i };
		if (i % 3 == 0) tmp[0] = cnt[i / 3][0];
		if (i % 2 == 0) tmp[1] = cnt[i / 2][0];
		tmp[2] = cnt[i - 1][0];

		int min_cnt = MAX, min_idx = -1;
		for (int j = 0; j < 3; j++) {
			if (tmp[j] != i && min_cnt > tmp[j] + 1) {
				min_cnt = tmp[j] + 1;
				min_idx = j;
			}
		}

		cnt[i][0] = min_cnt;
		if (min_idx == 0)cnt[i][1] = i / 3;
		else if (min_idx == 1) cnt[i][1] = i / 2;
		else cnt[i][1] = i - 1;
	}

	cout << cnt[X][0] << "\n" << X;
	int next = cnt[X][1];
	while (next) {
		cout << " " << next;
		next = cnt[next][1];
	}
	return 0;
}
