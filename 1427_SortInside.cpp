#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<char> num;

int main() {
	cin >> n;
	while (n) {
		num.push_back(n % 10 + '0');
		n /= 10;
	}
	sort(num.begin(), num.end());
	for (int i = num.size() - 1; i >= 0; i--){
		cout <<  num[i];
	}
	return 0;
}
