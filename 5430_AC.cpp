#include <iostream>
#include <string>
#include <deque>
#include <sstream>
using namespace std;

int T;
string func, arr;
int n;

int main() {
	cin >> T;
	while (T--) {
		deque<string> nums;

		cin >> func;
		cin >> n;
		cin >> arr;
		arr.erase(arr.end() - 1);
		arr.erase(arr.begin());

		stringstream sstream(arr);
		string num;
		while (getline(sstream, num, ',')) nums.push_back(num);


		bool isFront = true;
		bool isError = false;
		for (int i = 0; i < (int)func.length(); i++) {
			char cmd = func[i];
			if (cmd == 'R') isFront = !isFront;
			else if (cmd == 'D') {
				if ((int)nums.size() == 0) {
					isError = true;
					break;
				}
				if (isFront)nums.pop_front();
				else nums.pop_back();
			}
		}


		if (isError) {
			cout << "error\n";
		}
		else {
			cout << "[";
			if (isFront) {
				for (int i = 0; i < (int)nums.size(); i++) {
					cout << nums[i];
					if (i != (int)nums.size() - 1) cout << ",";
				}
			} else {
				for (int i = (int)nums.size() - 1; i >= 0; i--) {
					cout << nums[i];
					if (i != 0) cout << ",";
				}
			}
			cout << "]\n";
		}
	}
	return 0;
}