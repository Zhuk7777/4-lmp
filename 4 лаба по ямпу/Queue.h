#pragma once
#include<iostream>
class Queue {
	struct Node {
		char data;
		Node* next;
	};
	typedef Node* TQueue;
	TQueue head;
	TQueue tail;
public:
	Queue();
	~Queue();

	bool isEmpty();

	void deQueue();
	void push(char elem);
	bool pop(char& elem);

	void clear();
	void print();
};
