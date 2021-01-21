#include <iostream>
using namespace std;

int main() {
	int K, N;
	char Z;
	int time, sum = 0;
	int boom=0;
	cin >> K;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> time >> Z;
		sum += time;
		if (boom == 0 && sum >= 210) boom = K;
		if (Z == 'T') K++;
	}
	boom = boom % 8 == 0 ? 8 : boom % 8;
	cout << boom;
	return 0;
}