/* 문제 이해 잘못함
#include <iostream>
#include <string>
using namespace std;

int main() {
	int N, k=-1;
	cin >> N;
	for (int i = 1; i < 14; i++)
		if (2 * N == (i*i + i)) {
			k = i;
			break;
		}
	if (k == -1) {
		cout << k;
		return 0;
	}

	string str = "";
	for (int i = 0; i < k; i++) {
		str += 'A' + i;
	}
	for (int i = 0; i < k; i++) {
		for (int j = i; j > 0; j--) {
			str+='A' + i;
		}
	}

	cout << str;
	
	return 0;
}
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool findIndexes(int, int);

int N, num;
int indexes[100] = { 0 };

int main() {
	cin >> N;
	if (!findIndexes(1, 0)) cout << -1;
	else {
		//indexes에서 -1 한만큼 string 세팅
		string str = "";
		for (int i = 1; i <= num; i++)
			for (int j = 0; j < indexes[i] - 1; j++)
				str += 'A' + i - 1;

		//insert함수로 최종 문자열 완성
		for (int i = 1; i < num; i++)
			str.insert(indexes[i] - 1, 1, 'A' + i - 1);

		cout << str;
	}
	return 0;
}
bool findIndexes(int level, int sum) {
	if (sum > N) return false;
	if (sum == N) {
		num = level;
		return true;
	}
	for (int i = sum + 1; i > indexes[level - 1]; i--)
	{
		indexes[level] = i;
		if(findIndexes(level + 1, sum + i)) return true;
	}
	return false;
}