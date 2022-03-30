#include <iostream>
#include <algorithm>
using namespace std;

int findHighest(int start, int end);

int H, W;
int block[502];
int resultSum = 0;

int main() {
	cin >> H >> W;
	for (int i = 1; i <= W; i++) {
		cin >> block[i];
	}
	cout << findHighest(0, W + 1);
	return 0;
}

int findHighest(int start, int end) {
 	if(start + 1 >= end)
		return 0;
	if (start != 0 && end != W + 1) {
		int sum = 0;
		int waterHeight = min(block[start], block[end]);
		for (int i = start + 1; i < end; i++) {
			sum += waterHeight - block[i];
		}
		return sum;
	}

	int highestIndex = -1;
	if (start == 0) {
		highestIndex = start;
		for (int i = start + 1; i < end; i++) {
			if (block[highestIndex] < block[i]) {
				highestIndex = i;
			}
		}
	}
	else {
		highestIndex = end;
		for (int i = end - 1; i > start; i--) {
			if (block[highestIndex] < block[i]) {
				highestIndex = i;
			}
		}
	}
	int sum = 0;
	if(block[highestIndex]) sum += findHighest(start, highestIndex);
	if(block[highestIndex]) sum += findHighest(highestIndex, end);
	return sum;
}