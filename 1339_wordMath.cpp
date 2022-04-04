#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N;
string word;
int alphaValues[26];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> word;
		int tmp = 1;
		for (int j = (int)word.size() - 1; j >= 0; j--) {
			alphaValues[word[j] - 'A'] += tmp;
			tmp *= 10;
		}
	}
	sort(alphaValues, alphaValues + 26);
	
	int sum = 0;
	int val = 9;
	for (int i = 0; i < 10; i++) {
		sum += alphaValues[25 - i] * val--;
	}
	cout << sum;
	return 0;
}