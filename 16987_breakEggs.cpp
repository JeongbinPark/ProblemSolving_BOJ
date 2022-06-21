#include <iostream>
#include <algorithm>
using namespace std;

void breakEgg(int);

int N;
int durability[8], weight[8];
int maxEggs;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> durability[i] >> weight[i];
	}
	breakEgg(0);
	cout << maxEggs;
	return 0;
}
void breakEgg(int index) {
	if (index == N) {
		int brokenEggs = 0;
		for (int i = 0; i < N; i++) {
			if (durability[i] <= 0) brokenEggs++;
		}
		maxEggs = max(maxEggs, brokenEggs);
		return;
	}
	if (durability[index] <= 0) {
		breakEgg(index + 1);
		return;
	}
	bool existsEgg = false;
	for (int i = 0; i < N; i++) {
		if (i != index && durability[i] > 0) {
			existsEgg = true;
			durability[i] -= weight[index];
			durability[index] -= weight[i];

			breakEgg(index + 1);

			durability[i] += weight[index];
			durability[index] += weight[i];
		}
	}
	if (!existsEgg) breakEgg(index + 1);
	return;
}