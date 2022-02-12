#include <iostream>
#include <cmath>
using namespace std;

bool isSquare(int);

int cnt_tri = 0;
int cnt_game = 0;
int xIndexs[13];
int main() {
	for (int i = 0; i <= 1000000000; i += cnt_tri) {
		cnt_tri++;
		if (isSquare(i+1)) xIndexs[cnt_game++] = i;
	}

	long long T = 0;
	while (++T) {
		int a, b;
		cin >> a >> b;
		if (!a && !b) return 0;

		int result = 0;
		for (int i = 0; i < cnt_game; i++) {
			if (xIndexs[i] + 1 >= b) break;
			if (xIndexs[i] + 1 > a) result++;
		}
		cout << "Case " << T <<": " << result << "\n";
	}
	return 0;
}
bool isSquare(int num) {
	int temp = (int)(sqrt((double)num) + 0.5);
	return temp * temp == num;
}