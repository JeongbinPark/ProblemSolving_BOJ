#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, last, box;
vector<int> boxes;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> box;
		int index = lower_bound(boxes.begin(), boxes.end(), box) - boxes.begin();
		if(index < (int) boxes.size()) boxes[index] = box;
		else boxes.push_back(box);
	}
	cout << (int)boxes.size();
	return 0;
}

