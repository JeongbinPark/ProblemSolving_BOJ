//처음에 3번째 조건을 아에 적용안함....ㅎ
//문제를 잘보자
#include <iostream>
using namespace std;

int w(int, int, int);

int w_val[21][21][21] = { 0 };

int main() {
	for (int i = 0; i <= 20; i++) 
		for (int j = 0; j <= 20; j++) 
			for (int k = 0; k <= 20; k++) 
				if (w_val[i][j][k] == 0) 
					w(i, j, k);

	while (true) {
		int a, b, c, new_a, new_b, new_c;
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1) break;

		new_a = a, new_b = b, new_c = c;
		if (new_a <= 0 || new_b <= 0 || new_c <= 0) new_a = new_b = new_c = 0;
		if (new_a > 20 || new_b > 20 || new_c > 20 ) new_a = new_b = new_c = 20;

		cout << "w(" << a << ", " << b << ", " << c << ") = " << w_val[new_a][new_b][new_c] << "\n";
	}
	return 0;
}

int w(int a, int b, int c) {
	if (w_val[a][b][c] != 0) 
		return w_val[a][b][c];
	if (a <= 0 || b <= 0 || c <= 0) {
		w_val[a][b][c] = 1;
		return 1;
	}
	if (a > 20 || b > 20 || c > 20) {
		w_val[a][b][c] = w(20, 20, 20);
		return w_val[a][b][c];
	}
	if (a < b && b < c) {
		w_val[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
		return w_val[a][b][c];
	}
	int result = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
	w_val[a][b][c] = result;
	return result;
}