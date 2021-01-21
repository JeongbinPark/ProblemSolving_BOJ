/* 시간초과
#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> oven;
	int D, N;
	cin >> D >> N;
	int n;
	for (int i = 0; i < D; i++) {
		cin >> n;
		oven.push_back(n);
	}
	int end = D, dough;
	while (N-->0) {
		cin >> dough;
		for (int i = 0; i < end; i++) {
			if (dough>oven[i]) {
				end = i;
				break;
			}
		}
		end--;
		if (end == -1) break;
	}
	cout << end + 1;
	return 0;
}
*/

#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int main() {
	stack<int> oven;
	int D, N;
	cin >> D >> N;
	int n;
	cin >> n;
	oven.push(n);
	for (int i = 1; i < D; i++) {
		cin >> n;
		oven.push(min(n, oven.top()));
	}
	int dough;
	for(int i = 0; i < N; i++) {
		if (i != 0) oven.pop();
		cin >> dough;
		while (!oven.empty() && oven.top() < dough)
			oven.pop();
		if (oven.empty()) break;
	}

	cout << oven.size();
}