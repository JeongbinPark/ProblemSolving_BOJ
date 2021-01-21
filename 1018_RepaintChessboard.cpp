#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string str[50];

int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> str[i];
	int x, y;
	int mini, cnt;
	for (int x = 0; x <= N - 8; x++) {
		for (int y = 0; y <= M - 8; y++)
		{
			cnt = 0;
			for (int i = x; i < x + 8; i++)
				for (int j = y; j < y + 8; j++)
					if ((((i % 2 && j % 2) || (!(i % 2) && !(j % 2))) && str[i][j] != 'W') || (((i % 2 && !(j % 2)) || (!(i % 2) && j % 2)) && str[i][j] != 'B')) cnt++;
			if (!x && !y) mini = cnt;
			else mini = min(mini, cnt);
			cnt = 0;
			for (int i = x; i < x + 8; i++)
				for (int j = y; j < y + 8; j++)
					if ((((i % 2 && j % 2) || (!(i % 2) && !(j % 2))) && str[i][j] != 'B') || (((i % 2 && !(j % 2)) || (!(i % 2) && j % 2)) && str[i][j] != 'W')) cnt++;
			mini = min(mini, cnt);
		}
	}
	
	cout << mini;
	return 0;
}