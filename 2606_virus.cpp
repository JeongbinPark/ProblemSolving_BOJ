#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int computers[100][100];
	int inf = 101;
	int computer, connect;
	int a, b;

	cin >> computer;
	for (int i = 0; i < computer; i++)
		for (int j = 0; j < computer; j++)
			computers[i][j] = i == j ? 0 : inf;

	cin >> connect;
	for (int i = 0; i < connect; i++)
	{
		cin >> a >> b;
		computers[a - 1][b - 1] = 1;
		computers[b - 1][a - 1] = 1;
	}

	for (int k = 0; k < computer; k++)
		for (int i = 0; i < computer; i++)
			for (int j = 0; j < computer; j++)
				computers[i][j] = min(computers[i][j], computers[i][k] + computers[k][j]);
	
	int virus = 0;
	for (int i = 0; i < computer; i++)
		if (computers[0][i] > 0 && computers[0][i] != inf) virus++;
	cout << virus;
	return 0;
}