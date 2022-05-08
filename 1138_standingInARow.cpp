#include <iostream>
using namespace std;

int N, num;
int line[10];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		for (int j = 0; j < N; j++) {
			if (line[j]) continue;
			if (num > 0) {
				num--;
				continue;
			}
			line[j] = i + 1;
			break;
		}
	}
	for (int i = 0; i < N; i++) {
		cout << line[i] << " ";
	}
	return 0;
}