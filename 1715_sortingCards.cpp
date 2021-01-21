/* �������� �̿��ؼ� �� ī���� ������ �ּҰ� �� �� �ְ� Ʈ�� ����.
�׷��� �� ���鿡 Ʈ�� ���̸�ŭ ���ؼ� ����

�ٵ� �� Ʋ��?

�ش� ���� �� / 2�� ���� ������, ������ �ش� �ε��� -1�� �������� �ڽ� ��� ������(�̶� �ش� ���� ���� ������ ������ - ������ ������)
���� ������, �������� ������ Ʈ�� ���� ����(�ڵ忡���� ���Ǹ� ���� [������, ������)���� �ξ� ������ +1 �� ���� ���ƾ� ��)


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void checkTimes(int, int, int);

int N, deck, sum;
int times[100001], prefixSum[100001];
vector<int> cards;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> deck;
		cards.push_back(deck);
	}
	sort(cards.begin(), cards.end());
	prefixSum[0] = cards[0];
	for (int i = 1; i < N; i++) {
		prefixSum[i] = prefixSum[i - 1] + cards[i];
	}
	checkTimes(0, N, 0);

	for (int i = 0; i < N; i++) {
		sum += cards[i] * times[i];
	}
	cout << sum;
	return 0;
}

void checkTimes(int idx_s, int idx_e, int t) {
	if (idx_s + 1 == idx_e) {
		times[idx_s] = t;
		return;
	}
	int s = (prefixSum[idx_e - 1] - prefixSum[idx_s]) / 2 + prefixSum[idx_s];
	int next_idx = lower_bound(prefixSum + idx_s, prefixSum + idx_e, s)  - prefixSum;
	if (prefixSum[next_idx] > s) next_idx--;
	checkTimes(idx_s, next_idx + 1, t + 1);
	checkTimes(next_idx + 1, idx_e, t + 1);
}
*/

#include <iostream>
#include <queue>
using namespace std;

int N, cards, sum, a, b;
priority_queue<int> pq;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N;
	while (N--) {
		cin >> cards;
		pq.push(-cards);
	}
	while (pq.size() > 1) {
		a = -pq.top();
		pq.pop();
		b = -pq.top();
		pq.pop();

		sum += a + b;
		pq.push(-(a + b));
	}
	cout << sum;
	return 0;
}