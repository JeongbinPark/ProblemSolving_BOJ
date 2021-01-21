/* 숫자 범위 초과
#include <iostream>
using namespace std;

int N, cnt[1001][2] = { 0, 0, 0, 1 };

int main() {
	cin >> N;
	for (int i = 2; i <= N; i++) {
		cnt[i][0] = cnt[i - 1][0] + cnt[i - 1][1] - (i % 2);
		cnt[i][1] = cnt[i - 1][0] + cnt[i - 1][1];
	}
	cout << cnt[N][0];
	return 0;
}
*/
/*
#include <iostream>
#define MAX 100000000000000000
using namespace std;

int N;
long long cnt[1001][20][2];
bool flag;

int main() {
	cnt[1][0][1] = 1;
	cin >> N;
	if (N == 1) cout << 0;
	for (int i = 2; i <= N; i++) {
		cnt[i][0][0] = cnt[i - 1][0][0] + cnt[i - 1][0][1] - (i % 2);
		cnt[i][0][1] = cnt[i - 1][0][0] + cnt[i - 1][0][1];
		for (int j = 1; j < 20; j++) {
			cnt[i][j][0] = cnt[i - 1][j][0] + cnt[i - 1][j][1] + cnt[i][j - 1][0] / MAX;
			cnt[i][j - 1][0] %= MAX;

			cnt[i][j][1] = cnt[i - 1][j][0] + cnt[i - 1][j][1] + cnt[i][j - 1][1] / MAX;
			cnt[i][j - 1][1] %= MAX;
			
		}
	}
	for (int i = 19; i >= 0; i--) {
		if (!flag && cnt[N][i][0]) {
			cout << cnt[N][i][0];
			flag = true;
		}
		else if (flag) {
			cout.width(17);
			cout.fill('0');
			cout << cnt[N][i][0];
		}
	}
	return 0;
}*/

#include <iostream>
#define MAX 100000000000000000
using namespace std;

int N;
long long cnt[1001][20];
bool flag;

int main() {
	cin >> N;
	if (N == 1) cout << 0;
	for (int i = 2; i <= N; i++) {
		cnt[i][0] = 2 * cnt[i - 1][0] - (i % 2) + ((i+1) % 2);
		for (int j = 1; j < 20; j++) {
			cnt[i][j] = 2 * cnt[i - 1][j] + cnt[i][j - 1] / MAX;
			cnt[i][j - 1] %= MAX;
		}
	}
	for (int i = 19; i >= 0; i--) {
		if (!flag && cnt[N][i]) {
			cout << cnt[N][i];
			flag = true;
		}
		else if (flag) {
			cout.width(17);
			cout.fill('0');
			cout << cnt[N][i];
		}
	}
	return 0;
}

/*
#include <iostream>
#define MAX 100000000000000000
using namespace std;

int N;
long long cnt[1001][20];
bool flag;

int main() {
	for (int i = 2; i <= 1000; i++) {
		cnt[i][0] = 2 * cnt[i - 1][0] - (i % 2) + ((i + 1) % 2);
		for (int j = 1; j < 20; j++) {
			cnt[i][j] = 2 * cnt[i - 1][j] + cnt[i][j - 1] / MAX;
			cnt[i][j - 1] %= MAX;
		}
	}
	for (int k = 1; k <= 1000; k++) {
		flag = false;
		cout << "k = " << k << "\n";
		if (k == 1) {
			cout << 0 << "\n\n";
			continue;
		}
		for (int i = 19; i >= 0; i--) {
			if (!flag && cnt[k][i]) {
				cout << cnt[k][i];
				flag = true;
			}
			else if (flag) {
				cout.width(17);
				cout.fill('0');
				cout << cnt[k][i];
			}
		}
		cout << "\n\n";
	}
	return 0;
}
*/