/*
예외
6 2
436436

#include <iostream>
#include <vector>
#include <algorithm>
#define INF 500001
using namespace std;

int N, K, k, numbers[500001];
char c;
vector<pair<int, int> > v;

int main() {
	cin >> N >> K;
	k = K;
	for (int i = 0; i < N; i++) {
		cin >> c;
		v.push_back(make_pair(c - '0', i));
		numbers[i] = c - '0';
		if (k && numbers[i] >= numbers[i - 1]) {
			numbers[i - 1] = -1;
			k--;
		}
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < N; i++) {
		if (!k) break;
		if (numbers[v[i].first] == -1) continue;
		numbers[v[i].second] = -1;
		k--;
	}
	for (int i = 0; i < N; i++) {
		if (numbers[i] != -1) cout << numbers[i];
	}
	return 0;
}
*/

#include <iostream>
using namespace std;

int N, K, numbers[500002] = {10}, p1, p2 = 1;
char c;

int main() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> c;
		numbers[i] = c - '0';
	}
	numbers[N + 1] = 10;
	while (K){
		if (numbers[p1] < numbers[p2]) {
			numbers[p1] = -1;
			while (numbers[p1] == -1) p1--;
			K--;
		}
		else {
			p1 = p2;
			p2++;
		}
	}
	for (int i = 1; i <= N; i++) {
		if (numbers[i] != -1) cout << numbers[i];
	}

	return 0;
}
/*
아에 string을 바꾸는 법도 있음.

#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	string str;
	int top = -1;
	cin >> str;

	for (int i = 0; i < n; i++)
	{
		while (k && top >= 0 && str[top] < str[i])
		{
			top--;
			k--;
		}
		str[++top] = str[i];
	}
	str[++top - k] = '\0';
	cout << str;

	return 0;
}
*/