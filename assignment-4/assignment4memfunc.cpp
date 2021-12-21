#include <iostream>
#include "queue.h"

using namespace std;

void Queue::push(Date **head, Date *newDate) {
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

void Queue::pop(Date **head) {
	if (*head != NULL) {
		Date* temp = new Date;
		temp = *head;
		*head = temp->next;
		delete temp;
	}
}