/* 시간 초과 
단순 입력, 및 단순 비교
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N, M;
vector<string> sites, pws;
string site, pw;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> site >> pw;
		sites.push_back(site);
		pws.push_back(pw);
	}
	for (int i = 0; i < M; i++) {
		cin >> site;
		for (int i = 0; i < N; i++) {
			if (site.compare(sites[i]) == 0) {
				cout << pws[i] << "\n";
				break;
			}
		}
	}
	return 0;
}
*/

/*
O(nlogn)인 sort와 binary search를 통한 비교
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(pair<string, string>, pair<string, string>);

int N, M;
vector< pair<string, string> > password;
string site, pw;
int s, e, mid;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> site >> pw;
		password.push_back(make_pair(site, pw));
	}
	sort(password.begin(), password.end(), cmp);
	for (int i = 0; i < M; i++) {
		cin >> site;
		s = 0, e = N - 1;
		while (true) {
			mid = s + (e - s) / 2;
			if (password[mid].first.compare(site) < 0) s = mid + 1;
			else if (password[mid].first.compare(site) > 0) e = mid - 1;
			else break;
		}
		cout << password[mid].second << "\n";
	}

	return 0;
}

bool cmp(pair<string, string> p1, pair<string, string> p2) {
	return p1.first.compare(p2.first) < 0;
}
*/

//map 이용
#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string, string> pws;
string site, pw;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> site >> pw;
		pws.insert(make_pair(site, pw));
	}
	for (int i = 0; i < M; i++) {
		cin >> site;
		cout << pws[site] << "\n";
	}
	return 0;
}