#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, num;
vector<int> pos, neg;
int zero_length, one_length;
int result = 0;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		if (num == 0) {
			zero_length++;
		}
		else if (num == 1) {
			one_length++;
		}
		else if (num > 0) {
			pos.push_back(num);
		}
		else {
			neg.push_back(num);
		}
	}

	int pos_length = (int)pos.size();
	int neg_length = (int)neg.size();

	sort(pos.begin(), pos.end());
	sort(neg.begin(), neg.end());

	if (pos_length % 2) result += pos[0];
	if (neg_length % 2 && !zero_length) result += neg[neg_length - 1];

	for (int i = pos_length - 1; i > 0; i-=2) {
		result += pos[i] * pos[i - 1];
	}
	for (int i = 0; i < neg_length - 1; i += 2) {
		result += neg[i] * neg[i + 1];
	}

	result += one_length;

	cout << result;

	return 0;
}