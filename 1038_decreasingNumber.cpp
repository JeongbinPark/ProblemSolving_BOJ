/* 
시간 너무 오래 걸림
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <cstdlib>
using namespace std;

int N, num;
map<int, int> decreasing;
string number, tmp;

int main() {
	cin >> N;
	if (N < 10) {
		cout << N;
		return 0;
	}
	N -= 9;
	for (num = 0; num < 10; num++)
		decreasing[num] = 1;
	while (true) {
		number = to_string(num);
		tmp = "";
		bool flag = false;
		for (int i = 1; i < (int)number.size(); i++) {
			if (!flag && number[i] != '0') { flag = true; }
			if (flag) tmp += number[i];
		}
		if (tmp == "")tmp = "0";
		if (num >209)
			cout << "";
		if (number[0] > number[1] && ((int)number.size()  == 2 || (int) number.size() == (int) tmp.size() + 1) && decreasing[stoi(tmp)]) {
			if (N == 1) {
				cout << num;
				return 0;
			}
			else {
				decreasing[num]++;
				N--;
			}
		}
		num++;
	}
	return 0;
}
*/
/*
//c++11이상
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

int N;
char c;
vector<pair<int, string> > pre, curr;
string num;

int main() {
	cin >> N;
	if (N < 10) {
		cout << N;
		return 0;
	}
	N -= 9;
	for (int i = 0; i < 10; i++) {
		pre.push_back(make_pair(i, to_string(i)));
	}
	while (true) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < (int)pre.size(); j++) {
				if (i > pre[j].first) {
					N--;
					c = '0' + i;
					num = c;
					num += pre[j].second;
					curr.push_back(make_pair(i, num));
					if (N == 0) {
						cout << i << pre[j].second;
						return 0;
					}
					if (num == "9876543210" && N > 0) {
						cout << -1;
						return 0;
					}
				}
				else break;
			}
		}
		pre.resize((int)curr.size());
		copy(curr.begin(), curr.end(), pre.begin());
		curr.clear();
	}
	return 0;
}
*/
/* 참고 코드
#include<iostream>
using namespace std;
int i = 10, k, l, m = 10;
long long a[1023] = { 0,1,2,3,4,5,6,7,8,9, }, t = 10;
int main() {
	for (; i != k; m = i)
		for (; k != m; k++)
			for (l = 0; l<a[k] % 10; l++)
				a[i++] = a[k] * t + l;
	cin >> i;
	if (i<1023)cout << a[i];
	else cout << "-1";
}
*/
/*
#include <cstdio>

int n;
int arr[40];
bool find(int left, int last) {
	if (left == 0) return (n--) == 0;
	for (int i = 0; i < last; i++) {
		if (find(left - 1, i)) {
			arr[left] = i; return true;
		}
	}
	return false;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= 10; i++) {
		if (find(i, 10)) {
			for (int j = i; j > 0; j--) printf("%d", arr[j]);
			puts("");
			return 0;
		}
	}
	puts("-1");	return 0;
}
*/

