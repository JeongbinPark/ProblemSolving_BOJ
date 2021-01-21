#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int r, c, k, time, max_r, max_c, idx, tmp;
int A[101][101], counter[101];
vector< pair<int, int> > v;

int main() {
	cin >> r >> c >> k;
	r--, c--;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			cin >> A[i][j];
	max_r = 3;
	max_c = 3;
	while (true) {
		if (A[r][c] == k) break;
		if (time > 100) {
			time = -1;
			break;
		}

		if (max_r >= max_c) {
			for (int i = 0; i < max_r; i++) {
				memset(counter, 0, sizeof(counter));
				idx = 0;
				v.clear();
				for (int j = 0; j <= 100; j++) {
					counter[A[i][j]]++;
					A[i][j] = 0;
				}
				for (int j = 1; j <= 100; j++)
					if (counter[j]) v.push_back(make_pair(counter[j], j));
				sort(v.begin(), v.end());
				tmp = (int)v.size() > 50 ? 50 : (int)v.size();
				max_c = max(max_c, tmp * 2);
				for (int j = 0; j < tmp; j++) {
					A[i][idx++] = v[j].second;
					A[i][idx++] = v[j].first;
				}
			}
		}
		else {
			for (int i = 0; i < max_c; i++) {
				memset(counter, 0, sizeof(counter));
				idx = 0;
				v.clear();
				for (int j = 0; j <= 100; j++) {
					counter[A[j][i]]++;
					A[j][i] = 0;
				}
				for (int j = 1; j <= 100; j++)
					if (counter[j]) v.push_back(make_pair(counter[j], j));
				sort(v.begin(), v.end());
				tmp = (int)v.size() > 50 ? 50 : (int)v.size();
				max_r = max(max_r, tmp * 2);
				for (int j = 0; j < tmp; j++) {
					A[idx++][i] = v[j].second;
					A[idx++][i] = v[j].first;
				}
			}
		}
		time++;
	}
	cout << time;
	return 0;
}