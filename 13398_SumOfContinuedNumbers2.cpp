/* 틀림.. 3 9 -1 9 했을때 18 나와야하는데 17나옴
#include <iostream>
#include <algorithm>
using namespace std;

int n, num, sum, preSum, max_sum, result;
bool flag;

int main() {
	cin >> n;
	cin >> num;
	result = num;
	sum = num < 0 ? 0 : num;

	for(int i = 1; i < n; i++){
		cin >> num;
		sum += num;
		result = max(preSum + sum, result);
		if (sum <= 0) {
			preSum = sum - num;
			sum = 0;
			flag = true;
		}
	}
	cout << result;
	return 0;
}
*/
#include <iostream>
#include <algorithm>
using namespace std;

int n, num, sum_RemovedOne, sum_Original, result;

int main() {
	cin >> n;
	cin >> num;
	sum_RemovedOne = sum_Original = num;
	result = num;
	for (int i = 1; i < n; i++) {
		cin >> num;
		sum_RemovedOne = num < 0 ? max(sum_Original, sum_RemovedOne + num) : sum_RemovedOne + num;
		sum_Original = sum_Original < 0 ? num : sum_Original + num;
		result = max(result, max( sum_Original, sum_RemovedOne));
	}
	cout << result;
	return 0;
}

/*이거 위에랑 똑같음.... ㅜㅜ 멍청이
#include <iostream>
#include <algorithm>
using namespace std;

int n, num, sum_RemovedOne, sum_Original, result;

int main() {
	cin >> n;
	cin >> num;
	sum_RemovedOne = sum_Original = num;
	result = num;
	for (int i = 1; i < n; i++) {
		cin >> num;
		sum_RemovedOne = max(sum_Original, sum_RemovedOne + num);
		sum_Original = max(num , sum_Original + num);
		result = max(result, max(sum_Original, sum_RemovedOne));
	}
	cout << result;
	return 0;
}
*/