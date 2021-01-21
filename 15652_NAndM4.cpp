#include <iostream>
using namespace std;

void bt(int *, int);
void print(int *);

int n, m;

int main() {
	int numbers[8];
	cin >> n >> m;
	bt(numbers, 0);
	return 0;
}
void bt(int * numbers, int level) {
	if (level == m) {
		print(numbers);
		return;
	}
	else {
		for (int i = 1; i <= n; i++)
			if (level == 0 || numbers[level - 1] <= i) {
				numbers[level] = i;
				bt(numbers, level + 1);
			}
	}
}
void print(int * numbers) {
	for (int i = 0; i < m; i++)
	{
		cout << numbers[i] << " ";
	}
	cout << "\n";
}