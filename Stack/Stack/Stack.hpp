#pragma once
#include <iostream>

const int MAXSIZE = 10;

template<typename T>
class Stack
{
	T array[MAXSIZE];
	int top = -1;

	public:
		void push(T var) {
			if (!isFull())
				array[top + 1] = var;
			else
				printf("Stack is full");
			top++;
		}
		T pop() {
			T var;
			if (!isEmpty()) {
				var = array[top];
				top--;
				return var;
			}
			else
				printf("Stack is Empty");
		}
		T peek() {
			if (!isEmpty)
				return array[top];
			else
				printf("Stack is Empty");
		}
		bool isEmpty() {
			if (top <= -1) return true;
			return false;
		}
		bool isFull() {
			if (top >= MAXSIZE) return true;
			return false;
		}

		void printAll() {
			if (isEmpty()) printf("Stack is mt!");
			for (int i = top; i >= 0; i--) {
				std::cout << array[i] << " ";
			}
		}
};

