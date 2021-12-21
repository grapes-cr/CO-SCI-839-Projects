#include <iostream>
#include <conio.h>
#include "treeheader.h"
#include <string>

using namespace std;

int main() {
	char input, slash;
	Date date;
	int option;
	string frontBack;
	cout << "Creating new tree.." << endl;
	TreeList List(Date* dateList);
	cout << "Would you like to add a new date to the tree? (Y/N)" << endl;
	cin >> input;
	if (input == 'y' || input == 'Y') {

		cout << "Okay, input your date. (MM/DD/YYYY) ";
		cin >> date.month >> slash >> date.day >> slash >> date.year;
		List.insert(List, date);
		while (input != 'n' || input != 'N') {
			cout << "Add more dates to tree? (Y/N)" << endl;
			cin >> input;
			if (input == 'n' || input == 'N') {
				break;
			}
			else {
				cout << "Input your date. (MM/DD/YYYY) ";
				cin >> date.month >> slash >> date.day >> slash >> date.year;
				List.insert(List, date);
			}
		}

		cout << "List complete. What would you like to do? \n1. Display the list. \n2. Insert another date. \n3. Remove a date. \n4. Find a date. \n5. Display a date. \n6. Quit. " << endl;
		switch (option) {
		case 1:
			List.display(List);
			break;
		case 2:
			cout << "Insert date." << endl;
			cin >> date.month >> slash >> date.day >> slash >> date.year;
			List.insert(List, date);
			break;
		case 3:
			cout << "Remove a date." << endl;
			cin >> date.month >> slash >> date.day >> slash >> date.year;
			List.remove(List, date);
			cout << "Removed." << endl;
			break;
		case 4:
			cout << "Enter the date you would like to search for. (MM/DD/YYYY) " << endl;
			cin >> date.month >> slash >> date.day >> slash >> date.year;
			if (List.search(List, date) == NULL) {
				cout << "Date not found in list." << endl;
			}
			else {
				cout << "Date found in node number " << List.search(List, date) << ". " << endl;
			}
			break;
		case 5:
			cout << "Displaying dates." << endl;
			List.display(List);
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
}