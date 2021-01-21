#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N, M, times, num, pressed;
bool isBroken[10];
string numbers;
bool flag;

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> num;
		isBroken[num] = true;
	}

	if (N > 100) pressed = N - 100;
	else pressed = 100 - N;
	
	times = 0, num = N;
	while(times <= pressed) {
		numbers = to_string(num);
		flag = true;
		for (int i = 0; i < (int)numbers.size() && flag; i++) {
			if (isBroken[numbers[i] - '0']) flag = false;
		}
		if (flag) {
			pressed = min(pressed, times + (int)numbers.size());
			break;
		}
		times++, num++;
	}
	times = 0, num = N;
	while (num >= 0 && times <= pressed) {
		numbers = to_string(num);
		flag = true;
		for (int i = 0; i < (int)numbers.size() && flag; i++) {
			if (isBroken[numbers[i] - '0']) flag = false;
		}
		if (flag) {
			pressed = min(pressed, times + (int)numbers.size());
			break;
		}
		times++, num--;
	}
	cout << pressed;
	return 0;
}