#ifndef STACK_H
#define STACK_H
#include "linkedlist.h"

class Stack : private LinkedList { //private inheritance with linkedlist so the functions in LL would be private. I reused the remove_back and push_back functions in LL for stack's push and pop
public:
	void push(Date **head, Date *newDate);
	void pop(Date **head);
};

#endif
