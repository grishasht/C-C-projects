#include <iostream>
#include <malloc.h>

using namespace std;

typedef struct tree {
	tree *L;
	tree *R;
	int value;
}Node;

//bul == 0 - left, bul == 1 - right
void add_node(int x, Node *&root, int bul) {
	if (root == NULL) {
		root = (Node*)malloc(sizeof(Node));
		cout << "Enter element: "; cin >> x; cout << endl;
		root->value = x;
		root->L = root->R = NULL;
		cout << "Choose: 0 - left, 1 - right: "; cin >> bul; cout << endl;
	}
	if (bul == 0) {
		root->L = (Node*)malloc(sizeof(Node));
		cout << "Enter element: "; cin >> x; cout << endl;
		root->L->value = x;
		root = root->L;
		root->L = root->R = NULL;
		cout << "Choose: 0 - left, 1 - right: "; cin >> bul; cout << endl;
	}
	if (bul == 1) {
		root->R = (Node*)malloc(sizeof(Node));
		cout << "Enter element: "; cin >> x; cout << endl;
		root->R->value = x;
		root = root->R;
		root->L = root->R = NULL;
		cout << "Choose: 0 - left, 1 - right: "; cin >> bul; cout << endl;
	}
	if (bul < 0 || bul > 1) return;
	add_node(x, root, bul);
}

void print_node(Node *&root) {
	if (root == NULL) cout << "Node == NULL" << endl;
	else {
		cout << root->value << endl;
		if (root->L != NULL) print_node(root->L);
		else print_node(root->R);
	}
}

int main() {
	Node *tree = NULL;

	add_node(0, tree, 0);
	print_node(tree);

	system("pause");
	return 0;
}