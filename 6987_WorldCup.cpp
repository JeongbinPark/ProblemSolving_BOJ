/* ���º� ��꿡�� Ʋ��
���ºΰ� ���� 0 0 0 1 1 2�� ��� ��� �Ǿ���ϴµ�
�Ʒ� �ڵ忡���� 2�� ��� �ȵ�.
�ᱹ ���º� ���ؼ� backtracking �ؾ���
��<6, ��<6, ��<6
�� + �� + �� == 5
���� == ����
���� = 0, �̶�, ���� �߰ߵǸ� flag�� +, -;
#include <iostream>
using namespace std;

int main() {
	int w, d, l, w_s, d_s, l_s;
	int flag = 1;
	bool result;
	for (int i = 0; i < 4; i++) {
		result = true;
		w_s = d_s = l_s = 0;
		for (int j = 0; j < 6; j++) {
			cin >> w >> d >> l;
			if (w > 5 || d > 5 || l > 5 || w + d + l != 5)
				result = false;
			if(d) flag *= -1;
			w_s += w, d_s += flag * d, l_s += l;
		}
		if (w_s != l_s || d_s) result = false;
		cout << ( result ? 1 : 0 ) << " ";
	}
	return 0;
}
*/

// backtracking

#include <iostream>
#include <string.h>
using namespace std;

bool find(int);

int table[6][3], tmp[6][3];
bool result;
int main() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 6; j++)
			memset(tmp[j], 0, sizeof(int)*3);
		for (int j = 0; j < 6; j++) {
			cin >> table[j][0] >> table[j][1] >> table[j][2];
		}
		cout << (find(0) ? 1 : 0) << " ";
	}
	return 0;
}

int team1[] = { 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 3, 3, 4 };
int team2[] = { 1, 2, 3, 4, 5, 2, 3, 4, 5, 3, 4, 5, 4, 5, 5 };

bool find(int game) {
	if (game == 15) {
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 3; j++)
				if (table[i][j] != tmp[i][j]) {
					return false;
				}
		}
		return true;
	}
	tmp[team1[game]][0]++, tmp[team2[game]][2]++;
	if(find(game + 1)) return true;
	tmp[team1[game]][0]--, tmp[team2[game]][2]--;

	tmp[team1[game]][1]++, tmp[team2[game]][1]++;
	if (find(game + 1)) return true;
	tmp[team1[game]][1]--, tmp[team2[game]][1]--;

	tmp[team1[game]][2]++, tmp[team2[game]][0]++;
	if (find(game + 1)) return true;
	tmp[team1[game]][2]--, tmp[team2[game]][0]--;

	return false;
}
