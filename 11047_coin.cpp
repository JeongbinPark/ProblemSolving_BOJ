#include <iostream>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	int unit[10];
	for (int i = 0; i<N; i++)
		cin >> unit[i];

	int min = 0;

	for (int i = N - 1; i >= 0; i--) 
		if (K / unit[i]>0) {
			min += K / unit[i];
			K -= K / unit[i] * unit[i];
		}

	cout << min;
	return 0;
}