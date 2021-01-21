#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

void make_pattern(int x, int y, int level);
char stars[2187][2187];

int main() {
	int n, level, tmp = 1;
	cin >> n;
	for (int i = 0; i < 8; i++)
	{
		if (tmp != n) tmp *= 3; 
		else {
			level = i;
			break;
		}
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			stars[i][j] = ' ';

	make_pattern(0, 0, level);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << stars[i][j];
		cout << "\n";
	}
	return 0;
}

void make_pattern(int x, int y, int level) {
	if (level == 0) {
		stars[x][y] = '*';
		return;
	}

	int gap = pow(3, level - 1);
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (!(i == 1 && j == 1))
				make_pattern(x + i * gap, y + j * gap, level - 1);
	
	return;
}