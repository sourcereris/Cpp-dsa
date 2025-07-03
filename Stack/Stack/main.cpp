#include <stdlib.h>
#include <iostream>
#include "Stack.hpp"

using namespace std;

struct stack {

	int items[10];
	int top;
};
typedef struct stack st;

void creatingStack(st* s) {
	
	s->top = -1;
}

bool isFull(st* s) {
	if (s->top >= 10) return true;
	return false;
}

bool isEmpty(st* s) {
	if (s->top <= -1) return true;
	return false;
}

void push(st* s, int num) {
	
	if (isFull(s)) cout << "stack is Full\n";
	else {
		s->top++;
		s->items[s->top] = num;
	}
}

int pop(st* s) {
	int res = 0;
	if (!isEmpty(s)) {
		res = s->items[s->top];
		s->top -= 1;
	}
	return res;
}

int peek(st* s) {

	return s->items[s->top];
}

void main() {

	st* stack = (st*)malloc(sizeof(st));

	creatingStack(stack);
	push(stack, 5);
	push(stack, 10);
	push(stack, 12);
	push(stack, 15);

	cout << peek(stack)<< endl;
	cout << pop(stack) << endl;
	cout << pop(stack) << endl;

	Stack<char> stack1;
	cout << stack1.isEmpty() << "\n";
	while (!stack1.isFull()) {
		stack1.push('=');
	}

	stack1.printAll();
	cout << endl;
	while (!stack1.isEmpty()) {
		cout << stack1.pop();
	}
	stack1.push('p');
	stack1.printAll();
}