#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, K, coor;
	vector<int> sensor;


	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> coor;
		sensor.push_back(coor);
	}
	
	sort(sensor.begin(), sensor.end());

	vector<int> diff;

	for (int i = 1; i < N; i++) {
		diff.push_back(-(sensor[i] - sensor[i-1]));
	}
	
	sort(diff.begin(), diff.end());

	int sum = 0;
	for (int i = K - 1; i < N - 1; i++) {
		sum += -diff[i];
	}
	cout << sum;

	return 0;
}