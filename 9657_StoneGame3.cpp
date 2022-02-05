#include <iostream>
using namespace std;

int N;
bool isWinNumber[1001] = { 0, 1, 0, 1, 1 };

int main() {
	cin >> N;
	for (int i = 5; i <= N; i++) {
		isWinNumber[i] = (!isWinNumber[i - 1] || !isWinNumber[i - 3] || !isWinNumber[i - 4]);
	}
	cout << (isWinNumber[N] ? "SK" : "CY");
	return 0;
}