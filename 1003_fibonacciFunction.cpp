/*
#include <iostream>
using namespace std;

int zero[41] = { 1, 0 };
int one[41] = { 0, 1 };

int main() {
	for (int i = 2; i < 41; i++)
	{
		zero[i] = zero[i - 1] + zero[i - 2];
		one[i] = one[i - 1] + one[i - 2];
	}
	int t;
	cin >> t;
	
	int number;
	while (t-- > 0) {
		cin >> number;
		cout << zero[number] << " " << one[number] << "\n";
	}
	return 0;
}
*/


//zero[i] == one[i-1] ÀÌ´Ù!!!!

#include <iostream>
using namespace std;

int one[41] = { 0, 1 };

int main() {
	for (int i = 2; i < 41; i++)
		one[i] = one[i - 1] + one[i - 2];
	int t;
	cin >> t;

	int number;
	while (t-- > 0) {
		cin >> number;
		cout << (number == 0 ? 1 : one[number - 1]) << " " << one[number] << "\n";
	}
	return 0;
}
