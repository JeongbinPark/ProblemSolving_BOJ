/* 시간초과... 
#include <iostream>
#include <set>
using namespace std;

int N, num, cnt;
set<int> one, two;
set<int>::iterator iter1, iter2;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	cin >> num;
	one.insert(num);
	two.insert(2 * num);
	while (--N) {
		cin >> num;
		for (iter1 = one.begin(); iter1 != one.end(); iter1++) {
			iter2 = two.find(num + *iter1);
			if (iter2 != two.end()) {
				cnt++;
				break;
			}
		}

		one.insert(num);
		for (iter1 = one.begin(); iter1 != one.end(); iter1++)
			two.insert(*iter1 + num);
	}
	cout << cnt;
	return 0;
}
*/
/* 틀림
#include <iostream>
#include <set>
using namespace std;

int N, num, cnt;
set<int> one, two;
set<int>::iterator iter1, iter2;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	cin >> num;
	one.insert(num);
	two.insert(2 * num);
	while (--N) {
		cin >> num;
		for (iter1 = one.begin(); iter1 != one.end(); iter1++) {
			iter2 = two.find(num + *iter1);
			if (iter2 != two.end()) {
				cnt++;
				break;
			}
		}

		one.insert(num);
		for (iter1 = one.begin(); iter1 != one.end(); iter1++)
			two.insert(*iter1 + num);
	}
	cout << cnt;
	return 0;
}
*/

#include<iostream>
using namespace std;

int n, num, cnt;
int one[5001];
bool two[400001];

int main() {
	cin >> n;
	cin >> num;
	one[0] = num;
	two[2 * num + 200000] = true;
	for (int i = 1; i < n; i++) {
		cin >> one[i];
		for (int j = 0; j < i; j++) {
			if (two[one[i] - one[j] + 200000]) {
				cnt++;
				break;
			}
		}
		for (int j = 0; j <= i; j++)
			two[one[j] + one[i] + 200000] = true;
	}
	cout << cnt;
	return 0;
}

//a+b = d-k 