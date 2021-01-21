/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int work(int);

int N, tmp1, tmp2, time;
int times[10001];
vector<int> pre[10001];
bool visited[10001];

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> times[i] >> tmp1;
		while (tmp1--) {
			cin >> tmp2;
			pre[i].push_back(tmp2);
		}
	}
	for (int i = N; i; i--) {
		if (!visited[i]) {
			time = max(time, work(i));
		}
	}
	cout << time;
	return 0;
}
int work(int n) {
	int maxi = 0;
	if (visited[n]) return times[n];
	for (int i = 0; i < (int)pre[n].size(); i++) {
		maxi = max(maxi, work(pre[n][i]));
	}
	visited[n] = true;
	maxi += times[n];
	times[n] = maxi;
	return maxi;
}

*/
/*
선행 작업이 1 ~ K-1 중 있기때문에 가능
#include<cstdio>

int N;
int d[10001];
int main(void) {
	scanf("%d", &N);
	int max = -1;
	for (int i = 1; i <= N; i++) {
		int t, n;
		scanf("%d %d", &t, &n);
		while (n--) {
			int f;
			scanf("%d", &f);
			d[i] = d[f] > d[i] ? d[f] : d[i];
		}
		d[i] += t;
		max = max < d[i] ? d[i] : max;
	}
	printf("%d\n", max);

	return 0;
}
*/

#include <iostream>
#include <algorithm>
using namespace std;

int N, tmp1, tmp2, time, maxi;
int times[10001];

int main() {
	cin >> N;
	for(int i = 1; i <= N; i++) {
		cin >> times[i] >> tmp1;
		time = 0;
		while (tmp1--) {
			cin >> tmp2;
			time = max(time, times[tmp2]);
		}
		times[i] += time;
		maxi = max(maxi, times[i]);
	}
	cout << maxi;
	return 0;
}