/*
#include <iostream>
using namespace std;

void NQueen(int (*)[15], int);
bool possible(int (*)[15], int, int);

int n;
int cnt = 0;

int main() {
	int chess[15][15] = { 0 };
	cin >> n;
	NQueen(chess, 0);
	cout << cnt;
	return 0;
}
void NQueen(int (* chess)[15], int row) {
	if (row == n) {
		cnt++;
		return;
	}
	else {
		for (int i = 0; i < n; i++)
			if(possible(chess,row,i)){
				chess[row][i] = 1;
				NQueen(chess, row + 1);
				chess[row][i] = 0;
			}
	}
	return;
}
bool possible(int (* chess)[15], int row, int col) {
	for (int i = 1; i <= row; i++) {
		if (chess[row - i][col] || (col + i >= 0 && col + i < n && chess[row - i][col + i]) || (col - i >= 0 && col - i < n && chess[row - i][col - i]))
			return false;
	}
	return true;
}
*/

/*
위와 아래 차이점
1. 위는 2차원배열로 chess[row][col]에 값으로 bool과 같은 역할인 0과 1,
	아래는 1차원배열로 col[row]에 값으로 col의 위치
2. 위는 해당 위치에 놓았을때 가정하고 possible 돌린 후 가능하면 넣고 다음 NQueen 호출
	아래는 먼저 놓은뒤 현재까지 possible 인지 보고 맞으면 다음 row의 NQueen, 아니면 현재 col[row]에 다음값 대입
*/


#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

void NQueen(int);
bool isPossible(int);

int n;
int col[15];
int cnt = 0;

int main() {
	cin >> n;
	fill(col, col + n, -1);
	
	NQueen(0);
	cout << cnt;
	return 0;
}
void NQueen(int row) {
	if (row == n)
		cnt++;
	else {
		for (int i = 0; i < n; i++)
		{
			col[row] = i;
			if (isPossible(row)) NQueen(row + 1);
		}
	}
	return;
}
bool isPossible(int row) {
	for (int i = 0; i < row; i++)
	{
		if (col[i] == col[row] || abs(col[row] - col[i]) == abs(row - i)) return false;
	}
	return true;
};
