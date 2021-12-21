#include <iostream>
#include "linkedlist.h"

using namespace std;

LinkedList::LinkedList(Date *head) { //default
	head == NULL;
}

LinkedList::LinkedList(const LinkedList &ll) { //copy constructor
	head = new Date;
	if (ll.head != NULL) {
		while (ll.head->next != NULL) {
			head->month = ll.head->month;
			head->day = ll.head->day;
			head->year = ll.head->year;
			head->next = ll.head->next;
		}
	}
	else {
		head == NULL;
	}
}

const LinkedList& LinkedList::operator=(const LinkedList& ll) { //assignment overload
	LinkedList temp(ll);
	std::swap(temp.head, head);
	return *this;
}


void LinkedList::display(Date *node) {
	if (node != NULL) {
		while (node != NULL) {
			cout << node->month << "/" << node->day << "/" << node->year << endl;
			node = node->next;
		}
	}
	else {
		cout << "NULL" << endl;
	}
}

void LinkedList::push_front(Date** head, Date *newDate) {
	Date* newNode = new Date;
	newNode->month = newDate->month;
	newNode->day = newDate->day;
	newNode->year = newDate->year;
	newNode->next = (*head);
	(*head) = newNode;
}

void LinkedList::remove_front(Date **head) {
	if (*head != NULL) {
		Date* temp = new Date;
		temp = *head;
		*head = temp->next;
		delete temp;
	}
}

void LinkedList::pop_front(Date *head) {
	if (head != NULL) {
		cout << head->month << "/" << head->day << "/" << head->year << endl;
	}
	else {
		cout << "NULL" << endl;
	}
}

void LinkedList::push_back(Date **head, Date *newDate) {
	Date* newNode = new Date;
	newNode = (*head);
		if (*head != NULL) {
			while (newNode->next != NULL) {
				newNode = newNode->next;
			}
			newNode->next->month = newDate->month;
			newNode->next->day = newDate->day;
			newNode->next->year = newDate->year;
		}
		else {
			(*head) = newDate;
		}
}

void LinkedList::remove_back(Date **head) {
	Date *temp = new Date;
	temp = *head;
	if (*head != NULL) {
		while (temp->next->next != NULL) {
			temp = temp->next;
		}
		delete temp->next;
		temp->next = NULL;
		*head = temp;
		delete temp;
	}
}

void LinkedList::pop_back(Date *head) {
	Date *temp = new Date;
	temp = head;
	if (head != NULL) {
		while (temp->next != NULL) {
			temp = temp->next;
		}
		cout << temp->month << "/" << temp->day << "/" << temp->year << endl;
	}
	else {
		cout << "NULL" << endl;
	}
}

int LinkedList::search(const Date& date, Date *head) {
	int count = 0;
		Date *temp = new Date;
		temp = head;
		while (temp != NULL && temp != &date) {
			temp = temp->next;
			count++;
		}
		if (temp == NULL) {
			return;
		}
		else {
			return count;
		}
}

LinkedList::~LinkedList() {
	delete head;
}