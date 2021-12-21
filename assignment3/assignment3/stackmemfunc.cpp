#include <iostream>
#include "Stack.h"

using namespace std;

void Stack::push(Date **head, Date *newDate) {
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

void Stack::pop(Date **head) {
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