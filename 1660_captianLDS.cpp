#include <iostream>
#include <vector>
using namespace std;

int N, sum = 0, num;
vector<int> sumVector;
int times[300001];

int main() {
	cin >> N;
	for (int i = 1; sum <= N; i++) {
		num += i;
		sum += num;
		sumVector.push_back(sum);
	}
	for (int i = N; i >= 0; i--) {
		for (int j = 0; j < (int)sumVector.size(); j++) {
			int next = i - sumVector[j];
			if (next >= 0 && (!times[next] || times[next] > times[i] + 1)) {
				times[next] = times[i] + 1;
			}
		}
	}
	cout << times[0];
	return 0;
}