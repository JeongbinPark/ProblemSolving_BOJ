#include <iostream>
#include <algorithm>
using namespace std;

int l[3];

int main() {
	while (1) {
		for (int i = 0; i < 3; i++)
			cin >> l[i];
		if (!l[0] && !l[1] && !l[2]) break;
		sort(l, l + 3);
		if (l[2] * l[2] == l[1] * l[1] + l[0] * l[0]) cout << "right\n";
		else cout << "wrong\n";
	}
	return 0;
}