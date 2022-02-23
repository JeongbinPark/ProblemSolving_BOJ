#include <iostream>
#include <algorithm>
#define INF 100000
using namespace std;

int N;
int P[1001];
int total[1001];

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> P[i];
		total[i] = INF;
	}
	for (int i = 0; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if ((i + j <= N) && total[i + j] > total[i] + P[j]) 
				total[i + j] = total[i] + P[j];
		}
	}
	cout << total[N];
	return 0;
}