#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n, m;
	int inf = 10000001;
	cin >> n;

	int routes[100][100];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			routes[i][j] = inf;
	
	cin >> m;
	int s, t, c;
	for (int i = 0; i < m; i++)
	{
		cin >> s >> t >> c;
		routes[s-1][t-1] = min(routes[s-1][t-1],c);
	}

	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				routes[i][j] = i == j ? 0 : min(routes[i][j], routes[i][k] + routes[k][j]);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << (routes[i][j] == inf ? 0 : routes[i][j]) << " ";
		cout << "\n";
	}

	return 0;
}