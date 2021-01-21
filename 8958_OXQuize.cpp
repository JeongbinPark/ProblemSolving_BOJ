#include <iostream>
#include <string>
using namespace std;

int main() {
	int t, n, sum;
	string str;
	cin >> t;
	while (t-->0) {
		sum = n = 0;
		cin >> str;
		for (int i = 0; i< str.size(); i++) {
			if (str[i] == 'O') {
				n++;
				sum += n;
			}
			else n = 0;
		}
		cout << sum << "\n";
	}
	return 0;
}