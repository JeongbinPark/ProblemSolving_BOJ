#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int num, cnt;
vector<int> seq;

int main() {
	cin >> N;
	int first = 1001;
	for (int i = 0; i < N; i++) {
		cin >> num;
		if (first > num) {
			seq.push_back(-num);
		}
		else {
			int index = lower_bound(seq.begin(), seq.end(), -num) - seq.begin();
			seq[index] = -num;
		}
		first = -seq[(int)seq.size() - 1];
	}
	cout << (int)seq.size();
	return 0;
}