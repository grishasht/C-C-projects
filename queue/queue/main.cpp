#include <iostream>
#include <malloc.h>

using namespace std;

typedef struct elem {
	int buf;
	struct elem *next;
}queue;

queue *begq, *endq;

void push(int var) {
	queue *p = (queue*)malloc(sizeof(queue));
	p->buf = var;
	p->next = NULL;
	if (endq == NULL) begq = p;
	else endq->next = p;
	endq = p;
}

void pop() {
	int var = 0;
	queue *p;
	p = begq;
	if (begq != NULL) {
		var = begq->buf;
		begq = p->next;
		cout << "Deleted element: " << var << endl;
	}
	if (begq == NULL) endq = NULL;
	if (p!=NULL) free(p);
}

void show() {
	queue *p;
	p = begq;
	while (p != NULL) {
		cout << p->buf << "  ";
		p = p->next;
	}
	cout << endl;
}

int main() {
	
	while (1) {
		int x, n;

		cout << "1 - push; 2 - pop; 3 - show; 4 - exit: ";
		cin >> n;

		switch (n) {
		case 1: cout << "Add elem: "; cin >> x; push(x); break;
		case 2: pop(); break;
		case 3: show(); break;
		}

		if (n == 4) break;
	}

	system("pause");
	return 0;
}