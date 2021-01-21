#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N, M, area;
string num[50];

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> num[i];
	for (int x = 0; x < N ; x++)
		for (int y = 0; y < M; y++)
			for (int l = 0; l < min(N - x, M - y); l++)
				if (num[x][y] == num[x + l][y] && num[x + l][y] == num[x + l][y + l] && num[x + l][y + l] == num[x][y + l])
					area = max(area, (l+1)*(l+1));
	cout << area;
	return 0;
}