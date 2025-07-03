#pragma once
#include "Node.h"

class LinkedList
{
private:
	int length = 0;
	
public:
	Node* HEAD;
	LinkedList(){
		HEAD = nullptr;
	}

	LinkedList(Node* H) : HEAD(H) {}

	void insert(int var) {

		Node* newNode = new Node{ var, nullptr };

		if (HEAD != nullptr) {
			newNode->next = HEAD;
			HEAD = newNode;
		}
		else HEAD = newNode;
		++length;
	}

	void sortedInser(int var) {


	}

	void insertAt(int pos, int var) {	//if position exceeds size of list it will add as a last element.

		Node* newNode = new Node{ var, nullptr };
		if (HEAD == nullptr) {
			HEAD = newNode;
			++length;
			return;
		}
		Node* temp = HEAD;

		for (int i = 1; i < pos - 1 && temp->next != nullptr; ++i)
			temp = temp->next;

		if (temp->next == nullptr) {
			temp->next = newNode;
			++length;
			return;
		}

		newNode->next = temp->next;
		temp->next = newNode;
		++length;
	}

	void remove() { //removes first element
		if (HEAD == nullptr) return;

		Node* temp = HEAD;
		HEAD = HEAD->next;
		delete temp;
		--length;
	}

	void remove(int pos) { //removes element from nth position, if exists, else returns
		if (HEAD == nullptr) return;

		Node* temp = HEAD;
		for (int i = 0; temp != nullptr && i < pos; ++i)
			temp = temp->next;

		if (temp == nullptr) return;

		Node* rem = temp->next;
		temp->next = rem->next;
		delete rem;
		--length;
	}

	void traversal() {
		Node* temp = HEAD;

		while (temp != nullptr) {
			std::cout << temp->data << " ";
			temp = temp->next;
		}
		std::cout << std::endl;
	}

	Node *search(int var) { //return node that contains var value, useless :/
		if (HEAD == nullptr) return nullptr;
		Node* temp = HEAD;

		while (temp->next != nullptr) {
			if (temp->data == var) return temp;
			temp = temp->next;
		}

		return nullptr;
	}

	int size() {
		return length;
	}

	void sort() {
		if (HEAD == nullptr) return;
		bool sorted = false;

		Node* temp = HEAD;
		int snach = 0;

		int len = length-1;
		int operations = 0;
		while (!sorted) {
			sorted = true;
			for (int i = 0;temp->next != nullptr && i < len; ++i) {
				if (temp->data > temp->next->data) { 
					snach = temp->data;
					temp->data = temp->next->data;
					temp->next->data = snach;
					sorted = false;
				}
				++operations;
				temp = temp->next;
			}
			--len;
			temp = HEAD;
		}
		std::cout << "Operations: " << operations << '\n';
	}

	void timeSorted(std::chrono::milliseconds* duration) {
		auto start = std::chrono::high_resolution_clock::now();
		sort();
		auto end = std::chrono::high_resolution_clock::now();
		
		*duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	}

	bool sortedCorectly() {
		Node* temp = HEAD;

		while (temp->next != nullptr)
		{
			if (temp->data > temp->next->data) return false;
			temp = temp->next;
		}
		return true;
	}

	~LinkedList() {
		Node* temp = HEAD;

		while (temp != nullptr) {
			HEAD = HEAD->next;
			delete temp;
			temp = HEAD;
		}
		HEAD = nullptr;
	}
};

