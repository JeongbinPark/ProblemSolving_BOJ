/*배열 너무 커
#include <iostream>
#include <vector>
using namespace std;

void make_board(int, int, int);

int N, r, c, tmp = 1;
int board[32769][32769];
vector<int> pow2;

int main() {
	cin >> N >> r >> c;
	for (int i = 0; i < 2 * N; i++) {
		pow2.push_back(tmp);
		tmp *= 2;
	}
	make_board(0, 0, N);
	cout << board[r - 1][c - 1];
	return 0;
}
void make_board(int row, int col, int K) {
	if (K == 0) return;
	int tmp = board[row][col];
	board[row][col + K] = tmp + pow2[2 * N - 2];
	board[row + K][col] = tmp + 2 * pow2[2 * N - 2];
	board[row + K][col + K] = tmp + 3 * pow2[2 * N - 2];
	make_board(row, col, K - 1);
	make_board(row + K, col, K - 1);
	make_board(row, col + K, K - 1);
	make_board(row + K, col + K, K - 1);
	return;
}*/

#include <iostream>
#include <vector>
using namespace std;

void make_board(int, int, int, int);

int N, r, c, tmp = 1, result;
vector<int> pow2;

int main() {
	cin >> N >> r >> c;
	for (int i = 0; i < 2 * N; i++) {
		pow2.push_back(tmp);
		tmp *= 2;
	}
	make_board(0, 0, N, 0);
	cout << result;
	return 0;
}
void make_board(int row, int col, int K, int val) {
	if (row == r && col == c) {
		result = val;
	}
	if (K == 0) return;
	if(r < pow2[K - 1] + row && c < pow2[K - 1] + col) make_board(row, col, K - 1, val);
	else if (r < pow2[K - 1] + row && c >= pow2[K - 1] + col) make_board(row, col + pow2[K  - 1], K - 1, val + pow2[2 * K- 2]);
	else if (r >= pow2[K - 1] + row && c < pow2[K - 1] + col) make_board(row + pow2[K - 1], col, K - 1, val + 2 * pow2[2 * K - 2]);
	else if (r >= pow2[K - 1] + row && c >= pow2[K - 1] + col) make_board(row + pow2[K - 1], col + pow2[K - 1], K - 1, val + 3 * pow2[2 * K - 2]);
	return;
}

/* 이런 방법도 있네...
#include<stdio.h>

int su(int n, int r, int c){
	if(n<=0)return 0;
	return 4*su(n-1, r/2, c/2)+(r%2)*2+(c%2);
}

int main(){
	int a, b, c;
	while(scanf("%d%d%d", &a, &b, &c)!=EOF)printf("%d\n", su(a,b,c));
	return 0;
}
*/