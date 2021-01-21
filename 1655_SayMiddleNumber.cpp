/* 이 방법은 이전 데이터를 삭제하기 때문에 완전히 틀린 방법임!
#include <iostream>
#include <algorithm>
using namespace std;

int N, tmp;
int numbers[3];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N;
	cin >> numbers[0];
	cout << numbers[0] << "\n";
	for (int i = 0; i < (N-1) / 2; i++) {
		cin >> numbers[1];
		if (numbers[0] > numbers[1]) swap(numbers[0], numbers[1]);
		cout << numbers[0] << "\n";
		cin >> numbers[2];
		if (numbers[0] > numbers[2]) swap(numbers[0], numbers[2]);
		tmp = numbers[1] < numbers[2] ? numbers[1] : numbers[2];
		cout << tmp << "\n";
		numbers[0] = tmp;
	}
	if ((N-1) % 2) {
		cin >> numbers[1];
		if (numbers[0] > numbers[1]) swap(numbers[0], numbers[1]);
		cout << numbers[0] << "\n";
	}
	return 0;
}
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, num, middle;
vector<int> v;
priority_queue<int> small, large;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N;
	cin >> num;
	middle = num;
	cout << middle << "\n";
	if (N >= 2) {
		cin >> num;
		if (middle > num) {
			large.push(-middle);
			middle = num;
		}
		else large.push(-num);
		cout << middle << "\n";
	}
	if (N >= 3) {
		cin >> num;
		v.push_back(num);
		v.push_back(middle);
		v.push_back(-large.top());
		large.pop();
		sort(v.begin(), v.end());
		small.push(v[0]);
		middle = v[1];
		large.push(-v[2]);
		cout << middle << "\n";
	}
	for (int i = 4; i <= N; i++) {
		cin >> num;
		v.clear();
		v.push_back(num);
		v.push_back(middle);
		v.push_back(-large.top());
		large.pop();
		v.push_back(small.top());
		small.pop();
		sort(v.begin(), v.end());
		if (i % 2) {
			small.push(v[0]);
			small.push(v[1]);
			middle = v[2];
			large.push(-v[3]);
		}
		else {
			small.push(v[0]);
			middle = v[1];
			large.push(-v[2]);
			large.push(-v[3]);
		}
		cout << middle << "\n";
	}
	return 0;
}
/* 참고 코드
#include <stdio.h>
int n, size = 32768;
int tre[70000], i;

void up(int x) {
	while (x>0) {
		tre[x]++;
		x /= 2;
	}
}
void find() {
	int f = i / 2, p = 1;
	if (i % 2)f++;
	while (p<size) {
		p *= 2;
		if (tre[p]<f) { f -= tre[p]; p++; }
	}printf("%d\n", p - size - 10000);
}
int main() {
	scanf("%d", &n);
	int in;
	for (i = 1; i <= n; i++) {
		scanf("%d", &in);
		in += 10000 + size;
		up(in);
		find();
	}

	return 0;
}


#include <stdio.h>
int n, x;
int t[1 << 16];
void push(int x)
{
	x += (1 << 15) + 10000;
	while (x)
	{
		t[x]++;
		x /= 2;
	}
}
int pop(int p, int x)
{
	if (p >= (1 << 15))return p - (1 << 15) - 10000;
	if (t[2 * p] < x)return pop(2 * p + 1, x - t[2 * p]);
	else return pop(2 * p, x);
}
int main(void)
{
	scanf("%d", &n);
	for (int i = 2; i < n + 2; i++)
	{
		scanf("%d", &x);
		push(x);
		printf("%d\n", pop(1, i / 2));
	}
	return 0;
}

#include<stdio.h>
int N, size;
int tree[100000];
void input(int n) {
	int X = size + n - 1;
	while (X>0) {
		tree[X]++; X /= 2;
	}
}
int search(int n) {
	int X = 1;
	for (;;) {
		if (X >= size) break;
		if (tree[2 * X] >= n)X = X * 2;
		else { n -= tree[2 * X]; X = X * 2 + 1; }
	}
	return (X - size + 1);
}
int main() {
	int i, j, in;
	scanf("%d", &N);
	for (size = 1; size<30000; size *= 2);
	for (i = 1; i <= N; i++) {
		scanf("%d", &in); input(in + 15000);
		if (i % 2 == 0) printf("%d\n", search(i / 2) - 15000);
		else printf("%d\n", search(i / 2 + 1) - 15000);
	} return 0;
}
*/