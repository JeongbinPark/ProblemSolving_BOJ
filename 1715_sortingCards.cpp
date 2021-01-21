/* 구간합을 이용해서 각 카드의 값들이 최소가 될 수 있게 트리 만듦.
그래서 각 값들에 트리 높이만큼 곱해서 더함

근데 왜 틀림?

해당 구간 합 / 2와 같은 구간합, 없으면 해당 인덱스 -1을 기준으로 자식 노드 나누기(이때 해당 구간 합은 종료점 구간합 - 시작점 구간합)
구간 시작점, 종료점이 같으면 트리 높이 저장(코드에서는 편의를 위해 [시작점, 종료점)으로 두어 시작점 +1 한 값과 같아야 함)


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