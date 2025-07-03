#include <stdlib.h>
#include <iostream>

#define MAX 10;

template<typename T>
struct QueueNode {
	T data;
	QueueNode* next;
};

template<typename T>
struct Queue {
	QueueNode<T>* FRONT;
	QueueNode<T>* REAR;

	Queue() {
		FRONT = nullptr;
		REAR = nullptr;
	}

	void enQueue(T elmt) {
		QueueNode<T>* newNode = new QueueNode<T>{ elmt, nullptr };
		if (REAR == nullptr) {
			FRONT = REAR = newNode;
		}
		else {
			REAR->next = newNode;
			REAR = newNode;
		}
	}

	T deQueue() {

		if (FRONT == nullptr) {
			printf("Q is mt");
			return 0;
		}

		QueueNode<T>* temp = FRONT;
		FRONT = FRONT->next;

		T var = temp->data;

		delete temp;

		if (FRONT == nullptr)
			REAR = nullptr;

		return var;
	}

	void display() {
		printf("\n");
		QueueNode<T>* temp = FRONT;
		while (temp != nullptr) {
			printf("%.1f ", temp->data);
			temp = temp->next;
		}
	}

	void cleanQueue() {
		if (FRONT != nullptr) {
			QueueNode<T>* temp = FRONT;
			while (temp != nullptr) {
				FRONT = temp->next;
				delete temp;
				temp = FRONT;
			}
		}
		printf("\nQueue is clean\n");
	}
};

int main() {
	Queue<float> q;

	q.enQueue(5.1);
	q.enQueue(6.1);
	q.enQueue(7.1);
	q.enQueue(8.2);
	q.enQueue(9.6);

	printf("%.1f ", q.deQueue());
	printf("%.1f ", q.deQueue());
	printf("%.1f ", q.deQueue());

	q.display();
	q.enQueue(55);

	q.cleanQueue();
}