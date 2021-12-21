#include <iostream>
#include <conio.h>
#include "linkedlist.h"
#include <string>

using namespace std;

int main() {
	char input, slash;
	Date date;
	int option;
	string frontBack;
	cout << "Creating new Date List.." << endl;
	LinkedList List(Date* dateList);
	cout << "Would you like to add a new date to the list? (Y/N)" << endl;
	cin >> input;
	if (input == 'y' || input == 'Y') {

		cout << "Okay, input your date. (MM/DD/YYYY) ";
		cin >> date.month >> slash >> date.day >> slash >> date.year;
		List.push_front(List, date);
		while (input != 'n' || input != 'N') {
			cout << "Add more dates to list? (Y/N)" << endl;
			cin >> input;
			if (input == 'n' || input == 'N') {
				break;
			}
			else {
				cout << "Input your date. (MM/DD/YYYY) ";
				cin >> date.month >> slash >> date.day >> slash >> date.year;
				List.push_front(List, date);
			}
		}

		cout << "List complete. What would you like to do? \n1. Display the list. \n2. Insert another date (front or back). \n3. Remove a date (front or back). \n4. Find a date. \n5. Display a date (front or back). \n6. Quit. " << endl;
		switch (option) {
		case 1:
			List.display(List);
			break;
		case 2:
			cout << "Insert date in front or back?" << endl;
			cin >> frontBack;
			if (frontBack == "front" || frontBack == "Front" || frontBack == "FRONT") {
				cout << "Insert new date in front. (MM/DD/YYYY) " << endl;
				cin >> date.month >> slash >> date.day >> slash >> date.year;
				List.push_front(List, date);
			}
			else if (frontBack == "back" || frontBack == "Back" || frontBack == "BACK") {
				cout << "Insert new date in back. (MM/DD/YYYY) " << endl;
				cin >> date.month >> slash >> date.day >> slash >> date.year;
				List.push_back(List, date);
			}
			break;
		case 3:
			cout << "Remove date in front or back?" << endl;
			cin >> frontBack;
			if (frontBack == "front" || frontBack == "Front" || frontBack == "FRONT") {
				List.remove_front(List);
				cout << "Removed front." << endl;
			}
			else if (frontBack == "back" || frontBack == "Back" || frontBack == "BACK") {
				List.remove_back(List);
				cout << "Removed back." << endl;
			}
			break;
		case 4:
			cout << "Enter the date you would like to search for. (MM/DD/YYYY) " << endl;
			cin >> date.month >> slash >> date.day >> slash >> date.year;
			if (List.search(date) == -1) {
				cout << "Date not found in list." << endl;
			}
			else {
				cout << "Date found in node number " << search(date) << ". " << endl;
			}
			break;
		case 5:
			cout << "Display front or back date? " << endl;
			cin >> frontBack;
			if (frontBack == "front" || frontBack == "Front" || frontBack == "FRONT") {
				List.pop_front(List);
			}
			else if (frontBack == "back" || frontBack == "Back" || frontBack == "BACK") {
				List.pop_back(List);
			}
			break;
		case 6:
			break;
		default:
			cout << "Enter valid number. " << endl;
			break;
		}
	}
	cout << "Press any key to continue..." << endl;
	_getch();

} /*The main issue I had with this program was calling the member functions from the other CPP file to main. The compiler gives me an error so I think I am calling the functions wrong in main--
  any help or feedback would be appreciated :) */