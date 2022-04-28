//long long int abs (long long int n)À» À§ÇØ C++11
#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

int N;
int input[5001];
int result[3];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> input[i];
	}
	sort(input, input + N);

	long long minDiff = 3000000001;
	bool found = false;

	for (int i = 1; !found && i < N - 1; i++) {
		int left = 0, right = N - 1;
		while (left != i && right != i && left != right) {
			long long sum = input[left] + input[right];
			sum += input[i];
			if (minDiff > abs(sum)) {
				minDiff = abs(sum);
				result[0] = input[left];
				result[1] = input[i];
				result[2] = input[right];
			}
			if (sum == 0) {
				found = true;
				break;
			} else if (sum < 0) {
				left++;
			} else {
				right--;
			}
		}
	}

	sort(result, result + 3);
	cout << result[0] << " " << result[1] << " " << result[2];
	return 0;
}