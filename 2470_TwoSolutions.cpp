#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#define INF 2000000000
using namespace std;

int N, num;
vector<int> solutions;
int minSum = INF, idx1, idx2;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		solutions.push_back(num);
	}
	sort(solutions.begin(), solutions.end());

	int left = 0, right = N - 1;
	while (left < right) {
		int sum = solutions[left] + solutions[right];
		if (minSum > abs(sum)) {
			minSum = abs(sum);
			idx1 = left;
			idx2 = right;
		}
		if (sum == 0) break;
		else if (sum > 0) right--;
		else left++;
	}

	cout << solutions[idx1] << " " << solutions[idx2];
	return 0;
}