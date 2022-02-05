//시간초과
//#include <iostream>
//#include <queue>
//#include <algorithm>
//using namespace std;
//
//int K, N;
//int lans[10001];
//priority_queue<int> pq;
//
//int main() {
//	cin >> K >> N;
//	for (int i = 0; i < K; i++) {
//		cin >> lans[i];
//		pq.push(lans[i]);
//	}
//
//	while (!pq.empty()) {
//		int unit = pq.top();
//		pq.pop();
//
//		int result = 0;
//		for (int i = 0; i < K; i++) {
//			result += lans[i] / unit;
//		}
//
//		cout << unit << " : " << result << "\n";
//		if (result >= N) {
//			cout << unit;
//			return 0;
//		}
//
//		pq.push(unit / 2);
//		if (unit / 2) pq.push(unit / 2 + 1);
//	}
//
//	return 0;
//}

#include <iostream>
#include <cmath>
using namespace std;

int K, N;
int lans[10001];

int main() {
	cin >> K >> N;
	for (int i = 0; i < K; i++) {
		cin >> lans[i];
	}

	long long s = 0;
	int e = pow(2, 31) - 1;
	
	while (true) {
		if (s > e) {
			cout << e;
			break;
		}
		long long mid = (s + e) / 2;

		long long cnt = 0;
		for (int i = 0; i < K; i++) {
			cnt += lans[i] / mid;
		}

		if (cnt < N) {
			e = mid - 1;
		} else {
			s = mid + 1;
		}
	}
	return 0;
}