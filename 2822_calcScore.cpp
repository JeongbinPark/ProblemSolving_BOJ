#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int scores[8];
	for (int i = 0; i < 8; i++) cin >> scores[i];

	int questions[6];
	int index;
	int max;
	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		index = 0;
		max = scores[index];
		for (int j = 1; j < 8; j++)
			if (max < scores[j]) {
				max = scores[j];
				index = j;
			}
		questions[i] = index;
		sum += scores[index];
		scores[index] = -1;
	}
	sort(questions, questions+5);
	cout << sum << "\n";
	for (int i = 0; i < 5; i++)
		cout << questions[i]+1 << " ";

	return 0;

}