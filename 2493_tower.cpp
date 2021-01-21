/* �ð� �ʰ� O(N^2) �ε�?
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

// ���� �̿��Ͽ��� ���� ū ���� ��ġ ~ ���� ��ġ ���� Ÿ���� ����(pop)�ϴ� ���
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
