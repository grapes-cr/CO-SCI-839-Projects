#ifndef QUEUE_H
#define QUEUE_H
#include "linkedlist.h"

class Queue : private LinkedList {
public:
	void push(Date **head, Date *newDate);
	void pop(Date **head);
};

#endif

