/* �ð� �ʰ�, erase�� insert�� O(N)�̱⶧���� ��ü O(N^2)�� ��.
#include <iostream>
#include <string>
using namespace std;

int main() {
	int t, curser;
	cin >> t;
	string str, result;
	while (t--) {
		result.clear();
		curser = 0;

		cin >> str;

		for (int i = 0; i<str.size(); i++) {
			if (str[i] == '<') {
				if (curser) curser--;
			}
			else if (str[i] == '>') {
				if (curser < result.size()) curser++;
			}
			else if (str[i] == '-') {
				if (curser) {
					curser--;
					result.erase(curser, 1);
				}
			}
			else {
				result.insert(result.begin()+curser, str[i]);
				curser++;
			}
		}
		cout << result << "\n";
	}

	return 0;
}
*/

//list(���߿��Ḯ��Ʈ)�� �̿��Ͽ� insert�� erase�� �������� ����, �����Ͽ� O(N) �� ��.
#include <iostream>
#include <list>
#include <string>
using namespace std;

int main() {
	list<char> l;
	list<char>::iterator curser;
	string str;
	int t;
	cin >> t;
	while (t--) {
		for (curser = l.begin(); !l.empty() && curser != l.end();)
			l.erase(curser++);
		cin >> str;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == '<') {
				if (curser!=l.begin()) curser--;
			}
			else if (str[i] == '>') {
				if (curser != l.end()) curser++;
			}
			else if (str[i] == '-') {
				if (curser!=l.begin())	curser = l.erase(--curser);
			}
			else {
				l.insert(curser, str[i]);
			}
		}
		for (curser = l.begin(); curser != l.end(); curser++)
			cout << *curser;
		cout << "\n";
	}
	return 0;
}