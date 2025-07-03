#include <stdio.h>
#include <iostream>
#include <string>

struct Queue {
	int data;
	Queue* next;
};

struct PriorityQueue {
private:public:
	Queue* FRONT = nullptr;
	Queue* REAR = nullptr;

	void Enqueue(int var) {

		Queue* newNode = new Queue{ var, nullptr };
		
		if (FRONT == nullptr) {
			FRONT = REAR = newNode;
			return;
		}

		if (FRONT->data <= var) {
			newNode->next = FRONT;
			FRONT = newNode;
			return;
		}
		
		Queue* temp = FRONT;
		while (temp->next != nullptr && temp->next->data > var) {
			temp = temp->next;
		}

		newNode->next = temp->next;
		temp->next = newNode;

		if (newNode->next == nullptr) {
			REAR = newNode;
		}

	}

	int Dequeue() {
		if (FRONT == nullptr) {
			puts("Q is mt!");
			return -1;
		}

		int var = FRONT->data;
		Queue* temp = FRONT;
		if (FRONT != REAR) {
			FRONT = FRONT->next;
			delete temp;
		}else {
			delete temp;
			FRONT = REAR = nullptr;
		}
		return var;
	}

	void display() {
		if (FRONT == nullptr) return;

		Queue* temp = FRONT;
		while (temp != nullptr) {
			std::cout << temp->data << "\n";
			temp = temp->next;
		}
	}

	~PriorityQueue(){
		if (FRONT == nullptr) return;
		Queue* temp = FRONT;
		while (temp != nullptr)
		{
			FRONT = FRONT->next; 
			delete temp;
			temp = FRONT;
		}
		FRONT = REAR = nullptr;
	}
};

int main(){
	PriorityQueue pq;
	std::string str;

	if (pq.FRONT != nullptr) str = std::to_string(pq.FRONT->data);
	puts(str.c_str());

	pq.Enqueue(5);
	pq.Enqueue(9);
	pq.Enqueue(3);
	pq.Enqueue(4);
	pq.Enqueue(2);
	pq.Enqueue(17);
	pq.Enqueue(1);

	pq.display();

	printf("%d\n", pq.Dequeue());
	printf("%d\n", pq.Dequeue());
	printf("%d\n", pq.Dequeue());
	printf("%d\n", pq.Dequeue());
	printf("%d\n", pq.Dequeue());
	printf("%d\n", pq.Dequeue());
	printf("%d\n", pq.Dequeue());
}