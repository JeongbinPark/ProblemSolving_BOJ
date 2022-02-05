#include <iostream>
using namespace std;

struct Node {
	int value = NULL;
	Node *left = NULL;
	Node *right = NULL;
};

void postorder(Node);

int value;
Node headNode;

int main() {
	cin >> value;
	headNode.value = value;
	
	while (cin >> value) {
		Node * newNode = new Node;
		newNode->value = value;

		Node *currNode = &headNode;
		while (true) {
			if (currNode->value > value) {
				if (currNode->left == NULL) {
					currNode->left = newNode;
					break;
				} else {
					currNode = currNode->left;
				}
			} else {
				if (currNode->right == NULL) {
					currNode->right = newNode;
					break;
				} else {
					currNode = currNode->right;
				}
			}
		}
	}
	postorder(headNode);

	return 0;
}
void postorder(Node node) {
	if (node.left != NULL) postorder(*(node.left));
	if (node.right != NULL) postorder(*(node.right));
	cout << node.value << "\n";
	return;
}
/*Àç±Í ÀÌ¿ë
#include <iostream>
int a[10001],c,s,p;
void k(int f) {
  if (p != c) {
	  int t = a[p++];
	  if (a[p-1] > a[p]) k(t);
	  if (a[p] < f) k(f);
	  std::cout<<t<<'\n';
  }
}
int main() {
  while (std::cin>>a[c])c++;
  k(10e6);
}
*/