/*
메모리 초과
#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	int N, k;
	cin >> N >> k;
	for (int i = 1; i <= N; i++)
		str += to_string(i);
	if (str.size() < k) cout << -1;
	else cout << str[k - 1];
	return 0;
}

*/

/* 시간 초과
#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	int N, k;
	cin >> N >> k;
	for (int i = 1; i <= N; i++)
	{
		str = to_string(i);
		for (int j = 0; j < str.size(); j++)
		{
			if (!--k) {
				cout << str[j];
				return 0;
			}
		}
	}
	cout << -1;
	return 0;
}

*/

//숫자 범위 잘 생각해서 데이터 타입 결정


#include <iostream>
#include <string>
using namespace std;

int main() {
	int N, k;
	cin >> N >> k;
	int level = 0;
	long long n = 1, sum = 0;
	while (1) {
		level++;
		if (k <= sum + 9 * n * level) break;
		sum += 9 * n * level;
		n *= 10;
	}
	int m = (k - sum - 1) / level;

	string str = to_string(n + m);
	if (n + m > N) cout << -1;
	else cout << str[k - sum - 1 - level * m];
	return 0;
}