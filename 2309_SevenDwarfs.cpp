#include <iostream>
#include <algorithm>
using namespace std;

int h[9], e = 0;
int e_idx[2];
int main() {
	for (int i = 0; i < 9; i++)
	{
		cin >> h[i];
		e += h[i];
	}
	e -= 100;
	sort(h, h + 9);
	for (int i = 0; i < 8; i++)
		for (int j = i + 1; j < 9; j++)
			if (h[i] + h[j] == e) {
				for (int k = 0; k < 9; k++)
					if (k != i && k != j) cout << h[k] << "\n";
				return 0;
			}

	return 0;
}