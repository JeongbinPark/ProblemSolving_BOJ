#include <iostream>
#include <queue>
using namespace std;

void checkMid(int n, bool isCw, bool isLeft);
void updateMid();
void move(int n, bool isCw);
int printResult();

char c;
bool isS[4][8];
int num, cw;
bool mid[8];
queue<pair<int, bool> > q;

int main() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> c;
			isS[i][j] = (c == '1' ? true : false);
		}
	}

	int K = 0;
	cin >> K;
	while(K--){
		updateMid();

		cin >> num >> cw;
		q.push(make_pair(num, (cw == 1 ? true : false)));
		checkMid(num, (cw == 1 ? true : false), true);
		checkMid(num, (cw == 1 ? true : false), false);

		while (!q.empty()) {
			move(q.front().first - 1, q.front().second);
			q.pop();
		}
	}
	cout << printResult();
	return 0;
}

void checkMid(int n, bool isCw, bool isLeft) {
	if (!isLeft && n != 4 && mid[n * 2 - 1] != mid[n * 2]) {
		q.push(make_pair(n + 1, !isCw));
		checkMid(n + 1, !isCw, isLeft);
	}
	if (isLeft && n != 1 && mid[n * 2 - 2] != mid[n * 2 - 3]) {
		q.push(make_pair(n - 1, !isCw));
		checkMid(n - 1, !isCw, isLeft);
	}
}

void updateMid() {
	for (int i = 0; i < 4; i++) {
		mid[i * 2] = isS[i][6];
		mid[i * 2 + 1] = isS[i][2];
	}
}

void move(int n, bool isCw) {
	if (isCw) {
		bool tmp = isS[n][7];
		for (int i = 7; i > 0; i--) isS[n][i] = isS[n][i - 1];
		isS[n][0] = tmp;
	}
	else {
		bool tmp = isS[n][0];
		for (int i = 0; i < 7; i++) isS[n][i] = isS[n][i + 1];
		isS[n][7] = tmp;
	}
}

int printResult() {
	int sum = 0;
	int scale = 1;
	for (int i = 0; i < 4; i++) {
		sum += isS[i][0] ? scale : 0;
		scale *= 2;
	}
	return sum;
}