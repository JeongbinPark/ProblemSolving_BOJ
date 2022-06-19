#include <iostream>
#include <algorithm>
using namespace std;

int N, K, num;
int frame[20];
int counts[101], time[101];

int main() {
	int maxFrameIndex = 0;
	cin >> N >> K;
	for(int i = 0; i < K; i++) {
		int frameIndex = -1;
		bool sameStudent = false;
		int minCount = 1001;
		int minTime = 1001;

		cin >> num;
		for (int j = 0; j < N; j++) {
			int student = frame[j];
			if (student == num) {
				frameIndex = j;
				sameStudent = true;
				break;
			}
			if (minCount > counts[student]) {
				minCount = counts[student];
				minTime = time[student];
				frameIndex = j;
			}
			else if (minCount == counts[student]) {
				if (minTime > time[student]) {
					minTime = time[student];
					frameIndex = j;
				}
			}
		}

		int student = frame[frameIndex];
		if (sameStudent) {
			counts[student]++;
		}
		else {
			counts[student] = 0;
			frame[frameIndex] = num;
			counts[num] = 1;
			time[num] = i;
			maxFrameIndex = max(maxFrameIndex, frameIndex);
		}
	};
	sort(frame, frame + maxFrameIndex + 1);
	for (int i = 0; i < maxFrameIndex + 1; i++) {
		cout << frame[i] << " ";
	}
	return 0;
}