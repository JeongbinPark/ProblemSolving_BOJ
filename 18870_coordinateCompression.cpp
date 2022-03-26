#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, num;
vector<int> input;
vector<int> sortedInput;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		input.push_back(num);
		sortedInput.push_back(num);
	}

	sort(sortedInput.begin(), sortedInput.end());

	vector<int> index;
	index.push_back(sortedInput[0]);
	for (int i = 1; i < N; i++) {
		if (sortedInput[i] != sortedInput[i - 1]) {
			index.push_back(sortedInput[i]);
		}
	}

	for (int i = 0; i < N; i++) {
		cout << lower_bound(index.begin(), index.end(), input[i]) - index.begin() << " ";
	}

	return 0;
}