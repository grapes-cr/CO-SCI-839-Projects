#include <iostream>
#include "List.h"

using namespace std;

template <typename Type>
List<Type>::List(int s) : size(s), arr(new Type[s]) { //default
}

template <typename Type>
List<Type>::List(const List& l) : size(l.size) { //copy constructor
	arr = new Type(size);
	for (int i = 0; i < size; i++) {
		arr[i] = l.arr[i];
	}
}

template <typename Type>
const List<Type>& List<Type>::operator=(const List<Type>& l) { //assignment overload
	delete[] arr;
	arr = new Type[l.size];
	for (int i = 0; i < size; i++) {
		arr[i] = l.arr[i];
	}
	return *this;
}

template <typename Type>
void List<Type>::resize(int s) { //resizes the dynamic array
	if (s == size) {
		return;
	}
	Type* newArr = new Type[s];
	if (s < size) {
		for (int i = 0; i < s; i++) {
			newArr[i] = arr[i];
		}
	}
	else if (s > size) {
		for (int i = 0; i < size; i++) {
			newArr[i] = arr[i];
		}
		for (int i = size; i < s; i++) {
			newArr[i] = 0;
		}
	}
	delete[] arr;
	size = s;
	arr = newArr;
}

template <typename Type>
int& List<Type>::operator[](int index) { //return part of array
	return arr[index];
}

template <typename Type>
void List<Type>::insert_back(Type element) {
	resize(size + 1);
	arr[size] = element;
}

template <typename Type>
void List<Type>::remove_back() {
	resize(size - 1);
}

template <typename Type>
void List<Type>::insert_front(Type element) {
	resize(size + 1);
	Type* dummyArr = new Type[size + 1];
	dummyArr[0] = element;
	for (int i = 1; i <= size; i++) {
		dummyArr[i] = arr[i - 1];
	}
	arr = dummyArr;
}

template <typename Type>
void List<Type>::remove_front() {
	Type* dumbArr = new Type[size];
	for (int i = 1; i < size; i++) {
		dumbArr[i - 1] = arr[i];
	}
	resize(size - 1);
	arr = dumbArr;
}

template <typename Type>
List<Type>::~List() {
	delete[] arr;
}

template <typename Type>
ostream& operator<<(ostream& out, const List<Type>& l) {
	cout << endl;
	for (int i = 0; i < l.size; i++) {
		out << l[i] << ' ';
	}
	out << endl << endl;
}

template <typename Type>
istream& operator>>(istream& in, List<Type>& l) {
	for (int i = 0; i < l.size; i++) {
		in >> l[i];
	}
	return in;
}

template <typename Type>
istream& operator>>(istream& in, List<Date>& d) {
	char slash;
	for (int i = 0; i < d.size; i++) {
		in >> d->day >> slash >> d->month >> slash >> d->year;
	}
	return in;
}