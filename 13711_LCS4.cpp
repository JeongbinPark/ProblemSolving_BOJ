/* 당연히 시간초과지 n 최대가 100000인데 n^2 이면 
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
char c;
string str1, str2;
int pre[100001], curr[100001];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> c;
		str1 += c;
	}
	for (int i = 0; i < n; i++) {
		cin >> c;
		str2 += c;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (str1[i - 1] == str2[j - 1]) curr[j] = pre[j - 1] + 1;
			else curr[j] = max(curr[j - 1], pre[j]);
		}
		memcpy(pre, curr, sizeof(curr));
	}
	cout << curr[n];
	return 0;
}
*/

#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int n, tmp, cnt;
map<int, int> m;
int numbers[100001], lis[100001];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		m.insert(make_pair(tmp, i));
	}
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		numbers[m[tmp]] = i;
	}
	lis[0] = numbers[0];
	cnt++;
	for (int i = 1; i < n; i++) {
		tmp = numbers[i];
		if (tmp > lis[cnt - 1]) lis[cnt++] = tmp;
		else lis[lower_bound(lis, lis + cnt, tmp) - lis] = tmp;
	}
	cout << cnt;
	return 0;
}