/* ���� ��ģ���� ���� 1�� ���� �̿�, ó���� int������ �����Ͽ� �����÷ο��.
#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<long long> pinary;
	vector<long long> one;
	pinary.push_back(1);
	one.push_back(1);
	int N;
	cin >> N;
	for (long long i = 1; i < N; i++)
	{
		pinary.push_back(2 * pinary[i-1] - one[i-1]);
		one.push_back(pinary[i - 1] - one[i - 1]);
	}
	cout << pinary.back();
	return 0;
}
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<long long> pinary;
	vector<long long> one;
	pinary.push_back(1);
	one.push_back(1);
	int N;
	cin >> N;
	for (long long i = 1; i < N; i++)
	{
		pinary.push_back(2 * pinary[i - 1] - one[i - 1]);
		one.push_back(pinary[i - 1] - one[i - 1]);
	}
	cout << pinary.back();
	return 0;
}

/*
��������� �� ������ �Ǻ���ġ ������.

#include <iostream>
using namespace std;

int main() {
	long long fibo[91];
	int N;
	cin >> N;
	fibo[1] = fibo[2] = 1;
	for (int i = 3; i <= N; i++)
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	cout << fibo[N];
	return 0;
}

���� �ڵ�, �̷��Ե� �ۼ��� �� ����!

#include<iostream>
int n, m; 
long long a, b; 
int main() { 
	std::cin >> n;
	m = (n - 1) / 2;
	for (a = b = 1; m--; a += b, b += a);
	std::cout << (n % 2 ? a : b);
}

#include <iostream>
long long n, a, b = 1;
int main(){
    std::cin >> n;
    while( n-- ){
        a += b;
        b = a - b;
    }
    std::cout << a;
}
*/