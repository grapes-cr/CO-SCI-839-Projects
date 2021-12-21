#include <iostream>
#include "treeheader.h"

using namespace std;

TreeList::TreeList(Date *root) { //default
	root == NULL;
}

TreeList::TreeList(const TreeList &ll) { //copy constructor
	root = new Date;
	if (ll.root != NULL) {
		while (ll.root->left != NULL || ll.root->right != NULL) {
			root->month = ll.root->month;
			root->day = ll.root->day;
			root->year = ll.root->year;
			root->left = ll.root->left;
		}
	}
	else {
		root == NULL;
	}
}

const TreeList& TreeList::operator=(const TreeList& ll) { //assignment overload
	TreeList temp(ll);
	std::swap(temp.root, root);
	return *this;
}


void TreeList::display(Date *root) {
	if (root != NULL) {
		display(root->left);
		cout << root->day << "/" << root->month << "/" << root->year << endl;
		display(root->right);
	}
}

Date* TreeList::insert(Date *root, Date *newDate) {
	if (root == NULL) {
		return newDate;
	}
	else {
		if (newDate->year < root->year) {
			root->left = insert(root->left, newDate);
		}
		else if (newDate->year == root->year) {
			if (newDate->month < root->month) {
				root->left = insert(root->left, newDate);
			}
			else if (newDate->month > root->month) {
				root->right = insert(root->right, newDate);
			}
		}
		else if (newDate->year > root->year) {
			root->right = insert(root->left, newDate);
		}
	}
	return newDate;
}

Date* TreeList::remove(Date *root, Date *key) {
	if (root == NULL) {
		return root;
	}
	if (key->year < root->year) {
		root->left = remove(root->left, key);
	}
	else if (key->year == root->year) {
		if (key->month < root->month) {
			root->left = remove(root->left, key);
		}
		else if (key->month > root->month) {
			root->right = remove(root->right, key);
		}
	}
	else if (key->year > root->year) {
		root->right = remove(root->left, key);
	}
	else {
		if (root->left == NULL) {
			Date *temp = root->right;
			delete (root);
			return temp;
		}
		else if (root->right == NULL) {
			Date *temp = root->left;
			delete (root);
			return temp;
		}
	}
	Date *temp2 = root->right;
	while (temp2->left != NULL) {
		temp2 = temp2->left;
	}
	root = temp2;
	root->right = remove(root->right, temp2);
	return root;
}


Date* TreeList::search(Date *root, Date *key) {
	if (root == NULL || root == key) {
		return root;
	}
	if (key->year < root->year) {
		root->left = search(root->left, key);
	}
	else if (key->year == root->year) {
		if (key->month < root->month) {
			root->left = search(root->left, key);
		}
		else if (key->month > root->month) {
			root->right = search(root->right, key);
		}
	}
	else if (key->year > root->year) {
		root->right = search(root->left, key);
	}
}

TreeList::~TreeList() {
	delete root;
}