#ifndef LIST_H
#define LIST_H

template <typename Type> class List{
private:
	int size;
	Type *arr;
public:
	List(int size = 0);
	List(const List& l);
	void resize(int size);
	const List& operator=(const List& l);
	int& operator[](int index);
	void insert_front(Type element);
	void insert_back(Type element);
	void remove_front();
	void remove_back();
	~List();
};

struct Date {
	int month, day, year;
};
#endif