/*
#include <iostream>
#include <queue>
#include <stack>
#define MOD 10000
using namespace std;

int T, A, B, num, tmp, idx ,mini = MOD;
queue< pair<int, stack<char> > > q;
bool visited[MOD];
char a_dslr[MOD];

int main() {
	cin >> T;
	while (T--) {
		cin >> A >> B;
		stack<char>	s_dslr;
		q.push(make_pair(A, s_dslr));
		visited[A] = true;
		while (!q.empty()) {
			num = q.front().first;
			s_dslr = q.front().second;
			q.pop();

			if (num == B) {
				mini = (int)s_dslr.size();
				for (int i = 0; i < mini; i++) {
					a_dslr[i] = s_dslr.top();
					s_dslr.pop();
				}
				break;
			}

			idx = num * 2 % MOD;
			if (!visited[idx]) {
				s_dslr.push('D');
				q.push(make_pair(idx, s_dslr));
				visited[idx];
				s_dslr.pop();
			}

			idx = (MOD + num - 1) % MOD;
			if (!visited[idx]) {
				s_dslr.push('S');
				q.push(make_pair(idx, s_dslr));
				visited[idx];
				s_dslr.pop();
			}

			tmp = num * 10;
			idx = tmp % MOD + tmp / MOD;
			if (!visited[idx]) {
				s_dslr.push('L');
				q.push(make_pair(idx, s_dslr));
				visited[idx];
				s_dslr.pop();
			}

			tmp = num % 10;
			idx = num / 10 + tmp * 1000;
			if (!visited[idx]) {
				s_dslr.push('R');
				q.push(make_pair(idx, s_dslr));
				visited[idx];
				s_dslr.pop();
			}
		}
		while (!q.empty()) q.pop();
		for (int i = 0; i < mini; i++)
			cout << a_dslr[i];
		cout << "\n";
	}
	return 0;
}
*/
/* string사용으로 인한 메모리초과로 의심됨
#include <iostream>
#include <queue>
#include <string>
#define MOD 10000
using namespace std;

int T, A, B, num, tmp, idx, mini = MOD;
queue< pair<int, string> > q;
bool visited[MOD];

int main() {
	cin >> T;
	while (T--) {
		cin >> A >> B;
		fill(visited, visited + MOD, false);
		string s;
		q.push(make_pair(A, s));
		visited[A] = true;
		while (!q.empty()) {
			num = q.front().first;

			if (num == B) break;
			
			idx = num * 2 % MOD;
			if (!visited[idx]) {
				q.front().second += 'D';
				q.push(make_pair(idx, q.front().second));
				visited[idx];
				q.front().second.erase((int) q.front().second.size() - 1, 1);
			}

			idx = (MOD + num - 1) % MOD;
			if (!visited[idx]) {
				q.front().second += 'S';
				q.push(make_pair(idx, q.front().second));
				visited[idx];
				q.front().second.erase((int)q.front().second.size() - 1, 1);
			}

			tmp = num * 10;
			idx = tmp % MOD + tmp / MOD;
			if (!visited[idx]) {
				q.front().second += 'L';
				q.push(make_pair(idx, q.front().second));
				visited[idx];
				q.front().second.erase((int)q.front().second.size() - 1, 1);
			}

			tmp = num % 10;
			idx = num / 10 + tmp * 1000;
			if (!visited[idx]) {
				q.front().second += 'R';
				q.push(make_pair(idx, q.front().second));
				visited[idx];
				q.front().second.erase((int)q.front().second.size() - 1, 1);
			}

			q.pop();
		}
		cout << q.front().second << "\n";
		while (!q.empty()) q.pop();
	}
	return 0;
}
*/
//역추적방법
#include <iostream>
#include <queue>
#include <stack>
#include <cstring>
#define MOD 10000
using namespace std;

int T, A, B, num, tmp, idx, mini = MOD;
char dslr[MOD];
int parent[MOD];
queue<int> q;
bool visited[MOD];
stack<char> s;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		cin >> A >> B;
		memset(visited, 0, MOD);
		memset(dslr, 0, MOD);
		memset(parent, 0, MOD);
		q.push(A);
		visited[A] = true;
		while (!q.empty()) {
			num = q.front();
			q.pop();

			if (num == B) break;

			idx = num * 2 % MOD;
			if (!visited[idx]) {
				dslr[idx] = 'D';
				parent[idx] = num;
				q.push(idx);
				visited[idx] = true;
			}

			idx = (MOD + num - 1) % MOD;
			if (!visited[idx]) {
				dslr[idx] = 'S';
				parent[idx] = num;
				q.push(idx);
				visited[idx] = true;
			}

			tmp = num * 10;
			idx = tmp % MOD + tmp / MOD;
			if (!visited[idx]) {
				dslr[idx] = 'L';
				parent[idx] = num;
				q.push(idx);
				visited[idx] = true;
			}

			tmp = num % 10;
			idx = num / 10 + tmp * 1000;
			if (!visited[idx]) {
				dslr[idx] = 'R';
				parent[idx] = num;
				q.push(idx);
				visited[idx] = true;
			}
		}
		while (!q.empty()) q.pop();
		while (A != B) {
			s.push(dslr[B]);
			B = parent[B];
		}
		while(!s.empty()){
			cout << s.top();
			s.pop();
		}
		cout << "\n";
	}
	return 0;
}