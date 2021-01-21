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
���� �Ʒ� ������
1. ���� 2�����迭�� chess[row][col]�� ������ bool�� ���� ������ 0�� 1,
	�Ʒ��� 1�����迭�� col[row]�� ������ col�� ��ġ
2. ���� �ش� ��ġ�� �������� �����ϰ� possible ���� �� �����ϸ� �ְ� ���� NQueen ȣ��
	�Ʒ��� ���� ������ ������� possible ���� ���� ������ ���� row�� NQueen, �ƴϸ� ���� col[row]�� ������ ����
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
