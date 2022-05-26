#include <iostream>
#define INF 1000000
using namespace std;

int N, num;
int maxValue, maxValue_minIndex, maxValue_maxIndex;

int main() {
	cin >> N;
	cin >> num;
	maxValue = num;

	for (int i = 1; i < N; i++) {
		cin >> num;
		if (maxValue < num) {
			maxValue_minIndex = i;
			maxValue_maxIndex = i;
			maxValue = num;
		}
		else if (maxValue == num) {
			maxValue_maxIndex = i;
		}
	}
	int R = N - maxValue_maxIndex - 1;
	int B = maxValue_minIndex;

	if (R > B) cout << "R";
	else if (R < B) cout << "B";
	else cout << "X";

	return 0;
}