#pragma once
#include "Node.h"

class DoublyLinkedList
{
public:
	DNode* HEAD;
	DoublyLinkedList() {
		HEAD = nullptr;
	}

	void insert(int var) {

		DNode* newNode = new DNode{ var, HEAD, nullptr };

		if (HEAD == nullptr) {
			HEAD = newNode;
			return;
		}
		else {
			HEAD->prev = newNode;
			HEAD = newNode;
		}
	}

	void sortedInsert(int var) {
		
		DNode* newNode = new DNode{ var, nullptr, nullptr };
		DNode* temp = HEAD;

		if (HEAD != nullptr && HEAD->next != nullptr) {
			while(temp->next != nullptr && var > temp->data)
			{
				temp = temp->next;
			}
			if (temp->data < var) {
				temp->next = newNode;
				newNode->prev = temp;
			}
			else if(temp->data > var && temp->prev == nullptr){
				HEAD->prev = newNode;
				newNode->next = HEAD;
				HEAD = newNode;
			}
			else {
				newNode->next = temp;
				temp = temp->prev;
				temp->next = newNode;
				newNode->prev = temp;
			}
		}
		else if (HEAD != nullptr) {
			if(HEAD->data < var)
			{
				HEAD->next = newNode;
				newNode->prev = HEAD;
				newNode->next = nullptr;
			}
			else {
				
			}
		}
		else HEAD = newNode;


	}

	void traverse() {
		if (HEAD == nullptr) return;
		DNode* temp = HEAD;
		while (temp != nullptr)
		{	
			std::cout << temp->data << " ";
			temp = temp->next;
		}
		puts("");
	}

	void remove() {
		if (HEAD == nullptr) return;

		DNode* temp = HEAD;
		if (HEAD->next == nullptr) {
			delete HEAD;
			HEAD = nullptr;
			return;
		}

		HEAD = HEAD->next;
		delete temp;
		temp = nullptr;
		HEAD->prev = temp;
	}

	void sort() {
		if (HEAD == nullptr) return;
		DNode* temp = HEAD;

		bool sorted = false;

		int outerIterration = 0;
		int inerIteration = 0;
		int total = INT_MAX;

		int operations = 0;
		while (!sorted) {
			sorted = true;
			while(temp != nullptr){
				if (temp->next != nullptr && temp->data > temp->next->data) {
					int tempi = temp->next->data;
					temp->next->data = temp->data;
					temp->data = tempi;
					sorted = false;
					inerIteration = 0;
				}
				++inerIteration;
				++outerIterration;

				++operations;
				if (outerIterration > total) break;
				temp = temp->next;
			}

			total = outerIterration - inerIteration;
			outerIterration = 0;
			inerIteration = 0;
			temp = HEAD;
		}
		std::cout << "operations: " << operations << '\n';
	}
	
	void timeSorted(std::chrono::milliseconds* duration) {
		auto start = std::chrono::high_resolution_clock::now();
		sort();
		auto end = std::chrono::high_resolution_clock::now();

		*duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	}

	bool sortedCorectly() {
		DNode* temp = HEAD;

		int counter = 0;
		bool t = true;
		while (temp->next != nullptr)
		{
			++counter;
			if (temp->data > temp->next->data) {
				std::cout << temp->data << " -> " << temp->next->data << '\n';
				std::cout << "counter: " << counter << '\n';
				t = false;
			}
			temp = temp->next;
		}return t;
	}

	~DoublyLinkedList() {
		if (HEAD == nullptr) return;

		DNode* temp = HEAD;
		while (temp != nullptr)
		{
			HEAD = HEAD->next;
			delete temp;
			temp = HEAD;
		}
		HEAD = temp = nullptr;
	}
};

