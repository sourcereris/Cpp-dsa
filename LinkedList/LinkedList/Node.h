#pragma once
#include <iostream>
#include <chrono>

class Node{
public:
	int data;
	Node* next;
};

class DNode {
public:
	int data;
	DNode* next;
	DNode* prev;
};