#include <iostream>
#include <conio.h>
#include "List.h"

using namespace std;

template <typename Type>
ostream &operator<<(ostream&, const List<Type>&);

template <typename Type>
istream& operator>>(istream&, List<Type>&);

template <typename Type>
istream& operator>>(istream&, List<Date>&);

int main() {
	List<double> arr[5] = { 0 };
	List<Date> dates[5] = { 0 };
	cout << "Enter 5 elements for the double type (2.0,3.0,...)." << endl;
	cin >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4];
	cout << "\nEnter 5 elements for the Date type (day/month/year)." << endl;
	cin >> dates[0] >> dates[1] >> dates[2] >> dates[3] >> dates[4];

	cout << "\nYour inputted double list: " << arr;
	cout << "\nYour inputted Date list: " << dates;

	cout << "Resizing to 10.." << endl;
	arr->resize(10);
	dates->resize(10);

	cout << "Printing out new double list: " << arr << endl;
	cout << "Printing out new Date list: " << dates << endl;

	//Didn't get to have main test insert_front,back and remove_front,back. Also was having trouble compiling with error LNK2019.
}