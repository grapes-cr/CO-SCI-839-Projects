#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct Date{
	int month, day, year;
	Date *next;
};

class LinkedList{
private:
	Date *head;
public: 
	LinkedList(Date *head);
	LinkedList(const LinkedList &ll);
	const LinkedList& operator=(const LinkedList& ll);
	void display(Date *node);
	void push_front(Date** head, Date *newDate);
	void remove_front(Date **head);
	void pop_front(Date *head);
	void push_back(Date **head, Date *newDate);
	void remove_back(Date **head);
	void pop_back(Date *head);
	void search(const Date& date, Date *head);
	~LinkedList();
};
#endif
	