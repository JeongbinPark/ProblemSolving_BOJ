#include <iostream>
#include <cstring>
using namespace std;

void print_preorder(int);
void print_inorder(int);
void print_postorder(int);

int N;
char p, c1, c2;
int children[27][2];

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> p >> c1 >> c2;
		int p_idx = p - 'A';
		children[p_idx][0] = c1 - 'A';
		children[p_idx][1] = c2 - 'A';
	}

	print_preorder(0);
	cout << "\n";
	print_inorder(0);
	cout << "\n";
	print_postorder(0);
	return 0;
}

void print_preorder(int n) {
	cout << (char)('A' + n);
	if (children[n][0] > 0) print_preorder(children[n][0]);
	if (children[n][1] > 0) print_preorder(children[n][1]);
	return;
}

void print_inorder(int n) {
	if (children[n][0] > 0) print_inorder(children[n][0]);
	cout << (char)('A' + n);
	if (children[n][1] > 0) print_inorder(children[n][1]);
	return;
}

void print_postorder(int n) {
	if (children[n][0] > 0) print_postorder(children[n][0]);
	if (children[n][1] > 0) print_postorder(children[n][1]);
	cout << (char)('A' + n);
	return;
}