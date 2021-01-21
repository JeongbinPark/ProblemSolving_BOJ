/* 재귀이용
#include <iostream>
#include <algorithm>
using namespace std;

void HeapSort_push(int);
void HeapSort_push_sort(int);
void HeapSort_pop();
void HeapSort_pop_sort(int);

int N, op, arr_size;
int arr[100001] = { -1 };

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
	cin >> N;
	while (N--) {
		cin >> op;
		if (op) {
			HeapSort_push(op);
		}
		else {
			if (arr_size < 1) cout << 0 << "\n";
			else {
				cout << arr[1] << "\n";
				HeapSort_pop();
			}
		}
	}
	return 0;
}

void HeapSort_push(int v) {
	arr[++arr_size] = v;
	HeapSort_push_sort(arr_size);
}
void HeapSort_push_sort(int cur) {
	if (cur == 1) return;
	int parent = cur / 2;
	if (arr[parent] <= arr[cur]) return;
	swap(arr[parent], arr[cur]);
	HeapSort_push_sort(parent);
}
void HeapSort_pop() {
	arr[1] = arr[arr_size--];
	HeapSort_pop_sort(1);
};
void HeapSort_pop_sort(int cur) {
	int left = cur * 2 <= arr_size ? cur * 2 : -1;
	int right = cur * 2 + 1 <= arr_size ? cur * 2 + 1 : -1;

	if (left == -1 && right == -1) return;
	else if (right == -1) {
		if (arr[cur] <= arr[left]) return;
		swap(arr[cur], arr[left]);
		HeapSort_pop_sort(left);
	}
	else {
		int child = arr[left] < arr[right] ? left : right;
		if (arr[cur] <= arr[child]) return;
		swap(arr[cur], arr[child]);
		HeapSort_pop_sort(child);
	}
};
*/
/*
//while문 이용
#include <iostream>
#include <algorithm>
using namespace std;

void HeapSort_push(int);
void HeapSort_pop();

int N, op, arr_size;
int arr[100001] = { -1 };

int main() {
	cin >> N;
	while (N--) {
		cin >> op;
		if (op) {
			HeapSort_push(op);
		}
		else {
			if (arr_size < 1) cout << 0 << "\n";
			else {
				cout << arr[1] << "\n";
				HeapSort_pop();
			}
		}
	}
	return 0;
}

void HeapSort_push(int v) {
	arr[++arr_size] = v;

	int child = arr_size;
	int parent = child / 2;
	while (child > 1 && arr[parent] > arr[child]) {
		swap(arr[parent], arr[child]);
		child = parent;
		parent = child / 2;
	}
}
void HeapSort_pop() {
	arr[1] = arr[arr_size--];

	int parent = 1;
	int child = parent * 2;
	if (child + 1 <= arr_size) {
		child = (arr[child] < arr[child + 1]) ? child : child + 1;
	}

	while (child <= arr_size && arr[parent] > arr[child]) {
		swap(arr[parent], arr[child]);

		parent = child;
		child = child * 2;
		if (child + 1 <= arr_size) {
			child = (arr[child] < arr[child + 1]) ? child : child + 1;
		}
	}
}

*/
//priority queue 이용
#include <iostream>
#include <queue>
using namespace std;

int N, op;
priority_queue<int> pq;

int main() {
	cin >> N;
	while (N--) {
		cin >> op;
		if (op) pq.push(-op);
		else {
			if (pq.empty()) cout << 0 << "\n";
			else {
				cout << -pq.top() << "\n";
				pq.pop();
			}
		}
	}
	return 0;
}