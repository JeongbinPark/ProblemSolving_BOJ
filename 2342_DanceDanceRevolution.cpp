//맨위 define은 VS용, c++11 
#define  _SCL_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#define MAX 1000000
using namespace std;

int sq;
int power[5][5] = { -1, 2, 2, 2, 2, -1, 1, 3, 4, 3, -1, 3, 1, 3, 4, -1, 4, 3, 1, 3, -1, 3, 4, 3, 1 };
int prev_minPower[5][5];
int curr_minPower[5][5];

int main() {
	cin >> sq;
	fill(&prev_minPower[0][0], &prev_minPower[4][5], MAX);
	prev_minPower[0][sq] = prev_minPower[sq][0] = 2;
	while (cin >> sq && sq) {
		fill(&curr_minPower[0][0], &curr_minPower[4][5], MAX);
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (prev_minPower[i][j] != MAX) {
					if (i != sq) curr_minPower[i][sq] = min(curr_minPower[i][sq], prev_minPower[i][j] + power[j][sq]);
					if (j != sq) curr_minPower[sq][j] = min(curr_minPower[sq][j], prev_minPower[i][j] + power[i][sq]);
				}
			}
		}
		copy(&curr_minPower[0][0], &curr_minPower[0][0] + 25, &prev_minPower[0][0]);
	}

	int result_minPower = MAX;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			result_minPower = min(result_minPower, prev_minPower[i][j]);
		}
	}
	cout << result_minPower;
	return 0;
}