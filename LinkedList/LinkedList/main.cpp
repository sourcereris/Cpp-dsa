#include <stdlib.h>
#include <iostream>
#include <random>
#include "LinkedList.h"
#include "DoublyLinkedList.h"
#include <chrono>
#include <thread>

int main() {

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(INT_MIN, INT_MAX);

	LinkedList ll;
	DoublyLinkedList dl;

	auto from = std::chrono::high_resolution_clock::now();////////////////////////////////////////

	for (int i = 0; i < 1; ++i) {
		ll.insertAt(10, dist(gen));
	}
	
	for (int i = 0; i < 1000000; ++i) {
		dl.sortedInsert(dist(gen));
	}

	

	std::chrono::milliseconds* llduration = new std::chrono::milliseconds(0);
	std::chrono::milliseconds* dlduration = new std::chrono::milliseconds(0);



	std::thread t2(&DoublyLinkedList::timeSorted, &dl, dlduration);	
	std::thread t1(&LinkedList::timeSorted, &ll, llduration);


	t1.join();
	std::cout << "LinkedList sort:       " << llduration->count() << " ms\n\n";


	t2.join();
	std::cout << "DoublyLinkedList sort: " << dlduration->count() << " ms\n";


	auto to = std::chrono::high_resolution_clock::now();/////////////////////////////////////////////
	std::cout << "\nAll time: " << std::chrono::duration_cast<std::chrono::milliseconds>(to - from).count() << " ms\n";
	puts("");

	std::cout << "LinkedList sorted correctly:       " << ll.sortedCorectly() << '\n';
	std::cout << "DoublyLinkedList sorted correctly: " << dl.sortedCorectly() << '\n';

	delete llduration;
	delete dlduration;

	DoublyLinkedList dll;
	
	puts("\ndll:");

	return 0;
}