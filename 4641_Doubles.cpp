/*
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int num, cnt;
vector<int> v;
queue<int> cmp;

int main() {
	while (true) {
		cin >> num;
		if (num == -1) break;
		else if (num == 0) {
			sort(v.begin(), v.end());
			cnt = 0;
			for (int i = 0; i < (int)v.size(); i++) {
				if (i) {
					while (!cmp.empty() && 2 * cmp.front() < v[i]) cmp.pop();
					if (!cmp.empty() && 2 * cmp.front() == v[i]) cnt++;
				}
				cmp.push(v[i]);
			}
			cout << cnt << "\n";
			while (!cmp.empty()) cmp.pop();
			v.clear();
		}
		else {
			v.push_back(num);
		}
	}
	return 0;
} */

#include <iostream>
#include <algorithm>
using namespace std;

int num, cnt;
bool numbers[101];

int main() {
	while (true) {
		cin >> num;
		if (num == -1) break;
		else if (num == 0) {
			cnt = 0;
			for (int i = 1; i < 50; i++) {
				if (numbers[i] && numbers[2 * i]) cnt++;
			}
			cout << cnt << "\n";
			fill(numbers, numbers + 101, false);
		}
		else {
			numbers[num] = true;
		}
	}
	return 0;
}