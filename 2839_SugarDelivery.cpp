#include <iostream>
using namespace std;

int main() {
	int N;
	int bags = -1;
	cin >> N;
	for (int i = 0; i <= N/3; i++)
	{
		for (int j = 0; j <= N/5; j++)
		{
			if (i * 3 + j * 5 == N && (bags > i + j || bags == -1)) bags = i + j;
		}
	}
	cout << bags;

	return 0;
}