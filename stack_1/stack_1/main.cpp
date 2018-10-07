#include <iostream>
#include <malloc.h>

using namespace std;

typedef struct elem {
	int buf;
	struct elem *next;
}stack;

stack *top;

void push(int var) {
	stack *p = (stack*)malloc(sizeof(stack));
	p->buf = var;
	p->next = top;
	top = p;
}

void pop() {
	stack *p;
	int var;
	var = top->buf;
	p = top;
	top = p->next;
	free(p);
	cout << "Deleted element: " << var << endl;
}

void show() {
	stack *p;
	p = top;
	cout << "Stack: " << endl;
	while (p!=NULL) {
		cout << p->buf << "  ";
		p = p->next;
	}
	cout << endl;
}

int main() {
	int x;

	while (1) {
		int n;
		cout << "1 - push; 2 - pop; 3 - show; 4 - exit: ";
		cin >> n;

		switch (n) {
		case 1: cout << "Input element: " ; cin >> x;  push(x); break;
		case 2: pop(); break;
		case 3: show(); break;
		}

		if (n == 4) break;
	}

	system("pause");
	return 0;
}