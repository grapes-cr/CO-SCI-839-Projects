#include <iostream>
#include <conio.h>
#include "linkedlist.h"
#include "queue.h"

using namespace std;

int main() {
	char input, slash;
	Date date;
	int option;
	string frontBack;
	bool end = false;
	std::cout << "Creating new Date Queue.." << endl;
	Queue queue(Date* dateList);
	std::cout << "Would you like to add a new date to the queue? (Y/N)" << endl;
	cin >> input;
	if (input == 'y' || input == 'Y') {

		std::cout << "Okay, input your date. (MM/DD/YYYY) ";
		cin >> date.month >> slash >> date.day >> slash >> date.year;
		queue.push(queue, date);
		while (input != 'n' || input != 'N') {
			std::cout << "Add more dates to the queue? (Y/N)" << endl;
			cin >> input;
			if (input == 'n' || input == 'N') {
				break;
			}
			else {
				std::cout << "Input your date. (MM/DD/YYYY) ";
				cin >> date.month >> slash >> date.day >> slash >> date.year;
				queue.push(queue, date);
			}
		}

		std::cout << "Queue complete. What would you like to do? \n1. Display the queue. \n2. Insert another date. \n3. Remove a date. \n4. Find a date. \n5. Quit. " << endl;
		while (!end) {
			switch (option) {
			case 1:
				queue.display(queue);
				break;
			case 2:
				std::cout << "Insert date.(MM/DD/YYYY) " << endl;
				{
					std::cout << "Insert new date in back.  " << endl;
					cin >> date.month >> slash >> date.day >> slash >> date.year;
					queue.push(queue, date);
				}
				break;
			case 3:
				std::cout << "Removing date from queue. " << endl;
				queue.pop(queue);
				break;
			case 4:
				cout << "Enter the date you would like to search for. (MM/DD/YYYY) " << endl;
				cin >> date.month >> slash >> date.day >> slash >> date.year;
				if (queue.search(date) == -1) {
					cout << "Date not found in queue." << endl;
				}
				else {
					cout << "Date found in node number " << queue.search(date) << ". " << endl;
				}
				break;
			case 5:
				end = true;
				break;
			default:
				cout << "Enter valid number. " << endl;
				break;
			}
		}
	}
	cout << "Press any key to continue..." << endl;
	_getch();
