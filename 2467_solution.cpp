#include <iostream>
#include <cstdlib>
using namespace std;

int n;
int arr[100000];
int left_result, right_result;
int min_sum = 2000000000;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int left_index = 0, right_index = n - 1;
	while (left_index != right_index) {
		int sum = arr[left_index] + arr[right_index];
		bool move_left = sum < 0;
		if (min_sum > abs(sum)) {
			min_sum = abs(sum);
			left_result = arr[left_index];
			right_result = arr[right_index];
		}
		if (move_left) left_index++;
		else right_index--;
	}
	cout << left_result << " " << right_result;
	return 0;
}