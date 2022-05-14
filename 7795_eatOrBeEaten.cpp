#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;

int main() {
	cin >> N;
	while (N--) {
		int A, B, num;
		cin >> A >> B;
		vector<int> A_numbers, B_numbers;
		for (int i = 0; i < A; i++) {
			cin >> num;
			A_numbers.push_back(num);
		}
		for (int i = 0; i < B; i++) {
			cin >> num;
			B_numbers.push_back(num);
		}
		sort(A_numbers.begin(), A_numbers.end());
		sort(B_numbers.begin(), B_numbers.end());

		int A_p = 0, B_p = 0;
		int result = 0;

		while (true) {
			if (A_p == (int)A_numbers.size()) break;
			if (B_p == (int)B_numbers.size()) {
				result += B_p * ((int)A_numbers.size() - A_p);
				break;
			}
			if (A_numbers[A_p] <= B_numbers[B_p]) {
				A_p++;
				result += B_p;
			}
			else {
				B_p++;
			}
		}
		cout << result << "\n";
	}
	return 0;
}