/*BigInteger 필요
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

long long calc(int, int);
void makeString(int, int);

int N, M, K;
long long cnt, amount[101][101];
string str;

int main() {
	cin >> N >> M >> K;
	cnt = calc(N, M);
	if (K > cnt) {
		cout << -1;
		return 0;
	}
	makeString(N, M);
	cout << str;
	return 0;
}
long long calc(int n, int m) {
	if (amount[n][m]) return amount[n][m];
	if (n == 0 || m == 0) {
		amount[n][m] = 1;
		return 1;
	}
	amount[n][m] = calc(n - 1, m) + calc(n, m - 1);
	return amount[n][m];
}
void makeString(int n, int m) {
	if (n == 0) {
		while (m--) str += 'z';
		return;
	}
	if (m == 0) {
		while (n--) str += 'a';
		return;
	}
	if (amount[n - 1][m] >= K) {
		str += 'a';
		makeString(n - 1, m);
	}
	else {
		K -= amount[n - 1][m];
		str += 'z';
		makeString(n, m - 1);
	}
	return;
}
*/
/*
//BigInteger 사용.... 하지만 이 문제에서는 K의 최댓값(1000000000) 넘는지만 판단하면 된다...
//K의 최댓값이 넘으면 어차피 그만큼 a만 앞에 추가하니까....
#include <iostream>
#include <algorithm>
#include <string>
#define MAX 1000000000000000000
using namespace std;

long long calc(int, int);
void makeString(int, int);

int N, M, K;
long long cnt, amount_high[101][101], amount[101][101];
string str;

int main() {
	cin >> N >> M >> K;
	cnt = calc(N, M);
	if (!amount_high[N][M] && K > cnt) {
		cout << -1;
		return 0;
	}
	makeString(N, M);
	cout << str;
	return 0;
}
long long calc(int n, int m) {
	if (amount_high[n][m] || amount[n][m]) return amount[n][m];
	if (n == 0 || m == 0) {
		amount[n][m] = 1;
		return 1;
	}
	amount[n][m] = calc(n - 1, m) + calc(n, m - 1);
	amount_high[n][m] = amount_high[n - 1][m] + amount_high[n][m - 1];
	amount_high[n][m] += amount[n][m] / MAX;
	amount[n][m] %= MAX;
	return amount[n][m];
}
void makeString(int n, int m) {
	if (n == 0) {
		while (m--) str += 'z';
		return;
	}
	if (m == 0) {
		while (n--) str += 'a';
		return;
	}
	if (amount_high[n-1][m] || amount[n - 1][m] >= K) {
		str += 'a';
		makeString(n - 1, m);
	}
	else {
		K -= amount[n - 1][m];
		str += 'z';
		makeString(n, m - 1);
	}
	return;
}
*/

#include <iostream>
#include <algorithm>
#include <string>
#define MAX 1000000000
using namespace std;

long long calc(int, int);
void makeString(int, int);

int N, M, K;
long long cnt, amount[101][101];
string str;

int main() {
	cin >> N >> M >> K;
	cnt = calc(N, M);
	if (K > cnt) {
		cout << -1;
		return 0;
	}
	makeString(N, M);
	cout << str;
	return 0;
}
long long calc(int n, int m) {
	if (amount[n][m]) return amount[n][m];
	if (n == 0 || m == 0) {
		amount[n][m] = 1;
		return 1;
	}
	amount[n][m] = calc(n - 1, m) + calc(n, m - 1);
	if (amount[n][m] > MAX) {
		amount[n][m] %= MAX;
		amount[n][m] += MAX;
	}
	return amount[n][m];
}
void makeString(int n, int m) {
	if (n == 0) {
		while (m--) str += 'z';
		return;
	}
	if (m == 0) {
		while (n--) str += 'a';
		return;
	}
	if (amount[n - 1][m] >= K) {
		str += 'a';
		makeString(n - 1, m);
	}
	else {
		K -= amount[n - 1][m];
		str += 'z';
		makeString(n, m - 1);
	}
	return;
}