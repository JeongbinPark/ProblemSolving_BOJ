/*
#include <iostream>
#include <algorithm>
using namespace std;

long long likeFibo(int);

int n;
long long seq[118] = { 0, 1, 1, 1 };

int main() {
	cin >> n;
	fill(seq + 4, seq + 117, -1);
	cout << likeFibo(n);
	return 0;
}
long long likeFibo(int num) {
	if (seq[num] != -1) return seq[num];
	else {
		seq[num] = likeFibo(num - 3) + likeFibo(num - 1);
		return seq[num];
	}
}
*/

#include <iostream>
using namespace std;

int n;
long long seq[117] = { 0, 1, 1, 1 };

int main() {
	for (int i = 4; i <= 116; i++)
		seq[i] = seq[i - 1] + seq[i - 3];
	cin >> n;
	cout << seq[n];
	return 0;
}