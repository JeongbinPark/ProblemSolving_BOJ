#include <iostream>
#include <string>
using namespace std;

string S, T;
bool isForward = true;

int main() {
	cin >> S >> T;

	int S_len = (int)S.length();
	int T_start = 0;
	int T_end = (int)T.length() - 1;

	while (S_len < T_end - T_start + 1) {
		int idx = isForward ? T_end : T_start;
		if (isForward) {
			T_end--;
		} else {
			T_start++;
		}
		if (T[idx] == 'B') isForward = !isForward;
	}

	for (int i = 0; i < S_len; i++) {
		int idx = isForward ? i + T_start : T_end - i;
		if (S[i] != T[idx]) {
			cout << 0;
			return 0;
		}
	}
	cout << 1;
	return 0;
}