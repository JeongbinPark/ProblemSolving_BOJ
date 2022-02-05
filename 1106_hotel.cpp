#include <iostream>
#include <algorithm>
#define INF 1000000
using namespace std;

int C, N;
int city[20][2] = { 0 };
int fee[1001];

int main() {
	cin >> C >> N;
	for (int i = 0; i < N; i++) {
		cin >> city[i][0] >> city[i][1];
	}
	fill(fee, fee + C + 1, INF);
	
	fee[0] = 0;
	for (int i = 0; i < N; i++) {
		int payment = city[i][0];
		int customer = city[i][1];
		for (int j = 0; j <= customer; j++) {
			fee[j] = min(fee[j], payment);
		}
		for (int j = customer + 1; j <= C; j++) {
			for (int k = j; k - customer >= 0; k--) {
				fee[k] = min(fee[k], fee[k - customer] + payment);
			}
		}
	}

	cout << fee[C];
	return 0;
}