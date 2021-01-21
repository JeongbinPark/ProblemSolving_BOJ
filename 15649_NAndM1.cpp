#include <iostream>
using namespace std;

void dfs(int * numbers, int * isUsed, int level);
void print(int * numbers);

int n, m;

int main() {
	int numbers[8] = { 0 };
	int isUsed[8] = { 0 };

	cin >> n >> m;

	dfs(numbers, isUsed, 0);

	return 0;
}

void dfs(int * numbers, int * isUsed, int level) {
	if (level == m) {
		print(numbers);
		return;
	}
	else {
		for (int i = 1; i <= n; i++)
		if(!isUsed[i - 1]){
			numbers[level] = i;
			isUsed[i-1] = 1;
			dfs(numbers, isUsed, level + 1);
			isUsed[i-1] = 0;
		}
	}
	return;
}
void print(int * numbers) {
	for (int i = 0; i < m; i++)
	{
		cout << numbers[i] << " ";
	}
	cout << "\n";
}