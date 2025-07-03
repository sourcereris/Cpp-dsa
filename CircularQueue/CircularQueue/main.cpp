#include <stdio.h>
#include <iostream>

struct QNode {
	int data;
	QNode* next;
};

struct CircularQueue {
	QNode* FRONT = nullptr;
	QNode* REAR = nullptr;

	void Enqueue(int val) {

		QNode* newNode = new QNode{ val, FRONT };

		if (!newNode) {
			printf("Memory allocation failed!");
			return;
		}

		if (REAR == nullptr) {
			FRONT = REAR = newNode;
			return;
		}

		REAR->next = newNode;			//create and asign new node
		REAR = newNode;					//updating last node to last place
	}

	int Dequeue() {
		
		if (FRONT == nullptr) {
			printf("Q is mt!");
			return -1;
		}
			
		int var = FRONT->data;
		QNode* temp = FRONT;
			
		if (REAR == FRONT) {			//if FRONT == REAR last node left
			delete FRONT;
			FRONT = REAR = nullptr;
		}
		else {
			FRONT = FRONT->next;
			delete temp;
			REAR->next = FRONT;			//maintain circular link after FRONT was changed
		}

		return var;
	}

	void Display() {
		if (FRONT == nullptr) return;
		QNode* temp = FRONT;
		printf("Beggining of Queue\n");
		do {
			std::cout << temp->data << "\n";
			temp = temp->next;
		} while (temp != FRONT);

		printf("End");
	}

	~CircularQueue(){
		if (FRONT == nullptr) return;
		std::cout << "\n~\n";
		QNode* temp;
		do{
			temp = FRONT;
			FRONT = FRONT->next;
			delete temp;
		} while (FRONT != REAR && FRONT != nullptr);

		FRONT = REAR = nullptr;
	}
};


int main() {
	
	CircularQueue* qp = new CircularQueue;

	qp->Enqueue(5);
	qp->Enqueue(6);

	qp->Display();

	qp->Dequeue();

	delete qp;
	qp = nullptr;

	return 0;
}