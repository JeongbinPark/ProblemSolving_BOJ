//������ ���ӵ� ����� ������ ���, �ƴ� ���� [0][1]
#include <iostream>
#include <algorithm>
using namespace std;

int stair[301][2] = { 0, 0, 0 };
int n, score;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> score;
		if (i == 1)	stair[i][1] = score;
		else {
			stair[i][0] = stair[i - 1][1] + score;
			stair[i][1] = max(stair[i - 2][0], stair[i - 2][1]) + score;
		}
	}
	cout << max(stair[n][0], stair[n][1]);
	return 0;
}

//int score[] ��� ���� �ִ� ����
//int stair[] �ش� ����� ����
//score[i] = max(score[i-2], score[i-3] + stair[i-1]) + stair[i]