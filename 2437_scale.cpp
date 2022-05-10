//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//void makeSum(int, int);
//
//int N, weight;
//vector<int> weights;
//vector<int> sums;
//
//int main() {
//	cin >> N;
//
//	for (int i = 0; i < N; i++) {
//		cin >> weight;
//		weights.push_back(weight);
//	}
//
//	makeSum(0, 0);
//
//	sort(sums.begin(), sums.end());
//
//	int idx = 1;
//	while (true) {
//		if (idx < (int) sums.size() - 1 && sums[idx] + 1 >= sums[idx + 1]) {
//			idx++;
//			continue;
//		}
//		cout << sums[idx] + 1;
//		return 0;
//	}
//	return 0;
//}
//
//void makeSum(int level, int sum) {
//	if (level == N) {
//		sums.push_back(sum);
//		return;
//	}
//	makeSum(level + 1, sum + weights[level]);
//	makeSum(level + 1, sum);
//	return;
//}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, weight;
vector<int> weights;
int maxConsecutiveNumber = 0;

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> weight;
		weights.push_back(weight);
	}

	sort(weights.begin(), weights.end());

	for (int i = 0; i < N; i++) {
		if (maxConsecutiveNumber + 1 >= weights[i]) {
			maxConsecutiveNumber += weights[i];
		}
		else break;
	}

	cout << maxConsecutiveNumber + 1;
	return 0;
}