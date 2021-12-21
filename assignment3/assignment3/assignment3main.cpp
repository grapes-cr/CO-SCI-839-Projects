#include <iostream>
#include <conio.h>
#include "linkedlist.h"
#include "Stack.h"

using namespace std;

int main() {
	char input, slash;
	Date date;
	int option;
	string frontBack;
	std::cout << "Creating new Date Stack.." << endl;
	Stack stack(Date* dateList);
	std::cout << "Would you like to add a new date to the stack? (Y/N)" << endl;
	cin >> input;
	if (input == 'y' || input == 'Y') {

		std::cout << "Okay, input your date. (MM/DD/YYYY) ";
		cin >> date.month >> slash >> date.day >> slash >> date.year;
		stack.push(stack, date);
		while (input != 'n' || input != 'N') {
			std::cout << "Add more dates to the stack? (Y/N)" << endl;
			cin >> input;
			if (input == 'n' || input == 'N') {
				break;
			}
			else {
				std::cout << "Input your date. (MM/DD/YYYY) ";
				cin >> date.month >> slash >> date.day >> slash >> date.year;
				stack.push(stack, date);
			}
		}

		std::cout << "Stack complete. What would you like to do? \n1. Display the stack. \n2. Insert another date. \n3. Remove a date. \n4. Find a date. \n5. Quit. " << endl;
		switch (option) {
		case 1:
			stack.display(stack);
			break;
		case 2:
			std::cout << "Insert date.(MM/DD/YYYY) " << endl;
			{
				std::cout << "Insert new date in back.  " << endl;
				cin >> date.month >> slash >> date.day >> slash >> date.year;
				stack.push(stack, date);
			}
			break;
		case 3:
			std::cout << "Removing date from stack. " << endl;
			stack.pop(stack);
			break;
		case 4:
			cout << "Enter the date you would like to search for. (MM/DD/YYYY) " << endl;
			cin >> date.month >> slash >> date.day >> slash >> date.year;
			if (stack.search(date) == -1) {
				cout << "Date not found in stack." << endl;
			}
			else {
				cout << "Date found in node number " << stack.search(date) << ". " << endl;
			}
			break;
		case 5:
			break;
		default:
			cout << "Enter valid number. " << endl;
			break;
		}
	}
	cout << "Press any key to continue..." << endl;
	_getch();

	//I used most of the same code from the last assingment, however I had an issue with calling "stack.(function name)" and I think it's because of the way I declared stack in line 14.