#include <iostream>
using namespace std;

int mod = 1000000;
int p = mod / 10 * 15;
int fibo_pisa[1500001] = { 0, 1 };

int main() {
	long long N;
	cin >> N;
	for (int i = 2; i < p; i++) {
		fibo_pisa[i] = fibo_pisa[i - 1] + fibo_pisa[i - 2];
		fibo_pisa[i] %= mod;
	}
	cout << fibo_pisa[N%p];
	return 0;
}
//�ǻ�� �ֱ� �̿�
//N��° �Ǻ���ġ ���� M���� ���� ��������
//N%P��° �Ǻ���ġ ���� M���� ���� �������� ����
//�̶�, �ֱ� P�� 
//n>2�϶� M=10^n�̸�, P = 10^(n-1)*15
