/* 시간 초과 O(N^2) 인듯?
#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, h, top;
	cin >> N;
	
	int result[5001], s[5001];
	s[0] = 100000001;
	for (int i = 1; i <= N; i++)
	{
		cin >> h;
		s[i] = h;
		top = i;
		while (--top >= 0 && h > s[top]);
		result[i] = top;
	}


	for (int i = 1; i <= N; i++)
		cout << result[i] << " ";
	return 0;
}
*/

// 스택 이용하여서 가장 큰 값의 위치 ~ 현재 위치 사이 타워는 무시(pop)하는 방법
#include <iostream>
#include <stack>
#include <utility>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int N, h;
	cin >> N;
	stack< pair<int, int> > s;
	
	for(int i = 0; i < N; i++) {
		cin >> h;
		while (!s.empty() && s.top().second < h) s.pop();
		cout << (s.empty() ? 0 : s.top().first + 1) << " ";
		s.push(make_pair(i, h));
	}
	return 0;
}
