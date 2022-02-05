#include <iostream>
#include <algorithm>
using namespace std;

int N, num, prevNum;
int	curr_increase, max_increase, curr_decrease, max_decrease;

int main() {
	cin >> N;
	cin >> prevNum;
	curr_increase = max_increase = curr_decrease = max_decrease = 1;
	for (int i = 1; i < N; i++) {
		cin >> num;
		if (num > prevNum) {
			curr_increase++;
			max_decrease = max(max_decrease, curr_decrease);
			curr_decrease = 1;
		}
		else if (num < prevNum) {
			curr_decrease++;
			max_increase = max(max_increase, curr_increase);
			curr_increase = 1;
		}
		else {
			curr_increase++;
			curr_decrease++;
		}
		prevNum = num;
	}
	max_increase = max(max_increase, curr_increase);
	max_decrease = max(max_decrease, curr_decrease);
	cout << max(max_increase, max_decrease);
	return 0;
}