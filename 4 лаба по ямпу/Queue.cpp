#include "Queue.h"

Queue::Queue()
{
	head = 0;
	tail = 0;
}

Queue::~Queue()
{
	clear();
}

bool Queue::isEmpty()
{
	return head == 0;
}

void Queue::deQueue()
{
	if (!isEmpty())
	{
		TQueue p = head;
		head = head->next;
		p->next = nullptr;
		delete p;
		p = nullptr;
	}
}

void Queue::push(char elem)
{
	TQueue p = new Node;
	p->data = elem;
	p->next = nullptr;
	if (tail) {
		tail->next = p;
		tail = p;
	}
	else {
		head = p;
		tail = p;
	}
}

bool Queue::pop(char& elem)
{
	bool canGet = false;
	if (!isEmpty()) {
		canGet = true;
		elem = head->data;
		deQueue();
	}
	return canGet;
}

void Queue::clear()
{
	while (!isEmpty())
		deQueue();
}

void Queue::print()
{
	TQueue p = head;
	while (p) {
		std::cout << p->data;
		p = p->next;
	}
	std::cout << ::std::endl;
}
