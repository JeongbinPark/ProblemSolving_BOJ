#include <iostream>
using namespace std;

void pick(int, int);

int k;
int numbers[50], lottery[6];

int main() {
	while (true) {
		cin >> k;
		if (k == 0) break;
		for (int i = 0; i < k; i++)
			cin >> numbers[i];
		pick(-1, 0);
		cout << "\n";
	}
}
void pick(int idx, int level) {
	if (level == 6) {
		for (int i = 0; i < 6; i++)
			cout << lottery[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = idx + 1; i < k; i++) {
		lottery[level] = numbers[i];
		pick(i, level + 1);
	}
	return;
}